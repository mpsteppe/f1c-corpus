// Function: FUN_0046cb50 @ 0046cb50
// Strings:  [PlayerNameNeverUsed, PROFILE EXISTS PAGE, Profile already exists, Profile already exists]


undefined4 __fastcall FUN_0046cb50(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  uVar8 = 0xffffffff;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(3);
  if (iVar2 != 0) {
    iVar7 = -1;
    pcVar9 = &DAT_007cd818;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if (iVar7 != -2) {
      cVar1 = FUN_00469550(&DAT_007cd818);
      if (cVar1 != '\0') {
        if (DAT_007d2e41 != '\0') {
          puVar3 = DAT_005ec440;
          if (DAT_005ec440 == (undefined1 *)0x0) {
            puVar3 = &DAT_005ea438;
          }
          FUN_0058815f(&DAT_007cd718,&DAT_005be860,puVar3,s_PlayerNameNeverUsed_005c6970);
          FUN_00499690();
          DAT_007d2e41 = '\0';
        }
        FUN_00568560();
        pvVar4 = operator_new(0x49b4);
        if (pvVar4 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_004a70e0();
        }
        iVar5 = FUN_004b09a0(&DAT_007cd818);
        if (iVar5 != -1) {
          FUN_004692a0(&DAT_007cd818,1);
          uVar8 = 0;
        }
        if (iVar7 != 0) {
          FUN_004a8b80();
          FUN_00587bcf(iVar7);
        }
        if (0 < *(int *)(iVar2 + 0x450)) {
          FUN_004b0770(0);
        }
        FUN_004b03f0();
        FUN_004a0ad0();
        goto LAB_0046ccb0;
      }
    }
    iVar2 = FUN_00423a00(s_Profile_already_exists_005c6b38,&DAT_005ec4cc);
    if (iVar2 != 0) {
      iVar2 = 0;
      do {
        pcVar9 = s_Profile_already_exists_005c6b38 + iVar2;
        (&DAT_005ec4cc)[iVar2] = *pcVar9;
        iVar2 = iVar2 + 1;
      } while (*pcVar9 != '\0');
    }
    (**(code **)(**(int **)(param_1 + 0x40) + 4))(&DAT_005ec4cc);
    FUN_00497940(s_PROFILE_EXISTS_PAGE_005c6b24,0xffffffff);
    uVar8 = 0xffffffff;
  }
LAB_0046ccb0:
  piVar6 = (int *)(**(code **)(*DAT_007cd8c0 + 0x1c))(3);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0xa0))();
  }
  piVar6 = (int *)(**(code **)(*DAT_007cd8c0 + 0x1c))(0x2d);
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x38))(1);
  }
  return uVar8;
}


