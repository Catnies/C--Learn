#include <iostream>
#include <vector>
using namespace std;


// 类模板. 
template <class T> 
class Vector3 {
    public:
        T list[3];
        // 类内部定义函数
        Vector3(T v1, T v2, T v3) {
            list[0] = v1;
            list[1] = v2;
            list[2] = v3;
        };
        // 类外部定义函数
        T getMax();
};

// 类外部定义函数
template <typename T>
T Vector3<T>::getMax() {
    return list[0];
}




// 特化类模板
// 特化不能继承模板的成员, 例如此类中实际上没有 getMax() 函数.
template <> 
class Vector3<char> {
    public:
        char list[3];
        // 类内部定义函数
        Vector3(char v1, char v2, char v3) {
            list[0] = v1;
            list[1] = v2;
            list[2] = v3;
        };
        const char* asString() {
            return list;
        }
};



// 模板的类型也可以是模板
// 其中 template <typename T> typename Container 代表的是一个模板类型的类, 例如 vector , 是一个模板类型的类.
template <template <typename T> typename Container, typename T> 
class VectorWapper
{
    public:
        Container<T> values;
        VectorWapper(Container<T> &o): values(o) { };
        void print() {
            for (auto &&v : values) {
                cout << v << endl;
            }
        };
};





int main() {
    Vector3<int> vec1(1, 2, 3);

    vector<int> v1 = {2, 4, 6, 8, 10};
    VectorWapper<vector, int> exp(v1);
    exp.print();

    return 0;
}