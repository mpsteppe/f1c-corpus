// Function: FUN_0040c3b0 @ 0040c3b0
// Size (bytes): 358


undefined4 __fastcall FUN_0040c3b0(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char local_240 [62];
  char acStack_202 [514];
  
  if (*(int *)(param_1 + 0x20) == 0) {
    pvVar2 = operator_new(0x18);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0040b560();
    }
    *(undefined4 *)(param_1 + 0x20) = uVar3;
  }
  iVar4 = DAT_008ac48c * 0x18c + DAT_008ac490;
  if (iVar4 != 0) {
    pcVar6 = (char *)(iVar4 + 4);
    pcVar5 = pcVar6;
    do {
      cVar1 = *pcVar5;
      pcVar5[(int)(acStack_202 + (2 - (int)pcVar6))] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar7 = 0xffffffff;
    pcVar5 = acStack_202 + 2;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if ((0 < (int)(~uVar7 - 1)) && (pcVar5 = acStack_202 + ~uVar7, acStack_202 + 2 <= pcVar5)) {
      do {
        if (*pcVar5 == '\\') break;
        *pcVar5 = '\0';
        pcVar5 = pcVar5 + -1;
      } while (acStack_202 + 2 <= pcVar5);
    }
    uVar7 = 0xffffffff;
    pcVar5 = pcVar6;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    for (pcVar5 = pcVar6 + (~uVar7 - 1); pcVar6 < pcVar5; pcVar5 = pcVar5 + -1) {
      if (*pcVar5 == '\\') {
        pcVar5 = pcVar5 + 1;
        break;
      }
    }
    iVar4 = -(int)pcVar5;
    do {
      cVar1 = *pcVar5;
      pcVar5[(int)(local_240 + iVar4)] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar7 = 0xffffffff;
    pcVar6 = local_240;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar6 = local_240 + (~uVar7 - 1);
    if (local_240 < pcVar6) {
      do {
        if (*pcVar6 == '.') {
          *pcVar6 = '\0';
          break;
        }
        pcVar6 = pcVar6 + -1;
      } while (local_240 < pcVar6);
    }
    uVar7 = 0xffffffff;
    pcVar6 = &DAT_005be880;
    do {
      pcVar5 = pcVar6;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar5 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar5;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    iVar4 = -1;
    pcVar6 = local_240;
    do {
      pcVar9 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    pcVar6 = pcVar5 + -uVar7;
    pcVar5 = pcVar9 + -1;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar5 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
    }
    uVar7 = 0xffffffff;
    pcVar6 = local_240;
    do {
      pcVar5 = pcVar6;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar5 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar5;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    iVar4 = -1;
    pcVar6 = acStack_202 + 2;
    do {
      pcVar9 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    pcVar6 = pcVar5 + -uVar7;
    pcVar5 = pcVar9 + -1;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar5 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
    }
    (**(code **)(**(int **)(param_1 + 0x20) + 4))(acStack_202 + 2);
  }
  return 0;
}


