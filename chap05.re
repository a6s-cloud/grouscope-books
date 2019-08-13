= 環境構築
== Linux 愛好家、Webアプリ畑に立つ
Web 画面を構築しエンドユーザーに魅力的なビジュアルや体験を与えるフロントエンドエンジニア。今話題となっているAngular、React、VueJS を使ったレスポンシブでインタラクティブな画面はユーザのみならず「自分もこんなものを作ってみたい」と開発者の創作意欲を掻き立て新しいフロントエンドエンジニアが誕生することもあります。現代のIT 技術者として花形の職業一種です。一方で真っ黒な画面に白い文字で英数字が降り注ぐ中で、キーボードのキーをカタカタと奏でては次々と新しい文字を生み出していく…。一見すると地味で何が面白いのか理解できなかったりする、でもそんな傍からの視線を気にすることもなく我が愛するコンピュータとコマンドと通じて直に会話することに虜になっている人もいます。そう、今回環境構築周りをメインに執筆させていただく私、つとむもその虜になってしまった人間の内の一人です。

そんな私ですがこんかいなおとさんの勧誘がありgrouscope の開発チームに加わることになりました。普段Linux ばかり触っていてLinux の流行を少しは知っているが現代のWeb アプリのことはあまり知らない属性の人間がどのようにWeb アプリ開発チームに加わって貢献できるだろうかと最初は難しさを感じていました。そんな中で私はバックエンド/サーバサイド側の環境構築をメインにやることになり、今回の作業を通じて技術要素の選定や立ちはだかった壁とその乗り越え方について色々学んでいくものがありました。今回の私が担当する記事はバックエンド/サーバサイドの内容がメインとなってしまいますが普段フロントエンドで開発をしていてコマンドラインは時々しか触れない人にも、普段からバックエンド/サーバサイドで開発していて慣れている方々にもわかりやすく楽しく書いていきたいと思いますので、どうかお付き合いいただければと思います。

== アプリケーションの概要
今回開発するgrouscope というアプリケーションはtwitterハッシュタグ分析プラットフォームとなるものです。ユーザはWeb 画面に任意のハッシュタグを入力することでそのハッシュタグがつけられているtweetの傾向を分析し、画像・グラフ・ランキングといった形式に変換して可視化し、ホットな情報を探したり見たりすることを可能にするものです。今回はREST なAPI サーバを建ててフロントエンドとバックエンドがやり取りするアプリの構成となったため、GitHub リポジトリをそれぞれ分けて作ることになりました。それに加えてWord Cloud 画像を生成するバッチスクリプトもリポジトリも分けて開発していくことになりました。そして最終的に作成されたgrouscope のGitHub のリポジトリは以下のようになりました。

 * grouscope-front
https://github.com/a6s-cloud/grouscope-front

 * grouscope-backend
https://github.com/a6s-cloud/grouscope-backend

 * grouscope-batch
https://github.com/a6s-cloud/grouscope-batch

=== フロントエンドの技術要素概要
フロントエンドの技術要素としてユーザインタフェースを構築するためのJavaScript フレームワークにVue.js を採用することになりました。Vue.js は現在日本でも活発に採用されるようになってきてGitHub Star 数も全GitHub リポジトリの中でも有数のものとなっており、その人気とコミュニティの活発さから日本語の情報多く転がっており使いやすいものとなっています。またUI のデザインや色、モーション等をつけるコンポーネントライブラリとしてElement を使用することになりました。Element を使うことでVue.js のコンポーネントとして使うことで綺麗なテーブルやリスト、入力フォームやボタン等を簡単に作成することができるようになっています。現在フロントエンドはこのような構成となっていますが、デザインの仕事をされているのなとさんが途中から加わったため、現在デザイン及びユーザインタフェースについては大改修中です。その時にはまた利用する技術要素も変わってくるかもしれません。

=== バックエンドの技術要素概要
バックエンドの技術要素として、まずはWeb アプリ開発者の間でも話題になっているDocker があります。開発期間中は各メンバのPC に開発中のアプリを実行するためのサーバを建てるために使っています。バックエンドのフレームワークとしてPHP のLaravel を使うことになりました。Laravel はレンダリングされたWeb 画面をユーザに返すように使われることもありますが、今回はREST なアプリとなるためレスポンスはJSON 形式でデータを返すAPI サーバとして利用していきます。Laravel はAPI サーバ用のフレームワークも備えているので、API サーバの構築も比較的簡単にできるようになっています。またLaravel を入れるコンテナには画像作成バッチを実行するためにPython も取り入れています。そしてDB にはMySQL、Web(リバースプロキシ) サーバにはNginx を使っています。

//image[chap05/architecture][フロントエンドとバックエンドの技術要素構成図][scale=1.0]

== 開発環境としてDocker を提案
チームが発足して初めて御徒町のいいオフィスで開発会議を開いた時の話です。自己紹介をして開発するアプリケーションが決め、フロントエンドの技術要素も決まったら次はバックエンドの環境を構築する話になりました。普段からLinux を触っている私の頭の中ではDocker を使う選択肢しかありませんでした。やっぱり流行りのDocker なのか…と言われるかもしれませんが、やはりDocker は魅力的でした。その時私の頭に浮かんでいたDocker を推す理由としては以下のものがありました。

 * 各メンバのPC 上に同じ開発環境の提供ができる
 * 開発環境のリストアが簡単で早い
 * 知名度があり提案しやすく、理解してもらいやすい

そして「開発環境はDocker にしましょう！」提案したところ、やはり皆さん普段から勉強しているエンジニアの方々。Docker を知っていて説明もスムーズに進みDocker で開発環境を作成することに決まりました。しかしDocker を使うというだけではバックエンドのアプリケーションを動かすエンジンを決めただけで何の言語でどいうったフレームワークアプリケーションを作成していくかといったことがまだ決まっていません。次はそれらを決めていく必要がありますがここで一旦、Docker がなぜWeb アプリケーションの開発環境として良いのかといったことについてもう少し詳細に述べさせてください。

=== ポータビリティ
Docker を利用する理由のひとつとしてはポータビリティ(可搬・移植)性です。通常のVM(仮想マシン) と比較したDocker (コンテナ)の利点として軽量さやパフォーマンスの点で述べられることもありますが、今回のケースではそれよりも先にあげたポータビリティ性が魅力的でした。

Docker ではポータビリティ性を実現するために、各メンバの手元にDocker イメージを配布するにはいくつかの方法があります。

 1. Docker Hub(registry) にイメージをpush し、メンバにpull してもらう
 2. Docker ファイルを配布してメンバの手元でビルドしてもらう
 3. docker save でコンテナをイメージとして固め、メンバに配布しdocker load してもらう

//image[chap05/0000_DeployDockerImage][Docker イメージ配布方法][scale=1.0]

個人的に推奨したいのは1 番目のDocker Hub を利用する方法です。Docker Hub は作成したDocker イメージをクラウド上で共有して利用できるようにしたサービスです。Docker イメージ作者はDocker イメージをビルドするための処理が書かれたDockerfile を使ったり、手元にあるDocker コンテナをdocker commit してイメージ化したものをDocker Hub にアップロード(push)することでイメージを公開して配布できるようになります。この本を読んでいる人の中にはWeb アプリ開発の環境構築やDocker を勉強し始めた時に、Docker のインストールが完了した直後にDocker デーモンの起動が成功したかどうかを確かめるために以下のようなコマンドを実行したことがある人もいるのではないでしょうか？

//cmd{
$ docker run hello-world
//}

このdocker run コマンドはhello-world イメージからコンテナを起動するコマンドでDocker が正常にインストールされて起動していれば「Hello from Docker(その他Welcome メッセージ)!」とターミナルに表示されます。docker run コマンドは手元に対象のイメージが存在しない場合は自動的にそれをpull してから起動するようになっています。ではこのpull してきたイメージはどこで管理され保存されているかというと、実はDocker Hub 上で管理されているのです。

//image[chap05/0001_DockerImageHelloWorld][引用 hello-world Docker イメージ(https://hub.docker.com/_/hello-world)][scale=1.0]

このようにDocker Hub でイメージが管理されていることで我々はインターネットに繋がっていれば簡単にイメージをpull してきてコンテナを起動することができるようになっているのです。Docker Hub でイメージを管理すればイメージ登録後、イメージ名を伝えることで他メンバにそのイメージをpull してもらいコンテナを起動することができるようになるのです。

一方でDocker イメージを公開したくない場合はDocker Registry で独自のリポジトリを建てたりDockerfile を配布する方法やdocker save とdocker load を使った方法を利用するのもありだと思います@<fn>{chenv_01}。
//footnote[chenv_01][2019年8月現在、Docker Hub の無料プランでも1つまでならプライベートリポジトリは作成可能です。有料アカウントであれば更に多くのプライベートリポジトリ作成することもできます。詳細はhttps://hub.docker.com/pricing]

