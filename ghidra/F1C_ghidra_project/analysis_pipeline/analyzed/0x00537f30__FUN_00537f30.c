// Function: FUN_00537f30 @ 00537f30
// Size (bytes): 167


void __thiscall FUN_00537f30(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x16ad);
  if (0xd < iVar1) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(param_3 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x14)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined1 *)(iVar1 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    iVar1 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x16ad) = iVar1 + -0xd;
    *(ushort *)(param_1 + 0x16ab) = (ushort)param_3 >> (0x10U - (char)iVar1 & 0x1f);
    FUN_005397a0(param_2,1);
    return;
  }
  *(int *)(param_1 + 0x16ad) = iVar1 + 3;
  *(ushort *)(param_1 + 0x16ab) =
       *(ushort *)(param_1 + 0x16ab) | (ushort)(param_3 << ((byte)iVar1 & 0x1f));
  FUN_005397a0(param_2,1);
  return;
}


