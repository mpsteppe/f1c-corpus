// Function: FUN_004dd030 @ 004dd030
// Size (bytes): 876


void __thiscall
FUN_004dd030(int param_1,char *param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6
            ,float param_7,float param_8)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  undefined4 local_114;
  undefined1 local_110;
  undefined4 local_10f;
  undefined4 local_10b;
  undefined2 local_107;
  undefined1 local_105;
  undefined1 local_104 [3];
  char acStack_101 [2];
  undefined4 local_ff;
  undefined1 local_81;
  char local_80;
  undefined4 local_7f;
  
  if (param_2 != (char *)0x0) {
    acStack_101[1] = DAT_005ea438;
    puVar9 = &local_ff;
    for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    *(undefined2 *)puVar9 = 0;
    *(undefined1 *)((int)puVar9 + 2) = 0;
    if (DAT_0059e440 < param_7) {
      *(float *)(param_1 + 0x30) = param_7;
    }
    if (DAT_0059e440 < param_8) {
      *(float *)(param_1 + 0x34) = param_8;
    }
    _strncpy(acStack_101 + 1,param_2,0x7f);
    local_81 = 0;
    FUN_004dcf50(&local_12c,&local_134,0);
    FUN_004dcf30(&local_138,&local_13c);
    local_138 = local_138 + local_12c;
    local_130 = local_13c + local_134;
    param_3 = param_3 + local_12c;
    param_4 = param_4 + local_134;
    if (acStack_101[1] != '\0') {
      do {
        FUN_004dc600(&local_128,&local_11c,*(undefined4 *)(param_1 + 0x30),
                     *(undefined4 *)(param_1 + 0x34));
        iVar2 = local_11c;
        iVar7 = local_128;
        FUN_004dc340(local_128,local_11c,param_6,&local_118,&local_120);
        iVar3 = local_118;
        iVar6 = local_12c;
        local_13c = local_118 + iVar7;
        if (local_12c <= local_118) {
          if (local_120 < local_134) {
            return;
          }
          if ((local_13c <= local_138) && (local_120 + iVar2 <= local_130)) {
            FUN_004dc660(param_3,param_4,param_5,param_6,*(undefined4 *)(param_1 + 0x30),
                         *(undefined4 *)(param_1 + 0x34),0);
            return;
          }
        }
        if (local_120 < local_134) {
          return;
        }
        if (local_130 < local_120 + iVar2) {
          return;
        }
        if (iVar7 < 1) {
          return;
        }
        local_10f = 0;
        local_10b = 0;
        local_114 = DAT_005d4c04;
        local_107 = 0;
        local_110 = DAT_005d4c08;
        local_105 = 0;
        FUN_004dc600(&local_124,local_104,*(undefined4 *)(param_1 + 0x30),
                     *(undefined4 *)(param_1 + 0x34));
        iVar7 = (int)(local_124 + (local_124 >> 0x1f & 3U)) >> 2;
        if (iVar7 < 1) {
          iVar7 = 1;
        }
        else if (1000 < iVar7) {
          iVar7 = 1000;
        }
        if (iVar3 < iVar6) {
          uVar4 = (iVar6 - iVar3) / iVar7;
          if (uVar4 == 0) {
            uVar4 = 1;
          }
          else if (1000 < uVar4) {
            uVar4 = 1000;
          }
          uVar8 = 0xffffffff;
          pcVar5 = acStack_101;
          do {
            pcVar5 = pcVar5 + 1;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
          } while (*pcVar5 != '\0');
          if (~uVar8 - 1 <= uVar4) {
            return;
          }
          local_80 = DAT_005ea438;
          puVar9 = &local_7f;
          for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
          *(undefined2 *)puVar9 = 0;
          *(undefined1 *)((int)puVar9 + 2) = 0;
          iVar6 = 0;
          do {
            cVar1 = acStack_101[iVar6 + 1];
            (&local_80)[iVar6] = cVar1;
            iVar6 = iVar6 + 1;
          } while (cVar1 != '\0');
          pcVar5 = &local_80 + uVar4;
          iVar6 = 1 - (int)pcVar5;
          do {
            cVar1 = *pcVar5;
            pcVar5[(int)(acStack_101 + iVar6)] = cVar1;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
        }
        else {
          uVar4 = (local_13c - local_138) / iVar7;
          if (uVar4 == 0) {
            uVar4 = 1;
          }
          else if (1000 < uVar4) {
            uVar4 = 1000;
          }
          uVar8 = 0xffffffff;
          pcVar5 = acStack_101;
          do {
            pcVar5 = pcVar5 + 1;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
          } while (*pcVar5 != '\0');
          if (~uVar8 - 1 <= uVar4) {
            return;
          }
          uVar8 = 0xffffffff;
          pcVar5 = acStack_101;
          do {
            pcVar5 = pcVar5 + 1;
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
          } while (*pcVar5 != '\0');
          acStack_101[~uVar8 - uVar4] = '\0';
        }
        if (acStack_101[1] == '\0') {
          return;
        }
      } while( true );
    }
  }
  return;
}


