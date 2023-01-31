include ../include/include.mk

make: 
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) mandelbrot.c $(LIB) -o $(OUTDIR)/mandelbrot

clean: 
	rm -rf $(OUTDIR) 
