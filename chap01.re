= プライベートでのチーム開発は想像以上に難しかった

//flushright{
なおと（@naoto_7713）
//}

=={sec1-ext1} はじめに
皆さんはプライベートでチーム開発をやったことはありますか。

 * やったことがある人は個人開発との違いはどう感じましたか？
 * やったことがない人はチーム開発をやってみたいと思いますか？

僕はプライベートでチーム開発することに憧れを持っていました。
 
 * チーム開発ならば、モチベーションを保てるのではないだろうか
 * チーム開発ならば、スキルアップできるのではないだろうか
 * チーム開発ならば、楽しく開発ができるのではないだろうか

それならば、プライベートでチーム開発をやってみようと思い2019年2月から始めました。

人もいない、チーム作りも分からない。0からのスタートです。
正直、何から始めていけばいいか分かりませんでした。
ただ、仕事でもチーム開発をしているので、同じ要領で進めていけば上手くいくのではと考えていました。

しかし、実際に始めると課題が沢山でてきました。
 
 * 決めなければいけないことが分からない
 * まとまった時間が取れず中々進まない
 * 設計書って作ったほうがいいの？
 * 皆のモチベーションが下がっている！？

「チーム開発 進め方」と調べても0からの進め方について情報が少なかったです。
そのため、課題がでたら解決をするトライ & エラーで進めていきました。
上手くいった仕組み、いまいちだった仕組み沢山あります。

そこで本章では、僕(なおと)がどんな思いでチーム開発を進めたのかを振り返っていきます。

プライベートで0からチーム開発するのは大変です。しかし、とても楽しかったです。
そういった雰囲気が伝われば幸いです。

===== 本章で伝えること

 * なぜ始めようと思ったのか
 * チーム開発のどこが難しかったのか
 * どうやってチーム開発を進めていったのか
 * チーム開発だからといってモチベーションは保てるわけでない
 * モチベーションを上げていくための工夫
 * プライベートでチーム開発をする楽しさ
 * 個人開発とチーム開発の違い

===== 本章で伝えないこと

 * チーム開発の進め方(2章、3章)
 * 使用したツールの紹介(4章)
 * 環境構築(5章)

=={sec1-ext2} チーム開発をやりたい！！と思ったきっかけ
プライベートでチーム開発をやってみたいと思った理由はいくつかあります。

==== 楽しそう
個人開発は自分のペースで進めることができますが、孤独を感じることがあります。
仕事ではチーム開発をしていますが、納期や人間関係、作業のマンネリ化などで楽しさを忘れてしまうことがあります。

制約が少なく、かつ信頼した人達と一緒に開発できれば楽しいだろうなと考えていました。

==== スキルアップができそう
皆さんは自分で考えた設計や実装が本当に良いものだろうか？と考えたことはありませんか。
僕は、自分のコードはアンチパターンになっているのではないのか？もっと良い書き方があるのではないか？と考えてしまうタイプです。
こういう時にレビューしてくれる人がいれば、もっとスキルアップするのではないかと考えてました。

==== チームを0から作ることを体験してみたい
仕事でもチーム開発をしていますが、いわゆる0からチームを作成した経験がありません。
僕は常駐して仕事するため、チームが既にできあがっている状態で参加することが多いです。

そして、個人事業主であることからチームリーダを経験する機会もほぼありません。
そういったこともあり、人も仕組みも全く存在しない状態から自分でチームを作ってみたい思いがありました。

==== 自分のスキルや経験が通用するかを確認したい
個人事業主になってから強く考えるようになりましたが、特定の会社や現場でのみ通用するスキル・経験はリスクと捉えるようになりました。
しかし、今の自分のスキル・経験が他で通用するのかを確認する術はなかなかありません。
そのため、確認できる場所が欲しいと感じていました。

