// Function: FUN_0050fea7 @ 0050fea7
// Strings:  [DisableD3DXPSGP]


int FUN_0050fea7(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  if (param_1 == 0) {
    DAT_005d7998 = 0xffff;
    ppuVar2 = &PTR_FUN_005d78b0;
    ppuVar3 = &PTR_LAB_005d77c8;
    for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = *ppuVar2;
      ppuVar2 = ppuVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
  }
  else if (DAT_005d7998 == 0xffff) {
    DAT_005d7998 = 0;
    ppuVar2 = &PTR_FUN_005d78b0;
    ppuVar3 = &PTR_LAB_005d77c8;
    for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar3 = *ppuVar2;
      ppuVar2 = ppuVar2 + 1;
      ppuVar3 = ppuVar3 + 1;
    }
    FUN_00517927(&PTR_LAB_005d77c8);
    iVar1 = FUN_0050fbfc(4,"DisableD3DXPSGP",&param_1,4);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    if (param_1 != 1) {
      iVar1 = FUN_0050fdf3(7);
      if (iVar1 == 0) {
        iVar1 = FUN_0050fdf3(10);
        if (iVar1 == 0) {
          iVar1 = FUN_0050fdf3(6);
          if (iVar1 != 0) {
            FUN_00516fb0(&PTR_LAB_005d77c8);
            DAT_005d7998 = 3;
          }
        }
        else {
          FUN_005170c0(&PTR_LAB_005d77c8);
          DAT_005d7998 = 2;
        }
      }
      else {
        FUN_005172a5(&PTR_LAB_005d77c8);
        DAT_005d7998 = 1;
      }
    }
  }
  return DAT_005d7998;
}


