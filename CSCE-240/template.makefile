GPP = g++ -O3 -g -Wall -Wpedantic # was the O3 really necessary?
PROGRAM = <name here>
SOURCE = $(PROGRAM).cpp
OUT = $(PROGRAM).o

$(PROGRAM): $(OUT)
        $(GPP) -o $(PROGRAM) $(OUT)

$(OUT): $(SOURCE)
        $(GPP) -o $(OUT) -c $(SOURCE)

$(PROGRAM).s: $(SOURCE)
	$(GPP) -S $(SOURCE)

.PHONY: clean test assembly

clean:
	rm -f $(PROGRAM) $(OUT) output $(PROGRAM).s

test: $(PROGRAM)
	./$(PROGRAM) | tee > output

assembly: $(PROGRAM).s

