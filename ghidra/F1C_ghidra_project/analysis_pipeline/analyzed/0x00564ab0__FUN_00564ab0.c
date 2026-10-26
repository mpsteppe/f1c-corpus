// Function: FUN_00564ab0 @ 00564ab0
// Size (bytes): 88


int __fastcall FUN_00564ab0(undefined4 param_1,int param_2,int param_3,int param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = param_2;
  if (0 < param_3) {
    do {
      iVar1 = (*param_5)(param_1,iVar3);
      if (iVar1 == 0) {
        return iVar2 * param_4 + param_2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + param_4;
    } while (iVar2 < param_3);
  }
  return 0;
}


