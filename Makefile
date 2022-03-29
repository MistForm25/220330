a.out: main.c
	gcc -g3 main.c
.PHONY: test
test: a.out
	@./a.out < test/basic_1.in.txt | cmp test/basic_1.out.txt
	@echo "OK!"
