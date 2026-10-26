// Function: FUN_00568320 @ 00568320
// Size (bytes): 370


uint __thiscall FUN_00568320(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_2 == (int *)0x0) goto LAB_00568480;
  iVar4 = FUN_00563e70();
  iVar1 = param_2[1];
  iVar2 = param_2[9];
  bVar8 = param_2[3] != 0;
  if ((iVar2 != 0) || (bVar3 = true, param_2[10] != 0)) {
    bVar3 = false;
  }
  uVar5 = FUN_00499e20();
  iVar6 = FUN_00567d00(uVar5);
  if (iVar4 == 0) {
    if (!bVar3) {
LAB_00568436:
      if (iVar2 != 0) {
        *(int *)(param_2[9] + 4) = param_2[1];
        if (iVar1 != 0) {
          *(int *)(param_2[1] + 0x24) = param_2[9];
          uVar7 = FUN_00567a90(param_2);
          return uVar7 & 0xffffff00;
        }
      }
      else {
        *(int *)(param_2[10] + 0xc) = param_2[3];
        if (bVar8) {
          *(int *)(param_2[3] + 0x28) = param_2[10];
        }
      }
      goto LAB_00568480;
    }
    if (bVar8) {
      *(int *)(param_1 + iVar6 * 4) = param_2[3];
      *(undefined4 *)(param_2[3] + 0x28) = 0;
      *(int *)(param_2[3] + 4) = param_2[1];
      uVar7 = FUN_00567a90(param_2);
      return uVar7 & 0xffffff00;
    }
    *(int *)(param_1 + iVar6 * 4) = param_2[1];
  }
  else {
    if (!bVar3) goto LAB_00568436;
    if (bVar8) {
      *(int *)(*param_2 + 8) = param_2[3];
      *(undefined4 *)(param_2[3] + 0x28) = 0;
      *(int *)(param_2[3] + 4) = param_2[1];
      *(int *)param_2[3] = *param_2;
      uVar7 = FUN_00567a90(param_2);
      return uVar7 & 0xffffff00;
    }
    *(int *)(*param_2 + 8) = param_2[1];
  }
  if (iVar1 != 0) {
    *(undefined4 *)(param_2[1] + 0x24) = 0;
    uVar7 = FUN_00567a90(param_2);
    return uVar7 & 0xffffff00;
  }
LAB_00568480:
  uVar7 = FUN_00567a90(param_2);
  return uVar7 & 0xffffff00;
}


