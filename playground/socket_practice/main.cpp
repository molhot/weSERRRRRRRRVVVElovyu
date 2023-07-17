// サーバーの IP アドレスを取得
// サーバーと接続
// リクエストメッセージを作成
// リクエストメッセージを送信
// レスポンスメッセージを受信
// レスポンスメッセージに応じた処理
// サーバーとの接続をクローズ

#include <sys/socket.h>
#include <netinet/in.h>	
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8080
#define SIZE (5*1024)

/*
 * リクエストメッセージを解析する（今回はリクエスト行のみ）
 * method：メソッドを格納するバッファへのアドレス
 * target：リクエストターゲットを格納するバッファへのアドレス
 * request_message：解析するリクエストメッセージが格納されたバッファへのアドレス
 * 戻り値：成功時は0、失敗時は-1
 */
int parseRequestMessage(char *method, char *target, char *request_message) {

    char *line;
    char *tmp_method;
    char *tmp_target;
    
    /* リクエストメッセージの１行目のみ取得 */
    line = strtok(request_message, "\n");

    /* " "までの文字列を取得しmethodにコピー */
    tmp_method = strtok(line, " ");
    if (tmp_method == NULL) {
        printf("get method error\n");
        return -1;
    }
    strcpy(method, tmp_method);

    /* 次の" "までの文字列を取得しtargetにコピー */
    tmp_target = strtok(NULL, " ");
    if (tmp_target == NULL) {
        printf("get target error\n");
        return -1;
    }
    strcpy(target, tmp_target);

    return 0;
}

/* ファイルサイズを取得する */
unsigned int getFileSize(const char *path) {
    int size, read_size;
    char read_buf[SIZE];
    FILE *f;

    f = fopen(path, "rb");
    if (f == NULL) {
        return 0;
    }

    size = 0;
    do {
        read_size = fread(read_buf, 1, SIZE, f);
        size += read_size;
    } while(read_size != 0);

    fclose(f);

    return size;
}

int getProcessing(char *body, char *file_path) {

    FILE *f;
    int file_size;

    /* ファイルサイズを取得 */
    file_size = getFileSize(file_path);
    if (file_size == 0) {
        /* ファイルサイズが0やファイルが存在しない場合は404を返す */
        printf("getFileSize error\n");
        return 404;
    }

    /* ファイルを読み込んでボディとする */
    f = fopen(file_path, "r");
    fread(body, 1, file_size, f);
    fclose(f);

    return 200;
}

/*
 * レスポンスメッセージを作成する
 * response_message：レスポンスメッセージを格納するバッファへのアドレス
 * status：ステータスコード
 * header：ヘッダーフィールドを格納したバッファへのアドレス
 * body：ボディを格納したバッファへのアドレス
 * body_size：ボディのサイズ
 * 戻り値：レスポンスメッセージのデータサイズ（バイト長）
 */
int createResponseMessage(char *response_message, int status, char *header, char *body, unsigned int body_size) {

    unsigned int no_body_len;
    unsigned int body_len;

    response_message[0] = '\0';

    if (status == 200) {
        /* レスポンス行とヘッダーフィールドの文字列を作成 */
        sprintf(response_message, "HTTP/1.1 200 OK\r\n%s\r\n", header);

        no_body_len = strlen(response_message);
        body_len = body_size;

        /* ヘッダーフィールドの後ろにボディをコピー */
        memcpy(&response_message[no_body_len], body, body_len);
    } else if (status == 404) {
        /* レスポンス行とヘッダーフィールドの文字列を作成 */
        sprintf(response_message, "HTTP/1.1 404 Not Found\r\n%s\r\n", header);

        no_body_len = strlen(response_message);
        body_len = 0;
    } else {
        /* statusが200・404以外はこのプログラムで非サポート */
        printf("Not support status(%d)\n", status);
        return -1;
    }

    return no_body_len + body_len;
}

