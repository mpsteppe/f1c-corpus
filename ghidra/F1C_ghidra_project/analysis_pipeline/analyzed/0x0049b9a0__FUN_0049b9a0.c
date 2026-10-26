// Function: FUN_0049b9a0 @ 0049b9a0
// Size (bytes): 138


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049b9a0(void)

{
  int iVar1;
  int iVar2;
  undefined3 uVar3;
  undefined3 extraout_var;
  char cVar4;
  
  iVar2 = (&DAT_007c54f0)[DAT_007c54e4];
  iVar1 = *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894);
  if (iVar1 == *(int *)(iVar2 + 0x4894)) {
    iVar2 = CONCAT22((short)((uint)iVar2 >> 0x10),
                     (ushort)(_DAT_007c9174 < _DAT_007c9204) << 8 |
                     (ushort)(NAN(_DAT_007c9174) || NAN(_DAT_007c9204)) << 10 |
                     (ushort)(_DAT_007c9174 == _DAT_007c9204) << 0xe);
    if ((_DAT_007c9174 < _DAT_007c9204 == 0 && (_DAT_007c9174 == _DAT_007c9204) == 0) &&
       (iVar2 = DAT_007cea5c, DAT_007cea5c != 0)) {
      cVar4 = '\x01';
      goto LAB_0049b9eb;
    }
  }
  cVar4 = '\0';
LAB_0049b9eb:
  uVar3 = (undefined3)((uint)iVar2 >> 8);
  if (((&DAT_005ec354)[(&DAT_005f0f6c)[iVar1 * 0x1230]] == '\0') && (cVar4 == '\x01')) {
    FUN_0041b190(&DAT_005ec6d8 + iVar1 * 0x48c0);
    uVar3 = extraout_var;
  }
  (&DAT_005ec354)[(&DAT_005f0f6c)[iVar1 * 0x1230]] = cVar4;
  return CONCAT31(uVar3,cVar4);
}


