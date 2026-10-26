// Function: FUN_00492030 @ 00492030
// Size (bytes): 124


undefined4 __fastcall FUN_00492030(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = FUN_00491fb0();
  while ((iVar1 != 0 && (iVar1 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f8), iVar1 == 0))) {
    iVar1 = FUN_00491fb0();
  }
  do {
    iVar1 = FUN_00491fb0();
    if (iVar1 == 0) break;
    iVar1 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f8);
    if (iVar1 != 0) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4);
    if (iVar1 != 0) {
      iVar2 = iVar2 + -1;
    }
  } while (0 < iVar2);
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -1;
  return 0;
}


