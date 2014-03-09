
void asmb(unsigned char *s, unsigned char *t, unsigned char *u){
	int i;
	for (i=0; s[i] && t[i]; i++)
		u[i] = (s[i]<t[i]) ? s[i] : t[i];
	u[i] = '\0';
}