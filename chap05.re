= 環境構築
== Linux 愛好家、Webアプリ畑に立つ
Web アプリ画面を飾りエンドユーザーに魅力的なビジュアルや体験を与えるフロントエンジニア。今話題となっているAngular、React、VueJS を使ったレスポンシブでインタラクティブな画面はユーザのみならず「自分もこんなものを作ってみたい」と開発者の道に入る人も少なくないでしょう。現代のIT 技術者として花形の一種です。一方で真っ暗な画面に白い文字が真夏のスコールのごとく流れてくる中で、それに負けじとキーボードをパタパタ叩いては、また降ってくる文字を見てまたキーボードを叩いていく…。一見すると地味で何が面白いのか理解できなかったりする、でもそんな傍からの視線を気にすることもなく、我が愛するコンピュータとコマンドと通じて直に会話することに虜になっている人もいます。そう、今回環境構築周りをメインに執筆させていただく私、つとむもその虜になってしまった人間のうちのひとりです。

そんな私ですがgrouscope の開発に入ることになりました。どのようにして入ったのか等の経緯はなおとさんの記事に譲るため割愛させていただきます。普段Linux ばかり触っていてLinux の流行を少しは知っているがWeb アプリのことは殆ど知らない属性の人間が、どのようにWeb アプリ開発チームに入って貢献できるだろうかと最初は難しさを感じていました。そんな中で私はバックエンド側の環境構築をメインにやることになり、プロジェクトで採用した技術要素や立ちはだかった壁とその乗り越え方について色々学んでいくものがありました。今回の環境構築の記事はバックエンドがメインとなってしまいますが、私なりに普段フロントエンドで開発をしている方々にも、バックエンドで開発している方々両方にわかりやすく楽しく書いていきたいと思いますので、どうかお付き合いいただければと思います。

== アプリケーションの概要
今回開発するgrouscope はtwitterハッシュタグ分析プラットフォームです。Web 画面に任意のハッシュタグを入力することで、そのハッシュタグがつけられているtweetの傾向を分析し、画像・グラフ・ランキングといった形式に可視化し、hot なハッシュタグを探すことを可能にするものです(GitHub のREADME より一部抜粋し加筆)。今回はフロントエンドとバックエンドでGit リポジトリを分けて開発していくことになりました。

=== フロントエンドの技術要素概要
フロントエンドの技術要素として、ユーザインタフェースを構築するためのJavaScript フレームワークとしてVue.js を採用することになりました。Vue.js は現在日本でも活発に採用されるようになってきてGitHub Start 数も全GitHub リポジトリの中でも有数のものとなってきていて人気とコミュニティの活発さから採用しました。またUI のデザインや色、モーション等をつけるコンポーネントライブラリとしてElement を使用することになりました。こちらはすでになおとさんが実務で利用した経験があるのと使いやすいと評判がありました。またElement もコミュニティが活発で開発が盛んなので採用に至りました。現在は上記のような構成となっていますが、後からデザインの仕事をされているのなとさんが加わったため、現在デザイン及びユーザインタフェースについては大改修中です。その時にはまた利用する技術要素も変わってくるかもしれません。

=== バックエンドの技術要素概要
バックエンドの技術要素として、まずDocker があります。開発期間中は各開発者のPC にプログラムを実行するためのサーバを用意するために使っています。そしてアプリのバックエンドのWeb アプリケーションフレームワークとしてPHP のLaravel を採用しています。今回はLaravel はレンダリングされたWeb 画面をユーザで返す用に使われることもありますが、今回はAPI サーバとしてクライアント側にJSON を返すようにして利用しています。Laravel はAPI 用のフレームワークも用意されているので、API サーバのフレームワークとして使うのも苦ではありません。またDB にはMySQL、Web サーバにはnginx、画像を作成するバッチを実行するためにPython 環境も取り入れています。

//image[chap05/architecture][フロントエンドとバックエンドの技術要素構成図][scale=1.0]

== リポジトリの構成
TODO:

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

・Laradock: Laravel の実行及び検証環境
・grouscope-backend: word cloud API を呼び出すPython 製batch スクリプト
・RictyDiminished: word cloud 画像に埋め込む文字フォント

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


=={sec-ext1} デプロイ
AWS、Heroku、GCP、そして自宅サーバ

=={sec-ext1} 俺の環境では動いたのだよ。俺の環境では
Mac/Linux 間での環境差異やLaradock を他プロジェクトで使用していた場合で起きる問題が発生。

=={sec-ext1} Laradock を脱却してDocker Automated Builds の活用してみよう
まずはローカルでDockerfile を作成してビルドしよう。
Python 環境等の独自のカスタマイズが発生する場合は脱却するのもあり。

=={sec-ext1} Dcoker Hub でOrganization を作成しよう
Docker イメージをpush する場所を作成する。

=={sec-ext1} Automated Builds で
他の人のPC 環境に依存しないビルドの強み。

=={sec-ext1} CI
CircleCI、TravisCI

