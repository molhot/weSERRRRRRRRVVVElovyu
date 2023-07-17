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
  
## （上記を受けての）ルール
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
    cgi_extension .cgi;  
    #aaaaa  
    allow_methods GET;  
    location / {  
		root   /usr/share/nginx/html;  
        index  index.html index.htm;  
        alias ./docs/;  
		deny all; この配下のファイルにアクセスできないようにする  
    }  
\}  
  
* server {}  
	* serverと{}の間は複数の空白（空白　たぶ）を許容する  
  
### 複数の空白（空白　たぶ）を許容する 空白位置は準拠  
* \#後は普通の文字とみなす  
* listen \[数字\] ※空白は一つ  
* servername \[("or')名前("or')\] ※空白は一つ  
* root [] ※空白は一つ  
* index [pageA pageB pageC ...]  
* allow_methods [methodA methodB ...]  
* error_page

