// Node で実行する JavaScript (index.js)
var WebSocketServer = require("ws").Server;
var wss = new WebSocketServer({ port: 8080 });

wss.on("connection", function(ws) {
  // ブラウザからメッセージを受信した時の処理
  ws.on("message", function(message) {
    console.log(message);
  });

  // ブラウザにメッセージを送信する時の処理
  wss.clients.forEach(function(client) {
    client.send("A message from server");
  });
});
