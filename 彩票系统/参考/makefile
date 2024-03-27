#main makefile
Target:= main
Depend:= menu.o
Depend+= main.o
Depend+= user.o
Depend+= cread_head.o
Depend+= admin.o
Depend+= fun.h
$(Target):$(Depend)
	gcc $^ -o $@
%o:%c
	gcc -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o
