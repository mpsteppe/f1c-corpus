// Function: FUN_00560b60 @ 00560b60
// Size (bytes): 38


undefined4 * __thiscall FUN_00560b60(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  
  *param_1 = 0;
  pvVar1 = operator_new(param_2 * 4);
  param_1[1] = pvVar1;
  return param_1;
}


