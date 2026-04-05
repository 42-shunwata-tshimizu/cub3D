# get_next_line

## 手順
1. ファイルの読み込み
2. 一行出力 改行文字まで出力。
5. 最後の行まで行ったら return NULL

## 考えること
現在の行の記憶 malloc?
ファイルのeof
BUFFER　SIZE

## milestone
1. fileの読み込み
2. 一行読み込み
3. 一行出力
4. 前の行の記憶
5. 最後の行まで出力しきったら、次の行でerror
6. errorハンドリング

staticなsave変数の用意
readlineでBUFFER_SIZE文fileから読み込み(改行が現れるかファイルのeofまで)saveに保存
- whileでresに改行が現れるまで読み込み。
saveからget_lineで改行まで取得 lineに保存
- mallocでlineに改行までを保存。改行までの文字数が必要。
save_next_lineに残りの値を保存 saveに保存
- １つ目の改行までlineをすすめる。ポインタを一つ進めて終端までコピー
lineを返す
