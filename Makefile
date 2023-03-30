
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
				src/sort \
				src/free
OBJECTDIR	=	obj
INCLUDEDIR	=	inc

LIBMXDIR	=	libmx

INCLUDEINC	=	$(addprefix -I, $(INCLUDEDIR))
LIBINC		=	$(addprefix -I, libmx/inc)

LIBLINK		=	-L$(LIBMXDIR) -lmx 

SRC_FILES	=	$(foreach dir, $(SOURCEDIR), $(wildcard $(dir)/*.c))
OBJ_FILES	=	$(addprefix $(OBJECTDIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES	=	$(foreach dir, $(INCLUDEDIR), $(wildcard $(dir)/*.h))
LBA = libmx.a

all: $(LBA) $(NAME) clean


print:
	@echo $(INC_FILES)

$(LBA):
	@make -sC $(LIBMXDIR) all
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
	@make -sC $(LIBMXDIR) clean
	@rm -rf $(OBJECTDIR)
	@echo "$@ $(COLOUR_GREEN)finished$(COLOUR_END)"

reinstall: uninstall all
