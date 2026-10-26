// Function: FUN_00447b10 @ 00447b10
// Size (bytes): 149


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00447b10(int param_1)

{
  double dVar1;
  double dVar2;
  float10 fVar3;
  
  if (*(char *)(param_1 + 0x1c59) == '\0') {
    return (float10)_DAT_0059e430;
  }
  if (*(double *)(param_1 + 0x19c) < _DAT_0059eb38) {
    if (*(double *)(param_1 + 0x19c) < _DAT_0059e430 !=
        (*(double *)(param_1 + 0x19c) == _DAT_0059e430)) {
      return (float10)_DAT_0059e430;
    }
    dVar1 = *(double *)(param_1 + 0x19c) + _DAT_0059eba0;
    dVar2 = *(double *)(param_1 + 0x19c) + _DAT_0059eef8;
    fVar3 = (float10)FUN_00447ab0();
    fVar3 = ((float10)dVar2 - (float10)dVar1) * fVar3 + (float10)dVar1;
    if (fVar3 <= (float10)_DAT_0059e420) {
      return fVar3;
    }
  }
  return (float10)_DAT_0059e420;
}


