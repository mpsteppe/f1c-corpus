
undefined4 __thiscall FUN_0040bd10(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int aiStack_1c [7];
  
  bVar1 = false;
  if ((param_2 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_0058ba36(param_2,0x80);
    FUN_005668b0();
    if (param_3 == 0) {
      FUN_00566a70(param_2,0,1,1);
    }
    else {
      FUN_00566940(param_2,0,1,1);
    }
    if (aiStack_1c[0] != 0) {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x10)) {
        bVar1 = true;
        iVar3 = 0;
        do {
          (**(code **)(*(int *)(*(int *)(param_1 + 0xc) + iVar3) + 8))(aiStack_1c,0);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0xd0;
        } while (iVar2 < *(int *)(param_1 + 0x10));
      }
      FUN_00566b90();
      if (bVar1) {
        FUN_005668d0();
        return 0;
      }
    }
    FUN_005668d0();
  }
  return 1;
}

