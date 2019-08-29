= プロジェクトの管理

//flushright{
Toki（@tokidrill）
//}

=={sec-ext0} プロジェクトマネージメントへの情熱
皆さんはプロジェクトマネージメントに関して、どのような考えを持っていますでしょうか？
プロジェクト管理手法は非常に有用なものが多く確立されており、プロジェクトの性質によって採用される管理手法が異なってきます。
多くのメンバが所属する巨大なプロジェクトでは、全体状況の把握や明確な役割分担を意識してWBSや設計書などのドキュメントを重視するWF型の開発管理手法が採用されることが多いでしょう。
一方、スピードを意識して少数精鋭で行いたいプロジェクトではアジャイル型の開発管理手法が採用されることが多く、スタートアップやベンチャー企業が台頭している今日では、アジャイル型の開発管理手法が話題に挙がることが多い印象を受けます。

私、Tokiは2018年からプログラマとしてエンジニアキャリアをスタートさせ、本書執筆時点(2019年8月)までに5つのプライベートプロジェクトに携わってきました。
マネタイズを目的としたもの、技術の獲得を目的としたもの、できあがったサービスに価値を期待したもの… それぞれのプロジェクトには目的やストーリーがあり、どのプロジェクトも面白く、
最高のメンバが集まって結成されたものだと私は信じていますが、残念ながら頓挫しリリースを待たずに凍結されてしまったプロジェクトもいくつか存在します。
また、私と同じ若手のエンジニアたちと交流を深める中で、プライベートなプロジェクトを持っているがなかなか上手く進めることができずに悩んでいるという声は非常に多く聞いてきました。

はじめに述べたとおりプロジェクトマネージメントの手法は多くのフレームワークが発明されており、それぞれの手法に則って開発を行っていくのが一般的でしょう。
しかし、プライベートなチーム開発プロジェクトでのマネージメントに限っていえば、業務での開発プロジェクトに比べてほとんど研究されていないというのが現状です。
私や私の仲間たちの経験上、無理にマネージメントフレームワークに則ってプロジェクトを進めたり、逆に管理を全く意識せずに開発を進めてしまったりするとチームの疲弊(ゆくゆくの崩壊・凍結)を招きます。
チームやプロジェクトに適した管理手法を試行錯誤し、"いいとこ取り" で管理手法をオーダーメイドしていくことは非常に重要なことであるといえるでしょう。

本章では、プライベートなチーム開発プロジェクトでよくあるマネージメントの上での悩みをどのようにして乗り越えようか、私たちのチームが試行錯誤して辿り着いた方法を、私の考えを交えて紹介します。
ほんの一部分でも、プライベートでチーム開発をしたい皆さんの参考になれば幸いです。

=={sec-ext1} プライベートなプロジェクトを行う上での悩み

まずはプライベートなチームプロジェクトを行う上での悩みや問題点を整理していきましょう。
システム開発のプロジェクトの問題点といえば、初めに思いつくのは技術的な障壁や納期です。
しかし、私はこれらはプライベートなプロジェクトではあまり関係がないものだと考えています。

前者は、技術・経験をつけることが目的である場合が多いため、問題になることは少なく、逆にこのような障壁に出会ったときこそチームを組んだときの醍醐味で、
チームメンバと協力して解決する、多くの時間をかけてしっかりと調べて解決するなど人的・時間的なリソースを多く使うといった、業務ではなかなかできないような方法を取ることができます。
こうして解決した問題は自分自身の自信や経験に繋がりますし、チームとしての成果になるので逆にモチベーションが上がる要因ともいえます。

後者に関しては、そもそもプライベートプロジェクトで厳密な納期を定めているケースは少ないでしょう。
また、私はマネタイズを目的としたプロジェクトにも参加した経験がありますし、サービスを立ち上げて起業を考えている仲間に話を聞いたこともありますが、
納期や期日に関して悩んでいるということはあまり聞いたことがありません。

それではプライベートなチーム開発プロジェクトが頓挫してしまう本質的な原因とはどういったことが挙げられるでしょうか。
私は、開発が頓挫してしまうプロジェクトがチームとして抱えている問題点として主なものは下記のようなものであると考えています。


