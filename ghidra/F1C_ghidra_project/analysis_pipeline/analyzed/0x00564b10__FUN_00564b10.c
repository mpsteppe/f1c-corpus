// Function: FUN_00564b10 @ 00564b10
// Size (bytes): 102


int __fastcall
FUN_00564b10(undefined4 param_1,int param_2,int param_3,int param_4,code *param_5,
            undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_3 = param_3 + -1;
  iVar2 = 0;
  *param_6 = 0;
  if (-1 < param_3) {
    do {
      iVar3 = param_3 + iVar2 >> 1;
      iVar1 = (*param_5)(iVar3 * param_4 + param_2,param_1);
      if (iVar1 == 0) {
        *param_6 = 1;
LAB_00564b57:
        param_3 = iVar3 + -1;
      }
      else {
        if (-1 < iVar1) goto LAB_00564b57;
        iVar2 = iVar3 + 1;
      }
    } while (iVar2 <= param_3);
  }
  return iVar2 * param_4 + param_2;
}


