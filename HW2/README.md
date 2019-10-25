# HW2 作業說明
## 設計理念
因為題目本身就隱含著first-in-first-out的資料傳遞方式，所以使用circular queue的資料型態來實作。

### Function Introduction
* Shuffle: 將牌打亂(level越高，牌打越亂)
```c++
void shuffle(char* cards,const int size,int level=20)
```

* Print: 顯示circular queue裡的內容
```c++
void print(const char* cards,int head,int tail,int size)
```

### 流程
1. 初始化一個A~K的字元陣列來實作circular queue
  * 因為10非單一字元，故以`'X'`代表
  * 為了使用上的方便，多空出一格位置
  * head 指向第一個位置，tail指向最後一個(空)位置

2. 洗牌

3. 若head指向的元素為目標牌號，pop-out，反之將其push-back再pop-out，並print出circular queue的內容

4. 重複步驟3.，直到circular queue為空
