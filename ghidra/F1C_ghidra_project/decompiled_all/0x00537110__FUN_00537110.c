// Function: FUN_00537110 @ 00537110
// Strings:  [invalid bit length repeat, too many length or distance symbols, invalid stored block lengths, invalid block type]


void __fastcall FUN_00537110(uint *param_1,int *param_2,byte *param_3)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  uint local_30;
  int *local_2c;
  byte *local_28;
  byte *pbStack_24;
  undefined4 uStack_20;
  undefined4 auStack_1c [3];
  byte *pbStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_3c = (byte *)*param_2;
  local_38 = (byte *)param_2[1];
  local_34 = (byte *)param_1[0xd];
  local_30 = param_1[8];
  pbVar8 = (byte *)param_1[7];
  local_2c = param_2;
  if (local_34 < (byte *)param_1[0xc]) {
    local_28 = (byte *)param_1[0xc] + (-1 - (int)local_34);
  }
  else {
    local_28 = (byte *)(param_1[0xb] - (int)local_34);
  }
switchD_005371b9_default:
  piVar1 = local_2c;
  uVar10 = local_30;
  switch(*param_1) {
  case 0:
    for (; local_30 = uVar10, pbVar8 < (byte *)0x3; pbVar8 = pbVar8 + 8) {
      if (local_38 == (byte *)0x0) {
        param_1[8] = uVar10;
        param_1[7] = (uint)pbVar8;
        iVar6 = *local_2c;
        local_2c[1] = 0;
        *local_2c = (int)local_3c;
        local_2c[2] = (int)(local_3c + (local_2c[2] - iVar6));
        param_1[0xd] = (uint)local_34;
        goto LAB_0053787f;
      }
      local_38 = local_38 + -1;
      param_3 = (byte *)0x0;
      uVar10 = uVar10 | (uint)*local_3c << ((byte)pbVar8 & 0x1f);
      local_3c = local_3c + 1;
    }
    goto LAB_005371a5;
  case 1:
    if (pbVar8 < (byte *)0x20) {
LAB_0053725c:
      if (local_38 != (byte *)0x0) goto code_r0x00537266;
      param_1[8] = uVar10;
      param_1[7] = (uint)pbVar8;
      local_2c[1] = 0;
LAB_005379b7:
      iVar6 = *local_2c;
      *local_2c = (int)local_3c;
      pbVar8 = local_3c + (local_2c[2] - iVar6);
      goto LAB_00537c80;
    }
LAB_00537286:
    uVar3 = uVar10 & 0xffff;
    if (~uVar10 >> 0x10 != uVar3) {
      *param_1 = 9;
      param_3 = (byte *)0xfffffffd;
      local_2c[6] = (int)s_invalid_stored_block_lengths_005da8f4;
      param_1[8] = uVar10;
      param_1[7] = (uint)pbVar8;
      local_2c[1] = (int)local_38;
      goto LAB_00537c73;
    }
    pbVar8 = (byte *)0x0;
    param_1[1] = uVar3;
    local_30 = 0;
    if (uVar3 == 0) goto LAB_005373d9;
    *param_1 = 2;
    goto switchD_005371b9_default;
  case 2:
    if (local_38 == (byte *)0x0) {
      param_1[8] = local_30;
      param_1[7] = (uint)pbVar8;
      local_2c[1] = 0;
      pbVar8 = local_3c + (local_2c[2] - *local_2c);
      *local_2c = (int)local_3c;
      goto LAB_00537c80;
    }
    if (local_28 == (byte *)0x0) {
      if (local_34 == (byte *)param_1[0xb]) {
        pbVar2 = (byte *)param_1[0xc];
        pbVar7 = (byte *)param_1[10];
        if (pbVar2 != pbVar7) {
          if (pbVar7 < pbVar2) {
            local_28 = pbVar2 + (-1 - (int)pbVar7);
          }
          else {
            local_28 = (byte *)param_1[0xb] + -(int)pbVar7;
          }
          local_34 = pbVar7;
          if (local_28 != (byte *)0x0) goto LAB_00537374;
        }
      }
      param_1[0xd] = (uint)local_34;
      uVar4 = FUN_0053a660(param_3);
      local_34 = (byte *)param_1[0xd];
      pbVar2 = (byte *)param_1[0xc];
      if (local_34 < pbVar2) {
        local_28 = pbVar2 + (-1 - (int)local_34);
      }
      else {
        local_28 = (byte *)(param_1[0xb] - (int)local_34);
      }
      pbStack_24 = (byte *)param_1[0xb];
      if ((local_34 == pbStack_24) && (pbVar7 = (byte *)param_1[10], pbVar2 != pbVar7)) {
        local_34 = pbVar7;
        if (pbVar7 < pbVar2) {
          local_28 = pbVar2 + (-1 - (int)pbVar7);
        }
        else {
          local_28 = pbStack_24 + -(int)pbVar7;
        }
      }
      if (local_28 == (byte *)0x0) {
        param_1[8] = local_30;
        param_1[7] = (uint)pbVar8;
        iVar6 = *piVar1;
        piVar1[1] = (int)local_38;
        *piVar1 = (int)local_3c;
        piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
        param_1[0xd] = (uint)local_34;
        FUN_0053a660(uVar4);
        return;
      }
    }
LAB_00537374:
    param_3 = (byte *)0x0;
    pbVar2 = (byte *)param_1[1];
    if (local_38 < (byte *)param_1[1]) {
      pbVar2 = local_38;
    }
    if (local_28 < pbVar2) {
      pbVar2 = local_28;
    }
    pbVar7 = local_3c;
    pbVar9 = local_34;
    for (uVar10 = (uint)pbVar2 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pbVar9 = *(undefined4 *)pbVar7;
      pbVar7 = pbVar7 + 4;
      pbVar9 = pbVar9 + 4;
    }
    local_28 = local_28 + -(int)pbVar2;
    for (uVar10 = (uint)pbVar2 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pbVar9 = *pbVar7;
      pbVar7 = pbVar7 + 1;
      pbVar9 = pbVar9 + 1;
    }
    local_3c = local_3c + (int)pbVar2;
    uVar10 = param_1[1];
    local_38 = local_38 + -(int)pbVar2;
    local_34 = local_34 + (int)pbVar2;
    param_1[1] = uVar10 - (int)pbVar2;
    if (uVar10 - (int)pbVar2 == 0) {
LAB_005373d9:
      *param_1 = -(uint)(param_1[6] != 0) & 7;
    }
    goto switchD_005371b9_default;
  case 3:
    for (; pbVar8 < (byte *)0xe; pbVar8 = pbVar8 + 8) {
      if (local_38 == (byte *)0x0) {
        param_1[8] = uVar10;
        param_1[7] = (uint)pbVar8;
        local_2c[1] = 0;
        goto LAB_005379b7;
      }
      local_38 = local_38 + -1;
      param_3 = (byte *)0x0;
      uVar10 = uVar10 | (uint)*local_3c << ((byte)pbVar8 & 0x1f);
      local_3c = local_3c + 1;
    }
    param_1[1] = uVar10 & 0x3fff;
    if (((uVar10 & 0x1f) < 0x1e) && (((uVar10 & 0x3fff) >> 5 & 0x1f) < 0x1e)) {
      uVar3 = (*(code *)local_2c[8])(4);
      param_1[3] = uVar3;
      if (uVar3 == 0) {
        param_1[8] = uVar10;
        param_1[7] = (uint)pbVar8;
        iVar6 = *piVar1;
        piVar1[1] = (int)local_38;
        *piVar1 = (int)local_3c;
        piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
        param_1[0xd] = (uint)local_34;
        FUN_0053a660(0xfffffffc);
        return;
      }
      uVar10 = uVar10 >> 0xe;
      pbVar8 = pbVar8 + -0xe;
      param_1[2] = 0;
      *param_1 = 4;
      goto LAB_0053748b;
    }
    *param_1 = 9;
    param_3 = (byte *)0xfffffffd;
    local_2c[6] = (int)s_too_many_length_or_distance_symb_005da8d0;
    param_1[8] = uVar10;
    goto LAB_00537c65;
  case 4:
LAB_0053748b:
    if (param_1[2] < (param_1[1] >> 10) + 4) {
      do {
        for (; pbVar8 < (byte *)0x3; pbVar8 = pbVar8 + 8) {
          if (local_38 == (byte *)0x0) {
            param_1[8] = uVar10;
            param_1[7] = (uint)pbVar8;
            iVar6 = *piVar1;
            *piVar1 = (int)local_3c;
            piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
            piVar1[1] = 0;
            param_1[0xd] = (uint)local_34;
            FUN_0053a660(param_3);
            return;
          }
          local_38 = local_38 + -1;
          param_3 = (byte *)0x0;
          uVar10 = uVar10 | (uint)*local_3c << ((byte)pbVar8 & 0x1f);
          local_3c = local_3c + 1;
        }
        uVar3 = uVar10 & 7;
        pbVar8 = pbVar8 + -3;
        uVar10 = uVar10 >> 3;
        *(uint *)(param_1[3] + *(int *)(&DAT_005b7c60 + param_1[2] * 4) * 4) = uVar3;
        uVar3 = param_1[2];
        param_1[2] = uVar3 + 1;
      } while (uVar3 + 1 < (param_1[1] >> 10) + 4);
    }
    uVar3 = param_1[2];
    while (uVar3 < 0x13) {
      *(undefined4 *)(param_1[3] + *(int *)(&DAT_005b7c60 + param_1[2] * 4) * 4) = 0;
      uVar3 = param_1[2] + 1;
      param_1[2] = uVar3;
    }
    param_1[4] = 7;
    local_28 = (byte *)FUN_00539f70(param_1 + 5,param_1[9],piVar1);
    if (local_28 != (byte *)0x0) {
      (*(code *)piVar1[9])();
      if (local_28 == (byte *)0xfffffffd) {
        *param_1 = 9;
      }
      param_1[8] = uVar10;
      param_1[7] = (uint)pbVar8;
      iVar6 = *piVar1;
      piVar1[1] = (int)local_38;
      *piVar1 = (int)local_3c;
      piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
      param_3 = local_28;
      goto LAB_00537c83;
    }
    param_1[2] = 0;
    *param_1 = 5;
    break;
  case 5:
    break;
  case 6:
    goto LAB_005377b9;
  case 7:
    goto LAB_00537bb4;
  case 8:
    goto LAB_00537c1b;
  case 9:
    param_3 = (byte *)0xfffffffd;
    goto LAB_00537c5a;
  default:
    param_3 = (byte *)0xfffffffe;
LAB_00537c5a:
    param_1[8] = local_30;
LAB_00537c65:
    param_1[7] = (uint)pbVar8;
    local_2c[1] = (int)local_38;
LAB_00537c73:
    iVar6 = (int)local_3c - *local_2c;
    *local_2c = (int)local_3c;
    goto LAB_00537c7b;
  }
  if (param_1[2] < (param_1[1] >> 5 & 0x1f) + 0x102 + (param_1[1] & 0x1f)) {
    do {
      pbVar2 = (byte *)param_1[4];
      pbVar7 = pbVar8;
      if (pbVar8 < pbVar2) {
        do {
          if (local_38 == (byte *)0x0) goto LAB_00537aa9;
          local_38 = local_38 + -1;
          pbVar8 = pbVar7 + 8;
          param_3 = (byte *)0x0;
          pbVar2 = (byte *)param_1[4];
          uVar10 = uVar10 | (uint)*local_3c << ((byte)pbVar7 & 0x1f);
          local_3c = local_3c + 1;
          pbVar7 = pbVar8;
        } while (pbVar8 < pbVar2);
      }
      iVar6 = param_1[5] + (*(uint *)(&DAT_005dbb90 + (int)pbVar2 * 4) & uVar10) * 8;
      bVar5 = *(byte *)(iVar6 + 1);
      local_28 = (byte *)(uint)bVar5;
      uStack_c = *(uint *)(iVar6 + 4);
      if (uStack_c < 0x10) {
        pbVar8 = pbVar8 + -(int)local_28;
        uVar10 = uVar10 >> (bVar5 & 0x1f);
        *(uint *)(param_1[3] + param_1[2] * 4) = uStack_c;
        param_1[2] = param_1[2] + 1;
      }
      else {
        if (uStack_c == 0x12) {
          pbStack_24 = (byte *)0x7;
        }
        else {
          pbStack_24 = (byte *)(uStack_c - 0xe);
        }
        local_30 = (uint)(uStack_c == 0x12) * 8 + 3;
        pbStack_10 = pbStack_24 + (int)local_28;
        for (pbVar7 = pbVar8; pbVar7 < pbStack_10; pbVar7 = pbVar7 + 8) {
          if (local_38 == (byte *)0x0) goto LAB_00537aa9;
          local_38 = local_38 + -1;
          param_3 = (byte *)0x0;
          uVar10 = uVar10 | (uint)*local_3c << ((byte)pbVar7 & 0x1f);
          local_3c = local_3c + 1;
        }
        uVar10 = uVar10 >> (bVar5 & 0x1f);
        local_30 = local_30 + (*(uint *)(&DAT_005dbb90 + (int)pbStack_24 * 4) & uVar10);
        uVar10 = uVar10 >> ((byte)pbStack_24 & 0x1f);
        pbVar8 = pbVar7 + -(int)(pbStack_24 + (int)local_28);
        uVar3 = param_1[2];
        if ((param_1[1] >> 5 & 0x1f) + 0x102 + (param_1[1] & 0x1f) < local_30 + uVar3) {
LAB_00537ad6:
          (*(code *)piVar1[9])();
          *param_1 = 9;
          piVar1[6] = (int)s_invalid_bit_length_repeat_005da8b4;
          param_1[8] = uVar10;
          param_1[7] = (uint)pbVar8;
          iVar6 = *piVar1;
          piVar1[1] = (int)local_38;
          *piVar1 = (int)local_3c;
          piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
          param_1[0xd] = (uint)local_34;
          FUN_0053a660(0xfffffffd);
          return;
        }
        if (uStack_c == 0x10) {
          if (uVar3 == 0) goto LAB_00537ad6;
          uVar4 = *(undefined4 *)((param_1[3] - 4) + uVar3 * 4);
        }
        else {
          uVar4 = 0;
        }
        do {
          uVar3 = uVar3 + 1;
          *(undefined4 *)((param_1[3] - 4) + uVar3 * 4) = uVar4;
          local_30 = local_30 - 1;
        } while (local_30 != 0);
        param_1[2] = uVar3;
        local_30 = 0;
      }
    } while (param_1[2] < (param_1[1] >> 5 & 0x1f) + 0x102 + (param_1[1] & 0x1f));
  }
  param_1[5] = 0;
  local_30 = 9;
  pbStack_24 = (byte *)0x6;
  local_28 = (byte *)FUN_0053a4d0(param_1[3],&local_30,&pbStack_24,&uStack_4,&uStack_8,param_1[9],
                                  piVar1);
  (*(code *)piVar1[9])();
  if (local_28 != (byte *)0x0) {
    if (local_28 == (byte *)0xfffffffd) {
      *param_1 = 9;
    }
    param_1[8] = uVar10;
    param_1[7] = (uint)pbVar8;
    iVar6 = *piVar1;
    piVar1[1] = (int)local_38;
    *piVar1 = (int)local_3c;
    piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
    param_1[0xd] = (uint)local_34;
    FUN_0053a660(local_28);
    return;
  }
  uVar3 = FUN_00539830(uStack_4,uStack_8,piVar1);
  if (uVar3 == 0) {
    param_1[8] = uVar10;
    param_1[7] = (uint)pbVar8;
    iVar6 = *piVar1;
    piVar1[1] = (int)local_38;
    *piVar1 = (int)local_3c;
    param_3 = (byte *)0xfffffffc;
    piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
    goto LAB_00537c83;
  }
  param_1[1] = uVar3;
  *param_1 = 6;
