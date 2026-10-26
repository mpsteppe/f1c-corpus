// Function: FUN_00560547 @ 00560547
// Size (bytes): 327


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_00560547(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,int param_5,int *param_6
            ,int param_7,int param_8,int param_9,int param_10,int *param_11,int param_12)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_EAX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  uVar7 = param_4 * 2 + param_3[8] * param_5;
  _DAT_005dd82c = param_3[8];
  _DAT_005dd830 = param_6[8];
  puVar9 = (undefined4 *)(*param_3 + uVar7);
  puVar10 = (undefined4 *)(*param_6 + param_7 * 2 + param_6[8] * param_8);
  DAT_005dd838 = param_10;
  DAT_005dd834 = param_9;
  DAT_005dd840 = param_9 * param_10;
  param_11 = (int *)*param_11;
  uVar4 = 0;
  if (*param_11 != 0) {
    uVar4 = 0xffffffff;
  }
  if (param_12 == 0) {
    uVar4 = ~uVar4;
  }
  iVar6 = 0;
  uVar7 = uVar7 >> 1;
  uVar5 = param_11[1];
  puVar8 = (uint *)(param_11 + 2);
  DAT_005dd83c = ~uVar4;
  do {
    iVar6 = iVar6 + uVar5;
    if ((int)uVar7 <= iVar6) {
      uVar5 = iVar6 - uVar7;
      break;
    }
    uVar5 = *puVar8;
    puVar8 = puVar8 + 1;
    DAT_005dd83c = ~DAT_005dd83c;
  } while (iVar6 < (int)uVar7);
  iVar6 = 0;
  while (0 < DAT_005dd840) {
    if (0 < (int)uVar5) {
      if (DAT_005dd834 <= (int)(iVar6 + uVar5)) {
        uVar5 = DAT_005dd834 - iVar6;
      }
      if (DAT_005dd83c != 0) {
        uVar4 = (uVar5 & 0x7fffffff) >> 1;
        if (uVar4 != 0) {
          for (; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
        }
        uVar4 = uVar5 * 2 & 3;
        if (uVar4 != 0) {
          for (; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
            puVar9 = (undefined4 *)((int)puVar9 + 1);
            puVar10 = (undefined4 *)((int)puVar10 + 1);
          }
        }
        puVar9 = (undefined4 *)((int)puVar9 + uVar5 * -2);
        puVar10 = (undefined4 *)((int)puVar10 + uVar5 * -2);
      }
      iVar3 = DAT_005dd840;
      if ((int)(iVar6 + uVar5) < DAT_005dd834) {
        iVar1 = uVar5 * 2;
        iVar2 = uVar5 * 2;
        iVar6 = iVar6 + uVar5;
      }
      else {
        iVar1 = iVar6 * -2 + _DAT_005dd82c;
        iVar2 = iVar6 * -2 + _DAT_005dd830;
        iVar6 = 0;
      }
      puVar10 = (undefined4 *)((int)puVar10 + iVar2);
      puVar9 = (undefined4 *)((int)puVar9 + iVar1);
      DAT_005dd840 = DAT_005dd840 - uVar5;
      if (DAT_005dd840 == 0 || iVar3 < (int)uVar5) break;
    }
    uVar5 = *puVar8;
    puVar8 = puVar8 + 1;
    DAT_005dd83c = ~DAT_005dd83c;
  }
  return CONCAT44(param_2,in_EAX);
}


