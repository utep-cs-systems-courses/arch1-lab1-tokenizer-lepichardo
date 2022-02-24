#default rule
CFLAGS=-g -O3 #-g for debug, and -O3for optimization

# File dependencies
tokenizer.o: tokenizer.h
uimain.o: tokenizer.h
uimain.o: history.h

tokenizer: uimain.o tokenizer.o history.o
	cc -o $@ $^ $(CFLAGS)


#tokenizer depends on all object files
clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer
