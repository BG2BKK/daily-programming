# coding: utf-8
# http://calebmadrigal.com/draw-lines-with-matplotlib/

import matplotlib.pyplot as plt
import matplotlib.lines as lines 
fig, ax = plt.subplots()

plt.scatter([-0.1],[-0.1],s=0.01) 

lineset = []

x = [x for x in range(000, 60)]

for idx, el in enumerate(x):
    if idx % 16 == 0:
        lineset.append([(idx, 20), (idx+12, 20)])

line1 = [(0,1990), (1,1990)]
line2 = [(1.5,0), (2,0)]

# line1_x, line1_y = zip(*line1)
# line2_x, line2_y = zip(*line2)
# ax.add_line(lines.Line2D(line1_x, line1_y, lw=2))
# ax.add_line(lines.Line2D(line2_x, line2_y, lw=2))

for line in lineset:
    line_x, line_y = zip(*line)
    x1, x2, y1, y2 = line_x[0], line_x[1], line_y[0], line_y[1]
    ax.add_line(lines.Line2D(line_x, line_y, lw=2))
    plt.text(0, 0, x1, color='red', fontsize=10, position=(x1, y1*0.9))  
    plt.text(0, 0, x2, color='red', fontsize=10, position=(x1+ (x2-x1)*0.9, y1*0.9))  

plt.plot()
plt.show()
