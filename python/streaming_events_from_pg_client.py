import psycopg2
import random

conn = psycopg2.connect(database='pipeline', host='localhost', port="54321")
pipeline = conn.cursor()

# This continuous view will perform 3 aggregations on page view traffic, grouped by url:
#
# total_count - count the number of total page views for each url
# uniques     - count the number of unique users for each url
# p99_latency - determine the 99th-percentile latency for each url

q = """
CREATE CONTINUOUS VIEW v AS
SELECT
  url::text,
  count(*) AS total_count,
  count(DISTINCT cookie::text) AS uniques,
  percentile_cont(0.99) WITHIN GROUP (ORDER BY latency::integer) AS p99_latency
FROM page_views GROUP BY url
"""
pipeline.execute(q)
conn.commit()

# Now let's simulate some page views
for n in range(10000):
  # 10 unique urls
  url = '/some/url/%d' % (n % 10)

  # 1000 unique cookies
  cookie = '%032d' % (n % 1000)

  # latency uniformly distributed between 1 and 100
  latency = random.randint(1, 100)

  # NOTE: it would be much faster to batch these into a single INSERT
  # statement, but for simplicity's sake let's do one at a time
  pipeline.execute("""
    INSERT INTO page_views (url, cookie, latency) VALUES ('%s', '%s', %d)
  """ % (url, cookie, latency))

# The output of a continuous view can be queried like any other table or view
pipeline.execute('SELECT * FROM v ORDER BY url')

rows = pipeline.fetchall()
for row in rows:
  print row

# Clean up
pipeline.execute('DROP CONTINUOUS VIEW v')
conn.commit()

"""
Output:
('/some/url/0', 1000L, 100L, 100.0)
('/some/url/1', 1000L, 100L, 100.0)
('/some/url/2', 1000L, 100L, 99.5)
('/some/url/3', 1000L, 100L, 99.0)
('/some/url/4', 1000L, 98L, 99.0)
('/some/url/5', 1000L, 100L, 100.0)
('/some/url/6', 1000L, 100L, 100.0)
('/some/url/7', 1000L, 99L, 100.0)
('/some/url/8', 1000L, 100L, 99.0)
('/some/url/9', 1000L, 100L, 100.0)
"""
