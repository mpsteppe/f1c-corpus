// Function: FUN_004a4ed0 @ 004a4ed0
// Strings:  [LFTIRE, RFTIRE, LRTIRE, RRTIRE, SHADOWOBJECT, LODOUT, LODIN, MESHFILE]


void FUN_004a4ed0(undefined4 param_1,undefined4 param_2,int param_3,float param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char cVar6;
  undefined4 *puVar7;
  char *pcVar8;
  bool bVar9;
  float local_3e4;
  float local_3e0 [2];
  undefined1 local_3d8;
  undefined4 local_3d7;
  char local_398 [64];
  undefined1 local_358 [448];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  char local_180 [384];
  
  iVar2 = FUN_00588410(param_2,s_LFTIRE_005c6754);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00588410(param_2,s_RFTIRE_005c675c);
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = FUN_00588410(param_2,s_LRTIRE_005c6764);
      if (iVar2 == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = FUN_00588410(param_2,s_RRTIRE_005c676c);
        iVar2 = (-(uint)(iVar2 != 0) & 0xfffffffc) + 3;
      }
    }
  }
  pcVar3 = local_180;
  for (iVar5 = 0x60; iVar5 != 0; iVar5 = iVar5 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  iVar5 = FUN_00566cc0(local_180,0x180);
  do {
    if (iVar5 == 0) {
      return;
    }
    iVar5 = FUN_005651b0();
    if (iVar5 == 0) {
      iVar5 = 2;
      bVar9 = true;
      pcVar3 = local_180;
      pcVar4 = &DAT_005cc4f4;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar9);
      if (bVar9) {
        return;
      }
      iVar5 = FUN_00565520(s_INSTANCE_005cd620,local_358,0);
      if (iVar5 != 0) {
        FUN_004a4ed0(param_1,local_358,param_3,param_4);
      }
      if ((iVar2 != -1) && (iVar5 = FUN_00565520(s_MESHFILE_005cd614,local_398,0), iVar5 != 0)) {
        local_3e0[0] = -1.0;
        local_3e4 = -1.0;
        FUN_00565870(s_LODIN_005cd60c,local_3e0,0,0,0,0,0,0,0);
        FUN_00565870(s_LODOUT_005cd604,&local_3e4,0,0,0,0,0,0,0);
        if ((local_3e0[0] <= param_4) && (param_4 < local_3e4)) {
          local_3d8 = DAT_005ea438;
          puVar7 = &local_3d7;
          for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
          *(undefined2 *)puVar7 = 0;
          *(undefined1 *)((int)puVar7 + 2) = 0;
          iVar5 = FUN_00565520(s_SHADOWOBJECT_005cd5f4,&local_3d8,0);
          if ((iVar5 == 0) || (iVar5 = FUN_00588410(&local_3d8,&DAT_005c596c), iVar5 != 0)) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
            if (DAT_007cf884 < 2) goto LAB_004a517c;
          }
          pcVar3 = operator_new(0x48);
          if (pcVar3 != (char *)0x0) {
            pcVar4 = local_398;
            do {
              cVar1 = *pcVar4;
              pcVar4[(int)pcVar3 - (int)local_398] = cVar1;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            iVar5 = FUN_00566810();
            if (iVar5 == 0) {
              iVar5 = -1;
              pcVar4 = pcVar3;
              do {
                pcVar8 = pcVar4;
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                pcVar8 = pcVar4 + 1;
                cVar1 = *pcVar4;
                pcVar4 = pcVar8;
              } while (cVar1 != '\0');
              *(undefined4 *)(pcVar8 + -1) = DAT_005cd5ec;
              pcVar8[3] = DAT_005cd5f0;
            }
            pcVar3[0x40] = cVar6;
            *(undefined4 *)(pcVar3 + 0x44) = *(undefined4 *)(param_3 + iVar2 * 4);
            *(char **)(param_3 + iVar2 * 4) = pcVar3;
          }
        }
      }
    }
LAB_004a517c:
    iVar5 = FUN_00566cc0(local_180,0x180);
  } while( true );
}


