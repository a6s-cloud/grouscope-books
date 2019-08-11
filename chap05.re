= 環境構築
== Linux 愛好家、Webアプリ畑に立つ
Web アプリ画面を飾りエンドユーザーに魅力的なビジュアルや体験を与えるフロントエンジニア。今話題となっているAngular、React、VueJS を使ったレスポンシブでインタラクティブな画面はユーザのみならず「自分もこんなものを作ってみたい」と開発者の道に入る人も少なくないでしょう。現代のIT 技術者として花形の一種です。一方で真っ暗な画面に白い文字が真夏のスコールのごとく流れてくる中で、それに負けじとキーボードをパタパタ叩いては、また降ってくる文字を見てまたキーボードを叩いていく…。一見すると地味で何が面白いのか理解できなかったりする、でもそんな傍からの視線を気にすることもなく、我が愛するコンピュータとコマンドと通じて直に会話することに虜になっている人もいます。そう、今回環境構築周りをメインに執筆させていただく私、つとむもその虜になってしまった人間のうちのひとりです。

そんな私ですがgrouscope の開発に入ることになりました。どのようにして入ったのか等の経緯はなおとさんの記事に譲るため割愛させていただきます。普段Linux ばかり触っていてLinux の流行を少しは知っているがWeb アプリのことは殆ど知らない属性の人間が、どのようにWeb アプリ開発チームに入って貢献できるだろうかと最初は難しさを感じていました。そんな中で私はバックエンド側の環境構築をメインにやることになり、プロジェクトで採用した技術要素や立ちはだかった壁とその乗り越え方について色々学んでいくものがありました。今回の環境構築の記事はバックエンドがメインとなってしまいますが、私なりに普段フロントエンドで開発をしている方々にも、バックエンドで開発している方々両方にわかりやすく楽しく書いていきたいと思いますので、どうかお付き合いいただければと思います。

== アプリケーションの概要
今回開発するgrouscope はtwitterハッシュタグ分析プラットフォームです。Web 画面に任意のハッシュタグを入力することで、そのハッシュタグがつけられているtweetの傾向を分析し、画像・グラフ・ランキングといった形式に可視化し、hot なハッシュタグを探すことを可能にするものです(GitHub のREADME より一部抜粋し加筆)。今回はフロントエンドとバックエンドでGit リポジトリを分けて開発していくことになりました。そして作成したGitHub のリポジトリは以下のようになりました。

 * grouscope-front
https://github.com/a6s-cloud/grouscope-front

 * grouscope-backend
https://github.com/a6s-cloud/grouscope-backend

 * grouscope-batch
https://github.com/a6s-cloud/grouscope-batch

=== フロントエンドの技術要素概要
フロントエンドの技術要素として、ユーザインタフェースを構築するためのJavaScript フレームワークとしてVue.js を採用することになりました。Vue.js は現在日本でも活発に採用されるようになってきてGitHub Start 数も全GitHub リポジトリの中でも有数のものとなってきていて人気とコミュニティの活発さから採用しました。またUI のデザインや色、モーション等をつけるコンポーネントライブラリとしてElement を使用することになりました。こちらはすでになおとさんが実務で利用した経験があるのと使いやすいと評判がありました。またElement もコミュニティが活発で開発が盛んなので採用に至りました。現在は上記のような構成となっていますが、後からデザインの仕事をされているのなとさんが加わったため、現在デザイン及びユーザインタフェースについては大改修中です。その時にはまた利用する技術要素も変わってくるかもしれません。

=== バックエンドの技術要素概要
バックエンドの技術要素として、まずDocker があります。開発期間中は各開発者のPC にプログラムを実行するためのサーバを用意するために使っています。そしてアプリのバックエンドのWeb アプリケーションフレームワークとしてPHP のLaravel を採用しています。今回はLaravel はレンダリングされたWeb 画面をユーザで返す用に使われることもありますが、今回はAPI サーバとしてクライアント側にJSON を返すようにして利用しています。Laravel はAPI 用のフレームワークも用意されているので、API サーバのフレームワークとして使うのも苦ではありません。またDB にはMySQL、Web サーバにはnginx、画像を作成するバッチを実行するためにPython 環境も取り入れています。

//image[chap05/architecture][フロントエンドとバックエンドの技術要素構成図][scale=1.0]

== バックエンドの開発環境としてDocker の選定
御徒町のいいオフィスでgrouscope の開発会議がまだ初期の頃です。
バックエンドの環境を構築する話になりました。普段からLinux を触っている私の頭の中ではDocker を使う選択肢しかありませんでした。やっぱり流行りのDocker なのか…と言われるかもしれませんが、その時私の頭に浮かんでいたDocker を推す理由としては以下のものがありました。

 * 各開発者PC 上に同じ実行環境の提供が可能
 * 環境のリストアが簡単で早い
 * 知名度があり提案しやすい

「開発環境はDocker にしましょう！」提案したところ、やはりみんな普段から勉強しているエンジニアの方々。すんなりとDocker で進める方向に決まりました。しかしDocker を使うというだけではバックエンドのアプリケーションを動かすエンジンを決めただけで、何の言語でどいうったFW(フレームワーク)を動かすかといったことがまだ決まっていません。次はそれらを決めていく必要がありますが、ここで一旦Docker がなぜWeb アプリケーションの開発環境として良いのかといったことについてもう少し詳細に述べさせてください。

=== ポータビリティ
今となってはスタンダードとなっているDockerですが、やはり魅力的でした。その理由のひとつとしてはポータビリティ性とプログラム実行環境の統一化です。VM と比較したDocker (コンテナ)の利点として軽量さが言われることもありますが、今回のケースではそれよりも先にあげたポータビリティの確保とプログラム実行環境の統一化が魅力的でした。

ポータビリティ性を実現するために、各開発者環境に同じDocker イメージを落とすためのいくつかの方法があります。

 1. Docker Hub(registry) にイメージをpush し、メンバにpull してもらう
 2. Docker ファイルを配布してメンバの手元でビルドしてもらう
 3. docker save でコンテナをイメージとして固め、メンバに配布してdocker load してもらう

//image[chap05/0000_DeployDockerImage][Docker イメージ配布方法][scale=1.0]

個人的に推奨したいのは1 番目のDocker Hub 利用する方法です。Docker Hub はある作者が作成したDocker イメージをクラウドで共有して利用できるようにしたサービスです。Docker イメージ作成者はDocker イメージをビルドするための処理が書かれたDockerfile を使ったり、作業中のDocker コンテナをdocker commit してイメージ化したものをDocker Hub にアップロード(push)することで、イメージを公開して配布できるようになります。この本を読んでいる人の中には、Web アプリ開発の環境構築や、Docker を勉強し始めた時に以下のような確認コマンドを実行した経験がある人もいるのではないでしょうか？

//cmd{
$ docker run hello-world
//}

上記docker run コマンドはhello-world イメージからコンテナを起動するコマンドで、Docker が正常にインストールされて起動していれば「Hello from Docker!」とターミナルに表示されます。docker run コマンドは手元に対象のイメージが存在しない場合は手元にそれをpull してから起動するようになっています。そしてこのイメージもDocker Hub 上で管理されています。

