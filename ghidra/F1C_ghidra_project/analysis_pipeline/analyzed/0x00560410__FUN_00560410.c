// Function: FUN_00560410 @ 00560410
// Size (bytes): 173


undefined8 __fastcall
FUN_00560410(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,
            undefined4 *param_5,int param_6,uint param_7,int param_8,uint param_9)

{
  undefined4 uVar1;
  bool bVar2;
  short sVar3;
  undefined4 in_EAX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  DAT_005dd804 = param_9 & 0xffff;
  uVar6 = param_7 * 2;
  uVar4 = DAT_005dd804;
  if ((DAT_005dd804 == 0xffff) && (uVar4 = uVar6, (uVar6 & 7) == 0)) {
    uVar4 = (param_7 & 0x7fffffff) >> 1;
    DAT_005dd804 = 0xffff;
    do {
      for (; uVar4 != 0; uVar4 = uVar4 - 1) {
        *param_5 = *param_3;
        param_3 = param_3 + 1;
        param_5 = param_5 + 1;
      }
      uVar4 = uVar6 & 3;
      if (uVar4 != 0) {
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)param_5 = *(undefined1 *)param_3;
          param_3 = (undefined4 *)((int)param_3 + 1);
          param_5 = (undefined4 *)((int)param_5 + 1);
        }
      }
      param_3 = (undefined4 *)((int)param_3 + param_4 + param_7 * -2);
      uVar4 = (param_7 & 0x7fffffff) >> 1;
      param_5 = (undefined4 *)((int)param_5 + param_6 + param_7 * -2);
      iVar7 = param_8 + -1;
      bVar2 = 0 < param_8;
      param_8 = iVar7;
    } while (iVar7 != 0 && bVar2);
    return CONCAT44(param_2,in_EAX);
  }
  do {
    iVar7 = 0;
    uVar6 = param_7;
    do {
      uVar1 = *(undefined4 *)(iVar7 + (int)param_3);
      sVar3 = (short)uVar1;
      if (sVar3 != (short)uVar4) {
        *(short *)(iVar7 + (int)param_5) = sVar3;
      }
      iVar5 = uVar6 - 1;
      if ((int)uVar6 < 2) break;
      sVar3 = (short)((uint)uVar1 >> 0x10);
      if (sVar3 != (short)uVar4) {
        *(short *)(iVar7 + 2 + (int)param_5) = sVar3;
      }
      iVar7 = iVar7 + 4;
      uVar6 = uVar6 - 2;
    } while (uVar6 != 0 && 0 < iVar5);
    param_3 = (undefined4 *)((int)param_3 + param_4);
    param_5 = (undefined4 *)((int)param_5 + param_6);
    iVar7 = param_8 + -1;
    bVar2 = param_8 < 1;
    param_8 = iVar7;
    if (iVar7 == 0 || bVar2) {
      return CONCAT44(param_2,in_EAX);
    }
  } while( true );
}


