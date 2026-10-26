// Function: FUN_0043eae0 @ 0043eae0
// Size (bytes): 240


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043eae0(int param_1,double param_2)

{
  double dVar1;
  
  *(double *)(param_1 + 0x17d8) = param_2 * _DAT_0059ec78 + *(double *)(param_1 + 0x17d8);
  *(double *)(param_1 + 0x17f0) = param_2 * _DAT_0059eb58 + *(double *)(param_1 + 0x17f0);
  dVar1 = *(double *)(param_1 + 0x1c40) + _DAT_0059eb50;
  if (*(double *)(param_1 + 0x1c40) <= *(double *)(param_1 + 0x17d8)) {
    if (dVar1 < *(double *)(param_1 + 0x17d8)) {
      *(double *)(param_1 + 0x17d8) = dVar1;
    }
  }
  else {
    *(double *)(param_1 + 0x17d8) = *(double *)(param_1 + 0x1c40);
  }
  dVar1 = *(double *)(param_1 + 0x1c48) + _DAT_0059eb28;
  if (*(double *)(param_1 + 0x1c48) <= *(double *)(param_1 + 0x17f0)) {
    if (dVar1 < *(double *)(param_1 + 0x17f0)) {
      *(double *)(param_1 + 0x17f0) = dVar1;
    }
  }
  else {
    *(double *)(param_1 + 0x17f0) = *(double *)(param_1 + 0x1c48);
  }
  FUN_0043bb80(*(undefined4 *)(param_1 + 0x1c38),*(undefined4 *)(param_1 + 0x1c3c));
  return;
}


