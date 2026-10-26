// Function: FUN_00408420 @ 00408420
// Size (bytes): 47


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00408420(int param_1,float param_2)

{
  bool bVar1;
  bool bVar2;
  
  bVar1 = param_2 < DAT_0059e440;
  bVar2 = param_2 == DAT_0059e440;
  *(undefined4 *)(param_1 + 4) = 0x3f800000;
  if (bVar1 != bVar2) {
    *(undefined4 *)(param_1 + 8) = 0x3f800000;
    return;
  }
  *(float *)(param_1 + 8) = _DAT_0059e43c / param_2;
  return;
}


