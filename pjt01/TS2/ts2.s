	.file	"ts2.cpp"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LVL0:
.LFB5979:
	.file 1 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/stdio.h"
	.loc 1 346 1 view -0
	.cfi_startproc
	.loc 1 346 1 is_stmt 0 view .LVU1
	pushq	%rsi
	.seh_pushreg	%rsi
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.seh_stackalloc	56
	.cfi_def_cfa_offset 80
	.seh_endprologue
	.loc 1 347 3 is_stmt 1 view .LVU2
	.loc 1 348 3 view .LVU3
	.loc 1 348 35 view .LVU4
	.loc 1 348 53 is_stmt 0 view .LVU5
	leaq	88(%rsp), %rbx
	.loc 1 346 1 view .LVU6
	movq	%rcx, %rsi
	movq	%rdx, 88(%rsp)
	.loc 1 349 30 view .LVU7
	movl	$1, %ecx
.LVL1:
	.loc 1 346 1 view .LVU8
	movq	%r8, 96(%rsp)
	movq	%r9, 104(%rsp)
	.loc 1 348 53 view .LVU9
	movq	%rbx, 40(%rsp)
	.loc 1 349 3 is_stmt 1 view .LVU10
	.loc 1 349 30 is_stmt 0 view .LVU11
	call	*__imp___acrt_iob_func(%rip)
.LVL2:
	movq	%rbx, %r8
	movq	%rsi, %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
.LVL3:
	.loc 1 350 3 is_stmt 1 view .LVU12
	.loc 1 351 3 view .LVU13
	.loc 1 352 1 is_stmt 0 view .LVU14
	addq	$56, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rsi
	.cfi_restore 4
	.cfi_def_cfa_offset 8
.LVL4:
	.loc 1 352 1 view .LVU15
	ret
	.cfi_endproc
.LFE5979:
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Accepted socket number %llu\12\0"
	.align 8
.LC1:
	.ascii "GlobalAlloc() failed with error %lu\12\0"
	.align 8
.LC2:
	.ascii "GlobalAlloc() for SOCKET_INFORMATION is OK!\12\0"
	.text
	.p2align 4,,15
	.globl	_Z23CreateSocketInformationy
	.def	_Z23CreateSocketInformationy;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z23CreateSocketInformationy
_Z23CreateSocketInformationy:
.LVL5:
.LFB6018:
	.file 2 "../ts2.cpp"
	.loc 2 300 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 2 300 1 is_stmt 0 view .LVU17
	pushq	%rsi
	.seh_pushreg	%rsi
	.cfi_def_cfa_offset 16
	.cfi_offset 4, -16
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.seh_stackalloc	40
	.cfi_def_cfa_offset 64
	.seh_endprologue
	.loc 2 302 4 is_stmt 1 view .LVU18
	.loc 2 304 4 view .LVU19
	.loc 2 304 10 is_stmt 0 view .LVU20
	movq	%rcx, %rdx
	.loc 2 300 1 view .LVU21
	movq	%rcx, %rsi
	.loc 2 304 10 view .LVU22
	leaq	.LC0(%rip), %rcx
.LVL6:
	.loc 2 304 10 view .LVU23
	call	_Z6printfPKcz
.LVL7:
	.loc 2 307 4 is_stmt 1 view .LVU24
	.loc 2 307 48 is_stmt 0 view .LVU25
	movl	$8256, %edx
	movl	$64, %ecx
	call	*__imp_GlobalAlloc(%rip)
.LVL8:
	.loc 2 307 4 view .LVU26
	testq	%rax, %rax
	.loc 2 307 48 view .LVU27
	movq	%rax, %rbx
.LVL9:
	.loc 2 307 4 view .LVU28
	je	.L6
	.loc 2 313 7 is_stmt 1 view .LVU29
	.loc 2 313 13 is_stmt 0 view .LVU30
	leaq	.LC2(%rip), %rcx
	call	_Z6printfPKcz
.LVL10:
	.loc 2 317 4 is_stmt 1 view .LVU31
	.loc 2 322 28 is_stmt 0 view .LVU32
	movl	TotalSockets(%rip), %ecx
	.loc 2 322 30 view .LVU33
	leaq	SocketArray(%rip), %rdx
	.loc 2 317 15 view .LVU34
	movq	%rsi, 8208(%rbx)
	.loc 2 318 4 is_stmt 1 view .LVU35
	.loc 2 320 4 view .LVU36
	.loc 2 318 18 is_stmt 0 view .LVU37
	movq	$0, 8248(%rbx)
	.loc 2 322 4 is_stmt 1 view .LVU38
	.loc 2 322 28 is_stmt 0 view .LVU39
	movq	%rcx, %rax
	.loc 2 322 30 view .LVU40
	movq	%rbx, (%rdx,%rcx,8)
	.loc 2 323 4 is_stmt 1 view .LVU41
	.loc 2 323 16 is_stmt 0 view .LVU42
	addl	$1, %eax
	movl	%eax, TotalSockets(%rip)
	.loc 2 324 4 is_stmt 1 view .LVU43
	.loc 2 324 14 is_stmt 0 view .LVU44
	movl	$1, %eax
	.loc 2 325 1 view .LVU45
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
.LVL11:
	.loc 2 325 1 view .LVU46
	popq	%rsi
	.cfi_restore 4
	.cfi_def_cfa_offset 8
.LVL12:
	.loc 2 325 1 view .LVU47
	ret
.LVL13:
	.p2align 4,,10
.L6:
	.cfi_restore_state
.LBB4:
.LBB5:
	.loc 2 309 7 is_stmt 1 view .LVU48
	.loc 2 309 13 is_stmt 0 view .LVU49
	call	*__imp_GetLastError(%rip)
