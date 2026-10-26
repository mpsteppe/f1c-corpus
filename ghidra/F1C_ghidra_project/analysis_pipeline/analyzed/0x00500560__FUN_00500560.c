// Function: FUN_00500560 @ 00500560
// Size (bytes): 286


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __thiscall
FUN_00500560(int param_1,float param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            char param_6)

{
  float fVar1;
  float fVar2;
  char cVar3;
  char extraout_DL;
  undefined1 local_1b0 [432];
  
  cVar3 = FUN_005001f0();
  if (cVar3 != '\0') {
    cVar3 = FUN_005001d0();
    if ((cVar3 == '\0') || (param_2 <= *(float *)(param_1 + 0x1bc))) {
      cVar3 = FUN_004ff680(param_2,param_1 + 8,param_4,0x3f800000);
    }
    else {
      fVar1 = param_2 - *(float *)(param_1 + 0x1bc);
      fVar2 = _DAT_0059e600;
      if ((_DAT_0059e600 <= fVar1) && (fVar2 = fVar1, _DAT_0059e450 < fVar1)) {
        fVar2 = _DAT_0059e450;
      }
      FUN_004ff680(fVar2 + param_2,param_1 + 8,local_1b0,0x3f800000);
      cVar3 = FUN_004ff8f0(param_2,param_1 + 0x1b8,local_1b0,param_4);
    }
    FUN_004b3a90(param_4);
    if ((cVar3 != '\0') && (param_6 != '\0')) {
      FUN_005000e0(param_4,param_5);
    }
    return cVar3;
  }
  return extraout_DL;
}


