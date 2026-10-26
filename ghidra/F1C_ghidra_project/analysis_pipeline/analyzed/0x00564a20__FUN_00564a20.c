// Function: FUN_00564a20 @ 00564a20
// Size (bytes): 136


int __thiscall FUN_00564a20(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_4;
  
  local_4 = 1;
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (param_4 == 0) {
      iVar2 = param_1[2];
      iVar1 = iVar1 - param_3;
      FUN_005648b0(iVar1,iVar2,param_2);
      iVar1 = FUN_00564ab0(iVar1,iVar2,param_2);
    }
    else {
      piVar3 = &local_4;
      iVar2 = param_1[2];
      iVar1 = iVar1 - param_3;
      FUN_005648b0(iVar1,iVar2,param_2,piVar3);
      iVar1 = FUN_00564b10(iVar1,iVar2,param_2,piVar3);
    }
    if ((iVar1 != 0) && (local_4 != 0)) {
      return (iVar1 - param_1[5]) / param_1[2];
    }
  }
  return -1;
}


