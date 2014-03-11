#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
  public:
    Complex();
    Complex(const Complex& c);
    Complex(const Complex* c);
    Complex(int real, int imag);

    int getReal() const;
    int getImag() const;
    void setReal(int real);
    void setImag(int imag);

    Complex operator+(const Complex& c) const;
    Complex& operator+=(const Complex& c);
    Complex operator-(const Complex& c) const;
    Complex& operator-=(const Complex& c);
    Complex operator*(const Complex& c) const;
    Complex& operator*=(const Complex& c);

  private:
    int real;
    int imag;
};

#endif
