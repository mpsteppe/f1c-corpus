// Function: FUN_00543a80 @ 00543a80
// Size (bytes): 354


undefined4 __thiscall FUN_00543a80(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    if ((*(byte *)(param_1 + 0xec) & 4) == 0) {
      pvVar1 = operator_new(0x3c);
      if (pvVar1 == (void *)0x0) {
        DAT_008b8dbc = 0;
      }
      else {
        DAT_008b8dbc = FUN_005426a0();
      }
      iVar2 = FUN_00542950(DAT_008b8df4,DAT_008b8df4,DAT_008b8df8,0x40008);
      iVar3 = DAT_008b8dbc;
      if (iVar2 != 0) {
        if (DAT_008b8dbc != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar3);
        }
        DAT_008b8dbc = 0;
      }
      pvVar1 = operator_new(0x3c);
      if (pvVar1 == (void *)0x0) {
        DAT_008b8dc0 = 0;
      }
      else {
        DAT_008b8dc0 = FUN_005426a0();
      }
      iVar2 = FUN_00542950(DAT_008b8df4,DAT_008b8df4,DAT_008b8df8,0x40008);
      iVar3 = DAT_008b8dc0;
      if (iVar2 != 0) {
        if (DAT_008b8dc0 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar3);
        }
        DAT_008b8dc0 = 0;
      }
    }
    iVar3 = FUN_0055b6b0(param_2);
    if (iVar3 != 0) {
      if (DAT_008b8dbc != 0) {
        FUN_00542e50();
        iVar3 = DAT_008b8dbc;
        if (DAT_008b8dbc != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar3);
        }
        DAT_008b8dbc = 0;
      }
      if (DAT_008b8dc0 != 0) {
        FUN_00542e50();
        iVar3 = DAT_008b8dc0;
        if (DAT_008b8dc0 != 0) {
          FUN_00557470();
          FUN_00587bcf(iVar3);
        }
        DAT_008b8dc0 = 0;
      }
      return 0xffffffff;
    }
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10800;
  }
  return 0;
}