//image[chap05/0001_DockerImageHelloWorld][引用 hello-world Docker イメージ(https://hub.docker.com/_/hello-world)][scale=1.0]

このようにインターネットに繋がっていれば、簡単にイメージを取得してきてコンテナを起動することができます。Docker Hub でイメージを管理すればイメージ登録後、イメージ名を伝えることでメンバ間で同じイメージを手元に落としてコンテナを起動することができるようになるのです。

一方でDocker イメージを公開したくない場合はDocker Registry で独自のリポジトリを建てたりDockerfile を配布する方法やdocker save とdocker load を使った方法を利用するのもありだと思います@<fn>{chenv_01}。
//footnote[chenv_01][2019年7月現在、Docker Hub の無料プランでも1つまでならプライベートリポジトリは作成可能です。有料アカウントであれば更にプライベートリポジトリ作成することもできます。詳細はhttps://hub.docker.com/pricing]

=== 環境のリストアが簡単で早い
2つ目の理由としてはDocker イメージの普遍性を利用した環境のリストアが簡単な点です。複数メンバらが利用する開発環境として、とても大きな利点があります。例えばそれぞれメンバが開発中のプログラムに対して誤った改修を入れてしまったり、チャレンジングな設定変更をしてデータや環境を破損してしまったとしましょう。自分のマシン上にサーバを直接インストールしていた場合は、サーバの再インストールであったりエラー箇所を追跡して正しく動くように戻す必要があるでしょう。また仮想マシンを単に使っていた場合は、バックアップとして取得しておいたイメージをもう一度コピーして手元に展開し、再起動することで復旧できるかもしれませんが、イメージは数GB 〜 数十GB になることもざらにあり、結構コストが高かったりします。一方Docker では@<b>|コンテナを削除することで状態をリストアすることができる|のです。

削除することで初期の状態に戻せる、と聞くと何もなくなってしまう用に感じるかもしれませんがこれはどういう意味なのでしょうか？それを知るにはDocker のイメージとコンテナの違いを理解する必要があります。一言で例えていうならばDocker イメージは読み取り専用でDocker コンテナは読み書き両方できるオブジェクトになります。コンテナを起動するとアプリケーションの実行ファイルのような更新が発生しない読み取り・アクセスのみで良いファイルやデータについてはイメージから読み取られ、アプリケーションによってファイルが作成されたりファイルが更新されたりするときは、コンテナ内にそれらを持ってきてコンテナ内の情報のみ変更するようになっているのです。結果としてコンテナ上でファイルの作成や更新が行われようとも、イメージの状態は全く変わっていないのです。そのためユーザーは状態を元に戻したいと思ったら、動いていたコンテナを削除し、もう一度イメージからコンテナを起動し直せばよく、バックアップから大量の情報をコピーしてくるといったコストのかかることはしなくて済むのです。

//image[chap05/0001_FigureOfImageAndContainer][Docker 環境のリストアイメージ][scale=1.0]

==== Docker のイメージとコンテナの性質を体験してみる
Docker イメージとコンテナの違いを実際にコマンドを打って確認してみることにします。以下のようにdocker run コマンドを実行してAlpine Linux を起動します。以下のコマンドはAlpine Linux イメージがない状態から実行していることを想定しています。

//cmd[docker run でAlpine Linux]{
$ docker run -ti alpine sh
Unable to find image 'alpine:latest' locally
latest: Pulling from library/alpine
050382585609: Pull complete 
Digest: sha256:6a92cd1fcdc8d8cdec60f33dda4db2cb1fcdcacf3410a8e05b3741f44a9b5998
Status: Downloaded newer image for alpine:latest
/ # 
//}

するとalpine Linux のイメージがpull され、コンテナが起動してシェルのプロンプトが表示されます。Linux に画面とキーボードを直接接続したりSSH でroot ユーザとしてログインしているのと同じような状態です。ここで適当にファイルを作成してみましょう。以下のコマンドはアプリケーションが/var/log ディレクトリ下にyourapp.log というファイルでログを出力した状態を想定しています。

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

//cmd{
$ # イメージの確認
$ docker images
REPOSITORY                 TAG                 IMAGE ID            CREATED             SIZE
alpine                     latest              b7b28af77ffe        3 weeks ago         5.58MB
$ # コンテナの確認
$ docker ps -a
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                     PORTS               NAMES
c29ef7560eaa        alpine              "sh"                2 hours ago         Exited (0) 2 seconds ago                       vibrant_lumiere
//}

すると先程pull したイメージと起動したコンテナが表示されます。コンテナ名として"vibrant_lumiere" という名前がつけられていますが、これはコンテナを作成するたびにランダムにつけられる名前となります。このコンテナは"STATUS" の項目を見るとわかるとおり、約2 秒前に停止しているコンテナになります。コンテナはそのコンテナ内で起動しているメインプロセスが停止すると、コンテナ自体も終了する仕組みになっています。そのため先程の例ではdocker run でsh のメインプロセスが起動してログアウトすることでメインプロセスが終了して、コンテナも終了するようになっています。それでは次に、docker start コマンドでこのコンテナをもう一度起動してみましょう。

//cmd{
$ docker start vibrant_lumiere
vibrant_lumiere
$ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
c29ef7560eaa        alpine              "sh"                8 hours ago         Up 3 seconds                            vibrant_lumiere
//}

docker start を実行すると先程のコンテナでsh プロセスが起動しますので、このsh プロセスにアタッチして先程作成したファイルが残っていることを確認しましょう。

//cmd{
$ docker attach vibrant_lumiere
/ # cat /var/log/yourapp.log
An application said. 'Hellow world'
//}

ファイルがありました。先程作成したファイルはコンテナ内に残り続けていることがわかります。ここもう一度ログアウトしてコンテナを停止し、次はコンテナを削除してみましょう。

//cmd{
/ # exit
$ docker rm vibrant_lumiere
vibrant_lumiere
$ docker ps -a
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
//}

コンテナが削除されました。このコンテナの削除をもって状態のリストアは完了です。それではもう一度コンテナをdocker run コマンドから起動してみましょう。

//cmd{
$ docker run -ti alpine sh
/ # 
//}

Alpine Linux のコンテナが起動してsh のセッションに入りました。先程と違う点としては"Pulling from library/alpine" という文言が消えてイメージのpull が行われていない点です。これは一番最初にdocker run コマンドを実行した時にイメージは手元に落とせているため、そのイメージからAlpine Linux を起動したことになります。イメージをダウンロードする必要が無いので先程よりもすばやくコンテナを起動することができます。ここで先程のファイルの存在を確認してみましょう。

//cmd{
$ docker run -ti alpine sh
/ # cat /var/log/yourapp.log
cat: can't open '/var/log/yourapp.log': No such file or directory
//}

ファイルが無いためエラーとなりました。これは初期のAlpine Linux の状態に戻っているためです。このようにDocker ではコンテナを削除することで状態を元に戻すことができるため低コストで素早く、そしてバックアップを管理する必要もなく状態を元に戻せるようになっています。

