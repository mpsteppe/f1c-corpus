// Function: FUN_004193a0 @ 004193a0
// Size (bytes): 347


void __thiscall FUN_004193a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (*(int *)(DAT_007c54e8 + 0x4894) != *(int *)(param_2 + 0x4894)) {
    return;
  }
  if (param_3 == -1) {
    param_3 = FUN_004d7c10(*(undefined4 *)(param_2 + 0x4048));
  }
  iVar1 = FUN_004d7cc0(param_3);
  iVar2 = FUN_004d1ad0(iVar1);
  if (iVar2 != 2) {
    return;
  }
  if (*(int *)(param_1 + 0x4f0 + iVar1 * 4) == 2) {
    return;
  }
  FUN_004144d0();
  if (iVar1 == 0) {
    FUN_00418a20(0x89);
    uVar3 = 0x8a;
  }
  else if (iVar1 == 1) {
    if (DAT_007c56a8 == 8) goto LAB_004194d9;
    FUN_00418a20(0x85);
    uVar3 = 0x86;
  }
  else {
    if (iVar1 != 2) goto LAB_004194d9;
    FUN_00418a20(0x87);
    uVar3 = 0x88;
  }
  FUN_004144f0(uVar3,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
LAB_004194d9:
  FUN_00418560(local_20);
  *(undefined4 *)(param_1 + 0x4f0 + iVar1 * 4) = 2;
  return;
}


