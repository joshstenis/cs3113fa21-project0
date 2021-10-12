all: project0

project0: 
	gcc project0.c -o project0

t_binary:
	gcc t_binar.c -o t_binary
clean:
	rm project0
	rm t_binary