チームを組んで開発するとき、あるいは顧客を相手に開発するときに(業務・プライベートに関わらず)よく衝突するのが何から手をつけていいのかわからないという問題です。
業務では要件定義や外部設計で仕様を策定し、イメージを擦り込んで行くという工程があることが多いでしょう。
一方、プライベートなプロジェクトでは計画や設計よりも開発が先行している場合や、後入りのメンバに説明がなくコミットのハードルが高くなっている場合が多いように感じています。

開発が始まってから起こりやすいのは現状やっているタスクの解決方法がわからなくなってしまう場合です。
これはどちらかといえば技術的な障壁に近い問題で、チーム間でのコミュニケーションが活発に行われていない場合に発生する問題であると分析しています。
プライベートプロジェクトでは、それぞれ所属の違うメンバが集まっていたり挑戦的な技術を取り入れたりしている場合が多いです。
そういった場合に既存のソースコードなどが自分の所属や理解とは違う思想で記述されているために、「いつも利用しているフレームワークなのに何が書いてあるかわからない」などといった形で発生する場合が多いです。
また、これは開発にコミットする初期の段階で起こる場合が非常に多く、「環境構築ができない」、「独自に定義されたコマンドの利用方法がわからない」などといった形でも発生します。
これらは、メンバ個人が技術力を高めることで解決することも十分に可能ですが、それらのキャッチアップに終止してしまいプロジェクトへのコミットにたどり着かないなどといったケースも見られます。
この問題も、コミュニケーションをしっかり行うことによって十分に解決できる問題です。

本書を手にとっていただいている皆さんの多くは、アルバイト・サラリーマンといった被雇用者にせよ、経営者のような雇用者(もしくは事業主)にせよ、何かしらの形で所属があると思います。
また、家庭を持っている場合、趣味や個人的な活動に打ち込んでいる場合も少なくないでしょう。
番外編として、病気や怪我などで長期的に離脱することも考えられます。
率直にいえば、私はこういった場合はその期間中にコミットしてもらうことは諦めた方がいいケースが多いと考えています。
(実際に私も働きすぎで胃を壊してしまい、一ヶ月ほど何もできなかった時期があります(笑))
この場合は、どうしたらプロジェクトに復帰しやすいかということを考えるのが最も前向きで建設的な施策になるでしょう。

アルバイトや勤務先での業務に対してプライベートプロジェクトでは(マネタイズを目的とした場合があるにせよ)、すぐには利益は発生しづらいことが多いです。
目先の金銭的な利益が得られない場合はやり甲斐や成長にモチベーションが集中しますが、前に述べたような理由でモチベーションが低下することはよくあることです。
また、他のメンバのコミットが上手くいっていない場合、他のメンバに引っ張られて一番のコントリビュータがコミットしなくなってしまうということもよくあることで、
これがチーム、あるいはプロジェクトが崩壊してしまうといった現象の本質であると考えられます。

以上に述べたような問題点を整理すると、私の考えるプライベートでのチーム開発プロジェクトが抱えがちな問題は下記の4点に整理できます。

 1. やるべきことが明確化されておらず、手の付けようがない
 2. 行き詰まったissueが障害になって、開発が進まない
 3. 生活や仕事面で想定外に忙しくなってしまい、コミットできなくなってしまう
 4. モチベーションが維持できない

次節では、これらの問題に対してどのようなアプローチでプロジェクトを進めていけば、悩みを減らすことができるか、私たちがたどり着いたTIPS(コツ)を紹介します。

=={sec-ext2} 解決へのTIPS

前節では、プライベートでのチーム開発で私や私の仲間たちが出会った問題を分析して整理しました。
本節では、それらの問題にどのように対応していけばよいかを整理していきます。

=== ミーティングをする
プロジェクトにコミットする上で、何をすべきかを知ることは最も初歩的で重要なことです。
失敗してしまう多くのプライベートなプロジェクトでは、プロジェクトの概要はオーナーの頭の中にあり、メンバーたちはissueが起票されるまで何をすればいいのかがわかりません。
一緒にプロジェクトを進めていく仲間として、認識や価値観を共有して、主体的にプロジェクトにコミットして行くことは、健全なプロジェクトの進行に非常に有効なTIPSになります。

