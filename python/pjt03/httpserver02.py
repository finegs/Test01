#httpserver02.py

from http.server import HTTPServer, SimpleHTTPRequestHandler

PORT = 8080

Handler = SimpleHTTPRequestHandler
httpd = HTTPServer(('', PORT), Handler)

print('listening on port', PORT)
httpd.serve_forever()


