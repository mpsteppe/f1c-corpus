// Function: FUN_004122c0 @ 004122c0
// Size (bytes): 456


/* WARNING: Removing unreachable block (ram,0x00412473) */

undefined4
FUN_004122c0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  undefined4 local_1c;
  
  local_1c = 0xffffffff;
  iVar3 = FUN_00415650(param_3);
  iVar8 = 0;
  bVar2 = false;
  if (iVar3 != 0) {
    if ((DAT_007d0398 == 0) &&
       (((*(char *)(iVar3 + 0xc) != '\0' || (DAT_007d0410 == 5)) &&
        (iVar7 = *(int *)(iVar3 + 8) * 0x424 + DAT_008ac394, iVar7 != 0)))) {
      iVar8 = iVar7 + 0x7c;
      bVar2 = true;
    }
    else {
      if (param_2 == 0) {
        if (param_5 == '\0') {
          puVar9 = (undefined4 *)(iVar3 + 0x38);
          if ((char)param_4 == '\0') {
            puVar9 = (undefined4 *)(iVar3 + 0x4c);
          }
        }
        else {
          puVar9 = (undefined4 *)(iVar3 + 0x10);
          if ((char)param_4 == '\0') {
            puVar9 = (undefined4 *)(iVar3 + 0x24);
          }
        }
      }
      else {
        if (param_2 != 1) goto LAB_004123a9;
        if (param_5 == '\0') {
          puVar9 = (undefined4 *)(iVar3 + 0x88);
          if ((char)param_4 == '\0') {
            puVar9 = (undefined4 *)(iVar3 + 0x9c);
          }
        }
        else {
          puVar9 = (undefined4 *)(iVar3 + 0x60);
          if ((char)param_4 == '\0') {
            puVar9 = (undefined4 *)(iVar3 + 0x74);
          }
        }
      }
      puVar4 = (undefined1 *)*puVar9;
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      FUN_00566650(puVar4);
      param_1[2] = puVar9[2];
      param_1[3] = puVar9[3];
      *(undefined1 *)(param_1 + 4) = *(undefined1 *)(puVar9 + 4);
    }
  }
LAB_004123a9:
  FUN_00566650(&DAT_005ea438);
  pbVar10 = &DAT_005ea438;
  pbVar5 = (byte *)*param_1;
  if (pbVar5 == (byte *)0x0) {
    pbVar5 = &DAT_005ea438;
  }
  do {
    bVar1 = *pbVar5;
    bVar11 = bVar1 < *pbVar10;
    if (bVar1 != *pbVar10) {
LAB_00412414:
      iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_00412419;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar11 = bVar1 < pbVar10[1];
    if (bVar1 != pbVar10[1]) goto LAB_00412414;
    pbVar5 = pbVar5 + 2;
    pbVar10 = pbVar10 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_00412419:
  if (((iVar3 == 0) && (param_1[2] == -1)) &&
     ((param_1[3] == -1 && (*(char *)(param_1 + 4) == '\0')))) {
    if (bVar2) {
      uVar6 = FUN_00415550(iVar8);
      local_1c = FUN_004134d0(param_1,param_2,uVar6,param_4);
    }
  }
  else {
    local_1c = 1;
  }
  return local_1c;
}