==== モチベーションが続きそう
幾度となく挫折していった個人開発の数々。
Webアプリを作成したいと考えても、やることは沢山あります。

 * アプリ内容の設計
 * 画面設計、DB設計
 * フロント実装
 * バックエンド実装
 * インフラ周りの構築

最初は熱が高くても、時間とともに下がっていきます。
モチベーションが高いうちに、形あるものを作りたいですが、初めての技術はキャッチアップにも時間が掛かります。
キャッチアップに時間が掛かると、プロダクトの進捗がでない。
そしてモチベーションが下がるというサイクルに陥り、気づいたら燃え上がっていた熱もどこかに消えてしまいます。
良くも悪くも、個人開発は途中で諦めても他の人に迷惑が掛かりません。
そこに甘えて僕はすぐに投げ出し、GitHubには作りかけてプロジェクトが沢山あります。

個人開発ではやり切ることができなかったので、チーム開発で他の人も巻き込み、諦めづらい空気を作りたいと考えてました。

=={sec1-ext3} どうやって人を集めよう？
それでは、チーム開発をやってみよう！！と考えてもすぐにできないのがチーム開発です。
当たり前ですが2人以上でなければチームにはなりません。人を集める必要がありますが、ここが最初の難関でした。

そもそも僕は内向的なので簡単に声を掛けるなんと恐れ多くてできなかったです。
断られたらどうしよう。何も決まっていないのに誘ったら迷惑になるのでは。と考えてしまい行動に移せませんでした。

しかし、行動しなければ何も始まらないのも事実です。
漫然とした不安を消すために、具体的なアプローチ方法のメリット、デメリットを考えることにしました。

==== 身近な人に声を掛ける
自分の知り合いに声を掛けるので安心感はあります。
しかし、知り合いだからこそ断られたらショックを受ける。
上手く開発が進まずに中途半端なってしまい、気まずくなる可能性もあると考えました。

==== Twitterで呼びかけ
Twitterで「プライベートでチーム開発をやってみたい人募集します！！」とツイートする方法です。
これは1番手軽に声を掛けられそうですが、自分の知らない人から返信がくる可能性もあります。
知らない人といきなり始めるのは不安があります。

==== 勉強会で声を掛ける
僕は月に1〜2回の頻度で勉強会に参加していたので、そこで声を掛ける方法もあります。
勉強会に参加している人はスキルアップに対して意識も高いので、一緒に開発することでモチベーションも上がりそうです。
しかし、初対面でいきなり「チーム開発しませんか？」と声を掛けると怪しいので、コミュニケーション力が求められます。
@<br>{}

いくつかアプローチを考えた結果、最初は勉強会のLTで呼びかけました。
LTの最後に「プライベートで一緒に開発をやりたい人いませんか？」と問いかけました。
勉強会参加者というフィルターを掛け、さらに僕のLTに興味を持った人にアプローチをしました。
興味を持ってくれた人が声を掛けてくれるはずなので、僕自身は精神的に楽でした。

その結果、Tokiさんが声を掛けてくれました。
直接話したこともありませんでしたが、「楽しそうだからやってみたい！チャンスだと思った」と言ってくれてのを覚えています。(嬉しかったです。ありがとう、Tokiさん！！)

1人から2人になると気持ちも前向きになっていきます。
その勢いのままTwitterで知り合ったつとむさんにも声を掛けました。
つとむさんはGitHubやQiitaに積極的にアウトプットをし、一緒に開発ができたら楽しいだろうと勝手に思っていました。
結果的につとむさんも参加していただきました。(ありがとう、つとむさん)

この経験から次のことを気づきました。

 * チャンスを掴むためには、飛び込む勇気が必要
 * 目に見えたアウトプット行うことは信頼度が上がる
 * チーム開発に興味がある人は多い

そして3人でのチーム開発の一歩を踏み出していきました。

=={sec1-ext4} モチベーションが高いうちに、早めに進めよう
何事もモチベーションとスピードが大事なので、すぐに対面で集まり進め方を決めていくことにしました。

