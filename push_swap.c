/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemerci <mlemerci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:21:22 by mlemerci          #+#    #+#             */
/*   Updated: 2024/12/31 04:02:47 by mlemerci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack new_stack(void)
{
    return NULL;
}

bool empty_stack(stack b)
{
    if (b == NULL)
        return true;

    return false;
}

/*-------------------------------------------*/

stack pop_stack(stack b)
{
    stack_element *element;

    if(empty_stack(b))
        return new_stack();

    element = b->next;
        free(b);

        return element;
}

/*-------------------------------------------*/

void print_stack(stack b)
{
    if (empty_stack(b))
    {
        ft_printf("R.A.S.\n");
    return ;
    }
    while(!empty_stack(b))
    {
        ft_printf("[%d]\n, b->value");
        b = b->next;
    }
}

/*------------------------------------------*/

int stack_length(stack b)
{
    int length = 0;

    while(empty_stack(b))
    {
        length++;
        b = b->next;
    }
    return length;
}

/*------------------------------------------*/

int top_stack(stack b)
{
    if(empty_stack(b))
    {
        ft_printf("NO TOP,VIDE\n");
        return ;
    }
    return b->value;
}

/*------------------------------------------*/

stack clear_stack(stack b)
{
    stack_element *element;
    if(empty_stack(b))
        return new_stack();

    element = b->next;
    free(b);

    return clear_stack(element);

or

    while(!empty_stack(b))
        b = pop_stack(b);

    return new_stack();
}

/*------------------------------------------*/

//return null a verifier l17 push_swap.c
// je crois que a = b et b = a

/*
si à la suite de l’exécution la pile a est bien triée et la pile b est vide, alors le
programme doit afficher "OK" suivi par un ’\n’ sur la sortie standard.
• Sinon, il doit afficher "KO" suivi par un ’\n’ sur la sortie standard.
• En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
un int, s’il y a des doublons ou, bien sûr, si une instruction n’existe pas ou est
mal formatée
*/

int main(void)
{
    stack a = new_stack();

    if(empty_stack(a))
 
    ft_print_stack(a);

    ft_printf("\n-------------------\n\n");

    a = push_stack(a, 3);
    a = push_stack(a, 6);
    a = push_stack(a, 12);
    a = push_stack(a, 24);
    a = push_stack(a, 42);
    ft_print_stack(a);
    ft_printf("ON THE TOP : %d\n", top_stack(a));

    ft_printf("\n-------------------\n\n");

    a = clear_stack(a);
    a = pop_stack(a);

    ft_print_stack(a);
}