== Laravel という選択
閑話休題、Docker を使うことが決まったので次はバックエンドのWeb アプリケーションフレームワークを決める話題になりました。その時トキさんが「Laravel 使いたい！」と提案してくれました。普段PHP を使ったことがない私でも聞いたことはあり、当時会議に参加していたメンバも異論無しですんなりと決まりました。

Laravel はPHP で動くフルスタックなフレームワークでルーティングやコントローラ、ビュー、ORM も含んでいて且つAWS のS3 をストレージとして使うことを前提としたオプションも含まれていたりと至れり尽くせりなフレームワークです。今回はそのLaravel をフロントエンドのVue.js で組まれたプログラムにJSON で結果を返すREST 構成にすることに決まりました。もちろんLaravel にはAPI サーバの機能もあるためそのあたりの実装についても簡単に実装できるようになっています。

== Laradock との出会い
フレームワークとしてLaravel を使うことが決定したので、次はその環境をどのようにしてDocker で準備するかという流れになりました。自力でDockerfile を作成するのも良いですが、私には本業があってその隙間時間に進めていくプロジェクトであったことを考慮して、できるだけそれは回避しようと思っていました。有名なLaravel というフレームワークというのもあり、既に完成度の高いLaravel のDocker イメージを作成して配布している人がいるはずだと考えていました。それをメンバに伝えた所、Docker イメージを探す作業に入っていきました。するとトキさんがまたやらかしてくれました。「Laradock ありますよ！」。

Laradock を使えばLaravel 環境が手軽に自分の手元に準備でき、やはりコミュニティが活発でDockerfile やドキュメントもメンテナンスしっかりできているので、今後使い続けるのにも良い選択でした。LEMP @<fn>{chenv_02}構成に加えてRedis、Mongo DB、メールサーバ等のイメージも必要に応じて準備できるようになっており、今後のことも考えると当時選ばない理由はありませんでした。
//footnote[chenv_02][Linux、Nginx、MySQL、PHP な構成のこと。LAMP のApache がNginx に変わった]

=== Laradock を即席で立ち上げてみる
Laradock を使うと簡単にLaravel 環境を準備できます。とりあえずLaravel のトップ画面を表示するだけであれば以下のようにコマンドを実行することで用意できます@<fn>{chenv_03}。
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

コマンドを実行したら、Web ブラウザを開いてhttp://localhost にアクセスするとLaravel のwelcome page が表示されます。
//image[chap05/0003_LaravelWelcomePage][Laravel のwelcome page][scale=1.0]
#@+++
TODO: welcome page が表示されます... の直後に@<img>{chap05/0003_LaravelWelcomePage} として参照画像の番号を入れたいがずれる。保留
#@---

もし既にLaravel アプリケーションが用意できていてそれがGit で管理できているなら、次のようにコマンドを実行することでLaradock でアプリケーションを走らせることができます。今回はLaravel のアプリケーションとしてniwasawa 氏のphp-laravel-hello-world を使ってコマンドを実践していきたいと思います(感謝致します<(_ _)>)。

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

以上で準備は完了です。Web ブラウザを起動してhttp://localhost/hello/ を開いてみましょう。

//image[chap05/0004_LaravelHelloWorld][Laravel のHello World(https://github.com/niwasawa/php-laravel-hello-world.git)][scale=1.0]

上の画像のように画面が表示されれば成功です。laradock を使うことで既存のlaravel アプリケーションも簡単にlaradock へ移行できるようになっています。決して上から目線ではないですが、私のようにLinux 経験が長い人からすると自分で環境構築するほうが後々カスタマイズ性もあって便利では無いかと考えることもあるかもしれませんが、寄せ集めのメンバであったりスタートアップで限られた資源で開発をしている場合は有識なサーバサイドエンジニアが身近にいなかったりするかもしれません。そういった場合にまずはlaradock を使って開発環境を用意してみる、という選択は理にかなっていると思います。またドキュメントをじっくり読んでみるとわかるのですが、laradock の仕様や文化を理解するコストはありますが、アプリケーションのあらゆるニーズに答えられるようになっているのでサーバサイドの経験が長い人にとっても時間短縮のために利用したり、Laravel の複雑な組み合わせ(例えばMongoDB との接続やRedis との接続など)をテストするシーンにも利用することができます。

=== Laradock の構成図
Laradock が起動したところで、一旦ここでdocker ps コマンドでコンテナを見てみましょう。すると多くのコンテナからLaradock が構成されている事に気付く事でしょう。

//cmd[紙面の幅の都合上、一部記載を省略]{
$ docker ps
CONTAINER ID  IMAGE               COMMAND  CREATED             STATUS  PORTS  NAMES
8b407ee12c7a  l_nginx      ....   5 minutes ago  Up n seconds  ...     laradock_nginx_1
f5dc49dae496  l_php-fpm    ....   5 minutes ago  Up n seconds  ...     laradock_php-fpm_1
a9cdaae0a76a  l_workspace  ....   5 minutes ago  Up n seconds  ...     laradock_workspace_1
44641c8fee0b  l_mysql      ...    5 minutes ago  Up n seconds  ...     laradock_mysql_1
//}

これらのコンテナがどのように関わり合っているかということを図で示すと次のようになります。

//image[chap05/0005_LaravelStructure][Laravel のネットワークを含めた構成図][scale=1.0]

取り敢えずLaravel のアプリケーションを走らせるだけの環境であれば、これらの構成を深く気にする必要はありませんが、プロジェクト固有のカスタマイズが必要になってきたり、手動で環境設定を変更したい場合にも対応できるように概要は理解しておいて損はないでしょう。現に我々のプロジェクトではLaravel から外部コマンドとしてPython のスクリプトを動かすためにLaradock 環境のカスタマイズは必要でした。

まずネットワークを見てみると本番環境と遜色ない、DMZ とその裏側にあたるイントラネットワークエリアがDocker network で構成されています。nginx はWeb サーバとしてDMZ に置かれ、裏側イントラネットワークに位置するLaravel (php-fpm)のコンテナに対してリバースプロキシをするようになっています。先程Laradock をビルドしてLaravel のトップページを表示しましたが、その時のWeb ブラウザのリクエストはnginx に到達し、リバースプロキシされてLaravel のコンテナからページが取得されていました。

またworkspace という、Laravel アプリケーションとは一見関係なさそうなコンテナが存在します。これはnginx やphp-fpm と言った主要なコンテナの橋渡しをするコンテナで、このコンテナに乗り込むことで別コンテナとして起動するnginx とLaravelのファイルリソース類に対して透過的にアクセスできるようになっています(TODO: 要確認)。またこのコンテナにはcomposer をはじめとしたツールセットが盛り込まれており、conposer による新規Laravel プロジェクトの作成やartisan コマンドによるLaravel ユーティリティの利用、xDebug (ビルド時のオプションで指定が必要)を使ったデバッグ実行といった開発者のための作業環境となっています。このようにLaradock では数回のコマンドで本番環境さながらなネットワーク環境をするだけでなく、開発に集中できるよう環境が整った作業スペースまでをも提供してくれる、まさに至れり尽くせりな状態なのです。

