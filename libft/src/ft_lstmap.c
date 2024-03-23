/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:21:08 by dgiurgev          #+#    #+#             */
/*   Updated: 2024/02/04 05:21:47 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*create_new_node(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

void	clean_up_new_list(t_list **newlist, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *newlist;
	while (current)
	{
		next = current->next;
		if (del != NULL)
			del(current->content);
		free(current);
		current = next;
	}
	*newlist = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	**last;
	t_list	*newnode;
	void	*newcontent;

	newlist = NULL;
	last = &newlist;
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = create_new_node(newcontent);
		if (!newnode)
		{
			clean_up_new_list(&newlist, del);
			if (del != NULL)
				del(newcontent);
			return (NULL);
		}
		*last = newnode;
		last = &newnode->next;
		lst = lst->next;
	}
	return (newlist);
}
