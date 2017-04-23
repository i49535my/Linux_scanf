#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BLOCK 80
#define STDIN 0
#define STDOUT 1

void m_scanf(char* sente,...);  //scanf動作の関数

int main(){
	int a = 0 , a1 = 0;
	char b[ 50 ] , b1[ 50 ];
	char c = 0 , c1 = 0;
	int x = 0;

	while( 1 ){
		
		/* 初期化start */
		a  = 0;
		a1 = 0;
		c  = 0;
		c1 = 0;
		for( int i = 0 ; i < 50 ; i++ ){ 
			b[ i ] = 0;
			b1[ i ] = 0;
		}
		/* 初期化end */
		
		printf( "辞めるとき、-1を入力:" );
		scanf( "%d" , &x );
		if( x == -1 ) break;

		m_scanf( "%d %s %c" , &a , b , &c );	//scanf動作関数
		
		printf( "-------------------------------------\n" );
		
		if( a !=0 && b != 0 && c != 0 )			//出力
			printf( "%d\n%s%c\n" , a , b , c );
		
	}
	
	return 0;
}

void m_scanf( char* sente , ... ){		//scanf動作関数
	
	va_list list;
	char* cp;		//引数senteを入れる変数

	va_start( list , sente );
	
	/* 可変引数を読み取るループ */
	for( cp = sente ; *cp != '\0' ; cp++ ){
		
		if( *cp == '%' ){
			cp++;		//次の文字
			
			/* 数字の時 */
			if( *cp == 'd' ){
				
				int len = 0;		//可変引数の文字数
				int* value = 0;		//可変引数の変数
				int atoii = 0;		//
				
				value = va_arg( list , int* );	//可変引数を読み取る
				
				do{
					
					len = read( STDIN , *( &value ) , BLOCK );
					
				}while( len == 0 );
				
				atoii = atoi( ( char* )value );	//char*型→int型
				*( value ) = atoii;
				
			/* 文字列の時 */
			}else if( *cp == 's' ){
				
				int len = 0;		//可変引数の文字数
				char* a = 0;		//可変引数の変数

				a = va_arg( list , char* );		//可変引数を読み取る
				
				do{
					
					len = read( STDIN , *( &a ) , BLOCK );
					
				}while( len == 0 );
				
			/* 1文字の時 */
			}else if( *cp == 'c' ){
				
				int len = 0;		//可変引数の文字数
				char* b = 0;		//可変引数の変数

				b = va_arg( list , char* );		//可変引数を読み取る
				
				do{
					
					len = read( STDIN , *( &b ) , 1 );
					
				}while( len == 0 );
			}	
		}
	}
	
	va_end( list );
}