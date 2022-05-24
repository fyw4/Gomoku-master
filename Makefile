all:
	cd ./client && make
	cd ./server && make

.PHONY = clean
clean:
	rm ./bin/*