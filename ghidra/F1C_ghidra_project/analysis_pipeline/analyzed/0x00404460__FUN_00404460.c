// Function: FUN_00404460 @ 00404460
// Size (bytes): 397


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00404460(int param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = _DAT_0059e43c - (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450;
  if (((float)_DAT_0059e480 < ABS(*(float *)(param_1 + 0x170) - fVar2)) ||
     (*(int *)(param_1 + 0x174) != -1)) {
    if (*(int *)(param_1 + 0x174) == -1) {
      *(undefined4 *)(param_1 + 0x174) = 0;
      *(float *)(param_1 + 0x170) = fVar2;
      *(undefined4 *)(param_1 + 0x16c) = 0;
    }
    iVar3 = *(int *)(param_1 + 0x174);
    iVar4 = iVar3 + 0x14;
    if (*(int *)(param_1 + 0x130) < iVar3 + 0x14) {
      iVar4 = *(int *)(param_1 + 0x130);
    }
    iVar1 = *(int *)(param_1 + 0x16c);
    if (iVar1 == 0) {
      while (iVar3 < iVar4) {
        FUN_004fb260(fVar2);
        iVar3 = *(int *)(param_1 + 0x174) + 1;
        *(int *)(param_1 + 0x174) = iVar3;
      }
      if (iVar4 == *(int *)(param_1 + 0x130)) {
        *(undefined4 *)(param_1 + 0x16c) = 1;
        *(undefined4 *)(param_1 + 0x174) = 0;
      }
    }
    else if (iVar1 == 1) {
      while (iVar3 < iVar4) {
        FUN_004faf60();
        iVar3 = *(int *)(param_1 + 0x174) + 1;
        *(int *)(param_1 + 0x174) = iVar3;
      }
      if (iVar4 == *(int *)(param_1 + 0x130)) {
        *(undefined4 *)(param_1 + 0x174) = 0;
        *(undefined4 *)(param_1 + 0x16c) = 2;
        return;
      }
    }
    else if (iVar1 == 2) {
      while (iVar3 < iVar4) {
        FUN_004fb2e0();
        iVar3 = *(int *)(param_1 + 0x174) + 1;
        *(int *)(param_1 + 0x174) = iVar3;
      }
      if (iVar4 == *(int *)(param_1 + 0x130)) {
        *(undefined4 *)(param_1 + 0x16c) = 0;
        *(undefined4 *)(param_1 + 0x174) = 0xffffffff;
        return;
      }
    }
  }
  return;
}


