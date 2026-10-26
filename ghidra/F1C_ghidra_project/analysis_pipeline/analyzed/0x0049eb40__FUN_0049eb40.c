// Function: FUN_0049eb40 @ 0049eb40
// Size (bytes): 252


void __thiscall
FUN_0049eb40(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0049eca0();
    iVar3 = FUN_00553980(param_1 + 4,param_6,*(undefined4 *)(param_1 + 0xc),0x20,0xc0);
    if (iVar3 == 0) {
      fVar1 = (float)param_2;
      fVar2 = (float)param_3;
      *(int *)(param_1 + 0x3c) = param_2;
      *(int *)(param_1 + 0x44) = param_4;
      *(int *)(param_1 + 0x40) = param_3;
      *(int *)(param_1 + 0x48) = param_5;
      FUN_00553650(0,fVar1,fVar2,0x3f800000,0,0,0xffffffff);
      FUN_00553650(1,fVar1,(float)param_5 + fVar2,0x3f800000,0,0x3f800000,0xffffffff);
      FUN_00553650(2,(float)param_4 + fVar1,(float)param_5 + fVar2,0x3f800000,0x3f800000,0x3f800000,
                   0xffffffff);
      FUN_00553650(3,(float)param_4 + fVar1,fVar2,0x3f800000,0x3f800000,0,0xffffffff);
    }
  }
  return;
}


