= コラム

=={sec6-ext1} 俺の最強の開発環境
=== なおとの開発環境

 * 端末: MacBook Pro (13-inch, 2018) メモリ 16 GB 英字キー
 * エディター: VSCode
 * DBクライアント: Sequel Pro(MySql)
 * APIツール: Postman

僕はMacBookのみで開発してますね。本当は外部ディスプレイを使いたいのですが、机を置くスペースがありません。。ベッドの上で作業すること多いので腰を痛めます。たまにカフェに行くこともありますが、もっぱら家です。

Mac内では複数デスクトップ作成することができますが、僕は1つのデスクトップに全アプリを立ち上げてます。「command + tab」でアプリ切り替えて作業です。

//image[naoto1][デスクトップ][scale=0.8]

=== つとむの開発環境
 * 端末(出先): Think Pad T460s
 * 端末(自宅): Core i7-3960X (購入当時はフラッグシップ) なCPU で組み立てたマシン。マルチモニタ環境でキーボードはHHKB
 * OS: Arch Linux
 * エディター: vim
 * DB クライアント: mysql コマンド or MySQL Workbench
 * API ツール: soapUI (Postman もAUR で利用できる用になったみたいなのでそちらを利用するのも考え中)

またそれ以外の環境としては、家では広い机と座り心地の良いニトリで買った椅子があります。またターミナルは自分好みにカスタマイズしてショートカットや画面分割で作業効率を上げられるようにしています。あとはブルーライトカットのメガネで疲れ眼に気を使うようにしています。

=== トキの開発環境

=={sec-ext} 続けるために工夫している点

=== なおとの工夫
まずは自分の使える時間を把握することです。
僕の平日の平均的なスケジュールです。

 * 07:45          起床
 * 07:45 〜 08:15 仕度
 * 08:15 〜 09:15 通勤
 * 09:30 〜 18:30 仕事
 * 18:30 〜 19:30 帰宅
 * 19:30 〜 22:00 ご飯や家事
 * 22:00 〜 24:00 自由時間
 * 24:00          寝る

こうみると通勤や自由時間合わせると3時間以上もあります。
しかし、朝の通勤と帰りの通勤では同じ1時間ですが疲労度が違います。
例えば朝に本を集中的に読めても、帰りだと頭に入らないことが多いです。
自分のリズムを把握して適切な作業を割り当てましょう。

次は自分の使える時間を把握することです。
朝の通勤では頭を使う作業
なので夜の自由時間のときに以下に作業できるようにするためのコツが必要です。

皆さんが何か作業する時に考えることはなんでしょうか？
僕は「今日、何をしよう？」です。この時に作業が明確していないと、作業を考える必要があります。
しかし作業を洗い出すのは頭を使います。そしてモチベーションも下がってしまいます。
そして一つのタスクが大きすぎると中途半端で終わってしまいます。

そのため僕はまずタスクを一日単位で終わるぐらいに分割してissueに追加するようにしています。
これをすることで最初に始める際に無駄に考える必要がなくなり、作業できるようになります。
そして、同時に一回で終わる作業でコミットするようにすることでgithubの草が生えてモチベーションも上がっていきます。

また実際にPCを操作できる時は手を動かす作業をするようにしています。手を動かす途中で分からない所や基礎が抜けている箇所がでてくると思います。こういうときはメモやサイトの記事を残しておき、手を動かせないときの通勤中に見るようにしています。
とにかく手を動かすことを意識しています。

もしかしたら、何をやればいいんだろ？？という人もいるかもしれません。
何をすればいいのか分からないは僕もよく分かります。
まずは手を動かせるように真似からでいいと思います。僕自身も業務で使用していることの復習やチュートリアルを実施しています。
実際に業務で役に立つのは嬉しいものです。

