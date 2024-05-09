#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

// 函数原型
void checkHeartbeat(int clientSocket);

void checkHeartbeat(int clientSocket) {
    int count = 0;
    while(count < 5) {
        char buffer[256];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            count++;
        } else {
            count = 0;
        }
        sleep(3); // 等待3秒
    }

    // 处理客户端出现问题的情况
    // 在这里可以添加具体的处理逻辑
}

int main() {
    // 假设clientSocket是你已经建立连接的客户端socket
    int clientSocket;
    
    checkHeartbeat(clientSocket);

    return 0;
}