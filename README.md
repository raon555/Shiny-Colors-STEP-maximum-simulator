# Shiny-Colors-STEP-maximum-simulator
シャニマスのSTEPシナリオにおいて、特化パラメータの最大値を試算するためのシミュレータです。

~~セキュリティの観点上、exeファイルは置いていません。~~
各々でソースコードを確認したうえでC++コンパイルを行い、exeファイルを生成してください。<br>
[追記]exeファイルも置いておきますが、自環境でのコンパイル推奨です。(ネットから落としたexeファイルは不用意に実行しない方が良い)。それでも良いよって方のみ上記のexeファイルを実行してください。(DLや実行時にWindowsから怒られたりすると思いますが......)

# 注意点
- 各種アイドルの上限パネル等は未考慮です。残り団結力が分かるようになっているので、なんかいい感じに調整してください。

(例)1回目のシミュレーションで残り団結力が500
⇒団結力を16回(団結力480を消費して)SPに変換。上限パネルを開けた後2回目のシミュレーションを行う

# 使用例
![image](https://user-images.githubusercontent.com/80242944/167307940-063acd27-8164-490d-9aaa-d601db909f12.png)
![image](https://user-images.githubusercontent.com/80242944/167307944-f376a755-37ad-4a8e-98bb-d76c3a10fd0b.png)

![image](https://user-images.githubusercontent.com/80242944/167307950-5e38ceb7-4f0b-4211-b7aa-49fd75fb0377.png)
![image](https://user-images.githubusercontent.com/80242944/167307953-f4d2bc69-b8ca-467e-8cc2-4cb3be385b1c.png)


# 既知のバグ
~~以下の点はバグを確認していますが、見て分かる内容 & 入力検証が面倒くさいので対応していません。
- ~~ステータスが熟練度不足で上げられないのにも関わらず、上限の成長が可能な場合、成長を行ってしまう。~~<br>修正しました

- 入力に数値以外や有り得ない数値を入力した場合、挙動がおかしくなる。<br>
⇒入力に数値以外や負の整数、int型を越える大きな整数等を入れないでください。不自然な入力によりPC等に損害が発生した場合は自己責任でお願いします。(この程度で壊れるスペックのPCなんて今日日存在しないと思いますが......)<br>[追記]入力検証を実装し、ある程度の不自然な数値であれば対応できるようにしましたが、あり得ない数値などは基本入れないでください。何かあった場合は自己責任でお願いします。

# 備考
- クソコードなので改善等していただけるならありがたいです。
- 他言語へのリプレイスも歓迎です。
- 不具合等ありましたらご報告いただけるとありがたいです。致命的なものであれば対応いたします。
## 作者のコンパイル環境
```
Microsoft Visual Studio Community 2019
```
