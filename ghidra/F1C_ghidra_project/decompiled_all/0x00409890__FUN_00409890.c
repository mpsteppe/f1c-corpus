// Function: FUN_00409890 @ 00409890
// Strings:  [MAINVIEW, REARVIEW, MIRROR.BMP]


undefined4 __fastcall FUN_00409890(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00545f40();
  if (iVar1 != 0) {
    iVar1 = FUN_00547920(s_MIRROR_BMP_005be91c);
    if (iVar1 != 0) {
      if ((*(uint *)(*(int *)(iVar1 + 0x54) + 0x18) & 0x40000) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        uVar2 = FUN_00544f50(s_REARVIEW_005be8ec);
        *(undefined4 *)(param_1 + 8) = uVar2;
      }
      if (*(int *)(param_1 + 8) == 0) {
        iVar1 = *(int *)(iVar1 + 0x54);
      }
      else {
        uVar2 = *(undefined4 *)(iVar1 + 0x54);
        *(undefined4 *)(param_1 + 0xc) = uVar2;
        FUN_00542560(uVar2);
        iVar1 = FUN_00544f50(s_MAINVIEW_005be8e0);
        if (iVar1 != 0) {
          FUN_00542540(&LAB_00409950,0);
        }
        FUN_00409970();
        iVar1 = *(int *)(param_1 + 0xc);
      }
      FUN_00543440(0,0,*(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(iVar1 + 0x20),&DAT_00686b75);
    }
  }
  return 0;
}


