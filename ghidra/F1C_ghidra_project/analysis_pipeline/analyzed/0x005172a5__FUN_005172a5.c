// Function: FUN_005172a5 @ 005172a5
// Size (bytes): 550


void FUN_005172a5(undefined4 *param_1)

{
  byte bVar1;
  byte extraout_AH;
  
  bVar1 = FUN_005171d0();
  if (((bVar1 & 0x20) != 0) && ((char)bVar1 < '\0')) {
    *param_1 = &LAB_00526ca8;
    param_1[1] = &LAB_005261ea;
    param_1[2] = &LAB_00526f69;
    param_1[3] = &LAB_0052243a;
    param_1[5] = &LAB_00526cfd;
    param_1[6] = &LAB_0052625b;
    param_1[7] = FUN_005262c2;
    param_1[8] = &LAB_00526feb;
    param_1[9] = &LAB_00526d36;
    param_1[10] = &LAB_005267a2;
    param_1[0xb] = &LAB_0052266c;
    param_1[0xc] = &LAB_00527393;
    param_1[0xd] = &LAB_005273d6;
    param_1[0xe] = FUN_005267a7;
    param_1[0xf] = FUN_0052692f;
    param_1[0x10] = &LAB_0052704a;
    param_1[0x11] = &LAB_00526d9a;
    param_1[0x12] = &LAB_005261ce;
    param_1[0x13] = &LAB_00520ed0;
    param_1[0x14] = &LAB_00520f69;
    param_1[0x15] = FUN_00527578;
    param_1[0x16] = &LAB_005274ba;
    param_1[0x17] = FUN_00520fc6;
    param_1[0x18] = &LAB_00521079;
    param_1[0x19] = &LAB_005214aa;
    param_1[0x1a] = &LAB_0052273b;
    param_1[0x1b] = &LAB_0052278b;
    param_1[0x1c] = &LAB_00522876;
    param_1[0x1d] = FUN_0052156f;
    param_1[0x1e] = &LAB_00522952;
    param_1[0x1f] = &LAB_005229b5;
    param_1[0x20] = &LAB_00522a13;
    param_1[0x21] = &LAB_00522a6c;
    param_1[0x22] = &LAB_005275dc;
    param_1[0x23] = FUN_005215db;
    param_1[0x24] = FUN_00521712;
    param_1[0x25] = &LAB_00522ab3;
    param_1[0x26] = &LAB_00522b5b;
    param_1[0x27] = FUN_00522ce2;
    param_1[0x28] = FUN_00523e7a;
    param_1[0x29] = &DAT_0052401f;
    param_1[0x2a] = FUN_00524553;
    param_1[0x2b] = FUN_0052179f;
    param_1[0x2c] = &LAB_00521831;
    param_1[0x36] = &LAB_0052717c;
    param_1[0x33] = &LAB_00526321;
    param_1[0x30] = &LAB_00526e32;
    param_1[0x2e] = &LAB_00526e7b;
    param_1[0x34] = &LAB_005271ed;
    param_1[0x31] = &LAB_00526392;
    param_1[0x37] = FUN_00521895;
    param_1[0x38] = &LAB_0052193c;
    param_1[0x35] = &LAB_005272b5;
    param_1[0x2f] = &LAB_00526ebe;
    param_1[0x32] = &LAB_00526466;
    param_1[4] = &LAB_00525aa2;
    param_1[0x2d] = FUN_005219e1;
    if (((extraout_AH & 1) != 0) && ((extraout_AH & 2) != 0)) {
      param_1[0xf] = FUN_00526b55;
      param_1[0x12] = FUN_005257c0;
      param_1[0x26] = &LAB_00522c2d;
      param_1[0x27] = FUN_0052466c;
      param_1[0x18] = &LAB_00521295;
    }
  }
  return;
}


