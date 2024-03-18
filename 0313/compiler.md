```c
void DOWHILE() {
  int doBegin = nextLabel();
  int doEnd = nextLabel();
  //宣告兩個整數變數doBegin和doEnd，它們分別表示do while循環的開始和結束標籤。
  //使用nextLabel()函式獲取下一個可用的標籤索引，這樣我們就可以生成唯一的標籤名稱。

  emit("(L%d)\n", doBegin); 
  //通過emit()函式發出do循環的開始標籤。

  skip("do"); 
  //跳過do關鍵字。

  STMT(); 
  //調用STMT()函式，該函式用於解析並處理do循環的主體部分。

  skip("while"); 
  //跳過while關鍵字。

  skip("("); 
  //跳過左括號（）。

  int e = E(); 
  
  //調用E()函式，該函式用於解析並計算循環條件的值。

  emit("if T%d goto L%d\n", e, doBegin); //通過emit()函式生成條件檢查指令，如果條件為真，則跳轉到do循環的開始，否則跳轉到do循環的結束。

  skip(")"); 
  //跳過右括號（）。

  emit("(L%d)\n", doEnd); 
  //通過emit()函式發出do循環的結束標籤。
}
```