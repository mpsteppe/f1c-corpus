// Function: FUN_004a2220 @ 004a2220
// Size (bytes): 170


void __fastcall FUN_004a2220(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 0x22) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x26) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2a) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x2e) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  if ((DAT_008afe88 != 0) && (*(int *)(param_1 + 0x32) != 0)) {
    FUN_00545150(*(int *)(param_1 + 0x32));
  }
  *(undefined4 *)(param_1 + 0x32) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (*(int *)(param_1 + 0x36) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x36));
  }
  iVar1 = *(int *)(param_1 + 0x3a);
  *(undefined4 *)(param_1 + 0x36) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004dd4d0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  *(undefined4 *)(param_1 + 0x3a) = 0;
  return;
}


