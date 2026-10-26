// Function: FUN_005432f0 @ 005432f0
// Size (bytes): 334


void __thiscall
FUN_005432f0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_4;
  if (param_10 < 0) {
    param_10 = __ftol();
    param_2 = __ftol();
    iVar3 = __ftol();
    param_4 = iVar3;
    iVar4 = __ftol();
    param_6 = iVar4;
    param_3 = __ftol();
  }
  else {
    param_10 = __ftol();
    param_2 = __ftol();
    iVar3 = __ftol();
    param_4 = iVar3;
    iVar4 = __ftol();
    param_6 = iVar4;
    param_3 = __ftol();
  }
  param_5 = __ftol();
  if (iVar3 < 0) {
    param_10 = param_10 - iVar3;
  }
  if (iVar4 < 0) {
    param_2 = param_2 - iVar4;
  }
  FUN_00543540(&param_10,&param_2,&param_3,&param_5);
  FUN_00543540(&param_4,&param_6,&param_3,&param_5);
  if ((0 < param_3) && (0 < param_5)) {
    FUN_00540250(param_1,param_10,param_2,iVar2,param_4,param_6,param_3,param_5,param_9);
    puVar1 = (uint *)(iVar2 + 0x18);
    *puVar1 = *puVar1 & 0xfffffbff;
  }
  return;
}


