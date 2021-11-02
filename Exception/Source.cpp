#include <iostream> 
using namespace std;

class MathException
{
protected:
    char operationName[20]; //имя операции 
    long firstArg; //значение левого операнда операции 
    long secondArg; //значение правого операнда операции 
public:
    virtual void message() = 0;
};

class OverflowException : public MathException {
public:
    OverflowException(const char* name, long firstValue, long secondValue) {
        strcpy_s(operationName, name);
        firstArg = firstValue;
        secondArg = secondValue;
    };
    void message() {
        cout << "At " << operationName << " OverflowException " << endl;
    }
};

class UnderflowException : public MathException {
public:
    UnderflowException(const char* name, long firstValue, long secondValue) {
        strcpy_s(operationName, name);
        firstArg = firstValue;
        secondArg = secondValue;
    };
    void message() {
        cout << "At " << operationName << " UnderflowException" << endl;
    }
};

class ZdivideException : public MathException {
public:
    ZdivideException(const char* name, long firstValue, long secondValue)
    {
        strcpy_s(operationName, name);
        firstArg = firstValue;
        secondArg = secondValue;
    }

    void message() {
        cout << "At " << operationName << " ZdivideException" << endl;
    }
};

class Math
{
public:
    long addition(long firstArg, long secondArg) {
        double res = (double)firstArg + secondArg;
        if (res > INT_MAX) {
            throw OverflowException("addition", firstArg, secondArg);
        }
        return firstArg + secondArg;
    };


    long subtraction(long firstArg, long secondArg) {
        double res = (double)firstArg - secondArg;
        if (res < INT_MIN) {
            throw UnderflowException("subtraction", firstArg, secondArg);
        }
        return firstArg - secondArg;
    };


    long multiplication(long firstArg, long secondArg) {
        double res = (double)firstArg * secondArg;
        if (res > INT_MAX) {
            throw OverflowException("multiplication", firstArg, secondArg);
        }
        return firstArg * secondArg;
    };


    long division(long a, long b) {
        if (b == 0) {
            throw ZdivideException("division", a, b);
        }
        else return a / b;
    };


    long modulo(long a, long b) {
        if (b == 0) {
            throw ZdivideException("modulo", a, b);
        }
        else return a % b;
    }
};

int main() {
    Math math;
    try {
        math.division(56, 6);
        math.addition(INT_MAX, 54);
        math.subtraction(67, 43);
        math.multiplication(INT_MAX, 2);
        math.modulo(7896, 78);
    }
    catch (ZdivideException error) {
        error.message();
    }
    catch (OverflowException error) {
        error.message();
    }
    catch (UnderflowException error) {
        error.message();
    }

    return 0;
}