.LVL14:
	.loc 2 309 13 view .LVU50
	leaq	.LC1(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL15:
	.loc 2 310 7 is_stmt 1 view .LVU51
	.loc 2 309 13 is_stmt 0 view .LVU52
	xorl	%eax, %eax
.LBE5:
.LBE4:
	.loc 2 325 1 view .LVU53
	addq	$40, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
.LVL16:
	.loc 2 325 1 view .LVU54
	popq	%rsi
	.cfi_restore 4
	.cfi_def_cfa_offset 8
.LVL17:
	.loc 2 325 1 view .LVU55
	ret
	.cfi_endproc
.LFE6018:
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "Closing socket number %llu\12\0"
	.text
	.p2align 4,,15
	.globl	_Z21FreeSocketInformationm
	.def	_Z21FreeSocketInformationm;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z21FreeSocketInformationm
_Z21FreeSocketInformationm:
.LVL18:
.LFB6019:
	.loc 2 330 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 2 330 1 is_stmt 0 view .LVU57
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rdi
	.seh_pushreg	%rdi
	.cfi_def_cfa_offset 24
	.cfi_offset 5, -24
	pushq	%rsi
	.seh_pushreg	%rsi
	.cfi_def_cfa_offset 32
	.cfi_offset 4, -32
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$40, %rsp
	.seh_stackalloc	40
	.cfi_def_cfa_offset 80
	.seh_endprologue
	.loc 2 331 4 is_stmt 1 view .LVU58
	.loc 2 331 25 is_stmt 0 view .LVU59
	leaq	SocketArray(%rip), %rbp
	.loc 2 330 1 view .LVU60
	movl	%ecx, %esi
	.loc 2 331 25 view .LVU61
	movq	0(%rbp,%rsi,8), %rdi
.LVL19:
	.loc 2 332 4 is_stmt 1 view .LVU62
	.loc 2 334 4 view .LVU63
	.loc 2 334 15 is_stmt 0 view .LVU64
	movq	8208(%rdi), %rcx
.LVL20:
	.loc 2 334 15 view .LVU65
	call	*__imp_closesocket(%rip)
.LVL21:
	.loc 2 335 4 is_stmt 1 view .LVU66
	.loc 2 335 10 is_stmt 0 view .LVU67
	movq	8208(%rdi), %rdx
	leaq	.LC3(%rip), %rcx
	call	_Z6printfPKcz
.LVL22:
	.loc 2 336 4 is_stmt 1 view .LVU68
	.loc 2 336 14 is_stmt 0 view .LVU69
	movq	%rdi, %rcx
	call	*__imp_GlobalFree(%rip)
.LVL23:
	.loc 2 339 4 is_stmt 1 view .LVU70
	.loc 2 339 22 is_stmt 0 view .LVU71
	movl	TotalSockets(%rip), %edx
	leal	-1(%rdx), %r9d
	cmpl	%edx, %esi
	jnb	.L8
	leal	-1(%rdx), %r9d
	leaq	8+SocketArray(%rip), %rcx
	movl	%r9d, %edx
	leaq	0(%rbp,%rsi,8), %rax
	subl	%esi, %edx
	addq	%rsi, %rdx
	leaq	(%rcx,%rdx,8), %r8
	.loc 2 341 41 view .LVU72
	leal	1(%rsi), %ecx
	subq	%rsi, %rcx
.LVL24:
	.p2align 4,,10
.L9:
	.loc 2 341 7 is_stmt 1 discriminator 2 view .LVU73
	.loc 2 341 41 is_stmt 0 discriminator 2 view .LVU74
	movq	(%rax,%rcx,8), %rdx
	addq	$8, %rax
	.loc 2 341 22 discriminator 2 view .LVU75
	movq	%rdx, -8(%rax)
	.loc 2 339 22 discriminator 2 view .LVU76
	cmpq	%r8, %rax
	jne	.L9
.L8:
	.loc 2 344 4 is_stmt 1 view .LVU77
	.loc 2 344 16 is_stmt 0 view .LVU78
	movl	%r9d, TotalSockets(%rip)
	.loc 2 346 1 view .LVU79
	addq	$40, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 32
	popq	%rsi
	.cfi_restore 4
	.cfi_def_cfa_offset 24
.LVL25:
	.loc 2 346 1 view .LVU80
	popq	%rdi
	.cfi_restore 5
	.cfi_def_cfa_offset 16
.LVL26:
	.loc 2 346 1 view .LVU81
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE6019:
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC4:
	.ascii "Usage : ts2 [source port] [destination port]\0"
	.align 8
.LC5:
	.ascii "WSAStartup() failed with error %d\12\0"
.LC6:
	.ascii "WSAStartup() is fine!\12\0"
	.align 8
.LC7:
	.ascii "WSASocket() failed with error %d\12\0"
.LC8:
	.ascii "WSASocket() is OK!\12\0"
.LC9:
	.ascii "bind() failed with error %d\12\0"
.LC10:
	.ascii "bind() is OK!\12\0"
	.align 8
.LC11:
	.ascii "listen() failed with error %d\12\0"
.LC12:
	.ascii "listen() is OK!\12\0"
	.align 8
.LC13:
	.ascii "ioctlsocket() failed with error %d\12\0"
.LC14:
	.ascii "ioctlsocket() is OK!\12\0"
	.align 8
.LC15:
	.ascii "select() returned with error %d\12\0"
.LC16:
	.ascii "select() is OK!\12\0"
	.align 8
.LC17:
	.ascii "ioctlsocket(FIONBIO) failed with error %d\12\0"
.LC18:
	.ascii "ioctlsocket(FIONBIO) is OK!\12\0"
	.align 8
.LC19:
	.ascii "CreateSocketInformation(AcceptSocket) failed!\12\0"
	.align 8
.LC20:
	.ascii "CreateSocketInformation() is OK!\12\0"
	.align 8
.LC21:
	.ascii "accept() failed with error %d\12\0"
.LC22:
	.ascii "accept() is fine!\12\0"
	.align 8
.LC23:
	.ascii "WSARecv() failed with error %d\12\0"
.LC24:
	.ascii "WSARecv() is OK!\12\0"
	.align 8
.LC25:
	.ascii "WSASend() failed with error %d\12\0"
.LC26:
	.ascii "WSASend() is OK!\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LVL27:
.LFB6017:
	.loc 2 61 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 2 61 1 is_stmt 0 view .LVU83
	pushq	%r15
	.seh_pushreg	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.seh_pushreg	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.seh_pushreg	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.seh_pushreg	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rdi
	.seh_pushreg	%rdi
	.cfi_def_cfa_offset 56
	.cfi_offset 5, -56
	pushq	%rsi
	.seh_pushreg	%rsi
	.cfi_def_cfa_offset 64
	.cfi_offset 4, -64
	pushq	%rbx
	.seh_pushreg	%rbx
	.cfi_def_cfa_offset 72
	.cfi_offset 3, -72
	subq	$1608, %rsp
	.seh_stackalloc	1608
	.cfi_def_cfa_offset 1680
	.seh_endprologue
	.loc 2 61 1 view .LVU84
	movl	%ecx, %esi
	movq	%rdx, %rbx
	call	__main
.LVL28:
	.loc 2 63 4 is_stmt 1 view .LVU85
	.loc 2 64 4 view .LVU86
	.loc 2 65 4 view .LVU87
	.loc 2 66 4 view .LVU88
	.loc 2 67 4 view .LVU89
	.loc 2 68 4 view .LVU90
	.loc 2 69 4 view .LVU91
	.loc 2 70 4 view .LVU92
	.loc 2 71 4 view .LVU93
	.loc 2 72 4 view .LVU94
	.loc 2 73 4 view .LVU95
	.loc 2 74 4 view .LVU96
	.loc 2 75 4 view .LVU97
	.loc 2 77 4 view .LVU98
	.loc 2 79 4 view .LVU99
	.loc 2 80 5 view .LVU100
	cmpl	$2, %esi
	jle	.L14
	.loc 2 81 9 view .LVU101
	.loc 2 81 23 is_stmt 0 view .LVU102
	movq	8(%rbx), %rcx
	call	atoi
.LVL29:
	.loc 2 82 23 view .LVU103
	movq	16(%rbx), %rcx
	.loc 2 81 23 view .LVU104
	movl	%eax, %esi
.LVL30:
	.loc 2 82 9 is_stmt 1 view .LVU105
	.loc 2 82 23 is_stmt 0 view .LVU106
	call	atoi
.LVL31:
	.loc 2 89 4 is_stmt 1 view .LVU107
	.loc 2 89 25 is_stmt 0 view .LVU108
	leaq	128(%rsp), %rdx
	movl	$514, %ecx
	call	*__imp_WSAStartup(%rip)
.LVL32:
	.loc 2 89 4 view .LVU109
	testl	%eax, %eax
	jne	.L91
	.loc 2 97 7 is_stmt 1 view .LVU110
	.loc 2 97 13 is_stmt 0 view .LVU111
	leaq	.LC6(%rip), %rcx
	call	_Z6printfPKcz
.LVL33:
	.loc 2 103 4 is_stmt 1 view .LVU112
	.loc 2 103 32 is_stmt 0 view .LVU113
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	movl	$1, %edx
	movl	$1, 40(%rsp)
	movl	$2, %ecx
	movl	$0, 32(%rsp)
	call	*__imp_WSASocketA(%rip)
.LVL34:
	movq	%rax, 72(%rsp)
.LVL35:
	.loc 2 103 4 view .LVU114
	addq	$1, %rax
.LVL36:
	.loc 2 103 4 view .LVU115
	je	.L92
	.loc 2 109 7 is_stmt 1 view .LVU116
	.loc 2 109 13 is_stmt 0 view .LVU117
	leaq	.LC8(%rip), %rcx
	call	_Z6printfPKcz
.LVL37:
	.loc 2 113 4 is_stmt 1 view .LVU118
	.loc 2 114 39 is_stmt 0 view .LVU119
	xorl	%ecx, %ecx
	.loc 2 113 28 view .LVU120
	movw	$2, 112(%rsp)
	.loc 2 114 4 is_stmt 1 view .LVU121
	.loc 2 114 39 is_stmt 0 view .LVU122
	call	*__imp_htonl(%rip)
.LVL38:
	.loc 2 115 33 view .LVU123
	movzwl	%si, %ecx
	.loc 2 114 32 view .LVU124
	movl	%eax, 116(%rsp)
	.loc 2 115 4 is_stmt 1 view .LVU125
	.loc 2 115 33 is_stmt 0 view .LVU126
	call	*__imp_htons(%rip)
.LVL39:
	.loc 2 117 12 view .LVU127
	leaq	112(%rsp), %rdx
	movl	$16, %r8d
	movq	72(%rsp), %rcx
	.loc 2 115 26 view .LVU128
	movw	%ax, 114(%rsp)
	.loc 2 117 4 is_stmt 1 view .LVU129
	.loc 2 117 12 is_stmt 0 view .LVU130
	call	*__imp_bind(%rip)
.LVL40:
	.loc 2 117 4 view .LVU131
	addl	$1, %eax
	je	.L93
	.loc 2 123 7 is_stmt 1 view .LVU132
	.loc 2 123 13 is_stmt 0 view .LVU133
	leaq	.LC10(%rip), %rcx
	call	_Z6printfPKcz
.LVL41:
	.loc 2 127 4 is_stmt 1 view .LVU134
	.loc 2 127 14 is_stmt 0 view .LVU135
	movl	$5, %edx
	movq	72(%rsp), %rcx
	call	*__imp_listen(%rip)
.LVL42:
	.loc 2 127 4 view .LVU136
	testl	%eax, %eax
	jne	.L94
	.loc 2 133 7 is_stmt 1 view .LVU137
	.loc 2 133 13 is_stmt 0 view .LVU138
	leaq	.LC12(%rip), %rcx
	call	_Z6printfPKcz
.LVL43:
	.loc 2 139 4 is_stmt 1 view .LVU139
	.loc 2 140 19 is_stmt 0 view .LVU140
	leaq	96(%rsp), %rax
	movl	$-2147195266, %edx
	.loc 2 139 13 view .LVU141
	movl	$1, 96(%rsp)
	.loc 2 140 4 is_stmt 1 view .LVU142
	.loc 2 140 19 is_stmt 0 view .LVU143
	movq	%rax, 80(%rsp)
	movq	%rax, %r8
	movq	__imp_ioctlsocket(%rip), %rax
	movq	72(%rsp), %rcx
	movq	%rax, 88(%rsp)
	call	*%rax
.LVL44:
	.loc 2 140 4 view .LVU144
	addl	$1, %eax
	je	.L95
	.loc 2 146 7 is_stmt 1 view .LVU145
	.loc 2 146 13 is_stmt 0 view .LVU146
	leaq	.LC14(%rip), %rcx
	call	_Z6printfPKcz
.LVL45:
	movl	TotalSockets(%rip), %eax
	leaq	544(%rsp), %rdi
	leaq	1072(%rsp), %rbx
.LVL46:
	.p2align 4,,10
.L22:
	.loc 2 149 4 is_stmt 1 view .LVU147
.LBB6:
	.loc 2 153 6 view .LVU148
	.loc 2 154 6 view .LVU149
.LBB7:
	.loc 2 157 24 is_stmt 0 view .LVU150
	movq	72(%rsp), %rsi
.LBE7:
.LBB8:
	.loc 2 162 21 view .LVU151
	testl	%eax, %eax
.LBE8:
	.loc 2 154 19 view .LVU152
	movl	$0, 544(%rsp)
	.loc 2 157 6 is_stmt 1 view .LVU153
.LBB17:
	.loc 2 157 11 view .LVU154
	.loc 2 157 22 view .LVU155
.LVL47:
	.loc 2 157 22 view .LVU156
	.loc 2 157 22 view .LVU157
	.loc 2 157 27 view .LVU158
	.loc 2 157 18 is_stmt 0 view .LVU159
	movl	$1, 1072(%rsp)
	.loc 2 157 24 view .LVU160
	movq	%rsi, 1080(%rsp)
	.loc 2 157 9 is_stmt 1 view .LVU161
.LBE17:
	.loc 2 162 7 view .LVU162
.LVL48:
.LBB18:
	.loc 2 162 21 is_stmt 0 view .LVU163
	je	.L82
	leaq	SocketArray(%rip), %r8
	subl	$1, %eax
	xorl	%ebp, %ebp
	leaq	8(%r8), %rsi
	movl	$1, %r10d
	xorl	%r9d, %r9d
	leaq	(%rsi,%rax,8), %r11
	xorl	%esi, %esi
.LVL49:
	.p2align 4,,10
.L33:
	.loc 2 162 21 view .LVU164
.LBE18:
.LBE6:
	.loc 2 163 10 is_stmt 1 view .LVU165
.LBB37:
.LBB19:
.LBB9:
	.loc 2 163 27 is_stmt 0 view .LVU166
	movq	(%r8), %rax
	.loc 2 163 10 view .LVU167
	movl	8248(%rax), %ecx
	cmpl	%ecx, 8252(%rax)
	movq	8208(%rax), %rdx
	jbe	.L26
.LVL50:
.LBB10:
	.loc 2 164 45 view .LVU168
	testl	%r9d, %r9d
	je	.L51
	.loc 2 164 35 is_stmt 1 view .LVU169
	cmpq	%rdx, 552(%rsp)
	je	.L28
	leal	-1(%r9), %ecx
	movl	$1, %eax
	addq	$1, %rcx
	jmp	.L29
.LVL51:
	.p2align 4,,10
.L30:
	.loc 2 164 35 discriminator 3 view .LVU170
	addq	$1, %rax
.LVL52:
	.loc 2 164 35 is_stmt 0 discriminator 3 view .LVU171
	cmpq	%rdx, (%rdi,%rax,8)
	je	.L28
.LVL53:
.L29:
	.loc 2 164 45 discriminator 5 view .LVU172
	cmpq	%rcx, %rax
	.loc 2 164 28 discriminator 5 view .LVU173
	movl	%eax, %r12d
.LVL54:
	.loc 2 164 45 discriminator 5 view .LVU174
	jne	.L30
	.loc 2 164 28 is_stmt 1 discriminator 7 view .LVU175
	.loc 2 164 28 discriminator 7 view .LVU176
	cmpl	%r12d, %r9d
	jne	.L28
	cmpl	$64, %r9d
	jne	.L96
.LVL55:
	.p2align 4,,10
.L28:
	.loc 2 164 28 is_stmt 0 discriminator 7 view .LVU177
	addq	$8, %r8
.LBE10:
.LBE9:
	.loc 2 162 21 discriminator 2 view .LVU178
	cmpq	%r11, %r8
	jne	.L33
	testb	%sil, %sil
	je	.L34
	movl	%r9d, 544(%rsp)
.L34:
	testb	%bpl, %bpl
	je	.L82
	movl	%r10d, 1072(%rsp)
.L82:
	.loc 2 162 21 discriminator 2 view .LVU179
.LBE19:
	.loc 2 168 7 is_stmt 1 view .LVU180
	.loc 2 168 26 is_stmt 0 view .LVU181
	xorl	%r9d, %r9d
	xorl	%ecx, %ecx
	movq	%rdi, %r8
	movq	$0, 32(%rsp)
	movq	%rbx, %rdx
	call	*__imp_select(%rip)
.LVL56:
	.loc 2 168 7 view .LVU182
	cmpl	$-1, %eax
	.loc 2 168 26 view .LVU183
	movl	%eax, %ebp
.LVL57:
	.loc 2 168 7 view .LVU184
	je	.L97
	.loc 2 174 10 is_stmt 1 view .LVU185
	.loc 2 174 16 is_stmt 0 view .LVU186
	leaq	.LC16(%rip), %rcx
	call	_Z6printfPKcz
.LVL58:
	.loc 2 178 7 is_stmt 1 view .LVU187
	.loc 2 178 22 is_stmt 0 view .LVU188
	movq	72(%rsp), %rcx
	movq	%rbx, %rdx
	call	__WSAFDIsSet
.LVL59:
	.loc 2 178 7 view .LVU189
	testl	%eax, %eax
	jne	.L98
.L36:
.LVL60:
.LBB20:
	.loc 2 217 29 discriminator 1 view .LVU190
	testl	%ebp, %ebp
	movl	TotalSockets(%rip), %eax
	je	.L22
	.loc 2 217 29 view .LVU191
	testl	%eax, %eax
	je	.L42
	leaq	SocketArray(%rip), %r12
	xorl	%esi, %esi
.LBB21:
	.loc 2 232 24 view .LVU192
	movq	__imp_WSARecv(%rip), %r14
	jmp	.L43
.LVL61:
	.p2align 4,,10
.L47:
	.loc 2 232 24 view .LVU193
.LBE21:
	.loc 2 217 29 discriminator 3 view .LVU194
	testl	%ebp, %ebp
	movl	TotalSockets(%rip), %eax
	je	.L22
	.loc 2 217 29 discriminator 3 view .LVU195
	addq	$1, %rsi
.LVL62:
	.loc 2 217 29 discriminator 2 view .LVU196
	cmpl	%esi, %eax
	jbe	.L22
.LVL63:
.L43:
.LBB22:
	.loc 2 219 31 view .LVU197
	movq	(%r12,%rsi,8), %r13
	.loc 2 223 25 view .LVU198
	movq	%rbx, %rdx
	movl	%esi, %r15d
.LVL64:
	.loc 2 219 10 is_stmt 1 view .LVU199
	.loc 2 223 10 view .LVU200
	.loc 2 223 25 is_stmt 0 view .LVU201
	movq	8208(%r13), %rcx
	call	__WSAFDIsSet
.LVL65:
	.loc 2 223 10 view .LVU202
	testl	%eax, %eax
	je	.L44
	.loc 2 225 13 is_stmt 1 view .LVU203
	.loc 2 232 24 is_stmt 0 view .LVU204
	leaq	100(%rsp), %rax
	movl	$1, %r8d
	.loc 2 225 18 view .LVU205
	subl	$1, %ebp
.LVL66:
	.loc 2 227 13 is_stmt 1 view .LVU206
	.loc 2 227 37 is_stmt 0 view .LVU207
	movq	%r13, 8200(%r13)
	.loc 2 228 13 is_stmt 1 view .LVU208
	.loc 2 228 37 is_stmt 0 view .LVU209
	movl	$8192, 8192(%r13)
	.loc 2 230 13 is_stmt 1 view .LVU210
	.loc 2 232 24 is_stmt 0 view .LVU211
	movq	8208(%r13), %rcx
	leaq	8192(%r13), %rdx
	.loc 2 230 19 view .LVU212
	movl	$0, 100(%rsp)
	.loc 2 232 13 is_stmt 1 view .LVU213
	.loc 2 232 24 is_stmt 0 view .LVU214
	leaq	108(%rsp), %r9
	movq	$0, 48(%rsp)
	movq	$0, 40(%rsp)
	movq	%rax, 32(%rsp)
	call	*%r14
.LVL67:
	.loc 2 232 13 view .LVU215
	cmpl	$-1, %eax
	je	.L99
	.loc 2 248 16 is_stmt 1 view .LVU216
	.loc 2 248 38 is_stmt 0 view .LVU217
	movl	108(%rsp), %eax
	.loc 2 250 16 view .LVU218
	testl	%eax, %eax
	.loc 2 248 38 view .LVU219
	movl	%eax, 8252(%r13)
	.loc 2 250 16 is_stmt 1 view .LVU220
	je	.L100
.L44:
	.loc 2 260 10 view .LVU221
	.loc 2 260 25 is_stmt 0 view .LVU222
	movq	8208(%r13), %rcx
	movq	%rdi, %rdx
	call	__WSAFDIsSet
.LVL68:
	.loc 2 260 10 view .LVU223
	testl	%eax, %eax
	je	.L47
	.loc 2 263 13 is_stmt 1 view .LVU224
	.loc 2 265 72 is_stmt 0 view .LVU225
	movl	8248(%r13), %eax
	.loc 2 268 24 view .LVU226
	leaq	104(%rsp), %r9
	movl	$1, %r8d
	.loc 2 263 18 view .LVU227
	subl	$1, %ebp
.LVL69:
	.loc 2 265 13 is_stmt 1 view .LVU228
	.loc 2 268 24 is_stmt 0 view .LVU229
	movq	8208(%r13), %rcx
	.loc 2 265 72 view .LVU230
	movq	%rax, %rdx
	.loc 2 265 58 view .LVU231
	addq	%r13, %rax
	movq	%rax, 8200(%r13)
	.loc 2 266 13 is_stmt 1 view .LVU232
	.loc 2 266 61 is_stmt 0 view .LVU233
	movl	8252(%r13), %eax
	subl	%edx, %eax
	.loc 2 266 37 view .LVU234
	movl	%eax, 8192(%r13)
	.loc 2 268 13 is_stmt 1 view .LVU235
	.loc 2 268 24 is_stmt 0 view .LVU236
	leaq	8192(%r13), %rdx
	movq	$0, 48(%rsp)
	movq	$0, 40(%rsp)
	movl	$0, 32(%rsp)
	call	*__imp_WSASend(%rip)
.LVL70:
	.loc 2 268 13 view .LVU237
	cmpl	$-1, %eax
	je	.L101
	.loc 2 282 16 is_stmt 1 view .LVU238
	.loc 2 282 38 is_stmt 0 view .LVU239
	movl	104(%rsp), %eax
	addl	8248(%r13), %eax
	.loc 2 284 16 view .LVU240
	cmpl	8252(%r13), %eax
	.loc 2 282 38 view .LVU241
	movl	%eax, 8248(%r13)
	.loc 2 284 16 is_stmt 1 view .LVU242
	jne	.L47
	.loc 2 286 19 view .LVU243
	.loc 2 287 19 view .LVU244
	.loc 2 286 41 is_stmt 0 view .LVU245
	movq	$0, 8248(%r13)
	jmp	.L47
.LVL71:
.L91:
	.loc 2 286 41 view .LVU246
.LBE22:
.LBE20:
.LBE37:
	.loc 2 91 7 is_stmt 1 view .LVU247
	.loc 2 91 13 is_stmt 0 view .LVU248
	leaq	.LC5(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL72:
	.loc 2 92 7 is_stmt 1 view .LVU249
	.loc 2 92 17 is_stmt 0 view .LVU250
	call	*__imp_WSACleanup(%rip)
.LVL73:
	.loc 2 93 7 is_stmt 1 view .LVU251
.L17:
	.loc 2 295 1 is_stmt 0 view .LVU252
	movl	$1, %eax
	addq	$1608, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 72
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 64
	popq	%rsi
	.cfi_restore 4
	.cfi_def_cfa_offset 56
	popq	%rdi
	.cfi_restore 5
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_restore 12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_restore 13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_restore 14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_restore 15
	.cfi_def_cfa_offset 8
	ret
.LVL74:
.L14:
	.cfi_restore_state
	.loc 2 85 9 is_stmt 1 view .LVU253
	.loc 2 85 15 is_stmt 0 view .LVU254
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
.LVL75:
	.loc 2 86 9 is_stmt 1 view .LVU255
	.loc 2 86 15 is_stmt 0 view .LVU256
	jmp	.L17
.LVL76:
.L94:
	.loc 2 129 7 is_stmt 1 view .LVU257
	.loc 2 129 13 is_stmt 0 view .LVU258
	call	*__imp_WSAGetLastError(%rip)
.LVL77:
	leaq	.LC11(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL78:
	.loc 2 130 7 is_stmt 1 view .LVU259
	.loc 2 130 14 is_stmt 0 view .LVU260
	jmp	.L17
.LVL79:
	.p2align 4,,10
.L26:
.LBB38:
.LBB28:
.LBB14:
.LBB11:
	.loc 2 166 35 is_stmt 1 view .LVU261
	cmpq	%rdx, 1080(%rsp)
	je	.L28
	leal	-1(%r10), %ecx
	movl	$1, %eax
	addq	$1, %rcx
	jmp	.L31
.LVL80:
	.p2align 4,,10
.L32:
	.loc 2 166 35 discriminator 3 view .LVU262
	addq	$1, %rax
.LVL81:
	.loc 2 166 35 is_stmt 0 discriminator 3 view .LVU263
	cmpq	%rdx, (%rbx,%rax,8)
	je	.L28
.LVL82:
.L31:
	.loc 2 166 45 discriminator 5 view .LVU264
	cmpq	%rax, %rcx
	.loc 2 166 28 discriminator 5 view .LVU265
	movl	%eax, %r12d
.LVL83:
	.loc 2 166 45 discriminator 5 view .LVU266
	jne	.L32
	.loc 2 166 28 is_stmt 1 discriminator 7 view .LVU267
	.loc 2 166 28 discriminator 7 view .LVU268
	cmpl	$64, %r10d
	setne	%al
.LVL84:
	.loc 2 166 28 is_stmt 0 discriminator 7 view .LVU269
	cmpl	%r12d, %r10d
	sete	%cl
	.loc 2 166 28 discriminator 7 view .LVU270
	andb	%cl, %al
	je	.L28
	addl	$1, %r10d
	.loc 2 166 33 is_stmt 1 view .LVU271
	.loc 2 166 30 is_stmt 0 view .LVU272
	movq	%rdx, 1080(%rsp,%r12,8)
	.loc 2 166 15 is_stmt 1 view .LVU273
	movl	%eax, %ebp
	jmp	.L28
.LVL85:
	.p2align 4,,10
.L100:
	.loc 2 166 15 is_stmt 0 view .LVU274
.LBE11:
.LBE14:
.LBE28:
.LBB29:
.LBB23:
	.loc 2 252 19 is_stmt 1 view .LVU275
	.loc 2 252 40 is_stmt 0 view .LVU276
	movl	%esi, %ecx
	call	_Z21FreeSocketInformationm
.LVL86:
	.loc 2 253 19 is_stmt 1 view .LVU277
	jmp	.L47
.LVL87:
	.p2align 4,,10
.L96:
	.loc 2 253 19 is_stmt 0 view .LVU278
	addl	$1, %r9d
.LVL88:
.L27:
	.loc 2 253 19 view .LVU279
.LBE23:
.LBE29:
.LBB30:
.LBB15:
.LBB12:
	.loc 2 164 33 is_stmt 1 discriminator 8 view .LVU280
	.loc 2 164 30 is_stmt 0 discriminator 8 view .LVU281
	movq	%rdx, 552(%rsp,%r12,8)
	.loc 2 164 15 is_stmt 1 discriminator 8 view .LVU282
	movl	$1, %esi
	jmp	.L28
.LVL89:
	.p2align 4,,10
.L99:
	.loc 2 164 15 is_stmt 0 discriminator 8 view .LVU283
.LBE12:
.LBE15:
.LBE30:
.LBB31:
.LBB24:
	.loc 2 234 16 is_stmt 1 view .LVU284
	.loc 2 234 35 is_stmt 0 view .LVU285
	movq	__imp_WSAGetLastError(%rip), %r13
.LVL90:
	.loc 2 234 35 view .LVU286
	call	*%r13
.LVL91:
	.loc 2 234 16 view .LVU287
	cmpl	$10035, %eax
	je	.L46
	.loc 2 236 19 is_stmt 1 view .LVU288
	.loc 2 236 25 is_stmt 0 view .LVU289
	call	*%r13
.LVL92:
	leaq	.LC23(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL93:
	.loc 2 237 19 is_stmt 1 view .LVU290
	.loc 2 237 40 is_stmt 0 view .LVU291
	movl	%esi, %ecx
	call	_Z21FreeSocketInformationm
.LVL94:
	jmp	.L47
.LVL95:
.L98:
	.loc 2 237 40 view .LVU292
.LBE24:
.LBE31:
	.loc 2 180 10 is_stmt 1 view .LVU293
	.loc 2 181 36 is_stmt 0 view .LVU294
	xorl	%r8d, %r8d
	xorl	%edx, %edx
	movq	72(%rsp), %rcx
	.loc 2 180 15 view .LVU295
	subl	$1, %ebp
.LVL96:
	.loc 2 181 10 is_stmt 1 view .LVU296
	.loc 2 181 36 is_stmt 0 view .LVU297
	call	*__imp_accept(%rip)
.LVL97:
	.loc 2 181 10 view .LVU298
	cmpq	$-1, %rax
	.loc 2 181 36 view .LVU299
	movq	%rax, %rsi
.LVL98:
	.loc 2 181 10 view .LVU300
	je	.L37
	.loc 2 185 13 is_stmt 1 view .LVU301
	.loc 2 186 28 is_stmt 0 view .LVU302
	movq	%rax, %rcx
	movq	80(%rsp), %r8
	movl	$-2147195266, %edx
	.loc 2 185 22 view .LVU303
	movl	$1, 96(%rsp)
	.loc 2 186 13 is_stmt 1 view .LVU304
	.loc 2 186 28 is_stmt 0 view .LVU305
	movq	88(%rsp), %rax
.LVL99:
	.loc 2 186 28 view .LVU306
	call	*%rax
.LVL100:
	.loc 2 186 13 view .LVU307
	cmpl	$-1, %eax
	je	.L102
	.loc 2 192 16 is_stmt 1 view .LVU308
	.loc 2 192 22 is_stmt 0 view .LVU309
	leaq	.LC18(%rip), %rcx
	call	_Z6printfPKcz
.LVL101:
	.loc 2 194 13 is_stmt 1 view .LVU310
	.loc 2 194 40 is_stmt 0 view .LVU311
	movq	%rsi, %rcx
	call	_Z23CreateSocketInformationy
.LVL102:
	.loc 2 194 13 view .LVU312
	testl	%eax, %eax
	je	.L103
	.loc 2 200 17 is_stmt 1 view .LVU313
	.loc 2 200 23 is_stmt 0 view .LVU314
	leaq	.LC20(%rip), %rcx
	call	_Z6printfPKcz
.LVL103:
	jmp	.L36
.LVL104:
.L101:
.LBB32:
.LBB25:
	.loc 2 270 16 is_stmt 1 view .LVU315
	.loc 2 270 35 is_stmt 0 view .LVU316
	call	*__imp_WSAGetLastError(%rip)
.LVL105:
	.loc 2 270 16 view .LVU317
	cmpl	$10035, %eax
	je	.L49
	.loc 2 272 19 is_stmt 1 view .LVU318
	.loc 2 272 25 is_stmt 0 view .LVU319
	call	*__imp_WSAGetLastError(%rip)
.LVL106:
	leaq	.LC25(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL107:
	.loc 2 273 19 is_stmt 1 view .LVU320
	.loc 2 273 40 is_stmt 0 view .LVU321
	movl	%r15d, %ecx
	call	_Z21FreeSocketInformationm
.LVL108:
	jmp	.L47
.LVL109:
.L51:
	.loc 2 273 40 view .LVU322
.LBE25:
.LBE32:
.LBB33:
.LBB16:
.LBB13:
	.loc 2 164 36 view .LVU323
	xorl	%r12d, %r12d
	.loc 2 164 45 view .LVU324
	movl	$1, %r9d
	jmp	.L27
.LVL110:
.L46:
	.loc 2 164 45 view .LVU325
.LBE13:
.LBE16:
.LBE33:
.LBB34:
.LBB26:
	.loc 2 240 19 is_stmt 1 view .LVU326
	.loc 2 240 25 is_stmt 0 view .LVU327
	leaq	.LC24(%rip), %rcx
	call	_Z6printfPKcz
.LVL111:
	jmp	.L47
.LVL112:
.L37:
	.loc 2 240 25 view .LVU328
.LBE26:
.LBE34:
	.loc 2 205 13 is_stmt 1 view .LVU329
	.loc 2 205 32 is_stmt 0 view .LVU330
	call	*__imp_WSAGetLastError(%rip)
.LVL113:
	.loc 2 205 13 view .LVU331
	cmpl	$10035, %eax
	jne	.L104
	.loc 2 211 16 is_stmt 1 view .LVU332
	.loc 2 211 22 is_stmt 0 view .LVU333
	leaq	.LC22(%rip), %rcx
	call	_Z6printfPKcz
.LVL114:
	jmp	.L36
.LVL115:
.L49:
.LBB35:
.LBB27:
	.loc 2 276 19 is_stmt 1 view .LVU334
	.loc 2 276 25 is_stmt 0 view .LVU335
	leaq	.LC26(%rip), %rcx
	call	_Z6printfPKcz
.LVL116:
	jmp	.L47
.LVL117:
.L42:
	.loc 2 276 25 view .LVU336
.LBE27:
.LBE35:
.LBE38:
	.loc 2 149 4 is_stmt 1 view .LVU337
.LBB39:
	.loc 2 153 6 view .LVU338
	.loc 2 154 6 view .LVU339
	.loc 2 154 19 is_stmt 0 view .LVU340
	movl	$0, 544(%rsp)
	.loc 2 157 6 is_stmt 1 view .LVU341
.LBB36:
	.loc 2 157 11 view .LVU342
	.loc 2 157 22 view .LVU343
	.loc 2 157 22 view .LVU344
	.loc 2 157 22 view .LVU345
	.loc 2 157 27 view .LVU346
	.loc 2 157 24 is_stmt 0 view .LVU347
	movq	72(%rsp), %rax
	.loc 2 157 18 view .LVU348
	movl	$1, 1072(%rsp)
	.loc 2 157 24 view .LVU349
	movq	%rax, 1080(%rsp)
	.loc 2 157 9 is_stmt 1 view .LVU350
.LBE36:
	.loc 2 162 7 view .LVU351
	.loc 2 162 7 is_stmt 0 view .LVU352
	jmp	.L82
.LVL118:
.L97:
	.loc 2 170 10 is_stmt 1 view .LVU353
	.loc 2 170 16 is_stmt 0 view .LVU354
	call	*__imp_WSAGetLastError(%rip)
.LVL119:
	.loc 2 170 16 view .LVU355
	leaq	.LC15(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL120:
	.loc 2 171 10 is_stmt 1 view .LVU356
	.loc 2 171 16 is_stmt 0 view .LVU357
	jmp	.L17
.LVL121:
.L92:
	.loc 2 171 16 view .LVU358
.LBE39:
	.loc 2 105 7 is_stmt 1 view .LVU359
	.loc 2 105 13 is_stmt 0 view .LVU360
	call	*__imp_WSAGetLastError(%rip)
.LVL122:
	leaq	.LC7(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL123:
	.loc 2 106 7 is_stmt 1 view .LVU361
	.loc 2 106 14 is_stmt 0 view .LVU362
	jmp	.L17
.L93:
	.loc 2 119 7 is_stmt 1 view .LVU363
	.loc 2 119 13 is_stmt 0 view .LVU364
	call	*__imp_WSAGetLastError(%rip)
.LVL124:
	leaq	.LC9(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL125:
	.loc 2 120 7 is_stmt 1 view .LVU365
	.loc 2 120 14 is_stmt 0 view .LVU366
	jmp	.L17
.L95:
	.loc 2 142 7 is_stmt 1 view .LVU367
	.loc 2 142 13 is_stmt 0 view .LVU368
	call	*__imp_WSAGetLastError(%rip)
.LVL126:
	leaq	.LC13(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL127:
	.loc 2 143 7 is_stmt 1 view .LVU369
	.loc 2 143 14 is_stmt 0 view .LVU370
	jmp	.L17
.LVL128:
.L102:
.LBB40:
	.loc 2 188 16 is_stmt 1 view .LVU371
	.loc 2 188 22 is_stmt 0 view .LVU372
	call	*__imp_WSAGetLastError(%rip)
.LVL129:
	leaq	.LC17(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL130:
	.loc 2 189 16 is_stmt 1 view .LVU373
	.loc 2 189 23 is_stmt 0 view .LVU374
	jmp	.L17
.L104:
	.loc 2 207 16 is_stmt 1 view .LVU375
	.loc 2 207 22 is_stmt 0 view .LVU376
	call	*__imp_WSAGetLastError(%rip)
.LVL131:
	leaq	.LC21(%rip), %rcx
	movl	%eax, %edx
	call	_Z6printfPKcz
.LVL132:
	.loc 2 208 16 is_stmt 1 view .LVU377
	.loc 2 208 23 is_stmt 0 view .LVU378
	jmp	.L17
.L103:
	.loc 2 196 18 is_stmt 1 view .LVU379
	.loc 2 196 24 is_stmt 0 view .LVU380
	leaq	.LC19(%rip), %rcx
	call	_Z6printfPKcz
.LVL133:
	.loc 2 197 18 is_stmt 1 view .LVU381
	.loc 2 197 25 is_stmt 0 view .LVU382
	jmp	.L17
.LBE40:
	.cfi_endproc
.LFE6017:
	.seh_endproc
	.globl	SocketArray
	.bss
	.align 32
SocketArray:
	.space 512
	.globl	TotalSockets
	.align 4
TotalSockets:
	.space 4
	.text
.Letext0:
	.file 3 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/crtdefs.h"
	.file 4 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/excpt.h"
	.file 5 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/minwindef.h"
	.file 6 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/ctype.h"
	.file 7 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/basetsd.h"
	.file 8 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/winnt.h"
	.file 9 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/guiddef.h"
	.file 10 "D:/Programs/mingw-w64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/cstdlib"
	.file 11 "D:/Programs/mingw-w64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/bits/std_abs.h"
	.file 12 "D:/Programs/mingw-w64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/x86_64-w64-mingw32/bits/c++config.h"
	.file 13 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/stdlib.h"
	.file 14 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/malloc.h"
	.file 15 "D:/Programs/mingw-w64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/stdlib.h"
	.file 16 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/minwinbase.h"
	.file 17 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/rpcdce.h"
	.file 18 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/wtypesbase.h"
	.file 19 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/unknwnbase.h"
	.file 20 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/objidlbase.h"
	.file 21 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/cguid.h"
	.file 22 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/wtypes.h"
	.file 23 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/objidl.h"
	.file 24 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/oleidl.h"
	.file 25 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/servprov.h"
	.file 26 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/oaidl.h"
	.file 27 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/msxml.h"
	.file 28 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/urlmon.h"
	.file 29 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/propidl.h"
	.file 30 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/oleauto.h"
	.file 31 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/winioctl.h"
	.file 32 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/winsmcrd.h"
	.file 33 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/winscard.h"
	.file 34 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/commdlg.h"
	.file 35 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/_bsd_types.h"
	.file 36 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/inaddr.h"
	.file 37 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/psdk_inc/_socket_types.h"
	.file 38 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/psdk_inc/_fd_types.h"
	.file 39 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/psdk_inc/_ip_types.h"
	.file 40 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/psdk_inc/_wsadata.h"
	.file 41 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/winsock2.h"
	.file 42 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/in6addr.h"
	.file 43 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/Ws2tcpip.h"
	.file 44 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/winbase.h"
	.file 45 "D:/Programs/mingw-w64/mingw64/x86_64-w64-mingw32/include/errhandlingapi.h"
	.file 46 "<built-in>"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0x6416
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C++17 8.1.0 -mtune=core2 -march=nocona -g -O2 -std=c++14 -std=gnu++2a -fmessage-length=0\0"
	.byte	0x4
	.ascii "..\\ts2.cpp\0"
	.ascii "D:\\\\Dev\\\\git\\\\Test01\\\\pjt01\\\\TS2\0"
	.secrel32	.Ldebug_ranges0+0x100
	.quad	0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.ascii "__builtin_va_list\0"
	.long	0xbe
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x4
	.long	0xbe
	.uleb128 0x5
	.ascii "size_t\0"
	.byte	0x3
	.byte	0x23
	.byte	0x2a
	.long	0xda
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x4
	.long	0x105
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x6
	.ascii "pthreadlocinfo\0"
	.byte	0x3
	.word	0x1a8
	.byte	0x28
	.long	0x14b
	.uleb128 0x7
	.byte	0x8
	.long	0x151
	.uleb128 0x8
	.ascii "threadlocaleinfostruct\0"
	.word	0x160
	.byte	0x3
	.word	0x1bc
	.byte	0x10
	.long	0x34b
	.uleb128 0x9
	.byte	0x20
	.byte	0x3
	.word	0x1c2
	.byte	0xa
	.long	0x1c3
	.uleb128 0xa
	.ascii "locale\0"
	.byte	0x3
	.word	0x1c3
	.byte	0xb
	.long	0x436
	.byte	0
	.uleb128 0xa
	.ascii "wlocale\0"
	.byte	0x3
	.word	0x1c4
	.byte	0xe
	.long	0x43c
	.byte	0x8
	.uleb128 0xb
	.secrel32	.LASF0
	.byte	0x3
	.word	0x1c5
	.byte	0xa
	.long	0x452
	.byte	0x10
	.uleb128 0xa
	.ascii "wrefcount\0"
	.byte	0x3
	.word	0x1c6
	.byte	0xa
	.long	0x452
	.byte	0x18
	.byte	0
	.uleb128 0xb
	.secrel32	.LASF0
	.byte	0x3
	.word	0x1bd
	.byte	0x7
	.long	0x120
	.byte	0
	.uleb128 0xa
	.ascii "lc_codepage\0"
	.byte	0x3
	.word	0x1be
	.byte	0x10
	.long	0x458
	.byte	0x4
	.uleb128 0xa
	.ascii "lc_collate_cp\0"
	.byte	0x3
	.word	0x1bf
	.byte	0x10
	.long	0x458
	.byte	0x8
	.uleb128 0xa
	.ascii "lc_handle\0"
	.byte	0x3
	.word	0x1c0
	.byte	0x1c
	.long	0x468
	.byte	0xc
	.uleb128 0xa
	.ascii "lc_id\0"
	.byte	0x3
	.word	0x1c1
	.byte	0x10
	.long	0x48d
	.byte	0x24
	.uleb128 0xa
	.ascii "lc_category\0"
	.byte	0x3
	.word	0x1c7
	.byte	0x12
	.long	0x49d
	.byte	0x48
	.uleb128 0xc
	.ascii "lc_clike\0"
	.byte	0x3
	.word	0x1c8
	.byte	0x7
	.long	0x120
	.word	0x108
	.uleb128 0xc
	.ascii "mb_cur_max\0"
	.byte	0x3
	.word	0x1c9
	.byte	0x7
	.long	0x120
	.word	0x10c
	.uleb128 0xc
	.ascii "lconv_intl_refcount\0"
	.byte	0x3
	.word	0x1ca
	.byte	0x8
	.long	0x452
	.word	0x110
	.uleb128 0xc
	.ascii "lconv_num_refcount\0"
	.byte	0x3
	.word	0x1cb
	.byte	0x8
	.long	0x452
	.word	0x118
	.uleb128 0xc
	.ascii "lconv_mon_refcount\0"
	.byte	0x3
	.word	0x1cc
	.byte	0x8
	.long	0x452
	.word	0x120
	.uleb128 0xc
	.ascii "lconv\0"
	.byte	0x3
	.word	0x1cd
	.byte	0x11
	.long	0x4b4
	.word	0x128
	.uleb128 0xc
	.ascii "ctype1_refcount\0"
	.byte	0x3
	.word	0x1ce
	.byte	0x8
	.long	0x452
	.word	0x130
	.uleb128 0xc
	.ascii "ctype1\0"
	.byte	0x3
	.word	0x1cf
	.byte	0x13
	.long	0x4ba
	.word	0x138
	.uleb128 0xc
	.ascii "pctype\0"
	.byte	0x3
	.word	0x1d0
	.byte	0x19
	.long	0x4c0
	.word	0x140
	.uleb128 0xc
	.ascii "pclmap\0"
	.byte	0x3
	.word	0x1d1
	.byte	0x18
	.long	0x4c6
	.word	0x148
	.uleb128 0xc
	.ascii "pcumap\0"
	.byte	0x3
	.word	0x1d2
	.byte	0x18
	.long	0x4c6
	.word	0x150
	.uleb128 0xc
	.ascii "lc_time_curr\0"
	.byte	0x3
	.word	0x1d3
	.byte	0x1a
	.long	0x4f2
	.word	0x158
	.byte	0
	.uleb128 0x6
	.ascii "pthreadmbcinfo\0"
	.byte	0x3
	.word	0x1a9
	.byte	0x25
	.long	0x363
	.uleb128 0x7
	.byte	0x8
	.long	0x369
	.uleb128 0xd
	.ascii "threadmbcinfostruct\0"
	.uleb128 0xe
	.ascii "localeinfo_struct\0"
	.byte	0x10
	.byte	0x3
	.word	0x1ac
	.byte	0x10
	.long	0x3bf
	.uleb128 0xa
	.ascii "locinfo\0"
	.byte	0x3
	.word	0x1ad
	.byte	0x12
	.long	0x133
	.byte	0
	.uleb128 0xa
	.ascii "mbcinfo\0"
	.byte	0x3
	.word	0x1ae
	.byte	0x12
	.long	0x34b
	.byte	0x8
	.byte	0
	.uleb128 0x6
	.ascii "_locale_tstruct\0"
	.byte	0x3
	.word	0x1af
	.byte	0x3
	.long	0x37e
	.uleb128 0xe
	.ascii "tagLC_ID\0"
	.byte	0x6
	.byte	0x3
	.word	0x1b3
	.byte	0x10
	.long	0x427
	.uleb128 0xa
	.ascii "wLanguage\0"
	.byte	0x3
	.word	0x1b4
	.byte	0x12
	.long	0x105
	.byte	0
	.uleb128 0xa
	.ascii "wCountry\0"
	.byte	0x3
	.word	0x1b5
	.byte	0x12
	.long	0x105
	.byte	0x2
	.uleb128 0xa
	.ascii "wCodePage\0"
	.byte	0x3
	.word	0x1b6
	.byte	0x12
	.long	0x105
	.byte	0x4
	.byte	0
	.uleb128 0x6
	.ascii "LC_ID\0"
	.byte	0x3
	.word	0x1b7
	.byte	0x3
	.long	0x3d8
	.uleb128 0x7
	.byte	0x8
	.long	0xbe
	.uleb128 0x7
	.byte	0x8
	.long	0x442
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.ascii "wchar_t\0"
	.uleb128 0x4
	.long	0x442
	.uleb128 0x7
	.byte	0x8
	.long	0x120
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0xf
	.long	0x478
	.long	0x478
	.uleb128 0x10
	.long	0xda
	.byte	0x5
	.byte	0
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.ascii "long unsigned int\0"
	.uleb128 0xf
	.long	0x427
	.long	0x49d
	.uleb128 0x10
	.long	0xda
	.byte	0x5
	.byte	0
	.uleb128 0xf
	.long	0x173
	.long	0x4ad
	.uleb128 0x10
	.long	0xda
	.byte	0x5
	.byte	0
	.uleb128 0xd
	.ascii "lconv\0"
	.uleb128 0x7
	.byte	0x8
	.long	0x4ad
	.uleb128 0x7
	.byte	0x8
	.long	0x105
	.uleb128 0x7
	.byte	0x8
	.long	0x11b
	.uleb128 0x7
	.byte	0x8
	.long	0x4dd
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0x4
	.long	0x4cc
	.uleb128 0xd
	.ascii "__lc_time_data\0"
	.uleb128 0x7
	.byte	0x8
	.long	0x4e2
	.uleb128 0x5
	.ascii "_PHNDLR\0"
	.byte	0x4
	.byte	0x3f
	.byte	0x2e
	.long	0x508
	.uleb128 0x7
	.byte	0x8
	.long	0x50e
	.uleb128 0x11
	.long	0x519
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x13
	.ascii "_XCPT_ACTION\0"
	.byte	0x10
	.byte	0x4
	.byte	0x41
	.byte	0xa
	.long	0x565
	.uleb128 0x14
	.ascii "XcptNum\0"
	.byte	0x4
	.byte	0x42
	.byte	0x13
	.long	0x478
	.byte	0
	.uleb128 0x14
	.ascii "SigNum\0"
	.byte	0x4
	.byte	0x43
	.byte	0x9
	.long	0x120
	.byte	0x4
	.uleb128 0x14
	.ascii "XcptAction\0"
	.byte	0x4
	.byte	0x44
	.byte	0xd
	.long	0x4f8
	.byte	0x8
	.byte	0
	.uleb128 0xf
	.long	0x519
	.long	0x570
	.uleb128 0x15
	.byte	0
	.uleb128 0x16
	.ascii "_XcptActTab\0"
	.byte	0x4
	.byte	0x47
	.byte	0x1e
	.long	0x565
	.uleb128 0x16
	.ascii "_XcptActTabCount\0"
	.byte	0x4
	.byte	0x48
	.byte	0xe
	.long	0x120
	.uleb128 0x16
	.ascii "_XcptActTabSize\0"
	.byte	0x4
	.byte	0x49
	.byte	0xe
	.long	0x120
	.uleb128 0x16
	.ascii "_First_FPE_Indx\0"
	.byte	0x4
	.byte	0x4a
	.byte	0xe
	.long	0x120
	.uleb128 0x16
	.ascii "_Num_FPE\0"
	.byte	0x4
	.byte	0x4b
	.byte	0xe
	.long	0x120
	.uleb128 0x17
	.byte	0x8
	.uleb128 0x5
	.ascii "ULONG\0"
	.byte	0x5
	.byte	0x18
	.byte	0x19
	.long	0x478
	.uleb128 0x5
	.ascii "BOOL\0"
	.byte	0x5
	.byte	0x83
	.byte	0xf
	.long	0x120
	.uleb128 0x5
	.ascii "WORD\0"
	.byte	0x5
	.byte	0x8c
	.byte	0x1a
	.long	0x105
	.uleb128 0x5
	.ascii "DWORD\0"
	.byte	0x5
	.byte	0x8d
	.byte	0x19
	.long	0x478
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.ascii "float\0"
	.uleb128 0x7
	.byte	0x8
	.long	0x625
	.uleb128 0x18
	.uleb128 0x7
	.byte	0x8
	.long	0x458
	.uleb128 0x16
	.ascii "__imp__pctype\0"
	.byte	0x6
	.byte	0x2b
	.byte	0x1c
	.long	0x642
	.uleb128 0x7
	.byte	0x8
	.long	0x4ba
	.uleb128 0x16
	.ascii "__imp__wctype\0"
	.byte	0x6
	.byte	0x3b
	.byte	0x1c
	.long	0x642
	.uleb128 0x16
	.ascii "__imp__pwctype\0"
	.byte	0x6
	.byte	0x47
	.byte	0x1c
	.long	0x642
	.uleb128 0xf
	.long	0x4dd
	.long	0x680
	.uleb128 0x15
	.byte	0
	.uleb128 0x16
	.ascii "__newclmap\0"
	.byte	0x6
	.byte	0x50
	.byte	0x1e
	.long	0x675
	.uleb128 0x16
	.ascii "__newcumap\0"
	.byte	0x6
	.byte	0x51
	.byte	0x1e
	.long	0x675
	.uleb128 0x16
	.ascii "__ptlocinfo\0"
	.byte	0x6
	.byte	0x52
	.byte	0x19
	.long	0x133
	.uleb128 0x16
	.ascii "__ptmbcinfo\0"
	.byte	0x6
	.byte	0x53
	.byte	0x19
	.long	0x34b
	.uleb128 0x16
	.ascii "__globallocalestatus\0"
	.byte	0x6
	.byte	0x54
	.byte	0xe
	.long	0x120
	.uleb128 0x16
	.ascii "__locale_changed\0"
	.byte	0x6
	.byte	0x55
	.byte	0xe
	.long	0x120
	.uleb128 0x16
	.ascii "__initiallocinfo\0"
	.byte	0x6
	.byte	0x56
	.byte	0x28
	.long	0x151
	.uleb128 0x16
	.ascii "__initiallocalestructinfo\0"
	.byte	0x6
	.byte	0x57
	.byte	0x1a
	.long	0x3bf
	.uleb128 0x16
	.ascii "__imp___mb_cur_max\0"
	.byte	0x6
	.byte	0xcb
	.byte	0x10
	.long	0x452
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.ascii "signed char\0"
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.ascii "short int\0"
	.uleb128 0x5
	.ascii "UINT_PTR\0"
	.byte	0x7
	.byte	0x2f
	.byte	0x2c
	.long	0xda
	.uleb128 0x5
	.ascii "ULONG_PTR\0"
	.byte	0x7
	.byte	0x31
	.byte	0x2c
	.long	0xda
	.uleb128 0x6
	.ascii "PVOID\0"
	.byte	0x8
	.word	0x101
	.byte	0x11
	.long	0x5de
	.uleb128 0x6
	.ascii "CHAR\0"
	.byte	0x8
	.word	0x11d
	.byte	0x10
	.long	0xbe
	.uleb128 0x6
	.ascii "HANDLE\0"
	.byte	0x8
	.word	0x195
	.byte	0x11
	.long	0x5de
	.uleb128 0x13
	.ascii "_GUID\0"
	.byte	0x10
	.byte	0x9
	.byte	0x13
	.byte	0x10
	.long	0x812
	.uleb128 0x14
	.ascii "Data1\0"
	.byte	0x9
	.byte	0x14
	.byte	0x11
	.long	0x478
	.byte	0
	.uleb128 0x14
	.ascii "Data2\0"
	.byte	0x9
	.byte	0x15
	.byte	0x12
	.long	0x105
	.byte	0x4
	.uleb128 0x14
	.ascii "Data3\0"
	.byte	0x9
	.byte	0x16
	.byte	0x12
	.long	0x105
	.byte	0x6
	.uleb128 0x14
	.ascii "Data4\0"
	.byte	0x9
	.byte	0x17
	.byte	0x18
	.long	0x812
	.byte	0x8
	.byte	0
	.uleb128 0xf
	.long	0x4cc
	.long	0x822
	.uleb128 0x10
	.long	0xda
	.byte	0x7
	.byte	0
	.uleb128 0x5
	.ascii "GUID\0"
	.byte	0x9
	.byte	0x18
	.byte	0x3
	.long	0x7c6
	.uleb128 0x4
	.long	0x822
	.uleb128 0x5
	.ascii "IID\0"
	.byte	0x9
	.byte	0x53
	.byte	0xe
	.long	0x822
	.uleb128 0x4
	.long	0x834
	.uleb128 0x5
	.ascii "CLSID\0"
	.byte	0x9
	.byte	0x5b
	.byte	0xe
	.long	0x822
	.uleb128 0x4
	.long	0x845
	.uleb128 0x5
	.ascii "FMTID\0"
	.byte	0x9
	.byte	0x62
	.byte	0xe
	.long	0x822
	.uleb128 0x4
	.long	0x858
	.uleb128 0x19
	.ascii "std\0"
	.byte	0x2e
	.byte	0
	.long	0xa8f
	.uleb128 0x1a
	.ascii "__cxx11\0"
	.byte	0xc
	.word	0x104
	.byte	0x41
	.uleb128 0x1b
	.byte	0xc
	.word	0x104
	.byte	0x41
	.long	0x876
	.uleb128 0x1c
	.byte	0xa
	.byte	0x7f
	.byte	0xb
	.long	0xb59
	.uleb128 0x1c
	.byte	0xa
	.byte	0x80
	.byte	0xb
	.long	0xb94
	.uleb128 0x1c
	.byte	0xa
	.byte	0x86
	.byte	0xb
	.long	0xd89
	.uleb128 0x1c
	.byte	0xa
	.byte	0x8c
	.byte	0xb
	.long	0xda3
	.uleb128 0x1c
	.byte	0xa
	.byte	0x8d
	.byte	0xb
	.long	0xdc1
	.uleb128 0x1c
	.byte	0xa
	.byte	0x8e
	.byte	0xb
	.long	0xdd9
	.uleb128 0x1c
	.byte	0xa
	.byte	0x8f
	.byte	0xb
	.long	0xdf1
	.uleb128 0x1c
	.byte	0xa
	.byte	0x91
	.byte	0xb
	.long	0xe3a
	.uleb128 0x1c
	.byte	0xa
	.byte	0x94
	.byte	0xb
	.long	0xe56
	.uleb128 0x1c
	.byte	0xa
	.byte	0x96
	.byte	0xb
	.long	0xe70
	.uleb128 0x1c
	.byte	0xa
	.byte	0x99
	.byte	0xb
	.long	0xe8d
	.uleb128 0x1c
	.byte	0xa
	.byte	0x9a
	.byte	0xb
	.long	0xeab
	.uleb128 0x1c
	.byte	0xa
	.byte	0x9b
	.byte	0xb
	.long	0xed1
	.uleb128 0x1c
	.byte	0xa
	.byte	0x9d
	.byte	0xb
	.long	0xef5
	.uleb128 0x1c
	.byte	0xa
	.byte	0xa3
	.byte	0xb
	.long	0xf19
	.uleb128 0x1c
	.byte	0xa
	.byte	0xa5
	.byte	0xb
	.long	0xf27
	.uleb128 0x1c
	.byte	0xa
	.byte	0xa6
	.byte	0xb
	.long	0xf3c
	.uleb128 0x1c
	.byte	0xa
	.byte	0xa7
	.byte	0xb
	.long	0xf5b
	.uleb128 0x1c
	.byte	0xa
	.byte	0xa8
	.byte	0xb
	.long	0xf7f
	.uleb128 0x1c
	.byte	0xa
	.byte	0xa9
	.byte	0xb
	.long	0xfa4
	.uleb128 0x1c
	.byte	0xa
	.byte	0xab
	.byte	0xb
	.long	0xfbe
	.uleb128 0x1c
	.byte	0xa
	.byte	0xac
	.byte	0xb
	.long	0xfe4
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf0
	.byte	0x16
	.long	0xd66
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf2
	.byte	0x16
	.long	0x1003
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf4
	.byte	0x16
	.long	0x1018
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf5
	.byte	0x16
	.long	0xb00
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf6
	.byte	0x16
	.long	0x1031
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf8
	.byte	0x16
	.long	0x104f
	.uleb128 0x1c
	.byte	0xa
	.byte	0xf9
	.byte	0x16
	.long	0x10b3
	.uleb128 0x1c
	.byte	0xa
	.byte	0xfa
	.byte	0x16
	.long	0x1068
	.uleb128 0x1c
	.byte	0xa
	.byte	0xfb
	.byte	0x16
	.long	0x108d
	.uleb128 0x1c
	.byte	0xa
	.byte	0xfc
	.byte	0x16
	.long	0x10d2
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x66
	.byte	0x3
	.ascii "_ZSt3absg\0"
	.long	0x1129
	.long	0x9ac
	.uleb128 0x12
	.long	0x1129
	.byte	0
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x54
	.byte	0x3
	.ascii "_ZSt3absn\0"
	.long	0x113f
	.long	0x9cc
	.uleb128 0x12
	.long	0x113f
	.byte	0
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x4e
	.byte	0x3
	.ascii "_ZSt3abse\0"
	.long	0xbad
	.long	0x9ec
	.uleb128 0x12
	.long	0xbad
	.byte	0
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x4a
	.byte	0x3
	.ascii "_ZSt3absf\0"
	.long	0x616
	.long	0xa0c
	.uleb128 0x12
	.long	0x616
	.byte	0
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x46
	.byte	0x3
	.ascii "_ZSt3absd\0"
	.long	0xba3
	.long	0xa2c
	.uleb128 0x12
	.long	0xba3
	.byte	0
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x3d
	.byte	0x3
	.ascii "_ZSt3absx\0"
	.long	0xf4
	.long	0xa4c
	.uleb128 0x12
	.long	0xf4
	.byte	0
	.uleb128 0x1d
	.ascii "abs\0"
	.byte	0xb
	.byte	0x38
	.byte	0x3
	.ascii "_ZSt3absl\0"
	.long	0x127
	.long	0xa6c
	.uleb128 0x12
	.long	0x127
	.byte	0
	.uleb128 0x1e
	.ascii "div\0"
	.byte	0xa
	.byte	0xb1
	.byte	0x3
	.ascii "_ZSt3divll\0"
	.long	0xb94
	.uleb128 0x12
	.long	0x127
	.uleb128 0x12
	.long	0x127
	.byte	0
	.byte	0
	.uleb128 0x1f
	.ascii "__gnu_cxx\0"
	.byte	0xc
	.word	0x106
	.byte	0xb
	.long	0xb2d
	.uleb128 0x1a
	.ascii "__cxx11\0"
	.byte	0xc
	.word	0x108
	.byte	0x41
	.uleb128 0x1b
	.byte	0xc
	.word	0x108
	.byte	0x41
	.long	0xaa2
	.uleb128 0x1c
	.byte	0xa
	.byte	0xc8
	.byte	0xb
	.long	0xd66
	.uleb128 0x1c
	.byte	0xa
	.byte	0xce
	.byte	0xb
	.long	0x1003
	.uleb128 0x1c
	.byte	0xa
	.byte	0xd2
	.byte	0xb
	.long	0x1018
	.uleb128 0x1c
	.byte	0xa
	.byte	0xd8
	.byte	0xb
	.long	0x1031
	.uleb128 0x1c
	.byte	0xa
	.byte	0xe3
	.byte	0xb
	.long	0x104f
	.uleb128 0x1c
	.byte	0xa
	.byte	0xe4
	.byte	0xb
	.long	0x1068
	.uleb128 0x1c
	.byte	0xa
	.byte	0xe5
	.byte	0xb
	.long	0x108d
	.uleb128 0x1c
	.byte	0xa
	.byte	0xe7
	.byte	0xb
	.long	0x10b3
	.uleb128 0x1c
	.byte	0xa
	.byte	0xe8
	.byte	0xb
	.long	0x10d2
	.uleb128 0x1e
	.ascii "div\0"
	.byte	0xa
	.byte	0xd5
	.byte	0x3
	.ascii "_ZN9__gnu_cxx3divExx\0"
	.long	0xd66
	.uleb128 0x12
	.long	0xf4
	.uleb128 0x12
	.long	0xf4
	.byte	0
	.byte	0
	.uleb128 0x13
	.ascii "_div_t\0"
	.byte	0x8
	.byte	0xd
	.byte	0x3b
	.byte	0x12
	.long	0xb59
	.uleb128 0x14
	.ascii "quot\0"
	.byte	0xd
	.byte	0x3c
	.byte	0x9
	.long	0x120
	.byte	0
	.uleb128 0x14
	.ascii "rem\0"
	.byte	0xd
	.byte	0x3d
	.byte	0x9
	.long	0x120
	.byte	0x4
	.byte	0
	.uleb128 0x5
	.ascii "div_t\0"
	.byte	0xd
	.byte	0x3e
	.byte	0x5
	.long	0xb2d
	.uleb128 0x13
	.ascii "_ldiv_t\0"
	.byte	0x8
	.byte	0xd
	.byte	0x40
	.byte	0x12
	.long	0xb94
	.uleb128 0x14
	.ascii "quot\0"
	.byte	0xd
	.byte	0x41
	.byte	0xa
	.long	0x127
	.byte	0
	.uleb128 0x14
	.ascii "rem\0"
	.byte	0xd
	.byte	0x42
	.byte	0xa
	.long	0x127
	.byte	0x4
	.byte	0
	.uleb128 0x5
	.ascii "ldiv_t\0"
	.byte	0xd
	.byte	0x43
	.byte	0x5
	.long	0xb67
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.ascii "double\0"
	.uleb128 0x3
	.byte	0x10
	.byte	0x4
	.ascii "long double\0"
	.uleb128 0x7
	.byte	0x8
	.long	0xbc2
	.uleb128 0x20
	.uleb128 0x7
	.byte	0x8
	.long	0x44d
	.uleb128 0xf
	.long	0x436
	.long	0xbd9
	.uleb128 0x10
	.long	0xda
	.byte	0
	.byte	0
	.uleb128 0x16
	.ascii "_sys_errlist\0"
	.byte	0xd
	.byte	0xac
	.byte	0x2b
	.long	0xbc9
	.uleb128 0x16
	.ascii "_sys_nerr\0"
	.byte	0xd
	.byte	0xad
	.byte	0x29
	.long	0x120
	.uleb128 0x21
	.ascii "__imp___argc\0"
	.byte	0xd
	.word	0x119
	.byte	0x10
	.long	0x452
	.uleb128 0x21
	.ascii "__imp___argv\0"
	.byte	0xd
	.word	0x11d
	.byte	0x13
	.long	0xc2c
	.uleb128 0x7
	.byte	0x8
	.long	0xc32
	.uleb128 0x7
	.byte	0x8
	.long	0x436
	.uleb128 0x21
	.ascii "__imp___wargv\0"
	.byte	0xd
	.word	0x121
	.byte	0x16
	.long	0xc4f
	.uleb128 0x7
	.byte	0x8
	.long	0xc55
	.uleb128 0x7
	.byte	0x8
	.long	0x43c
	.uleb128 0x21
	.ascii "__imp__environ\0"
	.byte	0xd
	.word	0x127
	.byte	0x13
	.long	0xc2c
	.uleb128 0x21
	.ascii "__imp__wenviron\0"
	.byte	0xd
	.word	0x12c
	.byte	0x16
	.long	0xc4f
	.uleb128 0x21
	.ascii "__imp__pgmptr\0"
	.byte	0xd
	.word	0x132
	.byte	0x12
	.long	0xc32
	.uleb128 0x21
	.ascii "__imp__wpgmptr\0"
	.byte	0xd
	.word	0x137
	.byte	0x15
	.long	0xc55
	.uleb128 0x21
	.ascii "__imp__osplatform\0"
	.byte	0xd
	.word	0x13c
	.byte	0x19
	.long	0x626
	.uleb128 0x21
	.ascii "__imp__osver\0"
	.byte	0xd
	.word	0x141
	.byte	0x19
	.long	0x626
	.uleb128 0x21
	.ascii "__imp__winver\0"
	.byte	0xd
	.word	0x146
	.byte	0x19
	.long	0x626
	.uleb128 0x21
	.ascii "__imp__winmajor\0"
	.byte	0xd
	.word	0x14b
	.byte	0x19
	.long	0x626
	.uleb128 0x21
	.ascii "__imp__winminor\0"
	.byte	0xd
	.word	0x150
	.byte	0x19
	.long	0x626
	.uleb128 0x22
	.byte	0x10
	.byte	0xd
	.word	0x2bb
	.byte	0x12
	.ascii "7lldiv_t\0"
	.long	0xd66
	.uleb128 0xa
	.ascii "quot\0"
	.byte	0xd
	.word	0x2bb
	.byte	0x2c
	.long	0xf4
	.byte	0
	.uleb128 0xa
	.ascii "rem\0"
	.byte	0xd
	.word	0x2bb
	.byte	0x32
	.long	0xf4
	.byte	0x8
	.byte	0
	.uleb128 0x6
	.ascii "lldiv_t\0"
	.byte	0xd
	.word	0x2bb
	.byte	0x39
	.long	0xd35
	.uleb128 0x16
	.ascii "_amblksiz\0"
	.byte	0xe
	.byte	0x35
	.byte	0x17
	.long	0x458
	.uleb128 0x23
	.ascii "atexit\0"
	.byte	0xd
	.word	0x18a
	.byte	0x22
	.long	0x120
	.long	0xda3
	.uleb128 0x12
	.long	0xbbc
	.byte	0
	.uleb128 0x23
	.ascii "atof\0"
	.byte	0xd
	.word	0x18d
	.byte	0x25
	.long	0xba3
	.long	0xdbb
	.uleb128 0x12
	.long	0xdbb
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.long	0xc6
	.uleb128 0x23
	.ascii "atoi\0"
	.byte	0xd
	.word	0x190
	.byte	0x22
	.long	0x120
	.long	0xdd9
	.uleb128 0x12
	.long	0xdbb
	.byte	0
	.uleb128 0x23
	.ascii "atol\0"
	.byte	0xd
	.word	0x192
	.byte	0x23
	.long	0x127
	.long	0xdf1
	.uleb128 0x12
	.long	0xdbb
	.byte	0
	.uleb128 0x23
	.ascii "bsearch\0"
	.byte	0xd
	.word	0x196
	.byte	0x24
	.long	0x5de
	.long	0xe20
	.uleb128 0x12
	.long	0x61f
	.uleb128 0x12
	.long	0x61f
	.uleb128 0x12
	.long	0xcb
	.uleb128 0x12
	.long	0xcb
	.uleb128 0x12
	.long	0xe20
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.long	0xe26
	.uleb128 0x24
	.long	0x120
	.long	0xe3a
	.uleb128 0x12
	.long	0x61f
	.uleb128 0x12
	.long	0x61f
	.byte	0
	.uleb128 0x23
	.ascii "div\0"
	.byte	0xd
	.word	0x19c
	.byte	0x24
	.long	0xb59
	.long	0xe56
	.uleb128 0x12
	.long	0x120
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x23
	.ascii "getenv\0"
	.byte	0xd
	.word	0x19d
	.byte	0x24
	.long	0x436
	.long	0xe70
	.uleb128 0x12
	.long	0xdbb
	.byte	0
	.uleb128 0x23
	.ascii "ldiv\0"
	.byte	0xd
	.word	0x1a7
	.byte	0x25
	.long	0xb94
	.long	0xe8d
	.uleb128 0x12
	.long	0x127
	.uleb128 0x12
	.long	0x127
	.byte	0
	.uleb128 0x23
	.ascii "mblen\0"
	.byte	0xd
	.word	0x1a9
	.byte	0x22
	.long	0x120
	.long	0xeab
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xcb
	.byte	0
	.uleb128 0x23
	.ascii "mbstowcs\0"
	.byte	0xd
	.word	0x1b1
	.byte	0x25
	.long	0xcb
	.long	0xed1
	.uleb128 0x12
	.long	0x43c
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xcb
	.byte	0
	.uleb128 0x23
	.ascii "mbtowc\0"
	.byte	0xd
	.word	0x1af
	.byte	0x22
	.long	0x120
	.long	0xef5
	.uleb128 0x12
	.long	0x43c
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xcb
	.byte	0
	.uleb128 0x25
	.ascii "qsort\0"
	.byte	0xd
	.word	0x197
	.byte	0x23
	.long	0xf19
	.uleb128 0x12
	.long	0x5de
	.uleb128 0x12
	.long	0xcb
	.uleb128 0x12
	.long	0xcb
	.uleb128 0x12
	.long	0xe20
	.byte	0
	.uleb128 0x26
	.ascii "rand\0"
	.byte	0xd
	.word	0x1b4
	.byte	0x22
	.long	0x120
	.uleb128 0x25
	.ascii "srand\0"
	.byte	0xd
	.word	0x1b6
	.byte	0x23
	.long	0xf3c
	.uleb128 0x12
	.long	0x458
	.byte	0
	.uleb128 0x23
	.ascii "strtod\0"
	.byte	0xd
	.word	0x1c2
	.byte	0x41
	.long	0xba3
	.long	0xf5b
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.byte	0
	.uleb128 0x23
	.ascii "strtol\0"
	.byte	0xd
	.word	0x1e5
	.byte	0x23
	.long	0x127
	.long	0xf7f
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x23
	.ascii "strtoul\0"
	.byte	0xd
	.word	0x1e7
	.byte	0x2c
	.long	0x478
	.long	0xfa4
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x23
	.ascii "system\0"
	.byte	0xd
	.word	0x1eb
	.byte	0x22
	.long	0x120
	.long	0xfbe
	.uleb128 0x12
	.long	0xdbb
	.byte	0
	.uleb128 0x23
	.ascii "wcstombs\0"
	.byte	0xd
	.word	0x1f0
	.byte	0x25
	.long	0xcb
	.long	0xfe4
	.uleb128 0x12
	.long	0x436
	.uleb128 0x12
	.long	0xbc3
	.uleb128 0x12
	.long	0xcb
	.byte	0
	.uleb128 0x23
	.ascii "wctomb\0"
	.byte	0xd
	.word	0x1ee
	.byte	0x22
	.long	0x120
	.long	0x1003
	.uleb128 0x12
	.long	0x436
	.uleb128 0x12
	.long	0x442
	.byte	0
	.uleb128 0x27
	.ascii "_Exit\0"
	.byte	0xd
	.word	0x16f
	.byte	0x49
	.long	0x1018
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x23
	.ascii "llabs\0"
	.byte	0xd
	.word	0x2c1
	.byte	0x3d
	.long	0xf4
	.long	0x1031
	.uleb128 0x12
	.long	0xf4
	.byte	0
	.uleb128 0x23
	.ascii "lldiv\0"
	.byte	0xd
	.word	0x2bd
	.byte	0x34
	.long	0xd66
	.long	0x104f
	.uleb128 0x12
	.long	0xf4
	.uleb128 0x12
	.long	0xf4
	.byte	0
	.uleb128 0x23
	.ascii "atoll\0"
	.byte	0xd
	.word	0x2d3
	.byte	0x3d
	.long	0xf4
	.long	0x1068
	.uleb128 0x12
	.long	0xdbb
	.byte	0
	.uleb128 0x23
	.ascii "strtoll\0"
	.byte	0xd
	.word	0x2c4
	.byte	0x36
	.long	0xf4
	.long	0x108d
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x23
	.ascii "strtoull\0"
	.byte	0xd
	.word	0x2c5
	.byte	0x3f
	.long	0xda
	.long	0x10b3
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x23
	.ascii "strtof\0"
	.byte	0xd
	.word	0x1c9
	.byte	0x40
	.long	0x616
	.long	0x10d2
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.byte	0
	.uleb128 0x23
	.ascii "strtold\0"
	.byte	0xd
	.word	0x1d4
	.byte	0x48
	.long	0xbad
	.long	0x10f2
	.uleb128 0x12
	.long	0xdbb
	.uleb128 0x12
	.long	0xc32
	.byte	0
	.uleb128 0x1c
	.byte	0xf
	.byte	0x27
	.byte	0xc
	.long	0xd89
	.uleb128 0x1c
	.byte	0xf
	.byte	0x33
	.byte	0xc
	.long	0xb59
	.uleb128 0x1c
	.byte	0xf
	.byte	0x34
	.byte	0xc
	.long	0xb94
	.uleb128 0x23
	.ascii "abs\0"
	.byte	0xd
	.word	0x17f
	.byte	0x22
	.long	0x120
	.long	0x1121
	.uleb128 0x12
	.long	0x120
	.byte	0
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0x110a
	.uleb128 0x3
	.byte	0x10
	.byte	0x4
	.ascii "__float128\0"
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0x98c
	.uleb128 0x3
	.byte	0x10
	.byte	0x5
	.ascii "__int128\0"
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0x9ac
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0x9cc
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0x9ec
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0xa0c
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0xa2c
	.uleb128 0x1c
	.byte	0xf
	.byte	0x36
	.byte	0xc
	.long	0xa4c
	.uleb128 0x1c
	.byte	0xf
	.byte	0x37
	.byte	0xc
	.long	0xda3
	.uleb128 0x1c
	.byte	0xf
	.byte	0x38
	.byte	0xc
	.long	0xdc1
	.uleb128 0x1c
	.byte	0xf
	.byte	0x39
	.byte	0xc
	.long	0xdd9
	.uleb128 0x1c
	.byte	0xf
	.byte	0x3a
	.byte	0xc
	.long	0xdf1
	.uleb128 0x1c
	.byte	0xf
	.byte	0x3c
	.byte	0xc
	.long	0xb00
	.uleb128 0x1c
	.byte	0xf
	.byte	0x3c
	.byte	0xc
	.long	0xe3a
	.uleb128 0x1c
	.byte	0xf
	.byte	0x3c
	.byte	0xc
	.long	0xa6c
	.uleb128 0x1c
	.byte	0xf
	.byte	0x3e
	.byte	0xc
	.long	0xe56
	.uleb128 0x1c
	.byte	0xf
	.byte	0x40
	.byte	0xc
	.long	0xe70
	.uleb128 0x1c
	.byte	0xf
	.byte	0x43
	.byte	0xc
	.long	0xe8d
	.uleb128 0x1c
	.byte	0xf
	.byte	0x44
	.byte	0xc
	.long	0xeab
	.uleb128 0x1c
	.byte	0xf
	.byte	0x45
	.byte	0xc
	.long	0xed1
	.uleb128 0x1c
	.byte	0xf
	.byte	0x47
	.byte	0xc
	.long	0xef5
	.uleb128 0x1c
	.byte	0xf
	.byte	0x48
	.byte	0xc
	.long	0xf19
	.uleb128 0x1c
	.byte	0xf
	.byte	0x4a
	.byte	0xc
	.long	0xf27
	.uleb128 0x1c
	.byte	0xf
	.byte	0x4b
	.byte	0xc
	.long	0xf3c
	.uleb128 0x1c
	.byte	0xf
	.byte	0x4c
	.byte	0xc
	.long	0xf5b
	.uleb128 0x1c
	.byte	0xf
	.byte	0x4d
	.byte	0xc
	.long	0xf7f
	.uleb128 0x1c
	.byte	0xf
	.byte	0x4e
	.byte	0xc
	.long	0xfa4
	.uleb128 0x1c
	.byte	0xf
	.byte	0x50
	.byte	0xc
	.long	0xfbe
	.uleb128 0x1c
	.byte	0xf
	.byte	0x51
	.byte	0xc
	.long	0xfe4
	.uleb128 0x21
	.ascii "GUID_MAX_POWER_SAVINGS\0"
	.byte	0x8
	.word	0x13a9
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_MIN_POWER_SAVINGS\0"
	.byte	0x8
	.word	0x13aa
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_TYPICAL_POWER_SAVINGS\0"
	.byte	0x8
	.word	0x13ab
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "NO_SUBGROUP_GUID\0"
	.byte	0x8
	.word	0x13ac
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "ALL_POWERSCHEMES_GUID\0"
	.byte	0x8
	.word	0x13ad
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_POWERSCHEME_PERSONALITY\0"
	.byte	0x8
	.word	0x13ae
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ACTIVE_POWERSCHEME\0"
	.byte	0x8
	.word	0x13af
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_IDLE_RESILIENCY_SUBGROUP\0"
	.byte	0x8
	.word	0x13b0
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_IDLE_RESILIENCY_PERIOD\0"
	.byte	0x8
	.word	0x13b1
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DISK_COALESCING_POWERDOWN_TIMEOUT\0"
	.byte	0x8
	.word	0x13b2
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_EXECUTION_REQUIRED_REQUEST_TIMEOUT\0"
	.byte	0x8
	.word	0x13b3
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_SUBGROUP\0"
	.byte	0x8
	.word	0x13b4
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_POWERDOWN_TIMEOUT\0"
	.byte	0x8
	.word	0x13b5
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_ANNOYANCE_TIMEOUT\0"
	.byte	0x8
	.word	0x13b6
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE\0"
	.byte	0x8
	.word	0x13b7
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_DIM_TIMEOUT\0"
	.byte	0x8
	.word	0x13b8
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_ADAPTIVE_POWERDOWN\0"
	.byte	0x8
	.word	0x13b9
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_MONITOR_POWER_ON\0"
	.byte	0x8
	.word	0x13ba
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS\0"
	.byte	0x8
	.word	0x13bb
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS\0"
	.byte	0x8
	.word	0x13bc
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS\0"
	.byte	0x8
	.word	0x13bd
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS\0"
	.byte	0x8
	.word	0x13be
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_CONSOLE_DISPLAY_STATE\0"
	.byte	0x8
	.word	0x13bf
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ALLOW_DISPLAY_REQUIRED\0"
	.byte	0x8
	.word	0x13c0
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_VIDEO_CONSOLE_LOCK_TIMEOUT\0"
	.byte	0x8
	.word	0x13c1
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ADAPTIVE_POWER_BEHAVIOR_SUBGROUP\0"
	.byte	0x8
	.word	0x13c2
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_NON_ADAPTIVE_INPUT_TIMEOUT\0"
	.byte	0x8
	.word	0x13c3
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DISK_SUBGROUP\0"
	.byte	0x8
	.word	0x13c4
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DISK_POWERDOWN_TIMEOUT\0"
	.byte	0x8
	.word	0x13c5
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DISK_IDLE_TIMEOUT\0"
	.byte	0x8
	.word	0x13c6
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DISK_BURST_IGNORE_THRESHOLD\0"
	.byte	0x8
	.word	0x13c7
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DISK_ADAPTIVE_POWERDOWN\0"
	.byte	0x8
	.word	0x13c8
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SLEEP_SUBGROUP\0"
	.byte	0x8
	.word	0x13c9
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SLEEP_IDLE_THRESHOLD\0"
	.byte	0x8
	.word	0x13ca
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_STANDBY_TIMEOUT\0"
	.byte	0x8
	.word	0x13cb
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_UNATTEND_SLEEP_TIMEOUT\0"
	.byte	0x8
	.word	0x13cc
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_HIBERNATE_TIMEOUT\0"
	.byte	0x8
	.word	0x13cd
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_HIBERNATE_FASTS4_POLICY\0"
	.byte	0x8
	.word	0x13ce
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_CRITICAL_POWER_TRANSITION\0"
	.byte	0x8
	.word	0x13cf
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SYSTEM_AWAYMODE\0"
	.byte	0x8
	.word	0x13d0
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ALLOW_AWAYMODE\0"
	.byte	0x8
	.word	0x13d1
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ALLOW_STANDBY_STATES\0"
	.byte	0x8
	.word	0x13d2
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ALLOW_RTC_WAKE\0"
	.byte	0x8
	.word	0x13d3
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ALLOW_SYSTEM_REQUIRED\0"
	.byte	0x8
	.word	0x13d4
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SYSTEM_BUTTON_SUBGROUP\0"
	.byte	0x8
	.word	0x13d5
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_POWERBUTTON_ACTION\0"
	.byte	0x8
	.word	0x13d6
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SLEEPBUTTON_ACTION\0"
	.byte	0x8
	.word	0x13d7
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_USERINTERFACEBUTTON_ACTION\0"
	.byte	0x8
	.word	0x13d8
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_LIDCLOSE_ACTION\0"
	.byte	0x8
	.word	0x13d9
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_LIDOPEN_POWERSTATE\0"
	.byte	0x8
	.word	0x13da
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_SUBGROUP\0"
	.byte	0x8
	.word	0x13db
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_ACTION_0\0"
	.byte	0x8
	.word	0x13dc
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_LEVEL_0\0"
	.byte	0x8
	.word	0x13dd
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_FLAGS_0\0"
	.byte	0x8
	.word	0x13de
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_ACTION_1\0"
	.byte	0x8
	.word	0x13df
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_LEVEL_1\0"
	.byte	0x8
	.word	0x13e0
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_FLAGS_1\0"
	.byte	0x8
	.word	0x13e1
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_ACTION_2\0"
	.byte	0x8
	.word	0x13e2
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_LEVEL_2\0"
	.byte	0x8
	.word	0x13e3
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_FLAGS_2\0"
	.byte	0x8
	.word	0x13e4
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_ACTION_3\0"
	.byte	0x8
	.word	0x13e5
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_LEVEL_3\0"
	.byte	0x8
	.word	0x13e6
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_DISCHARGE_FLAGS_3\0"
	.byte	0x8
	.word	0x13e7
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_SETTINGS_SUBGROUP\0"
	.byte	0x8
	.word	0x13e8
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_THROTTLE_POLICY\0"
	.byte	0x8
	.word	0x13e9
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_THROTTLE_MAXIMUM\0"
	.byte	0x8
	.word	0x13ea
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_THROTTLE_MINIMUM\0"
	.byte	0x8
	.word	0x13eb
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_ALLOW_THROTTLING\0"
	.byte	0x8
	.word	0x13ec
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLESTATE_POLICY\0"
	.byte	0x8
	.word	0x13ed
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERFSTATE_POLICY\0"
	.byte	0x8
	.word	0x13ee
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_INCREASE_THRESHOLD\0"
	.byte	0x8
	.word	0x13ef
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_DECREASE_THRESHOLD\0"
	.byte	0x8
	.word	0x13f0
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_INCREASE_POLICY\0"
	.byte	0x8
	.word	0x13f1
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_DECREASE_POLICY\0"
	.byte	0x8
	.word	0x13f2
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_INCREASE_TIME\0"
	.byte	0x8
	.word	0x13f3
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_DECREASE_TIME\0"
	.byte	0x8
	.word	0x13f4
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_TIME_CHECK\0"
	.byte	0x8
	.word	0x13f5
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_BOOST_POLICY\0"
	.byte	0x8
	.word	0x13f6
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_BOOST_MODE\0"
	.byte	0x8
	.word	0x13f7
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLE_ALLOW_SCALING\0"
	.byte	0x8
	.word	0x13f8
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLE_DISABLE\0"
	.byte	0x8
	.word	0x13f9
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLE_STATE_MAXIMUM\0"
	.byte	0x8
	.word	0x13fa
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLE_TIME_CHECK\0"
	.byte	0x8
	.word	0x13fb
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD\0"
	.byte	0x8
	.word	0x13fc
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD\0"
	.byte	0x8
	.word	0x13fd
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD\0"
	.byte	0x8
	.word	0x13fe
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD\0"
	.byte	0x8
	.word	0x13ff
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY\0"
	.byte	0x8
	.word	0x1400
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY\0"
	.byte	0x8
	.word	0x1401
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_MAX_CORES\0"
	.byte	0x8
	.word	0x1402
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_MIN_CORES\0"
	.byte	0x8
	.word	0x1403
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME\0"
	.byte	0x8
	.word	0x1404
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME\0"
	.byte	0x8
	.word	0x1405
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR\0"
	.byte	0x8
	.word	0x1406
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD\0"
	.byte	0x8
	.word	0x1407
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING\0"
	.byte	0x8
	.word	0x1408
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR\0"
	.byte	0x8
	.word	0x1409
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD\0"
	.byte	0x8
	.word	0x140a
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING\0"
	.byte	0x8
	.word	0x140b
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD\0"
	.byte	0x8
	.word	0x140c
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PARKING_CORE_OVERRIDE\0"
	.byte	0x8
	.word	0x140d
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PARKING_PERF_STATE\0"
	.byte	0x8
	.word	0x140e
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PARKING_CONCURRENCY_THRESHOLD\0"
	.byte	0x8
	.word	0x140f
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PARKING_HEADROOM_THRESHOLD\0"
	.byte	0x8
	.word	0x1410
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_HISTORY\0"
	.byte	0x8
	.word	0x1411
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_PERF_LATENCY_HINT\0"
	.byte	0x8
	.word	0x1412
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PROCESSOR_DISTRIBUTE_UTILITY\0"
	.byte	0x8
	.word	0x1413
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SYSTEM_COOLING_POLICY\0"
	.byte	0x8
	.word	0x1414
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_LOCK_CONSOLE_ON_WAKE\0"
	.byte	0x8
	.word	0x1415
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_DEVICE_IDLE_POLICY\0"
	.byte	0x8
	.word	0x1416
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ACDC_POWER_SOURCE\0"
	.byte	0x8
	.word	0x1417
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_LIDSWITCH_STATE_CHANGE\0"
	.byte	0x8
	.word	0x1418
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BATTERY_PERCENTAGE_REMAINING\0"
	.byte	0x8
	.word	0x1419
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_GLOBAL_USER_PRESENCE\0"
	.byte	0x8
	.word	0x141a
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SESSION_DISPLAY_STATUS\0"
	.byte	0x8
	.word	0x141b
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_SESSION_USER_PRESENCE\0"
	.byte	0x8
	.word	0x141c
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_IDLE_BACKGROUND_TASK\0"
	.byte	0x8
	.word	0x141d
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_BACKGROUND_TASK_NOTIFICATION\0"
	.byte	0x8
	.word	0x141e
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_APPLAUNCH_BUTTON\0"
	.byte	0x8
	.word	0x141f
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PCIEXPRESS_SETTINGS_SUBGROUP\0"
	.byte	0x8
	.word	0x1420
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_PCIEXPRESS_ASPM_POLICY\0"
	.byte	0x8
	.word	0x1421
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_ENABLE_SWITCH_FORCED_SHUTDOWN\0"
	.byte	0x8
	.word	0x1422
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_PERFSTATE_CHANGE_GUID\0"
	.byte	0x8
	.word	0x1620
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_PERFSTATE_DOMAIN_CHANGE_GUID\0"
	.byte	0x8
	.word	0x1621
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_IDLESTATE_CHANGE_GUID\0"
	.byte	0x8
	.word	0x1622
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_PERFSTATES_DATA_GUID\0"
	.byte	0x8
	.word	0x1623
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_IDLESTATES_DATA_GUID\0"
	.byte	0x8
	.word	0x1624
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_IDLE_ACCOUNTING_GUID\0"
	.byte	0x8
	.word	0x1625
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_IDLE_ACCOUNTING_EX_GUID\0"
	.byte	0x8
	.word	0x1626
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_THERMALCONSTRAINT_GUID\0"
	.byte	0x8
	.word	0x1627
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_PERFMON_PERFSTATE_GUID\0"
	.byte	0x8
	.word	0x1628
	.byte	0x1b
	.long	0x82f
	.uleb128 0x21
	.ascii "PPM_THERMAL_POLICY_CHANGE_GUID\0"
	.byte	0x8
	.word	0x1629
	.byte	0x1b
	.long	0x82f
	.uleb128 0x13
	.ascii "_OVERLAPPED\0"
	.byte	0x20
	.byte	0x10
	.byte	0x13
	.byte	0x12
	.long	0x27e7
	.uleb128 0x28
	.byte	0x8
	.byte	0x10
	.byte	0x16
	.byte	0x19
	.long	0x27a8
	.uleb128 0x29
	.byte	0x8
	.byte	0x10
	.byte	0x17
	.byte	0xe
	.long	0x2792
	.uleb128 0x14
	.ascii "Offset\0"
	.byte	0x10
	.byte	0x18
	.byte	0x8
	.long	0x608
	.byte	0
	.uleb128 0x14
	.ascii "OffsetHigh\0"
	.byte	0x10
	.byte	0x19
	.byte	0x8
	.long	0x608
	.byte	0x4
	.byte	0
	.uleb128 0x2a
	.long	0x2764
	.uleb128 0x2b
	.ascii "Pointer\0"
	.byte	0x10
	.byte	0x1b
	.byte	0xd
	.long	0x799
	.byte	0
	.uleb128 0x14
	.ascii "Internal\0"
	.byte	0x10
	.byte	0x14
	.byte	0xf
	.long	0x787
	.byte	0
	.uleb128 0x14
	.ascii "InternalHigh\0"
	.byte	0x10
	.byte	0x15
	.byte	0xf
	.long	0x787
	.byte	0x8
	.uleb128 0x2c
	.long	0x275b
	.byte	0x10
	.uleb128 0x14
	.ascii "hEvent\0"
	.byte	0x10
	.byte	0x1d
	.byte	0xc
	.long	0x7b6
	.byte	0x18
	.byte	0
	.uleb128 0x5
	.ascii "OVERLAPPED\0"
	.byte	0x10
	.byte	0x1e
	.byte	0x5
	.long	0x2746
	.uleb128 0x5
	.ascii "RPC_IF_HANDLE\0"
	.byte	0x11
	.byte	0x42
	.byte	0x11
	.long	0x5de
	.uleb128 0x16
	.ascii "IWinTypesBase_v0_1_c_ifspec\0"
	.byte	0x12
	.byte	0x29
	.byte	0x16
	.long	0x27fa
	.uleb128 0x16
	.ascii "IWinTypesBase_v0_1_s_ifspec\0"
	.byte	0x12
	.byte	0x2a
	.byte	0x16
	.long	0x27fa
	.uleb128 0x16
	.ascii "IID_IUnknown\0"
	.byte	0x13
	.byte	0x3d
	.byte	0x16
	.long	0x840
	.uleb128 0x16
	.ascii "IID_AsyncIUnknown\0"
	.byte	0x13
	.byte	0xbd
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IClassFactory\0"
	.byte	0x13
	.word	0x16d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMarshal\0"
	.byte	0x14
	.word	0x16e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_INoMarshal\0"
	.byte	0x14
	.word	0x255
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAgileObject\0"
	.byte	0x14
	.word	0x294
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAgileReference\0"
	.byte	0x14
	.word	0x2d2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMarshal2\0"
	.byte	0x14
	.word	0x32d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMalloc\0"
	.byte	0x14
	.word	0x3b2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IStdMarshalInfo\0"
	.byte	0x14
	.word	0x469
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IExternalConnection\0"
	.byte	0x14
	.word	0x4cc
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMultiQI\0"
	.byte	0x14
	.word	0x547
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_AsyncIMultiQI\0"
	.byte	0x14
	.word	0x59e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternalUnknown\0"
	.byte	0x14
	.word	0x60c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumUnknown\0"
	.byte	0x14
	.word	0x668
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumString\0"
	.byte	0x14
	.word	0x706
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISequentialStream\0"
	.byte	0x14
	.word	0x7a2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IStream\0"
	.byte	0x14
	.word	0x84d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcChannelBuffer\0"
	.byte	0x14
	.word	0x991
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcChannelBuffer2\0"
	.byte	0x14
	.word	0xa3b
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAsyncRpcChannelBuffer\0"
	.byte	0x14
	.word	0xabd
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcChannelBuffer3\0"
	.byte	0x14
	.word	0xb7f
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcSyntaxNegotiate\0"
	.byte	0x14
	.word	0xc99
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcProxyBuffer\0"
	.byte	0x14
	.word	0xcee
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcStubBuffer\0"
	.byte	0x14
	.word	0xd56
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPSFactoryBuffer\0"
	.byte	0x14
	.word	0xe1c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IChannelHook\0"
	.byte	0x14
	.word	0xe9f
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IClientSecurity\0"
	.byte	0x14
	.word	0xfc3
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IServerSecurity\0"
	.byte	0x14
	.word	0x106d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcOptions\0"
	.byte	0x14
	.word	0x1113
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IGlobalOptions\0"
	.byte	0x14
	.word	0x11ae
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISurrogate\0"
	.byte	0x14
	.word	0x1221
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IGlobalInterfaceTable\0"
	.byte	0x14
	.word	0x1289
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISynchronize\0"
	.byte	0x14
	.word	0x1312
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISynchronizeHandle\0"
	.byte	0x14
	.word	0x138c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISynchronizeEvent\0"
	.byte	0x14
	.word	0x13e1
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISynchronizeContainer\0"
	.byte	0x14
	.word	0x1441
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISynchronizeMutex\0"
	.byte	0x14
	.word	0x14af
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICancelMethodCalls\0"
	.byte	0x14
	.word	0x151e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAsyncManager\0"
	.byte	0x14
	.word	0x158a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICallFactory\0"
	.byte	0x14
	.word	0x1608
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRpcHelper\0"
	.byte	0x14
	.word	0x1666
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IReleaseMarshalBuffers\0"
	.byte	0x14
	.word	0x16d1
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWaitMultiple\0"
	.byte	0x14
	.word	0x172c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAddrTrackingControl\0"
	.byte	0x14
	.word	0x1798
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAddrExclusionControl\0"
	.byte	0x14
	.word	0x17fd
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPipeByte\0"
	.byte	0x14
	.word	0x1868
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPipeLong\0"
	.byte	0x14
	.word	0x18d9
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPipeDouble\0"
	.byte	0x14
	.word	0x194a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IComThreadingInfo\0"
	.byte	0x14
	.word	0x1b24
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IProcessInitControl\0"
	.byte	0x14
	.word	0x1bb2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IFastRundown\0"
	.byte	0x14
	.word	0x1c07
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMarshalingStream\0"
	.byte	0x14
	.word	0x1c4a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICallbackWithNoReentrancyToApplicationSTA\0"
	.byte	0x14
	.word	0x1d09
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_NULL\0"
	.byte	0x15
	.byte	0xd
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "CATID_MARSHALER\0"
	.byte	0x15
	.byte	0xe
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IRpcChannel\0"
	.byte	0x15
	.byte	0xf
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IRpcStub\0"
	.byte	0x15
	.byte	0x10
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IStubManager\0"
	.byte	0x15
	.byte	0x11
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IRpcProxy\0"
	.byte	0x15
	.byte	0x12
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IProxyManager\0"
	.byte	0x15
	.byte	0x13
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IPSFactory\0"
	.byte	0x15
	.byte	0x14
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IInternalMoniker\0"
	.byte	0x15
	.byte	0x15
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IDfReserved1\0"
	.byte	0x15
	.byte	0x16
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IDfReserved2\0"
	.byte	0x15
	.byte	0x17
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IDfReserved3\0"
	.byte	0x15
	.byte	0x18
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "CLSID_StdMarshal\0"
	.byte	0x15
	.byte	0x19
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_AggStdMarshal\0"
	.byte	0x15
	.byte	0x1a
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_StdAsyncActManager\0"
	.byte	0x15
	.byte	0x1b
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "IID_IStub\0"
	.byte	0x15
	.byte	0x1c
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IProxy\0"
	.byte	0x15
	.byte	0x1d
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IEnumGeneric\0"
	.byte	0x15
	.byte	0x1e
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IEnumHolder\0"
	.byte	0x15
	.byte	0x1f
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IEnumCallback\0"
	.byte	0x15
	.byte	0x20
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IOleManager\0"
	.byte	0x15
	.byte	0x21
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IOlePresObj\0"
	.byte	0x15
	.byte	0x22
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IDebug\0"
	.byte	0x15
	.byte	0x23
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "IID_IDebugStream\0"
	.byte	0x15
	.byte	0x24
	.byte	0x14
	.long	0x840
	.uleb128 0x16
	.ascii "CLSID_PSGenObject\0"
	.byte	0x15
	.byte	0x25
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSClientSite\0"
	.byte	0x15
	.byte	0x26
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSClassObject\0"
	.byte	0x15
	.byte	0x27
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSInPlaceActive\0"
	.byte	0x15
	.byte	0x28
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSInPlaceFrame\0"
	.byte	0x15
	.byte	0x29
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSDragDrop\0"
	.byte	0x15
	.byte	0x2a
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSBindCtx\0"
	.byte	0x15
	.byte	0x2b
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_PSEnumerators\0"
	.byte	0x15
	.byte	0x2c
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_StaticMetafile\0"
	.byte	0x15
	.byte	0x2d
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_StaticDib\0"
	.byte	0x15
	.byte	0x2e
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CID_CDfsVolume\0"
	.byte	0x15
	.byte	0x2f
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_DCOMAccessControl\0"
	.byte	0x15
	.byte	0x30
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_GlobalOptions\0"
	.byte	0x15
	.byte	0x31
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_StdGlobalInterfaceTable\0"
	.byte	0x15
	.byte	0x32
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_ComBinding\0"
	.byte	0x15
	.byte	0x33
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_StdEvent\0"
	.byte	0x15
	.byte	0x34
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_ManualResetEvent\0"
	.byte	0x15
	.byte	0x35
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_SynchronizeContainer\0"
	.byte	0x15
	.byte	0x36
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_AddrControl\0"
	.byte	0x15
	.byte	0x37
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDFormKrnl\0"
	.byte	0x15
	.byte	0x38
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDPropertyPage\0"
	.byte	0x15
	.byte	0x39
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDFormDialog\0"
	.byte	0x15
	.byte	0x3a
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDCommandButton\0"
	.byte	0x15
	.byte	0x3b
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDComboBox\0"
	.byte	0x15
	.byte	0x3c
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDTextBox\0"
	.byte	0x15
	.byte	0x3d
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDCheckBox\0"
	.byte	0x15
	.byte	0x3e
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDLabel\0"
	.byte	0x15
	.byte	0x3f
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDOptionButton\0"
	.byte	0x15
	.byte	0x40
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDListBox\0"
	.byte	0x15
	.byte	0x41
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDScrollBar\0"
	.byte	0x15
	.byte	0x42
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDGroupBox\0"
	.byte	0x15
	.byte	0x43
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDGeneralPropertyPage\0"
	.byte	0x15
	.byte	0x44
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDGenericPropertyPage\0"
	.byte	0x15
	.byte	0x45
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDFontPropertyPage\0"
	.byte	0x15
	.byte	0x46
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDColorPropertyPage\0"
	.byte	0x15
	.byte	0x47
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDLabelPropertyPage\0"
	.byte	0x15
	.byte	0x48
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDCheckBoxPropertyPage\0"
	.byte	0x15
	.byte	0x49
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDTextBoxPropertyPage\0"
	.byte	0x15
	.byte	0x4a
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDOptionButtonPropertyPage\0"
	.byte	0x15
	.byte	0x4b
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDListBoxPropertyPage\0"
	.byte	0x15
	.byte	0x4c
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDCommandButtonPropertyPage\0"
	.byte	0x15
	.byte	0x4d
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDComboBoxPropertyPage\0"
	.byte	0x15
	.byte	0x4e
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDScrollBarPropertyPage\0"
	.byte	0x15
	.byte	0x4f
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDGroupBoxPropertyPage\0"
	.byte	0x15
	.byte	0x50
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CCDXObjectPropertyPage\0"
	.byte	0x15
	.byte	0x51
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CStdPropertyFrame\0"
	.byte	0x15
	.byte	0x52
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CFormPropertyPage\0"
	.byte	0x15
	.byte	0x53
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CGridPropertyPage\0"
	.byte	0x15
	.byte	0x54
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CWSJArticlePage\0"
	.byte	0x15
	.byte	0x55
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_CSystemPage\0"
	.byte	0x15
	.byte	0x56
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_IdentityUnmarshal\0"
	.byte	0x15
	.byte	0x57
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_InProcFreeMarshaler\0"
	.byte	0x15
	.byte	0x58
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_Picture_Metafile\0"
	.byte	0x15
	.byte	0x59
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_Picture_EnhMetafile\0"
	.byte	0x15
	.byte	0x5a
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "CLSID_Picture_Dib\0"
	.byte	0x15
	.byte	0x5b
	.byte	0x16
	.long	0x853
	.uleb128 0x16
	.ascii "GUID_TRISTATE\0"
	.byte	0x15
	.byte	0x5c
	.byte	0x15
	.long	0x82f
	.uleb128 0x16
	.ascii "IWinTypes_v0_1_c_ifspec\0"
	.byte	0x16
	.byte	0x28
	.byte	0x16
	.long	0x27fa
	.uleb128 0x16
	.ascii "IWinTypes_v0_1_s_ifspec\0"
	.byte	0x16
	.byte	0x29
	.byte	0x16
	.long	0x27fa
	.uleb128 0x21
	.ascii "IID_IMallocSpy\0"
	.byte	0x17
	.word	0x1dbd
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBindCtx\0"
	.byte	0x17
	.word	0x1f3a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumMoniker\0"
	.byte	0x17
	.word	0x204a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRunnableObject\0"
	.byte	0x17
	.word	0x20e8
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRunningObjectTable\0"
	.byte	0x17
	.word	0x218e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPersist\0"
	.byte	0x17
	.word	0x2269
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPersistStream\0"
	.byte	0x17
	.word	0x22be
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMoniker\0"
	.byte	0x17
	.word	0x236a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IROTData\0"
	.byte	0x17
	.word	0x2558
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumSTATSTG\0"
	.byte	0x17
	.word	0x25b5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IStorage\0"
	.byte	0x17
	.word	0x2658
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPersistFile\0"
	.byte	0x17
	.word	0x2841
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPersistStorage\0"
	.byte	0x17
	.word	0x28f1
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ILockBytes\0"
	.byte	0x17
	.word	0x29b1
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumFORMATETC\0"
	.byte	0x17
	.word	0x2ac0
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumSTATDATA\0"
	.byte	0x17
	.word	0x2b6c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRootStorage\0"
	.byte	0x17
	.word	0x2c08
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAdviseSink\0"
	.byte	0x17
	.word	0x2cb3
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_AsyncIAdviseSink\0"
	.byte	0x17
	.word	0x2d73
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAdviseSink2\0"
	.byte	0x17
	.word	0x2ea9
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_AsyncIAdviseSink2\0"
	.byte	0x17
	.word	0x2f2e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDataObject\0"
	.byte	0x17
	.word	0x2ff4
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDataAdviseHolder\0"
	.byte	0x17
	.word	0x3118
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMessageFilter\0"
	.byte	0x17
	.word	0x31d3
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "FMTID_SummaryInformation\0"
	.byte	0x17
	.word	0x325d
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_DocSummaryInformation\0"
	.byte	0x17
	.word	0x325f
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_UserDefinedProperties\0"
	.byte	0x17
	.word	0x3261
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_DiscardableInformation\0"
	.byte	0x17
	.word	0x3263
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_ImageSummaryInformation\0"
	.byte	0x17
	.word	0x3265
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_AudioSummaryInformation\0"
	.byte	0x17
	.word	0x3267
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_VideoSummaryInformation\0"
	.byte	0x17
	.word	0x3269
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "FMTID_MediaFileSummaryInformation\0"
	.byte	0x17
	.word	0x326b
	.byte	0x14
	.long	0x866
	.uleb128 0x21
	.ascii "IID_IClassActivator\0"
	.byte	0x17
	.word	0x3273
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IFillLockBytes\0"
	.byte	0x17
	.word	0x32d5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IProgressNotify\0"
	.byte	0x17
	.word	0x3389
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ILayoutStorage\0"
	.byte	0x17
	.word	0x33ee
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBlockingLock\0"
	.byte	0x17
	.word	0x3492
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITimeAndNoticeControl\0"
	.byte	0x17
	.word	0x34f7
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOplockStorage\0"
	.byte	0x17
	.word	0x354e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDirectWriterLock\0"
	.byte	0x17
	.word	0x35d5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IUrlMon\0"
	.byte	0x17
	.word	0x364d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IForegroundTransfer\0"
	.byte	0x17
	.word	0x36bc
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IThumbnailExtractor\0"
	.byte	0x17
	.word	0x3710
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDummyHICONIncluder\0"
	.byte	0x17
	.word	0x3786
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IProcessLock\0"
	.byte	0x17
	.word	0x37e5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISurrogateService\0"
	.byte	0x17
	.word	0x3848
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInitializeSpy\0"
	.byte	0x17
	.word	0x38f2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IApartmentShutdown\0"
	.byte	0x17
	.word	0x398a
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "IID_IOleAdviseHolder\0"
	.byte	0x18
	.byte	0xab
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleCache\0"
	.byte	0x18
	.word	0x162
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleCache2\0"
	.byte	0x18
	.word	0x229
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleCacheControl\0"
	.byte	0x18
	.word	0x2d4
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IParseDisplayName\0"
	.byte	0x18
	.word	0x33c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleContainer\0"
	.byte	0x18
	.word	0x39c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleClientSite\0"
	.byte	0x18
	.word	0x417
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleObject\0"
	.byte	0x18
	.word	0x4fe
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IOLETypes_v0_0_c_ifspec\0"
	.byte	0x18
	.word	0x6fe
	.byte	0x16
	.long	0x27fa
	.uleb128 0x21
	.ascii "IOLETypes_v0_0_s_ifspec\0"
	.byte	0x18
	.word	0x6ff
	.byte	0x16
	.long	0x27fa
	.uleb128 0x21
	.ascii "IID_IOleWindow\0"
	.byte	0x18
	.word	0x724
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleLink\0"
	.byte	0x18
	.word	0x79a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleItemContainer\0"
	.byte	0x18
	.word	0x8bf
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleInPlaceUIWindow\0"
	.byte	0x18
	.word	0x976
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleInPlaceActiveObject\0"
	.byte	0x18
	.word	0xa1c
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleInPlaceFrame\0"
	.byte	0x18
	.word	0xaf8
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleInPlaceObject\0"
	.byte	0x18
	.word	0xbf1
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IOleInPlaceSite\0"
	.byte	0x18
	.word	0xc91
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IContinue\0"
	.byte	0x18
	.word	0xda4
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IViewObject\0"
	.byte	0x18
	.word	0xdf9
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IViewObject2\0"
	.byte	0x18
	.word	0xf2a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDropSource\0"
	.byte	0x18
	.word	0xfd2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDropTarget\0"
	.byte	0x18
	.word	0x105b
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDropSourceNotify\0"
	.byte	0x18
	.word	0x10ff
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumOLEVERB\0"
	.byte	0x18
	.word	0x1176
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "IID_IServiceProvider\0"
	.byte	0x19
	.byte	0x39
	.byte	0x16
	.long	0x840
	.uleb128 0x16
	.ascii "IOleAutomationTypes_v1_0_c_ifspec\0"
	.byte	0x1a
	.byte	0xf1
	.byte	0x16
	.long	0x27fa
	.uleb128 0x16
	.ascii "IOleAutomationTypes_v1_0_s_ifspec\0"
	.byte	0x1a
	.byte	0xf2
	.byte	0x16
	.long	0x27fa
	.uleb128 0x21
	.ascii "IID_ICreateTypeInfo\0"
	.byte	0x1a
	.word	0x33b
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICreateTypeInfo2\0"
	.byte	0x1a
	.word	0x562
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICreateTypeLib\0"
	.byte	0x1a
	.word	0x7b2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICreateTypeLib2\0"
	.byte	0x1a
	.word	0x8ba
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDispatch\0"
	.byte	0x1a
	.word	0x9b6
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumVARIANT\0"
	.byte	0x1a
	.word	0xa87
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeComp\0"
	.byte	0x1a
	.word	0xb35
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeInfo\0"
	.byte	0x1a
	.word	0xbd9
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeInfo2\0"
	.byte	0x1a
	.word	0xe50
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeLib\0"
	.byte	0x1a
	.word	0x10d6
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeLib2\0"
	.byte	0x1a
	.word	0x123d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeChangeEvents\0"
	.byte	0x1a
	.word	0x1361
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IErrorInfo\0"
	.byte	0x1a
	.word	0x13da
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICreateErrorInfo\0"
	.byte	0x1a
	.word	0x147d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ISupportErrorInfo\0"
	.byte	0x1a
	.word	0x1520
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeFactory\0"
	.byte	0x1a
	.word	0x1575
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ITypeMarshal\0"
	.byte	0x1a
	.word	0x15d0
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IRecordInfo\0"
	.byte	0x1a
	.word	0x1684
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IErrorLog\0"
	.byte	0x1a
	.word	0x1820
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPropertyBag\0"
	.byte	0x1a
	.word	0x187a
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "__MIDL_itf_msxml_0000_v0_0_c_ifspec\0"
	.byte	0x1b
	.byte	0xeb
	.byte	0x18
	.long	0x27fa
	.uleb128 0x16
	.ascii "__MIDL_itf_msxml_0000_v0_0_s_ifspec\0"
	.byte	0x1b
	.byte	0xec
	.byte	0x18
	.long	0x27fa
	.uleb128 0x16
	.ascii "LIBID_MSXML\0"
	.byte	0x1b
	.byte	0xfc
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMImplementation\0"
	.byte	0x1b
	.word	0x100
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMNode\0"
	.byte	0x1b
	.word	0x127
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMDocumentFragment\0"
	.byte	0x1b
	.word	0x1fd
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMDocument\0"
	.byte	0x1b
	.word	0x266
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMNodeList\0"
	.byte	0x1b
	.word	0x375
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMNamedNodeMap\0"
	.byte	0x1b
	.word	0x3b0
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMCharacterData\0"
	.byte	0x1b
	.word	0x404
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMAttribute\0"
	.byte	0x1b
	.word	0x496
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMElement\0"
	.byte	0x1b
	.word	0x50f
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMText\0"
	.byte	0x1b
	.word	0x5a6
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMComment\0"
	.byte	0x1b
	.word	0x625
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMProcessingInstruction\0"
	.byte	0x1b
	.word	0x69e
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMCDATASection\0"
	.byte	0x1b
	.word	0x717
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMDocumentType\0"
	.byte	0x1b
	.word	0x792
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMNotation\0"
	.byte	0x1b
	.word	0x80b
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMEntity\0"
	.byte	0x1b
	.word	0x87f
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMEntityReference\0"
	.byte	0x1b
	.word	0x8f8
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDOMParseError\0"
	.byte	0x1b
	.word	0x961
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXTLRuntime\0"
	.byte	0x1b
	.word	0x9a6
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "DIID_XMLDOMDocumentEvents\0"
	.byte	0x1b
	.word	0xa3d
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_DOMDocument\0"
	.byte	0x1b
	.word	0xa5c
	.byte	0x1a
	.long	0x853
	.uleb128 0x21
	.ascii "CLSID_DOMFreeThreadedDocument\0"
	.byte	0x1b
	.word	0xa60
	.byte	0x1a
	.long	0x853
	.uleb128 0x21
	.ascii "IID_IXMLHttpRequest\0"
	.byte	0x1b
	.word	0xa67
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_XMLHTTPRequest\0"
	.byte	0x1b
	.word	0xacd
	.byte	0x1a
	.long	0x853
	.uleb128 0x21
	.ascii "IID_IXMLDSOControl\0"
	.byte	0x1b
	.word	0xad4
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_XMLDSOControl\0"
	.byte	0x1b
	.word	0xb0d
	.byte	0x1a
	.long	0x853
	.uleb128 0x21
	.ascii "IID_IXMLElementCollection\0"
	.byte	0x1b
	.word	0xb14
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDocument\0"
	.byte	0x1b
	.word	0xb4a
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLDocument2\0"
	.byte	0x1b
	.word	0xbb2
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLElement\0"
	.byte	0x1b
	.word	0xc24
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLElement2\0"
	.byte	0x1b
	.word	0xc82
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLAttribute\0"
	.byte	0x1b
	.word	0xce5
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IXMLError\0"
	.byte	0x1b
	.word	0xd11
	.byte	0x18
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_XMLDocument\0"
	.byte	0x1b
	.word	0xd2e
	.byte	0x1a
	.long	0x853
	.uleb128 0x21
	.ascii "CLSID_SBS_StdURLMoniker\0"
	.byte	0x1c
	.word	0x17e
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_HttpProtocol\0"
	.byte	0x1c
	.word	0x17f
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_FtpProtocol\0"
	.byte	0x1c
	.word	0x180
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_GopherProtocol\0"
	.byte	0x1c
	.word	0x181
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_HttpSProtocol\0"
	.byte	0x1c
	.word	0x182
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_FileProtocol\0"
	.byte	0x1c
	.word	0x183
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_MkProtocol\0"
	.byte	0x1c
	.word	0x184
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_UrlMkBindCtx\0"
	.byte	0x1c
	.word	0x185
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_SoftDistExt\0"
	.byte	0x1c
	.word	0x186
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_CdlProtocol\0"
	.byte	0x1c
	.word	0x187
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_ClassInstallFilter\0"
	.byte	0x1c
	.word	0x188
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_InternetSecurityManager\0"
	.byte	0x1c
	.word	0x189
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_SBS_InternetZoneManager\0"
	.byte	0x1c
	.word	0x18a
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IAsyncMoniker\0"
	.byte	0x1c
	.word	0x193
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_StdURLMoniker\0"
	.byte	0x1c
	.word	0x194
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_HttpProtocol\0"
	.byte	0x1c
	.word	0x195
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_FtpProtocol\0"
	.byte	0x1c
	.word	0x196
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_GopherProtocol\0"
	.byte	0x1c
	.word	0x197
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_HttpSProtocol\0"
	.byte	0x1c
	.word	0x198
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_FileProtocol\0"
	.byte	0x1c
	.word	0x199
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_MkProtocol\0"
	.byte	0x1c
	.word	0x19a
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_StdURLProtocol\0"
	.byte	0x1c
	.word	0x19b
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_UrlMkBindCtx\0"
	.byte	0x1c
	.word	0x19c
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_CdlProtocol\0"
	.byte	0x1c
	.word	0x19d
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_ClassInstallFilter\0"
	.byte	0x1c
	.word	0x19e
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IAsyncBindCtx\0"
	.byte	0x1c
	.word	0x19f
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IPersistMoniker\0"
	.byte	0x1c
	.word	0x250
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IMonikerProp\0"
	.byte	0x1c
	.word	0x321
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBindProtocol\0"
	.byte	0x1c
	.word	0x37f
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBinding\0"
	.byte	0x1c
	.word	0x3e0
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBindStatusCallback\0"
	.byte	0x1c
	.word	0x575
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBindStatusCallbackEx\0"
	.byte	0x1c
	.word	0x6a5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAuthenticate\0"
	.byte	0x1c
	.word	0x764
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IAuthenticateEx\0"
	.byte	0x1c
	.word	0x7d0
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IHttpNegotiate\0"
	.byte	0x1c
	.word	0x841
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IHttpNegotiate2\0"
	.byte	0x1c
	.word	0x8c1
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IHttpNegotiate3\0"
	.byte	0x1c
	.word	0x93b
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWinInetFileStream\0"
	.byte	0x1c
	.word	0x9bf
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWindowForBindingUI\0"
	.byte	0x1c
	.word	0xa30
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICodeInstall\0"
	.byte	0x1c
	.word	0xa9b
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWinInetInfo\0"
	.byte	0x1c
	.word	0x10a5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IHttpSecurity\0"
	.byte	0x1c
	.word	0x1112
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWinInetHttpInfo\0"
	.byte	0x1c
	.word	0x1179
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWinInetHttpTimeouts\0"
	.byte	0x1c
	.word	0x11f8
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "SID_BindHost\0"
	.byte	0x1c
	.word	0x1335
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBindHost\0"
	.byte	0x1c
	.word	0x133f
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternet\0"
	.byte	0x1c
	.word	0x144d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetBindInfo\0"
	.byte	0x1c
	.word	0x14ac
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetBindInfoEx\0"
	.byte	0x1c
	.word	0x1526
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetProtocolRoot\0"
	.byte	0x1c
	.word	0x15bf
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetProtocol\0"
	.byte	0x1c
	.word	0x1684
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetProtocolSink\0"
	.byte	0x1c
	.word	0x181a
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetProtocolSinkStackable\0"
	.byte	0x1c
	.word	0x18bd
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetSession\0"
	.byte	0x1c
	.word	0x193f
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetThreadSwitch\0"
	.byte	0x1c
	.word	0x1a48
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetPriority\0"
	.byte	0x1c
	.word	0x1ab2
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetProtocolInfo\0"
	.byte	0x1c
	.word	0x1b4e
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "CLSID_InternetSecurityManager\0"
	.byte	0x1c
	.word	0x1cb2
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "CLSID_InternetZoneManager\0"
	.byte	0x1c
	.word	0x1cb3
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "IID_IInternetSecurityMgrSite\0"
	.byte	0x1c
	.word	0x1ccb
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetSecurityManager\0"
	.byte	0x1c
	.word	0x1d69
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetHostSecurityManager\0"
	.byte	0x1c
	.word	0x210f
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IInternetZoneManager\0"
	.byte	0x1c
	.word	0x22c4
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "CLSID_SoftDistExt\0"
	.byte	0x1c
	.word	0x269c
	.byte	0x16
	.long	0x840
	.uleb128 0x21
	.ascii "IID_ISoftDistExt\0"
	.byte	0x1c
	.word	0x26cc
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_ICatalogFileInfo\0"
	.byte	0x1c
	.word	0x2778
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IDataFilter\0"
	.byte	0x1c
	.word	0x27e6
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEncodingFilterFactory\0"
	.byte	0x1c
	.word	0x28a6
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "GUID_CUSTOM_CONFIRMOBJECTSAFETY\0"
	.byte	0x1c
	.word	0x2933
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IWrappedProtocol\0"
	.byte	0x1c
	.word	0x2941
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IGetBindHandle\0"
	.byte	0x1c
	.word	0x29a5
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IBindCallbackRedirect\0"
	.byte	0x1c
	.word	0x2a0d
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPropertyStorage\0"
	.byte	0x1d
	.word	0x1b7
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IPropertySetStorage\0"
	.byte	0x1d
	.word	0x304
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumSTATPROPSTG\0"
	.byte	0x1d
	.word	0x3a6
	.byte	0x17
	.long	0x82f
	.uleb128 0x21
	.ascii "IID_IEnumSTATPROPSETSTG\0"
	.byte	0x1d
	.word	0x444
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "IID_StdOle\0"
	.byte	0x1e
	.byte	0x15
	.byte	0x16
	.long	0x840
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_DISK\0"
	.byte	0x1f
	.byte	0xc
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_CDROM\0"
	.byte	0x1f
	.byte	0xd
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_PARTITION\0"
	.byte	0x1f
	.byte	0xe
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_TAPE\0"
	.byte	0x1f
	.byte	0xf
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_WRITEONCEDISK\0"
	.byte	0x1f
	.byte	0x10
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_VOLUME\0"
	.byte	0x1f
	.byte	0x11
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_MEDIUMCHANGER\0"
	.byte	0x1f
	.byte	0x12
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_FLOPPY\0"
	.byte	0x1f
	.byte	0x13
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_CDCHANGER\0"
	.byte	0x1f
	.byte	0x14
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_STORAGEPORT\0"
	.byte	0x1f
	.byte	0x15
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_COMPORT\0"
	.byte	0x1f
	.byte	0x16
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR\0"
	.byte	0x1f
	.byte	0x17
	.byte	0x17
	.long	0x82f
	.uleb128 0x13
	.ascii "_SCARD_IO_REQUEST\0"
	.byte	0x8
	.byte	0x20
	.byte	0xa1
	.byte	0x12
	.long	0x5207
	.uleb128 0x14
	.ascii "dwProtocol\0"
	.byte	0x20
	.byte	0xa2
	.byte	0xb
	.long	0x608
	.byte	0
	.uleb128 0x14
	.ascii "cbPciLength\0"
	.byte	0x20
	.byte	0xa3
	.byte	0xb
	.long	0x608
	.byte	0x4
	.byte	0
	.uleb128 0x5
	.ascii "SCARD_IO_REQUEST\0"
	.byte	0x20
	.byte	0xa4
	.byte	0x5
	.long	0x51c2
	.uleb128 0x4
	.long	0x5207
	.uleb128 0x16
	.ascii "g_rgSCardT0Pci\0"
	.byte	0x21
	.byte	0x25
	.byte	0x3c
	.long	0x5220
	.uleb128 0x16
	.ascii "g_rgSCardT1Pci\0"
	.byte	0x21
	.byte	0x25
	.byte	0x4b
	.long	0x5220
	.uleb128 0x16
	.ascii "g_rgSCardRawPci\0"
	.byte	0x21
	.byte	0x25
	.byte	0x5a
	.long	0x5220
	.uleb128 0x16
	.ascii "IID_IPrintDialogCallback\0"
	.byte	0x22
	.byte	0xe
	.byte	0x17
	.long	0x82f
	.uleb128 0x16
	.ascii "IID_IPrintDialogServices\0"
	.byte	0x22
	.byte	0xf
	.byte	0x17
	.long	0x82f
	.uleb128 0x5
	.ascii "u_char\0"
	.byte	0x23
	.byte	0xd
	.byte	0x17
	.long	0x4cc
	.uleb128 0x5
	.ascii "u_short\0"
	.byte	0x23
	.byte	0xe
	.byte	0x18
	.long	0x105
	.uleb128 0x5
	.ascii "u_int\0"
	.byte	0x23
	.byte	0xf
	.byte	0x16
	.long	0x458
	.uleb128 0x5
	.ascii "u_long\0"
	.byte	0x23
	.byte	0x12
	.byte	0x17
	.long	0x478
	.uleb128 0x13
	.ascii "in_addr\0"
	.byte	0x4
	.byte	0x24
	.byte	0x11
	.byte	0x10
	.long	0x53a8
	.uleb128 0x28
	.byte	0x4
	.byte	0x24
	.byte	0x12
	.byte	0x9
	.long	0x5399
	.uleb128 0x29
	.byte	0x4
	.byte	0x24
	.byte	0x13
	.byte	0xc
	.long	0x5345
	.uleb128 0x14
	.ascii "s_b1\0"
	.byte	0x24
	.byte	0x13
	.byte	0x15
	.long	0x52ad
	.byte	0
	.uleb128 0x14
	.ascii "s_b2\0"
	.byte	0x24
	.byte	0x13
	.byte	0x1b
	.long	0x52ad
	.byte	0x1
	.uleb128 0x14
	.ascii "s_b3\0"
	.byte	0x24
	.byte	0x13
	.byte	0x21
	.long	0x52ad
	.byte	0x2
	.uleb128 0x14
	.ascii "s_b4\0"
	.byte	0x24
	.byte	0x13
	.byte	0x27
	.long	0x52ad
	.byte	0x3
	.byte	0
	.uleb128 0x29
	.byte	0x4
	.byte	0x24
	.byte	0x14
	.byte	0xc
	.long	0x536b
	.uleb128 0x14
	.ascii "s_w1\0"
	.byte	0x24
	.byte	0x14
	.byte	0x16
	.long	0x52bc
	.byte	0
	.uleb128 0x14
	.ascii "s_w2\0"
	.byte	0x24
	.byte	0x14
	.byte	0x1c
	.long	0x52bc
	.byte	0x2
	.byte	0
	.uleb128 0x2b
	.ascii "S_un_b\0"
	.byte	0x24
	.byte	0x13
	.byte	0x2f
	.long	0x5303
	.uleb128 0x2b
	.ascii "S_un_w\0"
	.byte	0x24
	.byte	0x14
	.byte	0x24
	.long	0x5345
	.uleb128 0x2b
	.ascii "S_addr\0"
	.byte	0x24
	.byte	0x15
	.byte	0xc
	.long	0x52da
	.byte	0
	.uleb128 0x14
	.ascii "S_un\0"
	.byte	0x24
	.byte	0x16
	.byte	0x5
	.long	0x52fa
	.byte	0
	.byte	0
	.uleb128 0x5
	.ascii "SOCKET\0"
	.byte	0x25
	.byte	0xb
	.byte	0x12
	.long	0x776
	.uleb128 0x2d
	.ascii "fd_set\0"
	.word	0x208
	.byte	0x26
	.byte	0x15
	.byte	0x10
	.long	0x53ed
	.uleb128 0x14
	.ascii "fd_count\0"
	.byte	0x26
	.byte	0x17
	.byte	0x8
	.long	0x52cc
	.byte	0
	.uleb128 0x14
	.ascii "fd_array\0"
	.byte	0x26
	.byte	0x18
	.byte	0x14
	.long	0x53ed
	.byte	0x8
	.byte	0
	.uleb128 0xf
	.long	0x53a8
	.long	0x53fd
	.uleb128 0x10
	.long	0xda
	.byte	0x3f
	.byte	0
	.uleb128 0x5
	.ascii "fd_set\0"
	.byte	0x26
	.byte	0x19
	.byte	0x3
	.long	0x53b7
	.uleb128 0x5
	.ascii "FD_SET\0"
	.byte	0x26
	.byte	0x68
	.byte	0x17
	.long	0x53b7
	.uleb128 0x13
	.ascii "sockaddr\0"
	.byte	0x10
	.byte	0x27
	.byte	0x46
	.byte	0x8
	.long	0x5452
	.uleb128 0x14
	.ascii "sa_family\0"
	.byte	0x27
	.byte	0x47
	.byte	0xa
	.long	0x52bc
	.byte	0
	.uleb128 0x14
	.ascii "sa_data\0"
	.byte	0x27
	.byte	0x48
	.byte	0x11
	.long	0x5452
	.byte	0x2
	.byte	0
	.uleb128 0xf
	.long	0xbe
	.long	0x5462
	.uleb128 0x10
	.long	0xda
	.byte	0xd
	.byte	0
	.uleb128 0x13
	.ascii "sockaddr_in\0"
	.byte	0x10
	.byte	0x27
	.byte	0x4b
	.byte	0x8
	.long	0x54c2
	.uleb128 0x14
	.ascii "sin_family\0"
	.byte	0x27
	.byte	0x4c
	.byte	0x8
	.long	0x769
	.byte	0
	.uleb128 0x14
	.ascii "sin_port\0"
	.byte	0x27
	.byte	0x4d
	.byte	0xa
	.long	0x52bc
	.byte	0x2
	.uleb128 0x14
	.ascii "sin_addr\0"
	.byte	0x27
	.byte	0x4e
	.byte	0x11
	.long	0x52e9
	.byte	0x4
	.uleb128 0x14
	.ascii "sin_zero\0"
	.byte	0x27
	.byte	0x4f
	.byte	0x11
	.long	0x54c2
	.byte	0x8
	.byte	0
	.uleb128 0xf
	.long	0xbe
	.long	0x54d2
	.uleb128 0x10
	.long	0xda
	.byte	0x7
	.byte	0
	.uleb128 0x5
	.ascii "PSOCKADDR\0"
	.byte	0x27
	.byte	0x5f
	.byte	0x1a
	.long	0x54e4
	.uleb128 0x7
	.byte	0x8
	.long	0x541b
	.uleb128 0x5
	.ascii "SOCKADDR_IN\0"
	.byte	0x27
	.byte	0x62
	.byte	0x1c
	.long	0x5462
	.uleb128 0x2d
	.ascii "WSAData\0"
	.word	0x198
	.byte	0x28
	.byte	0xd
	.byte	0x10
	.long	0x55a7
	.uleb128 0x14
	.ascii "wVersion\0"
	.byte	0x28
	.byte	0xe
	.byte	0x7
	.long	0x5fb
	.byte	0
	.uleb128 0x14
	.ascii "wHighVersion\0"
	.byte	0x28
	.byte	0xf
	.byte	0x7
	.long	0x5fb
	.byte	0x2
	.uleb128 0x14
	.ascii "iMaxSockets\0"
	.byte	0x28
	.byte	0x11
	.byte	0x11
	.long	0x105
	.byte	0x4
	.uleb128 0x14
	.ascii "iMaxUdpDg\0"
	.byte	0x28
	.byte	0x12
	.byte	0x11
	.long	0x105
	.byte	0x6
	.uleb128 0x14
	.ascii "lpVendorInfo\0"
	.byte	0x28
	.byte	0x13
	.byte	0x8
	.long	0x436
	.byte	0x8
	.uleb128 0x14
	.ascii "szDescription\0"
	.byte	0x28
	.byte	0x14
	.byte	0x1b
	.long	0x55a7
	.byte	0x10
	.uleb128 0x2e
	.ascii "szSystemStatus\0"
	.byte	0x28
	.byte	0x15
	.byte	0x1c
	.long	0x55b8
	.word	0x111
	.byte	0
	.uleb128 0xf
	.long	0xbe
	.long	0x55b8
	.uleb128 0x2f
	.long	0xda
	.word	0x100
	.byte	0
	.uleb128 0xf
	.long	0xbe
	.long	0x55c8
	.uleb128 0x10
	.long	0xda
	.byte	0x80
	.byte	0
	.uleb128 0x5
	.ascii "WSADATA\0"
	.byte	0x28
	.byte	0x1d
	.byte	0x3
	.long	0x54fe
	.uleb128 0xe
	.ascii "_WSABUF\0"
	.byte	0x10
	.byte	0x29
	.word	0x172
	.byte	0x12
	.long	0x5607
	.uleb128 0xa
	.ascii "len\0"
	.byte	0x29
	.word	0x173
	.byte	0xc
	.long	0x52da
	.byte	0
	.uleb128 0xa
	.ascii "buf\0"
	.byte	0x29
	.word	0x174
	.byte	0xb
	.long	0x436
	.byte	0x8
	.byte	0
	.uleb128 0x6
	.ascii "WSABUF\0"
	.byte	0x29
	.word	0x175
	.byte	0x5
	.long	0x55d8
	.uleb128 0x13
	.ascii "in6_addr\0"
	.byte	0x10
	.byte	0x2a
	.byte	0x11
	.byte	0x10
	.long	0x5659
	.uleb128 0x28
	.byte	0x10
	.byte	0x2a
	.byte	0x12
	.byte	0x9
	.long	0x564d
	.uleb128 0x2b
	.ascii "Byte\0"
	.byte	0x2a
	.byte	0x13
	.byte	0x13
	.long	0x565e
	.uleb128 0x2b
	.ascii "Word\0"
	.byte	0x2a
	.byte	0x14
	.byte	0x13
	.long	0x566e
	.byte	0
	.uleb128 0x14
	.ascii "u\0"
	.byte	0x2a
	.byte	0x18
	.byte	0x5
	.long	0x5629
	.byte	0
	.byte	0
	.uleb128 0x4
	.long	0x5617
	.uleb128 0xf
	.long	0x52ad
	.long	0x566e
	.uleb128 0x10
	.long	0xda
	.byte	0xf
	.byte	0
	.uleb128 0xf
	.long	0x52bc
	.long	0x567e
	.uleb128 0x10
	.long	0xda
	.byte	0x7
	.byte	0
	.uleb128 0x16
	.ascii "in6addr_any\0"
	.byte	0x2b
	.byte	0x53
	.byte	0x20
	.long	0x5659
	.uleb128 0x16
	.ascii "in6addr_loopback\0"
	.byte	0x2b
	.byte	0x54
	.byte	0x20
	.long	0x5659
	.uleb128 0x2d
	.ascii "_SOCKET_INFORMATION\0"
	.word	0x2040
	.byte	0x2
	.byte	0x27
	.byte	0x10
	.long	0x573a
	.uleb128 0x14
	.ascii "Buffer\0"
	.byte	0x2
	.byte	0x28
	.byte	0x14
	.long	0x573a
	.byte	0
	.uleb128 0x2e
	.ascii "DataBuf\0"
	.byte	0x2
	.byte	0x29
	.byte	0xb
	.long	0x5607
	.word	0x2000
	.uleb128 0x2e
	.ascii "Socket\0"
	.byte	0x2
	.byte	0x2a
	.byte	0xb
	.long	0x53a8
	.word	0x2010
	.uleb128 0x2e
	.ascii "Overlapped\0"
	.byte	0x2
	.byte	0x2b
	.byte	0xf
	.long	0x27e7
	.word	0x2018
	.uleb128 0x2e
	.ascii "BytesSEND\0"
	.byte	0x2
	.byte	0x2c
	.byte	0xa
	.long	0x608
	.word	0x2038
	.uleb128 0x2e
	.ascii "BytesRECV\0"
	.byte	0x2
	.byte	0x2d
	.byte	0xa
	.long	0x608
	.word	0x203c
	.byte	0
	.uleb128 0xf
	.long	0x7a8
	.long	0x574b
	.uleb128 0x2f
	.long	0xda
	.word	0x1fff
	.byte	0
	.uleb128 0x5
	.ascii "LPSOCKET_INFORMATION\0"
	.byte	0x2
	.byte	0x2e
	.byte	0x19
	.long	0x5768
	.uleb128 0x7
	.byte	0x8
	.long	0x56ab
	.uleb128 0x30
	.ascii "TotalSockets\0"
	.byte	0x2
	.byte	0x38
	.byte	0x7
	.long	0x608
	.uleb128 0x9
	.byte	0x3
	.quad	TotalSockets
	.uleb128 0xf
	.long	0x574b
	.long	0x579d
	.uleb128 0x10
	.long	0xda
	.byte	0x3f
	.byte	0
	.uleb128 0x30
	.ascii "SocketArray\0"
	.byte	0x2
	.byte	0x39
	.byte	0x16
	.long	0x578d
	.uleb128 0x9
	.byte	0x3
	.quad	SocketArray
	.uleb128 0x31
	.ascii "FreeSocketInformation\0"
	.byte	0x2
	.word	0x149
	.byte	0x6
	.ascii "_Z21FreeSocketInformationm\0"
	.quad	.LFB6019
	.quad	.LFE6019-.LFB6019
	.uleb128 0x1
	.byte	0x9c
	.long	0x5886
	.uleb128 0x32
	.ascii "Index\0"
	.byte	0x2
	.word	0x149
	.byte	0x22
	.long	0x608
	.secrel32	.LLST5
	.secrel32	.LVUS5
	.uleb128 0x33
	.ascii "SI\0"
	.byte	0x2
	.word	0x14b
	.byte	0x19
	.long	0x574b
	.secrel32	.LLST6
	.secrel32	.LVUS6
	.uleb128 0x33
	.ascii "i\0"
	.byte	0x2
	.word	0x14c
	.byte	0xa
	.long	0x608
	.secrel32	.LLST7
	.secrel32	.LVUS7
	.uleb128 0x34
	.quad	.LVL21
	.long	0x62ed
	.uleb128 0x35
	.quad	.LVL22
	.long	0x6121
	.long	0x5871
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC3
	.byte	0
	.uleb128 0x37
	.quad	.LVL23
	.long	0x62fa
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x75
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x38
	.ascii "CreateSocketInformation\0"
	.byte	0x2
	.word	0x12b
	.byte	0x6
	.ascii "_Z23CreateSocketInformationy\0"
	.long	0x5ee
	.byte	0x1
	.long	0x58e1
	.uleb128 0x39
	.ascii "s\0"
	.byte	0x2
	.word	0x12b
	.byte	0x25
	.long	0x53a8
	.uleb128 0x3a
	.ascii "SI\0"
	.byte	0x2
	.word	0x12e
	.byte	0x19
	.long	0x574b
	.byte	0
	.uleb128 0x3b
	.ascii "main\0"
	.byte	0x2
	.byte	0x3c
	.byte	0x5
	.long	0x120
	.quad	.LFB6017
	.quad	.LFE6017-.LFB6017
	.uleb128 0x1
	.byte	0x9c
	.long	0x6121
	.uleb128 0x3c
	.ascii "argc\0"
	.byte	0x2
	.byte	0x3c
	.byte	0xe
	.long	0x120
	.secrel32	.LLST8
	.secrel32	.LVUS8
	.uleb128 0x3c
	.ascii "argv\0"
	.byte	0x2
	.byte	0x3c
	.byte	0x1b
	.long	0xc32
	.secrel32	.LLST9
	.secrel32	.LVUS9
	.uleb128 0x3d
	.ascii "ListenSocket\0"
	.byte	0x2
	.byte	0x3f
	.byte	0xb
	.long	0x53a8
	.secrel32	.LLST10
	.secrel32	.LVUS10
	.uleb128 0x3d
	.ascii "AcceptSocket\0"
	.byte	0x2
	.byte	0x40
	.byte	0xb
	.long	0x53a8
	.secrel32	.LLST11
	.secrel32	.LVUS11
	.uleb128 0x3e
	.ascii "InternetAddr\0"
	.byte	0x2
	.byte	0x41
	.byte	0x10
	.long	0x54ea
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1568
	.uleb128 0x3e
	.ascii "wsaData\0"
	.byte	0x2
	.byte	0x42
	.byte	0xc
	.long	0x55c8
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1552
	.uleb128 0x3d
	.ascii "Ret\0"
	.byte	0x2
	.byte	0x43
	.byte	0x8
	.long	0x120
	.secrel32	.LLST12
	.secrel32	.LVUS12
	.uleb128 0x3e
	.ascii "WriteSet\0"
	.byte	0x2
	.byte	0x44
	.byte	0xb
	.long	0x540c
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1136
	.uleb128 0x3e
	.ascii "ReadSet\0"
	.byte	0x2
	.byte	0x45
	.byte	0xb
	.long	0x540c
	.uleb128 0x3
	.byte	0x91
	.sleb128 -608
	.uleb128 0x3d
	.ascii "i\0"
	.byte	0x2
	.byte	0x46
	.byte	0xa
	.long	0x608
	.secrel32	.LLST13
	.secrel32	.LVUS13
	.uleb128 0x3d
	.ascii "Total\0"
	.byte	0x2
	.byte	0x47
	.byte	0xa
	.long	0x608
	.secrel32	.LLST14
	.secrel32	.LVUS14
	.uleb128 0x3e
	.ascii "NonBlock\0"
	.byte	0x2
	.byte	0x48
	.byte	0xa
	.long	0x5e0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1584
	.uleb128 0x3e
	.ascii "Flags\0"
	.byte	0x2
	.byte	0x49
	.byte	0xa
	.long	0x608
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1580
	.uleb128 0x3e
	.ascii "SendBytes\0"
	.byte	0x2
	.byte	0x4a
	.byte	0xa
	.long	0x608
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1576
	.uleb128 0x3e
	.ascii "RecvBytes\0"
	.byte	0x2
	.byte	0x4b
	.byte	0xa
	.long	0x608
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1572
	.uleb128 0x3d
	.ascii "srcPort\0"
	.byte	0x2
	.byte	0x4d
	.byte	0x8
	.long	0x120
	.secrel32	.LLST15
	.secrel32	.LVUS15
	.uleb128 0x3d
	.ascii "dstPort\0"
	.byte	0x2
	.byte	0x4d
	.byte	0x10
	.long	0x120
	.secrel32	.LLST16
	.secrel32	.LVUS16
	.uleb128 0x3f
	.secrel32	.Ldebug_ranges0+0
	.long	0x5a9b
	.uleb128 0x3d
	.ascii "__i\0"
	.byte	0x2
	.byte	0x9d
	.byte	0x11
	.long	0x52cc
	.secrel32	.LLST17
	.secrel32	.LVUS17
	.byte	0
	.uleb128 0x3f
	.secrel32	.Ldebug_ranges0+0x40
	.long	0x5ab9
	.uleb128 0x3d
	.ascii "__i\0"
	.byte	0x2
	.byte	0xa4
	.byte	0x17
	.long	0x52cc
	.secrel32	.LLST18
	.secrel32	.LVUS18
	.byte	0
	.uleb128 0x40
	.quad	.LBB11
	.quad	.LBE11-.LBB11
	.long	0x5ae3
	.uleb128 0x3d
	.ascii "__i\0"
	.byte	0x2
	.byte	0xa6
	.byte	0x17
	.long	0x52cc
	.secrel32	.LLST19
	.secrel32	.LVUS19
	.byte	0
	.uleb128 0x3f
	.secrel32	.Ldebug_ranges0+0x80
	.long	0x5c9e
	.uleb128 0x3d
	.ascii "SocketInfo\0"
	.byte	0x2
	.byte	0xdb
	.byte	0x1f
	.long	0x574b
	.secrel32	.LLST20
	.secrel32	.LVUS20
	.uleb128 0x35
	.quad	.LVL65
	.long	0x6307
	.long	0x5b1f
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.uleb128 0x35
	.quad	.LVL67
	.long	0x6313
	.long	0x5b59
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x4
	.byte	0x7d
	.sleb128 8192
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x59
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1572
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 32
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1580
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 40
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 48
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0x35
	.quad	.LVL68
	.long	0x6307
	.long	0x5b71
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x75
	.sleb128 0
	.byte	0
	.uleb128 0x35
	.quad	.LVL70
	.long	0x6328
	.long	0x5ba9
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x4
	.byte	0x7d
	.sleb128 8192
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x59
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1576
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 32
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 40
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 48
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0x35
	.quad	.LVL86
	.long	0x57bb
	.long	0x5bc1
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.byte	0
	.uleb128 0x34
	.quad	.LVL91
	.long	0x633d
	.uleb128 0x34
	.quad	.LVL92
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL93
	.long	0x6121
	.long	0x5bfa
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC23
	.byte	0
	.uleb128 0x35
	.quad	.LVL94
	.long	0x57bb
	.long	0x5c12
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.byte	0
	.uleb128 0x34
	.quad	.LVL105
	.long	0x633d
	.uleb128 0x34
	.quad	.LVL106
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL107
	.long	0x6121
	.long	0x5c4b
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC25
	.byte	0
	.uleb128 0x35
	.quad	.LVL108
	.long	0x57bb
	.long	0x5c63
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.byte	0
	.uleb128 0x35
	.quad	.LVL111
	.long	0x6121
	.long	0x5c82
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC24
	.byte	0
	.uleb128 0x37
	.quad	.LVL116
	.long	0x6121
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC26
	.byte	0
	.byte	0
	.uleb128 0x34
	.quad	.LVL29
	.long	0xdc1
	.uleb128 0x34
	.quad	.LVL31
	.long	0xdc1
	.uleb128 0x35
	.quad	.LVL32
	.long	0x634a
	.long	0x5cd8
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x3
	.byte	0xa
	.word	0x202
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1552
	.byte	0
	.uleb128 0x35
	.quad	.LVL33
	.long	0x6121
	.long	0x5cf7
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC6
	.byte	0
	.uleb128 0x35
	.quad	.LVL34
	.long	0x6357
	.long	0x5d29
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x1
	.byte	0x32
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x59
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 32
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 40
	.uleb128 0x1
	.byte	0x31
	.byte	0
	.uleb128 0x35
	.quad	.LVL37
	.long	0x6121
	.long	0x5d48
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC8
	.byte	0
	.uleb128 0x35
	.quad	.LVL38
	.long	0x6364
	.long	0x5d5f
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0x35
	.quad	.LVL39
	.long	0x6375
	.long	0x5d7b
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x6
	.byte	0x74
	.sleb128 0
	.byte	0xa
	.word	0xffff
	.byte	0x1a
	.byte	0
	.uleb128 0x35
	.quad	.LVL40
	.long	0x6386
	.long	0x5da1
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1608
	.byte	0x6
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x3
	.byte	0x91
	.sleb128 -1568
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x1
	.byte	0x40
	.byte	0
	.uleb128 0x35
	.quad	.LVL41
	.long	0x6121
	.long	0x5dc0
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC10
	.byte	0
	.uleb128 0x35
	.quad	.LVL42
	.long	0x6395
	.long	0x5ddf
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1608
	.byte	0x6
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x1
	.byte	0x35
	.byte	0
	.uleb128 0x35
	.quad	.LVL43
	.long	0x6121
	.long	0x5dfe
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC12
	.byte	0
	.uleb128 0x35
	.quad	.LVL44
	.long	0x63a8
	.long	0x5e2a
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1608
	.byte	0x6
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x6
	.byte	0x11
	.sleb128 -2147195266
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1600
	.byte	0x6
	.byte	0
	.uleb128 0x35
	.quad	.LVL45
	.long	0x6121
	.long	0x5e49
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC14
	.byte	0
	.uleb128 0x35
	.quad	.LVL56
	.long	0x63b5
	.long	0x5e77
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x2
	.byte	0x75
	.sleb128 0
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x59
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x2
	.byte	0x77
	.sleb128 32
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0x35
	.quad	.LVL58
	.long	0x6121
	.long	0x5e96
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC16
	.byte	0
	.uleb128 0x35
	.quad	.LVL59
	.long	0x6307
	.long	0x5eb6
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1608
	.byte	0x6
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.uleb128 0x35
	.quad	.LVL72
	.long	0x6121
	.long	0x5ed5
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC5
	.byte	0
	.uleb128 0x34
	.quad	.LVL73
	.long	0x63c8
	.uleb128 0x35
	.quad	.LVL75
	.long	0x6121
	.long	0x5f01
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC4
	.byte	0
	.uleb128 0x34
	.quad	.LVL77
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL78
	.long	0x6121
	.long	0x5f2d
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC11
	.byte	0
	.uleb128 0x35
	.quad	.LVL97
	.long	0x63d5
	.long	0x5f51
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1608
	.byte	0x6
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x1
	.byte	0x30
	.byte	0
	.uleb128 0x35
	.quad	.LVL100
	.long	0x63a8
	.long	0x5f7b
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x6
	.byte	0x11
	.sleb128 -2147195266
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x4
	.byte	0x91
	.sleb128 -1600
	.byte	0x6
	.byte	0
	.uleb128 0x35
	.quad	.LVL101
	.long	0x6121
	.long	0x5f9a
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC18
	.byte	0
	.uleb128 0x35
	.quad	.LVL102
	.long	0x5886
	.long	0x5fb2
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.byte	0
	.uleb128 0x35
	.quad	.LVL103
	.long	0x6121
	.long	0x5fd1
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC20
	.byte	0
	.uleb128 0x34
	.quad	.LVL113
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL114
	.long	0x6121
	.long	0x5ffd
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC22
	.byte	0
	.uleb128 0x34
	.quad	.LVL119
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL120
	.long	0x6121
	.long	0x6029
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC15
	.byte	0
	.uleb128 0x34
	.quad	.LVL122
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL123
	.long	0x6121
	.long	0x6055
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC7
	.byte	0
	.uleb128 0x34
	.quad	.LVL124
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL125
	.long	0x6121
	.long	0x6081
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC9
	.byte	0
	.uleb128 0x34
	.quad	.LVL126
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL127
	.long	0x6121
	.long	0x60ad
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC13
	.byte	0
	.uleb128 0x34
	.quad	.LVL129
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL130
	.long	0x6121
	.long	0x60d9
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC17
	.byte	0
	.uleb128 0x34
	.quad	.LVL131
	.long	0x633d
	.uleb128 0x35
	.quad	.LVL132
	.long	0x6121
	.long	0x6105
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC21
	.byte	0
	.uleb128 0x37
	.quad	.LVL133
	.long	0x6121
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC19
	.byte	0
	.byte	0
	.uleb128 0x41
	.ascii "printf\0"
	.byte	0x1
	.word	0x159
	.byte	0x5
	.ascii "_Z6printfPKcz\0"
	.long	0x120
	.quad	.LFB5979
	.quad	.LFE5979-.LFB5979
	.uleb128 0x1
	.byte	0x9c
	.long	0x61d5
	.uleb128 0x32
	.ascii "__format\0"
	.byte	0x1
	.word	0x159
	.byte	0x19
	.long	0xdbb
	.secrel32	.LLST0
	.secrel32	.LVUS0
	.uleb128 0x42
	.uleb128 0x33
	.ascii "__retval\0"
	.byte	0x1
	.word	0x15b
	.byte	0x7
	.long	0x120
	.secrel32	.LLST1
	.secrel32	.LVUS1
	.uleb128 0x43
	.ascii "__local_argv\0"
	.byte	0x1
	.word	0x15c
	.byte	0x15
	.long	0xa6
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x35
	.quad	.LVL2
	.long	0x63e8
	.long	0x61ba
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x1
	.byte	0x31
	.byte	0
	.uleb128 0x37
	.quad	.LVL3
	.long	0x63f4
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x44
	.long	0x5886
	.ascii "_Z23CreateSocketInformationy\0"
	.quad	.LFB6018
	.quad	.LFE6018-.LFB6018
	.uleb128 0x1
	.byte	0x9c
	.long	0x62ed
	.uleb128 0x45
	.long	0x58c9
	.secrel32	.LLST2
	.secrel32	.LVUS2
	.uleb128 0x46
	.long	0x58d4
	.secrel32	.LLST3
	.secrel32	.LVUS3
	.uleb128 0x47
	.long	0x5886
	.quad	.LBB4
	.quad	.LBE4-.LBB4
	.long	0x628d
	.uleb128 0x45
	.long	0x58c9
	.secrel32	.LLST4
	.secrel32	.LVUS4
	.uleb128 0x48
	.quad	.LBB5
	.quad	.LBE5-.LBB5
	.uleb128 0x49
	.long	0x58d4
	.uleb128 0x34
	.quad	.LVL14
	.long	0x6400
	.uleb128 0x37
	.quad	.LVL15
	.long	0x6121
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC1
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x35
	.quad	.LVL7
	.long	0x6121
	.long	0x62b2
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC0
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.byte	0
	.uleb128 0x35
	.quad	.LVL8
	.long	0x640c
	.long	0x62d1
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2
	.byte	0x8
	.byte	0x40
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x3
	.byte	0xa
	.word	0x2040
	.byte	0
	.uleb128 0x37
	.quad	.LVL10
	.long	0x6121
	.uleb128 0x36
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x9
	.byte	0x3
	.quad	.LC2
	.byte	0
	.byte	0
	.uleb128 0x4a
	.secrel32	.LASF1
	.secrel32	.LASF1
	.byte	0x29
	.word	0x3cf
	.byte	0x22
	.uleb128 0x4a
	.secrel32	.LASF2
	.secrel32	.LASF2
	.byte	0x2c
	.word	0x43a
	.byte	0x26
	.uleb128 0x4b
	.secrel32	.LASF3
	.secrel32	.LASF3
	.byte	0x26
	.byte	0x1f
	.byte	0x5
	.uleb128 0x4c
	.ascii "WSARecv\0"
	.ascii "WSARecv\0"
	.byte	0x29
	.word	0x414
	.byte	0x22
	.uleb128 0x4c
	.ascii "WSASend\0"
	.ascii "WSASend\0"
	.byte	0x29
	.word	0x418
	.byte	0x22
	.uleb128 0x4a
	.secrel32	.LASF4
	.secrel32	.LASF4
	.byte	0x29
	.word	0x3f4
	.byte	0x22
	.uleb128 0x4a
	.secrel32	.LASF5
	.secrel32	.LASF5
	.byte	0x29
	.word	0x3f1
	.byte	0x22
	.uleb128 0x4a
	.secrel32	.LASF6
	.secrel32	.LASF6
	.byte	0x29
	.word	0x41c
	.byte	0x25
	.uleb128 0x4c
	.ascii "htonl\0"
	.ascii "htonl\0"
	.byte	0x29
	.word	0x3d6
	.byte	0x25
	.uleb128 0x4c
	.ascii "htons\0"
	.ascii "htons\0"
	.byte	0x29
	.word	0x3d7
	.byte	0x26
	.uleb128 0x4c
	.ascii "bind\0"
	.ascii "bind\0"
	.byte	0x29
	.word	0x3ce
	.byte	0x22
	.uleb128 0x4c
	.ascii "listen\0"
	.ascii "listen\0"
	.byte	0x29
	.word	0x3db
	.byte	0x22
	.uleb128 0x4a
	.secrel32	.LASF7
	.secrel32	.LASF7
	.byte	0x29
	.word	0x3d1
	.byte	0x22
	.uleb128 0x4c
	.ascii "select\0"
	.ascii "select\0"
	.byte	0x29
	.word	0x3e3
	.byte	0x22
	.uleb128 0x4a
	.secrel32	.LASF8
	.secrel32	.LASF8
	.byte	0x29
	.word	0x3f2
	.byte	0x22
	.uleb128 0x4c
	.ascii "accept\0"
	.ascii "accept\0"
	.byte	0x29
	.word	0x3cd
	.byte	0x25
	.uleb128 0x4b
	.secrel32	.LASF9
	.secrel32	.LASF9
	.byte	0x1
	.byte	0x52
	.byte	0x42
	.uleb128 0x4b
	.secrel32	.LASF10
	.secrel32	.LASF10
	.byte	0x1
	.byte	0xc7
	.byte	0x22
	.uleb128 0x4b
	.secrel32	.LASF11
	.secrel32	.LASF11
	.byte	0x2d
	.byte	0x2e
	.byte	0x24
	.uleb128 0x4a
	.secrel32	.LASF12
	.secrel32	.LASF12
	.byte	0x2c
	.word	0x433
	.byte	0x26
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x26
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x39
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x89
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x3a
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x8
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x15
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x87
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x17
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2a
	.uleb128 0xd
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0xd
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2e
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x2f
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x30
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x31
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x32
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x33
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x34
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x35
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x36
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x37
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x38
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x39
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3a
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3c
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3d
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3e
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3f
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x40
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x41
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x42
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x43
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x44
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x45
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x46
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x47
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x48
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0x49
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4a
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x4b
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x4c
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"dr"
.Ldebug_loc0:
.LVUS5:
	.uleb128 0
	.uleb128 .LVU65
	.uleb128 .LVU65
	.uleb128 .LVU80
	.uleb128 .LVU80
	.uleb128 0
.LLST5:
	.quad	.LVL18
	.quad	.LVL20
	.word	0x1
	.byte	0x52
	.quad	.LVL20
	.quad	.LVL25
	.word	0x1
	.byte	0x54
	.quad	.LVL25
	.quad	.LFE6019
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS6:
	.uleb128 .LVU62
	.uleb128 .LVU81
.LLST6:
	.quad	.LVL19
	.quad	.LVL26
	.word	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LVUS7:
	.uleb128 .LVU71
	.uleb128 .LVU73
.LLST7:
	.quad	.LVL23
	.quad	.LVL24
	.word	0x1
	.byte	0x54
	.quad	0
	.quad	0
.LVUS8:
	.uleb128 0
	.uleb128 .LVU85
	.uleb128 .LVU85
	.uleb128 .LVU105
	.uleb128 .LVU105
	.uleb128 .LVU253
	.uleb128 .LVU253
	.uleb128 .LVU257
	.uleb128 .LVU257
	.uleb128 0
.LLST8:
	.quad	.LVL27
	.quad	.LVL28-1
	.word	0x1
	.byte	0x52
	.quad	.LVL28-1
	.quad	.LVL30
	.word	0x1
	.byte	0x54
	.quad	.LVL30
	.quad	.LVL74
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	.LVL74
	.quad	.LVL76
	.word	0x1
	.byte	0x54
	.quad	.LVL76
	.quad	.LFE6017
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS9:
	.uleb128 0
	.uleb128 .LVU85
	.uleb128 .LVU85
	.uleb128 .LVU147
	.uleb128 .LVU147
	.uleb128 .LVU246
	.uleb128 .LVU246
	.uleb128 .LVU252
	.uleb128 .LVU252
	.uleb128 .LVU253
	.uleb128 .LVU253
	.uleb128 .LVU261
	.uleb128 .LVU261
	.uleb128 .LVU358
	.uleb128 .LVU358
	.uleb128 .LVU371
	.uleb128 .LVU371
	.uleb128 0
.LLST9:
	.quad	.LVL27
	.quad	.LVL28-1
	.word	0x1
	.byte	0x51
	.quad	.LVL28-1
	.quad	.LVL46
	.word	0x1
	.byte	0x53
	.quad	.LVL46
	.quad	.LVL71
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL71
	.quad	.LVL73
	.word	0x1
	.byte	0x53
	.quad	.LVL73
	.quad	.LVL74
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL74
	.quad	.LVL79
	.word	0x1
	.byte	0x53
	.quad	.LVL79
	.quad	.LVL121
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL121
	.quad	.LVL128
	.word	0x1
	.byte	0x53
	.quad	.LVL128
	.quad	.LFE6017
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS10:
	.uleb128 .LVU114
	.uleb128 .LVU115
	.uleb128 .LVU115
	.uleb128 .LVU246
	.uleb128 .LVU257
	.uleb128 0
.LLST10:
	.quad	.LVL35
	.quad	.LVL36
	.word	0x1
	.byte	0x50
	.quad	.LVL36
	.quad	.LVL71
	.word	0x3
	.byte	0x91
	.sleb128 -1608
	.quad	.LVL76
	.quad	.LFE6017
	.word	0x3
	.byte	0x91
	.sleb128 -1608
	.quad	0
	.quad	0
.LVUS11:
	.uleb128 .LVU300
	.uleb128 .LVU306
	.uleb128 .LVU306
	.uleb128 .LVU307
	.uleb128 .LVU307
	.uleb128 .LVU315
	.uleb128 .LVU328
	.uleb128 .LVU331
	.uleb128 .LVU331
	.uleb128 .LVU334
	.uleb128 .LVU371
	.uleb128 0
.LLST11:
	.quad	.LVL98
	.quad	.LVL99
	.word	0x1
	.byte	0x50
	.quad	.LVL99
	.quad	.LVL100-1
	.word	0x1
	.byte	0x52
	.quad	.LVL100-1
	.quad	.LVL104
	.word	0x1
	.byte	0x54
	.quad	.LVL112
	.quad	.LVL113-1
	.word	0x1
	.byte	0x50
	.quad	.LVL113-1
	.quad	.LVL115
	.word	0x1
	.byte	0x54
	.quad	.LVL128
	.quad	.LFE6017
	.word	0x1
	.byte	0x54
	.quad	0
	.quad	0
.LVUS12:
	.uleb128 .LVU109
	.uleb128 .LVU112
	.uleb128 .LVU246
	.uleb128 .LVU249
.LLST12:
	.quad	.LVL32
	.quad	.LVL33-1
	.word	0x1
	.byte	0x50
	.quad	.LVL71
	.quad	.LVL72-1
	.word	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LVUS13:
	.uleb128 .LVU163
	.uleb128 .LVU164
	.uleb128 .LVU190
	.uleb128 .LVU193
	.uleb128 .LVU193
	.uleb128 .LVU196
	.uleb128 .LVU196
	.uleb128 .LVU197
	.uleb128 .LVU199
	.uleb128 .LVU246
	.uleb128 .LVU274
	.uleb128 .LVU278
	.uleb128 .LVU283
	.uleb128 .LVU292
	.uleb128 .LVU315
	.uleb128 .LVU322
	.uleb128 .LVU325
	.uleb128 .LVU328
	.uleb128 .LVU334
	.uleb128 .LVU336
	.uleb128 .LVU336
	.uleb128 .LVU353
.LLST13:
	.quad	.LVL48
	.quad	.LVL49
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL60
	.quad	.LVL61
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL61
	.quad	.LVL62
	.word	0x3
	.byte	0x74
	.sleb128 1
	.byte	0x9f
	.quad	.LVL62
	.quad	.LVL63
	.word	0x3
	.byte	0x7f
	.sleb128 1
	.byte	0x9f
	.quad	.LVL64
	.quad	.LVL71
	.word	0x1
	.byte	0x54
	.quad	.LVL85
	.quad	.LVL87
	.word	0x1
	.byte	0x54
	.quad	.LVL89
	.quad	.LVL95
	.word	0x1
	.byte	0x54
	.quad	.LVL104
	.quad	.LVL109
	.word	0x1
	.byte	0x54
	.quad	.LVL110
	.quad	.LVL112
	.word	0x1
	.byte	0x54
	.quad	.LVL115
	.quad	.LVL117
	.word	0x1
	.byte	0x54
	.quad	.LVL117
	.quad	.LVL118
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS14:
	.uleb128 .LVU184
	.uleb128 .LVU187
	.uleb128 .LVU187
	.uleb128 .LVU246
	.uleb128 .LVU274
	.uleb128 .LVU278
	.uleb128 .LVU283
	.uleb128 .LVU322
	.uleb128 .LVU325
	.uleb128 .LVU353
	.uleb128 .LVU353
	.uleb128 .LVU355
	.uleb128 .LVU355
	.uleb128 .LVU358
	.uleb128 .LVU371
	.uleb128 0
.LLST14:
	.quad	.LVL57
	.quad	.LVL58-1
	.word	0x1
	.byte	0x50
	.quad	.LVL58-1
	.quad	.LVL71
	.word	0x1
	.byte	0x56
	.quad	.LVL85
	.quad	.LVL87
	.word	0x1
	.byte	0x56
	.quad	.LVL89
	.quad	.LVL109
	.word	0x1
	.byte	0x56
	.quad	.LVL110
	.quad	.LVL118
	.word	0x1
	.byte	0x56
	.quad	.LVL118
	.quad	.LVL119-1
	.word	0x1
	.byte	0x50
	.quad	.LVL119-1
	.quad	.LVL121
	.word	0x1
	.byte	0x56
	.quad	.LVL128
	.quad	.LFE6017
	.word	0x1
	.byte	0x56
	.quad	0
	.quad	0
.LVUS15:
	.uleb128 .LVU100
	.uleb128 .LVU105
	.uleb128 .LVU105
	.uleb128 .LVU107
	.uleb128 .LVU107
	.uleb128 .LVU147
	.uleb128 .LVU246
	.uleb128 .LVU252
	.uleb128 .LVU253
	.uleb128 .LVU257
	.uleb128 .LVU257
	.uleb128 .LVU261
	.uleb128 .LVU358
	.uleb128 .LVU371
.LLST15:
	.quad	.LVL28
	.quad	.LVL30
	.word	0x3
	.byte	0x9
	.byte	0xff
	.byte	0x9f
	.quad	.LVL30
	.quad	.LVL31-1
	.word	0x1
	.byte	0x50
	.quad	.LVL31-1
	.quad	.LVL46
	.word	0x1
	.byte	0x54
	.quad	.LVL71
	.quad	.LVL73
	.word	0x1
	.byte	0x54
	.quad	.LVL74
	.quad	.LVL76
	.word	0x3
	.byte	0x9
	.byte	0xff
	.byte	0x9f
	.quad	.LVL76
	.quad	.LVL79
	.word	0x1
	.byte	0x54
	.quad	.LVL121
	.quad	.LVL128
	.word	0x1
	.byte	0x54
	.quad	0
	.quad	0
.LVUS16:
	.uleb128 .LVU100
	.uleb128 .LVU107
	.uleb128 .LVU253
	.uleb128 .LVU257
.LLST16:
	.quad	.LVL28
	.quad	.LVL31
	.word	0x3
	.byte	0x9
	.byte	0xff
	.byte	0x9f
	.quad	.LVL74
	.quad	.LVL76
	.word	0x3
	.byte	0x9
	.byte	0xff
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS17:
	.uleb128 .LVU156
	.uleb128 .LVU246
	.uleb128 .LVU261
	.uleb128 .LVU358
	.uleb128 .LVU371
	.uleb128 0
.LLST17:
	.quad	.LVL47
	.quad	.LVL71
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL79
	.quad	.LVL121
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL128
	.quad	.LFE6017
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS18:
	.uleb128 .LVU168
	.uleb128 .LVU170
	.uleb128 .LVU170
	.uleb128 .LVU171
	.uleb128 .LVU171
	.uleb128 .LVU172
	.uleb128 .LVU172
	.uleb128 .LVU174
	.uleb128 .LVU174
	.uleb128 .LVU177
	.uleb128 .LVU278
	.uleb128 .LVU279
	.uleb128 .LVU322
	.uleb128 .LVU325
.LLST18:
	.quad	.LVL50
	.quad	.LVL51
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL51
	.quad	.LVL52
	.word	0x1
	.byte	0x50
	.quad	.LVL52
	.quad	.LVL53
	.word	0x1
	.byte	0x5c
	.quad	.LVL53
	.quad	.LVL54
	.word	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.quad	.LVL54
	.quad	.LVL55
	.word	0x1
	.byte	0x50
	.quad	.LVL87
	.quad	.LVL88
	.word	0x1
	.byte	0x50
	.quad	.LVL109
	.quad	.LVL110
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS19:
	.uleb128 .LVU261
	.uleb128 .LVU262
	.uleb128 .LVU262
	.uleb128 .LVU263
	.uleb128 .LVU263
	.uleb128 .LVU264
	.uleb128 .LVU264
	.uleb128 .LVU266
	.uleb128 .LVU266
	.uleb128 .LVU269
	.uleb128 .LVU269
	.uleb128 .LVU274
.LLST19:
	.quad	.LVL79
	.quad	.LVL80
	.word	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL80
	.quad	.LVL81
	.word	0x1
	.byte	0x50
	.quad	.LVL81
	.quad	.LVL82
	.word	0x1
	.byte	0x5c
	.quad	.LVL82
	.quad	.LVL83
	.word	0x3
	.byte	0x70
	.sleb128 -1
	.byte	0x9f
	.quad	.LVL83
	.quad	.LVL84
	.word	0x1
	.byte	0x50
	.quad	.LVL84
	.quad	.LVL85
	.word	0x1
	.byte	0x5c
	.quad	0
	.quad	0
.LVUS20:
	.uleb128 .LVU200
	.uleb128 .LVU246
	.uleb128 .LVU274
	.uleb128 .LVU278
	.uleb128 .LVU283
	.uleb128 .LVU286
	.uleb128 .LVU315
	.uleb128 .LVU322
	.uleb128 .LVU334
	.uleb128 .LVU336
.LLST20:
	.quad	.LVL64
	.quad	.LVL71
	.word	0x1
	.byte	0x5d
	.quad	.LVL85
	.quad	.LVL87
	.word	0x1
	.byte	0x5d
	.quad	.LVL89
	.quad	.LVL90
	.word	0x1
	.byte	0x5d
	.quad	.LVL104
	.quad	.LVL109
	.word	0x1
	.byte	0x5d
	.quad	.LVL115
	.quad	.LVL117
	.word	0x1
	.byte	0x5d
	.quad	0
	.quad	0
.LVUS0:
	.uleb128 0
	.uleb128 .LVU8
	.uleb128 .LVU8
	.uleb128 .LVU15
	.uleb128 .LVU15
	.uleb128 0
.LLST0:
	.quad	.LVL0
	.quad	.LVL1
	.word	0x1
	.byte	0x52
	.quad	.LVL1
	.quad	.LVL4
	.word	0x1
	.byte	0x54
	.quad	.LVL4
	.quad	.LFE5979
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS1:
	.uleb128 .LVU12
	.uleb128 0
.LLST1:
	.quad	.LVL3
	.quad	.LFE5979
	.word	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LVUS2:
	.uleb128 0
	.uleb128 .LVU23
	.uleb128 .LVU23
	.uleb128 .LVU24
	.uleb128 .LVU24
	.uleb128 .LVU47
	.uleb128 .LVU47
	.uleb128 .LVU48
	.uleb128 .LVU48
	.uleb128 .LVU55
	.uleb128 .LVU55
	.uleb128 0
.LLST2:
	.quad	.LVL5
	.quad	.LVL6
	.word	0x1
	.byte	0x52
	.quad	.LVL6
	.quad	.LVL7-1
	.word	0x1
	.byte	0x51
	.quad	.LVL7-1
	.quad	.LVL12
	.word	0x1
	.byte	0x54
	.quad	.LVL12
	.quad	.LVL13
	.word	0xb
	.byte	0x72
	.sleb128 0
	.byte	0x33
	.byte	0x24
	.byte	0x71
	.sleb128 0
	.byte	0x22
	.byte	0x6
	.byte	0x23
	.uleb128 0x2010
	.quad	.LVL13
	.quad	.LVL17
	.word	0x1
	.byte	0x54
	.quad	.LVL17
	.quad	.LFE6018
	.word	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LVUS3:
	.uleb128 .LVU28
	.uleb128 .LVU31
	.uleb128 .LVU31
	.uleb128 .LVU46
	.uleb128 .LVU46
	.uleb128 .LVU48
	.uleb128 .LVU48
	.uleb128 .LVU50
	.uleb128 .LVU50
	.uleb128 .LVU54
.LLST3:
	.quad	.LVL9
	.quad	.LVL10-1
	.word	0x1
	.byte	0x50
	.quad	.LVL10-1
	.quad	.LVL11
	.word	0x1
	.byte	0x53
	.quad	.LVL11
	.quad	.LVL13
	.word	0x7
	.byte	0x72
	.sleb128 0
	.byte	0x33
	.byte	0x24
	.byte	0x71
	.sleb128 0
	.byte	0x22
	.quad	.LVL13
	.quad	.LVL14-1
	.word	0x1
	.byte	0x50
	.quad	.LVL14-1
	.quad	.LVL16
	.word	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LVUS4:
	.uleb128 .LVU48
	.uleb128 .LVU52
.LLST4:
	.quad	.LVL13
	.quad	.LVL15
	.word	0x1
	.byte	0x54
	.quad	0
	.quad	0
	.section	.debug_aranges,"dr"
	.long	0x4c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	.LFB5979
	.quad	.LFE5979-.LFB5979
	.quad	.LFB6017
	.quad	.LFE6017-.LFB6017
	.quad	0
	.quad	0
	.section	.debug_ranges,"dr"
.Ldebug_ranges0:
	.quad	.LBB7
	.quad	.LBE7
	.quad	.LBB17
	.quad	.LBE17
	.quad	.LBB36
	.quad	.LBE36
	.quad	0
	.quad	0
	.quad	.LBB10
	.quad	.LBE10
	.quad	.LBB12
	.quad	.LBE12
	.quad	.LBB13
	.quad	.LBE13
	.quad	0
	.quad	0
	.quad	.LBB21
	.quad	.LBE21
	.quad	.LBB22
	.quad	.LBE22
	.quad	.LBB23
	.quad	.LBE23
	.quad	.LBB24
	.quad	.LBE24
	.quad	.LBB25
	.quad	.LBE25
	.quad	.LBB26
	.quad	.LBE26
	.quad	.LBB27
	.quad	.LBE27
	.quad	0
	.quad	0
	.quad	.Ltext0
	.quad	.Letext0
	.quad	.LFB5979
	.quad	.LFE5979
	.quad	.LFB6017
	.quad	.LFE6017
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
.LASF10:
	.ascii "__mingw_vfprintf\0"
.LASF12:
	.ascii "GlobalAlloc\0"
.LASF7:
	.ascii "ioctlsocket\0"
.LASF9:
	.ascii "__acrt_iob_func\0"
.LASF6:
	.ascii "WSASocketA\0"
.LASF11:
	.ascii "GetLastError\0"
.LASF0:
	.ascii "refcount\0"
.LASF2:
	.ascii "GlobalFree\0"
.LASF4:
	.ascii "WSAGetLastError\0"
.LASF1:
	.ascii "closesocket\0"
.LASF8:
	.ascii "WSACleanup\0"
.LASF3:
	.ascii "__WSAFDIsSet\0"
.LASF5:
	.ascii "WSAStartup\0"
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	atoi;	.scl	2;	.type	32;	.endef
	.def	__WSAFDIsSet;	.scl	2;	.type	32;	.endef
