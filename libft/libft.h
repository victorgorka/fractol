/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:28:32 by vde-prad          #+#    #+#             */
/*   Updated: 2023/02/18 16:38:46 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
//*******************STANDARD LIBRARIES*************************************
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# define BUFFER_SIZE 1000000
//************************FUNCTIONS******************************************

//tests for any printing character
int		ft_isprint(int c);

//tests for any digit character
int		ft_isdigit(int c);

//tests for any ascii character 
int		ft_isascii(int c);

//tests for any alphabetic character
int		ft_isalpha(int c);

//coverts lower case to upper case
int		ft_toupper(int c);

//converts upper case to lower case
int		ft_tolower(int c);

//tests for any character for which isalpha(3) or isdigit(3) is true.
int		ft_isalnum(int c);

//copies n bytes from memory area src to memory area dst. Overlap undefined
void	*ft_memcpy(void *dst, const void *src, size_t n);

//writes len bytes of value c (converted to an unsigned char) to the string b.
void	*ft_memset(void *b, int c, size_t len);

//copies len bytes from string src to string dst.  The two strings may overlap
void	*ft_memmove(void *dst, const void *src, size_t len);

//writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.
void	ft_bzero(void *s, size_t n);

//computes the length of the string s
size_t	ft_strlen(const char *s);

//copy and concatenate strings
//take the full size of the destination buffer and guarantee NUL-termination
//copies up to dstsize - 1 characters from the string src to dst, 
//NUL-terminating the result if dstsize is not 0.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

//appends string src to the end of dst
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

//locates the ocurrence of the character in the string
char	*ft_strchr(const char *s, int c);

//locates the last ocurrence of the character in the string
//return an integer greater than, equal to, or less than 0
char	*ft_strrchr(const char *s, int c);

//locates the first occurrence of c (converted to an unsigned char) in string s.
void	*ft_memchr(const void *s, int c, size_t n);

//compares byte string s1 against byte string s2.  
//Both strings are assumed to be n bytes long.
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//locates the first occurrence of the null-terminated string needle
// in the string haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

//converts the initial portion of the string pointed to by
//str to int representation.
int		ft_atoi(const char *str);

//allocates enough space for count objects that are size
//bytes of memory each and returns a pointer to the allocated memory.
//The allocated memory is filled with bytes of value zero.
void	*ft_calloc(size_t count, size_t size);

//allocates sufficient memory for a copy of the string s1, 
//does the copy, and returns a pointer to it
char	*ft_strdup(const char *s1);

/*
Reserva (con malloc(3)) y devuelve una substring de
la string ’s’.
La substring empieza desde el índice ’start’ y
tiene una longitud máxima ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
Reserva (con malloc(3)) y devuelve una nueva
string, formada por la concatenación de ’s1’ y
’s2’.

Valor devuelto: La nueva string.
NULL si falla la reserva de memoria.
*/
char	*ft_strjoin(char const *s1, char const *s2);

//Elimina todos los caracteres de la string ’set’
//desde el principio y desde el final de ’s1’, hasta
//encontrar un caracter no perteneciente a ’set’. La
//string resultante se devuelve con una reserva de
//malloc(3)
char	*ft_strtrim(char const *s1, char const *set);

//Reserva (utilizando malloc(3)) un array de strings
//resultante de separar la string ’s’ en substrings
//utilizando el caracter ’c’ como delimitador. El
//array debe terminar con un puntero NULL.
char	**ft_split(char const *s, char c);

//Utilizando malloc(3), genera una string que
//represente el valor entero recibido como argumento.
//Los números negativos tienen que gestionarse.
char	*ft_itoa(int n);

//A cada carácter de la string ’s’, aplica la
//función ’f’ dando como parámetros el índice de cada
//carácter dentro de ’s’ y el propio carácter. Genera
//una nueva string con el resultado del uso sucesivo
//de ’f
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//A cada carácter de la string ’s’, aplica la función
//’f’ dando como parámetros el índice de cada
//carácter dentro de ’s’ y la dirección del propio
//carácter, que podrá modificarse si es necesario.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//Envía el carácter ’c’ al file descriptor
//especificado.
void	ft_putchar_fd(char c, int fd);

//Envía la string ’s’ al file descriptor
//especificado.
void	ft_putstr_fd(char *s, int fd);

//Envía la string ’s’ al file descriptor dado,
//seguido de un salto de línea.
void	ft_putendl_fd(char *s, int fd);

//Envía el número ’n’ al file descriptor dado.
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Crea un nuevo nodo utilizando malloc(3). La
//variable miembro ’content’ se inicializa con el
//contenido del parámetro ’content’. La variable
//’next’, con NULL.
t_list	*ft_lstnew(void *content);

//Añade el nodo ’new’ al principio de la lista ’lst’.
void	ft_lstadd_front(t_list **lst, t_list *new);

//devuelve tamaño de la lista
int		ft_lstsize(t_list *lst);

//devuelve ultimo nodo
t_list	*ft_lstlast(t_list *lst);

//añade el nodo 'new' al final de la lista 'lst'
void	ft_lstadd_back(t_list **lst, t_list *new);

//libera contenido de nodo 'lst' y el propio nodo
void	ft_lstdelone(t_list *lst, void (*del)(void *));

//elimina y libera el nodo al que apunta el puntero 
//pasado por parametro
void	ft_lstclear(t_list **lst, void (*del)(void *));

//itera la lista y aplica 'f' a cada nodo
void	ft_lstiter(t_list *lst, void (*f)(void *));

//Itera la lista ’lst’ y aplica la función ’f’ al
//contenido de cada nodo. Crea una lista resultante
//de la aplicación correcta y sucesiva de la función
//’f’ sobre cada nodo. La función ’del’ se utiliza
//para eliminar el contenido de un nodo, si hace
//falta.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//GNL utils
int		ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strdup_gnl(const char *s1);

//GNL
char	*get_next_line(int fd);
#endif
