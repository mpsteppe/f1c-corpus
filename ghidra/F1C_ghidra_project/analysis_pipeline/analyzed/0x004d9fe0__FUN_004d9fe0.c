// Function: FUN_004d9fe0 @ 004d9fe0
// Size (bytes): 156


void __fastcall FUN_004d9fe0(int param_1)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0;
  if (*(int *)(DAT_007c54e0 + 0x40d0) == 0) {
    if (*(int *)(DAT_007c54e0 + 0x40d4) != 0) {
      *(undefined1 *)(param_1 + 0x18) = 0;
      iVar2 = *(int *)(DAT_007c54e0 + 0x40d4);
      *(int *)(param_1 + 0x1c) = iVar2;
      iVar1 = DAT_007c54e0;
      goto LAB_004da04b;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x18) = 1;
    iVar1 = *(int *)(DAT_007c54e0 + 0x40d0);
    *(int *)(param_1 + 0x1c) = iVar1;
    iVar2 = DAT_007c54e0;
LAB_004da04b:
    iVar1 = FUN_0049b6d0(iVar1,iVar2,param_1 + 0x14,&local_4);
    if (iVar1 != 0) goto LAB_004da072;
  }
  if ((*(float *)(param_1 + 0x14) < DAT_0059e440 == (*(float *)(param_1 + 0x14) == DAT_0059e440)) &&
     (local_4 == 0)) {
    return;
  }
LAB_004da072:
  FUN_004d7e30();
  return;
}


