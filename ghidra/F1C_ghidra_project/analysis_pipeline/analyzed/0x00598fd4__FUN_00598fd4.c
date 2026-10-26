// Function: FUN_00598fd4 @ 00598fd4
// Size (bytes): 173


uint __thiscall FUN_00598fd4(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  uVar1 = **(uint **)(param_1 + 0x1c);
  if (((uVar1 == 0) || (uVar1 <= **(uint **)(param_1 + 0xc))) ||
     ((param_2 != 0xffffffff && (*(byte *)(uVar1 - 1) != param_2)))) {
    if ((*(int *)(param_1 + 0x50) != 0) && (param_2 != 0xffffffff)) {
      if (*(int *)(param_1 + 0x38) == 0) {
        iVar4 = FUN_0059685f(param_2 & 0xff,*(int *)(param_1 + 0x50));
        if (iVar4 != -1) {
          return param_2;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x44);
        iVar2 = *(int *)(iVar4 + 8);
        if (iVar2 != 0) {
          FUN_00599534();
          cVar3 = FUN_00599707(*(undefined4 *)(iVar4 + 4),*(undefined4 *)(param_1 + 0x50),iVar2);
          if (cVar3 != '\0') {
            FUN_00599348(0,DAT_005b9c38);
            *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
            return param_2;
          }
        }
      }
    }
    param_2 = 0xffffffff;
  }
  else {
    FUN_00599465();
    param_2 = -(uint)(param_2 != 0xffffffff) & param_2;
  }
  return param_2;
}


