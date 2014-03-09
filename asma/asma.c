

void asma(unsigned char *s, unsigned char *t, unsigned char *u){
	int i;
	for (i=0; i <16; i++)
		u[i] = (s[i]<t[i]) ? s[i] : t[i];
}