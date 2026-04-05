/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:38:16 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:18:15 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Applies a function
 * to each character of a string, modifying the string in place.
 *
 * The ft_striteri() function applies the function `f` to each character of the
 * string `s`. The function `f` takes the index of the character as its first
 * argument and a pointer to the character as its second argument. The function
 * modifies the string `s` in place.
 *
 * @param s The input string to be modified.
 * @param f The function to apply to each character of the string.
 *          The function `f` takes the index of the character and a pointer to
 *          the character as arguments.
 *
 * @return None.
 *
 * @note If `s` or `f` is NULL, the function does nothing.
 *
 *
 * ```c
 *
 * void to_upper(unsigned int i, char *c)
 * {
 *     (void)i;
 *     if (*c >= 'a' && *c <= 'z')
 *         *c -= 32;
 * }
 *
 * char str[] = "hello";
 * ft_striteri(str, to_upper);
 * printf("%s\n", str); // Output: "HELLO"
 *
 * ```
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
