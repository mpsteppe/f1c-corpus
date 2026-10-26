// Function: FUN_00565870 @ 00565870
// Strings:  [(%f,%f), (%f,%f,%f), (%f,%f,%f,%f), (%f,%f,%f,%f,%f), (%f,%f,%f,%f,%f,%f), (%f,%f,%f,%f,%f,%f,%f), (%f,%f,%f,%f,%f,%f,%f,%f)]


bool __thiscall
FUN_00565870(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00565400(param_2);
  if (iVar1 == 0) {
    return false;
  }
  if (param_10 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__f__f__f__f__f__f__005e510c,
                         param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
    return iVar1 == 8;
  }
  if (param_9 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__f__f__f__f__f__005e50f4,param_3,
                         param_4,param_5,param_6,param_7,param_8,param_9);
    return iVar1 == 7;
  }
  if (param_8 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__f__f__f__f__005e50e0,param_3,
                         param_4,param_5,param_6,param_7,param_8);
    return iVar1 == 6;
  }
  if (param_7 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__f__f__f__005e50cc,param_3,
                         param_4,param_5,param_6,param_7);
    return iVar1 == 5;
  }
  if (param_6 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__f__f__005e50bc,param_3,param_4,
                         param_5,param_6);
    return iVar1 == 4;
  }
  if (param_5 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__f__005e50b0,param_3,param_4,
                         param_5);
    return iVar1 == 3;
  }
  if (param_4 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___f__f__005e50a8,param_3,param_4);
    return iVar1 == 2;
  }
  if (param_3 == 0) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&DAT_005e50a0,param_3);
    bVar2 = iVar1 == 1;
    if (!bVar2) {
      iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&DAT_005d433c,param_3);
      return iVar1 == 1;
    }
  }
  return bVar2;
}


