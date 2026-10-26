// Function: FUN_0044c0e0 @ 0044c0e0
// Size (bytes): 834


/* WARNING: Removing unreachable block (ram,0x0044c3e2) */

void FUN_0044c0e0(undefined4 param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint _Count;
  undefined1 local_614 [20];
  char local_600 [256];
  undefined1 local_500 [256];
  char local_400 [1024];
  
  if (DAT_008b8f24 != 0) {
    FUN_0053ac70(2,0);
  }
  FUN_0044c470();
  FUN_0044c430();
  pcVar7 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar7 = &DAT_005ea438;
  }
  uVar5 = 0xffffffff;
  pcVar8 = pcVar7;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  for (pcVar8 = pcVar7 + (~uVar5 - 1); pcVar7 < pcVar8; pcVar8 = pcVar8 + -1) {
    if (*pcVar8 == '\\') {
      pcVar8 = pcVar8 + 1;
      break;
    }
  }
  pcVar7 = operator_new(0x100);
  *pcVar7 = '\0';
  puVar2 = DAT_005ec438;
  if (DAT_005ec438 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  FUN_005665b0(&DAT_005c44a4);
  FUN_005665b0(pcVar8);
  pcVar8 = pcVar7;
  if (pcVar7 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  uVar5 = 0xffffffff;
  pcVar6 = pcVar8;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  for (pcVar6 = pcVar8 + (~uVar5 - 1); pcVar8 < pcVar6; pcVar6 = pcVar6 + -1) {
    if (*pcVar6 == '.') {
      *pcVar6 = '\0';
      break;
    }
  }
  FUN_005665b0(&DAT_005c449c);
  if (DAT_007cfee8 == '\0') {
    iVar3 = FUN_00449a20();
    iVar4 = FUN_00449a20();
    if (iVar4 < iVar3) {
      pcVar8 = DAT_007ce5d0;
      if (DAT_007ce5d0 == (char *)0x0) {
        pcVar8 = &DAT_005ea438;
      }
      pcVar6 = local_600;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        *pcVar6 = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00589901(local_600);
      iVar4 = FUN_00587c20(local_600,&DAT_005c4494);
      if (iVar4 != 0) {
        pcVar8 = (char *)&DAT_005c448c;
        do {
          cVar1 = *pcVar8;
          pcVar8[iVar4 + -0x5c448c] = cVar1;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        iVar4 = FUN_00449a20();
        if (iVar4 < iVar3) {
          FUN_004ceef0(local_500,0x100);
          iVar4 = FUN_00449a20();
          if (iVar4 < iVar3) {
            pcVar8 = pcVar7;
            if (pcVar7 == (char *)0x0) {
              pcVar8 = &DAT_005ea438;
            }
            iVar3 = FUN_0044be70(pcVar8);
            if (iVar3 == 0) goto LAB_0044c3eb;
            FUN_0044c470();
          }
        }
      }
    }
  }
  pcVar8 = pcVar7;
  if (pcVar7 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  FUN_00566650(pcVar8);
  uVar5 = 0xffffffff;
  pcVar8 = &DAT_005ea438;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar5 - 1)) {
    for (pcVar8 = &DAT_005ea436 + ~uVar5; (&DAT_005ea437 < pcVar8 && (*pcVar8 != '\\'));
        pcVar8 = pcVar8 + -1) {
      *pcVar8 = '\0';
    }
  }
  uVar5 = 0xffffffff;
  _Count = 0;
  pcVar8 = &DAT_005ea438;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar5 - 1)) {
    do {
      if (0x3ff < _Count) break;
      if ((local_400 + _Count)[(int)&DAT_005ea438 - (int)local_400] == '\\') {
        _strncpy(local_400,&DAT_005ea438,_Count);
        local_400[_Count] = '\0';
        FUN_00589671(local_400);
      }
      _Count = _Count + 1;
    } while ((int)_Count < (int)(~uVar5 - 1));
  }
  FUN_00589671(&DAT_005ea438);
  FUN_004492b0();
  FUN_0044bb60(param_1,local_614);
  FUN_0044b910(local_614);
  pcVar8 = pcVar7;
  if (pcVar7 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  FUN_0044bc50(pcVar8,local_614);
  FUN_00449340();
LAB_0044c3eb:
  FUN_0044ba40();
  if (DAT_008b8f24 != 0) {
    FUN_0053ac70(1,0);
  }
  if (pcVar7 != (char *)0x0) {
    FUN_00587bcf(pcVar7);
  }
  return;
}


