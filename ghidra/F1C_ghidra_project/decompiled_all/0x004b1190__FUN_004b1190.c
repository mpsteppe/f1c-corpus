// Function: FUN_004b1190 @ 004b1190
// Strings:  [RaceLaps, QualifyLaps]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b1190(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_ESI;
  
  *(undefined4 *)(param_1 + 0x200c) = 0xc;
  if (*(int *)(param_1 + 0x200c) < *(int *)(param_1 + 0x2014)) {
    *(int *)(param_1 + 0x200c) = *(int *)(param_1 + 0x2014);
  }
  else if (*(int *)(param_1 + 0x2018) < *(int *)(param_1 + 0x200c)) {
    *(int *)(param_1 + 0x200c) = *(int *)(param_1 + 0x2018);
  }
  *(undefined4 *)(param_1 + 0x2108) = 5;
  if (*(int *)(param_1 + 0x2108) < *(int *)(param_1 + 0x2110)) {
    *(int *)(param_1 + 0x2108) = *(int *)(param_1 + 0x2110);
  }
  else if (*(int *)(param_1 + 0x2114) < *(int *)(param_1 + 0x2108)) {
    *(int *)(param_1 + 0x2108) = *(int *)(param_1 + 0x2114);
  }
  *(undefined4 *)(param_1 + 0x2204) = 0xf;
  if (*(int *)(param_1 + 0x2204) < *(int *)(param_1 + 0x220c)) {
    *(int *)(param_1 + 0x2204) = *(int *)(param_1 + 0x220c);
  }
  else if (*(int *)(param_1 + 0x2210) < *(int *)(param_1 + 0x2204)) {
    *(int *)(param_1 + 0x2204) = *(int *)(param_1 + 0x2210);
  }
  puVar1 = *(undefined1 **)(param_1 + 0x154);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_004c5840(puVar1);
  if (iVar2 != 0) {
    iVar2 = FUN_005679c0(s_QualifyLaps_005d231c);
    if (iVar2 != 0) {
      uVar3 = FUN_00567970();
      uVar3 = FUN_00587ece(uVar3);
      *(undefined4 *)(param_1 + 0x200c) = uVar3;
      if (*(int *)(param_1 + 0x200c) < *(int *)(param_1 + 0x2014)) {
        *(int *)(param_1 + 0x200c) = *(int *)(param_1 + 0x2014);
      }
      else if (*(int *)(param_1 + 0x2018) < *(int *)(param_1 + 0x200c)) {
        *(int *)(param_1 + 0x200c) = *(int *)(param_1 + 0x2018);
      }
    }
    iVar2 = FUN_005679c0(s_RaceLaps_005c7444);
    if (iVar2 != 0) {
      uVar3 = FUN_00567970();
      uVar3 = FUN_00587ece(uVar3);
      *(undefined4 *)(param_1 + 0x2108) = uVar3;
      if (*(int *)(param_1 + 0x2108) < *(int *)(param_1 + 0x2110)) {
        *(int *)(param_1 + 0x2108) = *(int *)(param_1 + 0x2110);
      }
      else if (*(int *)(param_1 + 0x2114) < *(int *)(param_1 + 0x2108)) {
        *(int *)(param_1 + 0x2108) = *(int *)(param_1 + 0x2114);
      }
      iVar2 = __ftol();
      if (iVar2 < 1) {
        iVar2 = 1;
      }
      *(int *)(param_1 + 0x2108) = iVar2;
      if (*(int *)(param_1 + 0x2108) < *(int *)(param_1 + 0x2110)) {
        *(int *)(param_1 + 0x2108) = *(int *)(param_1 + 0x2110);
        FUN_0059d74e(unaff_ESI);
        return;
      }
      if (*(int *)(param_1 + 0x2114) < *(int *)(param_1 + 0x2108)) {
        *(int *)(param_1 + 0x2108) = *(int *)(param_1 + 0x2114);
        FUN_0059d74e(unaff_ESI);
        return;
      }
    }
    iVar2 = FUN_005679c0(s_Recon_Pit_Open_005d1898);
    if (iVar2 != 0) {
      uVar3 = FUN_00567970();
      _DAT_007cec30 = FUN_00587ece(uVar3);
    }
    iVar2 = FUN_005679c0(s_Recon_Pit_Closed_005d183c);
    if (iVar2 != 0) {
      uVar3 = FUN_00567970();
      _DAT_007cec54 = FUN_00587ece(uVar3);
    }
    FUN_005679c0(s_RaceTime_005d2310);
    FUN_004b1375(unaff_ESI);
    return;
  }
  return;
}


