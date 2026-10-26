// Function: FUN_0044acb0 @ 0044acb0
// Size (bytes): 609


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044acb0(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined1 local_110 [2];
  undefined2 local_10e;
  undefined4 local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined1 local_e8 [4];
  float local_e4 [2];
  undefined1 local_dc [12];
  undefined1 local_d0 [12];
  undefined1 local_c4 [4];
  float local_c0;
  float local_b8;
  double local_b4;
  float local_ac;
  undefined1 local_a8 [16];
  undefined1 local_98 [16];
  byte local_88 [64];
  byte local_48;
  undefined4 local_47;
  
  local_48 = DAT_005ea438;
  puVar9 = &local_47;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(undefined2 *)puVar9 = 0;
  *(undefined1 *)((int)puVar9 + 2) = 0;
  local_10c = 0xffffffff;
  local_104 = 0;
  local_ec = FUN_005452f0();
  local_100 = 0;
  if (0 < local_ec) {
    do {
      iVar6 = local_100;
      local_f4 = FUN_00545340(local_100);
      local_f8 = FUN_0054c210();
      local_108 = 0;
      if (0 < local_f8) {
        do {
          iVar6 = local_108;
          iVar2 = FUN_0054c230(local_108);
          if ((*(uint *)(iVar2 + 0x14) & 0x100) == 0x100) {
            local_fc = FUN_0054e190();
            iVar2 = 0;
            if (0 < local_fc) {
              do {
                FUN_0054e240(iVar2);
                FUN_00547370(local_88);
                pbVar8 = &local_48;
                pbVar3 = local_88;
                do {
                  bVar1 = *pbVar3;
                  bVar10 = bVar1 < *pbVar8;
                  if (bVar1 != *pbVar8) {
LAB_0044adb9:
                    iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                    goto LAB_0044adbe;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar3[1];
                  bVar10 = bVar1 < pbVar8[1];
                  if (bVar1 != pbVar8[1]) goto LAB_0044adb9;
                  pbVar3 = pbVar3 + 2;
                  pbVar8 = pbVar8 + 2;
                } while (bVar1 != 0);
                iVar6 = 0;
LAB_0044adbe:
                if (iVar6 != 0) {
                  uVar4 = FUN_004ce860(local_88);
                  local_104 = FUN_004ce8d0(uVar4);
                  iVar6 = 0;
                  do {
                    pbVar8 = local_88 + iVar6;
                    (&local_48)[iVar6] = *pbVar8;
                    iVar6 = iVar6 + 1;
                    local_10c = uVar4;
                  } while (*pbVar8 != 0);
                }
                if ((local_104 != 0) &&
                   (*(float *)(local_104 + 8) - *(float *)(local_104 + 0xc) * DAT_0059e440 !=
                    DAT_0059e440)) {
                  local_10e = (undefined2)local_10c;
                  local_110[0] = 0xff;
                  FUN_0054e1a0(iVar2,local_e8,local_dc,local_d0);
                  iVar6 = FUN_004dd9f0(local_d0,local_c4);
                  if ((iVar6 == 0) && ((float)_DAT_0059ea08 <= local_c0)) {
                    iVar6 = 3;
                    pfVar5 = &local_ac;
                    pfVar7 = local_e4;
                    do {
                      pfVar5[-3] = pfVar7[-1];
                      iVar6 = iVar6 + -1;
                      *(double *)(pfVar5 + -2) = (double)*pfVar7;
                      *pfVar5 = pfVar7[1];
                      pfVar5 = pfVar5 + 4;
                      pfVar7 = pfVar7 + 3;
                    } while (iVar6 != 0);
                    FUN_0044aae0(&local_b8,local_a8,local_98,local_110,param_2);
                  }
                }
                iVar2 = iVar2 + 1;
                iVar6 = local_108;
              } while (iVar2 < local_fc);
            }
          }
          local_108 = iVar6 + 1;
          iVar6 = local_100;
        } while (local_108 < local_f8);
      }
      local_100 = iVar6 + 1;
    } while (local_100 < local_ec);
  }
  return;
}