== 依存性管理
package.json、composer.json、pom.xml。Nodejsやphp、Java などのプロジェクト開発でこういった名前のファイルをみた事がある人も多いと思います。これらのファイルはプロジェクトの名前や設定情報、ビルドやテストするための命令を管理する一方で、プロジェクトが必要としている依存モジュールについても管理しています。grouscope-backend も同様で以下の複数のgit で管理されているプログラムに依存しています。

 * Laradock: Laravel の実行及び検証環境
 * grouscope-backend: word cloud API を呼び出すPython 製batch スクリプト
 * RictyDiminished: word cloud 画像に埋め込む文字フォント

昨今はマイクロサービスという言葉が出てきて、個々に作成されたサービスやアプリケーションを部品として組み込んでサービスやアプリケーションとして成り立っていくという開発の仕方が出てきています。grouscope のバックエンドアプリケーションもそれ単体では動かすことができず、ツイート内容を可視化するgrouscope-batch プロジェクト(内部でamueller氏の word_cloud を使用)と画像に文字を入れるためのフォントファイルRictyDiminished (edihbrandon 氏のリポジトリのものを使用)を必要としていました。そしてLaradock を使うことも決定したので、Laradock も必要なものとして加わりました。このように必要な要素が多くなってきており、これらをどのように管理していくかが課題になってきました。

=== 簡単なスクリプトで管理する方法
grouscope-backend リポジトリ作成したての頃はそれらの依存関係を管理する仕組みがありませんでした。原始的で手っ取り早く依存性を管理するなら、普段Linux でbash を触っている私からしたら以下のようなファイルとスクリプトを作成する事でしょうか。

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

このようにすれば依存関係にあるGit リポジトリをclone してくれます。しかしこれではまだまだ問題があります。

=== 依存モジュールの依存モジュールを取り入れる事ができない

もし依存モジュールに、更に依存モジュールがあった場合、上記のスクリプトはそれらをダウンロードしてきません。しかもそれぞれのプログラム作者が今回の例のように完全独自ルールな依存性管理スクリプトを自作していた場合、そのプログラムを依存モジュールとして使う他の開発者にそのスクリプトの仕様を理解させるという重労働を課してしまうことになります

//image[chap05/0011_FigureOfDependentModules][依存関係の依存までダウンロードできない][scale=0.9]

=== 取得してくる依存モジュールのバージョンが安定していない
多くの人から利用されている人気モジュールは世界中のユーザーから機能のリクエストがあったり仕様の改善が頻繁に行われています。例のスクリプトではパージョンタグやコミットを指定することなくgit のリポジトリをクローンしてくることになります。結果としてmaster ブランチの最新コミットを常にダウンロードしてくることになります。これではメンバによってビルドする日時の違いによってビルドが成功したり失敗したりと安定しない状態となってしまう可能性があります。

//image[chap05/0012_FigureOfVersionOfModules][依存関係のバージョンまで管理できていない。ビルド日時によって成功・失敗が左右される][scale=0.65]

== 環境カスタマイズ
ツイート内容を集計して画像を作成するgrouzcope-batch では内側にwordcloud を使用しておりPyfhon の環境を整える必要がありました。Laradock はもちろんLaravel に特化した環境なのでPython の環境は我々で構築しないといけない。幸いにもLaradock はDebian 系のLinux ディストリビューションを採用@<fn>{chenv_04}しているので情報も多く構築は簡単だと感じていました。またMysql 8 を使っていましたが、認証方式のデフォルトが変更されていてLaravel からの認証が通らないなどの事態が発生していました。それらの問題をひとつひとつ解消するために私がとった行動はこれらをbash スクリプトで全て解決しようという試みでした。そしてできたbash スクリプトの一部(紙面の都合上省略や追加の改行あり)が下記のようなスクリプトです。
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

Docker ホスト側からコンテナ側に対してSQL を発行しているが、このようにbash とその標準入力や引数を使う事でコンテナ側のコマンドを呼び出す事ができます@<fn>{chenv_05}。戦略によっては、一旦ピュアなLaradock のイメージをビルドして、その後に我々で作成したDocker ファイルでそのLaradock のイメージをベースにgrouscope 専用のイメージをビルドする形式も取れましたが、当時はそこまでカスタマイズ規模は大きくならないだろうと思ってbash で小手先な対応をしていました。今となっては黒歴史です。

//footnote[chenv_05][決してこのような書き方を推奨するものではありません]

== 俺の環境では動いたのだよ俺の環境では

私がプログラミングやコンピュータに本格的にのめり込み始めたのは大学入りたての18歳頃、高性能なPC を安く作りたいとの思いから秋葉原で買ったPC パーツを揃え、組み立てた頃からだったと記憶しています。そして最初はHTML とCSS から組み始め、Java に入りそしてLinux に魅了されかれこれ約15年、それでも変わらず出くわす場面に私は出くわしてしまったのでした。

メンバの開発環境PC のOS はMac かLinux で、bash 環境が整備されているのであまり悩まずに構築する事ができました。grouscope 環境構築スクリプトを改修し続けて、メンバの開発環境を支え続けていた所、トキさんからSlack で報告をいただきました。

//image[chap05/0013_AReportFromToki][トキさんからいただいた報告][scale=1.00]

ビルドスクリプトがエラーで動かないという報告をいただいたのです。OS はトキさんがMac で私がLinux。違くとも同じbash 環境を備えている環境で動かしているスクリプト。そしてトキさんと同じMac 環境である、なおとさんの手元でもビルドは成功していると報告を受けています。何が原因だったのでしょうか。

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

これはMySQL のコンテナに対してmysql コマンドを実行してDB のデータを初期化しようとしている部分の処理のエラー出力ですが、一見するとMySQL コンテナが見つからないという内容のエラーに見えます。しかしビルドスクリプトが走ってmysql コマンドが走る時点でコンテナも起動するように組んでいるはずなので、コンテナが見つからないというエラーメッセージは想像しずらい...仮にコンテナの起動に失敗しているのであればそれより前の段階で失敗しているだろいうという個人の推測でした。そして一方で同じMac を使っているなおとさんのMac 環境では成功しているという報告をいただいていてトキさんのMac 環境では失敗しという状況で色々お話を聞いたところ、トキさんがやっている他の開発プロジェクトでもLaradock を使っているという情報を得る事ができました。

=== Docker を使った場合の永続的なデータの取扱
Docker ではコンテナ上にあるデータは、コンテナを削除してしまうと消えてしまいます。Docker を使うシーンではコンテナが削除されることを前提(コンテナがいつまでも残っているとは限らないことを前提)にしている事が多いため、もしコンテナ上で書き込まれたり削除されたりするデータを永続的に保持しておきたい場合はそれらのデータを永続化するために工夫が必要です。その内の戦略の一つとして、Docker ホスト側のディレクトリをDocker コンテナ側のにマウントする方法があります。

