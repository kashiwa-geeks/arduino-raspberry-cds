var serialport = require('serialport').SerialPort;
var sp = new serialport('/dev/ttyACM0', {
  baudrate:9600,
  dataBits:8,
  parity:'none',
  flowControl:false
});

sp.on('open', function(){});

var Twig = require('twig');
var express = require('express');
var app = express();

app.set('views', __dirname + '/views');
app.set('view engine', 'twig');
app.set('view options', { layout: false });

app.get('/', function(req, res){
  res.render('index.twig');
});

app.get('/sp/:data', function(req, res){
  sp.write(req.params.data + '.');
  res.render('sended.twig', {
    message : req.params.data + 'を送信しました'
  });
});

app.listen(50359);
