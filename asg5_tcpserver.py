import socket

# Create TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1', 12345))
server_socket.listen(1)

print("TCP Server started... Listening on port 12345")
conn, addr = server_socket.accept()
print(f"Connected by {addr}")

while True:
    data = conn.recv(1024).decode()
    if not data or data.lower() == 'quit':
        print("Client disconnected.")
        break
    print(f"Received: {data}")
    conn.send(f"Echo: {data}".encode())

conn.close()
server_socket.close()
