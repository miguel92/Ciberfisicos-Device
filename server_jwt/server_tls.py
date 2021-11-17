import json
import socket
import ssl
import jwt

HOST = "192.168.1.101"
#HOST = "127.0.0.1"
PORT = 60000
usuarios = [{"email":"esp32@correo.com","password":"esp32pass"}]

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

server = ssl.wrap_socket(
    server, server_side=True, keyfile="certs/emqx.key", certfile="certs/emqx.pem"
)

if __name__ == "__main__":
    server.bind((HOST, PORT))
    server.listen(0)

    while True:
        connection, client_address = server.accept()
        data = connection.recv(1024)
        print(data)
        if not data:
            break
        usuario = json.loads(data.decode('utf-8'))

        for usu in usuarios:
            if usu.get('email')== usuario['email'] and usu.get('password') == usuario['password']:
                encoded = jwt.encode(usuario, "ciberfisicos1234-secreto", algorithm="HS256")
                print(encoded)
                connection.send(encoded.encode('utf-8'))