=== つとむの工夫
まず私の内部的な要素として、何を勉強しようか何に手を付けようかと考えた時に「それが実務に直結するか」ということはあまり考えないようにしています。幸いコンピュータやプログラミング等に関しては元々興味があり、自分が自発的に取り組む部分もそっち方面のことが多いので今の業務に直接関係のない勉強でも巡りに巡って実務に役立つことがあったりもしますし、違う観点から物を見ることもできるので既に得ていた技術の理解がより深まったりしています。例えば今回執筆した記事の中でもDocker のイメージとコンテナの違いについてはおそらく、あまり他の人達が書かれている説明とは異なるものになっているかもしれませんこのような書き方になった理由は、Docker のイメージを「スナップショット」と呼んでいる例があったためです@<fn>{docker_image_as_a_snapshot}。当時Docker に触り始めた時と同じくらいの時に私は並行してKVM やLVM(Logical Volume Manager)でスナップショットを使った状態のリストア方法についても色々試しており、それがDocker のイメージとコンテナの見方を大きく変えるきっかけになりました。

やはり自分の中では自分の内側から出てくる興味に反して期限や利益を優先して勉強を続けていくことのほうが辛く感じます。結局は自分の中から出てくるワクワクする気持ちを大切にしてあげることが、私にとっての勉強やプログラミングを続ける秘訣ではないでしょうか。
//footnote[docker_image_as_a_snapshot][例えば https://stackoverflow.com/a/22379305]

一方で外部的な要素ももちろんあります。それは良い椅子と良い机、良いモニター(複数)、お気に入りのキーボード(HHKB)をこしらえて開発や勉強をすることです。これらを使ったところですぐに効果は実感できないかもしれませんが長時間の作業になってくると大きな差が出てきます。私は快適なPC 環境を求めてPC の組み立てを始めてから15年近く経ちますが、結局快適なPC 環境とはマシンそのものの性能もありますが、それ以上に自分の身に直接触れる椅子やキーボード、机、モニタといったものに左右されることが多いと悟りの境地を開き始めています(笑)。

あとはカッコいいターミナル環境を用意することです。作業中の気分をあげて優越感に浸らせてくれ、プログラミングや執筆の楽しみを向上させてくれます。ターミナルを普段使わない人はデスクトップの背景でもWeb ブラウザのテーマのカスタマイズでも同じような効果は得られると思います。ただ注意点として、それらをカスタマイズすることに夢中になりすぎて時間を取られ、本来の作業が全く進まないという本末転倒な事態にならないようにしてください。

そしてあとひとつ...適度なお酒は重要です。
@<br>{}

最後に、この度はチームに参加させていただき書籍を執筆するという人生のひとつの夢を叶えてくださったなおとさん、Toki さん、のなとさん、みのきちさん。この紙面をお借りして感謝の意を表させてください。ありがとうございました<(_ _)>！

=== トキの工夫

=={sec-ext} 集まった場所
=== 【上野】いいオフィス
御徒町にある、株式会社LIG により運営されているコワーキングスペースです。
都営大江戸線、つくばエクスプレス線「新御徒町駅」から徒歩1分、もしくはJR 御徒町駅から徒歩10分程の場所に位置しており、アパートや商店街などが並ぶ通りの中にポツリとおしゃれなオープンテラスと木材を基調とした内装を有した落ち着いた空間が広がっています。

サービスとしてコーヒーや紅茶、お茶が飲み放題です。またWi-Fi とホワイトボード、電源、モニターが完備されています。
土日に利用しましたが、余裕のある座席数と広い空間のため、のびのびと使用することができました。
私達が利用した料金プランとしては2時間利用と1DAY 利用(10:00 〜 18:00)があり自分の時間にあわせてフレキシブルに利用できるようになっているので、仕事帰りや学校帰り、休日出かける前に少し寄っていくといった使い方もできます。
普段東京の騒がしい環境の中で過ごし、たまには静かに落ち着いて勉強やプログラミングをしたいという人にとってのオアシスとなる場所です。

 * いいオフィス 上野
 * https://ii-office.jp/ueno-by-lig/

=== 【池袋】いいオフィス
御徒町にあるいいオフィスと同じ株式会社LIG により運営されているコワーキングスペースです。御徒町にあるいいオフィスを利用した時に、1日無料券をいただいたので行ってきました。

