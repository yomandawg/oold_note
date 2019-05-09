// root file

/* core modules
http - launch a server, send requests 
https - launch a SSL server
fs
path
os
*/


const http = require('http');
const fs = require('fs');


// function rqListener(req, res) {}
// http.createServer(rqListener);

// event-driven architecture
// if req comes, execute res
// http.createServer(function(req, res) {});

// arrow function
const server = http.createServer((req, res) => {
    console.log(req.url, req.method, req.headers);
    // process.exit(); // eventlistener exit
    
    const url = req.url;
    const method = req.method;
    // routing requests
    if (url === '/') {
        res.write('<html>');
        res.write('<head><title>Enter Message</title></head>');
        res.write('<body><form action="/message" method="POST"><input type="text" name="message"><button type="submit">Send</button></form></body>');
        res.write('</html>');
        return res.end();
    }
    // redirecting requests
    if (url === '/message' && method === 'POST') {
        fs.writeFileSync('message.txt', 'dummy_text');
        res.statusCode = 302;
        res.setHeader('Location', '/');
        return res.end();
    }
    res.setHeader('Content-Type', 'text/html');
    res.write('<html>');
    res.write('<head><title>My First Page</title></head>');
    res.write('<body><h1>Hello from my Node.js Server!</h1></body>');
    res.write('</html>');
    res.end(); // shouldn't write anything after end()
});

// keep server running until listen
server.listen(3000);
// localhost:3000 => shows request