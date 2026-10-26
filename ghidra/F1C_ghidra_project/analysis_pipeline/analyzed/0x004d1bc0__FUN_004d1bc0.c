// Function: FUN_004d1bc0 @ 004d1bc0
// Size (bytes): 115


int __thiscall FUN_004d1bc0(undefined4 param_1,byte param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_4;
  
  bVar2 = param_2;
  iVar1 = DAT_005c329c;
  if (DAT_007c56a4 != 7) {
    iVar5 = 0;
    iVar4 = 1;
    uStack_4 = param_1;
    if (0 < DAT_005c329c) {
      do {
        uStack_4 = CONCAT13(*(byte *)((&DAT_007c54f0)[iVar5] + 0x4894),(undefined3)uStack_4);
        if ((*(byte *)((&DAT_007c54f0)[iVar5] + 0x4894) != bVar2) &&
           (iVar3 = FUN_004d0c20((int)&uStack_4 + 3,&param_2), iVar3 < 0)) {
          iVar4 = iVar4 + 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    return iVar4;
  }
  return (&DAT_005f0738)[(uint)param_2 * 0x1230];
}


