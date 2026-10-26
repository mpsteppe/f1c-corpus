// Function: FUN_00553a20 @ 00553a20
// Size (bytes): 121


void __thiscall FUN_00553a20(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x18) & 0x40000) != 0) {
    FUN_0055c860(param_1,param_2,param_2 + 0xc,param_3);
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffbff;
    return;
  }
  iVar3 = param_1;
  uVar1 = __ftol(param_3,param_1);
  uVar2 = __ftol(uVar1);
  __ftol(uVar2);
  __ftol();
  FUN_00553aa0(uVar2,uVar1,param_3,iVar3);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffbff;
  return;
}


