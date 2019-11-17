# Assignment 4 作業說明
## HW1
## 設計理念
使用 _linked list_ 的資料型態來完成題目。

### Function Introduction
* **_Shuffle_** : 將牌打亂(level越高，牌打越亂)
```c++
void shuffle(char* cards,const int size,int level=20)
```

* **_creat_list_** 產生一個洗牌後的linked list，由傳進去的的`header`當作list的頭，並回傳此list的尾。
```c++
card* creat_list(card* header)
```
* **_Print_** : 顯示 _linked list_ 裡的內容
```c++
void print(const char* cards,int head,int tail,int size)
```

### Flow
1. 初始化一個打亂的A~K的linked list
  * 因為10非單一字元，故以`'X'`代表
  * 為了使用上的方便，多空出一格位置
  * header 指向第一個位置，tail指向最後一個位置

2. 若header指向的元素為目標牌號，pop-out，反之將其push-back再pop-out。其實在操作上已經隱含著 _dynamic linked queue_ 的概念了

4. 輸出list裡頭的元素，重複步驟3.，直到list只剩下header即代表抽牌結束


### Bonus
跟用array實作的 _circular queue_ 來比較，其實在效率上並無太大差別。因為資料只會從頭尾進出，無論是 **push** 還是 **pop** ，兩者的 _Time complexity_ 皆為 **_O(1)_**。而題目所需的記憶體大小非常少且是固定的，因此 _linked list_ 動態配置的優勢就無法很明顯地被展現出來。差別只在於不需要像 _circular queue_ 作"circular"的轉換，使用上更直覺一些。

## HW2
## 設計理念
使用array實作queue的資料型態來完成題目。

### Function Introduction
* **_find_group_** : 回傳customer name所對應的group，若無則回傳-1。
  ```c++
  int find_group(const int* groups,char x)
  ```

#### **_class ArrayQueue_** :
* **_(constructor)_** : 初始化front和rear皆為0，並new出27個單位的記憶體
* **_(destructor)_** : 將整個queue的elements delete，歸還記憶體。
* **_is_empty_** : 若queue為空回(front==rear)傳True，否則回傳False。<br>
_Time complexity: O(1)_
  ```c++
  bool is_empty()
  ```
* **_push_** : 由於資料的傳入會有優先性的問題，這裡的push並非單純將新的資料推入，而是要從頭 `traverse`，找出是否有可以"插隊"的對象(同一個group_number)，將資料安插在同一組人的前面。若無同組的，則以正常的方式從rear端push，最後將rear加1。`traverse`加上`移動"被插隊的customers"`的步驟每次都會需要完全走訪過一次整個queue(front和rear所包含的範圍)。<br>
_Time complexity: O(n)_ (n為customer的數量)
  ```c++
  void push(char x,int group_number)
  ```
* **_pop_** : 將front所指向的資料(customer的名字)輸出。並將front加1。若queue已為空，則丟出一個`"The queue is empty."`例外。<br>
_Time complexity: O(1)_
  ```c++
  char pop()
  ```
* **_traverse_** : 找出符合`group_number`的元素，回傳其index。<br>
_Time complexity: O(n)_
  ```c++
  int traverse(int group_number)
  ```
* **_print_** : 顯示整個queue的內容。<br>
_Time complexity: O(n)_
  ```c++
  void print()
  ```

### Flow
1. 將groups的資訊以array的形式儲存。因題目規定所有customer名稱皆為大寫英文字母，不重複且不會同時出現在兩組groups裡。所以只需要一個大小為26的int array，將每個人所屬的group編號填入。若無則編號為0。

2. 依據 `ENQUEUE`或`DEQUEUE`的操作指令，分別用`push`或`pop`來完成。並用一個`string`來儲存每個被pop出來的字元(customer name)。

3. 當使用者輸入`EOF`後，跳出迴圈，將上一個步驟所儲存的字元一個個輸出顯示，程式執行結束。

### Bonus
與上題類似，_array queue_ 跟 _dynamic linked queue_ 來比較，其實在效率上並無太大差別。無論是 **pop** 的 _Time complexity_ 皆為 **_O(1)_**。_array queue_ 在 **push** 的動作會因為多了一個移動elements的步驟比 _dynamic linked queue_ 還慢一些，但因為都需要 _traverse_ ，所以 _Time complexity_ 皆為 **_O(n)_** 。而因為題目所需的記憶體大小非常少且是固定的(最多26個customers)， _dynamic linked queue_ 動態配置的優勢就無法很明顯地被展現出來。
