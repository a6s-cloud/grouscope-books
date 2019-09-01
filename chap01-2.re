= チーム開発のすすめ方

//flushright{
なおと（@naoto_7713）
//}

=={sec2-ext0} はじめに
皆さん、「今からチーム開発をしてください。」と言われたらどうしますか。
最初に何から決めていきますか。作るものでしょうか。それとも使用する技術でしょうか。もしくは開発フローでしょうか。
僕は何も分からない状態からプライベートでチーム開発を始めていきました。
仕事でチーム開発の経験はありますが、自分で0から立ち上げたことはありません。
「チーム開発の始め方」と調べても、体系的にまとめているサイトは少ないです。

そこで本章では、僕たちが実践したチーム開発の進め方を紹介していきます。
プライベートでチーム開発を始めてみたいけど、何をすれば良いのか分からないといった問題を少しでも解消できれば幸いです。

=={sec2-ext1} チーム開発の目的を決めよう
最初にチーム開発の目的を決めていきましょう。
目的を決める理由は、意思決定をスムーズにするためです。
意思決定とは特定の目的・目標を達成するために、ある状況において複数の代替案から、最善の解を求めようとすることです。

例えば、プロダクトを作ってマネタイズしたい人と転職活動でアピールできる成果物を作りたい人がいるとしましょう。
GitHubのリポジトリを作成する際、リポジトリをPublicにするかPrivateにするかで意見が対立するかもしれません。
このような時、あなたならどうやって決めていきますか。多数決で決めますか。それとも、じゃんけんで決めますか。

このようにチームの目的を明確化していないと、その時々によって判断基準が曖昧になり、合理的な意思決定が難しくなります。
チーム開発を進めることは意思決定の連続です。そのため、判断基準としての目的を決めておきましょう。

例えば、プライベートのチーム開発では次のような目的が挙げられます。

 * 【スキル志向】技術のスキル向上を目指す
 * 【プロセス志向】チーム開発のプロセスを経験して、チーム作りをしっかりする
 * 【プロダクト志向】プロダクト作りをしっかりして、使ってもらえるサービスを目指す
 * 【成果物志向】転職でアピールできる成果物を作成する

目的は1つにする必要はありませんが、意思決定する際の優先度は付けておいたほうがよろしいでしょう。

僕たちの場合は「チーム開発の経験を通して、スキルアップを目指す」というスキル志向の目的を掲げました。

=={sec2-ext2} 作るプロダクトを決めよう
実際に何を作るのかを決めていきましょう。
しかし、どんなプロダクトを作るかをすぐに思いつかないという方もいることでしょう。
そんな時は、既存システムを真似するような形で良いと思います。

