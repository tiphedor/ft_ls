/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_styling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteffen <msteffen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:22:42 by msteffen          #+#    #+#             */
/*   Updated: 2018/02/05 15:24:19 by msteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_styling.h"

static char	*ft_printf_formats(char *str)
{
	str = ft_strreplace(str, "{BOLD}", "\e[1m");
	str = ft_strreplace(str, "{/BOLD}", "\e[21m");
	str = ft_strreplace(str, "{BLINK}", "\e[5m");
	str = ft_strreplace(str, "{/BLINK}", "\e[25m");
	str = ft_strreplace(str, "{DIM}", "\e[2m");
	str = ft_strreplace(str, "{/DIM}", "\e[22m");
	str = ft_strreplace(str, "{UNDER}", "\e[4m");
	str = ft_strreplace(str, "{/UNDER}", "\e[24m");
	str = ft_strreplace(str, "{REVERSE}", "\e[7m");
	str = ft_strreplace(str, "{/REVERSE}", "\e[27m");
	str = ft_strreplace(str, "{HIDDEN}", "\e[8m");
	str = ft_strreplace(str, "{/HIDDEN}", "\e[28m");
	str = ft_strreplace(str, "{/RESET_FORMAT}", "\e[0m");
	return (str);
}

static char	*ft_printf_fg_colors(char *str)
{
	str = ft_strreplace(str, "{FG_DEF}", "\e[39m");
	str = ft_strreplace(str, "{FG_BLACK}", "\e[30m");
	str = ft_strreplace(str, "{FG_RED}", "\e[31m");
	str = ft_strreplace(str, "{FG_GREEN}", "\e[32m");
	str = ft_strreplace(str, "{FG_YELLOW}", "\e[33m");
	str = ft_strreplace(str, "{FG_BLUE}", "\e[34m");
	str = ft_strreplace(str, "{FG_MAGENTA}", "\e[35m");
	str = ft_strreplace(str, "{FG_CYAN}", "\e[36m");
	str = ft_strreplace(str, "{FG_LGRAY}", "\e[37m");
	str = ft_strreplace(str, "{FG_DGRAY}", "\e[90m");
	str = ft_strreplace(str, "{FG_LRED}", "\e[91m");
	str = ft_strreplace(str, "{FG_LGREEN}", "\e[92m");
	str = ft_strreplace(str, "{FG_LYELLOW}", "\e[93m");
	str = ft_strreplace(str, "{FG_LBLUE}", "\e[94m");
	str = ft_strreplace(str, "{FG_LMAGENTA}", "\e[95m");
	str = ft_strreplace(str, "{FG_LCYAN}", "\e[96m");
	str = ft_strreplace(str, "{FG_WHITE}", "\e[97m");
	return (str);
}

static char	*ft_printf_bg_colors(char *str)
{
	str = ft_strreplace(str, "{BG_DEF}", "\e[49m");
	str = ft_strreplace(str, "{BG_BLACK}", "\e[40m");
	str = ft_strreplace(str, "{BG_RED}", "\e[41m");
	str = ft_strreplace(str, "{BG_GREEN}", "\e[42m");
	str = ft_strreplace(str, "{BG_YELLOW}", "\e[43m");
	str = ft_strreplace(str, "{BG_BLUE}", "\e[44m");
	str = ft_strreplace(str, "{BG_MAGENTA}", "\e[45m");
	str = ft_strreplace(str, "{BG_CYAN}", "\e[46m");
	str = ft_strreplace(str, "{BG_LGRAY}", "\e[47m");
	str = ft_strreplace(str, "{BG_DGRAY}", "\e[100m");
	str = ft_strreplace(str, "{BG_LRED}", "\e[101m");
	str = ft_strreplace(str, "{BG_LGREEN}", "\e[102m");
	str = ft_strreplace(str, "{BG_LYELLOW}", "\e[103m");
	str = ft_strreplace(str, "{BG_LBLUE}", "\e[104m");
	str = ft_strreplace(str, "{BG_LMAGENTA}", "\e[105m");
	str = ft_strreplace(str, "{BG_LCYAN}", "\e[106m");
	str = ft_strreplace(str, "{BG_WHITE}", "\e[107m");
	return (str);
}

char		*ft_printf_stylize(char *str)
{
	str = ft_printf_formats(str);
	str = ft_printf_fg_colors(str);
	str = ft_printf_bg_colors(str);
	return (str);
}
