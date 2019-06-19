RED=\e[1;31m%s\e[0m
GRN=\e[1;32m%s\e[0m
YEL=\e[1;33m%s\e[0m

NAME = libgmath.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ../libft

INCLUDES = -I ./includes\
	-I $(LIBFT_PATH)/includes\

LIBS = $(LIBFT_PATH)/libft.a

SRC_CAMERA = camera_mat.c\
	rotate_camera.c\

SRC_COMPLEX = complex_operator.c\
	complex_coord.c\

SRC_MAT = identity_mat.c\
	mat4_operator.c\
	scale_mat.c\
	translate_mat.c\

SRC_VEC = vec4_operator.c\
	zero_vec.c\
	normalize.c\

SRC_QUATERNION = quaternion_operator.o\
	q_rotate.o\

SRC_PROJECTION = parallel_projection.o\
	perspective_projection.o\

SRC_POLYGON = polygon_coefficient.o\
	new_polygon.o\

OBJS = $(addprefix $(OBJDIR)/, $(SRC_CAMERA:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_COMPLEX:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_MAT:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_VEC:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_QUATERNION:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_PROJECTION:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_POLYGON:.c=.o))

$(OBJDIR)/%.o : $(SRCDIR)/camera/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/complex/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/mat4/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/vec4/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/quaternion/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/projection/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJDIR)/%.o : $(SRCDIR)/polygon/%.c $(INCDIR)/gmath.h
	@printf "$(YEL)\n" "-> compile $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME) : $(LIBS) $(OBJDIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIBS) :
	@printf "$(GRN)\n" "-> compile libft"
	$(MAKE) -C $(LIBFT_PATH) all

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re $(LIBS)
