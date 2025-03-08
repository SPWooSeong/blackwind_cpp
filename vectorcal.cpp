#include <iostream>
using namespace std;

class Vector3D {
private:
    double x, y, z;

public:
    Vector3D(double xVal = 0.0, double yVal = 0.0, double zVal = 0.0) : x(xVal), y(yVal), z(zVal) {}
    Vector3D operator+(const Vector3D& v){
        double xSum = x + v.x;
        double ySum = y + v.y;
        double zSum = z + v.z;
        return Vector3D(xSum, ySum, zSum);
    }
    Vector3D operator-(const Vector3D& v){
        double xSub = x - v.x;
        double ySub = y - v.y;
        double zSub = z - v.z;
        return Vector3D(xSub, ySub, zSub);
    }
    Vector3D operator*(const Vector3D& v){
        double xMul = x * v.x;
        double yMul = y * v.y;
        double zMul = z * v.z;
        return Vector3D(xMul, yMul, zMul);
    }
    friend Vector3D operator*(Vector3D v, double scalar); //스칼라곱
    friend Vector3D operator*(Vector3D v, int scalar); //스칼라곱
    double dotProduct(const Vector3D& v) {
        return x*v.x + y*v.y + z*v.z;
    }
    void printVector() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

//-----------IMPLEMENT HERE-------------
Vector3D operator*(Vector3D v, double scalar){
    return Vector3D(v.x*scalar, v.y*scalar, v.z*scalar);
};
Vector3D operator*(Vector3D v, int scalar){
    return Vector3D(v.x*scalar, v.y*scalar, v.z*scalar);
};
//-----------IMPLEMENT HERE-------------

int main() {
    Vector3D vec1(1.0, 2.0, 3.0);
    Vector3D vec2(4.0, 5.0, 6.0);
    Vector3D sum = vec1 + vec2;
    cout << "더하기 결과: ";
    sum.printVector();
    Vector3D diff = vec1 - vec2;
    cout << "빼기 결과: ";
    diff.printVector();
    // 벡터곱
    Vector3D crossProduct = vec1 * vec2;
    cout << "벡터곱 결과: ";
    crossProduct.printVector();
    // 내적
    double dot = vec1.dotProduct(vec2);
    cout << "내적 결과: " << dot << endl;
    // 스칼라곱
    double scalar1 = 2.5;
    Vector3D scaledVec1 = vec1 * scalar1;
    cout << "스칼라곱 결과: ";
    scaledVec1.printVector();
    // 스칼라곱
    int scalar2 = 7;
    Vector3D scaledVec2 = vec1 * scalar2;
    cout << "스칼라곱 결과: ";
    scaledVec2.printVector();

    return 0;
}