/*
 * レスポンスメッセージを送信する
 * sock：接続済のソケット
 * response_message：送信するレスポンスメッセージへのアドレス
 * message_size：送信するメッセージのサイズ
 * 戻り値：送信したデータサイズ（バイト長）
 */
int sendResponseMessage(int sock, char *response_message, unsigned int message_size) {

    int send_size;
    
    send_size = send(sock, response_message, message_size, 0);

    return send_size;
}

int httpServer(int sock)
{
	int request_size, response_size;
    char request_message[SIZE];
    char response_message[SIZE];
    char method[SIZE];
    char target[SIZE];
    char header_field[SIZE];
    char body[SIZE];
    int status;
    unsigned int file_size;

	while (1)
	{
		request_size = recv(sock, request_message, SIZE, 0);//requestmessageを受信
        if (request_size == -1) {
            printf("recvRequestMessage error\n");
            break;
        }
		else if (request_size == 0){
			printf("connection is closed\n");
			break;
		}
		std::cout << request_message << std::endl;
		if (parseRequestMessage(method, target, request_message) == -1) {
            printf("parseRequestMessage error\n");
            break;
        }

		/* メソッドがGET以外はステータスコードを404にする */
        if (strcmp(method, "GET") == 0) {
            if (strcmp(target, "/") == 0) {
                /* /が指定された時は/index.htmlに置き換える */
                strcpy(target, "/index.html");
            }

            /* GETの応答をするために必要な処理を行う */
            status = getProcessing(body, &target[1]);
        } else {
            status = 404;
        }

		/* ヘッダーフィールド作成(今回はContent-Lengthのみ) */
        file_size = getFileSize(&target[1]);
        sprintf(header_field, "Content-Length: %u\r\n", file_size);

        /* レスポンスメッセージを作成 */
        response_size = createResponseMessage(response_message, status, header_field, body, file_size);
        if (response_size == -1) {
            printf("createResponseMessage error\n");
            break;
        }

		/* レスポンスメッセージを送信する */
        sendResponseMessage(sock, response_message, response_size);
	}

	return (0);
}

int main(void)
{
	int	w_addr;
	int	c_sock;
	struct sockaddr_in a_addr;

	//socket作成
	//AS_INETに関してはhttps://linuxjm.osdn.jp/html/LDP_man-pages/man2/socket.2.html
	//SOCK_STREAMも同上
	w_addr = socket(AF_INET, SOCK_STREAM, 0);
	if (w_addr == -1)
		return (1);
	
	/* 構造体を全て0にセット *///多分これはおまじないみたいなもの
    memset(&a_addr, 0, sizeof(struct sockaddr_in));

	/* サーバーのIPアドレスとポートの情報を設定 */
    a_addr.sin_family = AF_INET;//アイネット
    a_addr.sin_port = htons((unsigned short)SERVER_PORT);//不明
    a_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);//不明
	std::cout << a_addr.sin_port << " | " << a_addr.sin_addr.s_addr << std::endl;

	//socketが何なのか想定できていないけどsocketに情報を詰めている
	if (bind(w_addr, (const struct sockaddr *)&a_addr, sizeof(a_addr)) == -1)
	{
        printf("bind error\n");
        close(w_addr);
        return -1;
    }

	/* ソケットを接続待ちに設定 */ //http://chokuto.ifdef.jp/advanced/function/listen.html
	//第二引数は同時に処理できる接続要求数 //1でいいんじゃないの
    if (listen(w_addr, 0) == -1) {
        printf("listen error\n");
        close(w_addr);
        return -1;
    }

	while (1) 
	{
        /* 接続要求の受け付け（接続要求くるまで待ち） */
        printf("Waiting connect...\n");

		//ここで接続？
        c_sock = accept(w_addr, NULL, NULL);
        if (c_sock == -1) {
            printf("accept error\n");
            close(w_addr);
            return -1;
        }
        printf("Connected!!\n");

        /* 接続済のソケットでデータのやり取り */
        httpServer(c_sock);

        /* ソケット通信をクローズ */
        close(c_sock);

        /* 次の接続要求の受け付けに移る */
    }
	return (0);
}