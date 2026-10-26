// Function: FUN_0048f0b0 @ 0048f0b0
// Size (bytes): 225


void __thiscall FUN_0048f0b0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_4;
  
  iVar1 = param_4;
  iVar3 = param_3;
  if (((param_2 != 0) && (*(char *)(param_1 + 0x17c) != '\0')) && (*(int *)(param_1 + 0xe4) != 0)) {
    iVar2 = *(int *)(param_1 + 0x120);
    local_4 = param_3;
    param_3 = param_4;
    if (iVar3 < iVar2) {
      param_4 = iVar2 - iVar3;
      local_4 = iVar2;
    }
    else {
      param_4 = 0;
    }
    iVar2 = *(int *)(param_1 + 0x140);
    if (iVar1 < iVar2 + -10) {
      iVar5 = iVar2 - iVar1;
      param_3 = iVar2;
    }
    else {
      iVar5 = 0;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xe4) + 0x1c);
    if (*(int *)(param_1 + 0x124) < iVar2 + iVar3) {
      iVar2 = *(int *)(param_1 + 0x124) - iVar3;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0xe4) + 0x20);
    if (*(int *)(param_1 + 0x144) + 10 < iVar3 + iVar1) {
      iVar3 = *(int *)(param_1 + 0x144) - iVar1;
    }
    uVar7 = 0;
    uVar6 = 0;
    uVar4 = FUN_00495150(local_4,param_3,iVar2,iVar3,0,0);
    FUN_00494a30(param_2,param_4,iVar5,uVar4,local_4,param_3,iVar2,iVar3,uVar6,uVar7);
  }
  return;
}