//image[chap05/0014_DockerVolume][Docker ボリュームのイメージ図][scale=0.90]

ホスト側のディレクトリをコンテナ側のディレクトリにマウントする事でデータの書き込みはコンテナ上のファイルではなくてホスト側のファイルに書き込まれるようになります。この状態でコンテナを削除すれば、失われる情報はコンテナ上の情報だけなので、マウントして書き込まれたDB のデータは残り続けることになります。

この性質を利用して、例えばMySQL のプログラムのバイナリ(実行ファイル)はコンテナ上のやつを利用しつつも、DB のデータ本体はマウントしたボリュームに置くことで更新されたデータはコンテナを削除しても残しておく事ができます。また、新規コンテナを立ち上げる時も同じディレクトリをマウントするようにしていれば、今までのデータを引き続き活用する事ができるようになるのです。

=== Laradock ではどうなっていたか
Laradock は標準でDocker ホスト側の~/.laradock/data ディレクトリをMySQL のデータディレクトリとしてコンテナ側でマウントしてデータを永続化するようになっています<foot>設定ファイルでマウントするディレクトリを変更可能です</foot>。これは場合によっては問題を引き起こす可能性があります。

例えばプロジェクトAでMySQL を使っていてユーザ名default、パスワードsecret を使っていたとします。またプロジェクトBでもMySQL を使っており、ユーザー名default パスワードpasswd を使っていたとします。そしてMySQL の認証情報としてポロジェクトAのユーザ名default パスワードsecret が設定されていた場合、プロジェクトBのLaradock コンテナを起動してDB にアクセスが発生した時、認証エラーが起こるでしょう。

(エラーを完全に特定できたわけではありませんが)今回の件は一旦~/.laradock/data ディレクトリを削除してLaradock を再起動することで解消しました。

=== どうすればよかったか
Laradock には永続化するデータを格納するディレクトリを.env ファイルのDATA_PATH_HOST で指定する事ができます。起動前にこの変数を変更して他のLaradock プロジェクトと被らない場所を指定するようにしましょう。この値には相対パスも指定する事ができます。なのであなたのLaravel プロジェクトにLaradock をgit submodule として取り入れて以下のように相対パスを指定しておけば、git リポジトリのディレクトリ内にDB のデータも含めておく事ができます@<fn>{chenv_06}。
//footnote[chenv_06][その場合、データディレクトリをコミットしないように.gitignore に含めておくようにしましょう]

//emlist[Laradock の.env のDATA_PATH_HOST に相対パスを指定する例]{
DATA_PATH_HOST=./.laradata
//}

このようにしておけば複数のLaradock を使うプロジェクトがあったとしても、プロジェクトのローカルのgit ディレクトリ内にデータが納まることになり、データの競合が発生することは無いでしょう。また、このようにすることによってローカルのgit ディレクトリを削除することによりMySQL のデータも一緒に消えることになります。

== ローカルのビルドスクリプトの欠点
現状Laravel の環境をbuild.sh というオリジナルなスクリプトを使って管理していると以下のような悩みごとがつきまとってきました。

 * 他プロジェクト等でlaradock のMySQL 環境が使われていたりするとデータや設定が混在してしまう可能性がある
 * build.sh が実行される環境のbash バージョンにより動かないことがある
 * build 環境が人それぞれ違うため、同じコマンドが通用しない

(1)に関しては前項で述べた通りのエラーで、データ永続化のためのマウントディレクトリが他のLaradock を使っているプロジェクトと被ったりすることによる問題です。(2)、(3)についてもう少し詳細に見ていくことにしましょう。

=== build.sh が実行される環境のbash バージョンにより動かないことがある
bash はMac にもLinux も入っている場合が殆どで、私が普段使っているArch Linux もbash が入っています。bash は安定していて、スクリプトを作成するのに役立つ便利な仕様や機能も多く備わっています。例えば以下のような書き方をする事で変数の中のアルファベット文字列を一律で大文字に変換する事ができます。パイプなどを使って他の文字列操作系のコマンドに、標準入力として値を渡さなくてもこのような文字列変換ができるようになっています。

//emlist[upper_string.sh]{
#!/bin/bash
something="Foo Bar"
echo ${something^^}        # FOO BAR
//}

私の手元のLinux にて実行すると想定通り"FOO BAR" という結果が得られます。しかし一部の環境では以下のようなエラーが出るかもしれません。

//cmd{
$ something="Foo Bar"
$ echo ${something~~}
bash: ${something~~}: bad substitution
//}

上記のような違いが出るのはなぜでしょう？既に答えがわかっている人もいるかもしれませんが、この記法はbash 4系から取り入れられた書き方でbash 3系で実行すると出るエラーです。bash 3系は今から10年以上前のバージョンのbash となりますが、Mac の現在(2019年08月執筆時点)のデフォルトシェルはbash 3系です@<fn>{chenv_07}。Mac が現在も3系をデフォルトシェルとしているのはGPLv3ライセンスのためではないかと言われています@<fn>{chenv_08}。このようにbash が入っていてもバージョン違いにより、動く環境とそうでない環境が出てきたりするので意識する必要があります。これに関してはbash に限らず他の言語に置いても同様です。今回のケースに関しては、チームメンバに呼びかけてbash をアップデートしてもらうことにしましょう。そして作成者側としてはbash に限らずスクリプトを作成したら、実行される環境を想定したテストを実施しておくことは当たり前ですがとても重要です。

//footnote[chenv_07][Mac デフォルトのシェルが2019年秋のCatalina からzsh になるようです。この書籍が皆さんの手元に届く頃には変わっているかもしれません(引用: https://www.theregister.co.uk/2019/06/04/apple_zsh_macos_catalina_default/)]
//footnote[chenv_08][先程示したURL に書かれています(引用: https://www.theregister.co.uk/2019/06/04/apple_zsh_macos_catalina_default/)]

=== build 環境が人それぞれ違うため、同じコマンドが通用しない
例えば同じbash バージョンを持っていたとしても、結局はbash が呼べるのは書く皆さんの環境にあるコマンドのみとなります。Mac とLinux におけるコマンドの違いについてはとても厄介なものとなります。これらの具体例については、言葉で語るより実例を使って説明したほうがわかりやすいでしょう。例えば以下のようなbash スクリプトを組んだ見たとしましょう。環境としてMac とLinux があったとして

 * 両方でエラー無く動くもの
 * Mac でエラー無く動くがLinux でエラー無く動かないもの
 * Linux でエラー無く動くがMac でエラー無く動かないもの

がこの中に含まれています@<fn>{chenv_10}。ここではコマンドのオプションを厳密に識別しやすくするために半角スペースを"␣"で表現するようにしています。

//footnote[chenv_10][条件を上げるとキリがないですが、Mac についてはMojave 標準のコマンド、Linux についてはUbuntu Desktop 18.04 標準インストール時点の環境とします。初期状態でコマンドがない場合はMac はbrew、Ubuntu はapt-get でインストールしてきたものを使用するとします]

