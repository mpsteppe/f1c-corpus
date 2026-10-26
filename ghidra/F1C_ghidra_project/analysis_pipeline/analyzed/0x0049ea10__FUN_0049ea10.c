// Function: FUN_0049ea10 @ 0049ea10
// Size (bytes): 294


void __thiscall
FUN_0049ea10(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0049ec40();
    iVar4 = FUN_00553980(param_1,param_6,*(undefined4 *)(param_1 + 8),0x20,0xc0);
    if (iVar4 == 0) {
      *(int *)(param_1 + 0x24) = param_2;
      *(int *)(param_1 + 0x28) = param_3;
      *(int *)(param_1 + 0x2c) = param_4;
      *(int *)(param_1 + 0x30) = param_5;
      *(float *)(param_1 + 0x34) =
           (float)param_4 / (float)*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x1c);
      *(float *)(param_1 + 0x38) =
           (float)param_5 / (float)*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x20);
      fVar1 = (float)param_2;
      fVar2 = (float)param_3;
      FUN_00553650(0,fVar1,fVar2,0x3f800000,0,0,0xffffffff);
      fVar3 = (float)param_5 + fVar2;
      FUN_00553650(1,fVar1,fVar3,0x3f800000,0,0x3f800000,0xffffffff);
      fVar1 = (float)param_4 + fVar1;
      FUN_00553650(2,fVar1,fVar3,0x3f800000,0x3f800000,0x3f800000,0xffffffff);
      FUN_00553650(3,fVar1,fVar2,0x3f800000,0x3f800000,0,0xffffffff);
    }
  }
  return;
}


