var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var port = process.env.PORT || 5000;
var uname;
app.get('/', function(req, res){
  res.sendFile(__dirname + '/h1.htm');
});
app.get ('/change', function (req, res) {
	uname = req.query.name;
	console.log (uname + ' is on ...') 
    io.emit('chat message',uname+" -is online");
	
	res.sendFile (__dirname + '/index-chat.html');
});
//app.listen(3000);
io.on('connection', function(socket){  // connection is same as connect
  socket.on('chat message', function(msg){
    io.emit('chat message',uname+" : "+msg);
	
  });
});

http.listen(port, function(){
  console.log('listening on *:' + port);
});