//emlist[(1)サイトのSSL/TLS 証明書を確認するopenssl コマンド]{
# インターネット接続はあるものとする
openssl␣s_client␣-connect␣www.google.com:443␣-showcerts
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

(1)ですが、これはMac でもLinux でも動きます。筋の良い人は気付くかもしれませんが、openssl コマンドがそもそもMac 及びLinux で標準コマンドとしてありません。openssl コマンドは暗号化ライブラリとして非常に有名なものなので、OS 初期状態であったりインストール直後から入っていたりすることが多々あります。もしくは何かをインストールすると依存関係として取り入れられていることがほとんどです。openssl はMac やLinux 独自のものではないため、オプションや使用にあまり違いがありません。

(2)については「Linux でエラー無く動くがMac でエラー無く動かないもの」になります。Mac で実行しようとすると下記のようなエラーが出ます。
//cmd{
$ find . -type f -regextype posix-extended -regex '^.*/access_[0-9]+\.gz$' -exec chmod 640 {} \;
find: -regextype: unknown primary or operator
//}
"-regextype" というオプションが無いようです。find コマンドはMac もLinux もfind コマンドの仕様についてはIEEE Std 1003.1 @<fn>{chenv_11}に基づいていますので基本的に同じオプションが使えるようになっています。が、例外的にfind コマンドの正規表現オプションについてはMac とLinux で異なるのです(その他にもいくつかあるかもしれません)。理由までは見つけることができませんでしたが、少なくともMac で同様な正規表現オプションを利用する場合は"-E" オプションが使えます。
//cmd{
$ find -E . -type f -regex '^.*/access_[0-9]+\.gz$' -exec chmod 640 {} \;
//}
このようにIEEE を基にしているからといっても必ずオプションまで一緒とは限らないものも潜んでいたりしますので注意が必要です。

//footnote[chenv_11][エディション違いはあるかもしれませんが、IEEE Std 1003.1 のfind コマンド2018年エディションは http://pubs.opengroup.org/onlinepubs/9699919799/utilities/find.html]

最後に(3)ですが、これは「Mac でエラー無く動くがLinux でエラー無く動かないもの」になります。Linux で実行した場合の結果は以下のようになります。
//cmd{
$ sed -i "" -e "s/^Foo/Bar/g" file.txt
sed: can't read : No such file or directory
//}
1 点補足ですが、このコマンドは上記のエラーが出ても想定通りの挙動をしており、file.txt 内の文字列置換は成功します。エラーが出るのです。これもMac とLinux の基本コマンドの差異により出るものですが、Linux の場合は上記のように指定すると""(空文字)という名前のファイルと"file.txt" という名前のファイル、2 つに対して文字列置換を行おうとします。が、""(空文字)という名前のファイルが無いのでそちらについては失敗しているというエラーメッセージになります。Linux でエラー無く想定通りの処理をするには以下のようにします。
//cmd{
$ sed -i"" -e "s/^Foo/Bar/g" file.txt
$ # or
$ sed -i -e "s/^Foo/Bar/g" file.txt
//}
1 つ目のコマンドは-i と"" の間に半角スペースが無いので注意してください。一方でMac でこのコマンドを実行すると以下のようになります。まずは上記の1 つ目のコマンドを実行してみましょう。
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
こちらも先程と同じような結果になりました。このように同じ"-i" オプションでもここまで挙動が違うのです。ここでまずはLinux のsed コマンドのドキュメントを見てみると次のようになっています。
//emlist{
......
-i[SUFFIX], --in-place[=SUFFIX]

       edit files in place (makes backup if SUFFIX supplied)
......
//}
一方でMac のsed コマンドのドキュメントを見てみると次のようになっています。
//emlist{
-i extension
        Edit files in-place, saving backups with the specified extension.  If a zero-length extension is given, no backup will be saved.  It is not recommended to give a zero-
        length extension when in-place editing files, as you risk corruption or partial content in situations where disk space is exhausted, etc.
//}
微妙にファイル拡張子を指定する位置が違います。Linux のsed では"-i" オプションのすぐ後に空白なしでファイルの拡張子を指定するようになっているのに対し、Mac のsed では空白を1 つ開けて拡張子を指定するようになっています。ドキュメント的には挙動は正しそうです。

このように同じコマンドでも環境によってオプションの指定方法が違ったりすることで思わぬエラーを出すことがあります。Mac にもGNU コマンドを入れるように強制することはできますが、メンバ全員の端末に対してそれを実施するのはあまり現実的ではありません。またMac とLinux でコマンドのオプションを分けるように条件分岐を入れたとしても、実はとあるメンバのMac 環境だけGNU コマンドがインストール済みでそれを使うように設定されたいたりすると、逆に条件分岐を入れることでエラーと成る可能性があります。簡単には解決できなさそうです。このように各メンバの手元で実行するスクリプトで環境構築を解決していくには限界を感じ始めていました。

== Docker Automated Build の利用
ビルド済みのイメージを公開してメンバ間で共有する仕組みは無いかと考えていた所、Docker Automated Build を思い出しました。このDocker Automated Build の構築について考えていくことにします。また今回Docker Automated Builds を使用するに当たりLaravel の利用は一旦やめることにしました。理由としてはDocker イメージの構成をよりシンプルにして我々側でイメージの管理をやりやすくするためです。

=== Docker Automated Builds とは
Docker Inc が提供するDocker Hubにて、Github やGitbucket 上のリポジトリと同期してリポジトリ内のDockerfile を基に自動ビルドを行なって自動的にイメージを作成して共有してくれるサービスです。これを利用することで開発メンバのPC 上でビルドするスクリプトを廃止することで環境差異による問題を解決するのに一役買うと考えていました。

//image[chap05/0021_ImageOfDockerAutomatedBuilds][Docker Automated Builds の流れ][scale=0.80]

=== Dockerfile の作成
Docker イメージをビルドするためのDockerfile を作成します。Dockerfile はイメージをビルドするための処理や設定を記述するためのファイルです。Dockerfile を我々で管理することでベースとなるDocker イメージはUbuntu かCentOS かそれとも他者が作成したnginx やPHP か、インストールするパッケージは何かといった情報を指定することができます。今回用意するDockerfile はLaravel 実行環境の本体となるphp-fpm、それに対するリバースプロキシサーバとなるnginx とすることにしました。またDB としてMySQL 利用することを考えていましたが、こちらについては我々がDockerfile を作らなくとも公式のMySQL イメージで事足りると判断したためDockerfile は作成しませんでした。

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

パッケージをアップグレードして事前に用意したnginx の設定ファイルdefault.conf を置き換えるだけです。default.conf はLaravel コンテナに対してリバースプロキシをするを設定を入れています。

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

