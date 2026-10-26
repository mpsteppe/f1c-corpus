// Function: FUN_00447bb0 @ 00447bb0
// Size (bytes): 192


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00447bb0(int param_1)

{
  double dVar1;
  float10 fVar2;
  undefined8 local_10;
  
  if (_DAT_0059ef10 <= *(double *)(param_1 + 0x19c)) {
    return (float10)_DAT_0059ef00;
  }
  if (*(double *)(param_1 + 0x19c) < _DAT_0059e430 !=
      (*(double *)(param_1 + 0x19c) == _DAT_0059e430)) {
    return (float10)DAT_0059e440;
  }
  dVar1 = *(double *)(param_1 + 0x19c) - _DAT_0059ec80;
  if (dVar1 < _DAT_0059e430) {
    dVar1 = _DAT_0059e430;
  }
  dVar1 = dVar1 * _DAT_0059eb50;
  if (_DAT_0059e7d8 <= *(double *)(param_1 + 0x19c)) {
    local_10 = 4.0;
  }
  else {
    local_10 = *(double *)(param_1 + 0x19c);
  }
  fVar2 = (float10)FUN_00447ab0();
  return (((float10)local_10 * (float10)_DAT_0059eb50 - (float10)dVar1) * fVar2 + (float10)dVar1) *
         (float10)_DAT_0059ef08;
}


