all: bisect bisect_b

bisect: bisect.cc
	g++ -Wall -Wextra -O3 -flto -o bisect bisect.cc

bisect_b: bisect_b.cc
	g++ -Wall -Wextra -O3 -flto -o bisect_b bisect_b.cc

clean:
	-rm -f bisect bisect_b
