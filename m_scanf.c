#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BLOCK 80
#define STDIN 0
#define STDOUT 1

void m_scanf(char* sente,...);  //scanf����̊֐�

int main(){
	int a = 0 , a1 = 0;
	char b[ 50 ] , b1[ 50 ];
	char c = 0 , c1 = 0;
	int x = 0;

	while( 1 ){
		
		/* ������start */
		a  = 0;
		a1 = 0;
		c  = 0;
		c1 = 0;
		for( int i = 0 ; i < 50 ; i++ ){ 
			b[ i ] = 0;
			b1[ i ] = 0;
		}
		/* ������end */
		
		printf( "���߂�Ƃ��A-1�����:" );
		scanf( "%d" , &x );
		if( x == -1 ) break;

		m_scanf( "%d %s %c" , &a , b , &c );	//scanf����֐�
		
		printf( "-------------------------------------\n" );
		
		if( a !=0 && b != 0 && c != 0 )			//�o��
			printf( "%d\n%s%c\n" , a , b , c );
		
	}
	
	return 0;
}

void m_scanf( char* sente , ... ){		//scanf����֐�
	
	va_list list;
	char* cp;		//����sente������ϐ�

	va_start( list , sente );
	
	/* �ψ�����ǂݎ�郋�[�v */
	for( cp = sente ; *cp != '\0' ; cp++ ){
		
		if( *cp == '%' ){
			cp++;		//���̕���
			
			/* �����̎� */
			if( *cp == 'd' ){
				
				int len = 0;		//�ψ����̕�����
				int* value = 0;		//�ψ����̕ϐ�
				int atoii = 0;		//
				
				value = va_arg( list , int* );	//�ψ�����ǂݎ��
				
				do{
					
					len = read( STDIN , *( &value ) , BLOCK );
					
				}while( len == 0 );
				
				atoii = atoi( ( char* )value );	//char*�^��int�^
				*( value ) = atoii;
				
			/* ������̎� */
			}else if( *cp == 's' ){
				
				int len = 0;		//�ψ����̕�����
				char* a = 0;		//�ψ����̕ϐ�

				a = va_arg( list , char* );		//�ψ�����ǂݎ��
				
				do{
					
					len = read( STDIN , *( &a ) , BLOCK );
					
				}while( len == 0 );
				
			/* 1�����̎� */
			}else if( *cp == 'c' ){
				
				int len = 0;		//�ψ����̕�����
				char* b = 0;		//�ψ����̕ϐ�

				b = va_arg( list , char* );		//�ψ�����ǂݎ��
				
				do{
					
					len = read( STDIN , *( &b ) , 1 );
					
				}while( len == 0 );
			}	
		}
	}
	
	va_end( list );
}