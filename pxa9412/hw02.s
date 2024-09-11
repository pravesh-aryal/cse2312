    .global _start

_start:
    //Name: Pravesh Aryal
    
    //initializing the values
    mov R0, #0
    mov R1, #34
    mov R2, #-17
    
    //R2 = R1 bitwise and R2
    AND R2, R1, R2

    //R2 = R2 shifted right by 3
    LSR R2, R2, #3

    //R0 = R1 bitwise or with R2
    ORR R0, R1, R2

    //R0 = R0 shifted left by 2
    LSL R0, R0, #2



end:
    mov R7, #1
    swi 0
