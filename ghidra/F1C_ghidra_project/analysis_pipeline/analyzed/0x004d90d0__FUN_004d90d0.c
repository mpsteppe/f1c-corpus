// Function: FUN_004d90d0 @ 004d90d0
// Size (bytes): 259


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d90d0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (param_2 != 0) {
    fVar3 = DAT_0059e440;
    if (*(int *)(param_1 + 8) != -1) {
      fVar3 = _DAT_005acf44;
    }
    fVar4 = *(float *)(param_1 + 0xe4) * DAT_0059e440;
    fVar3 = fVar3 * *(float *)(param_1 + 0xe8);
    fVar2 = *(float *)(param_1 + 0xe4) * _DAT_005acf40;
    fVar1 = *(float *)(param_1 + 0xe8) * _DAT_0059e828;
    FUN_00553650(0,fVar4,fVar3,0x3f800000,0,0,0x80000000);
    fVar1 = fVar1 + fVar3;
    FUN_00553650(1,fVar4,fVar1,0x3f800000,0,0x3f800000,0x80000000);
    fVar2 = fVar2 + fVar4;
    FUN_00553650(2,fVar2,fVar1,0x3f800000,0x3f800000,0x3f800000,0x80000000);
    FUN_00553650(3,fVar2,fVar3,0x3f800000,0x3f800000,0,0x80000000);
  }
  return;
}


