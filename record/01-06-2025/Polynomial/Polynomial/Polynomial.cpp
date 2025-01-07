/*
    project name: Polynomial

    author: 41243144 温博鈞

    description: 
	這是一個多項式計算的程式，使用者可以輸入兩個多項式，並且輸入一個值，程式會計算多項式的加減乘法及帶入值的結果。

    class:
		- Term: 多項式的單一項
		- Polynomial: 多項式的集合

	function:
		- Polynomial operator+(const Polynomial& b): 多項式加法
		- Polynomial operator-(const Polynomial& b): 多項式減法
		- Polynomial operator*(const Polynomial& b): 多項式乘法
		- float Eval(float x): 將多項式帶入值
		- friend istream& operator>>(istream& input, Polynomial& poly): 運算子多載 >>， 輸入多項式直到讀取到-1 -1結束
		- friend ostream& operator<<(ostream& out, const Polynomial& poly): 運算子多載 <<， 輸出多項式

    latest edit date: 01-06-2025
*/
#include <iostream>
#include <string>
using namespace std;

// 自訂多樣式物件
class Term {
    friend class Polynomial;
    friend istream& operator>>(istream& is, Polynomial& poly);
    friend ostream& operator<<(ostream& os, const Polynomial& poly);
public:
    float coef; // 多項式係數
    int exp;    // x的幾次方
    Term* next; // 下一個多項式
	Term() {
		// 初始化類別物件
		coef = 0;
		exp = 0;
		next = nullptr;
	}
	Term(float c, int e) {
		// 初始化類別物件
		coef = c;
		exp = e;
		next = nullptr;
	}
	Term(const Term& t) {
		// 初始化類別物件
		coef = t.coef;
		exp = t.exp;
		next = t.next;
	}
};

class Polynomial {
private:
    Term* head;         // 多項式陣列指標
	Term* dummy;        // 多項式尾巴指標

public:
	Polynomial() {
		// 初始化類別物件
		head = nullptr;
		dummy = nullptr;
	}
    Polynomial(const Polynomial& a) {
        // 初始化類別物件
		if (a.head == nullptr) {
			head = nullptr;
			dummy = nullptr;
		}
        else {
            Term* temp = a.head->next;
            head = new Term(temp ->coef, temp->exp);
            dummy = head;
            
            while (temp != nullptr) {
				dummy = new Term(temp->coef, temp->exp);
				temp = temp->next;
            }
        }
    }
	~Polynomial() {
		// 釋放記憶體
		Term* current = head;
		while (current != nullptr) {
			Term* temp = current;
			current = current->next;
			delete temp;
		}
	}

	Polynomial operator+(const Polynomial& b) {
		/**
		 *  多項式加法
		 */
		Polynomial result;
		Term* a_current = head;
		Term* b_current = b.head;
		Term* current = nullptr;
		while (a_current != nullptr && b_current != nullptr) {
			if (a_current->exp == b_current->exp) {
				float sum = a_current->coef + b_current->coef;
				if (sum != 0) {
					Term* newTerm = new Term(sum, a_current->exp);
					if (result.head == nullptr) {
						result.head = newTerm;
						current = result.head;
					}
					else {
						current->next = newTerm;
						current = current->next;
					}
				}
				a_current = a_current->next;
				b_current = b_current->next;
			}
			else if (a_current->exp > b_current->exp) {
				Term* newTerm = new Term(a_current->coef, a_current->exp);
				if (result.head == nullptr) {
					result.head = newTerm;
					current = result.head;
				}
				else {
					current->next = newTerm;
					current = current->next;
				}
				a_current = a_current->next;
			}
			else {
				Term* newTerm = new Term(b_current->coef, b_current->exp);
				if (result.head == nullptr) {
					result.head = newTerm;
					current = result.head;
				}
				else {
					current->next = newTerm;
					current = current->next;
				}
				b_current = b_current->next;
			}
		}
		while (a_current != nullptr) {
			Term* newTerm = new Term(a_current->coef, a_current->exp);
			if (result.head == nullptr) {
				result.head = newTerm;
				current = result.head;
			}
			else {
				current->next = newTerm;
				current = current->next;
			}
			a_current = a_current->next;
		}
		while (b_current != nullptr) {
			Term* newTerm = new Term(b_current->coef, b_current->exp);
			if (result.head == nullptr) {
				result.head = newTerm;
				current = result.head;
			}
			else {
				current->next = newTerm;
				current = current->next;
			}
			b_current = b_current->next;
		}
		return result;
	}