=== 環境のリストアが簡単で早い
2つ目のDocker を利用する理由としてはDocker イメージのスナップショットの性質を利用した環境のリストアが簡単で早い点です。この性質は色々なスキルセットを持つメンバが利用する環境としてとても大きな利点があります。例えばとあるメンバが開発中のプログラムに対して誤った改修を入れたりチャレンジングな設定変更をしてデータや環境を破損してしまったとしましょう。自分のマシン上にNginx やMySQL サーバを直接インストールしていた場合はサーバの再インストールであったりエラー箇所を追跡して正しく動くように戻したり、バックアップを事前にとっておきそれを使ってリストアする必要があるでしょう。またVM を使っていた場合はディスクイメージをバックアップとして取得しておき、そのディスクイメージをもう一度手元にコピーし直して再起動することで復旧できるかもしれませんが、ディスクイメージはたいてい数GB 〜 数十GB になることもざらにあり結構コストが高かったりします。一方Docker ではコストの高いコピー処理もなく「コンテナを削除することで状態をリストアする」という異なるアプローチで環境をリストアすることができるのです。

「コンテナを削除することで状態をリストアする」とはどういう意味なのでしょうか？それを知るにはDocker のイメージとコンテナの違いを理解する必要があります。一言で例えていうならばDocker イメージは読み取り専用でDocker コンテナは読み書き両方できるオブジェクトになります。コンテナを起動するとアプリケーションの実行ファイルのような更新が発生しない読み取り・アクセスのみで良いファイルやデータについてはイメージから読み取られ、アプリケーションによってファイルが作成されたりファイルが更新されたりするときはコンテナ内にそれらを複製して持ってきてコンテナ内の情報のみ変更するようになっているのです。結果としてファイルやデータの作成や変更はコンテナ上でのみ起こっていることで、イメージの状態は全く変わらないことになります。そのためユーザーは状態を元に戻したいと思ったら動いていたコンテナを削除してもう一度イメージからコンテナを起動し直せばよく、バックアップから大量の情報をコピーしてくるといったコストのかかることはしなくて済むようになっているのです。

//image[chap05/0001_FigureOfImageAndContainer][Docker 環境のリストアイメージ][scale=1.0]

==== Docker のイメージとコンテナの性質を体験してみる
Docker イメージとコンテナの違いを実際にコマンドを打って体験してみることにしましょう。まずは次のようにdocker run コマンドを実行してAlpine Linux コンテナを起動します。以下のコマンドはAlpine Linux イメージが無い状態から実行していることを想定しています。

//cmd[docker run でAlpine Linux(紙面の都合上一部変更)]{
$ docker run -ti alpine sh
Unable to find image 'alpine:latest' locally
latest: Pulling from library/alpine
050382585609: Pull complete 
Digest: sha256:6a92cd1fcdc8d8cdec6......4a9b5998
Status: Downloaded newer image for alpine:latest
/ # 
//}

するとalpine Linux のイメージがpull されコンテナが起動してシェルのプロンプトが表示されます。Linux に画面とキーボードを直接接続したりSSH でroot ユーザとしてログインしているのと同じような状態です。ここで適当にファイルを作成してみましょう。以下のコマンドはアプリケーションが/var/log ディレクトリ下にyourapp.log というファイルでログを出力した状態を想定しています。

//cmd{
/ # echo "An application said. 'Hellow world'" > /var/log/yourapp.log
/ # ls -l /var/log/yourapp.log
-rw-r--r--    1 root     root            nn MM DD hh:mm /var/log/yourapp.log
/ # cat /var/log/yourapp.log
An application said. 'Hellow world'
//}

/var/log/yourapp.log ファイルが作成されました。ここでDocker コンテナのセッションを終了してみましょう。

//cmd{
/ # exit
//}

するとDocker ホスト側にプロンプトが戻ります。この状態でイメージとコンテナの状態を確認してみます。

//cmd[紙面の都合上一部出力内容を修正]{
$ # イメージの確認
$ docker images
REPOSITORY  TAG     IMAGE ID      CREATED      SIZE
alpine      latest  b7b28af77ffe  3 weeks ago  5.58MB
$ # コンテナの確認
$ docker ps -a
CONTAINER ID  IMAGE   COMMAND  CREATED  STATUS      PORTS  NAMES
c29ef7560eaa  alpine  "sh"     -        Exited ...  vibrant_lumiere
//}

すると先程pull したイメージと起動したコンテナが表示されます。ただしこのコンテナは"STATUS" の項目を見るとわかるとおり、シェルのセッションを抜けた約2 秒前に停止しているコンテナになります。コンテナはそのコンテナ内で起動しているメインプロセスが停止すると、コンテナ自体も終了する仕組みになっています。そのため先程の例ではdocker run でsh のメインプロセスが起動してログアウトすることでメインプロセスが終了して、コンテナも終了するようになっています。次にコンテナ名を見てみると"vibrant_lumiere" という名前がつけられています。これはコンテナを作成するたびにランダムにつけられる名前となり、コンテナをもう一度起動したり削除したりする時に指定できるものになります。それでは次に、docker start コマンドでこのコンテナをもう一度起動してみましょう。

//cmd[]{
$ docker start vibrant_lumiere
vibrant_lumiere
$ docker ps
CONTAINER ID  IMAGE   COMMAND  CREATED  STATUS        PORTS  NAMES
c29ef7560eaa  alpine  "sh"     -        Up 3 seconds         vibrant_lumiere
//}

docker start を実行すると先程のコンテナでsh プロセスが起動しますので、このsh プロセスにアタッチして先程作成したファイルが残っていることを確認しましょう。

//cmd{
$ docker attach vibrant_lumiere
/ # cat /var/log/yourapp.log
An application said. 'Hellow world'
//}

ファイルがありました。先程作成したファイルはコンテナ内に残り続けていることがわかります。ここでもう一度ログアウトしてコンテナを停止し、コンテナを削除してみましょう。

//cmd[紙面の都合上一部出力内容を修正]{
/ # exit
$ docker rm vibrant_lumiere
vibrant_lumiere
$ docker ps -a
CONTAINER ID  IMAGE   COMMAND  CREATED  STATUS      PORTS  NAMES
c29ef7560eaa  alpine  "sh"     -        Exited ...         vibrant_lumiere
//}

コンテナが削除されました。このコンテナの削除をもって状態のリストアは完了です。それではもう一度コンテナをdocker run コマンドから起動してみましょう。

//cmd{
$ docker run -ti alpine sh
/ # 
//}

Alpine Linux のコンテナが起動してsh のセッションに入りました。先程と違う点としては"Pulling from library/alpine" という文言が消えてイメージのpull が行われていない点です。これは一番最初にdocker run コマンドを実行した時にイメージは手元に落とせているため、そのイメージからAlpine Linux コンテナを起動したことになります。イメージをダウンロードする必要が無いので先程よりもすばやくコンテナを起動することができます。ここで先程のファイルの存在を確認してみましょう。

//cmd{
$ docker run -ti alpine sh
/ # cat /var/log/yourapp.log
cat: can't open '/var/log/yourapp.log': No such file or directory
//}

ファイルが無いためエラーとなりました。これは初期のAlpine Linux の状態に戻っているためです。このようにDocker ではコンテナを削除することで状態を元に戻すことができるため低コストで素早く、そしてバックアップを管理する必要もなく状態を元に戻せるようになっています。

== フレームワーク実行環境の選定
閑話休題、Docker を使うことが決まったので次はバックエンドのWeb アプリケーションフレームワークを決める話題になりました。その時トキさんが「Laravel 使いたい！」と提案してくれました。普段PHP を使ったことがない私でも聞いたことはあり、当時会議に参加していたメンバも全員知っており異論無しですんなりと決まりました。

Laravel はPHP で動くフルスタックなフレームワークでルーティングやコントローラ、ビュー、ORM も含んでいて且つAWS のS3 をストレージとして使うことを前提としたオプションも含まれていたりと至れり尽くせりなフレームワークです。今回はそのLaravel をフロントエンドのVue.js で組まれたプログラムにJSON で結果を返すREST 構成とすることに決まりました。もちろんLaravel にはAPI サーバの機能もあるためそのあたりの実装についても簡単に実装できるようになっています。

== Laradock との出会い
フレームワークとしてLaravel を使うことが決定したので次はその環境をどのようにしてDocker で準備するかという流れになりました。自力でDockerfile を作成してイメージをビルドするのも良いですが、私には隙間時間に進めていくプロジェクトであったことを考慮して、できるだけコストのかかる方法は回避しようと思っていました。Laravel は有名であることもあり、既に完成度の高いLaravel のDocker イメージを作成して配布している人がいるはずだと漠然と考えていました。それをメンバに伝えた所、メンバ全員でDocker イメージを探す作業に入っていきました。するとトキさんがまたやらかしてくれました。「Laradock@<fn>{chenv_01_laradock} がありますよ！」。
//footnote[chenv_01_laradock][https://laradock.io/]

