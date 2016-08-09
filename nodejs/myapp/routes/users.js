var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/login', function(req, res, next) {
  res.render('login', { title: 'login' });
});

router.get('/register', function(req, res, next) {
  res.render('register', { title: 'register' });
});

module.exports = router;
