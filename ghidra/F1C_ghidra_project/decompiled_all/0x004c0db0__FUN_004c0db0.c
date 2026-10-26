// Function: FUN_004c0db0 @ 004c0db0
// Strings:  [Game Filter]


/* WARNING: Removing unreachable block (ram,0x004c0f49) */

undefined4 __fastcall FUN_004c0db0(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_20 [32];
  
  iVar1 = DAT_007d0a20;
  *(undefined4 *)(param_1 + 0xb144) = 2;
  *(undefined4 *)(param_1 + 0xb148) = 0;
  FUN_004c07f0();
  iVar5 = 0x67;
  do {
    FUN_004c07f0();
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_004b0b20(local_20,0x1f);
  FUN_00566650(local_20);
  iVar5 = 0;
  puVar2 = DAT_007ce64c;
  if (DAT_007ce64c == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  *(int *)(param_1 + 0xb110) = iVar1;
  *(int *)(param_1 + 0xb114) = iVar1;
  *(undefined4 *)(param_1 + 0xb118) = 0;
  *(undefined1 *)(param_1 + 0xb11c) = 1;
  puVar2 = DAT_007d0dcc;
  if (DAT_007d0dcc == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  FUN_005665b0(&DAT_005c32d8);
  uVar3 = FUN_005681f0(s_Game_Filter_005c7130);
  FUN_005665b0(uVar3);
  FUN_004bf630();
  puVar2 = DAT_007ce64c;
  if (DAT_007ce64c == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_004bf790(iVar1,puVar2,&DAT_005ea438);
  if (0 < iVar1) {
    param_1 = param_1 + 0x10;
    do {
      puVar4 = (undefined4 *)FUN_004bfcd0(iVar5);
      FUN_00566650(puVar4 + 0x2f);
      puVar2 = (undefined1 *)*puVar4;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      FUN_00566650(puVar2);
      FUN_00566650(&DAT_005ea438);
      *(int *)(param_1 + 0x194) = iVar5;
      *(int *)(param_1 + 0x198) = iVar5;
      *(undefined4 *)(param_1 + 0x19c) = 1;
      *(undefined1 *)(param_1 + 0x1a0) = 1;
      iVar5 = iVar5 + 1;
      param_1 = param_1 + 0x1b4;
    } while (iVar5 < iVar1);
  }
  FUN_004bf640();
  return 0;
}


