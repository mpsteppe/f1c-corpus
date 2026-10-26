// Function: FUN_004d8ab0 @ 004d8ab0
// Strings:  [FTFU30WH, font.mas, FTingame01, FTim24wh, FTim24hud]


undefined4 __fastcall FUN_004d8ab0(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int local_a4;
  undefined1 local_a0 [32];
  undefined1 local_80 [128];
  
  uVar2 = 1;
  if (DAT_008ad388 != 0) {
    FUN_004d8fb0();
  }
  local_a4 = 0;
  puVar1 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_80,&DAT_005be860,puVar1,PTR_s_font_mas_005d4a5c);
  FUN_0053cbc0(&local_a4,local_80);
  if (local_a4 != 0) {
    FUN_0058815f(local_a0,&DAT_005be860,PTR_s_FTFU30WH_005d4a48,PTR_DAT_005d4a58);
    FUN_0053cfe0(&DAT_008ad388,local_a0,0x20800);
    if (DAT_008ad388 != 0) {
      FUN_00552fd0(0,0xc0);
      *(undefined4 *)(DAT_008ad388 + 0x5c) = *(undefined4 *)(param_1 + 0xe4);
      *(undefined4 *)(DAT_008ad388 + 0x60) = *(undefined4 *)(param_1 + 0xe8);
    }
    FUN_0058815f(local_a0,&DAT_005be860,PTR_s_FTim24hud_005d4a4c,PTR_DAT_005d4a58);
    FUN_0053cfe0(&DAT_008ad38c,local_a0,0x20800);
    if (DAT_008ad38c != 0) {
      FUN_00552fd0(0,0xc0);
      *(undefined4 *)(DAT_008ad38c + 0x5c) = *(undefined4 *)(param_1 + 0xe4);
      *(undefined4 *)(DAT_008ad38c + 0x60) = *(undefined4 *)(param_1 + 0xe8);
    }
    FUN_0058815f(local_a0,&DAT_005be860,PTR_s_FTim24wh_005d4a50,PTR_DAT_005d4a58);
    FUN_0053cfe0(&DAT_008ad390,local_a0,0x20800);
    if (DAT_008ad390 != 0) {
      FUN_00552fd0(0,0xc0);
      *(undefined4 *)(DAT_008ad390 + 0x5c) = *(undefined4 *)(param_1 + 0xe4);
      *(undefined4 *)(DAT_008ad390 + 0x60) = *(undefined4 *)(param_1 + 0xe8);
    }
    FUN_0058815f(local_a0,&DAT_005be860,PTR_s_FTingame01_005d4a54,PTR_DAT_005d4a58);
    uVar2 = FUN_0053cfe0(&DAT_008ad394,local_a0,0x20800);
    if (DAT_008ad394 != 0) {
      FUN_00552fd0(0,0xc0);
      *(undefined4 *)(DAT_008ad394 + 0x5c) = *(undefined4 *)(param_1 + 0xe4);
      *(undefined4 *)(DAT_008ad394 + 0x60) = *(undefined4 *)(param_1 + 0xe8);
    }
    FUN_0053ce40(local_a4);
  }
  return uVar2;
}


