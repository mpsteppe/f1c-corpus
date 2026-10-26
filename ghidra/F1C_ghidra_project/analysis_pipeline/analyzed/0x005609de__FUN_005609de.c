// Function: FUN_005609de @ 005609de
// Size (bytes): 153


undefined8 __fastcall
FUN_005609de(undefined4 param_1,undefined4 param_2,ushort *param_3,int param_4,uint *param_5,
            int param_6,int param_7,int param_8,uint param_9)

{
  bool bVar1;
  undefined4 in_EAX;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  DAT_005dd804 = param_9 & 0xffffff;
  DAT_005dd814 = param_7 * 3;
  param_4 = param_4 + param_7 * -3;
  param_6 = param_6 + param_7 * -3;
  iVar3 = param_7;
  if (DAT_005dd804 != 0xffffff) {
    do {
      do {
        uVar2 = CONCAT31((int3)(((uint)*param_3 << 0x10) >> 8),(char)param_3[1]);
        param_3 = (ushort *)((int)param_3 + 3);
        if (uVar2 != DAT_005dd804) {
          *param_5 = uVar2;
        }
        param_5 = (uint *)((int)param_5 + 3);
        iVar4 = iVar3 + -1;
        bVar1 = 0 < iVar3;
        iVar3 = iVar4;
      } while (iVar4 != 0 && bVar1);
      param_3 = (ushort *)((int)param_3 + param_4);
      param_5 = (uint *)((int)param_5 + param_6);
      iVar4 = param_8 + -1;
      bVar1 = 0 < param_8;
      iVar3 = param_7;
      param_8 = iVar4;
    } while (iVar4 != 0 && bVar1);
    return CONCAT44(param_2,in_EAX);
  }
  DAT_005dd804 = 0xffffff;
  iVar3 = DAT_005dd814;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)param_5 = (char)*param_3;
      param_3 = (ushort *)((int)param_3 + 1);
      param_5 = (uint *)((int)param_5 + 1);
    }
    param_3 = (ushort *)((int)param_3 + param_4);
    param_5 = (uint *)((int)param_5 + param_6);
    iVar4 = param_8 + -1;
    bVar1 = 0 < param_8;
    iVar3 = DAT_005dd814;
    param_8 = iVar4;
  } while (iVar4 != 0 && bVar1);
  return CONCAT44(param_2,in_EAX);
}


