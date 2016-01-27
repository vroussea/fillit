/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:37:38 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/26 12:21:03 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# define BUF_SIZE 546

typedef struct		s_tetr
{
	char			**tetrimino;
	int				x;
	int				y;
	char			nbr;
	struct s_tetr	*next;
}					t_tetr;

int					init_tetri(char *source, t_tetr **start);
int					new_list(char *buf, t_tetr **start);
int					check_symbols(char *buf, int size);
int					check_size(char *buf, int size);
int					check_size_tetri(char **tetri);
int					check_next(char **tetri);
int					check_next2(char **tetri);
int					backtrack_tetr(t_tetr *start, t_tetr *tetr, int size);
void				printer(t_tetr *ptr, int size);
#endif
