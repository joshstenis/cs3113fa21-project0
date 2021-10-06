all: project0 t_shrink

project0: 
	gcc project0.c -o project0

t_shrink:
	gcc t_shrink.c -o t_shrink

clean:
	rm project0
	rm t_shrink
