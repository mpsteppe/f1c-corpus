// Function: FUN_005608f6 @ 005608f6
// Size (bytes): 167


undefined8 __fastcall
FUN_005608f6(undefined4 param_1,undefined4 param_2,ushort *param_3,int param_4,ushort *param_5,
            int param_6,uint param_7,int param_8,uint param_9)

{
  undefined8 uVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 in_EAX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  DAT_005dd804 = param_9 & 0xffff;
  param_4 = param_4 + param_7 * -2;
  param_6 = param_6 + param_7 * -2;
  uVar5 = param_7;
  if ((DAT_005dd804 == 0xffff) && ((param_7 * 2 & 7) == 0)) {
    DAT_005dd804 = 0xffff;
    uVar5 = (param_7 & 0x7fffffff) >> 2;
    do {
      do {
        uVar1 = *(undefined8 *)param_3;
        param_3 = param_3 + 4;
        *(undefined8 *)param_5 = uVar1;
        param_5 = param_5 + 4;
        uVar4 = uVar5 - 1;
        bVar3 = 0 < (int)uVar5;
        uVar5 = uVar4;
      } while (uVar4 != 0 && bVar3);
      uVar5 = param_7 * 2 & 7;
      if (uVar5 != 0) {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(char *)param_5 = (char)*param_3;
          param_3 = (ushort *)((int)param_3 + 1);
          param_5 = (ushort *)((int)param_5 + 1);
        }
      }
      param_3 = (ushort *)((int)param_3 + param_4);
      uVar5 = (param_7 & 0x7fffffff) >> 2;
      param_5 = (ushort *)((int)param_5 + param_6);
      iVar6 = param_8 + -1;
      bVar3 = 0 < param_8;
      param_8 = iVar6;
    } while (iVar6 != 0 && bVar3);
    return CONCAT44(param_2,in_EAX);
  }
  do {
    do {
      uVar2 = *param_3;
      param_3 = param_3 + 1;
      if (uVar2 != DAT_005dd804) {
        *param_5 = uVar2;
      }
      param_5 = param_5 + 1;
      uVar4 = uVar5 - 1;
      bVar3 = 0 < (int)uVar5;
      uVar5 = uVar4;
    } while (uVar4 != 0 && bVar3);
    param_3 = (ushort *)((int)param_3 + param_4);
    param_5 = (ushort *)((int)param_5 + param_6);
    iVar6 = param_8 + -1;
    bVar3 = 0 < param_8;
    uVar5 = param_7;
    param_8 = iVar6;
  } while (iVar6 != 0 && bVar3);
  return CONCAT44(param_2,in_EAX);
}