Laradock はDocker 環境上で実行できるPHP 開発環境です。環境が整備済みなPHP 環境以外にも様々なDocker イメージをサポートしており、PHP アプリケーションを開発するための懇切丁寧なDocker 資材のセットとなっています。Laradock を使えばLaravel 環境が手軽に自分の手元に準備できるのは当然のこと、やはりコミュニティが活発でDockerfile やドキュメントのメンテナンスもしっかり行き届いているので、今後使い続けるのにも良いチョイスでした。LEMP @<fn>{chenv_02}構成に加えてRedis、Mongo DB、メールサーバ等のイメージも必要に応じて準備できるようになっており、今後のことも考えると当時選ばない理由はありませんでした。
//footnote[chenv_02][Linux、Nginx、MySQL、PHP な構成のこと。LAMP のApache がNginx に変わった]

=== ちょっと手元でLaradock を動かしてみよう
Laradock を使うと簡単にPHP 及びLaravel 環境を準備できます。とりあえずLaravel のトップ画面を表示するだけであれば以下のようにコマンドを実行することで用意できます@<fn>{chenv_03}。なお、事前にDocker はインストールしておくようにしてください。
//footnote[chenv_03]["Do not run Composer as root/super user! See https://getcomposer.org/root for details" といった警告が出るかもしれませんが今回は無視して進むことにします]

//cmd{
$ mkdir -p laravel/laravel
$ cd laravel
$ git clone --depth 1 https://github.com/laradock/laradock.git
$ cd laradock
$ cp env-example .env
$ sed -i -e 's|APP_CODE_PATH_HOST=.*|APP_CODE_PATH_HOST=../laravel|' .env
$ docker-compose up -d nginx
$ docker-compose exec --user laradock workspace bash -c "cd /var/www && composer create-project laravel/laravel ."
$ docker-compose exec php-fpm chown -R www-data:www-data .
//}

コマンドを実行したらWeb ブラウザを開いてhttp://localhost にアクセスしてみましょう。Laravel のwelcome page が表示されます。
//image[chap05/0003_LaravelWelcomePage][Laravel のwelcome page][scale=1.0]
#@+++
TODO: welcome page が表示されます... の直後に@<img>{chap05/0003_LaravelWelcomePage} として参照画像の番号を入れたいが図の番号がずれる。保留
#@---

もし既にLaravel アプリケーションが用意できていてそれがGit で管理できているなら、次のようにコマンドを実行することでLaradock でアプリケーションを走らせることができます。今回はLaravel のアプリケーションとしてniwasawa 氏のphp-laravel-hello-world@<fn>{chenv_03_laravel_hello_world} を使ってコマンドを実践していきたいと思います(この場を借りて感謝いたします<(_ _)>)。
//footnote[chenv_03_laravel_hello_world][https://github.com/niwasawa/php-laravel-hello-world]

//cmd{
$ git clone https://github.com/niwasawa/php-laravel-hello-world.git
$ cd php-laravel-hello-world
$ # DB 接続先等の設定が必要な場合は、ここで.env ファイルの変数を修正しておきます(今回は割愛)
$ git submodule add https://github.com/Laradock/laradock.git
$ cd laradock
$ cp env-example .env
$ # mysql も必要な場合はmysql も追加してdocker-compose up します
$ docker-compose up -d nginx
$ docker-compose exec workspace composer install
$ docker-compose exec workspace php artisan key:generate
$ docker-compose exec php-fpm chown -R www-data:www-data .
//}

以上で準備は完了です。Web ブラウザを起動してhttp://localhost/hello/ にアクセスしてみましょう。

//image[chap05/0004_LaravelHelloWorld][Laravel のHello World(https://github.com/niwasawa/php-laravel-hello-world.git)][scale=1.0]

図のように画面が表示されれば成功です。既存のLaravel アプリケーションも簡単にLaradock へ移行できるようになっているのです。決して上から目線ではないですが、私のようにLinux 経験が長い人からすると自分で環境構築するほうが後々カスタマイズ性もあって便利では無いかと考えることもあるかもしれませんが、寄せ集めのメンバであったりスタートアップで限られた資源で開発をしている場合は有識なサーバサイドエンジニアが身近にいなかったりするかもしれません。そういった場合にまずはlaradock を使って開発環境を用意してみる、という時にLaradock は非常に便利です。またドキュメントをじっくり読んでみるとわかるのですがLaradock の仕様や文化を理解するイニシャルコストはありますが、アプリケーション開発者のあらゆるニーズに答えられるようになっているのでサーバサイドの経験が長い人にとっても時間短縮のために利用したりLaradock の複雑なDocker イメージの組み合わせ(例えばMongoDB との接続やRedis との接続など)をDockerfile やdocker-compose.yaml を見て勉強したり、複雑な構成のテスト環境を手早く準備するのに役立つことでしょう。

=== Laradock の構成図
Laradock を起動させたところで、一旦docker ps コマンドを実行してコンテナを見てみましょう。するとLaradock が複数のコンテナから構成されている事に気付く事でしょう。

//cmd[紙面の都合上、一部出力を変更]{
$ docker ps
CONTAINER ID  IMAGE        COMMAND  .  STATUS    PORTS  NAMES
8b407ee12c7a  l_nginx      ...      .  Up n sec  ...    laradock_nginx_1
f5dc49dae496  l_php-fpm    ...      .  Up n sec  ...    laradock_php-fpm_1
a9cdaae0a76a  l_workspace  ...      .  Up n sec  ...    laradock_workspace_1
44641c8fee0b  l_mysql      ...      .  Up n sec  ...    laradock_mysql_1
//}

これらのコンテナがどのように関わり合っているかということを図で示すと次のようになります。

//image[chap05/0005_LaravelStructure][Laravel の構成図][scale=1.0]

取り敢えずLaravel のアプリケーションを走らせるだけであればこれらの構成を深く気にする必要はありませんが、プロジェクト固有のカスタマイズが必要になってきたり一時的に環境設定を変更したい場合にも対応できるよう概要は理解しておいて損はないでしょう。現に我々のプロジェクトではLaravel から外部コマンドとしてPython 製のスクリプトを動かすためにLaradock 環境のカスタマイズは必要でした。

ネットワークを見てみると本番環境と遜色ないDMZ とその裏側にあたるイントラネットがDocker network にて構成されています。nginx コンテナはリバースプロキシサーバとしてDMZ に置かれ、裏側のイントラネットワークに位置するphp-fpm(Laravel) コンテナに対して代理でリクエストをするようになっています。先程Laradock をビルドしてLaravel のWeb ブラウザでトップページを表示しましたが、その時のリクエストはまずnginx コンテナに届きリバースプロキシされてphp-fpm コンテナからページが取得されていました。

またworkspace というLaravel アプリケーションとは一見関係なさそうなコンテナが存在します。これはphp-fpm コンテナの作業スペースとなるコンテナで、このコンテナに乗り込むことで別コンテナとして起動するphp-fpm のファイルリソース類に対して透過的にアクセスできるようになっています。またこのコンテナにはcomposer をはじめとしたツールセットが盛り込まれており、composer による新規Laravel プロジェクトの作成やartisan コマンドによるLaravel ユーティリティの利用、xDebug (ビルド時のオプションで指定が必要)を使ったデバッグ実行といったことができるようになっています。このようにLaradock では数回のコマンドで本番環境さながらなネットワークを構築して開発に集中できるよう環境が整った作業スペースまでをも提供してくれる、まさに至れり尽くせりなリソースセットなのです。

== 依存性管理
package.json、composer.json、pom.xml。NodejsやPHP、Java などのプロジェクト開発でこういった名前のファイルをみた事がある人も多いかもしれません。これらのファイルはプロジェクトの名前や設定情報、ビルドやテストするための命令を管理する一方でプロジェクトが必要としている依存モジュールについても管理しています。grouscope にもそのような依存性管理の方法が必要でした。

grouscope は複数のgit で管理されているプログラムに依存しており、具体的には以下のものがあります。

 * Laradock: Laravel の実行及び検証環境
 * grouscope-batch: word cloud API を呼び出すPython 製スクリプト
 * RictyDiminished: word cloud 画像に埋め込む文字フォント

昨今はマイクロサービスという言葉が出てきて、個々に作成されたサービスやアプリケーションを部品として組み込んで1 つのサービスやアプリケーションとして成り立たせていくという開発の手法が騒がれています。grouscope のバックエンドアプリケーションもそれ単体では動かすことができず、ツイート内容を可視化するgrouscope-batch プロジェクト(内部でamueller氏の word_cloud@<fn>{chenv_03_git_word_cloud} を使用)と画像に文字を入れるためのフォントファイルRictyDiminished (edihbrandon 氏のリポジトリのもの@<fn>{chenv_03_git_ricty_diminished}を使用)を必要としていました。そしてLaravel アプリケーション実行環境としてLaradock も必要なものとして追加されました。このように必要な要素が多くなってくるとこれらをどのように管理していくかが課題になってきました。
//footnote[chenv_03_git_word_cloud][https://github.com/amueller/word_cloud]
//footnote[chenv_03_git_ricty_diminished][https://github.com/edihbrandon/RictyDiminished]

