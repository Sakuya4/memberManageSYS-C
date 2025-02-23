# memberManageSYS-C

版號：`1.0`
說明：簡單基本系統架構建立，建立B+ tree 

### 使用C語言實現成員管理系統
這是一個用於管理成員信息的簡單命令行應用程式，使用 B+ tree來提高效率。該系統支持
`insert()`
`delete()`
`update()`
`search()`
等等功能。


## 使用方法
#### 1. 編譯程式碼：
`gcc -o member_management member_management.c`
#### 2. Run it：
`./member_management`
#### 3. Call help：
使用`help`查看幫助並使用。

## 資料結構使用
使用B+ tree, 有思考緩衝區 or 其他高等樹之應用，基於系統在未來可能數據量可能非常龐大之Case,
最後選擇了B+ tree, 可以使系統在操作上的Time Complexity皆為O(logn), 以及降低I/O的次數。

