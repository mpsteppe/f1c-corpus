// Function: FUN_0046c210 @ 0046c210
// Strings:  [%s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s]


void FUN_0046c210(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char local_248 [4];
  undefined4 *local_244;
  char local_240 [64];
  char local_200 [256];
  char local_100;
  undefined4 local_ff;
  char local_80;
  undefined4 local_7f;
  
  local_248[1] = '\0';
  local_248[2] = '\0';
  local_248[3] = 0;
  local_248[0] = DAT_005ea438;
  FUN_00489cb0();
  iVar2 = FUN_004c2760();
  if (iVar2 == 2) {
    iVar2 = FUN_004c2850();
    if (iVar2 != 0) {
      FUN_004c2850();
      iVar2 = FUN_004c1390();
      if (iVar2 != 0) {
        iVar2 = FUN_004c29d0();
        if (iVar2 != 0) {
          FUN_004c2850();
          iVar2 = FUN_004c1390();
          local_244 = (undefined4 *)FUN_004c29d0();
          local_80 = DAT_005ea438;
          puVar9 = &local_7f;
          for (iVar7 = 0x1f; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
          *(undefined2 *)puVar9 = 0;
          *(undefined1 *)((int)puVar9 + 2) = 0;
          local_100 = DAT_005ea438;
          puVar9 = &local_ff;
          for (iVar7 = 0x1f; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
          *(undefined2 *)puVar9 = 0;
          *(undefined1 *)((int)puVar9 + 2) = 0;
          FUN_004c0a20(&local_80,0x80);
          FUN_004894d0(local_248);
          FUN_004b0b20(local_240,0x3f);
          pcVar8 = local_240;
          pcVar6 = local_248;
          uVar3 = FUN_00487010(0);
          FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
          FUN_00489600(local_200,0,0,0,0);
          iVar7 = 0;
          do {
            cVar1 = (&DAT_005ea438)[iVar7];
            local_200[iVar7] = cVar1;
            iVar7 = iVar7 + 1;
          } while (cVar1 != '\0');
          FUN_00489600(local_200,0,0,0,0);
          FUN_0058815f(local_240,s__d__d_005c6b1c,*(int *)(iVar2 + 0x19c) + 1,
                       *(undefined4 *)(iVar2 + 0x198));
          pcVar8 = local_240;
          pcVar6 = local_248;
          uVar3 = FUN_00487010(1);
          FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
          FUN_00489600(local_200,0,0,0,0);
          iVar2 = 0;
          do {
            cVar1 = (&DAT_005ea438)[iVar2];
            local_200[iVar2] = cVar1;
            iVar2 = iVar2 + 1;
          } while (cVar1 != '\0');
          FUN_00489600(local_200,0,0,0,0);
          uVar3 = FUN_004c13c0(&local_80);
          uVar4 = FUN_004c1450(&local_80);
          FUN_0058815f(local_240,s__d__d_005c6b1c,uVar4,uVar3);
          pcVar8 = local_240;
          pcVar6 = local_248;
          uVar3 = FUN_00487010(2);
          FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
          FUN_00489600(local_200,0,0,0,0);
          iVar2 = 0;
          do {
            cVar1 = (&DAT_005ea438)[iVar2];
            local_200[iVar2] = cVar1;
            iVar2 = iVar2 + 1;
          } while (cVar1 != '\0');
          FUN_00489600(local_200,0,0,0,0);
          puVar5 = (undefined1 *)*local_244;
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          FUN_004c55b0(puVar5);
          iVar2 = FUN_004c5840(0);
          if (iVar2 != 0) {
            iVar2 = FUN_005679c0(s_TrackName_005c6984);
            if (iVar2 != 0) {
              pcVar6 = (char *)FUN_00567970();
              pcVar8 = &local_100;
              do {
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
                *pcVar8 = cVar1;
                pcVar8 = pcVar8 + 1;
              } while (cVar1 != '\0');
            }
          }
          iVar2 = FUN_00423a00(&local_100,&DAT_005ec4cc);
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              cVar1 = (&local_100)[iVar2];
              (&DAT_005ec4cc)[iVar2] = cVar1;
              iVar2 = iVar2 + 1;
            } while (cVar1 != '\0');
          }
          FUN_0058815f(local_240,&DAT_005c2c18,&DAT_005ec4cc);
          pcVar8 = local_240;
          pcVar6 = local_248;
          uVar3 = FUN_00487010(3);
          FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
          FUN_00489600(local_200,0,0,0,0);
          return;
        }
      }
    }
  }
  FUN_004894d0(local_248);
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005c694c)[iVar2];
    local_240[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  pcVar8 = local_240;
  pcVar6 = local_248;
  uVar3 = FUN_00487010(0);
  FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
  FUN_00489600(local_200,0,0,0,0);
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ea438)[iVar2];
    local_200[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00489600(local_200,0,0,0,0);
  pcVar8 = local_240;
  pcVar6 = local_248;
  uVar3 = FUN_00487010(1);
  FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
  FUN_00489600(local_200,0,0,0,0);
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ea438)[iVar2];
    local_200[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00489600(local_200,0,0,0,0);
  pcVar8 = local_240;
  pcVar6 = local_248;
  uVar3 = FUN_00487010(2);
  FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
  FUN_00489600(local_200,0,0,0,0);
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ea438)[iVar2];
    local_200[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00489600(local_200,0,0,0,0);
  pcVar8 = local_240;
  pcVar6 = local_248;
  uVar3 = FUN_00487010(3);
  FUN_0058815f(local_200,s__s_s_s_005c6784,uVar3,pcVar6,pcVar8);
  FUN_00489600(local_200,0,0,0,0);
  return;
}


