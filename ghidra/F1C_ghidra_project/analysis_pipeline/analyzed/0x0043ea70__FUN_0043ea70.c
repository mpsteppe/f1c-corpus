// Function: FUN_0043ea70 @ 0043ea70
// Size (bytes): 108


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043ea70(int param_1,double param_2)

{
  double dVar1;
  
  *(double *)(param_1 + 0x1bc0) = param_2 * _DAT_0059ec88 + *(double *)(param_1 + 0x1bc0);
  dVar1 = *(double *)(param_1 + 0x1c30) + _DAT_0059ec80;
  if (*(double *)(param_1 + 0x1bc0) < *(double *)(param_1 + 0x1c30)) {
    *(double *)(param_1 + 0x1bc0) = *(double *)(param_1 + 0x1c30);
    return;
  }
  if (dVar1 < *(double *)(param_1 + 0x1bc0)) {
    *(double *)(param_1 + 0x1bc0) = dVar1;
  }
  return;
}


