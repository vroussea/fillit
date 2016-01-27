/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 21:22:01 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/26 18:23:27 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	size_tab(int nb)
{
	int	size;

	nb = nb * 4;
	size = nb;
	while ((size = ft_sqrt(size)) == -1)
	{
		nb++;
		size = nb;
	}
	return (size);
}

static int	main_helper(int nb, t_tetr *start)
{
	int	valid;

	valid = 0;
	while (!valid)
	{
		valid = backtrack_tetr(start, start, nb);
		nb++;
	}
	if (valid == 0)
	{
		ft_putendl("error");
		return (0);
	}
	printer(start, --nb);
	return (1);
}

static void	free_lst(t_tetr *start)
{
	int		i;
	t_tetr	*ptr;

	while (start != NULL)
	{
		ptr = start;
		i = 0;
		while (i < 4)
		{
			ft_memdel((void **)(&(start->tetrimino[i])));
			i++;
		}
		ft_memdel((void **)(start->tetrimino));
		start = start->next;
		ft_memdel((void **)(&ptr));
	}
}

int			main(int argc, char **argv)
{
	t_tetr	*start;
	int		nb;

	start = NULL;
	if (argc == 2)
	{
		if ((nb = init_tetri(argv[1], &start)) == -1)
		{
			ft_putendl("error");
			free_lst(start);
			return (0);
		}
		nb = size_tab(nb);
		main_helper(nb, start);
	}
	else
	{
		ft_putendl("error");
		return (0);
	}
	free_lst(start);
	return (1);
}
