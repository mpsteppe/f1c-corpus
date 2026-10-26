// Function: FUN_004082b0 @ 004082b0
// Size (bytes): 291


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004082b0(float *param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (*param_1 == DAT_0059e440) {
    if (*(char *)((int)param_1 + 0x15) != '\0') {
      FUN_004d8860(1);
      *(undefined1 *)((int)param_1 + 0x15) = 0;
    }
  }
  else {
    if (DAT_008ad2a0 != -1) {
      FUN_004d8860(0);
      *(undefined1 *)((int)param_1 + 0x15) = 1;
    }
    uVar4 = 0;
    uVar2 = __ftol(0);
    uVar3 = __ftol(uVar2);
    FUN_005404d0(DAT_008b8dc8,0,0,uVar3,uVar2,uVar4);
    uVar5 = 0;
    uVar2 = __ftol(0);
    uVar3 = __ftol(uVar2);
    uVar4 = __ftol(uVar3);
    FUN_005404d0(DAT_008b8dc8,0,uVar4,uVar3,uVar2,uVar5);
  }
  if (param_1[1] <= *param_1) {
    if ((param_1[1] < *param_1) &&
       (fVar1 = *param_1 - (float)_DAT_008afe90 * param_1[2], *param_1 = fVar1, fVar1 < param_1[1]))
    {
      *param_1 = param_1[1];
    }
  }
  else {
    fVar1 = (float)_DAT_008afe90 * param_1[2] + *param_1;
    *param_1 = fVar1;
    if (param_1[1] < fVar1) {
      *param_1 = param_1[1];
      return;
    }
  }
  return;
}


