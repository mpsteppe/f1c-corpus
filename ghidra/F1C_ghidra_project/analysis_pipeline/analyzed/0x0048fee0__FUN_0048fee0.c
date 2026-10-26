// Function: FUN_0048fee0 @ 0048fee0
// Size (bytes): 448


undefined4 __thiscall FUN_0048fee0(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int local_c;
  int local_8;
  int local_4;
  
  pcVar2 = *(char **)(param_1 + 0xb0);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar7 = -1;
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar7 != -2) {
    local_c = 0;
    local_8 = 0;
    iVar7 = FUN_00487060(2);
    iVar3 = FUN_00487060(3);
    iVar4 = FUN_004870e0(2);
    local_4 = FUN_004870e0(3);
    iVar5 = FUN_004862c0();
    if (iVar5 != 0) {
      FUN_00498560(iVar5);
    }
    puVar6 = *(undefined1 **)(param_1 + 0xb0);
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    FUN_004983b0(puVar6,&local_c,&local_8,1);
    iVar5 = *param_2;
    if (iVar4 <= *param_2) {
      iVar5 = iVar4;
    }
    *param_2 = iVar5;
    iVar5 = *param_3;
    if (*param_3 <= local_4) {
      iVar5 = local_4;
    }
    *param_3 = iVar5;
    iVar5 = *(int *)(param_1 + 0xe4);
    if (iVar5 != 0) {
      if (iVar5 == 1) {
        puVar6 = *(undefined1 **)(param_1 + 0xb0);
        if (puVar6 == (undefined1 *)0x0) {
          puVar6 = &DAT_005ea438;
        }
        FUN_004980d0(puVar6,iVar4,iVar4 + local_8,iVar7,iVar3,1);
        iVar4 = *param_4;
        if (iVar7 <= *param_4) {
          iVar4 = iVar7;
        }
        *param_4 = iVar4;
      }
      else {
        if (iVar5 != 2) {
          return 0;
        }
        puVar6 = *(undefined1 **)(param_1 + 0xb0);
        if (puVar6 == (undefined1 *)0x0) {
          puVar6 = &DAT_005ea438;
        }
        FUN_004981f0(puVar6,iVar4,iVar4 + local_8,iVar3 - local_c,iVar3,1);
        iVar7 = iVar3 - local_c;
        if (*param_4 < iVar3 - local_c) {
          iVar7 = *param_4;
        }
        *param_4 = iVar7;
      }
      iVar7 = *param_5;
      if (*param_5 <= iVar3) {
        iVar7 = iVar3;
      }
      *param_5 = iVar7;
      return 0;
    }
    puVar6 = *(undefined1 **)(param_1 + 0xb0);
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    FUN_004981f0(puVar6,iVar4,iVar4 + local_8,iVar7,iVar7 + local_c,1);
    iVar3 = *param_4;
    if (iVar7 <= *param_4) {
      iVar3 = iVar7;
    }
    *param_4 = iVar3;
    iVar3 = iVar7 + local_c;
    if (iVar7 + local_c < *param_5) {
      iVar3 = *param_5;
    }
    *param_5 = iVar3;
  }
  return 0;
}


