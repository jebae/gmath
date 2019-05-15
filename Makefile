NAME = libgmath.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/mat4/*.c\
	srcs/vec4/*.c\
	srcs/quaternion/*.c\
	srcs/camera/*.c\

INCLUDES = -I ./includes\

OBJS = identity_mat.o\
	mat4_operator.o\
	scale_mat.o\
	translate_mat.o\
	vec4_operator.o\
	zero_vec.o\
	normalize.o\
	quaternion_operator.o\
	q_rotate.o\
	camera_rotate.o\

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) :
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
