from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer

PORT = 1042

messages = []

class myHandler(BaseHTTPRequestHandler):

    def do_POST(self):
        length = int(self.headers.getheader('content-length'))
        data = self.rfile.read(length)
        values = data.split('&')
        if len(values) > 0:
            bodys = filter(lambda x: x.startswith('Body'), values)
            if len(bodys) > 0:
                body = bodys[0].split("=")[1]
                messages.append(body)

        self.send_response(200)
        self.send_header('Content-type','text/html')
        self.end_headers()

    def do_GET(self):
        global messages
        self.send_response(200)
        self.send_header('Content-type','text/html')
        self.end_headers()
        self.wfile.write("\n".join(messages))
        messages = []



server = HTTPServer(('', PORT), myHandler)
server.serve_forever()
