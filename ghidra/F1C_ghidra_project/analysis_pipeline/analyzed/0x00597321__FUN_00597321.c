// Function: FUN_00597321 @ 00597321
// Size (bytes): 28


bool FUN_00597321(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;
  
  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}


