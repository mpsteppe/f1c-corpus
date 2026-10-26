// Function: FUN_004d4600 @ 004d4600
// Strings:  [D:\dev\F1_1999_2002\Source\steward.cpp, Entered Steward::Post()]


void __fastcall FUN_004d4600(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0xb27);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_Steward__Post___005d43ac);
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_004482d0();
    iVar4 = *(int *)(param_1 + 0xa8);
    if (iVar4 != 0) {
      FUN_004482d0();
      FUN_00587bcf(iVar4);
    }
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  FUN_004d2e20();
  FUN_004d24d0();
  FUN_0040da30();
  *(undefined4 *)(param_1 + 0x10c) = 0;
  if (*(int *)(param_1 + 0x110) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x110));
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  if (*(int *)(param_1 + 0x114) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x114));
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  if (DAT_007d0410 != 4) {
    FUN_004c2a80();
  }
  if (0 < DAT_005c329c) {
    iVar4 = 0;
    do {
      FUN_004bb950();
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_005c329c);
  }
  if (*(int *)(param_1 + 0x110) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x110));
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  iVar4 = *(int *)(param_1 + 0x1ac);
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  if (iVar4 != 0) {
    local_4 = *(int *)(iVar4 + -4);
    iVar5 = iVar4 + local_4 * 8;
    if (-1 < local_4 + -1) {
      do {
        piVar1 = (int *)(iVar5 + -8);
        iVar5 = iVar5 + -8;
        if (*piVar1 != 0) {
          FUN_00587bcf(*piVar1);
        }
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    FUN_00587bcf(iVar4 + -4);
    *(undefined4 *)(param_1 + 0x1ac) = 0;
  }
  puVar3 = (undefined4 *)(param_1 + 0x280);
  iVar4 = 0x34;
  do {
    puVar3[-0x34] = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


