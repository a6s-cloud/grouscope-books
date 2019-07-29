= 環境構築

=={sec-ext1} バックエンドメインでやっている人の生き残り方
フロントエンドを殆どやったことがない人がどのようにしてWeb アプリ開発プロジェクトに関わっていくかということを短く語る予定

=={sec-ext1} Laravel の検証環境構成
各開発者の手元で検証できること。Laravel を動かす環境について

=={sec-ext1} 検証環境で使う技術要素の選定
Docker が第一候補。

=={sec-ext1} やっぱりDocker なのか
今流行りのDocker。しかし、ただ流行りに乗るのではなくやはり利点があるからDocker を選定するのである。

=={sec-ext1} Laradock を使ったLaravel 環境の構築
トキさんがLaradock を提案してくれた。

=={sec-ext1} フロントエンドとバックエンド、バッチプロジェクトの依存性管理
git submodule を使って複数プログラムの依存性を管理。

=={sec-ext1} 環境カスタマイズ
bash をつかった環境構築スクリプト作成。最初はうまく行っていたが他の人の環境でうまくビルドできない事象発生。黒歴史を語る

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

