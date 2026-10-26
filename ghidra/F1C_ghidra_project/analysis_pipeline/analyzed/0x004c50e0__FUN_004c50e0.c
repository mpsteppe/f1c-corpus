// Function: FUN_004c50e0 @ 004c50e0
// Size (bytes): 76


undefined4 FUN_004c50e0(int param_1)

{
  undefined4 *puVar1;
  int extraout_ECX;
  int extraout_EDX;
  int iVar2;
  undefined8 uVar3;
  
  if (-1 < param_1) {
    uVar3 = FUN_005871f0();
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    if (iVar2 < (int)uVar3) {
      FUN_004c6760(iVar2);
      if (extraout_EDX < *(int *)(extraout_ECX + 0x14)) {
        puVar1 = *(undefined4 **)(extraout_ECX + 8);
        for (iVar2 = extraout_EDX; 0 < iVar2; iVar2 = iVar2 + -1) {
          if (puVar1 == (undefined4 *)0x0) {
            return uRam00000000;
          }
          puVar1 = (undefined4 *)puVar1[1];
        }
        if (puVar1 != (undefined4 *)0x0) {
          return *(undefined4 *)*puVar1;
        }
      }
      return uRam00000000;
    }
  }
  return 0;
}


