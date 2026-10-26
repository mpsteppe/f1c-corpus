// Function: FUN_00441ad0 @ 00441ad0
// Size (bytes): 213


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00441ad0(int param_1)

{
  double dVar1;
  int iVar2;
  double dVar3;
  
  if (((*(char *)(*(int *)(param_1 + 0x1f00) + 0x344c) != '\0') &&
      (*(int *)(*(int *)(param_1 + 0x1f00) + 0x3450) != 3)) && (DAT_007ce838 != '\0')) {
    iVar2 = *(int *)(param_1 + 0x15f0);
    dVar3 = (_DAT_0059ed48 -
            SQRT(*(double *)(iVar2 + 0x74) * *(double *)(iVar2 + 0x74) +
                 *(double *)(iVar2 + 0x6c) * *(double *)(iVar2 + 0x6c) +
                 *(double *)(iVar2 + 100) * *(double *)(iVar2 + 100))) * _DAT_0059ed40;
    if (_DAT_0059e430 < dVar3) {
      dVar1 = *(double *)(param_1 + 0x48);
      if (*(int *)(param_1 + 0x1ef0) != -1) {
        dVar1 = -dVar1;
      }
      dVar1 = dVar1 * dVar3;
      *(double *)(iVar2 + 0x134) = dVar1 * *(double *)(iVar2 + 0x2c) + *(double *)(iVar2 + 0x134);
      *(double *)(iVar2 + 0x13c) = dVar1 * *(double *)(iVar2 + 0x44) + *(double *)(iVar2 + 0x13c);
      *(double *)(iVar2 + 0x144) = dVar1 * *(double *)(iVar2 + 0x5c) + *(double *)(iVar2 + 0x144);
      return;
    }
  }
  return;
}


