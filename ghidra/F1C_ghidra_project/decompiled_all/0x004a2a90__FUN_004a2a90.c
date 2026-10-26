// Function: FUN_004a2a90 @ 004a2a90
// Strings:  [POSITION, D:\dev\F1_1999_2002\Source\pitcrew.cpp, Unable to setup after pitcrew %s, ROTATE %f, ROTATE, %s.ANM, MOVE %s %s %f, POSITION %f %f %f]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004a2a90(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined2 *puVar6;
  int *piVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  bool bVar11;
  undefined4 local_6d4;
  undefined4 local_6d0;
  undefined4 local_6cc;
  undefined4 local_6c8;
  undefined4 local_6c4;
  float local_6c0;
  undefined4 local_6bc;
  undefined2 local_6b8 [2];
  undefined4 local_6b4;
  char local_6b0 [64];
  undefined1 local_670 [12];
  undefined1 local_664 [12];
  char local_658 [64];
  undefined1 local_618 [640];
  undefined4 local_398;
  undefined1 local_394;
  undefined4 local_38c;
  undefined4 local_388;
  int local_384;
  undefined4 local_380 [96];
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  puVar9 = local_380;
  for (iVar5 = 0x60; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  local_398 = 0;
  local_384 = 0;
  local_38c = 0;
  local_388 = 0;
  local_394 = 1;
  iVar5 = FUN_00587db0(param_2,&DAT_005be690);
  if (iVar5 == 0) {
    return 0xffffffff;
  }
  local_6b4 = DAT_008afe88;
  iVar2 = FUN_005450e0(param_1 + 5,param_4,s_FUELRIG_MTS_005cd474,0x14);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if ((1 < DAT_007cf884) && (iVar2 = FUN_0054c230(0), iVar2 != 0)) {
    FUN_00545930(iVar2,0);
  }
  iVar2 = 0;
  iVar3 = FUN_00587ca0(local_380,0x180,iVar5);
  while (iVar3 != 0) {
    iVar3 = FUN_005651b0();
    if ((iVar3 == 0) && (iVar3 = FUN_00587c20(local_380,s_ACTOR_005cd46c), iVar3 != 0)) {
      iVar2 = iVar2 + 1;
    }
    iVar3 = FUN_00587ca0(local_380,0x180,iVar5);
  }
  FUN_00587f64(iVar5,0,0);
  piVar4 = operator_new(iVar2 * 0x78 + 4);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = iVar2;
    piVar4 = piVar4 + 1;
    piVar7 = piVar4;
    if (-1 < iVar2 + -1) {
      do {
        piVar7[0x19] = 0;
        piVar7[0x1b] = 0;
        piVar7[0x1d] = 0;
        FUN_004a2220();
        piVar7 = piVar7 + 0x1e;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  param_1[4] = piVar4;
  puVar6 = (undefined2 *)0x0;
  param_1[3] = 0;
  iVar2 = FUN_00587ca0(local_380,0x180,iVar5);
  do {
    if (iVar2 == 0) {
      FUN_00587d02(iVar5);
      FUN_00545250(param_1[5]);
      iVar5 = FUN_00543fa0();
      if (iVar5 != 0) {
        FUN_0053c5b0(0,local_200);
        cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_pitcr_005cd174,0x2c4);
        if (cVar1 != '\0') {
          FUN_004d7aa0(&DAT_008ad25c,s_Unable_to_setup_after_pitcrew__s_005cd33c,local_200);
        }
      }
      iVar5 = FUN_0054c230(0);
      if (iVar5 != 0) {
        *(float *)(iVar5 + 0x18) = *(float *)(iVar5 + 0x18) * (float)_DAT_0059e7d8;
      }
      FUN_004d1100(DAT_007c54e8,local_664,local_670);
      FUN_004a3320(local_664,local_670);
      FUN_0054c030(1,0,0,0);
      *param_1 = 1;
      FUN_004a3440();
      iVar5 = 0;
      if (0 < (int)param_1[3]) {
        do {
          FUN_004a27d0();
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)param_1[3]);
      }
      return 0;
    }
    iVar2 = FUN_005651b0();
    if (iVar2 == 0) {
      iVar2 = FUN_00587c20(local_380,s_ACTOR_005cd46c);
      if (iVar2 != 0) {
        puVar6 = (undefined2 *)(param_1[3] * 0x78 + param_1[4]);
        param_1[3] = param_1[3] + 1;
        FUN_005887ed(local_380,s_ACTOR__s_005cd460,local_618);
        FUN_004a2a40(local_618,local_6b0);
        iVar2 = 5;
        bVar11 = true;
        pcVar8 = local_6b0;
        pcVar10 = &DAT_005cd458;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar11 = *pcVar8 == *pcVar10;
          pcVar8 = pcVar8 + 1;
          pcVar10 = pcVar10 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar2 = 9;
          bVar11 = true;
          pcVar8 = local_6b0;
          pcVar10 = s_LOLLIPOP_005cd44c;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar11 = *pcVar8 == *pcVar10;
            pcVar8 = pcVar8 + 1;
            pcVar10 = pcVar10 + 1;
          } while (bVar11);
          if (!bVar11) {
            *(undefined1 *)((int)puVar6 + 3) = 0;
            goto LAB_004a2ce7;
          }
        }
        *(undefined1 *)((int)puVar6 + 3) = 1;
      }
LAB_004a2ce7:
      iVar2 = FUN_00587c20(local_380,s_DETAIL_005cd444);
      if (iVar2 != 0) {
        FUN_005887ed(local_380,s_DETAIL__d_005cd438,local_6b8);
        *puVar6 = local_6b8[0];
      }
      iVar2 = FUN_00587c20(local_380,&DAT_005cd430);
      if (iVar2 != 0) {
        FUN_005887ed(local_380,s_MESH__s_005cd428,local_618);
        FUN_004a2a40(local_618,local_658);
        iVar2 = 0xf;
        bVar11 = true;
        pcVar8 = local_658;
        pcVar10 = s_LFWHEELOFF_MTS_005cd418;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar11 = *pcVar8 == *pcVar10;
          pcVar8 = pcVar8 + 1;
          pcVar10 = pcVar10 + 1;
        } while (bVar11);
        if (bVar11) {
          FUN_004a2770(0,0,local_6b0,*(undefined4 *)(param_3 + 4),param_1[5]);
        }
        else {
          iVar2 = 0xe;
          bVar11 = true;
          pcVar8 = local_658;
          pcVar10 = s_LFWHEELON_MTS_005cd408;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar11 = *pcVar8 == *pcVar10;
            pcVar8 = pcVar8 + 1;
            pcVar10 = pcVar10 + 1;
          } while (bVar11);
          if (bVar11) {
            FUN_004a2770(1,0,local_6b0,*(undefined4 *)(param_3 + 4),param_1[5]);
          }
          else {
            iVar2 = 0xf;
            bVar11 = true;
            pcVar8 = local_658;
            pcVar10 = s_RFWHEELOFF_MTS_005cd3f8;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar11 = *pcVar8 == *pcVar10;
              pcVar8 = pcVar8 + 1;
              pcVar10 = pcVar10 + 1;
            } while (bVar11);
            if (bVar11) {
              FUN_004a2770(0,1,local_6b0,*(undefined4 *)(param_3 + 4),param_1[5]);
            }
            else {
              iVar2 = 0xe;
              bVar11 = true;
              pcVar8 = local_658;
              pcVar10 = s_RFWHEELON_MTS_005cd3e8;
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar11 = *pcVar8 == *pcVar10;
                pcVar8 = pcVar8 + 1;
                pcVar10 = pcVar10 + 1;
              } while (bVar11);
              if (bVar11) {
                FUN_004a2770(1,1,local_6b0,*(undefined4 *)(param_3 + 4),param_1[5]);
              }
              else {
                iVar2 = 0xf;
                bVar11 = true;
                pcVar8 = local_658;
                pcVar10 = s_LRWHEELOFF_MTS_005cd3d8;
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar11 = *pcVar8 == *pcVar10;
                  pcVar8 = pcVar8 + 1;
                  pcVar10 = pcVar10 + 1;
                } while (bVar11);
                if (bVar11) {
                  FUN_004a2770(0,2,local_6b0,*(undefined4 *)(param_3 + 8),param_1[5]);
                }
                else {
                  iVar2 = 0xe;
                  bVar11 = true;
                  pcVar8 = local_658;
                  pcVar10 = s_LRWHEELON_MTS_005cd3c8;
                  do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar11 = *pcVar8 == *pcVar10;
                    pcVar8 = pcVar8 + 1;
                    pcVar10 = pcVar10 + 1;
                  } while (bVar11);
                  if (bVar11) {
                    FUN_004a2770(1,2,local_6b0,*(undefined4 *)(param_3 + 8),param_1[5]);
                  }
                  else {
                    iVar2 = 0xf;
                    bVar11 = true;
                    pcVar8 = local_658;
                    pcVar10 = s_RRWHEELOFF_MTS_005cd3b8;
                    do {
                      if (iVar2 == 0) break;
                      iVar2 = iVar2 + -1;
                      bVar11 = *pcVar8 == *pcVar10;
                      pcVar8 = pcVar8 + 1;
                      pcVar10 = pcVar10 + 1;
                    } while (bVar11);
                    if (bVar11) {
                      FUN_004a2770(0,3,local_6b0,*(undefined4 *)(param_3 + 8),param_1[5]);
                    }
                    else {
                      iVar2 = 0xe;
                      bVar11 = true;
                      pcVar8 = local_658;
                      pcVar10 = s_RRWHEELON_MTS_005cd3a8;
                      do {
                        if (iVar2 == 0) break;
                        iVar2 = iVar2 + -1;
                        bVar11 = *pcVar8 == *pcVar10;
                        pcVar8 = pcVar8 + 1;
                        pcVar10 = pcVar10 + 1;
                      } while (bVar11);
                      if (bVar11) {
                        FUN_004a2770(1,3,local_6b0,*(undefined4 *)(param_3 + 8),param_1[5]);
                      }
                      else {
                        FUN_004a21d0(local_6b0,local_658,param_1[5],0);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      iVar2 = FUN_00587c20(local_380,s_POSITION_005c59d4);
      if (iVar2 != 0) {
        local_6d4 = 0;
        local_6d0 = 0;
        local_6cc = 0;
        FUN_005887ed(local_380,s_POSITION__f__f__f_005cd394,&local_6d4,&local_6d0,&local_6cc);
        *(undefined4 *)(puVar6 + 0x26) = local_6d4;
        *(undefined4 *)(puVar6 + 0x28) = local_6d0;
        *(undefined4 *)(puVar6 + 0x2a) = local_6cc;
      }
      iVar2 = FUN_00587c20(local_380,&DAT_005cd38c);
      if (iVar2 != 0) {
        local_6c8 = 0;
        FUN_005887ed(local_380,s_MOVE__s__s__f_005cd37c,local_618,local_100,&local_6c8);
        FUN_004a2a40(local_618,local_200);
        FUN_0058815f(local_618,s__s_ANM_005cd374,local_200);
        FUN_004a22d0(local_200,local_618,local_100,local_6c8);
      }
      local_384 = FUN_00587c20(local_380,s_ROTATE_005cd36c);
      if (local_384 != 0) {
        local_6c4 = *(undefined4 *)(puVar6 + 0x2c);
        local_6c0 = *(float *)(puVar6 + 0x2e);
        local_6bc = *(undefined4 *)(puVar6 + 0x30);
        FUN_005887ed(local_384,s_ROTATE__f_005cd360,&local_6c0);
        local_6c0 = local_6c0 * _DAT_0059e65c;
        *(undefined4 *)(puVar6 + 0x2c) = local_6c4;
        *(float *)(puVar6 + 0x2e) = local_6c0;
        *(undefined4 *)(puVar6 + 0x30) = local_6bc;
      }
    }
    iVar2 = FUN_00587ca0(local_380,0x180,iVar5);
  } while( true );
}


