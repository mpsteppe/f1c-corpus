// Function: FUN_0041e890 @ 0041e890
// Size (bytes): 135


undefined4 __fastcall FUN_0041e890(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar1 = FUN_004c2850();
    if (iVar1 != 0) {
      iVar1 = iVar4;
      FUN_004c2850(iVar4);
      iVar1 = FUN_004c13a0(iVar1);
      if (iVar1 != 0) {
        iVar1 = iVar4;
        FUN_004c2850(iVar4);
        puVar2 = (undefined4 *)FUN_004c13a0(iVar1);
        puVar3 = (undefined1 *)*puVar2;
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        iVar1 = FUN_00588410(puVar3,param_1);
        if (iVar1 == 0) {
          FUN_004c2850(iVar4);
          iVar4 = FUN_004c13a0(iVar4);
          return *(undefined4 *)(iVar4 + 0x198);
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (0x66 < iVar4) {
      return 0;
    }
  } while( true );
}


