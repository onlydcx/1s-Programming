## 出力環境

デフォルトだとファイルと同階層にバイナリが作られるので専用ディレクトリを作る

```bash
$ mkdir /home/user/binary
```

## Code Runner 設定

- gccのコマンド順を入れ替え
- tempCodeRunnerFile.c を削除
- binary/ に移動
- 実行文を削除

```json:settings.json
"code-runner.executorMap": {
      "c": "cd $dir && sudo gcc -o $fileNameWithoutExt $fileName -lm -ldrawlib && rm tempCodeRunnerFile.c -f && mv $fileNameWithoutExt /home/user/binary -f && cd /home/user/binary && clear && ./$fileNameWithoutExt && cd /home/user"
}
```