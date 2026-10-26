// Function: FUN_0043e980 @ 0043e980
// Size (bytes): 240


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043e980(int param_1,double param_2)

{
  double dVar1;
  
  *(double *)(param_1 + 0x1808) = param_2 * _DAT_0059ec78 + *(double *)(param_1 + 0x1808);
  *(double *)(param_1 + 0x1818) = param_2 * _DAT_0059eb58 + *(double *)(param_1 + 0x1818);
  dVar1 = *(double *)(param_1 + 0x1c20) + _DAT_0059eb50;
  if (*(double *)(param_1 + 0x1c20) <= *(double *)(param_1 + 0x1808)) {
    if (dVar1 < *(double *)(param_1 + 0x1808)) {
      *(double *)(param_1 + 0x1808) = dVar1;
    }
  }
  else {
    *(double *)(param_1 + 0x1808) = *(double *)(param_1 + 0x1c20);
  }
  dVar1 = *(double *)(param_1 + 0x1c28) + _DAT_0059eb28;
  if (*(double *)(param_1 + 0x1c28) <= *(double *)(param_1 + 0x1818)) {
    if (dVar1 < *(double *)(param_1 + 0x1818)) {
      *(double *)(param_1 + 0x1818) = dVar1;
    }
  }
  else {
    *(double *)(param_1 + 0x1818) = *(double *)(param_1 + 0x1c28);
  }
  FUN_0043bbd0(*(undefined4 *)(param_1 + 0x1c18),*(undefined4 *)(param_1 + 0x1c1c));
  return;
}


