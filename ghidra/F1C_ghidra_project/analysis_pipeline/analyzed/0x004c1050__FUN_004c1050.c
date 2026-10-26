// Function: FUN_004c1050 @ 004c1050
// Size (bytes): 311


uint __fastcall FUN_004c1050(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = FUN_004c11d0();
  puVar2 = (undefined4 *)FUN_004c11e0(uVar1);
  uVar4 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = (undefined1 *)*puVar2;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_004c55b0(puVar3);
    FUN_004c54f0(0);
    *(undefined4 *)(param_1 + 0xb118) = 0;
    FUN_004c0850();
    iVar5 = 0x67;
    iVar6 = param_1;
    do {
      *(undefined4 *)(iVar6 + 0x1ac) = 1;
      FUN_004c0850();
      iVar6 = iVar6 + 0x1b4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar6 = FUN_004c1370();
    if (iVar6 + 1 < 0x67) {
      iVar6 = (iVar6 + 1) * 0x48c0;
      do {
        FUN_004ef5a0(0xffffffff,0);
        iVar6 = iVar6 + 0x48c0;
      } while (iVar6 < 0x1d4540);
    }
    FUN_004b1190(0xbf800000);
    DAT_007d00ec = *(int *)(param_1 + 0xb14c);
    if (DAT_007d00ec < DAT_007d00f4) {
      DAT_007d00ec = DAT_007d00f4;
    }
    else if (DAT_007d00f8 < DAT_007d00ec) {
      DAT_007d00ec = DAT_007d00f8;
    }
    puVar3 = *(undefined1 **)(param_1 + 0xaf6c);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = *(undefined1 **)(param_1 + 0xaf74);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    puVar3 = *(undefined1 **)(param_1 + 0xaf74);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    uVar4 = FUN_00415730(puVar3);
  }
  return uVar4 & 0xffffff00;
}


