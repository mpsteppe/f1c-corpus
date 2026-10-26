// Function: FUN_00496e90 @ 00496e90
// Strings:  [No draw stack available]


undefined4 __thiscall FUN_00496e90(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  float10 fVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int local_c;
  int local_8;
  int local_4;
  
  iVar8 = param_2;
  *(undefined4 *)(param_1 + 0x38) = 1;
  cVar1 = FUN_00496030(param_2);
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar2 = FUN_00495150();
      FUN_00494bf0(iVar2,0,0,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20),0xa0402);
      iVar2 = -1;
      pcVar7 = (char *)(param_1 + 0x166c);
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (iVar2 != -2) {
        uVar12 = 1;
        uVar3 = FUN_00495150(1);
        FUN_00494f10((char *)(param_1 + 0x166c),s_No_draw_stack_available_005cca30,0,0,uVar3,uVar12)
        ;
      }
      FUN_00497100(iVar8);
      return 0xffffffff;
    }
    uVar3 = FUN_00498e40();
    *(undefined4 *)(param_1 + 0x34) = uVar3;
    if (DAT_005cc9e8 != 5) {
      return 0xffffffff;
    }
    cVar1 = FUN_00497240();
    if (((cVar1 != '\0') || (DAT_007ce03c != 0)) || (0 < (int)DAT_005cc9e4)) {
      uVar13 = 600;
      uVar11 = 800;
      uVar12 = 0;
      uVar3 = 0;
      DAT_005cc9e4 = ((int)(DAT_005cc9e4 - 1) < 1) - 1 & DAT_005cc9e4 - 1;
      FUN_00490920(0,0,800,600);
      FUN_004918d0(uVar3,uVar12,uVar11,uVar13);
      FUN_00497250(0);
    }
    if (*(char *)(param_1 + 0x24) == '\0') {
      FUN_00490920();
      FUN_00491bd0();
      piVar6 = *(int **)(param_1 + 0x18);
      iVar8 = 0;
      do {
        if (piVar6[0x1a] == 0) break;
        (**(code **)(*piVar6 + 8))(&local_4,&local_8,&local_c,&param_2);
        iVar5 = local_8 - local_4;
        iVar4 = param_2 - local_c;
        iVar2 = local_c;
        iVar10 = local_4;
        FUN_00490920(local_c,local_4,iVar4,iVar5);
        FUN_004919c0(iVar2,iVar10,iVar4,iVar5);
        piVar6 = (int *)piVar6[0x1a];
        iVar8 = iVar8 + 1;
      } while (iVar8 < 8);
      while (piVar6 != (int *)0x0) {
        FUN_00490920();
        FUN_00491ad0();
        (**(code **)(*piVar6 + 0x34))();
        piVar6 = (int *)piVar6[0x19];
        FUN_00490920();
        FUN_00491a40();
      }
      FUN_00495b60();
      FUN_00495bd0();
      FUN_004973d0();
      FUN_00495580();
    }
    *(undefined4 *)(param_1 + 0x38) = 2;
    if (DAT_0059e440 < *(float *)(param_1 + 0x44)) {
      pcVar7 = *(char **)(param_1 + 0x3c);
      if (pcVar7 == (char *)0x0) {
        pcVar7 = &DAT_005ea438;
      }
      iVar8 = FUN_00423a00(pcVar7,&DAT_005ec4cc);
      if (iVar8 != 0) {
        if (pcVar7 == (char *)0x0) {
          DAT_005ec4cc = 0;
        }
        else {
          iVar8 = (int)&DAT_005ec4cc - (int)pcVar7;
          do {
            cVar1 = *pcVar7;
            pcVar7[iVar8] = cVar1;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
        }
      }
      FUN_004989e0(&DAT_005ec4cc);
      fVar9 = (float10)FUN_00498730();
      *(float *)(param_1 + 0x44) = (float)((float10)*(float *)(param_1 + 0x44) - fVar9);
    }
    FUN_00497100(1);
    *(undefined1 *)(param_1 + 0x24) = 0;
  }
  return 0;
}


