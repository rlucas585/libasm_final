# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_write.s                                         :+:    :+:             #
#                                                      +:+                     #
#    By: rlucas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/19 15:56:05 by rlucas        #+#    #+#                  #
#    Updated: 2020/06/23 13:34:05 by rlucas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

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
