// Function: FUN_00411ab0 @ 00411ab0
// Size (bytes): 158


undefined4 __fastcall FUN_00411ab0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  bool bVar5;
  
  iVar1 = 0;
  do {
    *(undefined2 *)(param_1 + iVar1 * 4) = 1;
    *(undefined2 *)(param_1 + 2 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x219);
  iVar1 = 0;
  do {
    if (iVar1 < 0x125) {
      if (iVar1 < 0x123) {
        bVar5 = iVar1 == 0;
        goto LAB_00411aea;
      }
    }
    else {
      bVar5 = iVar1 == 0x218;
LAB_00411aea:
      if (!bVar5) {
        iVar2 = FUN_004144c0();
        if (-1 < iVar2) {
          if ((iVar1 < 1) || (0x122 < iVar1)) {
            if ((iVar1 < 0x125) || (0x217 < iVar1)) goto LAB_00411b3f;
            puVar4 = &DAT_005bf2f8;
          }
          else {
            puVar4 = &DAT_005bebb0;
          }
          iVar2 = (uint)*(ushort *)(puVar4 + iVar2 * 2 + 2) - (uint)*(ushort *)(puVar4 + iVar2 * 2);
          if (0 < iVar2) {
            iVar3 = _rand();
            *(short *)(param_1 + iVar1 * 4) = (short)iVar2;
            *(short *)(param_1 + 2 + iVar1 * 4) = (short)(iVar3 % iVar2);
          }
        }
      }
    }
LAB_00411b3f:
    iVar1 = iVar1 + 1;
    if (0x218 < iVar1) {
      return 0;
    }
  } while( true );
}


