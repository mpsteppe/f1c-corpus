// Function: FUN_00418e50 @ 00418e50
// Size (bytes): 133


void __fastcall FUN_00418e50(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    iVar2 = 0;
    puVar1 = (undefined4 *)(param_1 + 0x350);
    do {
      puVar1[-0xd4] = 0xffffffff;
      puVar1[-0x68] = 0x7fffffff;
      *puVar1 = 0;
      puVar1[0x6b] = 0xbf800000;
      puVar1[0xd3] = 0;
      puVar1[0x13b] = 0;
      *(undefined1 *)(param_1 + 0x9dc + iVar2) = 0;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < 0x68);
    FUN_00418ee0();
    *(undefined4 *)(param_1 + 0x4f0) = 0;
    *(undefined4 *)(param_1 + 0x4f4) = 0;
    *(undefined4 *)(param_1 + 0x4f8) = 0;
  }
  return;
}


