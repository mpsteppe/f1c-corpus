// Function: FUN_00403540 @ 00403540
// Size (bytes): 248


void __fastcall FUN_00403540(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar4 = *(int *)(param_1 + 0x130);
  local_4 = 0;
  if (0 < iVar4) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x134);
      iVar2 = *(int *)(iVar3 + 0x124 + iVar1);
      if ((iVar2 == -1) || (iVar4 <= iVar2)) {
        *(undefined4 *)(iVar3 + 0x110 + iVar1) = 0;
        *(undefined4 *)(iVar3 + 0x124 + *(int *)(param_1 + 0x134)) = 0xffffffff;
      }
      else {
        *(int *)(iVar3 + 0x110 + iVar1) = iVar2 * 0x13c + iVar1;
      }
      iVar4 = *(int *)(param_1 + 0x134);
      iVar1 = *(int *)(iVar3 + 0x120 + iVar4);
      if ((iVar1 == -1) || (*(int *)(param_1 + 0x130) <= iVar1)) {
        *(undefined4 *)(iVar3 + 0x10c + iVar4) = 0;
        *(undefined4 *)(iVar3 + 0x120 + *(int *)(param_1 + 0x134)) = 0xffffffff;
      }
      else {
        *(int *)(iVar3 + 0x10c + iVar4) = iVar1 * 0x13c + iVar4;
      }
      iVar4 = *(int *)(param_1 + 0x134);
      iVar1 = *(int *)(iVar3 + 0x128 + iVar4);
      if ((iVar1 == -1) || (*(int *)(param_1 + 0x130) <= iVar1)) {
        *(undefined4 *)(iVar3 + 0x114 + iVar4) = 0;
        *(undefined4 *)(iVar3 + 0x128 + *(int *)(param_1 + 0x134)) = 0xffffffff;
      }
      else {
        *(int *)(iVar3 + 0x114 + iVar4) = iVar1 * 0x13c + iVar4;
      }
      iVar4 = *(int *)(param_1 + 0x130);
      local_4 = local_4 + 1;
      iVar3 = iVar3 + 0x13c;
    } while (local_4 < iVar4);
  }
  return;
}


