# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rlucas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/20 10:00:23 by rlucas        #+#    #+#                  #
#    Updated: 2020/03/13 12:56:36 by rlucas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------------------------------------------

DIR = src/

NAME = libasm.a

LIBRARIES = libasm.a

HEADDIR = includes/

TESTDIR = tests/

TESTEXEC = testexec

#-----------------------------Select sources------------------------------------

ASM = $(DIR)ft_write.s \
	  $(DIR)ft_read.s \
	  $(DIR)ft_strlen.s \
	  $(DIR)ft_strcpy.s \
	  $(DIR)ft_strcmp.s \
	  $(DIR)ft_strdup.s

BONUS = $(DIR)ft_atoi_bonus.s \
		$(DIR)ft_atoi_base_bonus.s \
		$(DIR)ft_strchr_bonus.s \
		$(DIR)ft_list_push_front_bonus.s \
		$(DIR)ft_list_size_bonus.s \
		$(DIR)ft_list_sort_bonus.s \
		$(DIR)ft_list_remove_if_bonus.s

ifdef WITH_BONUS
	ASM += $(BONUS)
endif

SRC = $(TESTDIR)nocrit_main.c \
	  $(TESTDIR)write_tests.c \
	  $(TESTDIR)read_tests.c \
	  $(TESTDIR)strlen_tests.c \
	  $(TESTDIR)strcpy_tests.c \
	  $(TESTDIR)strcmp_tests.c \
	  $(TESTDIR)strdup_tests.c

CRITSRC = $(TESTDIR)tests.c \
	  $(TESTDIR)testmain.c

BONUSCRITSRC = $(TESTDIR)testmain_bonus.c \
		   $(TESTDIR)tests_bonus.c

ifdef WITH_BONUS
	SRC += $(BONUSSRC)
	CRITSRC += $(BONUSCRITSRC)
endif

BONUSOBJ = $(patsubst $(TESTDIR)%.c, $(ODIR)%.o,$(BONUSCRITSRC) $(CRITSRC))

#----------------------------Select Objects-------------------------------------

ODIR = obj/
ASMOBJ = $(patsubst $(DIR)%.s,$(ODIR)%.o,$(ASM))
ifdef CRIT
	OBJ = $(patsubst $(TESTDIR)%.c,$(ODIR)%.o,$(CRITSRC))
else
	OBJ = $(patsubst $(TESTDIR)%.c,$(ODIR)%.o,$(SRC))
endif
ALLOBJ = $(patsubst $(DIR)%.s,$(ODIR)%.o,$(ASM) $(BONUS)) \
		 $(OBJ) \
		 $(BONUSOBJ)

#------------------------Library and Flags definitions--------------------------

HEADERS = $(HEADDIR)libasm.h \
		  $(HEADDIR)libasm_bonus.h
FLAGS = -Wall -Wextra -Werror

#------------------------------Compile Library----------------------------------

all: $(NAME)

$(NAME): $(ASMOBJ)
	@ar -rc $(NAME) $(ASMOBJ)

#-----------------------------Compile with bonus--------------------------------

bonus:
	@$(MAKE) WITH_BONUS=1 all

bonuscrittest:
	@$(MAKE) WITH_BONUS=1 CRIT=1 test

#--------------------------Compile test executable (normal)---------------------

test: $(OBJ) $(NAME)
ifdef CRIT
	@gcc $(FLAGS) -I$(HEADDIR) -o $(TESTEXEC) $(OBJ) -L. \
		-l$(subst .a,,$(subst lib,,$(NAME))) \
		-lcriterion
else
	@gcc $(FLAGS) -I$(HEADDIR) -o $(TESTEXEC) $(OBJ) -L. \
		-l$(subst .a,,$(subst lib,,$(NAME)))
endif

#--------------------------Compile test executable (criterion)------------------

crittest:
	@$(MAKE) CRIT=1 test

#-------------Create and fill objects directory with *.c sources----------------

$(OBJ): $(SRC) $(HEADERS)
	@mkdir -p $(ODIR)
	@gcc $(FLAGS) -I$(HEADDIR) -c -o $@ $(patsubst $(ODIR)%.o, $(TESTDIR)%.c,$@)

#-------------Create and fill objects directory with assembly sources-----------

$(ASMOBJ): $(ASM)
	@mkdir -p $(ODIR)
	@nasm -fmacho64 -o $@ $(patsubst $(ODIR)%.o,$(DIR)%.s,$@)

#------------------------Utility Make Instructions------------------------------

clean:
	@rm -f $(ALLOBJ)
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(TESTEXEC)
	@rm -f $(LIBRARIES)

re: fclean all

#-----------------------------Phony instructions--------------------------------

.PHONY: clean fclean all re bonus bonuscrittest crittest test
