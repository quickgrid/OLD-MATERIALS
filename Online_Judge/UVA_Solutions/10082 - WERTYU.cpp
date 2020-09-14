/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10082 WERTYU ( using c++ string stream )
 */

#include<cstdio>
#include<sstream>
#include<iostream>

static const char kb[64] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
static char s[256];

int main(){
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(0);
    register int i, j;

	while(gets(s)){
        std::stringstream ss;

        for(i = 0; s[i]; ++i){
            if(s[i] == ' ')
                ss << ' ';
            else{
                for(j = 0; kb[j]; ++j){
                    /**
                     * Each character maps to a character in its left as defined
                     */
                    if(s[i] == kb[j])
                        ss << kb[j - 1];
                }
            }
        }
        std::cout << ss.str() << "\n";
	}
	return 0;
}
