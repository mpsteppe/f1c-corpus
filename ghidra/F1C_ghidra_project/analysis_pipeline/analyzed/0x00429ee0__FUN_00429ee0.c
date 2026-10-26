// Function: FUN_00429ee0 @ 00429ee0
// Size (bytes): 226


void __fastcall FUN_00429ee0(int param_1)

{
  int iVar1;
  
  if (DAT_007c56a8 == 3) {
    FUN_0042adb0();
    *(undefined4 *)(param_1 + 0x4544) = 0;
    FUN_0042ac90();
  }
  if (DAT_007c56a4 != 7) {
    iVar1 = FUN_00424e30(0);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x4544) = 0;
      FUN_0042acd0(0x12);
      *(undefined4 *)(param_1 + 0x4510) = 5;
      FUN_0042aca0(1);
    }
  }
  iVar1 = FUN_00424e30(5);
  if (iVar1 != 0) {
    FUN_0042acd0(99999);
    *(undefined4 *)(param_1 + 0x4544) = 1;
  }
  iVar1 = FUN_00424e30(4);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x443c) = 1;
    FUN_0042acd0(0x12);
  }
  iVar1 = FUN_00424e30(0xe);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x4544) = 0;
    *(undefined4 *)(param_1 + 0x443c) = 1;
  }
  if (DAT_007c56a8 == 4) {
    FUN_0042aca0(0);
    FUN_0042acd0(99999);
    *(undefined4 *)(param_1 + 0x4544) = 1;
  }
  return;
}


