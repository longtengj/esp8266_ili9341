#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	char *p;
	char *name;
	int wf = 0;
	int rf = 0;
	int size = 0;
	int count = 0;
	int errors = 0;
	FILE *FP;
	unsigned int *buffer;

	for(i=1;i<argc;++i)
	{
		p = argv[i];
		if(p == NULL)
			break;
		if(*p == '-')
		{
			++p;
			if(*p == 'w')
			{
				name = argv[++i];
				wf = 1;
				continue;
			}
			if(*p == 'r')
			{
				name = argv[++i];
				rf = 1;
				continue;
			}
			if(*p == 's')
			{
				++p;
				if(*p)
					size = strtol(p, NULL,16);
				else
					size = strtol(argv[++i], NULL,16);
				continue;
			}
		}
	}

	if(!size || (!rf && !wf))
	{
		fprintf(stderr,"Usage: %s [-w filename ]|[-r filename] -s size\n", argv[0]);
		exit(1);
	}

	buffer = (unsigned int *) calloc(size,1);
	if(!buffer)
	{
		fprintf(stderr,"Can not alocate %d bytes\n", size);
		exit(1);
	}

	if(wf)
	{
		FP = fopen(name,"w");
		if(!FP)
		{
			fprintf(stderr,"Can not open %s for writting\n", name);
			free((void *) buffer);
			exit(1);
		}
		for(i=0;i<size/4;++i)
		{
			buffer[i] = i;
		}
		count = fwrite(buffer, 1, size,FP);
		fclose(FP);
		free((void *) buffer);
		if(count != size)
		{
			fprintf(stderr,"wrote:%08x bytes, expected:%08x bytes\n", count, size);
		}
	}
	if(rf)
	{
		FP = fopen(name,"r");
		if(!FP)
		{
			fprintf(stderr,"Can not open %s for writting\n", name);
			free((void *) buffer);
			exit(1);
		}
		count = fread(buffer, 1, size,FP);
		fclose(FP);
		if(count != size)
		{
			fprintf(stderr,"read:%08x bytes, expected:%08x bytes\n", count, size);
			free((void *) buffer);
			exit(1);
		}
		for(i=0;i<size/4;++i)
		{
			if(buffer[i] != i) 
			{
				fprintf(stderr,"addr:%08x, expected:%08x, got:%08x\n",
					i * 4, i, buffer[i]);
				++errors;
			}
		}
		free((void *) buffer);
	}
	return(0);
}
