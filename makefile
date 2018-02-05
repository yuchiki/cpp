.PHONY: run clean
run: main.c incdec.c
	gcc -E -P -w main.c

incdec.c: inccreate.rb
	ruby inccreate.rb > incdec.c

clean:
	rm -rf incdec.c