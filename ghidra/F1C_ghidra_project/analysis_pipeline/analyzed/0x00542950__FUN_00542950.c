// Function: FUN_00542950 @ 00542950
// Size (bytes): 85


undefined4 __thiscall
FUN_00542950(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  
  iVar1 = FUN_005426e0(param_4,param_5);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  *(undefined4 *)(param_1 + 0x20) = param_3;
  *(uint *)(param_1 + 0x18) = param_5;
  if ((param_5 & 0xf) != 0) {
    iVar1 = FUN_0053f720(param_1,0);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
  }
  return 0;
}


