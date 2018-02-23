GPP = g++ -O3 -Wall -Wpedantic
OUT = hello-world.o

hello-world: $(OUT)
	$(GPP) -o hello-world $(OUT)

$(OUT): hello-world.cpp
	$(GPP) -o $(OUT) -c hello-world.cpp

hello-world.s: hello-world.cpp
	$(GPP) -S hello-world.cpp

.PHONY: clean test

clean:
	rm -f hello-world $(OUT) output

test: hello-world
	./hello-world | tee > output

assembly: hello-world.s
