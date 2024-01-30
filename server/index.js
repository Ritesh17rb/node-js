const http = require("http");
const fs = require("fs");
const url = require("url");

const myServer = http.createServer((req, res) => {
    if (req.url === "/favicon.ico") return;
    const log = `${Date.now()}:${req.method} ${req.url} New Req Received\n`;

    const myUrl = url.parse(req.url, true);
    console.log(myUrl);

    fs.appendFile("log.txt", log, (err) => {
        if (err) {
            console.error("Error writing to log file:", err);
        }

        switch (myUrl.pathname) {
            case '/':
                if (req.method === 'GET') {
                    res.end("You are at HomePage");
                }
                break;

            case '/about':
                if (req.method === 'GET') {
                    const username = myUrl.query.myname;
                    res.end(`Hii, ${username}`);
                }
                break;

            case '/search':
                if (req.method === 'GET') {
                    const search = myUrl.query.search_query;
                    res.end("Here are your results for " + search);
                }
                break;

            case '/signup':
                if (req.method === 'POST') {
                    // Handle POST request
                    // DB Query
                    res.end("Success!");
                } else {
                    res.end("Invalid method for /signup. Use POST.");
                }
                break;

            default:
                res.end("404 NOT FOUND");
        }
    });
});

myServer.listen(8000, () => {
    console.log("Server Started on PORT: 8000");
});
