// Function: FUN_004c01a0 @ 004c01a0
// Size (bytes): 190


void FUN_004c01a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_1a4;
  int local_1a0 [104];
  
  piVar7 = local_1a0;
  for (iVar3 = 0x68; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = -1;
    piVar7 = piVar7 + 1;
  }
  iVar3 = 0;
  iVar5 = 1;
  if (0 < DAT_005c329c) {
    do {
      piVar7 = &DAT_007c54f0 + iVar3;
      iVar3 = iVar3 + 1;
      local_1a0[*(int *)(*piVar7 + 0x4894)] = *(int *)(*piVar7 + 0x4710);
    } while (iVar3 < DAT_005c329c);
  }
  local_1a4 = 0;
  iVar3 = DAT_005c329c;
  if (0 < DAT_005c329c) {
    do {
      iVar6 = -1;
      iVar4 = 999;
      iVar2 = 0;
      do {
        iVar1 = local_1a0[iVar2];
        if ((iVar1 != -1) && (iVar1 < iVar4)) {
          iVar4 = iVar1;
          iVar6 = iVar2;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x68);
      if ((iVar4 != 999) && (iVar6 != -1)) {
        FUN_004bc2f0(iVar5);
        local_1a0[iVar6] = -1;
        iVar5 = iVar5 + 1;
        iVar3 = DAT_005c329c;
      }
      local_1a4 = local_1a4 + 1;
    } while (local_1a4 < iVar3);
  }
  return;
}


