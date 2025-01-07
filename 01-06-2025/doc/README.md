# Polynomial

## 題目定義
#### 這是一個多項式計算的程式，使用者可以輸入兩個多項式，並且輸入一個值，程式會計算多項式的加減乘法及帶入值的結果。

## 解題說明
#### 程式包含兩個主要的類別：`Term` 和 `Polynomial`。`Term` 類別表示多項式的單一項，`Polynomial` 類別表示多項式的集合。程式提供多項式的加法、減法、乘法運算，以及將多項式帶入值進行計算的功能。

#### 1. 輸入資料（運算子多載）
> 讓使用者輸入2的倍數個數字，直到輸入至-1 -1結束
```c++
friend istream& operator>>(istream& input, Polynomial& poly) {}
```

#### 2. 輸出資料（運算子多載）
> 依照當前的多項式輸出
```c++
friend ostream& operator<<(ostream& out, const Polynomial& poly) {}
```

#### 3. 建構子
> 建建構子有兩個
> > 一個是當沒有資料傳入時初始化heaa和dummy為nullptr
> > 另一個是當有另一個多項式傳入時，複製其內容

```c++
Polynomial() {}
Polynomial(const Polynomial& a) {}
```

#### 4. 解構子
> 歸還使用的記憶體空間

```c++
~Polynomial() {}
```

#### 5. 運算子多載（加法）
> 若自己為a，傳入資料為`b`，若`a` `b`都不為nullptr時
> 判斷兩邊`exp`大小，若相同則相加之值放入`result->val`
> `exp`不同則將較大數字的值加入`result->val`，並將較小記憶體位置移至`next`
> 移動`result`的記憶體位置至`next`
> 判斷`a`是否為nullptr，是的話將`a`插入`result->val`
> 判斷`b`是否為nullptr，是的話將`b`插入`result->val`

```c++
Polynomial operator+(const Polynomial& b) {}
```

#### 6. 運算子多載（減法）
> 若自己為a，傳入資料為`b`，若`a` `b`都不為nullptr時
> 判斷兩邊`exp`大小，若相同則相減之值放入`result->val`
> `exp`不同則將較大數字的值加入`result->val`，並將較小記憶體位置移至`next`
> 移動`result`的記憶體位置至`next`
> 判斷`a`是否為nullptr，是的話將`a`插入`result->val`
> 判斷`b`是否為nullptr，是的話將`b`插入`result->val`

```c++
Polynomial operator-(const Polynomial& b) {}
```

#### 7. 運算子多載（乘法）
> 若自己為`a`，傳入資料為`b`， 以`a`為底，對於每個`a`元素，對每個`b`元素相乘，並將結果放回`result`

```c++
Polynomial operator*(const Polynomial& b) {}
```

## 類別與函數

### 類別
- `Term`: 多項式的單一項
- `Polynomial`: 多項式的集合

### 函數
- `Polynomial operator+(const Polynomial& b)`: 多項式加法
- `Polynomial operator-(const Polynomial& b)`: 多項式減法
- `Polynomial operator*(const Polynomial& b)`: 多項式乘法
- `float Eval(float x)`: 將多項式帶入值
- `friend istream& operator>>(istream& input, Polynomial& poly)`: 運算子多載 >>，輸入多項式直到讀取到 -1 -1 結束
- `friend ostream& operator<<(ostream& out, const Polynomial& poly)`: 運算子多載 <<，輸出多項式

## 演算分析

#### 時間複雜度
- 多項式加法：$O(n + m)$，其中 n 和 m 分別是兩個多項式的項數。
- 多項式減法：$O(n + m)$，其中 n 和 m 分別是兩個多項式的項數。
- 多項式乘法：$O(n * m)$，其中 n 和 m 分別是兩個多項式的項數。
- 帶入值計算：$O(n)$，其中 n 是多項式的項數。

#### 空間複雜度
- 多項式加法：$O(n + m)$，需要額外的空間來存儲結果多項式。
- 多項式減法：$O(n + m)$，需要額外的空間來存儲結果多項式。
- 多項式乘法：$O(n * m)$，需要額外的空間來存儲結果多項式。
- 帶入值計算：$O(1)$，不需要額外的空間。

### 申論及心得
#### 因為有做過陣列版本的，所以對於串列版本的多項式並沒有遇到太多問題，但我不確定這樣做是否效率已經是最好了，也許有更有效率的方法可以完成，by the way，輸入我是預設使用者會從大排到小輸入(根據exp的大小)，若每次都要在排序那又是另一項挑戰了

By. 41243144