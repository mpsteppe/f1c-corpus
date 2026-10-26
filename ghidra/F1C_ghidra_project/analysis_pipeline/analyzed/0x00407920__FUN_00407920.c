// Function: FUN_00407920 @ 00407920
// Size (bytes): 701


int * __thiscall FUN_00407920(int param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 *puVar2;
  bool bVar3;
  byte *pbVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  bool bVar10;
  int local_604;
  byte local_600 [512];
  undefined1 local_400 [1024];
  
  if (((param_2 == (byte *)0x0) && (param_3 == -1)) && (param_4 == -1)) {
    return (int *)0x0;
  }
  piVar6 = *(int **)(param_1 + 8);
  *(int **)(param_1 + 0x10) = piVar6;
  if (piVar6 == (int *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *piVar6;
  }
  bVar3 = false;
  local_604 = 0;
  if (param_2 == (byte *)0x0) {
LAB_004079a8:
    local_604 = FUN_004080b0(param_4);
    if (local_604 == 0) {
      return (int *)0x0;
    }
    bVar3 = true;
    while (iVar7 != 0) {
      piVar6 = *(int **)(iVar7 + 0x5c);
      if (((*(int *)(iVar7 + 0xc) == param_3) && (*(int *)(iVar7 + 0x10) == param_4)) &&
         (piVar6 != (int *)0x0)) {
        piVar6[1] = piVar6[1] + 1;
        return piVar6;
      }
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      if (*(int **)(param_1 + 0x10) == (int *)0x0) break;
      iVar7 = **(int **)(param_1 + 0x10);
    }
  }
  else {
    pbVar9 = &DAT_005ea438;
    pbVar4 = param_2;
    do {
      bVar1 = *pbVar4;
      bVar10 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_0040799b:
        iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_004079a0;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar10 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_0040799b;
      pbVar4 = pbVar4 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_004079a0:
    if (iVar5 == 0) goto LAB_004079a8;
    while (iVar7 != 0) {
      piVar6 = *(int **)(iVar7 + 0x5c);
      puVar8 = *(undefined1 **)(iVar7 + 4);
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      iVar7 = FUN_00588410(param_2,puVar8);
      if ((iVar7 == 0) && (piVar6 != (int *)0x0)) {
        piVar6[1] = piVar6[1] + 1;
        return piVar6;
      }
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      if (*(int **)(param_1 + 0x10) == (int *)0x0) break;
      iVar7 = **(int **)(param_1 + 0x10);
    }
  }
  piVar6 = operator_new(8);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    *piVar6 = 0;
    piVar6[1] = 1;
  }
  if (bVar3) {
    iVar7 = FUN_004054e0(param_3);
    if (iVar7 != 0) {
      if (piVar6 == (int *)0x0) {
        return (int *)0x0;
      }
      goto LAB_00407bc5;
    }
    pbVar4 = *(byte **)(local_604 + 4);
    if (pbVar4 == (byte *)0x0) {
      pbVar4 = &DAT_005ea438;
    }
    pbVar9 = local_600;
    do {
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
      *pbVar9 = bVar1;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 != 0);
  }
  else {
    iVar5 = FUN_00566810();
    iVar7 = -(int)param_2;
    if (iVar5 == 0) {
      do {
        bVar1 = *param_2;
        param_2[(int)(local_600 + iVar7)] = bVar1;
        param_2 = param_2 + 1;
      } while (bVar1 != 0);
      iVar7 = -1;
      pbVar4 = local_600;
      do {
        pbVar9 = pbVar4;
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        pbVar9 = pbVar4 + 1;
        bVar1 = *pbVar4;
        pbVar4 = pbVar9;
      } while (bVar1 != 0);
      *(undefined4 *)(pbVar9 + -1) = DAT_005be868;
      pbVar9[3] = DAT_005be86c;
    }
    else {
      do {
        bVar1 = *param_2;
        param_2[(int)(local_600 + iVar7)] = bVar1;
        param_2 = param_2 + 1;
      } while (bVar1 != 0);
    }
  }
  iVar7 = _AIL_file_read_8(local_600,0);
  *piVar6 = iVar7;
  if (iVar7 != 0) {
LAB_00407b45:
    if (bVar3) {
      FUN_00405630();
    }
    return piVar6;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  *(undefined4 **)(param_1 + 0x30) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
    while (puVar2 != (undefined4 *)0x0) {
      puVar8 = (undefined1 *)*puVar2;
      if (puVar8 == (undefined1 *)0x0) {
        puVar8 = &DAT_005ea438;
      }
      FUN_0058815f(local_400,&DAT_005be860,puVar8,local_600);
      iVar7 = _AIL_file_read_8(local_400,0);
      *piVar6 = iVar7;
      if (iVar7 != 0) goto LAB_00407b45;
      if (*(int *)(param_1 + 0x30) != 0) {
        *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x30) == (undefined4 *)0x0) break;
      puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x30);
    }
  }
LAB_00407bc5:
  FUN_00587bcf(piVar6);
  return (int *)0x0;
}


