#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "inc/FdF.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

void	ft_bzero(void *s, size_t n)
{
	size_t	cntr;

	cntr = 0;
	while (cntr < n && s)
	{
		*(unsigned char *)(s + cntr) = (unsigned char) 0;
		cntr++;
	}
}

//new code

float	**ft_apply_rot(float rotationMatrix[3][3], float vertices[8][3], int size_vertices)
{
	float	**result;
	int	ca;
	int	cb;
	int	cc;

	ca = 0;
	ft_bzero(result = malloc(size_vertices*sizeof(int*)), size_vertices*sizeof(int*));
	while (ca < size_vertices)
	{
		ft_bzero(result[ca++] = malloc(3*sizeof(int)), 3*sizeof(int));
	}
	ca = 0;
	while (ca < size_vertices)
	{
		cb = 0;
		while (cb < 3)
		{
			cc = 0;
			while (cc < 3)
			{
				//printf("ca: %i, cb: %i, cc: %i\n", ca, cb, cc);
				result[ca][cb] += rotationMatrix[cb][cc] * vertices[ca][cc];
				//printf("rotationMatrix: %f, vertices: %f, result: %f\n", rotationMatrix[cb][cc], vertices[ca][cc], result[ca][cb]);
				cc++;
			}
			cb++;
		}
		ca++;
	}
	return (result);
}

float	**ft_apply_proj(float projectionMatrix[2][3], float *rotationMatrix[3], int size_rm)
{
	float	**result;
	int	ca;
	int	cb;
	int	cc;

	ca = 0;
	ft_bzero(result = malloc(size_rm*sizeof(int*)), size_rm*sizeof(int*));
	while (ca < size_rm)
	{
		ft_bzero(result[ca++] = malloc(2*sizeof(int)), 2*sizeof(int));
	}
	ca = 0;
	while (ca < size_rm)
	{
		cb = 0;
		while (cb < 2)
		{
			cc = 0;
			while (cc < 3)
			{
				//printf("ca: %i, cb: %i, cc: %i\n", ca, cb, cc);
				//printf("projectionMatrix: %f, roationMatrix: %f\n", projectionMatrix[cb][cc], rotationMatrix[ca][cc]);
				result[ca][cb] += projectionMatrix[cb][cc] * rotationMatrix[ca][cc];
				//printf("projectionMatrix: %f, roationMatrix: %f, result: %f\n", projectionMatrix[cb][cc], rotationMatrix[ca][cc], result[ca][cb]);
				cc++;
			}
			cb++;
		}
		ca++;
	}
	return (result);
}

// void	calc_cube(float **rotmat, float** projmat, float **cubecord)
// {
// 	float	**resultRotation = ft_apply_rot(isometricRotation, cube_coords, 8);
// 	float	**resultProjection = ft_apply_proj(projectionMatrix, resultRotation, 8);
// 	int x;
// 	int y;

// 	for (size_t i = 0; i < 8; i++)
// 	{
// 		x = resultProjection[i][0];
// 		y = resultProjection[i][1];
// 	}
// }

int main()
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "FdF", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	
	float isometricRotation[3][3] = {
		{ cos(45), 0, -sin(45) },
		{ -0.55237, -0.76065, -0.34101 },
		{ -0.64724, 0.64916, -0.39958 }
	};

	float projectionMatrix[2][3] = { 
		{ 1, 0, 0 },
		{ 0, 1, 0 },
	};

	float cube_coords[8][3] = {
		{1, -1, -1},
		{-1, -1, -1},
		{1, 1, 1},
		{1, 0, -1},
		{0, 1, 1},
		{1, 1, 5},
		{2, 0, 5},
		{3, 0, 5}
	};

	float	**resultRotation = ft_apply_rot(isometricRotation, cube_coords, 8);
	float	**resultProjection = ft_apply_proj(projectionMatrix, resultRotation, 8);
	
	for (int i = 0; i < 8; i++){
		//printf("Rotation: x: %f, y: %f, z: %f\n", resultRotation[i][0], resultRotation[i][1], resultRotation[i][2]);
		//printf("Projection: x: %f, y: %f\n", nearbyintf(resultProjection[i][0]), nearbyintf(resultProjection[i][1]));
		mlx_put_pixel(image, (nearbyintf(resultProjection[i][0])*10)+WIDTH/2, (nearbyintf(resultProjection[i][1])*10)+HEIGHT/2, 0xFFFFFFFF);
	}
	//mlx_loop_hook(mlx, calc_cube, mlx);
	// mlx_loop_hook(mlx, ft_controls, mlx);
	
	for (matr)


	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// old code

// void ft_calc_line(int x1, int y1, int x2, int y2, int dx,
//                int dy, int decide)
// {
//     // pk is initial decision making parameter
//     // Note:x1&y1,x2&y2, dx&dy values are interchanged
//     // and passed in plotPixel function so
//     // it can handle both cases when m>1 & m<1
//     int pk = 2 * dy - dx;
//     for (int i = 0; i <= dx; i++) {
//         printf("x1: %i, y1: %i ", x1, y1);
//         // checking either to decrement or increment the
//         // value if we have to plot from (0,100) to (100,0)
//         x1 < x2 ? x1++ : x1--;
//         if (pk < 0) {
//             // decision value will decide to plot
//             // either  x1 or y1 in x's position
//             if (decide == 0) {
//                 mlx_put_pixel(image, x1, y1, 0xFFFFFF);
//                 pk = pk + 2 * dy;
//             }
//             else {
//                 //(y1,x1) is passed in xt
//                 mlx_put_pixel(image, y1, x1, 0xFFFFFF);
//                 pk = pk + 2 * dy;
//             }
//         }
//         else {
//             y1 < y2 ? y1++ : y1--;
//             if (decide == 0) {
 
//                 mlx_put_pixel(image, x1, y1, 0xFFFFFF);
//             }
//             else {
//                 mlx_put_pixel(image, y1, x1, 0xFFFFFF);
//             }
//             pk = pk + 2 * dy - 2 * dx;
//         }
//     }
// }

// void	ft_line(void *param)
// {
// 	int x1 = 100, y1 = 40, x2 = 2, y2 = 200, dx, dy, pk;
 
//     dx = abs(x2 - x1);
//     dy = abs(y2 - y1);
 
//     // If slope is less than one
//     if (dx > dy) {
 
//         // passing argument as 0 to plot(x,y)
//         ft_calc_line(x1, y1, x2, y2, dx, dy, 0);
//     }
 
//     // if slope is greater than or equal to 1
//     else {
 
//         // passing argument as 1 to plot (y,x)
//         ft_calc_line(y1, x1, y2, x2, dy, dx, 1);
//     }
// 	printf("\n");
// }

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_controls(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int	main(int argc, const char* argv[])
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "FdF", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_line, mlx);
// 	mlx_loop_hook(mlx, ft_controls, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
