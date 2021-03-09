4.2
A
vtable * // 8
string 24 bytes // 32
int i | char c | 3 padding // 40


sizeof(B)

A // 40
int h | 4 padding // 48
double d // 56

---

// A

vtable * // 8
mCapacity // 16
mSize // 24
mData // 32
int i | char c | 3 padding // 40
int h | 4 padding // 48
double d // 56

VTable of B:

A vtable:
[0] A::x()
[1] A::z()
[2] A::~A()

B vtable

[0] B::x()
[1] A::z()
[2] B::~B()
[3] B::w()