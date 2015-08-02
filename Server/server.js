// var app = require('express')();
// var http = require('http').Server(app);
// var io = require('socket.io')(http);

// var http = require('http').createServer();
var io = require('socket.io')();

var socket = io.listen(3000);
// app.get('/', function(req, res){
//   // res.send('<h1>Hello world</h1>');
// });

// io.sockets.on('connection', function(socket){
//     console.log('A user connected.');
// });

// http.listen(3000, function(){
//   console.log('listening on *:3000');
// });

// function handler(req, res) {
//   console.log('something');
// }
