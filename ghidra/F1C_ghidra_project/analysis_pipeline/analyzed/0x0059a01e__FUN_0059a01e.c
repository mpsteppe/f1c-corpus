// Function: FUN_0059a01e @ 0059a01e
// Size (bytes): 183


uint __thiscall FUN_0059a01e(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  short sVar5;
  
  uVar1 = **(uint **)(param_1 + 0x1c);
  sVar5 = (short)param_2;
  if (((uVar1 == 0) || (uVar1 <= **(uint **)(param_1 + 0xc))) ||
     ((sVar5 != -1 && (*(short *)(uVar1 - 2) != sVar5)))) {
    if ((*(int *)(param_1 + 0x50) != 0) && (sVar5 != -1)) {
      if (*(int *)(param_1 + 0x38) == 0) {
        sVar5 = FUN_0059bcd2(param_2,*(int *)(param_1 + 0x50));
        if (sVar5 != -1) {
          return param_2;
        }
        return 0xffff;
      }
      iVar2 = *(int *)(param_1 + 0x44);
      iVar3 = *(int *)(iVar2 + 8);
      if (iVar3 != 0) {
        FUN_00599534();
        cVar4 = FUN_00599707(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(param_1 + 0x50),iVar3);
        if (cVar4 != '\0') {
          FUN_00599348(0,DAT_005b9c38);
          *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
          return param_2 & 0xffff;
        }
      }
    }
    param_2 = 0xffff;
  }
  else {
    FUN_0059a407();
    param_2 = -(uint)(sVar5 != -1) & param_2;
  }
  return param_2;
}


