// Function: FUN_00588d95 @ 00588d95
// Strings:  [LC_CTYPE, LC_COLLATE]


undefined1 * FUN_00588d95(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  bVar1 = true;
  if (DAT_005e64f4 == (undefined1 *)0x0) {
    DAT_005e64f4 = _malloc(0x351);
  }
  *DAT_005e64f4 = 0;
  FUN_00588f66(DAT_005e64f4,3,PTR_s_LC_COLLATE_005e64fc,&DAT_005c30ac,PTR_DAT_005e6500);
  ppuVar3 = &PTR_DAT_005e6500;
  do {
    FUN_0058fcb0(DAT_005e64f4,&DAT_005b8c74);
    ppuVar4 = ppuVar3 + 3;
    iVar2 = _strcmp(*ppuVar3,ppuVar3[3]);
    if (iVar2 != 0) {
      bVar1 = false;
    }
    FUN_00588f66(DAT_005e64f4,3,ppuVar3[2],&DAT_005c30ac,*ppuVar4);
    ppuVar3 = ppuVar4;
  } while ((int)ppuVar4 < 0x5e6530);
  if (!bVar1) {
    return DAT_005e64f4;
  }
  FUN_0058aa6f(DAT_005e64f4);
  DAT_005e64f4 = (undefined1 *)0x0;
  return PTR_DAT_005e650c;
}


