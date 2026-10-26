// Function: FUN_00495580 @ 00495580
// Size (bytes): 527


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00495580(int param_1)

{
  char cVar1;
  int *piVar2;
  float fVar3;
  char *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if (((*(char *)(param_1 + 0x1588) == '\0') ||
      (*(float *)(param_1 + 0xcc) < *(float *)(param_1 + 0xd0))) ||
     (*(int *)(param_1 + 0x156c) == 0)) {
    *(undefined4 *)(param_1 + 0x1570) = 0;
  }
  else {
    pcVar4 = *(char **)(*(int *)(param_1 + 0x156c) + 0xc0);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = &DAT_005ea438;
    }
    iVar7 = -1;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar7 != -2) {
      iVar7 = -1;
      pcVar4 = (char *)(param_1 + 0x1538);
      pcVar9 = pcVar4;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (iVar7 == -2) {
        FUN_00498550();
      }
      else {
        FUN_00497ec0(pcVar4);
        FUN_00498560(pcVar4);
      }
      puVar5 = *(undefined1 **)(*(int *)(param_1 + 0x156c) + 0xc0);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      FUN_004983b0(puVar5,&local_1c,&local_18,1);
      iVar7 = local_1c + 8;
      piVar2 = *(int **)(param_1 + 0x156c);
      local_10 = iVar7;
      if (*(int **)(param_1 + 0x1570) != piVar2) {
        *(int *)(param_1 + 0x158c) = *(int *)(param_1 + 0x5c) - iVar7 / 2;
        *(int **)(param_1 + 0x1570) = piVar2;
        (**(code **)(*piVar2 + 8))(local_4,&local_14,local_8,local_c);
        uVar6 = local_14 + 5;
        *(uint *)(param_1 + 0x1590) = uVar6;
        uVar8 = *(uint *)(param_1 + 0x158c) & ((int)*(uint *)(param_1 + 0x158c) < 0) - 1;
        *(uint *)(param_1 + 0x158c) = uVar8;
        if ((int)(800U - iVar7) < (int)uVar8) {
          uVar8 = 800U - iVar7;
        }
        *(uint *)(param_1 + 0x158c) = uVar8;
        uVar6 = uVar6 & ((int)uVar6 < 0) - 1;
        uVar8 = 600 - (local_18 + 4);
        *(uint *)(param_1 + 0x1590) = uVar6;
        if ((int)uVar8 < (int)uVar6) {
          uVar6 = uVar8;
        }
        *(uint *)(param_1 + 0x1590) = uVar6;
      }
      uVar11 = *(undefined4 *)(param_1 + 0x158c);
      uVar12 = *(undefined4 *)(param_1 + 0x1590);
      fVar3 = *(float *)(param_1 + 0xd4) - (*(float *)(param_1 + 0xcc) - *(float *)(param_1 + 0xd0))
      ;
      if (fVar3 < _DAT_005ac9c0 != (fVar3 == _DAT_005ac9c0)) {
        iVar7 = local_18 + 0xe;
        iVar10 = local_1c + 0x12;
        FUN_00490920(uVar11,uVar12,iVar10,iVar7);
        FUN_004918d0(uVar11,uVar12,iVar10,iVar7);
        return;
      }
      iVar7 = __ftol();
      iVar10 = __ftol();
      if ((2 < iVar7) && (2 < iVar10)) {
        iVar7 = iVar7 + 1;
        iVar10 = iVar10 + 1;
        FUN_00490920(uVar11,uVar12,iVar10,iVar7);
        FUN_004918d0(uVar11,uVar12,iVar10,iVar7);
        return;
      }
    }
  }
  return;
}


