; Assembly ft_strlen

; ft_strlen prototype: size_t	ft_strlen(const char *s);

			global		_ft_strlen

_ft_strlen:
			push		rbp
			mov			rbp, rsp
			xor			rax, rax
loop:
			mov			cl, BYTE [rdi + rax]
			test		cl, cl
			jz			exit
			inc			rax
			jmp			loop

exit:
			mov			rsp, rbp
			pop			rbp
			ret
