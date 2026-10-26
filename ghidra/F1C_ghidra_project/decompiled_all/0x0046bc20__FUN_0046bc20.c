// Function: FUN_0046bc20 @ 0046bc20
// Strings:  [%d:%06.3f, --:--.---, --:--.---, %s%d:%06.3f]


void __fastcall FUN_0046bc20(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  undefined *puVar15;
  char *pcVar16;
  char *pcVar17;
  float10 fVar18;
  int local_23c;
  char local_228 [48];
  char local_1f8 [47];
  undefined1 local_1c9;
  char local_1c8 [47];
  undefined1 local_199;
  undefined1 local_198 [48];
  char acStack_168 [48];
  char acStack_138 [48];
  char acStack_108 [260];
  
  iVar5 = *(int *)(param_1 + 0x178);
  iVar12 = iVar5 * 0x48c0;
  if (((&DAT_005ef9a0)[iVar5 * 0x1230] == -1) || (*(int *)(&DAT_005f0714 + iVar12) < 1)) {
    *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
  }
  else {
    FUN_00489cb0();
    _strncpy(local_1f8,&DAT_005f0cf8 + iVar12,0x2f);
    local_1c9 = 0;
    _strncpy(local_1c8,(char *)(iVar12 + 0x5f0d90),0x2f);
    local_199 = 0;
    local_23c = *(int *)(&DAT_005f0714 + iVar12);
    if (*(int *)(&DAT_005f0794 + iVar12) <= *(int *)(&DAT_005f0714 + iVar12)) {
      local_23c = *(int *)(&DAT_005f0794 + iVar12);
    }
    iVar8 = 0;
    if (0 < local_23c) {
      do {
        FUN_0058815f(local_228,&DAT_005c3280,
                     (int)*(char *)(iVar8 + *(int *)(&DAT_005f07a0 + iVar12)));
        iVar1 = iVar8 + 1;
        FUN_0058815f(local_198,&DAT_005c3280,iVar1);
        fVar2 = *(float *)(*(int *)(&DAT_005f079c + iVar12) + iVar8 * 4);
        if (fVar2 < DAT_0059e440 == (fVar2 == DAT_0059e440)) {
          fVar18 = (float10)FUN_0058957a();
          uVar7 = __ftol((double)fVar18);
          FUN_0058815f(acStack_168,s__d__06_3f_005c3310,uVar7);
        }
        else {
          iVar6 = 0;
          do {
            cVar4 = (&DAT_005c6a94)[iVar6];
            acStack_168[iVar6] = cVar4;
            iVar6 = iVar6 + 1;
          } while (cVar4 != '\0');
        }
        if ((fVar2 < DAT_0059e440 == (fVar2 == DAT_0059e440)) &&
           ((float)(&DAT_005f0774)[iVar5 * 0x1230] < DAT_0059e440 ==
            ((float)(&DAT_005f0774)[iVar5 * 0x1230] == DAT_0059e440))) {
          fVar3 = (float)(&DAT_005f0774)[iVar5 * 0x1230];
          puVar15 = &DAT_005c6abc;
          if (fVar2 - fVar3 < DAT_0059e440) {
            puVar15 = &DAT_005ea438;
          }
          fVar18 = (float10)FUN_0058957a();
          uVar7 = __ftol((double)fVar18);
          FUN_0058815f(acStack_138,s__s_d__06_3f_005c6ab0,puVar15,uVar7);
          if (fVar2 - fVar3 == DAT_0059e440) {
            *(int *)(param_1 + 0x168) = iVar8;
          }
        }
        else {
          iVar8 = 0;
          do {
            cVar4 = (&DAT_005c6a94)[iVar8];
            acStack_138[iVar8] = cVar4;
            iVar8 = iVar8 + 1;
          } while (cVar4 != '\0');
        }
        iVar6 = 1;
        iVar8 = 0;
        do {
          pcVar13 = local_228 + iVar8;
          acStack_108[iVar8] = *pcVar13;
          iVar8 = iVar8 + 1;
        } while (*pcVar13 != '\0');
        iVar8 = *(int *)(param_1 + 0x17c);
        pcVar13 = local_1f8;
        do {
          if (((iVar8 != 1) || (iVar6 == 1)) || (iVar6 == 4)) {
            iVar9 = -1;
            pcVar14 = acStack_108;
            do {
              pcVar17 = pcVar14;
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              pcVar17 = pcVar14 + 1;
              cVar4 = *pcVar14;
              pcVar14 = pcVar17;
            } while (cVar4 != '\0');
            *(undefined2 *)(pcVar17 + -1) = DAT_005c692c;
            uVar10 = 0xffffffff;
            pcVar14 = pcVar13;
            do {
              pcVar17 = pcVar14;
              if (uVar10 == 0) break;
              uVar10 = uVar10 - 1;
              pcVar17 = pcVar14 + 1;
              cVar4 = *pcVar14;
              pcVar14 = pcVar17;
            } while (cVar4 != '\0');
            uVar10 = ~uVar10;
            iVar9 = -1;
            pcVar14 = acStack_108;
            do {
              pcVar16 = pcVar14;
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              pcVar16 = pcVar14 + 1;
              cVar4 = *pcVar14;
              pcVar14 = pcVar16;
            } while (cVar4 != '\0');
            pcVar14 = pcVar17 + -uVar10;
            pcVar17 = pcVar16 + -1;
            for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar17 = *(undefined4 *)pcVar14;
              pcVar14 = pcVar14 + 4;
              pcVar17 = pcVar17 + 4;
            }
            for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *pcVar17 = *pcVar14;
              pcVar14 = pcVar14 + 1;
              pcVar17 = pcVar17 + 1;
            }
          }
          iVar6 = iVar6 + 1;
          pcVar13 = pcVar13 + 0x30;
        } while (iVar6 < 6);
        FUN_00489600(acStack_108,0,0,0,0);
        iVar8 = iVar1;
        if (local_23c <= iVar1) {
          return;
        }
      } while( true );
    }
  }
  return;
}