その上で私が一番最初にオススメしたいTIPSは定期的にミーティングを行うことです。
できれば対面で、さもなければビデオ通話がいいでしょう。
対面でのミーティングを行う際はディスプレイやホワイトボードがレンタルできるコワーキングスペースがオススメです。
私たちは上野、池袋にあるいいオフィス@<fn>{chenv_01}を利用しています。
ミーティングを行うことでプロジェクトオーナーの頭の中にあったイメージは簡単にメンバーに伝わることになりますし、次のスプリントに向けて足並みを揃えることができます。

定期的に対面でミーティングを行うことでモチベーションを保つことができますし、もしモチベーションが下がってしまっていた場合にテンションを上げるためのきっかけにもなります。
また、重要なのは次のスプリントに向けての作戦会議と、悩みを共有することです。

前者は、やるべきことが明確化されていないという問題と、忙しくてコミットできないという問題への強力なアプローチになります。
一定期間以上コミットできない状態が続いてしまうと、今のプロジェクトの状況がわからなくなり、プロジェクトに復帰しづらくなります。
また、これは一定期間コミットできなかったメンバだけでなく、開発でなくて次エピックの設計に着手していたメンバや、自分のissueに集中していたメンバにもいえることです。
次のスプリントに向けての作戦会議では、まずは前のスプリントでどのようなissueがクリアされたかをメンバ全員で確認します。
この際、起票されたissueを閲覧しながら担当者が機能や工夫した点、苦労した点、利用した学習リソースなどを話すと、より有意義なものになります。
また、説明の際はデモサイトなどを用意し、口頭や文書での説明でなく実際に動きを見せて説明を行うことを基本に考えてください。
可能であれば、各々の開発環境で成果をビルドしてデモするのが良いです。
バグや仕様とのズレが発覚することもありますし、改善点や意外な発見がある可能性もあります。
前スプリントでの成果を確認した後は、次スプリントにクリアするべきissueを確認し、振り分けます。
この際に、挑戦したいissueがある場合はそのメンバに立候補してもらうのがいいでしょうし、リーダーが推薦するのもよいでしょう。
推薦する場合は、本人にその意思があるかを確認するのを忘れないでください。
個人プロジェクトでは些細なことがモチベーションの低下に繋がるため、これを怠るのは危険です。
また、挑戦したいissueはあるが、自信がない、キャッチアップしなければならないという場合は、そのissueをクリアするだけの知識を持っているメンバに支援を依頼しましょう。
後述しますが、ミーティング後半は自由時間を設けることをオススメしています。その時間を使ってハンズオンしてもらったり、ペアプログラミングでissueに着手したりするとより効率的にキャッチアップできます。

後者は、行き詰まってしまったissueのハンドリングという点で強力なアプローチになります。
issueを他のメンバに振り分け直すような対応をしてもいいですし、前述したように自由時間を使ってキャッチアップを行ってもよいです。

ミーティングを行うときは、必ずアジェンダ(つまり議題)を事前に作るようにしてください。
アジェンダを作らない場合、ただ集まっておしゃべりをするだけの会になったり、間延びして充実感のないミーティングを生んでしまいます。

//image[chap02/001_meetingIssue][GitHubでミーティング用のissueを起票し、アジェンダを作成した例]

また、アジェンダにはそれぞれにどうしたらその議題がクリアされるかというゴールを決め、目的を明確にしておきます。
目的が上手く定まっていない、共有されていない場合は、議題が間延びしてしまう可能性が高いため、リーダーはそれぞれに目的を定めておき、議題の最初に目的を話すといいでしょう。
目的が具体的な成果物として定められる場合、作成したアジェンダに記載しておくのもよい方法です。
更に、アジェンダ一つ一つに時間をかけすぎないために、それぞれに制限時間を設けておくと成果がでやすくなります。
アイデアを募集するような議題の場合は、ホワイトボードやノート、リアルタイムで文書を共有できるFigmaのようなサービスを用いてブレインストーミングすると効率がよいです。

