// Function: FUN_00594478 @ 00594478
// Size (bytes): 177


undefined4 * FUN_00594478(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_008d48f8 == DAT_008d48e8) {
    pvVar2 = HeapReAlloc(DAT_008d4904,0,DAT_008d48fc,(DAT_008d48e8 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_008d48e8 = DAT_008d48e8 + 0x10;
    DAT_008d48fc = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_008d48fc + DAT_008d48f8 * 0x14);
  pvVar2 = HeapAlloc(DAT_008d4904,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_008d48f8 = DAT_008d48f8 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_008d4904,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