=== 簡単なスクリプトで管理する方法
grouscope リポジトリ作成したての頃はそれらの依存関係を管理する仕組みがありませんでした。原始的で手っ取り早く依存性を管理するなら普段Linux でbash を触っている私からしたら、以下のようなファイル(requirements.txt)とスクリプト(install.sh)を作成する事でしょうか。

//list[requirements.txt][requirements.txt]{
https://github.com/laradock/laradock.git
https://github.com/nsuzuki7713/a6s-cloud-batch.git
https://github.com/edihbrandon/RictyDiminished.git
//}

//list[install.sh][install.sh]{
#!/usr/bin/env bash
while read r; do
    rm -rf "$(basename ${r%.*})" && git clone "$r"    # rm の使い方が怖い…
done < ./requirements.txt
//}

このようにすれば依存関係にあるgit リポジトリをclone してくれます。しかしこれではまだ問題があります。

=== 再帰的に依存モジュールを取り入れる事ができない
もし依存モジュールに更に依存モジュールがあった場合、先程のスクリプトではそれらをダウンロードできません。しかもそれぞれのプログラム作者が今回の例のように完全独自ルールな依存性管理スクリプトを自作していた場合、そのプログラムを依存モジュールとして使う他の開発者にそのスクリプトの仕様を理解させるという重労働を課してしまうことになります。

//image[chap05/0011_FigureOfDependentModules][依存関係の依存までダウンロードできない][scale=0.9]

=== 取得してくる依存モジュールのバージョンが安定していない
多くの人から利用されている人気モジュールは世界中のユーザーから機能のリクエストがあったり仕様の改善やバグフィックスが頻繁に行われています。先程のスクリプトではパージョンタグやコミットを指定することなくgit のリポジトリをクローンしています。結果としてmaster ブランチの最新コミットを常にダウンロードしてくることになり、これではメンバによってアプリケーションをビルドする日時の違いによって成功したり失敗したりと安定しない状態となってしまう可能性があります。

//image[chap05/0012_FigureOfVersionOfModules][依存関係のバージョンまで管理できていない。ビルド日時によって成功・失敗が左右される][scale=0.65]

=== git submodule を使う
これらの問題を解決するためには自作のスクリプトではなくでgit submodule を使うことにしましょう。例えばgrouscope-batch を依存関係としてあなたのgit リポジトリに追加する場合は以下のようにコマンドを実行します。

//cmd{
$ git submodule add https://github.com/a6s-cloud/grouscope-batch.git grouscope-batch
$ git commit -m "grouscope-batch を依存モジュールとして追加"
$ git push origin HEAD
//}

これで依存関係の追加は完了です。次は他メンバのPC にてこの依存関係を手元に落としてくるにはgit submodule update コマンドに--recursive オプションをつけて実行します。

//cmd{
$ # 事前にpull(fetch やmerge) を実行しておく
$ git submodule update --init --recursive
//}

これで他メンバにも依存関係のgit リポジトリが手元に落とされるようになります。そしてgrouscope-batch リポジトリも依存するsubmodule がある場合は、このコマンドを実行することで再帰的にその依存モジュールも落とされるようになっています。またsubmodule として落とされたgrouscope-batch ですが参照しているコミットはgit submodule add コマンドを実行した時点のmaster ブランチの最新となっており、この参照先コミットは固定です。すなわちgrouscope-batch の開発が今後進んで新しいコミットがされようとも、バージョンアップして仕様が大幅改変されようともsubmodule として取得されるgrouscope-batch のコミットは同じで中身が変わりません。そのため依存モジュールのアップデートによる想定外のエラーや障害が発生するといったリスクを抑えることができるようになっています。またここでは説明を割愛しますが、特定のバージョン(tag)やコミットに対しても参照を設定することができるので、やはり独自のスクリプトで管理するよりもgit submodule として管理するのが懸命でしょう。

== Laravel 環境のカスタマイズ
ツイート内容を集計して画像を作成するgrouzcope-batch では内部でwordcloud を使用しているためPyfhon の環境を整える必要がありました。Laradock はPHP やLaravel に特化した環境なのでPython の環境は我々で考えて構築する必要がありました。ただ幸いにもLaradock はDebian 系のLinux ディストリビューションを採用@<fn>{chenv_04}しているので、環境構築のための情報も多くいくつかコマンドを実行すれば環境が構築できることがわかりました。またgrouscope ではMysql 8 を使っていましたが、認証方式のデフォルトが変更されていてLaravel からの認証が通らないなどの事態が発生していました。それらの問題をひとつひとつ解消するために私がとった行動はこれらをbash スクリプトで全て解決しようという試みでした。そしてできたbash スクリプトの一部が下記のようなスクリプトです。
//footnote[chenv_04][Docker ファイルを追っていくとphp-fpm をベースにしており更に追っていくとDebian を使っている事がわかる]

//emlist[docker のMySQL コンテナに無理やりSQL を送っているbuild スクリプト(ゲシュタルトの崩壊)]{
# ......
docker-compose exec mysql bash -c '
  # ...(略)...
  MYSQL_PWD="${DB_PW_ROOT}" mysql -u root \
    <<< "ALTER USER '"'"'default'"'"'@'"'"'%'"'"' IDENTIFIED WITH mysql_native_password BY '"'"'secret'"'"';"
  MYSQL_PWD="${DB_PW_ROOT}" mysql -u root \
    <<< "GRANT ALL ON ${DB_NAME}.* TO '"'"'default'"'"'@'"'"'%'"'"';"
'
# ......
//}

Docker ホスト側からコンテナ側に対してSQL を発行していますが、このようにbash と標準入力や引数を駆使することでコンテナ側のコマンドを呼び出す事ができます@<fn>{chenv_05}。戦略によっては一旦Laradock のイメージを普通にビルドして、それに対して我々で作成したDockerfile でgrouscope 専用のイメージをビルドする形式も取れましたが、当時はそこまでカスタマイズ規模は大きくならないだろうと思ってbash で小手先な対応をしていました。今となっては黒歴史です。
//footnote[chenv_05][決してこのような書き方を推奨するものではありません]

== 俺の環境では動いたのだよ俺の環境では
メンバの開発環境PC のOS はMac かLinux でどちらもbash 環境が整備されているので、ゴリゴリと環境構築スクリプトを作っていいきました。その環境構築スクリプトがコテコテになっていったところで、トキさんからSlack で報告をいただきました。
//image[chap05/0013_AReportFromToki][トキさんからいただいた報告][scale=1.00]
なんとスクリプトでエラーが出て動かないという内容でした。OS はトキさんがMac で私がLinux。OS は違くともどちらもbash 環境を備えていました。まとトキさんと同じMac 環境であるなおとさんの手元ではビルドは成功していると報告を受けています。そんなはずは無い…と思いながらも原因究明のための調査に入りました。

=== エラーの原因とは
トキさんから戴いたコンソールの出力を確認したところ、MySQL の初期化処理でエラーが出ているようでした。

//cmd{
NOTICE: mysql データを初期化しています。
ERROR: No container found for mysql_1
## Stack Trace ########################################################
Error in ./build.sh:124. 'docker-compose exec mysql bash -c '
        # (一部内容省略)
        echo ">>> sql: CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
        MYSQL_PWD=${DB_PW_ROOT} mysql -u root <<< "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
        # (一部内容省略)
    '' exited with status 1
Call tree:
 1: ./build.sh:118 init_mysql_db(...)
 2: ./build.sh:47 build(...)
 3: ./build.sh:247 main(...)
Exiting with status 1
//}

これはMySQL のコンテナに対してmysql コマンドでSQL を流してDB のデータを初期化処理の部分エラー出力です。一見するとMySQL コンテナが見つからないという内容のエラーに見えます。しかし私が作成ビルドスクリプトでは"mysql_1" という名前のコンテナを指定している箇所は無いため、そのコンテナが見つからないというエラーメッセージは想定外…スクリプトの中身というよりは何か想定外の環境によるエラーと推測していました。そして一方で同じMac を使っているなおとさんのMac 環境では成功しているという報告をいただいていてトキさんのMac 環境では失敗しという状況でした。そこで色々お話を聞いたところ、トキさんがやっている他の開発プロジェクトでもLaradock を使っているという情報を得る事ができました。