作成しておいたアジェンダをクリアしたら、ミーティングの後半に入ります。
アジェンダをクリアしたら解散する、各々その場で開発に着手する、などといった選択肢もありますが、せっかく対面で集まっている好機を逃す手はありません。
ミーティングの後半では、プロジェクトのためにキャッチアップしたい技術をハンズオンしたり、複数人で調査を行ったり、担当者にとって困難もしくは億劫なissueをペアプログラミングやモブプログラミングで解決したりします。
私が特にオススメしたいのは、複数人での調査とモブプログラミング@<fn>{chenv_02}です。
これを行うことによって、自分の知らなかったサービスを知ることができたり、キャッチアップの速度と正確さが上がることが見込めます。
所属や文化が違うために生まれてしまうハードルを、上手くプロジェクトに還元してベネフィットとして利用してください。

プライベートなチーム開発プロジェクトにとって、ミーティングはミサ、アジェンダは聖典です。
ミーティングをしっかり活用することができれば、問題はほぼ解決されたといっても過言でないでしょう。

=== 環境はすぐに作ってしまおう

開発への参入障壁として、誰もがまず最初に思い浮かべるのは開発環境の構築です。
プロジェクトに参加したはいいものの、コミットできないというメンバの中には、環境構築ができないまたは億劫だという人が多くいます。
技術力に自信があるメンバにとっても、普段扱っている言語やフレームワーク、構成でない場合はコストに感じるものです。
これを持ち帰って各々で対応しようとするとissueの取り掛かりの時期に差が出てしまい、ボトルネックになる可能性が高くなりますし、
環境にバラつきが出て開発途中で問題が発生する可能性もあります。
こういったトラブルは、プロジェクトへのモチベーションの低下に繋がるため、なんとしても除外しなければなりません。

そこで私がオススメするのは、開発開始初期に環境構築のためにミーティングを設定する、もしくは既に設定されているミーティングの中で環境構築に時間を取るいうことです。
こうすることによって、全員が環境構築を完了することを担保することができますし、よりよい開発環境を構築するためにアイデアを出し合うことができるため、環境の洗練や技術力の向上に繋がります。

また、環境構築を行った際は必ずメモを取るようにしてください。
取ったメモはアプリケーションやモジュールのREADMEなどに記載し、リポジトリにpushしておきます。
こうすることで、後から入ってきたメンバの参入障壁もかなり下げることができます。
また、ここでいう「後から入ってきたメンバ」とは、マシンを新品に乗り換えたあなた自身のことかもしれません。
誰でも簡単に開発に着手する環境を構築できることは非常に重要なことです。

多くの場合は、プロジェクトを初めたときのメンバが構築したものを利用する形になると思いますが、後から入ってきたメンバにとってはGitHubのリポジトリを見せられただけでは環境構築は難しい場合が多いです。
そこで、私たちのチームで行っている取り組みが環境構築用のスクリプトの整備や、DockerHubを利用したオートメイドビルドです。
詳しい説明はつとむさんに譲ります@<fn>{chenv_03}が、この取り組みは私たちのプロジェクトにとって非常にパワフルな働きをしており、
実際に新規メンバが参加した際に2行のコマンドと15分で環境構築が終了したという実績があります。
こういった取り組みによってメンバはアプリケーションの実装に集中することができ、開発中に新しいミドルウェアなどを導入した際にもビルド用のイメージやスクリプトを持っていれば、
プルリクエストで動作確認を依頼する際にも構築のハードルを取り除くことができるため、リズムを乱すことがありません。

//image[chap02/002_build][神降臨の図]

=== 記録を残す

=== 持ち帰りの課題を可視化する

=== 困ったときのissue起票

=== 後から入ってきたメンバーが気持ちよく開発するために

=== 非同期コミュニケーションの障害を越える

=={sec-ext2} issue駆動プロジェクトマネジメントへの誘い

//footnote[chenv_01][6.3.1、6.3.2で詳しく紹介しています。]
//footnote[chenv_02][私たちのチームでは、毎回つとむさんにドライバをお願いしてモブプログラミングを行っています。]
//footnote[chenv_03][詳しくは 5 環境構築 で解説されています。]
