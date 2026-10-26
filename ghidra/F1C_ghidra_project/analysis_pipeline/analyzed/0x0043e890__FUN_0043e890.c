// Function: FUN_0043e890 @ 0043e890
// Size (bytes): 240


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043e890(int param_1,double param_2)

{
  double dVar1;
  
  *(double *)(param_1 + 0x17a8) = param_2 * _DAT_0059ec78 + *(double *)(param_1 + 0x17a8);
  *(double *)(param_1 + 0x17c0) = param_2 * _DAT_0059eb58 + *(double *)(param_1 + 0x17c0);
  dVar1 = *(double *)(param_1 + 0x1c08) + _DAT_0059eb50;
  if (*(double *)(param_1 + 0x1c08) <= *(double *)(param_1 + 0x17a8)) {
    if (dVar1 < *(double *)(param_1 + 0x17a8)) {
      *(double *)(param_1 + 0x17a8) = dVar1;
    }
  }
  else {
    *(double *)(param_1 + 0x17a8) = *(double *)(param_1 + 0x1c08);
  }
  dVar1 = *(double *)(param_1 + 0x1c10) + _DAT_0059eb28;
  if (*(double *)(param_1 + 0x1c10) <= *(double *)(param_1 + 0x17c0)) {
    if (dVar1 < *(double *)(param_1 + 0x17c0)) {
      *(double *)(param_1 + 0x17c0) = dVar1;
    }
  }
  else {
    *(double *)(param_1 + 0x17c0) = *(double *)(param_1 + 0x1c10);
  }
  FUN_0043bb30(*(undefined4 *)(param_1 + 0x1c00),*(undefined4 *)(param_1 + 0x1c04));
  return;
}


