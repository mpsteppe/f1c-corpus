// Function: FUN_004f6720 @ 004f6720
// Size (bytes): 290


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f6720(int param_1,double param_2,double *param_3,double *param_4)

{
  int iVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  
  iVar3 = *(int *)(param_1 + 0x6c4);
  if (iVar3 < 1) {
    *(undefined4 *)param_3 = 0;
    *(undefined4 *)((int)param_3 + 4) = 0;
    *(undefined4 *)param_4 = 0;
    *(undefined4 *)((int)param_4 + 4) = 0;
    return;
  }
  if (iVar3 == 1) {
    *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 0x6d0);
    *(undefined4 *)((int)param_3 + 4) = *(undefined4 *)(param_1 + 0x6d4);
    *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x6d8);
    *(undefined4 *)((int)param_4 + 4) = *(undefined4 *)(param_1 + 0x6dc);
    return;
  }
  iVar4 = 0;
  if (0 < iVar3) {
    pdVar5 = (double *)(param_1 + 0x6c8);
    do {
      if (param_2 < *pdVar5) break;
      iVar4 = iVar4 + 1;
      pdVar5 = pdVar5 + 3;
    } while (iVar4 < iVar3);
    if (iVar4 != 0) {
      if (iVar4 < iVar3) {
        iVar3 = iVar4 + -1;
      }
      else {
        iVar3 = iVar4 + -2;
        iVar4 = iVar4 + -1;
      }
      goto LAB_004f67c0;
    }
  }
  iVar3 = 0;
  iVar4 = 1;
LAB_004f67c0:
  iVar1 = param_1 + iVar3 * 0x18;
  pdVar5 = (double *)(param_1 + (iVar3 * 3 + 0xdb) * 8);
  dVar2 = (param_2 - *(double *)(param_1 + 0x6c8 + iVar3 * 0x18)) /
          (*(double *)(param_1 + 0x6c8 + iVar4 * 0x18) - *(double *)(iVar1 + 0x6c8));
  *param_3 = (*(double *)(param_1 + iVar4 * 0x18 + 0x6d0) - *(double *)(iVar1 + 0x6d0)) * dVar2 +
             *(double *)(iVar1 + 0x6d0);
  dVar2 = (*(double *)(param_1 + (iVar4 * 3 + 0xdb) * 8) - *pdVar5) * dVar2 + *pdVar5;
  *param_4 = dVar2;
  if (dVar2 < *param_3) {
    dVar2 = (dVar2 + *param_3) * _DAT_0059e880;
    *param_3 = dVar2;
    *param_4 = dVar2;
    return;
  }
  return;
}