==== 目的を決める
僕が発起者として、皆に「一緒にチーム開発しましょう！！」と声を掛けました。その時は何のためにチーム開発をするのか、何を目指すのかを伝えていません。
僕とTokiさんとつとむさんで期待していることはバラバラな状態です。
プライベードの時間を費やすからには、皆が成長できる環境を作りたいと考えていました。
そのためには、皆がチーム開発に対して何を期待しているかを共有しました。

話し合いでは次のことが挙がってきました。

 * 仕事ではチーム開発できていないから経験したい
 * モダンな技術をつかってみたい
 * 転職活動などでアピールできる成果物がほしい
 * ０から開発してリリースしたい
 * 会社での経験が外でも通用するかを試してみたい
 * プロダクトを成功させて利益を得たい

複数の目的を混在すると軸がブレる可能性もあったので、できる限りシンプルな目的にしました。
結果、僕たちのチーム開発の目的は「@<b>{チーム開発を通して、技術のスキルアップを目指す}」にしました。

==== 作るものを決めよ
もともと僕が作成していたWordCloud@<fn>{word_cloud}をWebアプリ化したい構想がありました。
プロダクトを作るモチベーションより、スキル向上に重きがあったので異論もなく決まりました。
//footnote[word_cloud][文章中で出現頻度が高い単語を複数選び出し、その頻度に応じた大きさで図示する手法。 ウェブページやブログなどに頻出する単語を自動的に並べることなどを指す。 文字の大きさだけでなく、色、字体、向きに変化をつけることで、文章の内容をひと目で印象づけることができる。]

少しだけアプリ説明をすると勉強会のツイートを集計・分析して、可視化することで勉強会の雰囲気や特徴を掴めるようにするものです。
勉強会の特徴を把握することで、初めて参加する時の不安などを減らし、勉強会への参加ハードルを下げること目的としたものです。現状だとプロトタイプまでは作成できた状態ですが、UIは一新して作り直そうと考えています。

==== 設計を決める
最初に決めたことはUI部分です。画面から考えていくのが１番イメージしやすいと思ったからです。
しかし、デザインスキルが低い僕にはUIを書くことに苦戦しました。また、アプリの機能イメージも皆に伝えきれませんでした。
そのため、画面のワイヤーフレームとDBの設計は僕が作成していきました。

しかし機能一覧も考えずに付け焼き刃で作成しているので、設計にも時間が掛かります。
作業分担もできていなかったので、自分がボトルネックなっていることは感じていました。
このままでは全員のモチベーションが下がってしまうので、設計はほどほどにして実装と一緒に仕様・設計を皆に考えてもらう方針に変更しました。

コードを書いて手を動かせばモチベーションも上がるはずだとこの時は思っていました。

=={sec1-ext5} モチベーションを維持することは難しい
手を動かしてコードを書き始めればモチベーションも上がっていくだろう思っていました。
最初は勢いよく進んでいきましたが、2週間も経つと、自分含め皆のモチベーションも下がっているのを感じてきました。
個人開発ならば、僕はここで諦めていたでしょう。

しかし、今回はチーム開発です。
発起者の自分が皆に声を掛けています。
責任感もあり、簡単には投げ出すことはできません。
もっと上手くやるにはどうすればいいのかを考える必要があったので、モチベーションが下がってしまう要因は考えてみました。

==== 金銭的なインセンティブがないから？
金銭的なインセンティブがないからモチベーションが下がるのではないか？
しかし科学的に「金銭的報酬は、人の内発的動機づけを低下させる」と結果がでています。
 
 * 内発的動機づけとは活動そのものが目的であること
 * 外発的動機づけとは報酬などの外部からの刺激による動機づけ

今回のプライベート開発では「チーム開発を通して、スキルアップを目指す」を目的としており、内発動機づけです。
そもそも、金銭的な報酬を求めるなら、チーム開発に参加もしないはずなので、インセンティブが原因ではないと考えました。