=== Docker を使った場合の永続的なデータの取り扱い
Docker ではコンテナ上にあるデータはコンテナを削除してしまうと消えてしまいます。Docker を使う、特に開発環境として利用されるシーンではコンテナが削除されること(コンテナがいつまでも残っているとは限らないこと)を前提にしている事が多いため、もしコンテナ上で更新されたり削除されたりするデータを永続的に保持しておきたい場合は工夫が必要です。その戦略の一つとして、Docker ホスト側のディレクトリをDocker コンテナ側にマウントする方法があります。

//image[chap05/0014_DockerVolume][Docker ボリュームのイメージ図][scale=0.90]

ホスト側のディレクトリをコンテナ側のディレクトリにマウントする事でデータの書き込みはコンテナ上のファイルではなくてホスト側のファイルに書き込まれるようになります。この状態でコンテナを削除すれば失われる情報はコンテナ上の情報だけなので、マウントしてホスト側に書き込まれたファイルは残り続けることになります。

この性質を利用して例えばMySQL のプログラムのバイナリ(実行ファイル)はコンテナ上に置いておき、DB のデータファイル本体はホスト側にマウントしたディレクトリに置くことで更新されたDB データはコンテナを削除しても残しておく事ができるようになります。また新規コンテナを立ち上げる時も同じディレクトリをマウントするようにしていれば、過去のコンテナで更新されたデータを引き続き活用する事ができるようになるのです。

=== Laradock ではどうなっていたか
Laradock は標準でDocker ホスト側の~/.laradock/data ディレクトリをMySQL のデータディレクトリとしてコンテナ側でマウントしてデータを永続化するようになっています。これは時と場合によっては問題を引き起こす可能性があります。

例えばLaradock を使っているプロジェクトA とB があったとして、プロジェクトA でMySQL のユーザ名default、パスワードsecret を使っていたとします。またプロジェクトBでもMySQL を使っており、ユーザー名default パスワードpasswd を使っていたとします。そしてMySQL の認証情報としてプロジェクトA のユーザ名default パスワードsecret が設定されていた場合、プロジェクトBのLaradock コンテナを起動してDB にアクセスが発生した時に認証エラーが起こるでしょう。

(エラーを完全に特定できたわけではありませんが)今回のトキさんのエラーの件は一旦~/.laradock/data ディレクトリを削除してLaradock コンテナも一旦すべて削除してを再起動することで解消しました。

=== どうすればよかったか
Laradock には永続化するデータを格納するホスト側ディレクトリを.env ファイルのDATA_PATH_HOST で指定する事ができます。Laradock コンテナ起動前にこの変数を変更して他のLaradock を使っているプロジェクトと被らない場所を指定するようにしましょう。この値には相対パスも指定する事ができます。なのであなたのLaravel プロジェクトにLaradock をgit submodule として取り入れて以下のように相対パスを指定しておけば、git リポジトリのディレクトリ内にDB のデータも含めておく事ができます@<fn>{chenv_06}。
//footnote[chenv_06][その場合、データディレクトリをコミットしないように.gitignore に含めておくようにしましょう]

//emlist[Laradock の.env のDATA_PATH_HOST に相対パスを指定する例]{
DATA_PATH_HOST=./.laradata
//}

このようにしておけばメンバのPC に複数のLaradock を使うプロジェクトがあったとしても、各プロジェクトのgit リポジトリのディレクトリ内にデータが納まることになり、永続化データの競合を回避することができます。また、このようにすることによってローカルのgit ディレクトリを削除することによりMySQL のデータも一緒に消えてくれるようになります。

== ビルドスクリプトの終焉
現状Laravel の環境構築をbuild.sh という独自なbash スクリプトを使って管理していると以下のような問題が出てきました。

 * 他プロジェクト等でlaradock のMySQL 環境が使われていたりするとデータや設定が混在してしまう可能性がある
 * build.sh が実行される環境のbash バージョン差異によるエラー
 * OS 環境が人それぞれ異なり基本コマンドも違う

(1)に関しては前項で述べた通りのエラーで、Laradock の永続化データ保存ディレクトリが他のLaradock を使っているプロジェクトと被ったりすることで発生しうる問題です。(2)、(3)についてはもう少し詳細に見ていくことにしましょう。

=== build.sh 実行環境のbash バージョン差異によるエラー
bash はMac にもLinux も入っている場合が殆どで、私が普段使っているArch Linux もbash が入っています。bash は安定していてスクリプトを作成するのに役立つ便利な仕様や機能も多く備わっています。例えば以下のような書き方をする事で変数の中のアルファベット文字列を一律で大文字に変換する事ができます。パイプなどを使って他の文字列操作系のコマンドに値を渡さなくてもこのような文字列変換ができるようになっています。

//emlist[upper_string.sh]{
#!/bin/bash
something="Foo Bar"
echo ${something^^}        # FOO BAR
//}

しかしこれが問題を引き起こす可能性もありました。私の手元のLinux にて実行すると想定通り"FOO BAR" という結果が得られます。しかし一部の環境では以下のようなエラーが出るかもしれません。

//cmd{
$ something="Foo Bar"
$ echo ${something~~}
bash: ${something~~}: bad substitution
//}

上記のような違いが出るのはなぜでしょう？既に答えがわかっている人もいるかもしれませんが、この記法はbash 4系から取り入れられた書き方でbash 3系で実行すると出るエラーです。bash 3系は今から10年以上前のバージョンのbash で入っている環境のほうが少ないのではと思われますが、実はMac の現在(2019年08月執筆時点)のデフォルトシェルはbash 3系となっています@<fn>{chenv_07}。Mac が現在もbash 3系をデフォルトシェルとしているのはGPLv3ライセンスのためではないかと言われています@<fn>{chenv_08}。このように昔のバージョンのbash を使っている人はもういないだろうという考えから、安易にbash スクリプトを組んでしまうとエラーに出くわしてしまう危険性があります。このバージョン問題に関してはbash に限らず他の言語においても同様です。今回のケースに関してはチームメンバに呼びかけてbash をアップデートしてもらうようにするのが良いでしょう。そして作成者側としてはbash に限らずプログラムを作成したら実行される環境を想定したテストを実施し、低いバージョンでも動くように改修するか、対応するバージョンを明確に仕様として定義しておくようにすると良いでしょう。
//footnote[chenv_07][Mac デフォルトのシェルが2019年秋のCatalina からzsh になるようです。この書籍が皆さんの手元に届く頃には変わっているかもしれません(引用: https://www.theregister.co.uk/2019/06/04/apple_zsh_macos_catalina_default/)]
//footnote[chenv_08][先程示したURL に書かれています(引用: https://www.theregister.co.uk/2019/06/04/apple_zsh_macos_catalina_default/)]

=== OS 環境が人それぞれ異なり基本コマンドも違う
同じbash バージョンを持っていたとしても、結局はbash スクリプトの中ではメンバのOS 環境にあるコマンドとなります。Mac とLinux のコマンドは一見すると同じようでも実はMac はBSD からのコマンドを多く採用していたりLinux ではGNU Cor Utilities からのコマンドを採用している等の理由から細かい部分で異なり、とても厄介なものとなります。これらがどのように厄介なのかという具体例については言葉で語るよりも実例を見て説明したほうがわかりやすいだろうということで、いくつかのMac とLinux のコマンドに関する問題を解いてみることにしましょう。この問題はコマンド実行環境として環境としてMac とLinux があったとして...

 * 両方でエラー無く動くもの
 * Mac でエラー無く動くがLinux でエラーが出るもの
 * Linux でエラー無く動くがMac でエラーが出るもの

がこの中に含まれています@<fn>{chenv_10}。ここではコマンドのオプションを厳密に識別しやすくするために半角スペースを"␣"で表現するようにしています。

//footnote[chenv_10][条件を上げるとキリがないですが、Mac についてはMojave 標準のコマンド、Linux についてはUbuntu Desktop 18.04 標準インストール時点の環境とします。初期状態でコマンドがない場合はMac はbrew、Ubuntu はapt-get でインストールしてきたものを使用するとします]

//emlist[(1)POST メソッドでlocalhost サーバにリクエストを飛ばす]{
# サーバ自体は常に200 OK を返すものとする
curl http://localhost/api/v1/AnalysisRequests \
    -D - --data-binary @- <<< "analysis_word=#技術書典"
//}

//emlist[(2)正規表現を使い複雑な名前のファイルを検索して権限を変更するfind コマンド]{
# カレントディレクトリ以下のファイル全てに対してchmod する権限はあるものとする
find␣.␣-type␣f␣-regextype␣posix-extended␣\
␣␣␣␣-regex␣'^.*/access_[0-9]+\.gz$'␣-exec␣chmod␣644␣{}␣\;
//}

//emlist[(3)file.txt ファイル内の文字列置換。バックアップファイルは不要なので""を指定するsed コマンド]{
# カレントディレクトリにはfile.txt のみがあり、読み書き権はあるものとする
sed␣-i␣""␣-e␣"s/^Foo/Bar/g"␣file.txt
//}

