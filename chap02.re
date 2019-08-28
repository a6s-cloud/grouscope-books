= プロジェクトの管理

//flushright{
Toki（@tokidrill）
//}

=={sec-ext0} プロジェクトマネージメントへの情熱
皆さんはプロジェクトマネージメントに関して、どのような考えを持っていますでしょうか？
プロジェクト管理手法は非常に有用なものが多く確立されており、プロジェクトの性質によって採用される管理手法が異なってきます。
多くのメンバが所属する巨大なプロジェクトでは、全体状況の把握や明確な役割分担を意識してWBSや設計書などのドキュメントを重視するWF型の開発管理手法が採用されることが多いでしょう。
一方、スピードを意識して少数精鋭で行いたいプロジェクトではアジャイル型の開発管理手法が採用されることが多く、スタートアップやベンチャー企業が台頭している今日では、アジャイル型の開発管理手法が話題に挙がることが多い印象を受けます。

私、Tokiは2018年からプログラマとしてエンジニアキャリアをスタートさせ、本書執筆時点(2019年8月)までに5つのプライベートプロジェクトに携わってきました。
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

開発が頓挫してしまうプロジェクトのチームとしての問題で多く見られるのは下記の3点です。
* やるべきことが明確化されておらず、手の付けようがない
* 行き詰まったissueが障害になって、開発が進まない
* モチベーションが維持できない

=={sec-ext2} 解決へのTIPS

== ミーティングをする
プロジェクトにコミットする上で、何をすべきかを知ることは最も初歩的で重要なことです。失敗してしまう多くのプライベートなプロジェクトでは、プロジェクトの概要はオーナーの頭の中にあり、メンバーたちはissueが起票されるまで何をすればいいのかがわかりません。一緒にプロジェクトを進めていく仲間として、認識や価値観を共有して、主体的にプロジェクトにコミットして行くことは、健全なプロジェクトの進行に非常に有効なTIPSになります。

その上で私が一番最初にオススメしたいTIPSは定期的にミーティングを行うことです。できれば対面で、さもなければビデオ通話がいいでしょう。ミーティングを行うことで、プロジェクトオーナーの頭の中にあったイメージは簡単にメンバーに伝わることになりますし、次のスプリントに向けて足並みを揃えることができます。

定期的に対面でミーティングしよう
モチベーションが保てるし、悩みが解決されるし、次に何をすべきかが明確になるよ

ミーティングをするときはアジェンダを作ろう
ミーティングをするときはアジェンダそれぞれにゴールを定めよう
ミーティング後半はみんなで遊ぼう→ミーティング後のペアプロは問題解決・技術交換の場になるよ

== 環境はすぐに作ってしまおう

== 記録を残す

== 持ち帰りの課題を可視化する

== 困ったときのissue起票

== 後から入ってきたメンバーが気持ちよく開発するために

== 非同期コミュニケーションの障害を越える

=={sec-ext2} issue駆動プロジェクトマネジメントへの誘い