の部分でLaravel コンテナに対して、SCRIPT_FILENAME パラメータとして渡す値を組み立てるためにあります。逆にnginx のドキュメントルートにコンテンツは置かないようにしてください。try_files ディレクティブがindex.php パスを付与しなくなり想定しない動作となってしまいます。これはLaravel のコンテナに対してFast CGI パラメータSCRIPT_FILENAME が渡されるようになり、想定される値は先程設定したroot ディレクティブの値と組み合わされ"/var/www/html/a6s-cloud/public/index.php" となります。この後作成するLaravel コンテナではそのディレクトリにLaravel のコンテンツ及びindex.php を置くように作成する必要があります。あと最後にリバースプロキシ先としてLaravel コンテナを指定することを忘れないようにしてください。
//emlist[(2)リバースプロキシパスの設定]{
fastcgi_pass laravel:9000;
//}
nginx コンテナ設定ファイルの主なポイントとしては以上です。

==== Laravel イメージ

次にLaravel イメージを作成していきましょう。Laravel イメージのDockerfile は以下のようになります。

//emlist[Laravel のDockerfile 一部抜粋(紙面の都合上一部改変)]{
FROM php:7.3-fpm-stretch

RUN apt-get update && \
  DEBIAN_FRONTEND=noninteractive apt-get upgrade -y && \
  DEBIAN_FRONTEND=noninteractive apt-get install -y ... && \
  DEBIAN_FRONTEND=noninteractive apt-get install -y python3 python3-pip && \
  docker-php-ext-configure gd --with-freetype-dir=/usr/include/ ... && \
  # ...(略)...

COPY grouscope_entrypoint.sh /opt/grouscope_entrypoint.sh
COPY install_git_modules.sh /opt/install_git_modules.sh
COPY wait_until_mysql_started.sh /opt/wait_until_mysql_started.sh

# ...(略)...

CMD ["/opt/grouscope_entrypoint.sh"]
//}

