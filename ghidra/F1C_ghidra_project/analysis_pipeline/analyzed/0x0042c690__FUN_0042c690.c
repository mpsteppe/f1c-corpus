// Function: FUN_0042c690 @ 0042c690
// Size (bytes): 863


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c690(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_008ab6e4 != 2) {
    FUN_0042c440();
    FUN_005895a2(_DAT_008afea0 * _DAT_0059e9b0);
    iVar1 = __ftol();
    if (0xc9 < iVar1 - DAT_007c5694) {
      DAT_007c5694 = iVar1 + -0xc9;
    }
    for (; DAT_007c5694 < iVar1; DAT_007c5694 = DAT_007c5694 + 1) {
      if ((int)DAT_007c5698 % 10 == 0) {
        iVar2 = 0;
        if (0 < DAT_005c329c) {
          do {
            FUN_00424e70();
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_005c329c);
        }
        FUN_00410980();
        iVar2 = 0;
        _DAT_007c932c = 0;
        _DAT_007c9330 = 0;
        _DAT_007c9334 = 0;
        _DAT_007c9338 = 0;
        _DAT_007c933c = 0;
        _DAT_007c9340 = 0;
        _DAT_007c9344 = 0;
        _DAT_007c9348 = 0;
        _DAT_007c934c = 0;
        _DAT_007c9350 = 0;
        _DAT_007c9354 = 0;
        _DAT_007c9358 = 0;
        if (0 < DAT_005c329c) {
          do {
            FUN_004eb430();
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_005c329c);
        }
        iVar2 = 0;
        if (0 < DAT_005c329c) {
          do {
            FUN_004ee2d0();
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_005c329c);
        }
        if (((int)DAT_007c5698 % 400 == 0) && (iVar2 = 0, 0 < DAT_005c329c)) {
          do {
            if (*(int *)((&DAT_007c54f0)[iVar2] + 13000) == 1) {
              FUN_004ed960();
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_005c329c);
        }
        if ((int)DAT_007c5698 % 0x32 == 0) {
          FUN_0042caa0();
          iVar2 = 0;
          if (0 < DAT_005c329c) {
            do {
              FUN_004f1c40();
              iVar2 = iVar2 + 1;
            } while (iVar2 < DAT_005c329c);
          }
          iVar2 = 0;
          if (0 < DAT_005c329c) {
            do {
              if (*(int *)((&DAT_007c54f0)[iVar2] + 13000) == 1) {
                FUN_004ed810();
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < DAT_005c329c);
          }
        }
        if (*(int *)(DAT_007c54e8 + 13000) == 0) {
          FUN_004bccc0();
        }
        if ((int)DAT_007c5698 % DAT_008ad23c == 0) {
          if (DAT_008ad238 != 0) {
            FUN_004d5960();
          }
          if ((DAT_007c5698 == 0) && (DAT_008ad238 != 0)) {
            FUN_004d59b0();
          }
        }
      }
      else if ((*(int *)(DAT_007c54e8 + 13000) == 0) &&
              (((DAT_007ce958 == 0 || ((DAT_007c5698 & 1) == 0)) &&
               ((*(uint *)(DAT_007c54e8 + 0x48bc) >> 3 & 1) != 0)))) {
        FUN_004e4930();
      }
      DAT_007c5698 = DAT_007c5698 + 1;
      if (399 < (int)DAT_007c5698) {
        DAT_007c5698 = 0;
      }
    }
    if (DAT_007cbf24 != 0) {
      FUN_00451720();
    }
  }
  FUN_004109d0();
  return;
}


