// Function: FUN_00491680 @ 00491680
// Size (bytes): 91


undefined4 __thiscall FUN_00491680(short *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (int)*param_1;
  iVar2 = iVar1;
  if (iVar1 <= param_2) {
    iVar2 = param_2;
  }
  iVar3 = param_1[2] + iVar1;
  if (param_4 + param_2 <= param_1[2] + iVar1) {
    iVar3 = param_4 + param_2;
  }
  if (iVar3 != iVar2 && -1 < iVar3 - iVar2) {
    iVar1 = (int)param_1[1];
    iVar2 = iVar1;
    if (iVar1 <= param_3) {
      iVar2 = param_3;
    }
    iVar3 = param_1[3] + iVar1;
    if (param_5 + param_3 <= param_1[3] + iVar1) {
      iVar3 = param_5 + param_3;
    }
    if (iVar3 != iVar2 && -1 < iVar3 - iVar2) {
      return 1;
    }
  }
  return 0;
}


