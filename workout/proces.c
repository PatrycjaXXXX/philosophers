/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:42:47 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/12 15:13:45 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>   // dla fork(), getpid(), getppid()
#include <sys/types.h>

int main() {
	pid_t pid;
	int	i = 0;
	// Tworzymy nowy proces
	pid = fork();

	if (pid < 0) {
		// Błąd podczas tworzenia procesu
		perror("Błąd fork()");
		return 1;
	} 
	else if (pid == 0) {
		// Kod wykonywany przez proces potomny
		while (i < 4)
			i++;
		printf("%i\n", i);
		printf("To jest proces potomny! PID = %d, rodzic PID = %d\n", getpid(), getppid());
	} 
	else {
		// Kod wykonywany przez proces rodzica
		while (i < 3)
			i++;
		printf("%i\n", i);
		printf("To jest proces rodzicielski! PID = %d, PID potomka = %d\n", getpid(), pid);
	}

	return 0;
}
