// Function: FUN_00455fd0 @ 00455fd0
// Size (bytes): 54


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00455fd0(float *param_1)

{
  if (_DAT_0059efa4 < *param_1) {
    *param_1 = _DAT_0059efa8 - *param_1;
    return;
  }
  if (*param_1 < -_DAT_0059efa4) {
    *param_1 = _DAT_0059efa8 + *param_1;
  }
  return;
}