	Polynomial operator-(const Polynomial& b) {
		/**
		 *  多項式減法
		 */
		Polynomial result;
		Term* a_current = head;
		Term* b_current = b.head;
		Term* current = nullptr;
		while (a_current != nullptr && b_current != nullptr) {
			if (a_current->exp == b_current->exp) {
				float sub = a_current->coef - b_current->coef;
				if (sub != 0) {
					Term* newTerm = new Term(sub, a_current->exp);
					if (result.head == nullptr) {
						result.head = newTerm;
						current = result.head;
					}
					else {
						current->next = newTerm;
						current = current->next;
					}
				}
				a_current = a_current->next;
				b_current = b_current->next;
			}
			else if (a_current->exp > b_current->exp) {
				Term* newTerm = new Term(a_current->coef, a_current->exp);
				if (result.head == nullptr) {
					result.head = newTerm;
					current = result.head;
				}
				else {
					current->next = newTerm;
					current = current->next;
				}
				a_current = a_current->next;
			}
			else {
				Term* newTerm = new Term(b_current->coef, b_current->exp);
				if (result.head == nullptr) {
					result.head = newTerm;
					current = result.head;
				}
				else {
					current->next = newTerm;
					current = current->next;
				}
				b_current = b_current->next;
			}
		}
		while (a_current != nullptr) {
			Term* newTerm = new Term(a_current->coef, a_current->exp);
			if (result.head == nullptr) {
				result.head = newTerm;
				current = result.head;
			}
			else {
				current->next = newTerm;
				current = current->next;
			}
			a_current = a_current->next;
		}
		while (b_current != nullptr) {
			Term* newTerm = new Term(b_current->coef, b_current->exp);
			if (result.head == nullptr) {
				result.head = newTerm;
				current = result.head;
			}
			else {
				current->next = newTerm;
				current = current->next;
			}
			b_current = b_current->next;
		}
			
		return result;
	}

	Polynomial operator*(const Polynomial& b) {
		/**
		 *  多項式乘法
		 */
		Polynomial result;
		Term* a_current = head;
		Term* b_current = b.head;
		Term* current = nullptr;

		while (a_current != nullptr) {
			while (b_current != nullptr) {
				float coef = a_current->coef * b_current->coef;
				int exp = a_current->exp + b_current->exp;
				Term* newTerm = new Term(coef, exp);
				if (result.head == nullptr) {
					result.head = newTerm;
					current = result.head;
				}
				else {
					current->next = newTerm;
					current = current->next;
				}
				b_current = b_current->next;
			}
			a_current = a_current->next;
			b_current = b.head;
		}
		return result;
	}

	float Eval(float x) {
		/**
		* 將多項式帶入值
		*/
		float result = 0;
		Term* current = head;
		while (current != nullptr) {
			result += current->coef * pow(x, current->exp);
			current = current->next;
		}
		return result;
	}
		
    friend istream& operator>>(istream& input, Polynomial& poly) {
        /**
         *  運算子多載 >>， 輸入多項式直到讀取到-1 -1結束
         */
        float coef;
        int exp;
        Term* current = nullptr;
        while (true) {
            input >> coef >> exp;
            if (coef == -1 && exp == -1) break;
            Term* newTerm = new Term(coef, exp);
            if (poly.head == nullptr) {
                poly.head = newTerm;
                current = poly.head;
            } else {
                current->next = newTerm;
                current = current->next;
            }
        }
        return input;
    }

    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        /**
         *  運算子多載 <<， 輸出多項式
         */
        Term* current = poly.head;
        bool first = true;
        while (current != nullptr) {
            if (!first && current->coef > 0)
                out << " + ";
            out << current->coef << "x^" << current->exp;
            current = current->next;
            first = false;
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


    cout << "第一個多項式為: " << p1 << endl;
    cout << "第二個多項式為: " << p2 << endl;
    cout << "第一個多項式帶入(" << p1_eval << ")值為: " << p1.Eval(p1_eval) << endl;
    cout << "第二個多項式帶入(" << p2_eval << ")值為: " << p2.Eval(p2_eval) << endl;
    cout << "加法結果為    : " << p1 + p2 << endl;
	cout << "減法結果為    : " << p1 - p2 << endl;
    cout << "乘法結果為    : " << p1 * p2 << endl;

    return 0;
}
