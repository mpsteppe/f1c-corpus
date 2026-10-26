// Function: FUN_00459950 @ 00459950
// Size (bytes): 55


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00459950(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  double dVar1;
  
  dVar1 = _DAT_0059e420 / (double)CONCAT44(param_3,param_2);
  *(undefined4 *)(param_1 + 0x180) = param_2;
  *(undefined4 *)(param_1 + 0x184) = param_3;
  *(double *)(param_1 + 0x188) = dVar1;
  FUN_005697a0(param_4);
  return;
}


