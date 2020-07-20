; Assembly ft_write

; ft_write prototype:
; ssize_t	ft_write(int fildes, void *buf, size_t nbyte);

			global		_ft_write
			extern		___error

_ft_write:	push		rbx
			mov			rax, 0x2000004
			syscall
			jc			err
			pop			rbx
			ret

err:		mov			rbx, rax
			call		___error
			mov			[rax], rbx
			mov			rax, -0x01
			pop			rbx
			ret