コマンドを見ただけでエラーとなるかどうか、またエラーの理由がわかる人はいますでしょうか？もしわかったとしたらかなりの訓練をされたエンジニアだと思います。では、答えを上から順番に解説していきます。

(1)ですが、これは「両方でエラー無く動くもの」となります。curl コマンドはBSD やGNU にも管理されていないコマンドでありながら、Mac にもLinux にもHTTP のリクエストを行うためのコマンドとして比較的一般にインストールされているコマンドになります。BSD(Mac) かGNU(Linux) かに関係なくcurl 自体は独立しているので大きくバージョンが離れたりしていない限りは異なるOS 間でも使えるオプションやコマンドの書式は同じになります。今回のコマンドについてもMac かLinux かで大きく違いは出ないため、どちらの環境においても正常に実行できるコマンドになります。

(2)については「Linux でエラー無く動くがMac でエラーが出るもの」になります。Mac で実行しようとすると下記のようなエラーが出ます。
//cmd{
$ find . -type f -regextype posix-extended \
     -regex '^.*/access_[0-9]+\.gz$' -exec chmod 640 {} \;
find: -regextype: unknown primary or operator
//}
"-regextype" というオプションが無いようです。find コマンドはMac もLinux もIEEE Std 1003.1 @<fn>{chenv_11}に基づいていますので基本的に同じオプションが使えるようになっています。しかし、例外的にfind コマンドの正規表現オプションについてはMac とLinux で異なるのです(その他にもいくつかあるかもしれません)。理由までは見つけることができませんでしたが、少なくともMac で同様な正規表現オプションを利用する場合は"-E" オプションが使えます。
//cmd{
$ find -E . -type f -regex '^.*/access_[0-9]+\.gz$' -exec chmod 640 {} \;
//}
このようにIEEE Std 1003.1 を基にしているからといって必ずしも全てのオプションまで一緒とは限らないものも潜んでいたりしますので注意が必要です。
//footnote[chenv_11][エディション違いはあるかもしれませんが、IEEE Std 1003.1 のfind コマンド2018年エディションは http://pubs.opengroup.org/onlinepubs/9699919799/utilities/find.html]

最後に(3)ですが、これは「Mac でエラー無く動くがLinux でエラーが出るもの」になります。Linux で実行した場合の結果は以下のようになります。
//cmd{
$ sed -i "" -e "s/^Foo/Bar/g" file.txt
sed: can't read : No such file or directory
//}
1 点補足ですが、このコマンドは上記のエラーが出ても想定通りの挙動をしており、file.txt 内の文字列置換は成功します。ただエラーが出るのです。これもMac とLinux の基本コマンドの差異により出るものですが、Linux の場合は上記のように指定すると""(空文字)という名前のファイルと"file.txt" という名前のファイル2 つに対して文字列置換を行おうとします。が、""(空文字)という名前のファイルが無いのでそちらについては失敗しているというエラーメッセージになります。Linux でエラー無く想定通りの処理をするには以下のようにオプションの形式を変更します。
//cmd{
$ sed␣-i""␣-e␣"s/^Foo/Bar/g"␣file.txt
$ # or
$ sed␣-i␣-e␣"s/^Foo/Bar/g"␣file.txt
//}
1 つ目のコマンドは-i と"" の間に半角スペースが無い点に注意してください。一方でMac でこのコマンドを実行すると以下のようになります。まずは上記の1 つ目のコマンドを実行してみましょう。
//cmd{
$ ls -1
file.txt
$ cat file.txt
Foo
Bar
$ sed -i"" -e "s/^Foo/Bar/g" file.txt
$ cat file.txt
Bar
Bar
$ ls -1
file.txt
file.txt-e
//}
あれれ…。ファイルの中身は想定通り変わっていますが想定していないバックアップファイルが作成されています。次に2 つ目のコマンドを実行してみましょう。
//cmd{
$ ls -1
file.txt
$ sed -i -e "s/^Foo/Bar/g" file.txt
$ cat file.txt
Bar
Bar
$ ls -1
file.txt
file.txt-e
//}
こちらも先程と同じような結果になりました。このように同じ-i オプションでもここまで挙動が違うのです。困った時はドキュメントを見てみましょう。ということでここでまずはLinux のsed コマンドのドキュメントを見てみると次のように書かれています。
//emlist{
......
-i[SUFFIX], --in-place[=SUFFIX]

       edit files in place (makes backup if SUFFIX supplied)
......
//}
一方でMac のsed コマンドのドキュメントを見てみると次のようになっています。
//emlist{
......
-i extension
        Edit files in-place, saving backups with the specified extension.  If a zero-length extension is given, no backup will be saved.  It is not recommended to give a zero-
        length extension when in-place editing files, as you risk corruption or partial content in situations where disk space is exhausted, etc.
......
//}
微妙にバックアップファイルの拡張子を指定する位置が違います。Linux のsed では-i オプションのすぐ後に空白なしでファイルの拡張子を指定するようになっているのに対し、Mac のsed では空白を1 つ開けて拡張子を指定するようになっています。色々コマンドを実行してエラーメッセージを出しましたが、ドキュメント的には挙動は正しそうです。

このように同じコマンドでもOS 環境によってオプションの指定方法が違ったりすることで思わぬエラーを出すことがあります。Mac にもGNU コマンドを入れるようにすることはできますが、Mac を使うメンバ全員の端末に対してそれを実施するのはあまり現実的ではありません。またMac とLinux でコマンドのオプションを分けるように条件分岐を入れたとしても、実はとあるメンバのMac 環境だけGNU コマンドがインストール済みでそれを使うように設定されたいたりすると、逆に条件分岐を入れることでエラーとなる可能性があります。簡単には解決できなさそうです。このように各メンバの手元で実行するbash スクリプトによって環境構築を解決していくには限界を感じ始めていました。

== Docker Automated Build の利用
各メンバのローカル環境で実行するbash スクリプトに限界を感じ始めていた頃、簡単にビルド済みのイメージを公開してメンバ間で共有する仕組みは無いかと考えていた所、Docker Automated Build を思い出しました。このDocker Automated Build の構築について考えていくことにします。また今回Docker Automated Builds を使用するに当たりLaravel の利用は一旦やめることにしました。理由としてはDocker イメージの構成をよりシンプルにして我々側でイメージの管理をやりやすくするためです。

=== Docker Automated Builds とは
Docker Inc が提供するDocker Hubにて、Github やGitbucket 上のリポジトリと同期してリポジトリ内のDockerfile を基に自動ビルドを行なって自動的にイメージを作成して共有してくれるサービスです。これを利用することで開発メンバのPC 上でビルドするスクリプトを廃止することができて、環境差異による問題を解決するのに一役買うと考えていました。
//image[chap05/0021_ImageOfDockerAutomatedBuilds][Docker Automated Builds の流れ][scale=0.80]

=== Dockerfile の作成
Docker イメージをビルドするためのDockerfile を作成します。Dockerfile はイメージをビルドするための処理や設定を記述するためのファイルです。Dockerfile を我々で管理することでベースとなるDocker イメージはUbuntu かCentOS かそれとも他者が作成したnginx やPHP か、インストールするパッケージは何かといったことを考える必要があります。今回用意するDockerfile はLaravel 実行環境の本体となるphp-fpm、それに対するリバースプロキシサーバとなるnginx にすることにしました。またDB としてMySQL を利用しますが、こちらについては我々がDockerfile を作らなくとも公式のMySQL イメージで事足りると判断したためDockerfile は作成しませんでした。

//image[chap05/0022_GrouscopeImagesOfDockerAutomatedBuilds][grouscope でのDocker イメージ構成][scale=0.80]

==== nginx イメージ
それではまずはnginx のDockerfile を作成していきます。nginx は後側のLaravel のコンテナに対してリクエストをリバースプロキシするだけなのでそれほど複雑なDockerfile にはなりません。

//emlist[/docker/nginx/Dockerfile]{
FROM nginx:1.17
# ...(略)...

RUN apt-get update && \
        apt-get -y upgrade
COPY default.conf /etc/nginx/conf.d/default.conf
//}

パッケージをアップグレードして事前に用意したnginx の設定ファイルdefault.conf を置き換えるだけです。default.conf はLaravel コンテナに対してリバースプロキシをする設定を入れています。

//emlist[default.conf(紙面の都合上インデントを変更)]{
server {
  listen 80;
  server_name  default_server;
  root   /var/www/html/a6s-cloud/public;    # (1)
  index index.php index.html;

  client_max_body_size 10m;

  location / {
    add_header X-Request-Id $request_id always;
    try_files $uri $uri/ /index.php?$query_string;

    location ~ ^/index.php {
      internal;
      include fastcgi_params;
      fastcgi_split_path_info ^(.+\.php)(/.+)$;
      fastcgi_pass laravel:9000;
      fastcgi_param HTTP_X_Request_Id $request_id;        # (2)
      fastcgi_index index.php;
      fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name; # (3)
      fastcgi_read_timeout 300s;
    }
    # ...(略)...
  }
}
//}

