/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:04:58 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/22 11:22:23 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	int				nb;
	int				num;
	int				flag;
	int				file;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	int				len;
	int				mediane;
	int				second_mediane;
	int				c;
	int				c2;
}					t_data;

typedef struct		s_opt
{
	int				v;
	int				f;
	int				beg;
	int				color;
}					t_opt;

t_list				*ft_create_list(int nb);
t_list				*ft_last_elem(t_list *lst);
void				ft_lst_add(t_list **beg_lst, long long nb);
void				ft_swap(t_list *lst);
void				ft_push(t_list **src, t_list **dest);
void				ft_rotate(t_list **beg_lst);
void				ft_reverse_rotate(t_list **beg_lst);
int					ft_check_list(t_list *lst_a, t_list *lst_b);
int					ft_min(t_list *lst);
int					ft_max(t_list *lst);

int					get_next_line(const int fd, char **line);
int					ft_strlen(char *str);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
int					ft_strcmp(const char *s1, const char *s2);
long long			ft_atoi(const char *nptr);

void				ft_print_list(t_list *lst);

int					ft_check_line(char **line, t_list **lst_a, t_list **lst_b);
int					ft_check_str(char *str);
int					check(t_list *lst_a);

void				ft_exit(t_list **lst_a, t_list **lst_b);
void				ft_exit_a(t_list **lst_a);
void				ft_exit_b(t_list **lst_b);

void				ft_tri(t_list **lst_a, t_list **lst_b);

int					ft_lst_len(t_list *lst);
int					ft_median(t_list *lst, int size);
void				ft_tri_tab(int tab[], int size);
int					ft_second_median(t_list *lst, int size);

void				ft_sa(t_list **lst_a, t_list **lst_b);
void				ft_sb(t_list **lst_a, t_list **lst_b);
void				ft_ss(t_list **lst_a, t_list **lst_b);
void				ft_pb(t_list **lst_a, t_list **lst_b);
void				ft_pa(t_list **lst_a, t_list **lst_b);
void				ft_ra(t_list **lst_a, t_list **lst_b);
void				ft_rb(t_list **lst_a, t_list **lst_b);
void				ft_rr(t_list **lst_a, t_list **lst_b);
void				ft_rra(t_list **lst_a, t_list **lst_b);
void				ft_rrb(t_list **lst_a, t_list **lst_b);
void				ft_rrr(t_list **lst_a, t_list **lst_b);

void				ft_a_to_b(t_list **lst_a, t_list **lst_b,
					t_list **lst_c, int len);
void				ft_b_to_a(t_list **lst_a, t_list **lst_b, t_list **lst_c);

int					ft_is_sup_a(t_list *lst, int len, int nb);
int					ft_is_inf_b(t_list *lst, int len, int nb);
int					ft_is_sup_b_start(t_list *lst, int len, int nb);
int					ft_is_inf_b_start(t_list *lst, int len, int nb);

int					ft_is_tri_a(t_list *lst, int len);
int					ft_is_tri_b(t_list *lst, int len);
void				ft_lst_c_del(t_list **lst_c);
void				ft_lst_del(t_list **lst);

void				ft_little_tri(t_list **lst_a, t_list **lst_b);
void				ft_tri_3_a(t_list **lst_a, t_list **lst_b);
void				ft_tri_inf3_a(t_list **lst_a, t_list **lst_b, int len);

void				ft_count_med(t_list **lst_b, t_list **lst_c,
					int mediane, int c);
void				ft_count_sec_med(t_list **lst_b, t_list **lst_c,
					int mediane, int c);

void				ft_tri_2_btoa(t_list **lst_a, t_list **lst_b);
void				ft_tri_3_btoa(t_list **lst_a, t_list **lst_b);
void				ft_tri_inf3_btoa(t_list **lst_a, t_list **lst_b, int len);

void				ft_start_a_to_b(t_list **lst_a, t_list **lst_b,
					t_list **lst_c);
void				ft_first_start_a_to_b(t_list **lst_a, t_list **lst_b,
					t_list **lst_c);
void				ft_a_to_b(t_list **lst_a, t_list **lst_b, t_list **lst_c,
					int len);
void				ft_b_to_a(t_list **lst_a, t_list **lst_b, t_list **lst_c);

void				ft_affichage(t_list **lst_a, t_list **lst_b);

#endif
