NAME	=	uls
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang


INC		=	libmx.h
INCS	=	$(addprefix $(INCD)/, $(INC))
LMXDIR	=	libmx
OBJECTDIR = obj
INCLUDEDIR = inc
SOURCEDIR = src

LBA = libmx/libmx.a 
LBMX = libmx
LBI = libmx/inc/

SRC_FILES = $(wildcard $(SOURCEDIR)/*.c)
OBJ_FILES = $(addprefix $(OBJECTDIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard $(INCLUDEDIR)/*.h)


all: $(LBA) $(NAME) clean

$(NAME): $(OBJ_FILES)
	@$(COMP) $(CFLAGS) $(OBJ_FILES) -L$(LBMX) -lmx -o $@

$(OBJ_FILES): | $(OBJECTDIR)

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.c $(INC_FILES)
	@$(COMP) $(CFLAGS) -c $< -o $@ -I $(INCLUDEDIR) -I$(LBI) 

$(OBJECTDIR):
	@$ mkdir -p $@

$(LBA):
	@make -sC libmx all

clean:
	rm -rf $(OBJECTDIR)
	@make -C libmx clean

uninstall: clean
	rm -rf $(NAME)
	@make -C libmx uninstall

reinstall: uninstall all
