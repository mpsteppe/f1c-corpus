// Function: FUN_00537fe0 @ 00537fe0
// Size (bytes): 528


void __fastcall FUN_00537fe0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x16ad);
  *(ushort *)(param_1 + 0x16ab) =
       *(ushort *)(param_1 + 0x16ab) | (ushort)(2 << ((byte)iVar1 & 0x1f));
  if (iVar1 < 0xe) {
    *(int *)(param_1 + 0x16ad) = iVar1 + 3;
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    iVar1 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x16ad) = iVar1 + -0xd;
    *(ushort *)(param_1 + 0x16ab) = 2 >> (0x10U - (char)iVar1 & 0x1f);
  }
  iVar1 = *(int *)(param_1 + 0x16ad);
  if (iVar1 < 10) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(0 << ((byte)iVar1 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar1 + 7;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(0 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    iVar1 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x16ad) = iVar1 + -9;
    *(ushort *)(param_1 + 0x16ab) = 0 >> (0x10U - (char)iVar1 & 0x1f);
  }
  FUN_00539690();
  iVar1 = *(int *)(param_1 + 0x16ad);
  if ((*(int *)(param_1 + 0x16a7) - iVar1) + 0xb < 9) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(2 << ((byte)iVar1 & 0x1f));
    if (iVar1 < 0xe) {
      *(int *)(param_1 + 0x16ad) = iVar1 + 3;
    }
    else {
      *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
           *(undefined1 *)(param_1 + 0x16ab);
      iVar1 = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x14) = iVar1;
      *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      iVar1 = *(int *)(param_1 + 0x16ad);
      *(int *)(param_1 + 0x16ad) = iVar1 + -0xd;
      *(ushort *)(param_1 + 0x16ab) = 2 >> (0x10U - (char)iVar1 & 0x1f);
    }
    iVar1 = *(int *)(param_1 + 0x16ad);
    if (9 < iVar1) {
      *(ushort *)(param_1 + 0x16ab) =
           *(ushort *)(param_1 + 0x16ab) | (ushort)(0 << ((byte)iVar1 & 0x1f));
      *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
           *(undefined1 *)(param_1 + 0x16ab);
      iVar1 = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x14) = iVar1;
      *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      iVar1 = *(int *)(param_1 + 0x16ad);
      *(int *)(param_1 + 0x16ad) = iVar1 + -9;
      *(ushort *)(param_1 + 0x16ab) = 0 >> (0x10U - (char)iVar1 & 0x1f);
      FUN_00539690();
      *(undefined4 *)(param_1 + 0x16a7) = 7;
      return;
    }
    *(int *)(param_1 + 0x16ad) = iVar1 + 7;
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(0 << ((byte)iVar1 & 0x1f));
    FUN_00539690();
  }
  *(undefined4 *)(param_1 + 0x16a7) = 7;
  return;
}


