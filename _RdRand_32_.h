#ifndef _RDRAND_32_H
#define _RDRAND_32_H

#include<immintrin.h>

class _RdRand_32_{
	private:
 union buffer{
	unsigned long long rand64;
	unsigned int rand32[2];
 } buf;
 bool Stored = false;
	public:
 inline unsigned int operator()(void);

 inline unsigned int min(void);
 inline unsigned int max(void);
 typedef unsigned int result_type;
};

#pragma GCC target("rdrnd")
inline unsigned int _RdRand_32_::operator()(void){
 if(Stored){
	Stored = false;
	return buf.rand32[1];
 }
 else{
	while(!_rdrand64_step( &buf.rand64 ));
	Stored = true;
	return buf.rand32[0];
 }
}
#pragma GCC reset_options

inline unsigned int _RdRand_32_::min(void){
 return 0;
}

inline unsigned int _RdRand_32_::max(void){
 return 4294967295U;
}

#endif
