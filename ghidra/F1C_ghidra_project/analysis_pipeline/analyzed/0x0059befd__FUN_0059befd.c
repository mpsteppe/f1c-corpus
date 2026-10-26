// Function: FUN_0059befd @ 0059befd
// Size (bytes): 28


exception * __thiscall FUN_0059befd(exception *param_1,byte param_2)

{
  exception::~exception(param_1);
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


