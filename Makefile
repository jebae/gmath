NAME = libgmath.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/mat4/*.c\
	srcs/vec4/*.c\
	srcs/quaternion/*.c\
	srcs/camera/*.c\
	srcs/projection/*.c\
	srcs/polygon/*.c\

INCLUDES = -I ./includes\
	-I ../libft/includes\

OBJS = identity_mat.o\
	mat4_operator.o\
	scale_mat.o\
	translate_mat.o\
	vec4_operator.o\
	zero_vec.o\
	normalize.o\
	quaternion_operator.o\
	q_rotate.o\
	camera_mat.o\
	rotate_camera.o\
	parallel_projection.o\
	perspective_projection.o\
	polygon_coefficient.o\
	new_polygon.o\

LIBS = ../libft/libft.a

all : $(NAME)

$(NAME) : $(LIBS) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBS) :
	$(MAKE) -C ../libft all

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

clean :
	$(MAKE) -C ../libft clean
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) -C ../libft fclean
	rm -rf $(NAME)

re : fclean all
