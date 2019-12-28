# gmath

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/2896cdcf3e864345af1210ba83da5ac6)](https://www.codacy.com/manual/jebae/gmath?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/gmath&amp;utm_campaign=Badge_Grade)

C library **gmath** is made to easily use graphical math related with vector, matrix and quaternion.

<br><br>

## Requirements

This library is using [libft](https://github.com/jebae/libft).

```
# download libft
git clone https://github.com/jebae/libft.git

# directory structure
root/
  libft/
  gmath/
```

Instead of putting libft in same path with gmath, you can modify [Makefile](./Makefile) macro `LIBFT_PATH = ../libft`.

<br><br>

## Features

### vector

```c
typedef struct	s_vec4
{
	float	arr[4];
}		t_vec4;

// get zero vector
t_vec4 zero_vec(void);

// dot product
float vec_dot_vec(t_vec4 *v1, t_vec4 *v2);

// scalar multiplication
t_vec4 scalar_mul_vec(float scalar, t_vec4 *v);

// add
t_vec4 vec_plus_vec(t_vec4 *v1, t_vec4 *v2);

// subtract
t_vec4 vec_sub_vec(t_vec4 *v1, t_vec4 *v2);

// cross product
t_vec4 vec_cross_vec(t_vec4 *v1, t_vec4 *v2);

// get norm of vector
float vec_norm(t_vec4 *v);

// get normalized vector
t_vec4 normalize(t_vec4 *v);
```

<br>

### matrix

```c
typedef struct	s_mat4
{
	float	arr[4][4];
}		t_mat4;

// get 4 x 4 identity matrix
t_mat4 identity_mat(void);

// matrix multiply vector
t_vec4 mat_mul_vec(t_mat4 *m, t_vec4 *v);

// matrix multiply matrix
t_mat4 mat_mul_mat(t_mat4 *m1, t_mat4 *m2);

// get scaling matrix
t_mat4 scale_mat(float scale);

// get translation matrix
t_mat4 translate_mat(float x, float y, float z);

// get transposed matrix
t_mat4 mat_transpose(t_mat4 *mat);

// get determinant of 3 x 3 matrix
float mat3_det(t_mat4 *mat);

// get cramer solution as vec4
t_vec4 mat3_cramer_solution(
	t_mat4 *a,
	t_vec4 *b,
	int *solution_found
);
```

<br>

### complex number

```c
typedef struct	s_complex
{
	double	r;
	double	i;
}		t_complex;

// add
t_complex cmplx_plus_cmplx(t_complex *c1, t_complex *c2);

// get conjugate complex (a + bi -> a - bi)
t_complex conjugate(t_complex *c);

// multiplacation
t_complex cmplx_mul_cmplx(t_complex *c1, t_complex *c2);

// get zoomed coordinate
t_complex complex_coord_zoom(t_complex_coord_zoom_args *args);
```

<br>

### quaternion

```c
typedef struct	s_quaternion
{
	float	x;
	float	y;
	float	z;
	float	w;
}		t_quaternion;

// multiplication
t_quaternion q_mul_q(t_quaternion *q1, t_quaternion *q2);

// get rotation q with axis and angle
t_quaternion rotate_q(t_vec4 *n, float theta);

// get q^(-1)
t_quaternion inverse_q(t_quaternion *q);

// rotate vector with q and q^(-1)
t_vec4 rotate(t_quaternion *q, t_vec4 *v, t_quaternion *q_i);
```

<br>

### polygon

```c
typedef struct		s_polygon
{
	size_t		v_count;
	struct s_vec4	*vertices;
	int		line_color;
	int		fill_color;
}			t_polygon;

// make new polygon
t_polygon new_polygon(size_t v_count, int line_color,\
	int fill_color);

// get coefficient of polygon formula
t_polygon_coefficient polygon_coefficient(t_polygon *polygon);
```

<br>

### camera

```c
typedef struct	s_camera
{
	t_vec4	pos;
	t_vec4	x_axis;
	t_vec4	y_axis;
	t_vec4	z_axis;
	float	zoom;
	float	roll;
}		t_camera;

// camera axis
void set_camera_z_axis(t_camera *cam, t_vec4 *focus);
void set_camera_y_axis(t_camera *cam);
void set_camera_x_axis(t_camera *cam);
void set_camera_axis(t_camera *cam, t_vec4 *focus);

// get matrix of camera coordinate (assume camera locates at (0, 0, 0))
t_mat4 camera_basis_mat(t_camera *cam);

// get world to camera coordinate matrix
t_mat4 world_to_cam_coord_mat(t_camera *cam);

// rotate camera
void rotate_camera(
	t_camera *cam,
	t_vec4 *axis,
	t_vec4 *axis_foot,
	float theta
);

```

<br>

### projection

```c
// parallel
t_vec4 parallel_projection(t_vec4 *vertex);

// get z index value from coordinate when parallel projection
float cal_parallel_proj_z(
	int x,
	int y,
	t_polygon_coefficient *co
);

// perspective
t_vec4 perspective_projection(t_vec4 *vertex);

// get z index value from coordinate when perspective projection
float cal_perspective_proj_z(
	int x,
	int y,
	t_polygon_coefficient *co
);
```