==== 時間的な制約がある
メンバー全員仕事をしています。そのため、チーム開発の作業を行えるのは仕事が終わった後の平日夜か、土日になっていきます。
僕の生活リズムだと平日は最大1時間、土日だと4時間を割り当てられました。
しかし、自分の好きな勉強や仕事で必要な勉強も考慮に入れるともっと少なくなります。
もちろん、毎日作業ができるわけではありません。
チーム開発に触れる時間が少ないほど、熱も冷めていきます。

==== タスクがざっくりし過ぎたため、何をしていいか分からない
いざ、作業を始めるぞ！！と思っても、何をすればいいのかが分かりませんでした。実際に作成していたissueが次の画像となります。

//image[sec1-ext5-2][作成したissue][scale=0.9]

これを見てすぐに実装を進めれるでしょうか？「自由にいい感じにしてください」は曖昧すぎて、何をすればいいのかが分かりません。仕事が終わった平日の夜に考える作業は疲れもあり気乗りしません。その結果、何もしないことが多くなりました。

短い時間で作業を進めていくためにはできるだけ考える作業(設計)と手を動かす作業(実装)を分ける必要があると感じました。

==== スケジュールを立てていなかった
スケジュールを立てなかった理由としては次となります。

 * 決まった時間を確保できないので工数を立てづらい
 * タスクの内容が把握できないの見積もりを立てられない
 * スケジュールがあるとプレッシャーになるのではないのか

期限があると少なからずプレッシャーを感じます。そういった中だと楽しく進めることができなくなるのでは考えていましたが、期限がないことで気も緩んでしまいます。
例えば、設計作業を2週間で終わらせると考えてみましょう。2週間目で終わっているためには1週間目ではここまで完了していないといけない、3日目の進捗でこのタスクを終わらせなければならない。と逆算して計画をしていきます。
しかし、スケジュールがないと逆算しての計画ができません。目標なき作業は意義が見出しづらくなってしまいモチベーションも下がってしまいます。

==== タスクが大きすぎる
１つのタスクが大きすぎると完了するまでに時間が掛かり、達成感を感じづらくなってました。
タスクがざっくりしていたので、実装途中に機能をどんどん追加してしまい途中で進捗をアウトプットできなくなってしまいました。
進捗をアウトプットできないので前に進んでいる感がありません。slackでも次のような投稿をしていました。

//image[sec1-ext5-1][slackでのやり取り][scale=1.0]

==== 属人化してしまう
メンバー全員、得意分野やスキルセットが異なるため、タスクによって作業スピードが違います。
例えば僕は環境構築周りに関しては知見がないので、キャッチアップから始める必要があります。
反対につとむさんは環境構築周りの作業が得意なので、タスクをすぐに完了させることができます。
チーム開発だと自分の作業がクリティカルパスとなり、全体の作業が止まってしまうことがあります。自分だと時間が掛かるので得意な人にやってもらうという空気が生まれてきます。つまり属人化です。

僕らはスキル向上を目的にしていたはずなのに、いつしか自分のできることだけをやるようになっていました。

=={sec1-ext6} モチベーションを上げるための工夫
モチベーションが下がってしまう要因は分かってきました。

 * タスクが大きすぎて何をすればいいのか分からない
 * 短い時間でタスクが終わらないので手が付けにくい
 * スケジュールがないので、前に進んでいる感覚がない

これらのことを踏まえて、モチベーションを上げ、楽しく進める方法を考える必要があります。

メンバーの士気を高めるアプローチは色々あると思います。
例えば強いリーダシップを持って、リーダが皆を引っ張っていくスタイルです。
しかし、僕にはこのスタイルは合わないです。周りの人を鼓舞する言葉やビジョンを掲げられません。そして対面でなく、リモートの作業が主であるためリーダが引っ張っていく形では上手くいかないのではと考えました。

