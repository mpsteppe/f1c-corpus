// Function: FUN_00477ba0 @ 00477ba0
// Size (bytes): 258


void __fastcall FUN_00477ba0(int param_1)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 0xfc)) {
    do {
      if ((-1 < iVar7) && (iVar7 < *(int *)(param_1 + 0xfc))) {
        piVar2 = *(int **)(param_1 + 0xf0);
        for (iVar4 = iVar7; 0 < iVar4; iVar4 = iVar4 + -1) {
          if (piVar2 == (int *)0x0) goto LAB_00477c41;
          piVar2 = (int *)piVar2[1];
        }
        if (((piVar2 != (int *)0x0) && (iVar4 = *piVar2, iVar4 != 0)) &&
           (*(int *)(iVar4 + 0x3c) != 0)) {
          pbVar8 = DAT_007ce5ec;
          if (DAT_007ce5ec == (byte *)0x0) {
            pbVar8 = &DAT_005ea438;
          }
          pbVar5 = (byte *)(*(int *)(iVar4 + 0x3c) + 0x104);
          do {
            bVar1 = *pbVar5;
            bVar9 = bVar1 < *pbVar8;
            if (bVar1 != *pbVar8) {
LAB_00477c34:
              iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
              goto LAB_00477c39;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar9 = bVar1 < pbVar8[1];
            if (bVar1 != pbVar8[1]) goto LAB_00477c34;
            pbVar5 = pbVar5 + 2;
            pbVar8 = pbVar8 + 2;
          } while (bVar1 != 0);
          iVar6 = 0;
LAB_00477c39:
          if (iVar6 == 0) {
            *(int *)(param_1 + 0x174) = iVar7;
            puVar3 = *(undefined1 **)(iVar4 + 4);
            goto LAB_00477c71;
          }
        }
      }
LAB_00477c41:
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0xfc));
  }
  if (((0 < *(int *)(param_1 + 0xfc)) && (*(int **)(param_1 + 0xf0) != (int *)0x0)) &&
     (iVar7 = **(int **)(param_1 + 0xf0), iVar7 != 0)) {
    *(undefined4 *)(param_1 + 0x174) = 0;
    puVar3 = *(undefined1 **)(iVar7 + 4);
LAB_00477c71:
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_004c55b0(puVar3);
    FUN_004c54f0(0);
  }
  return;
}


