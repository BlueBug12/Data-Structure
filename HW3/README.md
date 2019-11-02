# Assignment 3 作業說明
## 設計理念
使用dynamic linked queue的資料型態來達成比一般的queue更有效率的資料處理。

### Function Introduction
* **_find_group_** : 回傳customer name所對應的group，若無則回傳-1。
  ```c++
  int find_group(const int* groups,char x)
  ```

#### **_class LinkedQueue_** :
* **_(constructor)_** : 為了操作上的方便，會先初始化一個head node，並將front跟rear pointer都指向它。
* **_(destructor)_** : 將整個queue的element一個個delete，歸還記憶體。
* **_is_empty_** : 若queue為空回(front==rear)傳True，否則回傳False。<br>
_Time complexity: O(1)_
  ```c++
  bool is_empty()
  ```
* **_push_** : 由於資料的傳入會有優先性的問題，這裡的push並非單純將新的資料推入，而是要從頭 `traverse`，找出是否有可以"插隊"的對象(同一個group_number)，再將資料安插在同一組人的前面。若無同組的，則以正常的方式從rear端push。<br>
_Time complexity: O(n)_ (n為customer的數量)
  ```c++
  void push(char x,int group_number)
  ```
* **_pop_** : 將資料(customer的名字)輸出。需注意的是，因為前述初始化的設定，pop的資料永遠是front所指向的後一個元素。若queue已為空，則丟出一個`"The queue is empty."`例外。<br>
_Time complexity: O(1)_
  ```c++
  char pop()
  ```
* **_traverse_** : 找出符合`group_number`的前一個元素，回傳其指標。<br>
_Time complexity: O(n)_
  ```c++
  listPointer traverse(int group_number)
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
