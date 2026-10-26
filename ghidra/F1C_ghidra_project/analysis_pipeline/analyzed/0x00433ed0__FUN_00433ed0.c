// Function: FUN_00433ed0 @ 00433ed0
// Size (bytes): 229


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00433ed0(undefined4 param_1,char param_2)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 1;
  cVar1 = FUN_0042bc10();
  if ((cVar1 != '\0') &&
     (iVar4 = *(int *)(DAT_007c54e8 + 0x4898) * 0x424 + DAT_008ac394, iVar4 != 0)) {
    _DAT_007c56c4 = DAT_007d0450;
    FUN_0042ed70();
    puVar2 = *(undefined1 **)(iVar4 + 8);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    iVar4 = FUN_004f4270(puVar2,&DAT_007c56c0,0);
    if (iVar4 == 0) {
      FUN_0042ebc0();
      iVar4 = FUN_004f4270(param_1,&DAT_007c56c0,1);
      if (iVar4 == 0) {
        uVar3 = 0;
        DAT_007c56c0 = 0;
        if (param_2 != '\0') {
          FUN_00566650(param_1);
          FUN_00568b00();
        }
      }
      FUN_00430f00();
    }
  }
  return uVar3;
}


