var express = require('express');
var smart = require("../smart/smart.js");
var router = express.Router();

/* GET users listing. */
router.post('/hb', function(req, res, next) {
	smart.heartbeat(req, res, next);
});

router.post('/upload', function(req, res, next) {
});

router.get('/alldevices', function(req, res, next) {
	smart.getdevices(req, res, next);
});

router.get('/alldevicestat', function(req, res, next) {
	smart.device_and_stat(req, res, next);
});

router.get('/deviceinfo/:id', function(req, res, next) {
	smart.getdeviceinfo(req, res, next);
});

module.exports = router;
