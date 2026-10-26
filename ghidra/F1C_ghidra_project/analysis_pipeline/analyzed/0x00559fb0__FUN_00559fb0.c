// Function: FUN_00559fb0 @ 00559fb0
// Size (bytes): 164


undefined4 __thiscall
FUN_00559fb0(int param_1,int param_2,float *param_3,float *param_4,float *param_5,float *param_6)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  uVar3 = 0;
  iVar2 = FUN_00559d80(param_2);
  pfVar1 = param_3;
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0x30c) + 1;
    uVar3 = 1;
    param_2 = iVar2;
    if (param_3 != (float *)0x0) {
      fVar4 = (float10)FUN_0058b077(iVar2,&param_2);
      *pfVar1 = (float)fVar4;
      iVar2 = param_2 + 1;
    }
    pfVar1 = param_4;
    if (param_4 != (float *)0x0) {
      fVar4 = (float10)FUN_0058b077(iVar2,&param_2);
      *pfVar1 = (float)fVar4;
      iVar2 = param_2 + 1;
    }
    pfVar1 = param_5;
    if (param_5 != (float *)0x0) {
      fVar4 = (float10)FUN_0058b077(iVar2,&param_2);
      *pfVar1 = (float)fVar4;
      iVar2 = param_2 + 1;
    }
    pfVar1 = param_6;
    if (param_6 != (float *)0x0) {
      fVar4 = (float10)FUN_0058b077(iVar2,&param_2);
      *pfVar1 = (float)fVar4;
    }
  }
  return uVar3;
}


