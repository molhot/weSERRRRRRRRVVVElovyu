##　課題で要求されていること

### ポートやホストを選択できること  
- リクエストの中に含まれているポートやホストを解釈するような機能が必要になる  

### サーバーネームありでもなしでも対応可能にする  
- confファイル内のサーバーネームがあるかを調べてあるならサーバーネームを読み取る、なければ自分で設定？  
  
### 複数同じポートを共有するようなサーバーの時は初めに書かれている設定を参照すること  
- よくわからんけど前から読めば良さそう  
  
### errorpageを設定すること  
  
### clientのbodysizeは制限すること  
  
### httpメソッドを定義すること  
  
### redirectionを設定すること  
  
### アクセスされたパスを別の場所に紐付ける  
例えば/satushiが/tmp/wwwに接続された場合/satushi/ohmygodが/tmp/www/ohmygodを自動的に探しに行く  
  
### autoindex機能（多分directory listening）　を付与すること（あってるか不安）  
  
### ディレクトリへのアクセスであった場合、ファイルを応答すること  
  
### CGIを実行できるようにする  
  
### POSTとGETを行えるようにする  
  
## （上記を受けての）共通ルール
- confファイルは必ず拡張子が.confであること  
confファイルの記載方法は下記のようになっていること  
シャープ以降は無視されるものとする  
変数の使用はなしとしたい  （要相談
  
server \{  
    listen 4242;  
    server_name "webserv1";  別に　server_name webserv1; でも良い  
	root nanka;  
    index index.html index.php;  
	error_page   500 502 503 504  /50x.html;  
	client_body_buffer_size 8k;  
    cgi_extension .cgi;  
    #aaaaa  
    allow_methods GET;  
	access_log ;  
	error_log ;  
	keepalive_requests ;一度の接続で受け付けることのできるリクエスト数の上限  
	keepalive_timeout ;キープアライブのタイムアウトまでの秒数  
	server_tokens ;バージョン番号の表示  
	autoindex ;インデックスリスト表示のon/off  
	rewrite ;リダイレクトの設定  
	chunked_transfer_encoding on;chunked transferの設定を有効無効にすることができる  
	client_header_buffer_size 1k;  
	types {  
        application/javascript mjs;  
    }  
    location / {  
		root   /usr/share/nginx/html;  
        index  index.html index.htm;  
        alias ./docs/;  
		deny all; この配下のファイルにアクセスできないようにする  
    }  
	location ~ \.cgi$ {
		include /etc/nginx/fastcgi_params;  
    	fastcgi_pass unix:/var/run/fcgiwrap.socket;よくわかってない  
    	fastcgi_index index.pl;よくわかってない  
    	fastcgi_param SCRIPT_FILENAME /srv/www/example.com/public_html$fastcgi_script_name;よくわかってない  
	}  
\}  
  
* server {}  
	* serverと{}の間は複数の空白（空白　たぶ）を許容する  
  
### 複数の空白（空白　たぶ）を許容する 空白位置は準拠 locationディレクティブ外  
* ssl通信に関しては無視する  
* proxyは不対応  
* aioは不対応（課題要件に反してしまうため  
*   
  
## server内   
* listen \[数字\]  
* servername \[("or')名前("or')\]  
* root \[nanka]  
* index [codeA codeB codeC ...]   
* allow_methods [methodA methodB ...]  
* error_page [pageA pageB pageC ...] 対象のページのURI  
* types{A A'smime B B'smime ...} 許容できるmimetypeは後々調べる  
* chunked_transfer_encoding [on off];  
* access_log ;  
* error_log ;  
* keepalive_requests ;一度の接続で受け付けることのできるリクエスト数の上限  
* keepalive_timeout ;キープアライブのタイムアウトまでの秒数  
* server_tokens ;バージョン番号の表示  
* autoindex ;  
* rewrite ; ??  
* client_body_buffer_size 8k;数字でも単位でも可能な模様、種類に関して要検討 デフォは8kか16k  
* client_body_timeout 60s;数字でも単位でも可能な模様 デフォルトは60s  
* client_header_buffer_size 1k;同上 デフォルトは1k  
* client_header_timeout 60s;同上 デフォルトは60s  
* client_max_body_size 1m;同上 デフォルトは1m  
* default_type mime-type;mimetypeに関しては調査必要  
* etag on | off;意味は理解したいかも 可能であれば  
  
## location内  
* access_log ;  
* error_log ;  
* keepalive_requests ;一度の接続で受け付けることのできるリクエスト数の上限  
* keepalive_timeout ;キープアライブのタイムアウトまでの秒数  
* server_tokens ;バージョン番号の表示  
* root \[nanka] ※空白は一つ  
* index [pageA pageB pageC ...]  
* autoindex ;  
* rewrite ; ??  
* client_body_buffer_size 8k;数字でも単位でも可能な模様、種類に関して要検討  
* client_body_timeout 60s;数字でも単位でも可能な模様 デフォルトは60s  
* client_header_buffer_size 1k;同上 デフォルトは1k  
* client_header_timeout 60s;1同上 デフォルトは60s  
* client_max_body_size 1m;同上 デフォルトは1m  
* default_type mime-type;mimetypeに関しては調査必要  
* etag on | off;意味は理解したいかも 可能であれば  
* log_not_found [on off];ファイルが見つからなかった場合のエラーログを出すかどうか決めれる  
  

## 一旦対応しないけど書き込みは可能な設定（使い方わからん。。。）  
connection_pool_size size;単位は許容しないので注意  
directio size | off;単位許容 使い方不明。。。  
directio_alignment size;単位は許容しないので注意  
disable_symlinks off;ファイルを開く時にシンボリックリンクをどう扱うかを決定  
if_modified_since off | exact | before;  
keepalive_requests 1000;使い方不明  
keepalive_time 1h;使い方不明  
large_client_header_buffers 4 8k;  
