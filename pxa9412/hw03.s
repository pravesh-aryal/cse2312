    .global _start

_start:
    mov    r0, #0   // r0 = 0
    mov    r1, #3  // r1 = 3
    mov    r2, #4   // r2 = 4
    mov    r3, #13 // r3 = 13
    mov    r4, #5 // r4 = 5
    mov    r5, #2 // r5 = 2

    mul    r6, r4, r1  // r6 = r4 * r1 (5 * 3 = 15)
    mul    r7, r5, r2  // r7 = r5 * r2 (2 * 4 = 8)
    sub    r0, r6, r7  // r0 = r6 - r7 (15 - 8 = 7)

    cmp    r3, #10     // compare r3 with 10
    addge r0, r0, #3    //r0 = r0 + 3 if c >= 10

    cmp    r3, #5      // compare r3 with 5
    addeq r0, r0, #20 // r0 = r0 + 20 if c is 5
    addne r0, r0, #100 //r0 = r0 + 100 if c isnot 5

end:
    mov R7, #1
    swi 0
