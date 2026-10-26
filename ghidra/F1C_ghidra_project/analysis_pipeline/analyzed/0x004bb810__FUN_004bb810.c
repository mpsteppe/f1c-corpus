// Function: FUN_004bb810 @ 004bb810
// Size (bytes): 193


void __fastcall FUN_004bb810(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  FUN_004bb950();
  *(undefined4 *)(param_1 + 0x30) = 0;
  if (DAT_007c56a4 == 7) {
    *(undefined4 *)(param_1 + 0xc) = 2;
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x60) = 1;
  }
  iVar1 = DAT_008acf8c;
  if (0x7f < DAT_008acf8c) {
    iVar1 = 0x80;
  }
  *(int *)(param_1 + 0x88) = iVar1;
  pvVar2 = operator_new(iVar1 << 2);
  *(void **)(param_1 + 0x8c) = pvVar2;
  pvVar2 = operator_new(*(int *)(param_1 + 0x88) << 2);
  *(void **)(param_1 + 0x90) = pvVar2;
  pvVar2 = operator_new(*(uint *)(param_1 + 0x88));
  *(void **)(param_1 + 0x94) = pvVar2;
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  if (0 < *(int *)(param_1 + 0x88)) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x8c) + iVar1 * 4) = 0xbf800000;
      *(undefined4 *)(*(int *)(param_1 + 0x90) + iVar1 * 4) = 0xbf800000;
      *(undefined1 *)(iVar1 + *(int *)(param_1 + 0x94)) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x88));
  }
  return;
}


