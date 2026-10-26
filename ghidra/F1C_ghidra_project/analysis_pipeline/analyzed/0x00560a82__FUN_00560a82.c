// Function: FUN_00560a82 @ 00560a82
// Size (bytes): 159


undefined8 __fastcall
FUN_00560a82(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
            undefined4 *param_5,int param_6,int param_7,int param_8,uint param_9)

{
  bool bVar1;
  undefined4 in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_005dd844 = (uint)(param_9 == 0xffffffff);
  param_9 = param_9 & 0xffffff;
  DAT_005dd814 = param_7;
  DAT_005dd804 = param_9;
  if (DAT_005dd844 == 1) {
    iVar2 = param_7 * -4;
    iVar4 = param_7 * -4;
    do {
      for (; param_7 != 0; param_7 = param_7 + -1) {
        *param_5 = *param_3;
        param_3 = param_3 + 1;
        param_5 = param_5 + 1;
      }
      param_3 = (undefined4 *)((int)param_3 + param_4 + iVar2);
      param_5 = (undefined4 *)((int)param_5 + param_6 + iVar4);
      iVar3 = param_8 + -1;
      bVar1 = 0 < param_8;
      param_7 = DAT_005dd814;
      param_8 = iVar3;
    } while (iVar3 != 0 && bVar1);
    return CONCAT44(param_2,in_EAX);
  }
  do {
    iVar4 = 0;
    iVar2 = param_7;
    do {
      if (*(uint *)(iVar4 + (int)param_3) != param_9) {
        *(uint *)(iVar4 + (int)param_5) = *(uint *)(iVar4 + (int)param_3);
      }
      iVar4 = iVar4 + 4;
      iVar3 = iVar2 + -1;
      bVar1 = 0 < iVar2;
      iVar2 = iVar3;
    } while (iVar3 != 0 && bVar1);
    param_3 = (undefined4 *)((int)param_3 + param_4);
    param_5 = (undefined4 *)((int)param_5 + param_6);
    iVar2 = param_8 + -1;
    bVar1 = 0 < param_8;
    param_8 = iVar2;
  } while (iVar2 != 0 && bVar1);
  return CONCAT44(param_2,in_EAX);
}


