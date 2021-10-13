all: project0

project0: 
	gcc project0.c -o project0

nproj:
	gcc nproj.c -o nproj

clean:
	rm project0
	rm nproj
