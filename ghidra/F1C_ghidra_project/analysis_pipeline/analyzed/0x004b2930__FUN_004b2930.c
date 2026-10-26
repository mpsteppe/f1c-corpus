// Function: FUN_004b2930 @ 004b2930
// Size (bytes): 68


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b2930(int param_1,float param_2)

{
  int iVar1;
  
  iVar1 = (int)ROUND(param_2 * _DAT_0059e5fc);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0x7fff < iVar1) {
    iVar1 = 0x7fff;
  }
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0x1ffff | iVar1 << 0x11;
  return;
}


