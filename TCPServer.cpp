#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9000);
    printf("%s\n %s", argv[2], argv[3]);
    printf("Minh la server");
    bind(listener, (SOCKADDR*)&addr, sizeof(addr));
    listen(listener, 5);
    SOCKET client = accept(listener, NULL, NULL);
    char* buf;
    int ret = recv(client, buf, sizeof(buf), 0);

    //Them ki tu ket thuc xau va ghi vao file chaodenclient.txt

    FILE* fp = NULL;
    fopen_s(&fp, "chaodenclient.txt", "w");
    fputs("Xin chao client!!!", fp);
    fclose(fp);

    //Ghi noi dung client gui den vao file noidungclientguiden.txt
    FILE* fp = NULL;
    fopen_s(&fp, "noidungclientguiden.txt", "w");
    fputs(buf, fp);
    fclose(fp);
   
    system("pause");
    closesocket(client);
    closesocket(listener);
    WSACleanup();
}