そこで、今回は仕組みづくりでモチベーションを上げていくアプローチを目指すことにしました。
人に依存しない仕組みは、他の場所でも利用できる可能性が高まります。

==== README駆動：見た目を豪華にして気分向上
まずは見た目から入ろうと考えました。
GitHubを使ったチーム開発といえば、やはり最初はREADMEになると思います。
このREADMEを豪華にして、テンションを上げていく作成です。
アイコンや理念、構成図、アウトプット記事などのアピールできるものを集約して載せるようにしました。アウトプットを一箇所に集めることで「やっている感」がでて、もっとREADMEを豪華にした欲求掻き立てる作戦です。

//image[sec1-ext6-1][README1][scale=0.9]

//image[sec1-ext6-2][README2][scale=0.9]

//image[sec1-ext6-3][README3][scale=0.9]

==== タスクは細かくする
チーム開発を続けていくコツは、少ない時間でもいいので毎日触れて作業をすることだと考えています。
少ない時間で作業するにはタスクは細かく、明確化にする必要があります。

そのため、issueは細かい単位で分けることにしました。30分で完了できる作業を１つのissueにするよう心がけていました。
実際にタスクを小さくしてからは、以前の大きなタスクより手が付けやすい状態になりました。

==== 前に進んでいることを感じよう
僕はGitHubに草を生やすことでモチベーションは上がります。
僕たちも作業をした際に、コントリビュートを増やせるような工夫しました。
コントリビュートはissueやプルリクの作成で生やすことができます。
そのため、細かくissueを作成して、細かい単位でプルリクを出すフローにしていきました。

次は僕のGitHub contributionsです。草が生えている箇所がチーム開発の作業をしている箇所です。平日もコンスタント作業できています。

//image[sec1-ext6-4][GitHub contributions][scale=0.8]

==== Twitterに発信していこう
自分がやったことはどんどん発信していこうと考えました。
手軽なアウトプットはTwitterです。開発用でアカウントは取得していたので、そこで発信することにしました。
ただ、手動での運用は負担が大きいです。続かないことは目に見えているので
次のようなツールを作成しました。

 * GitHubでプルリクをマージした際にツイートする
 * slackで特定のリアクションをつけたらツイートする

//image[sec1-ext6-5][マージした際のツイート][scale=0.8]
//image[sec1-ext6-6][slackでリアクションした際のツイート][scale=0.8]

実際に運用した際の感想が次となります。

 * ツイ廃なのですぐにマージされたことが分かるようになりました。
 * 継続的ツイートをすることで、自分含め他の人の活動がはっきり見える化するので、良い刺激にもなります。
 * Githubなどを見ている開発者モードのときじゃなくても、Twitterで通知を見られる。それぞれ、開発に時間を使えるタイミングや量が違い、ほぼ完全にリモートで作業しているチームでのコミュニケーションロスによる摩擦を減らせる。

作成したツールについてQiitaに投稿していますので、興味がある方は確認してみてください。

 * GitHubのWebhookでプルリクエストをマージした際にツイートできるようしてみた
 ** https://qiita.com/turmericN/items/f6267a75be45c51eaed7
 * Slackでリアクションをした際にツイートできるようにしてみた
 ** https://qiita.com/turmericN/items/23c86d70aae3dd8bfc77

=={sec-ext7} プライベートのチーム開発は楽しい
開発スピートはゆっくりながらも2019年2月から始めたチーム開発を半年続けられました。さらに皆で同人誌を執筆することもできました。

自分のプライベートの時間を費やすので楽しくなければ続けられません。そして楽しかったので続けてこれました。

==== 皆で決めていく流れが楽しい
個人開発では自分一人で考え、決定していきます。
しかし、チーム開発は皆で決めていくことになります。
それぞれの意見を出し合いディスカッションして、ベストやベターを探していく流れは一人では味わうことができない楽しさがありました。

