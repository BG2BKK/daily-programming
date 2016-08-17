var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;

function getURL(URL) {

	return new Promise(function(resolve, reject) {
		var req = new XMLHttpRequest();
		req.open('GET', URL, true);
		req.onload = function() {
			if (req.status === 200) {
				resolve(req.responseText);
			} else {
				reject(new Error(req.statusText));
			}
		};

		req.onerror = function() {
			reject(new Error(req.statusText));
		};
		req.send();
	});

}

var request = {
	comment: function getComment(callback) {
		
		return getURL('http://azu.github.io/promises-book/json/comment.json').then(JSON.parse);
	},
	people: function getPeople(callback) {
		return getURL('http://azu.github.io/promises-book/json/people.json').then(JSON.parse);
	}
};

function main() {
	function recordValue(results, value) {
		results.push(value);
		return results;
	}

	var pushValue = recordValue.bind(null, []);
	return request.comment().then(pushValue).then(request.people).then(pushValue);
}

main().then(function(value){
	console.log(value);
}).catch(function(error){
	console.error(error);
});