// Function: FUN_00563870 @ 00563870
// Size (bytes): 447


int __fastcall FUN_00563870(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char local_40 [64];
  
  iVar1 = *(int *)(param_1 + 0x5b4);
  if (iVar1 == 0) {
    iVar1 = FUN_00563a70(3);
    if (iVar1 == -1) {
      return 0;
    }
    if (iVar1 < 0xc) {
      return -1;
    }
    _strncpy(local_40,(char *)(param_2 + 0xc),iVar1 - 0xc);
    local_40[iVar1 + -0xd] = '\0';
    DAT_008cfa88 = FUN_00587f59(local_40);
    if (DAT_008cfa88 < 0x15) {
      *(undefined4 *)(param_1 + 0x5b4) = 1;
      if (0 < DAT_008cfa88) {
        puVar5 = &DAT_008cfa90;
        for (iVar3 = DAT_008cfa88; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
      }
LAB_00563a23:
      return iVar1 + -1;
    }
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_00563a70(2);
    if (iVar1 == -1) {
      return 0;
    }
    _strncpy(local_40,(char *)(param_2 + 1),iVar1 - 2);
    local_40[iVar1 + -2] = '\0';
    uVar2 = FUN_00564690();
    FUN_00564780();
    iVar3 = 0;
    if (0 < DAT_008cfa88) {
      while ((&DAT_008cfa90)[iVar3] != 0) {
        iVar3 = iVar3 + 1;
        if (DAT_008cfa88 <= iVar3) {
          return -1;
        }
      }
      iVar4 = DAT_008cfa88 + -1;
      (&DAT_008cfa90)[iVar3] = uVar2;
      if (iVar3 == iVar4) {
        *(undefined4 *)(param_1 + 0x5b4) = 2;
        return iVar1 + -1;
      }
      goto LAB_00563a23;
    }
  }
  else if (iVar1 == 2) {
    iVar1 = FUN_00563a70(DAT_008cfa88 + 1);
    if (iVar1 == -1) {
      return 0;
    }
    uVar2 = FUN_00563a30(DAT_008cfa88,param_2,*(undefined4 *)(param_1 + 0x90));
    *(undefined1 *)(param_2 + -1 + iVar1) = 0x5c;
    (**(code **)(param_1 + 0x78))(param_1,2,*(undefined4 *)(param_1 + 0x7c),uVar2,0);
    return iVar1 + -1;
  }
  return -1;
}


