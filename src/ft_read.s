; Assembly ft_read

; ft_read prototype:
; ssize_t	ft_read(int fildes, void *buf, size_t nbyte);

			global		_ft_read
			extern		___error

_ft_read:	push		rbx
			mov			rax, 0x2000003
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
