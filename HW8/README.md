# Assignment 8 作業說明
## HW1
## Single source shortest paths
使用adjaceny matrix來代表此有像圖。並用一個三層for迴圈來展開所有edge相鄰的可能。若不相鄰，則設為無限大；反之每當得出一更小的權重時，則更新該相鄰edge之權重。並記錄更新路徑上的節點。帶迴圈結束，我們就可以得出最短路徑及其權重。


## HW2
## Design
使用 _recursion_ 來找出All pair shortest paths。function _shortest_path_ 每次呼叫時，都會找出所有可能往下延伸的edge。若可以得到更小的weight總和，則繼續往下延伸，並在結束此次呼叫時記錄沿途的節點。若無更小的weight總和，則回到上次的function call，繼續尋找。直到所有edge都尋訪過一次，便已找出最短路徑。總共要找N*(N-1)，且每次皆要尋訪所有edge。因此時間複雜度為 _O(N^2*E)_