上記nginx 設定ファイルの作成ポイントは以下の通りとなります。まずはroot ディレクティブの値を変更してドキュメントルートを以下のように変更しています。

//emlist[(1)root ディレクティブ(ドキュメントルートの変更)]{
root   /var/www/html/a6s-cloud/public;
//}
注意点としては、このnginx のコンテナ本体にはコンテンツは置かないということです。ドキュメントルートを設定するのは後ほど出てくる
//emlist[(3)fastcgi パラメータSCRIPT_FILENAME の組み立て]{
fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
//}
の部分でLaravel コンテナに対して、SCRIPT_FILENAME パラメータとして渡す値を組み立てるためにあります。逆にnginx のドキュメントルートにコンテンツは置かないようにしてください。try_files ディレクティブがindex.php パスを付与しなくなり想定しない動作となってしまいます。最終的にphp-fpm コンテナに対してFast CGI パラメータSCRIPT_FILENAME が渡されるようになり、想定される値は先程設定したroot ディレクティブの値と組み合わされ"/var/www/html/a6s-cloud/public/index.php" となります。この後作成するphp-fpm コンテナではそのディレクトリ(/var/www/html/a6s-cloud/public)にLaravel のコンテンツ及びindex.php を置くように作成する必要があります。あと最後にリバースプロキシ先としてLaravel コンテナ(php-fpm のエイリアス: laravel)を指定することを忘れないようにしてください。
//emlist[(2)リバースプロキシパスの設定]{
fastcgi_pass laravel:9000;
//}

==== Laravel イメージ
次にLaravel イメージを作成していきましょう。Laravel イメージのDockerfile は以下のようになります。

//emlist[Laravel のDockerfile 一部抜粋(紙面の都合上一部改変)]{
FROM php:7.3-fpm-stretch

RUN apt-get update && \
  DEBIAN_FRONTEND=noninteractive apt-get upgrade -y && \
  DEBIAN_FRONTEND=noninteractive apt-get install -y ... && \
  DEBIAN_FRONTEND=noninteractive apt-get install -y python3 ... && \
  docker-php-ext-configure gd --with-freetype-dir=/usr/include/ ... && \
  # ...(略)...

COPY grouscope_entrypoint.sh /opt/grouscope_entrypoint.sh
COPY wait_until_mysql_started.sh /opt/wait_until_mysql_started.sh

# ...(略)...

CMD ["/opt/grouscope_entrypoint.sh"]
//}

