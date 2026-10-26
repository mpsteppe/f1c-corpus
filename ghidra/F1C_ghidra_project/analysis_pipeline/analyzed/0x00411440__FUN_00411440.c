// Function: FUN_00411440 @ 00411440
// Size (bytes): 290


void __thiscall FUN_00411440(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_008ab6e4 != 2) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x48)) {
      piVar2 = (int *)(*(int *)(param_1 + 0x50) + 0xd0);
      do {
        if (param_2 == *piVar2) {
          if (*(int *)(*(int *)(param_1 + 0x4c) + iVar1 * 0x24) != -1) {
            FUN_00410af0(*(int *)(param_1 + 0x4c) + iVar1 * 0x24);
            FUN_004bdf90();
            return;
          }
          goto LAB_00411535;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0xca;
      } while (iVar1 < *(int *)(param_1 + 0x48));
    }
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x54)) {
      piVar2 = (int *)(*(int *)(param_1 + 0x5c) + 0xd0);
      do {
        if (param_2 == *piVar2) {
          if (*(int *)(*(int *)(param_1 + 0x58) + iVar1 * 0x24) != -1) {
            FUN_00410af0(*(int *)(param_1 + 0x58) + iVar1 * 0x24);
            FUN_004bdf90();
            return;
          }
          goto LAB_00411535;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0xc6;
      } while (iVar1 < *(int *)(param_1 + 0x54));
    }
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x60)) {
      piVar2 = (int *)(*(int *)(param_1 + 0x68) + 0xd0);
      do {
        if (param_2 == *piVar2) {
          piVar2 = (int *)(*(int *)(param_1 + 100) + iVar1 * 0x24);
          if (*piVar2 != -1) {
            FUN_00410af0(piVar2);
            FUN_004bdf90();
            return;
          }
LAB_00411535:
          FUN_004be180();
          return;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0xc6;
      } while (iVar1 < *(int *)(param_1 + 0x60));
    }
  }
  return;
}


