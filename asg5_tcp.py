import socket

# Create TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1', 12345))
print("Connected to TCP Server.")

while True:
    msg = input("\nEnter message (or 'quit' to exit): ")
    client_socket.send(msg.encode())
    if msg.lower() == 'quit':
        break
    reply = client_socket.recv(1024).decode()
    print(f"Server: {reply}")

client_socket.close()
