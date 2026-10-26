// Function: FUN_00404d50 @ 00404d50
// Size (bytes): 260


void __thiscall FUN_00404d50(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  undefined1 *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  *(char *)(*param_1 + 0x24) = param_2;
  if (param_2 != '\0') {
    iVar7 = *param_1;
    piVar3 = *(int **)(iVar7 + 0x40);
    while (piVar3 != (int *)0x0) {
      piVar1 = (int *)piVar3[1];
      if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
        if (*piVar2 != 0) {
          FUN_00587bcf(*piVar2);
        }
        FUN_00587bcf(piVar2);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar1;
    }
    *(undefined4 *)(iVar7 + 0x40) = 0;
    *(undefined4 *)(iVar7 + 0x44) = 0;
    *(undefined4 *)(iVar7 + 0x48) = 0;
    *(undefined4 *)(iVar7 + 0x4c) = 0;
    FUN_00565dc0();
    puVar5 = DAT_005ec410;
    if (DAT_005ec410 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    FUN_00565f80(&DAT_005be714,1,puVar5,0);
    FUN_00565f50();
    pcVar6 = (char *)FUN_005662d0();
    while (pcVar6 != (char *)0x0) {
      iVar7 = -1;
      pcVar8 = pcVar6;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        cVar4 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar4 != '\0');
      if (iVar7 != -2) {
        FUN_00404e60(pcVar6);
      }
      cVar4 = FUN_00565f20();
      if (cVar4 == '\0') break;
      pcVar6 = (char *)FUN_005662d0();
    }
    FUN_00565e20();
  }
  return;
}


