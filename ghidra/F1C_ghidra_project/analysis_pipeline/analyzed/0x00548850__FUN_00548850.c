// Function: FUN_00548850 @ 00548850
// Size (bytes): 52


int __thiscall FUN_00548850(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((int)(param_2 & 0xffff) < *(int *)(param_1 + 0x10)) {
    iVar1 = *(int *)(param_1 + 0x24);
    for (; (iVar1 != 0 && (uVar2 != (param_2 & 0xffff))); uVar2 = uVar2 + 1) {
      iVar1 = *(int *)(iVar1 + 0xc0);
    }
    return iVar1;
  }
  return 0;
}


