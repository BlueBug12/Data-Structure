# HW1 作業說明
## ackerman.cpp:

* 使用遞迴方式輸出*Ackerman function*
* 依據*Ackerman function*的定義完成程式
> **if(m = 0), A(m,n) = n+1**</br>
> **if(n = 0), A(m,n) = A(m-1,1)**</br>
> **otherwise, A(m,n) = A(m-1,A(m,n-1))**
* 當輸入為 EOF 時，結束程式


## powerset.cpp:
* 使用遞迴方式輸出powerset，做法如下:

  * 初始化一個空集合S(0)={ϕ} , s1,s2,s3...為輸入的set名稱

  * S(1) = {{s1 + S(0)} ∪ S(0)} = {{s1},{ϕ}}

  * S(2) = {{s2 + S(1)} ∪ S(1)} = {{s2,s1},{s2},{s1},{ϕ}}

  * S(3) = {{s3 + S(2)} ∪ S(2)} = {{s3,s2,s1},{s3,s2},{s3,s1},{s3},{s2,s1},{s2},{s1},{ϕ}}

  * 以此原則，我們可以歸納出隱含遞迴關係的通式:  
> **S(n) = {sn + S(n-1)} ∪ S(n-1)  for n>=1 , S(0)={ϕ}**

* 因此我們只需要將輸入的set名稱依次放入遞迴函式的參數中，就能堆疊出答案
* 當輸入為 EOF 時，結束程式