JR 池袋駅から徒歩5分程の場所にあり、仕事帰りにも利用できる好立地なコワーキングスペースです。
料金プランとしては、こちらも2時間利用と1DAY 利用があり、飲み物やWi-Fi についても完備されています。
池袋駅周辺といえば東京の中でも特に人が多くて賑やかな場所ですが部屋に入った途端、静かで落ち着ける空間に包まれます。
池袋駅周辺は飲み屋街も多くあるので、いいオフィスを利用して勉強した後には自分へのご褒美として居酒屋へ...という使い方もおすすめです。

 * いいオフィス 池袋
 * https://ii-office.jp/ikebukuro-by-lig/

=== 【上野】上野酒場 情熱ホルモン
チームが発足して数回目の御徒町でのミーティングの後、私達は居酒屋で飲み会をすることになりました。その時に利用させていただいたのが上野酒場情熱ホルモンさんです。
話は変わりますが、当時我々チーム内でWDD という言葉が流行っていました。これはWhisky Driven Development(ウィスキー駆動開発) という手法を意味する、DDD やTDD といった言葉に対抗して作られた完全に我々チーム内でのみ通用する用語です(笑)。
アルコールを取り入れて開発を促進しようと考えていたのです。そのアルコールのお供として上野酒場情熱ホルモンさんにて美味しいホルモンをいただきました。ちなみにグルメ通なToki さんがお薦めする部位はコプチャンで、メニューに迷ったらまずはそれを頼んでおくのが得策でしょう。

JR 御徒町駅から徒歩3分程度、上野駅からでも数分程度で行けるところに位置しており休日のみならず平日の仕事帰りにも利用できる会話と料理とお酒がすすむザ・下町な雰囲気の場所となっています。
香ばしいホルモンを焼いた煙と滴る脂、ビールとハイボールが何杯も進む体験をし、チームの結束力をより一層深めることができました。

ところでアルコールを取り入れることでプロダクトの開発が促進されたかというと...引き続き縦断的な調査が必要で、まだ検証結果は出せていません。
//footnote[wdd][ここでいうウィスキー(Whisky)とはアルコール飲料全般を意味します]

 * 上野酒場 情熱ホルモン
 * https://ueno-jonetsuhorumon.com/

=== 【池袋】木々屋(はやしや)
焼きとんとホルモン、お酒が楽しめるお店で、私達は池袋西口駅前の四号店さんをご利用させていただきました。
この日はWDD の2 回目で、池袋のいいオフィスを利用した帰りに美味しい料理とお酒が飲める場所が無いかを探していた所、Toki さんの紹介により訪れたお店です。
池袋に多くの支店ができる程の人気なお店で、身が大振りで程よく塩味が効いた香ばしい焼きとんがビールや焼酎等のお酒と非常に相性が良く、ついつい飲みすぎてしまいます。
座席はテーブル席とカウンター席があり、複数人でも一人でも気兼ねなく利用することができます。
店舗はJR 池袋駅を囲むように複数構えており東口にもお店があり、普段池袋に勤務している人や頻繁に池袋に足を運ぶ人は帰り道の途中に木々屋さんが無いか調べてみると結構あると思うので、帰りに一人飲みや気が置けない友人を軽く誘って飲みに行くのも良いかも知れません。

 * 木々屋(はやしや)
 * https://hayashiya-inc.co.jp/

=== 【池袋】Bar TIPTOP
池袋西口を出て雑踏の中をかき分けて、西池袋の動脈とも言える劇場通りを数分歩いた閑静なビルの一角にその老舗なバーはあります。Bar TIPTOP さんです。木々屋(はやしや)さんで飲んだ後に二軒目の場所として利用させていただきました。

お店に入り地下へ向かう階段を下りると、目の前に広がるカウンターとその後ろに並べられたお酒の瓶の数々、ほんのりと淡い赤い光がちょっと悪い大人になった気持ちにさせてくれるとても雰囲気の良いお店です。
飲み物のメニューは豊富でお酒に詳しい人でも楽しめるようになっており、それに加えて薄暗いオシャレな店内の景観が相まって、ゆっくりと時間が流れる落ち着いた空間を提供してくれます。
そういった趣のある空間であるため親密な友人や重要な取引先、大切な人を連れたデートシーンに利用し、濃い話でお互いの懐を深める貴重な体験ができるでしょう。より深い友情や関係性を築く時に、ぜひとも利用してみてはいかがでしょうか。

 * Bar TIPTOP
 * https://tiptop.owst.jp/

