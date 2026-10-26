// Function: FUN_0040c140 @ 0040c140
// Strings:  [default.cfg, default.cfg, default.cfg, default.cfg, cams.cfg]


undefined4 __fastcall FUN_0040c140(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char local_200 [512];
  
  if (*(int *)(param_1 + 0x18) == 0) {
    pvVar2 = operator_new(0x54);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004084b0();
    }
    *(undefined4 *)(param_1 + 0x18) = uVar3;
  }
  FUN_004b0220(local_200,0x200);
  uVar5 = 0xffffffff;
  pcVar4 = PTR_s_cams_cfg_0059e604;
  do {
    pcVar9 = pcVar4;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar9 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar9;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar6 = -1;
  pcVar4 = local_200;
  do {
    pcVar8 = pcVar4;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar8;
  } while (cVar1 != '\0');
  pcVar4 = pcVar9 + -uVar5;
  pcVar9 = pcVar8 + -1;
  for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = (**(code **)(**(int **)(param_1 + 0x18) + 4))(local_200);
  if (iVar6 != 0) {
    pcVar4 = DAT_005ec440;
    if (DAT_005ec440 == (char *)0x0) {
      pcVar4 = &DAT_005ea438;
    }
    iVar6 = -4 - (int)pcVar4;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(local_200 + iVar6)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0xffffffff;
    pcVar4 = s_default_cfg_005be874;
    do {
      pcVar9 = pcVar4;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar9 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar9;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar6 = -1;
    pcVar4 = &stack0xfffffdfc;
    do {
      pcVar8 = pcVar4;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar8 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar8;
    } while (cVar1 != '\0');
    pcVar4 = pcVar9 + -uVar5;
    pcVar9 = pcVar8 + -1;
    for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar6 = (**(code **)(**(int **)(param_1 + 0x18) + 4))(&stack0xfffffdfc);
    if (iVar6 != 0) {
      FUN_0040aa20();
    }
  }
  FUN_0040d100();
  return 0;
}


