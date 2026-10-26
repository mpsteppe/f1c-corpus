// Function: FUN_004d1670 @ 004d1670
// Size (bytes): 179


void __fastcall FUN_004d1670(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char local_34 [52];
  
  pcVar3 = local_34;
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    do {
      iVar1 = *(int *)((&DAT_007c54f0)[iVar2] + 0x48a4);
      if ((-1 < iVar1) && (iVar1 < 0x34)) {
        local_34[iVar1] = '\x01';
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  iVar2 = 0;
  piVar4 = (int *)(param_1 + 0x280);
  do {
    iVar1 = *piVar4;
    if (local_34[iVar2] == '\0') {
      if (piVar4[-0x34] != 0) {
        FUN_0054c030(1,1,1,0);
      }
      if (iVar1 != 0) {
        uVar6 = 0;
        uVar5 = 0;
        goto LAB_004d170c;
      }
    }
    else {
      if (piVar4[-0x34] != 0) {
        FUN_0054c030(0,0,1,0);
      }
      if (iVar1 != 0) {
        uVar6 = 1;
        uVar5 = 1;
LAB_004d170c:
        FUN_0054c030(uVar5,uVar6,1,0);
      }
    }
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 1;
    if (0x33 < iVar2) {
      return;
    }
  } while( true );
}


