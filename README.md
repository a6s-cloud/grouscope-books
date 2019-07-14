# README

これは Re:VIEW Starter で生成された、Re:VIEW 用プロジェクトです。

* 対象とする Re:VIEW バージョン： 2.4 (これ以外のバージョンだと動作未確認)
* 問い合わせ： Twitter でハッシュタグ「#reviewstarter」つきでツイートしてください。


## `review init` との違い

* (TODO)

ビルドの方法
```
### Docker を使う場合
$ docker pull kauplan/review2.5    # 3GB 以上ダウンロードするので注意
$ unzip mybook.zip
$ cd mybook/
$ docker run --rm -v $PWD:/work kauplan/review2.5 /bin/bash -c "cd /work; rake pdf"
$ ls mybook.pdf

### Docker を使わない場合 (Ruby と Re:VIEW と LaTeX が必要)
$ gem install review --version 2.5  # 最初に1回だけ行う（2回目からは不要）
$ review version                    # Re:VIEWのバージョンを確認
2.5.0                               # （3系は未サポートなので注意!!）
$ unzip mybook.zip
$ cd mybook/
$ rake pdf
$ ls mybook.pdf
```