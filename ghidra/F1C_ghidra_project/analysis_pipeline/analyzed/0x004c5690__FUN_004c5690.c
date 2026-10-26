// Function: FUN_004c5690 @ 004c5690
// Size (bytes): 408


void FUN_004c5690(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  char local_a0;
  undefined4 local_9f;
  char local_51 [2];
  undefined4 local_4f;
  
  local_51[1] = DAT_005ea438;
  puVar8 = &local_4f;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  uVar3 = 0xffffffff;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  pcVar4 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  for (pcVar4 = param_1 + (~uVar3 - 1); param_1 < pcVar4; pcVar4 = pcVar4 + -1) {
    if (*pcVar4 == '\\') {
      pcVar4 = pcVar4 + 1;
      break;
    }
  }
  iVar2 = 1 - (int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(local_51 + iVar2)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = local_51;
  uVar3 = 0xffffffff;
  do {
    pcVar4 = pcVar4 + 1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
  } while (*pcVar4 != '\0');
  pcVar4 = local_51 + ~uVar3;
  if (local_51 + 1 < pcVar4) {
    do {
      if (*pcVar4 == '.') {
        *pcVar4 = '\0';
        break;
      }
      pcVar4 = pcVar4 + -1;
    } while (local_51 + 1 < pcVar4);
  }
  iVar2 = 0;
  if (DAT_008ac488 < 1) {
    return;
  }
  iVar7 = 0;
  do {
    local_a0 = DAT_005ea438;
    pcVar4 = (char *)(iVar7 + 4 + DAT_008ac490);
    puVar8 = &local_9f;
    for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    *(undefined2 *)puVar8 = 0;
    uVar3 = 0xffffffff;
    *(undefined1 *)((int)puVar8 + 2) = 0;
    pcVar6 = pcVar4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    for (pcVar6 = pcVar4 + (~uVar3 - 1); pcVar4 < pcVar6; pcVar6 = pcVar6 + -1) {
      if (*pcVar6 == '\\') {
        pcVar6 = pcVar6 + 1;
        break;
      }
    }
    iVar5 = -(int)pcVar6;
    do {
      cVar1 = *pcVar6;
      pcVar6[(int)(&local_a0 + iVar5)] = cVar1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar3 = 0xffffffff;
    pcVar4 = &local_a0;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = &stack0xffffff5f + ~uVar3;
    if (&local_a0 < pcVar4) {
      do {
        if (*pcVar4 == '.') {
          *pcVar4 = '\0';
          break;
        }
        pcVar4 = pcVar4 + -1;
      } while (&local_a0 < pcVar4);
    }
    iVar5 = -1;
    pcVar4 = &local_a0;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar5 != -2) {
      uVar3 = 0xffffffff;
      pcVar4 = &local_a0;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      iVar5 = FUN_00596c80(local_51 + 1,&local_a0,~uVar3 - 1);
      if (iVar5 == 0) {
        DAT_008ac48c = iVar2;
        return;
      }
    }
    iVar2 = iVar2 + 1;
    iVar7 = iVar7 + 0x18c;
    if (DAT_008ac488 <= iVar2) {
      return;
    }
  } while( true );
}


