// Function: FUN_00553070 @ 00553070
// Size (bytes): 379


void __thiscall
FUN_00553070(int param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  
  if (*param_2 != '\0') {
    uVar3 = 0xffffffff;
    pcVar5 = param_2;
    if ((*(uint *)(param_1 + 0x24) & 0x20000) == 0) {
      uVar4 = 0;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (uVar3 != 0xfffffffe) {
        do {
          iVar8 = FUN_00552910(param_2[uVar4],param_3,param_4,param_5);
          param_3 = param_3 + iVar8;
          uVar3 = 0xffffffff;
          uVar4 = uVar4 + 1;
          pcVar5 = param_2;
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
        } while (uVar4 < ~uVar3 - 1);
      }
    }
    else {
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar8 = *(int *)(param_1 + 8);
      iVar2 = (~uVar3 - 1) * 6;
      if (iVar2 - (0x300 - iVar8) == 0 || iVar2 < 0x300 - iVar8) {
        uVar6 = *(undefined4 *)(param_1 + 0xc);
        uVar7 = 0x20;
      }
      else {
        uVar6 = *(undefined4 *)(param_1 + 0xc);
        iVar8 = 0;
        uVar7 = 0x60;
        *(undefined4 *)(param_1 + 8) = 0;
      }
      iVar8 = FUN_00540f00(uVar6,uVar7,iVar8,iVar2);
      *(int *)(param_1 + 0x10) = iVar8;
      if (iVar8 != 0) {
        uVar6 = *(undefined4 *)(param_1 + 8);
        iVar8 = -1;
        uVar3 = 0;
        pcVar5 = param_2;
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        if (iVar8 != -2) {
          do {
            iVar8 = FUN_00552910(param_2[uVar3],param_3,param_4,param_5);
            param_3 = param_3 + iVar8;
            uVar4 = 0xffffffff;
            uVar3 = uVar3 + 1;
            pcVar5 = param_2;
            do {
              if (uVar4 == 0) break;
              uVar4 = uVar4 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
          } while (uVar3 < ~uVar4 - 1);
        }
        FUN_00540f90(*(undefined4 *)(param_1 + 0xc));
        if (DAT_008b8df0 == 0) {
          FUN_005550a0();
        }
        FUN_00541120(DAT_008b8f28,*(undefined4 *)(param_1 + 0xc),uVar6,iVar2,
                     *(undefined4 *)(param_1 + 0x868),*(undefined4 *)(param_1 + 0x4c),
                     *(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x58),0);
        if (DAT_008b8df0 == 0) {
          FUN_005550c0();
          return;
        }
      }
    }
  }
  return;
}


