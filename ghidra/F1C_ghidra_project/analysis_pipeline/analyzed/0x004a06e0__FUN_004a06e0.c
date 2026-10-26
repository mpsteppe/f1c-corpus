// Function: FUN_004a06e0 @ 004a06e0
// Size (bytes): 118


undefined4 FUN_004a06e0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  FUN_004b0ef0(4);
  DAT_008ab6e4 = (uint)(DAT_007d0038 != 0);
  DAT_005cc9e8 = 1;
  FUN_004c2810();
  DAT_007c5690 = 1;
  iVar1 = FUN_004c2850();
  if (iVar1 != 0) {
    uVar2 = FUN_004c11c0();
    FUN_0042cf10(uVar2);
  }
  return 0;
}


