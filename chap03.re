= 利用したサービス紹介

//textleft{
なおと
//}

本章ではチーム開発をした際に使用したサービスやツールの紹介をしていきます。

=={sec-ext1} 設計書作成

チーム開発と個人開発の大きな違いは作るものを皆で共有する必要があることです。
個人開発では自分さえ分かっていれば良いので設計書も作る必要がないかもしれません。
しかし、チーム開発で何をどう作るかが明確化しなければタスクを分割できません。

ここでは設計書のツール達を紹介していきます。

=== plantUML
==== plantUMLとは
http://plantuml.com/ja/

下記のような図(一例)をコードベースで作成できるサービスです。

 * シーケンス図
 * ユースケース図
 * クラス図
 * アクティビティ図
 * コンポーネント図
 * 状態遷移図
 * オブジェクト図
 * 配置図
 * タイミング図

コードベースで管理できるため、GitHubでバージョン管理が可能ということです。

//image[db][GitHubで差分][scale=0.8]

DBの設計書とシーケンス図で使用しました。DBのリレーション関係は図で書くのが分かりやすいです。
シーケンス図を書くことで誰がどんな処理を実装すればよいのか分かるのでタスクがふりやすくなります。

=== drow.io
==== drow.ioとは
https://www.draw.io/

フローチャートやオフィスのレイアウト図、ネットワーク図を作成できる無料の作図ツールです。
Chrome等のブラウザを使用して作成していきます。こちらもGitHubのコードベースで管理できます。

システム構成図を作成しました。

=== cacoo
==== cacooとは
フローチャートからワイヤーフレーム、プレゼン資料まで作れる「オンライン作図ツール」
最小3人(3アカウント)からのチーム単位なら無料でりようできます。

=== Keynote、googleスライド
デザインを考えたりする際にsketch、figmaなどのデザインツールが必要だと考えていませんか？
僕もデザインツールが必要だと思っていましたが学習コストが高く何度も挫折しました。
なので簡単なワイヤーレベルはKeynote等を使っています。慣れ親しんでいるので簡単に作成できます。
画像を入れる

=== スプレットシート
DBの設計書を書く際に使用しました。
GitHubで管理できないのが難点ですが、表敬形式で作成する際は何だかんだスプレットシートが便利です。
画像を入れる

=== swagger
API仕様書ツール
フロントとバックエンドの開発を分けるためにSwaggerを使いました。
SPAの良い所はフロントとバックエンドのタスクを切り分けられることです。

=={sec-ext2} ナレッジ共有
環境構築の手順やツールの使いた方はドキュメントに残すべきです。
その際にどこにドキュメントを置くかは検討する必要があります。

=== kibela
SaaSの情報共有ツールです。フリープランでは5ユーザーまで無料で使用できます。
画像の組み込みがドラックアンドドロップで可能な所が良いです。
ただ、管理ツールが増えてしますのが難点ではあります。
僕達はオープンにできない情報などはkibelaに記載するようにしていました。

=== GitHubのプロジェクト内
環境構築や使い方はプロジェクト内にドキュメントを掘って書いていました。
ドキュメントがプロジェクト内で収まること、差分の確認がしやすいことがメリットです。
画像を入れる際はkibelaのようにドラッグアンドドロップできず、フォルダに画像を置いて参照する形になるため少し手間ではあります。

=== GitHub Wiki
GitHubにはWikiもあります。
編集がしづらい、画像を入れづらいなど正直こちらは使いづらかったです。
個人的にはプロジェクト内にドキュメントを管理することで対外的もアピールでき、集約もできるのでおすすめです。

=={sec-ext3} コミュニケーションツール

=== slack
コミュニケーションツールのデファクトスタンダードですね。
外部ツールとの連携も簡単にできます。

 * general
 ** 全体的なアナウンスをする時に使用しています
 * random
 ** プロジェクトに関係ない雑談でしようしてます、
 * grouscope_applog
 ** アプリケーションのエラーが発生した場合の通知先のチャネルです。
 * grouscope_backend
 ** バックエンドのリポジトリの通知用チャンネルです。issueやコメント、プルリクの作成時に通知するようにしています。
 * grouscope_batch
 ** バッチのリポジトリの通知用チャンネルです。issueやコメント、プルリクの作成時に通知するようにしています。
 * grouscope_front
 ** フロントの通知用チャンネルです。issueやコメント、プルリクの作成時に通知するようにしています。
 * grouscope_netlify
 ** netlifyのデプロイ状況を通知するチャンネルです。issueやコメント、プルリクの作成時に通知するようにしています。
 * grouscope_デザイン
 ** 画面デザインの話をするチャネルです。デザイナーがJOINしたのをきっかけに作成
 * grouscope_ミーティング
 ** 対面やオンラインMTGする際にスケジュール調整や議事録っぽいのを残すチャンネルする
 * grouscope_開発
 ** プロジェクトの開発に関するを話をするチャンネルです。
 * grouscope_kibela
 ** kibelaで記事の作成やコメントを書いた際に通知するチャネルです。

=== zooms
オンラインMTGで使用できます。
画面共有もあるので、自分の画面を見せながら進めることが可能です。

=={sec-ext4} Git Hub関連
=== pullpanda
コードレビューワークフローを効率化するためのツールです。

【GitHub】コードレビューツールのPull Pandaを一部触ってみた(https://qiita.com/turmericN/items/095c0318dd14cad71cdc)

=== Dependabot
依存パッケージの更新を定期的にチェックし、更新があった際にプルリクエストを作成してくれるサービス

Dependabotで依存パッケージ更新のプルリクを作成してもらう(https://qiita.com/turmericN/items/b4c49bf71b28120f1238)

=== organizationアカウント
GitHubでチーム開発をするには下記のような方法があります。

 * １人がプロジェクトを作成して、他の人はForkして進める
 * １人がプロジェクトを作成して、他の人にcollaboration権限を付与する
 * organizationアカウントを作成して、他の人にcollaboration権限を付与する

僕達は最初2番の方法で進めていました。ただ、リポジトリを作成するたびに権限を追加する手間もありました。
そのためorganizationアカウント管理に途中から変更しました。個人リポジトリから移管する作業がありますが、参照リンクとうはGitHubがうまくやってくれるのでそのままでも問題ありません。
また、organizationにするとプロフィールにorganizationのアイコンが表示されるためモチベーションも上がってきます。

=== Projects
GitHubのProjectsとはカンバンです。
これを使用することで現在の進捗がひと目で分かるようになります。
issueやpullrequestにも対応しているのでcloseしたらissueを閉じるなど自動で可能です。

僕たちも導入してみましたがそこまで活性化しなかったです。
そもそもスケジュールありきの開発をしていなかったのでissueで確認を行っていました。

=={sec-ext5} その他

=== ロゴメーカ
よしslackもプロジェクトも作成したとなったらロゴを作成したくなりませんか？
しかし、ロゴなんと思いつないし、書けない。
こういう時はロゴメーカーがとても良いです。
基本的に自分の好きなものを選択していくと多くの画像が生成されます。

=== vscode live share
物理的に離れている時に実装などを教えてもらう時は、実際にコードを触れると便利です。
vscode live shareは画面共有がほぼ遅延なしで可能です。またターミナル操作も共有できるのでコマンド操作も可能です。
実際にやりましたがエラーやコードレビューは直接書き方を見せれるので分かりやすいです。