LAB_005377b9:
  param_1[8] = uVar10;
  param_1[7] = (uint)pbVar8;
  iVar6 = *piVar1;
  piVar1[1] = (int)local_38;
  *piVar1 = (int)local_3c;
  piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
  param_1[0xd] = (uint)local_34;
  param_3 = (byte *)FUN_00539870(param_3);
  if (param_3 != (byte *)0x1) {
LAB_0053787f:
    FUN_0053a660(param_3);
    return;
  }
  param_3 = (byte *)0x0;
  FUN_00539f60();
  local_38 = (byte *)piVar1[1];
  local_3c = (byte *)*piVar1;
  local_30 = param_1[8];
  pbVar8 = (byte *)param_1[7];
  local_34 = (byte *)param_1[0xd];
  if (local_34 < (byte *)param_1[0xc]) {
    local_28 = (byte *)param_1[0xc] + (-1 - (int)local_34);
  }
  else {
    local_28 = (byte *)(param_1[0xb] - (int)local_34);
  }
  if (param_1[6] != 0) {
    *param_1 = 7;
LAB_00537bb4:
    param_1[0xd] = (uint)local_34;
    uVar4 = FUN_0053a660(param_3);
    local_34 = (byte *)param_1[0xd];
    if ((byte *)param_1[0xc] != local_34) {
      param_1[7] = (uint)pbVar8;
      param_1[8] = local_30;
      iVar6 = *piVar1;
      piVar1[1] = (int)local_38;
      *piVar1 = (int)local_3c;
      piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
      param_1[0xd] = (uint)local_34;
      FUN_0053a660(uVar4);
      return;
    }
    *param_1 = 8;
LAB_00537c1b:
    param_1[8] = local_30;
    param_1[7] = (uint)pbVar8;
    iVar6 = *piVar1;
    piVar1[1] = (int)local_38;
    *piVar1 = (int)local_3c;
    piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
    param_1[0xd] = (uint)local_34;
    FUN_0053a660(1);
    return;
  }
  *param_1 = 0;
  goto switchD_005371b9_default;
