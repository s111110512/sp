```
1: #include <stdio.h>
2: int power(int x, int n) {
3:     if (n == 0) {
    ENT  0
    LLA  2
    LI  
    PSH 
    IMM  0
    EQ  
    BZ   0
4:         return 1;
    IMM  1
    LEV 
5:     }
6:     else {
    JMP  0
7:         return x * power(x, n - 1);
    LLA  3
    LI
    PSH
    LLA  3
    LI
    PSH
    LLA  2
    LI
    PSH
    IMM  1
    SUB
    PSH
    JSR  -1712389992
    ADJ  2
    MUL
    LEV
8:     }
9: }
    LEV
10: int main() {
11:     printf("%d",power(2, 3));
    ENT  0
    IMM  -1712127840
    PSH
    IMM  2
    PSH
    IMM  3
    PSH
    JSR  -1712389992
    ADJ  2
    PSH
    PRTF
    ADJ  2
12:     return 0;
    IMM  0
    LEV
13: }
    LEV
```