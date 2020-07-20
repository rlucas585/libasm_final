; Assembly language ft_list_push_front

; ft_list_push_front prototype:
;	void	*ft_list_push_front(t_list **begin_list, void *data);

; t_list has size 16

; rdi = **begin_list
; rsi = *data

				global		_ft_list_push_front
				extern		_malloc
				
_ft_list_push_front:
				push		rbp
				mov			rbp, rsp

				test		rdi, rdi
				jz			err

				sub			rsp, 8
				mov			[rsp], rdi	; Storing **begin_list in stack
				sub			rsp, 8
				mov			[rsp], rsi	; Storing *data in stack

				mov			rdi, 16		; bytes to allocate
				call		_malloc		
				test		rax, rax	; check 'rax' == NULL
				jz			err			; Allocation failure
										
				mov			rcx, [rsp]	; places *data in 'rcx'
				mov			[rax], rcx	; new->data = data
				mov			rdx, [rsp + 8]
				mov			rcx, [rdx]
				mov			[rax + 8], rcx	; new->next = head (or NULL)
										
assign_head:
				mov			rcx, [rsp + 8]		; place **begin_list in rcx
				mov			[rcx], rax			; *begin_list = new

err:
				mov			rsp, rbp
				pop			rbp
				ret
				
