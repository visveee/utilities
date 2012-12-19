#ifndef H_toksplit_h
# define H_toksplit_h

# ifdef __cplusplus
extern "C" {
# endif
unsigned char *toksplit(unsigned char *src, /* Source of tokens */
char tokchar, /* token delimiting char */
unsigned char *token, /* receiver of parsed token */
int lgh); /* length token can receive */

# ifdef __cplusplus
}
# endif
#endif
