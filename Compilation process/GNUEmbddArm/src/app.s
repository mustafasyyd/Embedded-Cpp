	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"app.c"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	.fnstart
.LFB0:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	adr	r3, .L3
	ldmia	r3, {r2-r3}
	str	r2, [fp, #-12]
	str	r3, [fp, #-8]
	sub	r1, fp, #12
	ldmia	r1, {r0-r1}
	bl	_Z8get_datad
	str	r0, [fp, #-20]
	str	r1, [fp, #-16]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L4:
	.align	3
.L3:
	.word	-1717986918
	.word	1077320089
	.cantunwind
	.fnend
	.size	main, .-main
	.global	__aeabi_dmul
	.align	2
	.global	_Z8get_datad
	.syntax unified
	.arm
	.type	_Z8get_datad, %function
_Z8get_datad:
	.fnstart
.LFB1:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-12]
	str	r1, [fp, #-8]
	adr	r3, .L7
	ldmia	r3, {r2-r3}
	sub	r1, fp, #12
	ldmia	r1, {r0-r1}
	bl	__aeabi_dmul
	mov	r2, r0
	mov	r3, r1
	str	r2, [fp, #-12]
	str	r3, [fp, #-8]
	sub	r3, fp, #12
	ldmia	r3, {r2-r3}
	mov	r0, r2
	mov	r1, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L8:
	.align	3
.L7:
	.word	1374389535
	.word	1074339512
	.cantunwind
	.fnend
	.size	_Z8get_datad, .-_Z8get_datad
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
