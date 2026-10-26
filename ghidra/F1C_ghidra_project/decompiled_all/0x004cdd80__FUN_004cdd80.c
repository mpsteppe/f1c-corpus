// Function: FUN_004cdd80 @ 004cdd80
// Strings:  [MATERIALS, GUARDRAIL, GUARDRAIL, SOLIDWALL, SOLIDWALL, TIREWALL, TIREWALL, RUMBLE]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cdd80(int param_1,undefined4 param_2,undefined4 param_3)

{
  float *pfVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  float local_108;
  int local_104;
  char local_100 [256];
  
  iVar3 = FUN_00565520(s_LEGAL_005d38f0,local_100,0);
  if ((iVar3 != 0) && (iVar3 = FUN_00588410(local_100,&DAT_005c596c), iVar3 == 0)) {
    *(undefined1 *)(param_1 + 0x60) = 1;
  }
  pfVar1 = (float *)(param_1 + 8);
  local_108 = 0.0;
  iVar3 = FUN_004cdc70(param_2,&DAT_005d38ec,pfVar1,param_3);
  if (iVar3 != 0) {
    *(float *)(param_1 + 0xc) = *pfVar1;
  }
  iVar3 = FUN_004cdc70(param_2,&DAT_005d38e8,&local_108,param_3);
  if (iVar3 != 0) {
    *(float *)(param_1 + 0xc) = *pfVar1 - local_108;
  }
  FUN_004cdc70(param_2,s_RESISTANCE_005d38dc,param_1 + 0x10,param_3);
  pfVar1 = (float *)(param_1 + 0x14);
  iVar3 = FUN_004cdc70(param_2,s_BUMPAMP_005d38d4,pfVar1,param_3);
  if (iVar3 != 0) {
    *pfVar1 = *pfVar1 * _DAT_0059e7f8;
  }
  iVar3 = FUN_004cdc70(param_2,s_BUMPWAVELEN_005d38c8,&local_108,param_3);
  if (iVar3 != 0) {
    if (local_108 < _DAT_0059e478) {
      local_108 = 3.0;
    }
    *(float *)(param_1 + 0x18) = (float)_DAT_0059ed28 / local_108;
  }
  FUN_004cdc70(param_2,s_SPRING_005d38c0,param_1 + 0x1c,param_3);
  FUN_004cdc70(param_2,s_DAMPER_005d38b8,param_1 + 0x20,param_3);
  FUN_004cdc70(param_2,s_COLLFRICT_005d38ac,param_1 + 0x24,param_3);
  FUN_00565760(s_SPARKS_005d38a4,param_1 + 0x28,0,0,0);
  iVar3 = FUN_00565760(s_SCRAPING_005d3898,&local_104,0,0,0);
  if (iVar3 != 0) {
    *(bool *)(param_1 + 0x2c) = local_104 != 0;
  }
  iVar3 = FUN_004cdc70(param_2,&DAT_005d3890,&local_108,param_3);
  if (iVar3 != 0) {
    *(double *)(param_1 + 100) = (double)local_108;
  }
  iVar3 = FUN_00565520(s_SOUND_005d3888,local_100,0);
  if (iVar3 != 0) {
    iVar3 = 4;
    bVar7 = true;
    pcVar6 = local_100;
    pcVar5 = &DAT_005d38ec;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar6 == *pcVar5;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar7);
    if (bVar7) {
      *(undefined4 *)(param_1 + 0x30) = 6;
      *(undefined4 *)(param_1 + 0x34) = 0x15;
      *(undefined4 *)(param_1 + 0x38) = 0x1b;
    }
    else {
      iVar3 = 4;
      bVar7 = true;
      pcVar6 = local_100;
      pcVar5 = &DAT_005d38e8;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pcVar6 == *pcVar5;
        pcVar6 = pcVar6 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (bVar7) {
        *(undefined4 *)(param_1 + 0x30) = 7;
        *(undefined4 *)(param_1 + 0x34) = 0x16;
        *(undefined4 *)(param_1 + 0x38) = 0x1b;
      }
      else {
        iVar3 = 5;
        bVar7 = true;
        pcVar6 = local_100;
        pcVar5 = &DAT_005d3880;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar7 = *pcVar6 == *pcVar5;
          pcVar6 = pcVar6 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar7);
        if (bVar7) {
          *(undefined4 *)(param_1 + 0x30) = 9;
          *(undefined4 *)(param_1 + 0x34) = 0x18;
          *(undefined4 *)(param_1 + 0x38) = 0x20;
        }
        else {
          iVar3 = 6;
          bVar7 = true;
          pcVar6 = local_100;
          pcVar5 = s_GRASS_005d3878;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar7 = *pcVar6 == *pcVar5;
            pcVar6 = pcVar6 + 1;
            pcVar5 = pcVar5 + 1;
          } while (bVar7);
          if (bVar7) {
            *(undefined4 *)(param_1 + 0x30) = 8;
            *(undefined4 *)(param_1 + 0x34) = 0x17;
            *(undefined4 *)(param_1 + 0x38) = 0x20;
          }
          else {
            iVar3 = 7;
            bVar7 = true;
            pcVar6 = local_100;
            pcVar5 = s_GRAVEL_005d3870;
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar7 = *pcVar6 == *pcVar5;
              pcVar6 = pcVar6 + 1;
              pcVar5 = pcVar5 + 1;
            } while (bVar7);
            if (bVar7) {
              *(undefined4 *)(param_1 + 0x30) = 10;
              *(undefined4 *)(param_1 + 0x34) = 0x19;
              *(undefined4 *)(param_1 + 0x38) = 0x20;
            }
            else {
              iVar3 = 7;
              bVar7 = true;
              pcVar6 = local_100;
              pcVar5 = s_RUMBLE_005d3868;
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar7 = *pcVar6 == *pcVar5;
                pcVar6 = pcVar6 + 1;
                pcVar5 = pcVar5 + 1;
              } while (bVar7);
              if (bVar7) {
                *(undefined4 *)(param_1 + 0x30) = 0xb;
                *(undefined4 *)(param_1 + 0x34) = 0x15;
                *(undefined4 *)(param_1 + 0x38) = 0x1b;
              }
              else {
                iVar3 = 9;
                bVar7 = true;
                pcVar6 = local_100;
                pcVar5 = s_TIREWALL_005d385c;
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar7 = *pcVar6 == *pcVar5;
                  pcVar6 = pcVar6 + 1;
                  pcVar5 = pcVar5 + 1;
                } while (bVar7);
                if (bVar7) {
                  uVar4 = 0x20;
                }
                else {
                  iVar3 = 10;
                  bVar7 = true;
                  pcVar6 = local_100;
                  pcVar5 = s_SOLIDWALL_005d3850;
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar7 = *pcVar6 == *pcVar5;
                    pcVar6 = pcVar6 + 1;
                    pcVar5 = pcVar5 + 1;
                  } while (bVar7);
                  if (!bVar7) {
                    iVar3 = 10;
                    bVar7 = true;
                    pcVar6 = local_100;
                    pcVar5 = s_GUARDRAIL_005d3844;
                    do {
                      if (iVar3 == 0) break;
                      iVar3 = iVar3 + -1;
                      bVar7 = *pcVar6 == *pcVar5;
                      pcVar6 = pcVar6 + 1;
                      pcVar5 = pcVar5 + 1;
                    } while (bVar7);
                    if (!bVar7) goto LAB_004ce088;
                  }
                  uVar4 = 0x1b;
                }
                *(undefined4 *)(param_1 + 0x30) = uVar4;
                *(undefined4 *)(param_1 + 0x34) = uVar4;
                *(undefined4 *)(param_1 + 0x38) = uVar4;
              }
            }
          }
        }
      }
    }
  }
LAB_004ce088:
  iVar3 = FUN_005654a0(s_MATERIALS_005d3838,local_100);
  if (iVar3 != 0) {
    FUN_00589901(local_100);
    if (local_100[0] != '\0') {
      pcVar6 = local_100 + 1;
      do {
        pcVar5 = pcVar6;
        if (pcVar6[-1] == ' ') {
          do {
            cVar2 = *pcVar5;
            pcVar5[-1] = cVar2;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
        }
        else if ((pcVar6[-1] == ',') && ((*pcVar6 == ',' || (*pcVar6 == '\0')))) {
          do {
            cVar2 = *pcVar5;
            pcVar5[-1] = cVar2;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
        }
        else {
          pcVar6 = pcVar6 + 1;
        }
      } while (pcVar6[-1] != '\0');
    }
    FUN_00566650(local_100);
  }
  return;
}