==== 仕組みを０から構築できて楽しい
今回は人も仕組みも0からのスタートでした。
そのような中でGitHubの運用フローやタスクの洗い出しなどの仕組みを試行錯誤しながら作っていきました。
0から徐々に1になり、2になり、10になるどんどん良くなっていく過程を経験できて楽しかったです。

==== 自分の知らない技術を知ることが楽しい
１人で開発している時は、もっと良い書き方があるのではと悩むことがありますが、レビューしてもらうことで考えの幅が広がりました。
また、自分の知らない分野だとこの技術でそもそも何ができるのかが分かりません。
今回、bashによる環境の自動作成やDockerによる管理などの環境構築周りをつとむさんに作成してもらいました。この辺の内容を僕はまったく分かっていませんでしたが、実践ベースで勉強できて楽しかったです。

==== 課題が見つかって解決する過程が楽しい
どんな作業でも進めていくうちに課題は見つかっていきます。
例えば今回だと環境構築をもっと楽にした。タスクをもっと見える化したい。気軽にアウトプットできるようにしたい。などがでてきました。
出てきた課題を皆で一つ一つ解決して、良い方向に進めていけて楽しかったです。

=={sec-ext8} 個人開発とチーム開発の違い
最後にチーム開発をやってみて、僕が感じた個人開発の違いを挙げていきます。

==== モチベーション
個人開発もチーム開発もモチベーションについてはあまり大差なかったです。
最初は熱が高く、時間が経つにつれて下がってきます。

チーム開発は途中で投げ出すと周りの人に迷惑を掛けてしまうので、諦めづらくなりました。

しかし、周りの人が進めている中で自分だけ作業できない状態が続くと戻りづらくなる可能性もあります。

==== 開発の自由度
自分１人で決定できる個人開発のほうが開発の自由度は高いです。
チーム開発だと自分がやりたい開発と他の人がやりたい開発が一致しないこともあります。チームで進めていくため、話し合いで決めていく流れになりますが、100%納得いく形になるとは限りません。

==== 開発のスピード
開発のスピードはケースバイケースですが、個人開発のほうが早くなると感じてます。
意思決定のスピードとタスクの分割をせずに進めることができるからです。
チーム開発だと運用ルールや設計の割り振りを考える必要があります。また、他の人の作業完了待ちでボトルネックが発生する可能性があるので開発スピードが下がります。
しかし、開発スピードは下がりますがレビューを挟むことで品質は上がると思います。

チーム開発は走り出しに時間は掛かりますが、メンバー同士のシナジーを生む可能性が高いです。

==== スキル向上
チーム開発のほうがスキル向上が早いと感じてます。
他の人のコードを読む、そして自分のコードをレビューしてもらえます。コードレビューの過程が入ることで、読みやすいコードを書くことを心掛けるようになってきます。
１人で実装するときより、意識してコードを書くようになるため技術向上できる気がしています。

しかし、チーム開発だとタスクの割り振りを工夫しなければ属人化やコードレビューの形骸化は起きやすいです。

==== 意思決定
個人開発では自分一人で決めるので意思決定について特に意識することはありません。
しかし、チーム開発は皆の意見をまとめて決定する必要があります。
意見をまとめて決定することは責任も伴いますが、そこは勇気を持って決めていきましょう。１番良くないのは何も決まらず進まないことです。

=={sec-ext9} 最後に
プライベートでのチーム開発は想像以上に難しかったです。トキさん、つとむさんのような優秀なエンジニアが集まってもうまく開発は進んでいきません。チーム開発は人が単に集まっただけでは機能しません。人、仕組み、ルールなどを決めていく必要があります。それをTry & Errorで進めていき、チームとしてまとめていくのがプライベート開発の醍醐味だと感じています。

今回、僕の気持ちや考えを伝えました。そして、皆さんは「自分ならもっと上手くできる」、「私ならこんな工夫する」など考えがあると思います。
是非、想像だけでは終わらせずに、実際にプライベートでのチーム開発を実感してみてください。