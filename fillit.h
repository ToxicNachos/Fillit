/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:24:19 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/10 19:00:54 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define VAL_MACRO int i = 0, new_lines = 0, pieces = 0, dot = 0;
# define SPLIT_PIECES char **boxes = NULL; int box = 0, s; SPLIT_PIECES2;
# define SPLIT_PIECES2 char ***coords = NULL; int i = 0; BOX_COUNT; SIZE_MAP;
# define BOX_COUNT int box_count = ft_piece_count(str); int q = -1;
# define SIZE_MAP int map_size = ft_sqrt_up(box_count * 4); BOX_MALLOC;
# define BOX_MALLOC boxes = ft_box_malloc(boxes, box_count);
# define MOVE_LEFT while (++q < box_count) coords[q] = ft_move_left(coords[q]);
# define FUCK_IT while (s < BOX_SIZE - 1) boxes[box][s++] = *str++;
# define MOVE_X_Y int x; int y;
# define COORDS_MACRO int a = 0; int b; int c; char	***coords = NULL;
# define MAP_MACRO char **map = NULL; int x = 0; int y; int i = -1;
# define CRDS_MACRO int **crds = NULL; int x = -1; int y = 0;
# define PIECE_MACRO int **crds = NULL; int x = -1, y; CHAR_MACRO;
# define CHAR_MACRO char l = 'A' + box_num; int current[3];
# define PIECE_MACRO2 int cx = 0, a = 0, cy;
# define CURRENT_MACRO current[0] = x; current[1] = y; current[2] = size;
# define EXIT_MACRO write(1, "error\n", 6); exit(-1);
# define MAX_FILLIT_FILE 545
# define LINE_SIZE 5
# define CUSHION 10
# define BOX_SIZE 21

int			ft_validate_piece(char *str);
int			ft_piece_count(char *str);
char		**ft_split_pieces(char *str);
char		**ft_make_map(int p);
char		**ft_remake_map(char **map, int p);
int			**ft_getpiece(char **box);
void		ft_placer(char ***coords, int size);
void		ft_print_map(char **map);
void		ft_strdel(char **as);
char		**ft_move_left(char **box);
int			ft_sqrt_up(int n);

#endif
