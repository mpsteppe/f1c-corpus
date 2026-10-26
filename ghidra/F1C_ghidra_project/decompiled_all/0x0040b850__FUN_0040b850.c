// Function: FUN_0040b850 @ 0040b850
// Strings:  [MAINVIEW, TRACKINGCAM]


undefined4 FUN_0040b850(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  FUN_005881c0();
  FUN_005668b0();
  puVar6 = (undefined4 *)&stack0x000001b8;
  for (iVar4 = 0x60; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar4 = 0x80;
  do {
    FUN_004583b0();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar5 = 0;
  iVar4 = FUN_00544f50();
  if (iVar4 != 0) {
    *(int *)(extraout_ECX + 4) = iVar4;
  }
  cVar1 = FUN_00566b20();
  if (cVar1 == '\0') {
    iVar4 = 0x80;
    do {
      FUN_004584a0();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    iVar4 = FUN_00566cc0();
    if (iVar4 != 0) {
      do {
        iVar4 = FUN_005651b0();
        if (((iVar4 == 0) && (iVar4 = FUN_00565520(), iVar4 != 0)) && (iVar5 < 0x80)) {
          FUN_004585e0();
          iVar5 = iVar5 + 1;
        }
        iVar4 = FUN_00566cc0();
      } while (iVar4 != 0);
      if (0 < iVar5) {
        piVar2 = operator_new(iVar5 * 0xd0 + 4);
        if (piVar2 == (int *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = piVar2 + 1;
          *piVar2 = iVar5;
          iVar4 = iVar5;
          if (-1 < iVar5 + -1) {
            do {
              FUN_004583b0();
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        iVar4 = 0;
        *(int **)(extraout_ECX + 0xc) = piVar3;
        *(int *)(extraout_ECX + 0x10) = iVar5;
        *(undefined4 *)(extraout_ECX + 0x14) = 0;
        if (0 < iVar5) {
          do {
            FUN_00459330();
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(int *)(extraout_ECX + 0x10));
        }
        iVar4 = 0x80;
        do {
          FUN_004584a0();
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        FUN_005668d0();
        return 0;
      }
    }
    iVar4 = 0x80;
    do {
      FUN_004584a0();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_005668d0();
  return 1;
}


