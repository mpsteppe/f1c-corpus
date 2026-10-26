// Function: FUN_0049a520 @ 0049a520
// Size (bytes): 93


undefined4 __thiscall FUN_0049a520(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_00589901(param_2);
  iVar1 = FUN_0049a330(param_2);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1 + iVar1 * 4);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = FUN_0049a2b0();
    iVar3 = FUN_00588410(param_2,uVar2);
    if (iVar3 == 0) break;
    iVar1 = *(int *)(iVar1 + 0x18);
  }
  return 1;
}


