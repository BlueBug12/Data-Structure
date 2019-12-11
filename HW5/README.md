# Assignment 5 作業說明
## HW1
## Design
使用 _max heap_ 的資料型態來完成題目。

### Function Introduction

#### **_class max_heap_** :
* **_(constructor)_** : 初始化最大node數+1的array，第0個位置紀錄目前總共有幾個node
```c++
max_heap(int size)
```
* **_(destructor)_** : 將整個max heap的elements delete，歸還記憶體。
```c++
~max_heap()
```

* **_is_empty_** : 若max heap為空，回傳True，否則回傳False <br>
_Time complexity: O(1)_
```c++
bool is_empty()
```
* **_push_** : 將新的element n加入max heap <br>
_Time complexity: O(logN)_ (N為node個數)
```c++
void push(int n)
```
* **_pop_** : 將top的element移除(回傳)，並更新max heap <br>
_Time complexity: O(logN)_
```c++
int pop()
```
### Flow
1. 初始化一個空的max heap，並依序push input data。

2. 依據waiting fans的數量，pop出最大的ticket price。只要pop的數值大於1，便重新push pop值-1的new ticket price。

3. 使用一個array紀錄每次pop的值，待迴圈結束後，依序輸出答案。


## HW2
## Design
使用array實作 _set_ 的資料型態來完成題目。

### Function Introduction

#### **_class set_** :
* **_(constructor)_** : 初始化大小為100的int array(因題目規定最大node數為100)
```c++
set()
```
* **_(destructor)_** : 將整個set的elements delete，歸還記憶體。
```c++
~set()
```
* **_push_** : 將element的parent(or height)紀錄於array相對應的位置中。<br>
_Time complexity: O(1)_
  ```c++
  void push(const int node,const int parent)
  ```
* **_collapsingFind_** : 用recursion的方式，重複呼叫collapsingFind。直到找出root，再依呼叫的順序更新走訪過的node的parent。pointer _record_ 則是為了記錄traverse link和reset link的次數。<br>
_Time complexity: O(logN)_ (N為node個數)
  ```c++
  int collapsingFind(const int i,int*record)
  ```
* **_heightUnion_** : 依據每個tree的高度，決定合併的方式。若i的高度小於j，則令i的parent為j。反之亦然。若兩者高度一樣高時，需更新root的height <br>
_Time complexity: O(n)_
  ```c++
  void heightUnion(const int i,const int j)
  ```

### Flow
1. 初始化一個大小為100的int array當作set的紀錄容器。並依序建立set的elements。

2. 依據不同的command決定要做union或find。若是find，則須將紀錄steps的record用vector紀錄。

3. 若輸入為STOP，跳出迴圈，並將答案依序輸出。

##### Question: heightUnion vs weightUnion
* 因為被合併在另一個tree之下的所有tree nodes都會增加一個node(新的root)的height，而每個node的height決定了find的速度。因此我們應儘可能減少會被增加height的node數，所以使用weightUnion來配合collapsingFind是比較合理的。
