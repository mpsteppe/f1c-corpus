// Function: FUN_004c7de0 @ 004c7de0
// Size (bytes): 156


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c7de0(int param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    fVar3 = *(float *)(param_1 + 4) - (float)_DAT_008afe98;
    *(float *)(param_1 + 4) = fVar3;
    if (fVar3 < DAT_0059e440) {
      FUN_004c7f30(0x3ecccccd);
      fVar3 = *(float *)(param_1 + 4) + _DAT_0059e8c8;
      *(float *)(param_1 + 4) = fVar3;
      if (fVar3 < DAT_0059e440) {
        *(undefined4 *)(param_1 + 4) = 0;
      }
    }
    if (DAT_008ac4c4 != (int *)0x0) {
      (**(code **)(*DAT_008ac4c4 + 0x28))(0,0,0);
      piVar1 = (int *)**(int **)(param_1 + 0xc);
      (*(int **)(param_1 + 0xc))[2] = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        for (iVar2 = *piVar1; iVar2 != 0; iVar2 = **(int **)(iVar2 + 8)) {
          FUN_004c8fc0();
          iVar2 = *(int *)(param_1 + 0xc);
          if (*(int *)(iVar2 + 8) != 0) {
            *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(*(int *)(iVar2 + 8) + 4);
          }
          if (*(int **)(iVar2 + 8) == (int *)0x0) {
            return;
          }
        }
      }
    }
  }
  return;
}


