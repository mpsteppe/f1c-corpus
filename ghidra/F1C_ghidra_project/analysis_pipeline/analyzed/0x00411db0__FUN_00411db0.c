// Function: FUN_00411db0 @ 00411db0
// Size (bytes): 222


undefined4 FUN_00411db0(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if (param_2[2] == 0x2693) {
    if ((param_5 == 0x18d) || (param_5 == 0x1aa)) {
      uVar1 = FUN_00412490(param_4,1,*(undefined4 *)(param_3 + 0x14),0,0);
      FUN_00414140(param_4);
      return uVar1;
    }
  }
  else if (param_2[2] == 0x2694) {
    if ((0 < param_5) && (param_5 < 3)) {
      uVar1 = FUN_00414010(param_4,*(undefined4 *)(param_3 + 0x14));
      FUN_00414140(param_4);
      return uVar1;
    }
  }
  else {
    iVar2 = FUN_00414160(param_1);
    if (-1 < iVar2) {
      puVar3 = (undefined1 *)*param_2;
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      uVar1 = param_2[2];
      FUN_00566650(puVar3);
      *(undefined4 *)(param_4 + 8) = uVar1;
      *(int *)(param_4 + 0xc) = iVar2;
      *(undefined1 *)(param_4 + 0x10) = 0;
      return 1;
    }
  }
  return 0xffffffff;
}


