# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	printf "$(KGRN)[gmath]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# lib name
NAME = libgmath.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ../libft

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\

# srcs
SRC_CAMERA = camera_axis.c\
	camera_coord.c\
	rotate_camera.c\

SRC_COMPLEX = complex_operator.c\
	complex_coord.c\

SRC_MAT = identity_mat.c\
	mat4_operator.c\
	scale_mat.c\
	translate_mat.c\

SRC_VEC = vec4_operator.c\
	vec4_operator2.c\
	zero_vec.c\
	normalize.c\

SRC_QUATERNION = quaternion_operator.c\
	q_rotate.c\

SRC_PROJECTION = parallel_projection.c\
	perspective_projection.c\

SRC_POLYGON = polygon_coefficient.c\
	new_polygon.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_CAMERA:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_COMPLEX:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_MAT:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_VEC:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_QUATERNION:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_PROJECTION:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_POLYGON:.c=.o))

# compile objs
HEADERS = $(INCDIR)/gmath.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(LIBFT_PATH)/includes/get_next_line.h\

$(OBJDIR)/%.o : $(SRCDIR)/camera/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/complex/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/mat4/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/vec4/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/quaternion/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/projection/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/polygon/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[gmath] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[gmath] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re
