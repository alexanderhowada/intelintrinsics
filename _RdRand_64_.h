#ifndef _RdRand_64_H
#define _RdRand_64_H

#include<immintrin.h>

class _RdRand_64_{
	public:
 inline unsigned long long operator()(void);

 inline unsigned long long min(void);
 inline unsigned long long max(void);

 typedef unsigned long long result_type;
};

#pragma GCC target("rdrnd")
inline unsigned long long _RdRand_64_::operator()(void){
 unsigned long long buf;
 while(!_rdrand64_step( &buf ));
 return buf;
}
#pragma GCC reset_options

inline unsigned long long _RdRand_64_::min(void){
 return 0;
}

inline unsigned long long _RdRand_64_::max(void){
 return 18446744073709551615U;
}

#endif
