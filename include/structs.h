#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct t_format
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
	int		flag_zero;
	int		width;
	int		precision;
	char	specifier;
}	s_format;

#endif