下記サイトに個人開発プロダクトが集約されています。
他の方がどんなものを作られているのか分かるので、参考にするのも良いでしょう。

 * 開発会議(https://devtalk.jp/)
 * 個人開発のフリマ(https://devmart.jp/)
 * litfire(https://litfire.jp/)

サービスのアイディアを考える際のアプローチとして次の2つから考えていく方法もあります。

 * 課題解決系
 * エンタメ系

課題解決系とは文字通り不満や課題、願望からプロダクトを考えていくアプローチです。
例えば、勉強会の雰囲気をもっと知りたい、お昼ごはんを自動で決めたい、などの「〜したい」を挙げていく形です。

エンタメ系は、娯楽や面白さを考えていくアプローチです。
アニメ・ゲーム、漫画など新しいものを生み出していく形です。

最初は課題解決系のほうが、自分の不満や願望からサービス作りができるので考えやすいと思います。
僕たちのプロダクトも、「勉強会の雰囲気を掴んで、参加するハードルを下げたい」という課題解決系で考えました。

=={sec2-ext3} ペルソナを作成しよう
作るものが決まったら、ペルソナを考えていきましょう。
ペルソナとは企業や商品の典型的なターゲットとなる顧客像のことです。Webサービスの場合は、利用ユーザとなります。
しかし、なぜペルソナを作成する必要があるのでしょうか？
それはプロダクトを作成する際に、メンバー間の認識を合わせるためです。
プライベートのチーム開発は皆で集まることが少なく、対面コミュニケーションではなく、チャットベースでのやり取りが基本となります。
対面であればジェスチャーや図などでも説明することが可能ですが、チャットだと文字のみとなります。
そのため、自分の考えを伝えることは対面よりも非常に難しくなります。
ペルソナは前提条件をメンバー間で共有するための作業です。

以下は僕たちが実際に作成したペルソナです。

//image[persona][ペルソナ][scale=1.0]

ここまで細かく設定を練る必要はありませんが、具体的な人物像を想像し、作成すると、要件や機能を考える際に、「長谷川くんなら〇〇と考えるだろう」とペルソナ視点で具体的に考えることができます。
前提条件が一致しているため、コミュニケーションのズレも少なくなります。

ペルソナは１人の人間を表すので具体的に作成するのがコツです。

 * 名前
 * 年齢
 * 職業
 * 大学
 * 使用言語
 * 家族構成
 * 性格
 * 職場環境
 * 生活環境

余談ですが、この作業は実際にやってみると皆の経験や願望が反映されるので面白いです。
皆でワイワイしながら是非作成してみてください。

=={sec2-ext4} 使用したい技術を検討しよう
技術が好きなエンジニアなら技術選定は楽しい作業でしょう。
Vueがやりたい、Reactがやりたいなど様々な希望が挙がってくると思います。
意見が分かれた時に、意識したいことはチーム開発の目的に沿った技術選択をすることです。
転職活動のアピールが目的ならばその時IT業界で需要のある技術を選択することになりますし、プロダクト作成が目的ならば後々の機能追加や保守の側面から自分たちの知見のあるものを選択したほうが良いでしょう。意思決定する際は、チーム開発の目的を振り返りましょう。

次は僕たちが最初に決めた技術群(フロントエンドやバックエンド、インフラ、開発ツール)です。

 * フロントエンド
 ** 言語: TypeScript
 ** FW: Vue.js
 ** CSS FW: Element
 * バックエンド
 ** 言語: PHP、Python
 ** FW: Laravel
 * インフラ
 ** DB: MySQL
 ** サーバー: NGINX、Docker
 * 開発ツール
 ** コミュニケーションツール: Slack
 ** 仕様書: PlantUML, Swagger, drow.io

=={sec2-ext5} 設計を考えよう
融通の利く個人開発なら設計と実装を一緒に考えることも可能です。しかし、チーム開発では手戻り作業を発生させないためにも、メンバー間の認識を合わせていくことが重要となります。そのため、考えるフェーズ(設計)と手を動かすフェーズ(実装)を分けるようにしましょう。ここでは考えるフェーズ(設計)について説明をしていきます。

==== 要求定義
要求定義とは「～したい」という内容を挙げていく作業です。
一旦実現の可否は考えず、現状の課題や不満、願望からプロダクトで実現したいことを考えていきましょう。

以下は僕たちが考えた要求定義の例です。

 * 勉強会に参加するハードルを下げたい
 * 勉強会の内容をもっと可視化したい

==== 要件定義
要件定義とは「〜が必要」という内容を挙げていく作業です。
要求定義した内容を実現可能な形にしていくために必要となります。

次は僕たちの考えた要件定義の例です。

 * 勉強会に参加するハードルを下げたい
 ** 勉強会情報を表示する必要がある
 * 勉強会の内容をもっと可視化したい
 ** ツイート数やいいね数などを集計して表示する必要がある
 ** ツイート内容を分析して表示する必要がある

==== 機能の洗い出し
要件定義から必要な機能の洗い出しをしましょう。
個人的には画面単位で考えていくことをおすすめしています。
細かい機能はUIを考える際に追加すればよいので、ここでは最低限必要な画面と機能が網羅されているかを注意して書き出しましょう。

 * TOP画面
 ** 勉強会一覧を表示する
 ** 勉強会の詳細画面に遷移できる
 ** 勉強会の登録画面に遷移できる

 * 勉強会の詳細画面
 ** 勉強会の詳細情報を表示する
 ** TOP画面に遷移する

==== UI作成
機能の洗い出しができたらUIを考えていきましょう。
細かい機能もこの段階で考えていきます。
sketchやAdobe XDのモダンなデザインツールを使用したほうが良いと考えてしまうかもしれませんが、手書きのワイヤレベルでも問題ありません。自分が使い慣れているKeynoteやdrow.ioなどを使用して書いても良いでしょう。

僕は以下のように手書きで書いています。

//image[sec2-ext5-1][UIイメージ][scale=0.7]

==== システム構成図
ちぐはぐなシステム構成にならないようにするため、システム全体の構成図を考えていきましょう。

//image[sec2-ext1-8][システム設計図][scale=1.0]


==== データ設計
画面UIを基にデータ設計を考えていきましょう。
僕はテーブルのリレーション関係を把握するために、ER図の作成から始めています。その後に、スプレットシートで具体的な項目を書き出しています。

//image[EntityRelationship][ER図][scale=0.8]

//image[sec2-ext5-4][テーブル詳細][scale=1.0]

==== API設計
API設計書を作成しましょう。
設計書の作成は次のことを目的としています。

 * 実装時に考える作業を減らす
 ** 基本は平日の夜や土日の作業となるため、あらかじめAPI設計書を作っておくことで実装時はすぐに手を動かすことができます。
 * コードレビュー後の大幅な戻りを減らす
 ** 実装後に抜本的な処理変更の指摘は気を使います。そのため、設計時にレビューをすることで、実装方針を共有でき、大幅な手戻りを減らすことができます。
 * コードレビュー者の負担を減らす
 ** 設計書がないとレビュー者は、処理内容とコードを見なければなりません。設計書を作成することで、レビュー者はコードに集中することができ、レビューの負担を減らすことができます。

設計書には次の内容を記載しています。

 * 概要
 ** APIの処理内容についてを記載する
 * シーケンス図
 ** APIの処理内容をシーケンス図に記載(PlantUMLで作成)
 * API仕様書
 ** Swaggerで作成したAPIのリンクを貼り付ける
 * ワークフロー
 ** 具体的な処理内容を記載していく


//list[?][設計書.md]{
# Post /api/v1/AnalysisRequestsの基本設計書

## 概要
解析依頼APIです。
集計開始日を元にツイートを取得して、WordCloud処理を実行します。

## シーケンス図
シーケンス図の画像を入れる

## API仕様書
http://localhost:8080/api/v1/AnalysisRequests

## ワークフロー
- バリデーションチェック
    |     項目      | 必須 | その他         |
    | ------------- | ----| -------------- |
    | start_date    | ○   | 日付形式であること |
    | analysis_word | ○   |                |
- エラーがあれば400を返す

- ツイートを取得
  - 開始日と検索ワードを元にTwitter apiを呼ぶ
  - 100件ずつ取得する

- ツイートを集計
  - いいね数、リツイート数 ユーザー数の総計を計算

- ツイートデータを保存
  - DBに取得してツイートと統計情報を保存する

- wordCloud処理を実行
  - バッチ処理を実行する

- 画像のpath情報を保存
  - DBに画像path情報を保存する

- 200を返す
//}

//image[analysisResult][シーケンス図][scale=1.0]

=={sec2-ext6} 開発の流れを決めよう
開発の進め方を検討していきましょう。
プライベートのチーム開発はリモート作業で作業時間も限られています。
開発の進め方を統一せずに、各自でタスクを進めると作業管理が難しくなります。そのため、ルール作りをしてタスク管理できるようにします。

==== スケジュールを考えよう
作業時間や作業ボリュームが分からない中でのスケジュール計画は難しいと思います。
ざっくりでもいいので全体のスケジュールを見積もりしてみましょう。
スケジュールを立てることで、後から振り返り作業ができるようになります。
タスクが早く終わった、遅くなったなどを把握するためには、目標とする期限を立てることが大事です。

また、スケジュール計画を相互レビューしてみるのも良いかもしれません。主観で考えた計画と、他のメンバーに客観的に考えてもらった計画との差異を把握し、スケジュールを見直すことで見積もりの精度も上がっていきます。

//image[sec2-ext6-2][ガントチャート][scale=1.0]

==== タスクは細分化してissueにしましょう
タスクはGitHubのissueで管理することをおすすめしています。
理由は情報を集約化することで、GitHub内でプロジェクトを完結できるからです。
別のタスクツールを導入すると、管理が大変になってしまいます。

タスクの分割は30分程度の作業でプルリクが出せる粒度にすることをおすすめしています。
30分に設定しているのは平日の夜でも負担なく作業できるようにするためです。

具体的なタスクは設計書を基に作成していきましょう。
30分でタスクを分割するため、issueの粒度はかなり細かくなると思います。

以下は僕たちが作成したタスクの例です。

 * 解析依頼画面のプロトタイプ作成(親タスク)
 ** 【処理フロー1】要素とデータと紐付ける(子タスク)
 ** 【処理フロー2】解析ボタンを押下時にイベントが実行される(子タスク)
 ** 【処理フロー3】解析ボタン押下時にパラメータを作成(子タスク)
 ** 【処理フロー4】解析ボタン押下時にリクエストする(子タスク)

GitHubではissueのリンク付けができるので、親issueに子issueを関連させることが可能です。
こうしておくことで、親issueから全体のタスクを確認でき、対応済みかどうかもissueがopenかclosedで把握できるようになります。

//image[sec2-ext6-1][親のissue画面][scale=1.0]

==== 議論はGitHubで行おう
作業を進めていくと、処理内容や実装方法を他のメンバーに確認する必要がでてくると思います。
多くの方はSlackや口頭などで確認するのではないでしょうか。
しかし、僕はGitHubのコメントを使用することをおすすめします。

Slackや口頭やり取りした際のデメリットは次のようなものがあります。

 * 過去のログを確認しづらい/確認できない
 * クローズドな環境になってしまう

Slackや口頭は手軽にやり取りできますが会話が流れやすい特徴があります。そして一度流れてしまった会話は振り返りづらくなります。
GitHubでオープンなプロジェクトにしている場合は、Slackで意思決定をするとクローズドな環境になってしまいます。
また、意思決定の過程が振り返りづらいと、属人化しやすくもなります。

そのため、少し手間は掛かりますがGitHubのコメントでやり取りするようにしましょう。

//image[sec2-ext6-3][コメントのやり取り][scale=1.0]

僕たちのプロジェクトでは意思決定のログを残す場合はGitHubを使い、それ以外をslackで確認するようにしていました。

=={sec2-ext7} 環境を整備しよう

==== プロジェクトを作成しよう
GitHubやGitLab等でプロジェクトを作成しましょう。
publicなプロジェクトの場合はGitHubで問題ないと思います。
privateなプロジェクトの場合はprivateリポジトリの作成上限がないGitLabでも良いかもしれません。
GitHubではorganizationアカウントを作成しての運用もおすすめしています。
organizationと聞くと会社などの組織が使うイメージがあるかもしれませんが、個人でも取得できます。
個人アカウントにプロジェクトを紐付けると、新たにプロジェクトを作成する際に、メンバーを管理者権限に追加する手間が発生します。
organizationアカウントを作成し、予め権限を与えておくことで自分以外の人でもプロジェクト作成が可能となります。

organizationアカウント単位でプロジェクトをまとめることができるので、管理も楽になります。

//image[sec2-ext7-1][organizationでプロジェクトをまとめられる][scale=1.0]

==== GitHubとSlackを連携する
GitHubでissueやプルリクを作成した場合、他のメンバーにも共有するために、すぐに気付ける環境を整えた方が良いです。
プロジェクトをwatchすることでメールが送られますが、Slackに通知したほうが情報の一元化もできて便利です。

設定方法は「GitHub slack 連携」等のワードで検索すると調べることができます。
是非、最初に設定しておきましょう。

//image[sec2-ext7-2][GitHubの作業をslackに通知][scale=1.0]

僕たちはissue、プルリク、コメントを作成した際に通知する設定にしていました。

==== プルリクのテンプレートを作成しよう
あなたがプルリクのレビュー者にアサインされた場合、概要にはどんな情報が欲しいでしょうか。

プルリクの概要では何を修正し、確認箇所はどこなのかを明確化することで、レビュー者の負担が減ります。そのため、プルリクのテンプレート機能を使用して、記載漏れがないようにしていきましょう。

導入方法は「Pull Request テンプレート」等のワードで検索すると調べることができます。

僕たちは下記のフォーマットを作成しました。

//list[?][pull-request.md]{
# 対応内容
#xx の内容を修正しました。

# 確認方法
〇〇を確認してください。

# クローズするissue
close #xx
close #xx

# このタスクで発生したissue
#xx
#xx

# その他
xxxxxxxxxxx
//}

実際のプルリク画面は以下となります。

//image[sec2-ext7-3][プルリク画面][scale=0.7]

=={sec2-ext8} さいごに
僕はチーム開発を上手く進めていくためには、@<b>{相手を尊重する気持ち}と@<b>{スムーズに開発が進められる仕組み作り}が重要だと考えています。
今回は仕組み作りについて説明しました。
僕が意識したことはメンバー間で認識を合わせること。そして、属人化しないようにすることです。
言葉で書くと簡単ですが、実際に行おうとすると難しいです。
意識しなければすぐにタスクは属人化してしまいますし、コミュニケーションのすれ違いが起きてしまいます。

仕組み作りにベストはないのかもしれません。
しかし、今より良いもの(ベター)を探すために、今後も様々な工夫を試していきたいと思います。

//image[myuhu7][][scale=1.0]