Laravel イメージはphp-fpm イメージをベースに作成するようにしています。ベースイメージのタグを"php:7.3-fpm" ではなく"php:7.3-fpm-stretch" としているのは2019年07月にあげられたPHP のgd モジュールのissue のためです(https://github.com/docker-library/php/issues/865)。Dockerfile の記載の主な内容としては、既にphp-fpm イメージをベースにしておりPHP の環境はだいたい揃っているので、好みのPHP エクステンションの追加及びgrouscope が依存するPython 製バッチを実行するためのPython をインストールしています。そしてコンテナが起動した時に実行されるentrypoint 用のスクリプトも準備し、そのなかでcomposer install を実行してアプリケーションが依存するパッケージ類をインストールしています。PHP 以外の依存としていくつかのgit submodule とPython のパッケージがありますが、それはcomposer.json のpost-install-cmd で、composer install が実行された後に続けてインストールするコマンドが実行されるようにしています。

//emlist[composer.json の一部抜粋(紙面の都合上一部改変)]{
  # ...(略)...
  "scripts": {
    # ...(略)...
    "post-install-cmd": [
      "@php artisan migrate",
      "@php artisan db:seed",
      "pip3 install -r requirements.txt",  # Python の依存インストール
      "git submodule update --init --recursive"  # git submodule の依存インストール
    ],
    # ...(略)...
  }
//}

残りのwait_until_mysql_started.sh というスクリプトファイルはNginx、Laravel、MySQL コンテナと同時に起動した時にMySQL が接続する準備ができていないのにDB 接続をしようとしてエラーが出るのを防ぐために作成しました。このスクリプトを使ってDB が接続できるのを確認してからDB のマイグレーションを実行してアプリケーションが始動するようになっています。

==== MySQL イメージ
次にMySQL ですが、こちらはオフィシャルのMySQL のイメージをそのまま使うことにしました。MySQL のオフィシャルイメージではコンテナを起動した時にコンテナの"/docker-entrypoint-initdb.d" ディレクトリ下に".sh"または".sql"、".sql.gz" という拡張子のファイルがあった場合、それを実行するようになっています。なのでDB の初期化やユーザを作成するSQL 及びその他実行したいコマンドがあればそのディレクトリに入れておけば良いのです。今回は以下のようなSQL ファイルを1 つだけ用意してMySQL コンテナ起動時にDB の初期化とユーザを作成するSQL を格納しておきました。
//emlist[]{
CREATE DATABASE IF NOT EXISTS a6s_cloud;
-- ALTER USER 'default'@'%' IDENTIFIED WITH mysql_native_password BY 'secret';
CREATE USER 'default'@'%' IDENTIFIED WITH mysql_native_password BY 'secret';
GRANT ALL ON a6s_cloud.* TO 'default'@'%';
//}
テーブルを作成する処理が無いですが、それはLaravel コンテナから実行されるマイグレーションコマンド"php artisan" で作成される予定なのでここで作成する必要はありません。むしろテーブル構成や管理のことを考えるとLaravel のマイグレーションに任せたほうが良いでしょう。ここではLaravel がMySQL に接続してDB を操作できるようになるまでの最低限の処理だけにしておきます。

=== Dockerfile のテストビルド
Dockerfile が作成できたらテストのために一旦手元でビルドしてみましょう。ビルドするには各Dockerfile があるディレクトリに移動して"docker build" コマンドを叩きます。

//cmd{
$ # grouscope-backend のリポジトリroot にいることを想定
$ cd docker/nginx
$ docker build -t a6scloud/grouscope-nginx .
$ cd ../laravel
$ docker build -t a6scloud/grouscope-laravel .
//}

nginx とlaravel のイメージのビルドそに成功しましたでしょうか？これでイメージの準備はほぼ完了です。次はDocker Hub での作業を実施していきます。

=== Docker Hub Organization を作成する
Docker Hub にイメージを公開する場合は私個人のアカウントのリポジトリでも構いませんが今回我々はa6scloud というチームを作っており、せっかくなのでa6scloud という名前のorganization を作ることにしました。この名前は後ほどDocker イメージをpull する時に指定される名前となるので注意してください。今回は既にDocker Hub にアカウントを持っている前提で話を進めていき、また厳密な手順については別の機会に説明するとして今回は概要のみを説明します。

それではDocker Hub にログインしましょう。画面右上のメニューにOrganizations が表示されるのでそれをクリックします。するとOrganizations ページに遷移して"Create Organization +" ボタンが表示されます。

//image[chap05/0031_CreateDockerOrganizations][Organization 作成ページ][scale=1.0]

それをクリックすると以下のような項目の入力を要求されます。

 * Organization Namespace
 * Organization Full Name
 * Company
 * (Optional) Location
 * (Optional) Gravatar Email
 * (Optional) Gravatar URL

Organization Namespace がイメージをpull する時に指定される名前の一部になるので注意するようにしてください(今回はa6scloud という名前にしました)。その他の項目についても、チームのメンバに相談するなどして決めていったほうが良いかもしれません。
Organization を作成したらOrganization ページから先程作成したOrganization をクリックしましょう。するとデフォルトでowners というチームができていると思います。必要に応じてowner 権限レベルのチームメンバを追加するようにしてください。

//image[chap05/0032_AddOwnersToOrganizations][Organization ページ][scale=1.0]

Organization を作成したら次はリポジトリを作成しましょう。真ん中の右側にあるRepositories をクリックするとリポジトリ一覧ページに遷移します。

//image[chap05/0033_CreateRepositoriesInOrganization][リポジトリ作成画面][scale=1.0]

ここで"Create Repository" をクリックしてリポジトリを作成します。すると"a6scloud" というプレフィクスに続くリポジトリ名を要求されます。今回作成するのはNginx とLaravel のイメージで、"grouscope-nginx"、"grouscope-laravel" とすることにしました。合計2 つのリポジトリを作成します。リポジトリを作成したら次はAutomated Builds の設定を行ないます。リポジトリを作成したらリポジトリの画面へ移動して上部メニューの"Builds" を選択して"Configure Automated Builds" ボタンをクリックします。

//image[chap05/0034_CreateRepositories][リポジトリ作成画面][scale=1.0]

するとBuild に関する設定画面に遷移します。我々が入力する項目としては"SOURCE REPOSITORY"、"AUTOTEST"、"REPOSITORY LINKS"、"BUILD RULES" になります。その中でもBUILD RULES はDockerfile からイメージをビルドするための重要な情報になるので間違え無いように入力してください。内容を間違えてしまうと、たとえローカルのビルドに成功していたとしてもDocker Hub 上でのビルドに失敗する原因になりかねません。今回a6scloud にて作成した"grouscope-nginx" リポジトリについては図のようになります。今回はa6scloud/grouscope-backend GitHub リポジトリのmaster ブランチとtesting ブランチにてpush を検知すると/docker/nginx/Dockerfile ファイルを使ってgrouscope-nginx イメージのビルドが走るように設定をしました。これと同様に"grouscope-laravel" イメージのビルド設定も行うようにしてください(図6.18)。

//image[chap05/0035_ConfigureAutomatedBuilds][Nginx イメージのAutomatedBuilds の設定画面][scale=1.0]

これでDocker Automated Builds の準備は完了です。GitHub にてmaster もしくはtesting ブランチにリソースがpush されるとDocker Hub にて自動ビルドが走りイメージが更新されるようになります。master もしくはtesting GitHub ブランチにリソースをpush 後、Automated Builds が完了すると以下のようなコマンドでイメージをpull できるようになります。

//cmd{
$ # testing タグのa6scloud/grouscope-nginx イメージをpull する例
$ docker pull a6scloud/grouscope-nginx:testing
$ # latest タグ(GitHub master ブランチ)のa6scloud/grouscope-nginx イメージをpull する例
$ docker pull a6scloud/grouscope-nginx:latest
//}

=== docker-compose ファイルを作成する
Docker Automated Builds でイメージも準備できましたのでこれで開発環境のDocker コンテナを起動できます。しかし今回の開発環境は複数のコンテナからなりNginx、Laravel、MySQL のコンテナの起動をもって開発環境の完成とみなされます。ということはそれらコンテナの依存関係を解決する必要があります。これらの依存関係を管理するために今回はdocker-compose を使用します。

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

上記のように合計3 つのコンテナを起動するように指定し、それぞれgrouscope_laravel コンテナはgrouscope_mysql コンテナに依存し、grouscope_nginx はgrouscope_laravel コンテナに依存する関係もdepends_on キーワード宣言し、それぞれが起動するタイミングを定義しています。またボリュームのマウントとしてgrouscope_laravel コンテナはこのdocker-compose.yaml ファイルがあるディレクトリと同じディレクトリをコンテナ上の/var/www/html 上にマウントするようになっており、最終的にアプリケーションの起点となるindex.php が/var/www/html/a6s-cloud/public/index.php としてgrouscope_laravel コンテナから見れるようになります。そして環境変数としてgrouscope_laravel コンテナではMySQL へ接続するユーザ名やDB 名をするようになっており、Twitter からツイート情報を取得してくるためのAPI キーを.env ファイルから読み込んでコンテナの環境変数として反映するようになっています。その他にもホスト側とバインドするポート番号やpull してくるイメージのタグ名も.env ファイルから取得して値を指定する用になっています。docker-compose ではデフォルトでdocker-compose.yaml ファイルと同じディレクトリにある.env ファイルを読み込んでdocker-compose.yaml 内の変数を宣言することができるようになっていて、今回我々のプロジェクトの.env ファイルは以下のように作成しました。

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
docker-compose の環境ができたところでdocker-compose でコンテナを起動してみましょう。イメージは既にmaster ブランチにリソースがpush されていてAutomated Builds により既に作成されている想定です。

//cmd{
$ docker-compose up
......
grouscope_laravel | > git submodule update --init --recursive
grouscope_laravel | [DD-MMM-YYYY hh:mm:ss] NOTICE: fpm is running, pid 1
grouscope_laravel | [DD-MMM-YYYY hh:mm:ss] NOTICE: ready to handle connections
//}

grouscope_nginx、grouscope_laravel、grouscope_mysql コンテナが起動してPHP の依存モジュールをインストールしてDB テーブルのマイグレーションをしてgrouscope_laravel コンテナが最後に起動したログが出力されています。これでgrouscope_backend の起動は完了です。

これで開発環境が完成しました。今までローカルで開発環境のDocker コンテナをカスタマイズするスクリプトをそれぞれのメンバで走らせていたときとは違い、こちらはイメージのビルドが完全にDocker Hub 上で行われるのでメンバのPC の環境に左右されません。またdocker-compose を利用することで1 コマンドで複数コンテナの起動と停止、環境変数等の設定を管理することができるため開発メンバ向けのドキュメントも肥大化すること無くメンテにかかるコストも減らすことができました。

=== Laradock を使ったほうが良いか独自に作ったほうが良いか
今回のdocker-compose を利用することで、結果的にLaradock から離脱するような形になってしまいました。果たしてLaradock から離れることは判断として正しかったのか？それは未だにわかっていません。しかし今回のケースではシンプルなLEMP 環境があれば充分であったためLaradock はオーバーキルな状態にありました。またLaradock は公式のドキュメントどおりに使うにはとても良いのですが、その中に独自のPython 環境を入れようとしたりすると結局は自分の手でカスタマイズすることが多くなっていき、あまり恩恵を感じることがありませんでした。また今までは各メンバPC 上でビルドを走らせることによりビルドを実行した日時によって内部の細かいパッケージ等のバージョンが微妙に異なるようになったりすることで、各メンバに対して同一なイメージを配布することはできていませんでした。そして考えた結果、自分でDockerfile を組んでイメージを作成し、更にDocker Automated Builds を使うことでメンバのビルド日時や環境に依存すること無く、同一な開発環境イメージを各メンバの手元に配布することができるようになりました。

どちらが正解かはわかりませんが、確実に言えることはシンプルなLEMP 環境であれば自作のDocker イメージでも充分に開発に耐えられることです。一方で今後アプリケーションに高度な仕様が出てきた時にRedis と組み合わせたりメール送信サーバと組み合わせたりといったものが出てきた場合、またLaradock に戻ってくるといった選択は充分にありえるでしょう。

=={sec-ext1} デプロイ
AWS、Heroku、GCP、そして自宅サーバ

=={sec-ext1} CI
CircleCI、TravisCI

