// Function: FUN_00494a70 @ 00494a70
// Size (bytes): 375


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494a70(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,int param_7,int param_8,int param_9,int param_10,
                 undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (0x100 < param_4) {
    param_4 = 0x100;
  }
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (0x100 < param_5) {
    param_5 = 0x100;
  }
  if ((0 < param_4) && (0 < param_5)) {
    FUN_00543250(param_2,param_3,DAT_007cde08,0,0,param_4,param_5,0,0);
    fVar1 = (float)param_7;
    fVar2 = (float)param_8;
    fVar3 = (float)param_4 * _DAT_005ac988;
    fVar4 = (float)param_5 * _DAT_005ac988;
    FUN_00553650(0,fVar1,fVar2,0x3f800000,0,0,param_11);
    FUN_00553650(1,fVar1,(float)param_10 + fVar2,0x3f800000,0,fVar4,param_12);
    FUN_00553650(2,(float)param_9 + fVar1,(float)param_10 + fVar2,0x3f800000,fVar3,fVar4,param_13);
    FUN_00553650(3,(float)param_9 + fVar1,fVar2,0x3f800000,fVar3,0,param_14);
    FUN_004f9f00();
    FUN_00553700(param_6);
    FUN_004f9f30();
  }
  return;
}


