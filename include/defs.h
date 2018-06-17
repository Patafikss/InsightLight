#ifndef DEFS_H
#define DEFS_H

#ifdef MSG_DEBUG
#include <iostream>
#define DOUT std::cerr

#else
class log_disabled_output {};
static log_disabled_output log_disabled_output_instance;

template<typename T>
log_disabled_output& operator << (log_disabled_output& any, T const& thing) { return any; }

#define DOUT log_disabled_output_instance
#endif

#endif // DEFS_H
