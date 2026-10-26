// Function: FUN_0053a7b0 @ 0053a7b0
// Strings:  [invalid literal/length code, invalid distance code]


undefined4 __fastcall
FUN_0053a7b0(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  uint local_18;
  uint local_14;
  byte *local_10;
  byte *local_c;
  
  pbVar9 = (byte *)*param_6;
  local_18 = param_6[1];
  pbVar10 = *(byte **)(param_5 + 0x34);
  uVar11 = *(uint *)(param_5 + 0x20);
  uVar4 = *(uint *)(param_5 + 0x1c);
  if (pbVar10 < *(byte **)(param_5 + 0x30)) {
    local_10 = *(byte **)(param_5 + 0x30) + (-1 - (int)pbVar10);
  }
  else {
    local_10 = (byte *)(*(int *)(param_5 + 0x2c) - (int)pbVar10);
  }
  uVar7 = *(uint *)(&DAT_005dbb90 + param_2 * 4);
  uVar2 = *(uint *)(&DAT_005dbb90 + param_1 * 4);
  while( true ) {
    for (; uVar4 < 0x14; uVar4 = uVar4 + 8) {
      local_18 = local_18 - 1;
      uVar11 = uVar11 | (uint)*pbVar9 << ((byte)uVar4 & 0x1f);
      pbVar9 = pbVar9 + 1;
    }
    pbVar6 = (byte *)(param_3 + (uVar2 & uVar11) * 8);
    uVar8 = (uint)*pbVar6;
    if (uVar8 != 0) break;
LAB_0053a874:
    uVar4 = uVar4 - pbVar6[1];
    uVar11 = uVar11 >> (pbVar6[1] & 0x1f);
    *pbVar10 = pbVar6[4];
    pbVar10 = pbVar10 + 1;
    local_10 = local_10 + -1;
LAB_0053a88d:
    if ((local_10 < (byte *)0x102) || (local_18 < 10)) {
      uVar7 = param_6[1] - local_18;
      if (uVar4 >> 3 < param_6[1] - local_18) {
        uVar7 = uVar4 >> 3;
      }
      *(uint *)(param_5 + 0x20) = uVar11;
      *(uint *)(param_5 + 0x1c) = uVar4 + uVar7 * -8;
      iVar3 = *param_6;
      param_6[1] = uVar7 + local_18;
      *param_6 = (int)pbVar9 - uVar7;
      param_6[2] = param_6[2] + (((int)pbVar9 - uVar7) - iVar3);
      *(byte **)(param_5 + 0x34) = pbVar10;
      return 0;
    }
  }
LAB_0053a840:
  uVar11 = uVar11 >> (pbVar6[1] & 0x1f);
  uVar4 = uVar4 - pbVar6[1];
  if ((uVar8 & 0x10) == 0) {
    if ((uVar8 & 0x40) == 0) goto code_r0x0053a85b;
    if ((uVar8 & 0x20) != 0) {
      uVar7 = param_6[1] - local_18;
      if (uVar4 >> 3 < param_6[1] - local_18) {
        uVar7 = uVar4 >> 3;
      }
      *(uint *)(param_5 + 0x20) = uVar11;
      *(uint *)(param_5 + 0x1c) = uVar4 + uVar7 * -8;
      iVar3 = *param_6;
      param_6[1] = uVar7 + local_18;
      *param_6 = (int)pbVar9 - uVar7;
      param_6[2] = param_6[2] + (((int)pbVar9 - uVar7) - iVar3);
      *(byte **)(param_5 + 0x34) = pbVar10;
      return 1;
    }
    param_6[6] = (int)s_invalid_literal_length_code_005da964;
  }
  else {
    uVar8 = uVar8 & 0xf;
    local_14 = (*(uint *)(&DAT_005dbb90 + uVar8 * 4) & uVar11) + *(int *)(pbVar6 + 4);
    uVar11 = uVar11 >> (sbyte)uVar8;
    for (uVar4 = uVar4 - uVar8; uVar4 < 0xf; uVar4 = uVar4 + 8) {
      local_18 = local_18 - 1;
      uVar11 = uVar11 | (uint)*pbVar9 << ((byte)uVar4 & 0x1f);
      pbVar9 = pbVar9 + 1;
    }
    local_c = (byte *)(param_4 + (uVar7 & uVar11) * 8);
    bVar1 = *local_c;
    while( true ) {
      uVar11 = uVar11 >> (local_c[1] & 0x1f);
      uVar4 = uVar4 - local_c[1];
      if ((bVar1 & 0x10) != 0) {
        uVar8 = bVar1 & 0xf;
        for (; uVar4 < uVar8; uVar4 = uVar4 + 8) {
          local_18 = local_18 - 1;
          uVar11 = uVar11 | (uint)*pbVar9 << ((byte)uVar4 & 0x1f);
          pbVar9 = pbVar9 + 1;
        }
        uVar4 = uVar4 - uVar8;
        uVar12 = (*(uint *)(&DAT_005dbb90 + uVar8 * 4) & uVar11) + *(int *)(local_c + 4);
        uVar11 = uVar11 >> (sbyte)uVar8;
        local_10 = local_10 + -local_14;
        if ((uint)((int)pbVar10 - *(int *)(param_5 + 0x28)) < uVar12) {
          uVar12 = (*(int *)(param_5 + 0x28) - (int)pbVar10) + uVar12;
          pbVar6 = (byte *)(*(int *)(param_5 + 0x2c) - uVar12);
          if (uVar12 < local_14) {
            local_14 = local_14 - uVar12;
            do {
              *pbVar10 = *pbVar6;
              pbVar10 = pbVar10 + 1;
              pbVar6 = pbVar6 + 1;
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
            pbVar6 = *(byte **)(param_5 + 0x28);
          }
        }
        else {
          pbVar5 = pbVar10 + -uVar12;
          *pbVar10 = *pbVar5;
          pbVar6 = pbVar5 + 2;
          pbVar10[1] = pbVar5[1];
          local_14 = local_14 - 2;
          pbVar10 = pbVar10 + 2;
        }
        do {
          *pbVar10 = *pbVar6;
          pbVar10 = pbVar10 + 1;
          pbVar6 = pbVar6 + 1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
        goto LAB_0053a88d;
      }
      if ((bVar1 & 0x40) != 0) break;
      local_c = local_c + ((*(uint *)(&DAT_005dbb90 + (uint)bVar1 * 4) & uVar11) +
                          *(int *)(local_c + 4)) * 8;
      bVar1 = *local_c;
    }
    param_6[6] = (int)s_invalid_distance_code_005da980;
  }
  uVar7 = uVar4 >> 3;
  if (param_6[1] - local_18 <= uVar4 >> 3) {
    uVar7 = param_6[1] - local_18;
  }
  *(uint *)(param_5 + 0x20) = uVar11;
  *(uint *)(param_5 + 0x1c) = uVar4 + uVar7 * -8;
  iVar3 = *param_6;
  param_6[1] = uVar7 + local_18;
  *param_6 = (int)pbVar9 - uVar7;
  param_6[2] = param_6[2] + (((int)pbVar9 - uVar7) - iVar3);
  *(byte **)(param_5 + 0x34) = pbVar10;
  return 0xfffffffd;
code_r0x0053a85b:
  pbVar6 = pbVar6 + ((*(uint *)(&DAT_005dbb90 + uVar8 * 4) & uVar11) + *(int *)(pbVar6 + 4)) * 8;
  uVar8 = (uint)*pbVar6;
  if (uVar8 == 0) goto LAB_0053a874;
  goto LAB_0053a840;
}


