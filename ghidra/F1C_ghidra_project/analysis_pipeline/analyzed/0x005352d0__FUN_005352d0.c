// Function: FUN_005352d0 @ 005352d0
// Size (bytes): 183


uint __fastcall FUN_005352d0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = false;
  if ((param_1 == 0) || (*(char *)(param_1 + 0x5c) != 'w')) {
    return 0xfffffffe;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  do {
    iVar3 = 0x4000 - *(int *)(param_1 + 0x10);
    if (iVar3 != 0) {
      iVar2 = FUN_00588678(*(undefined4 *)(param_1 + 0x48),1,iVar3,*(undefined4 *)(param_1 + 0x40));
      if (iVar2 != iVar3) {
        *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
        return 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x10) = 0x4000;
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x48);
    }
    if (bVar1) break;
    iVar2 = FUN_00535e80();
    *(int *)(param_1 + 0x38) = iVar2;
    if ((iVar3 == 0) && (iVar2 == -5)) {
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    if ((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x38) != 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  } while ((*(int *)(param_1 + 0x38) == 0) || (*(int *)(param_1 + 0x38) == 1));
  return -(uint)(*(uint *)(param_1 + 0x38) != 1) & *(uint *)(param_1 + 0x38);
}