LAB_00537aa9:
  param_1[8] = uVar10;
  param_1[7] = (uint)pbVar7;
  iVar6 = *piVar1;
  piVar1[1] = 0;
  *piVar1 = (int)local_3c;
  piVar1[2] = (int)(local_3c + (piVar1[2] - iVar6));
  goto LAB_00537c83;
code_r0x00537266:
  param_3 = (byte *)0x0;
  bVar5 = (byte)pbVar8;
  local_38 = local_38 + -1;
  pbVar8 = pbVar8 + 8;
  uVar10 = uVar10 | (uint)*local_3c << (bVar5 & 0x1f);
  local_3c = local_3c + 1;
  if ((byte *)0x1f < pbVar8) goto LAB_00537286;
  goto LAB_0053725c;
LAB_005371a5:
  param_1[6] = uVar10 & 1;
  switch((uVar10 & 7) >> 1) {
  case 0:
    *param_1 = 1;
    uVar3 = (uint)(pbVar8 + -3) & 7;
    local_30 = (uVar10 >> 3) >> (sbyte)uVar3;
    pbVar8 = pbVar8 + -3 + -uVar3;
    break;
  case 1:
    FUN_0053a630(auStack_1c,&uStack_20,local_2c);
    uVar3 = FUN_00539830(auStack_1c[0],uStack_20,local_2c);
    param_1[1] = uVar3;
    if (uVar3 == 0) {
      param_1[8] = uVar10;
      param_1[7] = (uint)pbVar8;
      iVar6 = *local_2c;
      local_2c[1] = (int)local_38;
      *local_2c = (int)local_3c;
      local_2c[2] = (int)(local_3c + (local_2c[2] - iVar6));
      param_1[0xd] = (uint)local_34;
      FUN_0053a660(0xfffffffc);
      return;
    }
    local_30 = uVar10 >> 3;
    pbVar8 = pbVar8 + -3;
    *param_1 = 6;
    break;
  case 2:
    local_30 = uVar10 >> 3;
    pbVar8 = pbVar8 + -3;
    *param_1 = 3;
    break;
  case 3:
    *param_1 = 9;
    local_2c[6] = (int)s_invalid_block_type_005da914;
    param_1[8] = uVar10 >> 3;
    param_1[7] = (uint)(pbVar8 + -3);
    local_2c[1] = (int)local_38;
    iVar6 = (int)local_3c - *local_2c;
    *local_2c = (int)local_3c;
    param_3 = (byte *)0xfffffffd;
LAB_00537c7b:
    pbVar8 = (byte *)(local_2c[2] + iVar6);
LAB_00537c80:
    local_2c[2] = (int)pbVar8;
LAB_00537c83:
    param_1[0xd] = (uint)local_34;
    FUN_0053a660(param_3);
    return;
  }
  goto switchD_005371b9_default;
}


