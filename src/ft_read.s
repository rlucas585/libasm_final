# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_read.s                                          :+:    :+:             #
#                                                      +:+                     #
#    By: rlucas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/20 10:39:44 by rlucas        #+#    #+#                  #
#    Updated: 2020/06/23 13:25:28 by rlucas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

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
