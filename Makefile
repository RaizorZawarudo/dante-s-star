##
## EPITECH PROJECT, 2021
## B-CPE-200-BER-2-1-dante-renan.dubois
## File description:
## Makefile
##

CFLAGS = -g3 -W -Wall -Wextra

all:
	cd generator/ && make
	cd ../
	cd solver/ && make
	cd ..

clean:
	cd generator/ && make clean
	cd ../
	cd solver/ && make clean
	cd ..

fclean:
	cd generator/  && make fclean
	cd ../
	cd solver/ && make fclean
	cd ..

re: fclean all

unit_test:
	gcc -lcriterion

.PHONY: all clean fclean re