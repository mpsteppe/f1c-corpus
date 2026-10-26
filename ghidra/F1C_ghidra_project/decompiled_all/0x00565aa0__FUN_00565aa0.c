// Function: FUN_00565aa0 @ 00565aa0
// Strings:  [(%lf), (%lf,%lf), (%lf,%lf,%lf), (%lf,%lf,%lf,%lf)]


bool __thiscall
FUN_00565aa0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_00565400(param_2);
  if (iVar1 == 0) {
    return false;
  }
  if (param_6 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___lf__lf__lf__lf__005e514c,param_3,
                         param_4,param_5,param_6);
    return iVar1 == 4;
  }
  if (param_5 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___lf__lf__lf__005e513c,param_3,param_4,
                         param_5);
    return iVar1 == 3;
  }
  if (param_4 != 0) {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___lf__lf__005e5130,param_3,param_4);
    return iVar1 == 2;
  }
  if (param_3 == 0) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___lf__005e5128,param_3);
    bVar2 = iVar1 == 1;
    if (!bVar2) {
      iVar1 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&PTR_DAT_005d46f8,param_3);
      return iVar1 == 1;
    }
  }
  return bVar2;
}


