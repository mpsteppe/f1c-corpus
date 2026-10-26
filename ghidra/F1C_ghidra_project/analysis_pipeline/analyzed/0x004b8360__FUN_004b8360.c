// Function: FUN_004b8360 @ 004b8360
// Size (bytes): 287


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004b8360(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  
  puVar5 = *(undefined4 **)(param_1 + 0x6c0);
  *(undefined4 **)(param_1 + 0x6c8) = puVar5;
  if ((puVar5 != (undefined4 *)0x0) && (pfVar6 = (float *)*puVar5, pfVar6 != (float *)0x0)) {
    do {
      fVar1 = *pfVar6;
      fVar2 = ABS(fVar1 - *(float *)(param_1 + 0xf38));
      if (fVar2 < _DAT_005acd20 == (fVar2 == _DAT_005acd20)) {
        fVar2 = *(float *)(param_1 + 0xf38);
        puVar5 = (undefined4 *)
                 CONCAT22((short)((uint)puVar5 >> 0x10),
                          (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                          (ushort)(fVar1 == fVar2) << 0xe);
        if (fVar1 < fVar2 == 0 && (fVar1 == fVar2) == 0) break;
      }
      else {
        for (piVar3 = *(int **)(param_1 + 0x6c0); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
          if ((float *)*piVar3 == pfVar6) {
            if (piVar3 == *(int **)(param_1 + 0x6c8)) {
              *(int *)(param_1 + 0x6c8) = piVar3[1];
            }
            if (piVar3[2] == 0) {
              *(int *)(param_1 + 0x6c0) = piVar3[1];
            }
            else {
              *(int *)(piVar3[2] + 4) = piVar3[1];
            }
            if (piVar3[1] != 0) {
              *(int *)(piVar3[1] + 8) = piVar3[2];
            }
            if (*(int **)(param_1 + 0x6c4) == piVar3) {
              *(int *)(param_1 + 0x6c4) = piVar3[2];
            }
            *(int *)(param_1 + 0x6cc) = *(int *)(param_1 + 0x6cc) + -1;
            if (((char)piVar3[3] != '\0') && (iVar4 = *piVar3, iVar4 != 0)) {
              if (*(int *)(iVar4 + 4) != 0) {
                FUN_00587bcf(*(int *)(iVar4 + 4));
              }
              FUN_00587bcf(iVar4);
            }
            FUN_00587bcf(piVar3);
            *(undefined1 *)(param_1 + 0x6d0) = 1;
            goto LAB_004b8465;
          }
        }
      }
      if (*(int *)(param_1 + 0x6c8) != 0) {
        *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(*(int *)(param_1 + 0x6c8) + 4);
      }
LAB_004b8465:
      puVar5 = *(undefined4 **)(param_1 + 0x6c8);
      if ((puVar5 == (undefined4 *)0x0) || (pfVar6 = (float *)*puVar5, pfVar6 == (float *)0x0))
      break;
    } while( true );
  }
  return CONCAT31((int3)((uint)puVar5 >> 8),1);
}


