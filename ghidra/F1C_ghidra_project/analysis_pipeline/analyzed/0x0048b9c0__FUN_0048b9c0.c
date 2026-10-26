
undefined4 __thiscall
FUN_0048b9c0(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_104 [4];
  char cStack_100;
  undefined4 uStack_ff;
  undefined1 uStack_2;
  
  iVar10 = 0;
  if (param_1[0x32] != 0) {
    puVar2 = *(undefined1 **)(param_1[0x32] + 0x40);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00498560(puVar2);
  }
  FUN_004983b0(&DAT_005cc218,&iStack_10c,auStack_104,1);
  piVar3 = (int *)FUN_00486460(0);
  if (piVar3 != (int *)0x0) {
    iVar7 = param_1[1];
    iVar5 = param_1[3];
    uVar15 = 0;
    uVar14 = 0;
    iVar8 = piVar3[3] - piVar3[2];
    iVar9 = piVar3[1] - *piVar3;
    uVar4 = FUN_00495150(iVar5,iVar7,iVar9,iVar8,0,0);
    FUN_00494a30(*(undefined4 *)(piVar3[8] + 0xc),*piVar3,piVar3[2],uVar4,iVar5,iVar7,iVar9,iVar8,
                 uVar14,uVar15);
  }
  pcVar11 = (char *)param_1[0xbc];
  cStack_100 = DAT_005ea438;
  puVar12 = &uStack_ff;
  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(undefined2 *)puVar12 = 0;
  *(undefined1 *)((int)puVar12 + 2) = 0;
  if (*(char *)((int)param_1 + 0xe2) == '\0') {
    _strncpy(&cStack_100,pcVar11,0xff);
  }
  else {
    iVar7 = 0;
    do {
      pcVar13 = &cStack_100 + iVar7;
      if (pcVar13[(int)pcVar11 - (int)&cStack_100] == '\0') break;
      iVar7 = iVar7 + 1;
      *pcVar13 = '*';
    } while (iVar7 < 0x100);
  }
  uStack_2 = 0;
  if (((char)param_1[0x38] != '\0') && (*(char *)((int)param_1 + 0xe1) != '\0')) {
    iVar7 = -1;
    pcVar11 = &cStack_100;
    do {
      pcVar13 = pcVar11;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar13 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar13;
    } while (cVar1 != '\0');
    *(undefined2 *)(pcVar13 + -1) = DAT_005cc214;
  }
  uStack_108 = 0;
  iStack_10c = 0;
  pcVar11 = &cStack_100;
  FUN_004983b0(&cStack_100,&iStack_10c,&uStack_108,1);
  iVar7 = (**(code **)(*param_1 + 0x20))();
  iVar5 = (**(code **)(*param_1 + 0x18))();
  for (; (iVar7 - iVar5 < iStack_10c && (iVar10 < 0xff)); iVar10 = iVar10 + 1) {
    pcVar11 = pcVar11 + 1;
    FUN_004983b0(pcVar11,&iStack_10c,&uStack_108,1);
  }
  iVar10 = -1;
  pcVar13 = pcVar11;
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  if (iVar10 != -2) {
    uVar16 = 1;
    uVar4 = (**(code **)(*param_1 + 0x20))(1);
    uVar14 = (**(code **)(*param_1 + 0x18))(uVar4);
    uVar15 = (**(code **)(*param_1 + 0x24))(uVar14);
    uVar6 = (**(code **)(*param_1 + 0x1c))(uVar15);
    FUN_004981f0(pcVar11,uVar6,uVar15,uVar14,uVar4,uVar16);
    uVar4 = (**(code **)(*param_1 + 0x1c))();
    *param_2 = uVar4;
    uVar4 = (**(code **)(*param_1 + 0x24))();
    *param_3 = uVar4;
    uVar4 = (**(code **)(*param_1 + 0x18))();
    *param_4 = uVar4;
    uVar4 = (**(code **)(*param_1 + 0x20))();
    *param_5 = uVar4;
  }
  (**(code **)(*param_1 + 0x2c))(0);
  return 0;
}

