// Function: FUN_00551eb0 @ 00551eb0
// Size (bytes): 89


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00551eb0(undefined4 *param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  if (((float)param_1[4] != param_2) && ((float)_DAT_0059e430 <= param_2)) {
    fVar1 = (float)_DAT_0059e420;
    if ((!NAN(param_2) && !NAN(fVar1)) && param_2 < fVar1 != (param_2 == fVar1)) {
      param_1[4] = param_2;
      uVar2 = __ftol();
      _BinkSetVolume_12(*param_1,0,uVar2);
    }
  }
  return;
}


