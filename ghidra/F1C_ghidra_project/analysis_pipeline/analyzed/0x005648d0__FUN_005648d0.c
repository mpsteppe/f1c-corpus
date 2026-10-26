// Function: FUN_005648d0 @ 005648d0
// Size (bytes): 92


void __thiscall FUN_005648d0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*param_1 == param_1[1]) {
    FUN_00564930();
  }
  iVar1 = *param_1;
  iVar3 = iVar1 + 1;
  *param_1 = iVar3;
  if (param_2 < iVar1) {
    uVar2 = FUN_005648b0(((iVar3 - param_2) + -1) * param_1[2]);
    uVar2 = FUN_005648b0(uVar2);
    FUN_0058b130(uVar2);
  }
  FUN_00564960(param_2);
  return;
}


