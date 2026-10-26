// Function: FUN_00565760 @ 00565760
// Strings:  [(%d,%d), (%d,%d,%d), (%d,%d,%d,%d)]


bool __thiscall
FUN_00565760(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00565400(param_2);
  if (iVar1 == 0) {
    return false;
  }
  if (param_6 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___d__d__d__d__005e5090,param_3,param_4,
                         param_5,param_6);
    return iVar1 == 4;
  }
  if (param_5 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___d__d__d__005e5084,param_3,param_4,
                         param_5);
    return iVar1 == 3;
  }
  if (param_4 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___d__d__005e507c,param_3,param_4);
    return iVar1 == 2;
  }
  if (param_3 == 0) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&DAT_005e5074,param_3);
    bVar2 = iVar1 == 1;
    if (!bVar2) {
      iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&DAT_005c3280,param_3);
      return iVar1 == 1;
    }
  }
  return bVar2;
}


