#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9000);
    system("pause");
    char str3[256];
    printf("Hay nhap xau ki tu gui den server: ");
    gets_s(str3);
    connect(client, (SOCKADDR*)&addr, sizeof(addr));
    send(client, str3, strlen(str3), 0);
    closesocket(client);
    WSACleanup();
}
