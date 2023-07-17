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
  
server {  
    listen 4242;  
    server_name webserv1;  
  
    index index.html index.php;  
  
    cgi_extension .cgi;  
  
    allow_methods GET;  
  
    location / {  
        alias ./docs/;  
    }  
}  
  
