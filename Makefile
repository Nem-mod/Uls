# NAME	=	uls
# CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g
# COMP 	= 	clang


# INC		=	libmx.h
# INCS	=	$(addprefix $(INCD)/, $(INC))
# LMXDIR	=	libmx
# OBJECTDIR = obj
# INCLUDEDIR = inc
# SOURCEDIR = src

# LBA = libmx/libmx.a 
# LBMX = libmx
# LBI = libmx/inc/

# SRC_FILES = $(wildcard $(SOURCEDIR)/*.c)
# OBJ_FILES = $(addprefix $(OBJECTDIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
# INC_FILES = $(wildcard $(INCLUDEDIR)/*.h)


# all: $(LBA) $(NAME) clean

# $(NAME): $(OBJ_FILES)
# 	@$(COMP) $(CFLAGS) $(OBJ_FILES) -L$(LBMX) -lmx -o $@ --debug

# $(OBJ_FILES): | $(OBJECTDIR)

# $(OBJECTDIR)/%.o: $(SOURCEDIR)/%.c $(INC_FILES)
# 	@$(COMP) $(CFLAGS) -c $< -o $@ -I $(INCLUDEDIR) -I$(LBI) 

# $(OBJECTDIR):
# 	@$ mkdir -p $@

# $(LBA):
# 	@make -sC libmx all

# clean:
# 	rm -rf $(OBJECTDIR)
# 	@make -C libmx clean

# uninstall: clean
# 	rm -rf $(NAME)
# 	@make -C libmx uninstall

# reinstall: uninstall all

NAME	=	uls
CFLAGS 	=	-std=c11 $(addprefix -W, all extra error pedantic) 
COMP 	= 	clang

COLOUR_GREEN	=	\033[32;1m
# COLOUR_RED		=	\033[0;31m
# COLOUR_BLUE		=	\033[0;34m
COLOUR_END		=	\033[0m

SOURCEDIR 	=	src \
				src/create \
				src/get \
				src/print \
				src/sort
OBJECTDIR	=	obj
INCLUDEDIR	=	inc

LIBMXDIR	=	libmx

INCLUDEINC	=	$(addprefix -I, $(INCLUDEDIR))
LIBINC		=	$(addprefix -I, libmx/inc)

LIBLINK		=	-L$(LIBMXDIR) -lmx 

SRC_FILES	=	$(foreach dir, $(SOURCEDIR), $(wildcard $(dir)/*.c))
OBJ_FILES	=	$(addprefix $(OBJECTDIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES	=	$(foreach dir, $(INCLUDEDIR), $(wildcard $(dir)/*.h))

all: libs $(NAME) clean

libs: libmx

print:
	@echo $(INC_FILES)

libmx:
	@make -sC $(LIBMXDIR)
	@echo "$@ $(COLOUR_GREEN)created$(COLOUR_END)"

$(NAME): $(OBJECTDIR) copy $(OBJ_FILES)
	@$(COMP) $(CFLAGS) $(OBJ_FILES) $(LIBLINK) -o $@ --debug

$(OBJ_FILES): %.o: %.c
	@$(COMP) $(CFLAGS) -c $< -o $@ $(INCLUDEINC) $(LIBINC) --debug
	@echo "$@ $(COLOUR_GREEN)compiled$(COLOUR_END)"

$(OBJECTDIR):
	@mkdir -p $@
	@echo "$@ $(COLOUR_GREEN)created$(COLOUR_END)"

copy:
	@cp -f $(SRC_FILES) $(OBJECTDIR)

uninstall: clean
	@make -sC $(LIBMXDIR) $@
	@rm -rf $(NAME)
	@echo "$@ $(COLOUR_GREEN)finished$(COLOUR_END)"

clean:
	@make -sC $(LIBMXDIR) $@
	@rm -rf $(OBJECTDIR)
	@echo "$@ $(COLOUR_GREEN)finished$(COLOUR_END)"

reinstall: uninstall all
