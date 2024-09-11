
hw03.s:     file format elf32-littlearm


Disassembly of section .text:

00010054 <start>:
   10054:	e3a00000 	mov	r0, #0
   10058:	e3a01003 	mov	r1, #3
   1005c:	e3a02004 	mov	r2, #4
   10060:	e3a0300d 	mov	r3, #13
   10064:	e3a04005 	mov	r4, #5
   10068:	e3a05002 	mov	r5, #2
   1006c:	e0060194 	mul	r6, r4, r1
   10070:	e0070295 	mul	r7, r5, r2
   10074:	e0460007 	sub	r0, r6, r7
   10078:	e353000a 	cmp	r3, #10
   1007c:	aa000002 	bge	1008c <update>
   10080:	e3530005 	cmp	r3, #5
   10084:	0a000001 	beq	10090 <update2>
   10088:	e2800064 	add	r0, r0, #100	; 0x64

0001008c <update>:
   1008c:	e2800003 	add	r0, r0, #3

00010090 <update2>:
   10090:	e2800014 	add	r0, r0, #20

00010094 <end>:
   10094:	e3a07001 	mov	r7, #1
   10098:	ef000000 	svc	0x00000000