Laravel イメージはphp-fpm イメージをベースに作成します。ベースイメージのタグを"php:7.3-fpm" ではなく"php:7.3-fpm-stretch" としているのは2019年07月にあげられたPHP のgd モジュールのissue のためです(https://github.com/docker-library/php/issues/865)。Dockerfile の記載内容としては、ベースイメージはphp-fpm イメージにしてあります。そして環境をカスタマイズしていきますがPHP の環境はだいたい揃っているので、好みのPHP エクステンションの追加及びgrouscope が依存するPython 製バッチを実行するためにPython をインストールしています。そしてコンテナが起動した時に実行されるentrypoint スクリプトも準備し、そのなかでcomposer install を実行してアプリケーションが依存するパッケージ類をインストールしています。PHP 以外の依存としてgit submodule とPython のパッケージがありますが、それはcomposer.json のpost-install-cmd で、composer install が実行された後に続けてインストールされるようにコマンドを指定しています。

//emlist[composer.json の一部抜粋(紙面の都合上一部改変)]{
  # ...(略)...
  "scripts": {
    # ...(略)...
    "post-install-cmd": [
      "@php artisan migrate",
      "@php artisan db:seed",
      "pip3 install -r requirements.txt",  # Python の依存
      "git submodule update --init --recursive"  # git submodule の依存
    ],
    # ...(略)...
  }
//}

あとwait_until_mysql_started.sh というスクリプトファイルがイメージにコピーされていますがLaravel、MySQL コンテナと同時に起動した時にMySQL が接続する準備ができていないのにDB のマイグレーションをしようとしてエラーが出るのを防ぐために作成しました。このスクリプトを使ってDB が接続できるのを確認してからDB のマイグレーションを実行してアプリケーションが始動するようになっています。

==== MySQL イメージ
次にMySQL ですが、こちらはオフィシャルのMySQL のイメージをそのまま使うことにしました。MySQL のオフィシャルイメージではコンテナを起動した時にコンテナの"/docker-entrypoint-initdb.d" ディレクトリ下に".sh"または".sql"、".sql.gz" という拡張子のファイルがあった場合、それを実行するようになっています。なのでDB の初期化やユーザを作成するSQL 及びその他実行したいコマンドがあればそのディレクトリに入れておけば良いのです。今回は以下のようなSQL ファイルを1 つだけ用意してMySQL コンテナ起動時にDB の初期化とユーザを作成するSQL を格納しておきました。
//emlist[]{
CREATE DATABASE IF NOT EXISTS a6s_cloud;
-- ALTER USER 'default'@'%' IDENTIFIED WITH mysql_native_password BY 'secret';
CREATE USER 'default'@'%' IDENTIFIED WITH mysql_native_password BY 'secret';
GRANT ALL ON a6s_cloud.* TO 'default'@'%';
//}
テーブルを作成する処理が無いですが、それはphp-fpm(Laravel) コンテナから実行されるマイグレーションコマンド"php artisan" で作成される予定なのでここで作成する必要はありません。むしろテーブル構成や管理のことを考えるとLaravel のマイグレーションに任せたほうが良いでしょう。ここではphp-fpm コンテナがMySQL に接続してDB を操作できるようになるまでに必要な最低限の処理だけにしておきます。

=== Dockerfile のテストビルド
一通りDockerfile の作成が完了したら、一旦手元でビルドしてみましょう。ビルドするには各Dockerfile があるディレクトリに移動して"docker build" コマンドを叩きます。

//cmd{
$ # grouscope-backend のリポジトリroot にいることを想定
$ cd docker/nginx
$ docker build -t a6scloud/grouscope-nginx .
$ cd ../laravel
$ docker build -t a6scloud/grouscope-laravel .
//}

Nginx コンテナと php-fpm コンテナのイメージのビルドに成功しましたでしょうか？これでイメージの準備はほぼ完了です。次はDocker Hub での作業を実施していきます。

=== Docker Hub Organization を作成する
Docker Hub にイメージを公開する場合は自分個人のアカウントのリポジトリでも構いませんが今回我々はa6scloud というチームを作っており、せっかくなのでa6scloud という名前のorganization を作ることにしました。この名前は後ほどDocker イメージをpull する時に指定される名前となります。今回は既にDocker Hub にアカウントを持っている前提で話を進めていき、また厳密な手順については別の機会に説明するとして今回は概要のみを説明します。

それではDocker Hub にログインしましょう。画面右上のメニューにOrganizations メニューをクリックします。するとOrganizations ページに遷移して"Create Organization +" ボタンが表示されます。
//image[chap05/0031_CreateDockerOrganizations][Organization 作成ページ][scale=1.0]

それをクリックすると以下のような項目の入力を要求されます。

 * Organization Namespace
 * Organization Full Name
 * Company
 * (Optional) Location
 * (Optional) Gravatar Email
 * (Optional) Gravatar URL

Organization Namespace がイメージをpull する時に指定される名前の一部になるので注意するようにしてください(今回はa6scloud という名前にしました)。その他の項目についても、チームのメンバに相談するなどして決めていってください。Organization を作成したらOrganization ページから先程作成したOrganization 名をクリックしましょう。するとデフォルトでowners というチームができていると思います。必要に応じてowner 権限レベルのチームメンバを追加するようにしてください。
//image[chap05/0032_AddOwnersToOrganizations][Organization ページ][scale=1.0]

Organization を作成したら次はリポジトリを作成しましょう。真ん中の右側にあるRepositories をクリックするとリポジトリ一覧ページに遷移します。
//image[chap05/0033_CreateRepositoriesInOrganization][リポジトリ作成画面][scale=1.0]

ここで"Create Repository" をクリックしてリポジトリを作成します。すると"a6scloud" というプレフィクスに続くリポジトリ名を要求されます。今回作成するのはNginx とLaravel(php-fpm) のイメージで、"grouscope-nginx"、"grouscope-laravel" とすることにしました。計2 つのリポジトリを作成します。リポジトリを作成したら次はAutomated Builds の設定を行ないます。リポジトリを作成したらリポジトリの画面へ移動して上部メニューの"Builds" を選択して"Configure Automated Builds" ボタンをクリックします。
//image[chap05/0034_CreateRepositories][リポジトリ作成画面][scale=1.0]

するとBuild に関する設定画面に遷移します。我々が入力する項目としては"SOURCE REPOSITORY"、"AUTOTEST"、"REPOSITORY LINKS"、"BUILD RULES" になります。その中でもBUILD RULES はDockerfile からイメージをビルドするための重要な情報になるので間違え無いように入力してください。内容を間違えてしまうと、たとえローカルのビルドに成功していたとしてもDocker Hub 上でのビルドに失敗する原因になりかねません。今回a6scloud にて作成した"grouscope-nginx" リポジトリについては図のようになります。今回はa6scloud/grouscope-backend GitHub リポジトリのmaster ブランチとtesting ブランチにてpush を検知すると/docker/nginx/Dockerfile ファイルを使ってgrouscope-nginx イメージのビルドが走るように設定をしました。これと同様に"grouscope-laravel" イメージのビルド設定も行うようにしてください(図6.18)。

//image[chap05/0035_ConfigureAutomatedBuilds][Nginx イメージのAutomatedBuilds の設定画面][scale=1.0]

これでDocker Automated Builds の準備は完了です。GitHub にてmaster もしくはtesting ブランチにリソースがpush されるとDocker Hub にて自動ビルドが走りイメージが更新されるようになります。master もしくはtesting GitHub ブランチにリソースをpush 後、Automated Builds が完了すると以下のようにイメージをpull できるようになります。

//cmd{
$ # testing タグのa6scloud/grouscope-nginx イメージをpull する例
$ docker pull a6scloud/grouscope-nginx:testing
$ # latest タグ(GitHub master ブランチ)のa6scloud/grouscope-nginx イメージをpull する例
$ docker pull a6scloud/grouscope-nginx:latest
//}

=== docker-compose ファイルを作成する
Docker Automated Builds でイメージも準備できましたので開発環境のDocker コンテナを起動する準備ができました。しかし今回の開発環境は複数のコンテナからなりNginx、Laravel、MySQL のコンテナの起動をもって1 つの開発環境の完成とみなされます。ということはそれらコンテナの依存関係を解決する必要があり、それら管理するために今回はdocker-compose を使用することにしました。

docker-compose は複数のコンテナから成るサービスを構築・実行する手順を自動的にし、管理を容易にする機能です。docker-compose を利用するにはdocker-compose コマンドを実行するディレクトリにdocker-compose.yaml ファイルを作成し、その中に利用するイメージとコンテナの情報を定義していきます。今回はgrouscope-backend のroot リポジトリに以下のようなdocker-compose.yaml ファイルを作成しました。

//emlist[docker-compose.yaml の一部抜粋]{
# ......

services:
  nginx:
    container_name: grouscope_nginx
    image:
      a6scloud/grouscope-nginx:${NGINX_IMAGE_TAG}
    ports:
      - "${NGINX_BIND_PORT}:80"
    networks:
      - a6s
    depends_on:
      - laravel

  laravel:
    container_name: grouscope_laravel
    image:
      a6scloud/grouscope-laravel:${LARAVEL_IMAGE_TAG}
    environment:
      - DB_HOST=grouscope_mysql
      - DB_DATABASE=a6s_cloud
      - DB_USERNAME=default
      # ......
      - ACCESS_TOKEN_SECRET=${ACCESS_TOKEN_SECRET}
    volumes:
      - ./:/var/www/html
    networks:
      - a6s
    depends_on:
      - mysql

  mysql:
    container_name: grouscope_mysql
    networks:
      a6s:
        - mysql
    image:
      mysql:${MYSQL_IMAGE_TAG}
    ports:
      - ${MYSQL_BIND_PORT}:3306
    environment:
      - MYSQL_ROOT_PASSWORD=secret
    volumes:
      - ./docker/mysql/docker-entrypoint-initdb.d:/docker-entrypoint-initdb.d
    networks:
      - a6s
//}

上記のように合計3 つのコンテナを起動するように定義し、それぞれdepends_on キーワードを用いてgrouscope_laravel コンテナはgrouscope_mysql コンテナに依存し、grouscope_nginx はgrouscope_laravel コンテナに依存する関係性も定義しています。このようにすることによって、それぞれのコンテナが起動するタイミングを調整することができます。またボリュームのマウントとしてgrouscope_laravel コンテナはこのdocker-compose.yaml ファイルがあるディレクトリと同じディレクトリをコンテナ上の/var/www/html 上にマウントするようになっており、最終的にアプリケーションの起点となるindex.php が/var/www/html/a6s-cloud/public/index.php としてgrouscope_laravel コンテナから見れるようになります。そして環境変数としてgrouscope_laravel コンテナではMySQL へ接続するユーザ名やDB 名、Twitter からツイート情報を取得してくるためのAPI キーを.env ファイルから読み込んでコンテナの環境変数として反映するようになっています。その他にもホスト側とバインドするポート番号やpull してくるイメージのタグ名も.env ファイルから取得して値を指定するようになっています。docker-compose ではデフォルトでdocker-compose.yaml ファイルと同じディレクトリにある.env ファイルを読み込んでdocker-compose.yaml 内の変数を定義することができるようになっていて、今回我々のプロジェクトの.env ファイルは以下のように作成しました。

//emlist[.env]{
NGINX_BIND_PORT=80
NGINX_IMAGE_TAG=latest

LARAVEL_IMAGE_TAG=latest
CONSUMER_KEY=xxxxx
CONSUMER_SECRET=xxxxx
ACCESS_TOKEN=xxxxx
ACCESS_TOKEN_SECRET=xxxxx

MYSQL_IMAGE_TAG=8
MYSQL_BIND_PORT=3306
//}

上記のように設定することでdocker-compose.yaml を直接編集するのではなく.env ファイルの方を編集することでコンテナの環境変数やバインドするポート番号等の値を設定することができるようになっています。

=== コンテナの起動
docker-compose の環境ができたところでdocker-compose でコンテナを起動してみましょう。イメージは既にmaster ブランチにリソースがpush されていてAutomated Builds により作成されているものとします。

//cmd{
$ docker-compose up
......
grouscope_laravel | > git submodule update --init --recursive
grouscope_laravel | [DD-MMM-YYYY hh:mm:ss] NOTICE: fpm is running, pid 1
grouscope_laravel | [DD-MMM-YYYY hh:mm:ss] NOTICE: ready to handle connections
//}

grouscope_nginx、grouscope_laravel、grouscope_mysql コンテナが起動してPHP の依存モジュールをインストールしてDB テーブルのマイグレーションをしてgrouscope_laravel コンテナが最後に起動したログが出力されています。これでgrouscope_backend の起動は完了です。

開発環境が完成しました。今までメンバのローカルでbash スクリプトを走らせていた時とは違い、こちらはイメージのビルドが完全にDocker Hub 上で行われるのでメンバのPC の環境に左右されません。またdocker-compose を利用することで1 コマンドで複数コンテナの起動と停止、環境変数等の設定を管理することができるため、開発メンバ向けの追加のドキュメントを作る必要もなくメンテにかかるコストも減らすことができました。

=== Laradock を使ったほうが良いか独自に作ったほうが良いか
今回はdocker-compose を利用することで、結果的にLaradock から離脱するような形になってしまった一方でAutomated Builds を使用してメンバのビルド環境に依存しない開発環境を用意することができました。果たしてLaradock から離れることは判断として正しかったのか？それは判断が難しいところです。しかし今回のケースではシンプルなLEMP 環境があれば充分であったためLaradock はオーバーキルな状態にありました。またLaradock は公式のドキュメントどおりに使うにはとても良いのですが、その中に独自のPython 環境を入れようとしたりすると結局は自分の手でカスタマイズすることが多くなっていき、Laradock を使う恩恵をあまり感じることができませんでした。また今までは各メンバのPC でビルドを走らせることによりビルドを実行した日時によって内部の細かいパッケージ等のバージョンが微妙に異なるようになったりすることで、各メンバに対して同一なイメージを配布することはできていませんでした。それらを考慮すると、自分でDockerfile を作成してDocker Automated Builds でイメージを作成することでメンバのビルド日時や環境に依存すること無く、より同一な開発環境イメージを配布することができるようになりました。

今でも正解がどちらかはわかりませんが、確実に言えることはシンプルなLEMP 環境であれば自作のDocker イメージでも充分に開発に耐えられるし、それであればDocker Automated Builds を使ってイメージをDocker Hub 上でビルドしてしまうほうがメンバに対してより同一な開発環境を提供できます。一方で今後アプリケーションに高度な仕様が出てきた時に、例えばRedis と組み合わせたりメール送信サーバと組み合わせたりといったものが出てきた場合、またLaradock に戻ってくるといった選択は充分にありえるでしょう。

=={sec-ext1} デプロイ
AWS、Heroku、GCP、そして自宅サーバ

=={sec-ext1} CI
CircleCI、TravisCI

