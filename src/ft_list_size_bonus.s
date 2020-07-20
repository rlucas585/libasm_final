; Assembly ft_list_size

; ft_list_size prototype:
;	int	ft_list_size(t_list *begin_list)

; A t_list has size 16

; rdi = *begin_list

				global		_ft_list_size

_ft_list_size:
				push		rbp
				mov			rbp, rsp

				xor			rax, rax	; rax = 0

loop:
				test		rdi, rdi
				jz			exit

				inc			rax			; rax++
				mov			rcx, [rdi + 8]	; rcx = current->next
				mov			rdi, rcx	; current = current->next
				jmp			loop


exit:
				mov			rsp, rbp
				pop			rbp
				ret
