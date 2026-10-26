// Function: FUN_00544af0 @ 00544af0
// Size (bytes): 349


undefined4 __fastcall FUN_00544af0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0xec) & 0x100000) != 0) {
    if (*(int *)(param_1 + 0x164) != 0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x160)) {
        do {
          FUN_005502c0();
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x160));
      }
      FUN_005478b0(*(undefined4 *)(param_1 + 0x164));
      *(undefined4 *)(param_1 + 0x164) = 0;
      *(undefined4 *)(param_1 + 0x160) = 0;
      FUN_00541420();
    }
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffefffff;
  }
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
  for (iVar3 = *(int *)(param_1 + 0x100); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x104)) {
    for (iVar2 = *(int *)(iVar3 + 0xec); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
      iVar1 = FUN_00544e20(iVar2,0);
      if (iVar1 != 0) {
        return 0xffffffff;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x108);
  while( true ) {
    if (iVar3 == 0) {
      for (iVar3 = *(int *)(param_1 + 0x148); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x68)) {
        FUN_00557630();
      }
      FUN_00540760();
      return 0;
    }
    iVar2 = FUN_00544e20(iVar3,0);
    if (iVar2 != 0) break;
    iVar3 = *(int *)(iVar3 + 0x4c);
  }
  return 0xffffffff;
}


