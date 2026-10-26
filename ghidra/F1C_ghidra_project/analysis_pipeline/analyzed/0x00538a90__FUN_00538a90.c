
void __fastcall FUN_00538a90(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int unaff_retaddr;
  
  iVar2 = *(int *)(param_1 + 0x16ad);
  iVar3 = param_2 + -0x101;
  if (iVar2 < 0xc) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar2 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    iVar2 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16ad) = iVar2 + -0xb;
    *(ushort *)(param_1 + 0x16ab) = (ushort)iVar3 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = *(int *)(param_1 + 0x16ad);
  param_3 = param_3 + -1;
  if (iVar3 < 0xc) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(param_3 << ((byte)iVar3 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar3 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(param_3 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    iVar3 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16ad) = iVar3 + -0xb;
    *(ushort *)(param_1 + 0x16ab) = (ushort)param_3 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar2 = *(int *)(param_1 + 0x16ad);
  iVar3 = param_4 + -4;
  if (iVar2 < 0xd) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar2 + 4;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    iVar2 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x16ad) = iVar2 + -0xc;
    *(ushort *)(param_1 + 0x16ab) = (ushort)iVar3 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar2 = *(int *)(param_1 + 0x16ad);
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x16ab) =
             *(ushort *)(param_1 + 0x16ab) |
             *(short *)(param_1 + 0xa74 + (uint)(byte)(&UNK_005b7dec)[iVar3] * 4) <<
             ((byte)iVar2 & 0x1f);
        *(int *)(param_1 + 0x16ad) = iVar2 + 3;
      }
      else {
        uVar1 = *(ushort *)(param_1 + 0xa74 + (uint)(byte)(&UNK_005b7dec)[iVar3] * 4);
        *(ushort *)(param_1 + 0x16ab) =
             *(ushort *)(param_1 + 0x16ab) | uVar1 << ((byte)iVar2 & 0x1f);
        *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
             *(undefined1 *)(param_1 + 0x16ab);
        iVar2 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar2;
        *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        iVar2 = *(int *)(param_1 + 0x16ad);
        *(int *)(param_1 + 0x16ad) = iVar2 + -0xd;
        *(ushort *)(param_1 + 0x16ab) = uVar1 >> (0x10U - (char)iVar2 & 0x1f);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  func_0x00538ce0(param_2 + -1);
  func_0x00538ce0(unaff_retaddr + -1);
  return;
}

