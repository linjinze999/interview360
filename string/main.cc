#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

	//test =
	qh::string s0 = NULL;
	qh::string s1 = "";
	qh::string s2 = "abc";
	qh::string s3 = "abc\0";
	qh::string s4 = "abc\0def";
	assert( s0.data() == NULL && s0.size() == 0 );
	assert( strcmp( "", s1.data() ) == 0 && s1.size() == 0 );
	assert( strcmp( "abc", s2.data() ) == 0 && s2.size() == 3 );
	assert( strcmp( "abc\0", s3.data() ) == 0 && s3.size() == 3 );
	assert( strcmp( "abc\0def", s4.data() ) == 0 && s4.size() == 3 );

	//test string()
	qh::string t = qh::string();
	assert( t.data() == NULL && t.size() == 0);

	//test string(const char* s)
	qh::string t0(NULL);
	qh::string t1("");
	qh::string t2("abc\0def");
	assert( t0.data() == NULL  && t0.size() == 0);
	assert( strcmp( "", t1.data() ) == 0 && t1.size() == 0);
	assert( strcmp( "abc\0def", t2.data() ) == 0 && t2.size() == 3);

	//test string(const char* s, size_t len)
	qh::string r0(NULL,0);
	qh::string r1(NULL,1);
	qh::string r2("",0);
	qh::string r3("abc\0def",1);
	qh::string r4("abc\0def",10);
	assert( r0.data() == NULL && r0.size() == 0);
	assert( r1.data() == NULL && r1.size() == 0);
	assert( strcmp( "", r2.data() ) == 0 && r2.size() == 0);
	assert( strcmp( "a", r3.data() ) == 0 && r3.size() == 1);
	assert( strcmp( "abc\0def", r4.data() ) == 0 && r4.size() == 3);
	
	//test string(const string& rhs)
	qh::string i0(NULL);
	qh::string i1("");
	qh::string i2("abc\0def");
	qh::string i3(i0);
	qh::string i4(i1);
	qh::string i5(i2);
	assert( i3.data() == NULL && i3.size() == 0);
	assert( strcmp( "", i4.data() ) == 0 && i4.size() == 0);
	assert( strcmp( "abc\0def", i5.data() ) == 0 && i5.size() == 3);

	//test ~string();
	qh::string n0(NULL);
	qh::string n1("");
	qh::string n2("abc\0def");
	n0.~string();
	n1.~string();
	n2.~string();
	assert( n0.data() == NULL && n0.size() == 0);
	assert( n1.data() == NULL && n1.size() == 0);
	assert( n2.data() == NULL && n2.size() == 0);

	//test size()/data()/c_str()
	qh::string g0(NULL);
	qh::string g1("");
	qh::string g2("abc\0def");
	assert( g0.size() == 0 && g0.data() == NULL && g0.c_str() == NULL );
	assert( g1.size() == 0 && strcmp( "", g1.data() ) == 0 && strcmp( "\0", g1.c_str() ) == 0 );
	assert( g2.size() == 3 && strcmp( "abc\0def", g2.data() ) == 0 && strcmp( "abc\0def\0", g2.c_str() ) == 0 );

	//test []
	qh::string str0(NULL);
	qh::string str1("");
	qh::string str2("abc\0def");
	assert( str0[0] == NULL );
	assert( str1[0] == '\0' );
	assert( str1[2] == '\0' );
	assert( *str2[2] == 'c' );
	assert( str2[10] == NULL );
	*str2[0] = '1';
	assert( *str2[0] == '1' );
	printf("All test OK!\n");

#ifdef WIN32
    system("pause");
#endif

	return 0;
}
