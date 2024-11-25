/*
    project name: Polynomial

    author: 41243144 温博鈞

    description: 自訂多項式加法 乘法及 operator overloading >> 及 <<

    class:
        - Term: 自訂多項式物件
        - Polynomial: 包含多項式儲存 加法 減法 及輸入輸出overloading

    function:
        - void addTerm(): 將元素加入

    global variable:
        - MAX_DEAPH: 指定最大遞迴深度
        - recurse_deaph: 紀錄目前遞迴深度
        - max_n: print出在不同m值下，n的最大可計算值

    latest edit date: 10-17-2024
*/
#include <iostream>
#include <string>
using namespace std;

// 自訂多樣式物件
class Term {
    friend class Polynomial;
    friend istream& operator>>(istream& is, Polynomial& poly);
    friend ostream& operator<<(ostream& os, const Polynomial& poly);

private:
    float coef; // 多項式係數
    int exp;    // x的幾次方
};

class Polynomial {
private:
    Term* termArray;    // 多項式陣列指標
    int capacity;       // 當前陣列大小
    int terms;          // 當前使用到陣列長度

public:
    Polynomial() {
        // 初始化類別物件
        termArray = new Term[1];
        termArray[0].exp = 0;
        termArray[0].coef = 0;
        capacity = 1;
        terms = 0;
    }

    void addTerm(float coef, int exp) {
        /**
         *  將資料儲存，若當前資料大於陣列長度時呼叫 addArray()擴充陣列之後再儲存
         *
         *  args:
         *      - coef: 多項式係數
         *      - exp:  x的幾次方
         */

        if (terms + 1 >= capacity) {
            addArray();
        }

        int left = 0, right = terms - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (termArray[mid].exp == exp) {
                termArray[mid].coef += coef;
                return;
            }
            else if (termArray[mid].exp < exp) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        for (int i = terms; i > left; --i) {
            termArray[i] = termArray[i - 1];
        }
        termArray[left].coef = coef;
        termArray[left].exp = exp;
        terms++;
    }

    void addArray() {
        /**
         * 擴建陣列，每次大小*2，並將原有資料轉移至新的陣列
         */

        Term* newArray = new Term[capacity * 2];

        copy(termArray, termArray + terms, newArray);
        capacity *= 2;
        delete[] termArray;
        termArray = newArray;
    }

    Polynomial Add(Polynomial poly) {
        /**
         *  將自己的多項式輸入的多項式做加法之後回傳
         *  args:
         *      - poly: 多項式被加數
         *
         *  retrun:
         *      Pllynomial: 加完後結果
         */

        Polynomial result;
        int thisCount = 0, polyCount = 0;
        result.capacity = this->capacity + poly.capacity;
        result.addArray();

        while (thisCount < this->terms && polyCount < poly.terms) {
            if (this->termArray[thisCount].exp == poly.termArray[polyCount].exp) {
                result.addTerm(this->termArray[thisCount].coef + poly.termArray[polyCount].coef, this->termArray[thisCount].exp);
                thisCount++;
                polyCount++;
            }
            else if (this->termArray[thisCount].exp > poly.termArray[polyCount].exp) {
                result.addTerm(this->termArray[thisCount].coef, this->termArray[thisCount].exp);
                thisCount++;
            }
            else {
                result.addTerm(poly.termArray[polyCount].coef, poly.termArray[polyCount].exp);
                polyCount++;
            }
        }

        while (thisCount < this->terms) {
            result.addTerm(this->termArray[thisCount].coef, this->termArray[thisCount].exp);
            thisCount++;
        }
        while (polyCount < poly.terms) {
            result.addTerm(poly.termArray[polyCount].coef, poly.termArray[polyCount].exp);
            polyCount++;
        }

        return result;
    }

    Polynomial Mult(Polynomial poly) {
        /**
         *  將自己的多項式輸入的多項式做乘法之後回傳
         *  args:
         *      - poly: 多項式被乘數
         *
         *  retrun:
         *      Pllynomial: 乘完後結果
         */

        Polynomial result;
        for (int i = 0; i < this->terms; i++) {
            for (int j = 0; j < poly.terms; j++) {
                float newCoef = this->termArray[i].coef * poly.termArray[j].coef;
                int newExp = this->termArray[i].exp + poly.termArray[j].exp;
                result.addTerm(newCoef, newExp);
            }
        }
        return result;
    }

    float Eval(float f) {
        /**
         *  帶入一個數，回傳多項式的解
         *
         *  args:
         *      -f: 代入值
         *  return:
         *      float: 多項式代入f後的解
         */
        float result = 0;
        for (int i = 0; i < terms; i++) {
            result += termArray[i].coef * pow(f, termArray[i].exp);
        }
        return result;
    }
    friend istream& operator>>(istream& input, Polynomial& poly) {
        /*
        */
        float coef;
        int exp;
        while (true) {
            input >> coef >> exp;
            if (coef == -1 && exp == -1) break; // 使用 -1 -1 作為結束條件
            poly.addTerm(coef, exp);
        }
        return input;
    }

    // 重載輸出運算子 <<，用來顯示多項式
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        for (int i = 0; i < poly.terms; i++) {
            if (i > 0 && poly.termArray[i].coef > 0)
                out << " + ";
            out << poly.termArray[i].coef << "x^" << poly.termArray[i].exp;
        }
        return out;
    }
};

int main() {
    Polynomial p1, p2;

    float p1_eval, p2_eval;

    cout << "輸入第一個多項式(格式：係數 指數，例如 3 2 表示 3x^2），輸入 -1 -1 結束輸入：" << endl;
    cin >> p1;
    cout << "輸入第二個多項式(格式：係數 指數，例如 3 2 表示 3x^2），輸入 -1 -1 結束輸入：" << endl;
    cin >> p2;

    cout << "輸入第一個多項式帶入值(float): ";
    cin >> p1_eval;
    cout << "輸入第二個多項式帶入值(float): ";
    cin >> p2_eval;
    cout << endl << "--------------------------------------------------------" << endl;

    Polynomial p3 = p1.Add(p2);
    Polynomial p4 = p1.Mult(p2);


    cout << "第一個多項式為: " << p1 << endl;
    cout << "第二個多項式為: " << p2 << endl;
    cout << "第一個多項式帶入(" << p1_eval << ")值為: " << p1.Eval(p1_eval) << endl;
    cout << "第二個多項式帶入(" << p2_eval << ")值為: " << p2.Eval(p2_eval) << endl;
    cout << "加法結果為    : " << p3 << endl;
    cout << "乘法結果為    : " << p4 << endl;



    return 0;
}
