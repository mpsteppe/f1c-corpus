// Function: FUN_00539870 @ 00539870
// Strings:  [invalid literal/length code, invalid distance code]


void __fastcall FUN_00539870(int param_1,int *param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  byte *pbVar9;
  uint local_18;
  uint local_10;
  undefined1 *local_c;
  byte *local_8;
  undefined1 *local_4;
  
  local_10 = param_2[1];
  local_18 = *(uint *)(param_1 + 0x20);
  piVar2 = *(int **)(param_1 + 4);
  pbVar9 = (byte *)*param_2;
  uVar8 = *(uint *)(param_1 + 0x1c);
  puVar7 = *(undefined1 **)(param_1 + 0x34);
  if (puVar7 < *(undefined1 **)(param_1 + 0x30)) {
    local_c = *(undefined1 **)(param_1 + 0x30) + (-1 - (int)puVar7);
  }
  else {
    local_c = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar7);
  }
  do {
    puVar6 = puVar7;
    switch(*piVar2) {
    case 0:
      if (((undefined1 *)0x101 < local_c) && (9 < local_10)) {
        *(uint *)(param_1 + 0x20) = local_18;
        *(uint *)(param_1 + 0x1c) = uVar8;
        iVar5 = *param_2;
        param_2[1] = local_10;
        *param_2 = (int)pbVar9;
        param_2[2] = (int)(pbVar9 + (param_2[2] - iVar5));
        *(undefined1 **)(param_1 + 0x34) = puVar7;
        param_3 = FUN_0053a7b0(*(undefined4 *)((int)piVar2 + 0x12),
                               *(undefined4 *)((int)piVar2 + 0x16),param_1,param_2);
        local_10 = param_2[1];
        local_18 = *(uint *)(param_1 + 0x20);
        pbVar9 = (byte *)*param_2;
        uVar8 = *(uint *)(param_1 + 0x1c);
        puVar7 = *(undefined1 **)(param_1 + 0x34);
        if (puVar7 < *(undefined1 **)(param_1 + 0x30)) {
          local_c = *(undefined1 **)(param_1 + 0x30) + (-1 - (int)puVar7);
        }
        else {
          local_c = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar7);
        }
        if (param_3 != 0) {
          *piVar2 = (uint)(param_3 != 1) * 2 + 7;
          break;
        }
      }
      *piVar2 = 1;
      piVar2[3] = (uint)*(byte *)(piVar2 + 4);
      piVar2[2] = *(int *)((int)piVar2 + 0x12);
    case 1:
      for (; uVar8 < (uint)piVar2[3]; uVar8 = uVar8 + 8) {
        if (local_10 == 0) {
LAB_00539e1d:
          *(uint *)(param_1 + 0x1c) = uVar8;
          *(uint *)(param_1 + 0x20) = local_18;
          iVar5 = *param_2;
          param_2[1] = 0;
          *param_2 = (int)pbVar9;
          param_2[2] = (int)(pbVar9 + (param_2[2] - iVar5));
          *(undefined1 **)(param_1 + 0x34) = puVar7;
          FUN_0053a660(param_3);
          return;
        }
        local_10 = local_10 - 1;
        param_3 = 0;
        local_18 = local_18 | (uint)*pbVar9 << ((byte)uVar8 & 0x1f);
        pbVar9 = pbVar9 + 1;
      }
      local_8 = (byte *)(piVar2[2] + (*(uint *)(&DAT_005dbb90 + piVar2[3] * 4) & local_18) * 8);
      local_18 = local_18 >> (local_8[1] & 0x1f);
      uVar8 = uVar8 - local_8[1];
      bVar1 = *local_8;
      uVar4 = (uint)bVar1;
      if (uVar4 == 0) {
        piVar2[2] = *(int *)(local_8 + 4);
        *piVar2 = 6;
      }
      else if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) == 0) {
LAB_00539a3a:
          piVar2[3] = uVar4;
          piVar2[2] = (int)(local_8 + *(int *)(local_8 + 4) * 8);
        }
        else {
          if ((bVar1 & 0x20) == 0) {
            *piVar2 = 9;
            param_2[6] = (int)s_invalid_literal_length_code_005da964;
            param_3 = 0xfffffffd;
            goto LAB_00539efc;
          }
          *piVar2 = 7;
        }
      }
      else {
        piVar2[2] = bVar1 & 0xf;
        iVar5 = *(int *)(local_8 + 4);
        *piVar2 = 2;
        piVar2[1] = iVar5;
      }
      break;
    case 2:
      uVar4 = piVar2[2];
      for (; uVar8 < uVar4; uVar8 = uVar8 + 8) {
        if (local_10 == 0) goto LAB_00539e1d;
        local_10 = local_10 - 1;
        param_3 = 0;
        local_18 = local_18 | (uint)*pbVar9 << ((byte)uVar8 & 0x1f);
        pbVar9 = pbVar9 + 1;
      }
      piVar2[1] = piVar2[1] + (*(uint *)(&DAT_005dbb90 + uVar4 * 4) & local_18);
      local_18 = local_18 >> ((byte)uVar4 & 0x1f);
      uVar8 = uVar8 - uVar4;
      *piVar2 = 3;
      piVar2[3] = (uint)*(byte *)((int)piVar2 + 0x11);
      piVar2[2] = *(int *)((int)piVar2 + 0x16);
    case 3:
      for (; uVar8 < (uint)piVar2[3]; uVar8 = uVar8 + 8) {
        if (local_10 == 0) goto LAB_00539e1d;
        local_10 = local_10 - 1;
        param_3 = 0;
        local_18 = local_18 | (uint)*pbVar9 << ((byte)uVar8 & 0x1f);
        pbVar9 = pbVar9 + 1;
      }
      local_8 = (byte *)(piVar2[2] + (*(uint *)(&DAT_005dbb90 + piVar2[3] * 4) & local_18) * 8);
      local_18 = local_18 >> (local_8[1] & 0x1f);
      uVar8 = uVar8 - local_8[1];
      bVar1 = *local_8;
      uVar4 = (uint)bVar1;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) == 0) goto LAB_00539a3a;
        param_3 = 0xfffffffd;
        *piVar2 = 9;
        param_2[6] = (int)s_invalid_distance_code_005da980;
        goto LAB_00539efc;
      }
      piVar2[2] = bVar1 & 0xf;
      iVar5 = *(int *)(local_8 + 4);
      *piVar2 = 4;
      piVar2[3] = iVar5;
      break;
    case 4:
      uVar4 = piVar2[2];
      for (; uVar8 < uVar4; uVar8 = uVar8 + 8) {
        if (local_10 == 0) goto LAB_00539e1d;
        local_10 = local_10 - 1;
        param_3 = 0;
        local_18 = local_18 | (uint)*pbVar9 << ((byte)uVar8 & 0x1f);
        pbVar9 = pbVar9 + 1;
      }
      piVar2[3] = piVar2[3] + (*(uint *)(&DAT_005dbb90 + uVar4 * 4) & local_18);
      local_18 = local_18 >> ((byte)uVar4 & 0x1f);
      uVar8 = uVar8 - uVar4;
      *piVar2 = 5;
    case 5:
      if ((uint)((int)puVar7 - *(int *)(param_1 + 0x28)) < (uint)piVar2[3]) {
        iVar5 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) - piVar2[3];
      }
      else {
        iVar5 = -piVar2[3];
      }
      local_4 = puVar7 + iVar5;
      iVar5 = piVar2[1];
      while (iVar5 != 0) {
        puVar6 = puVar7;
        if (local_c == (undefined1 *)0x0) {
          if (puVar7 == *(undefined1 **)(param_1 + 0x2c)) {
            local_c = *(undefined1 **)(param_1 + 0x30);
            puVar6 = *(undefined1 **)(param_1 + 0x28);
            if (local_c != puVar6) {
              if (puVar6 < local_c) {
                local_c = local_c + (-1 - (int)puVar6);
              }
              else {
                local_c = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar6;
              }
              puVar7 = puVar6;
              if (local_c != (undefined1 *)0x0) goto LAB_00539d03;
            }
          }
          *(undefined1 **)(param_1 + 0x34) = puVar7;
          param_3 = FUN_0053a660(param_3);
          puVar6 = *(undefined1 **)(param_1 + 0x34);
          puVar7 = *(undefined1 **)(param_1 + 0x30);
          if (puVar6 < puVar7) {
            local_c = puVar7 + (-1 - (int)puVar6);
          }
          else {
            local_c = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar6);
          }
          if ((puVar6 == *(undefined1 **)(param_1 + 0x2c)) &&
             (puVar3 = *(undefined1 **)(param_1 + 0x28), puVar7 != puVar3)) {
            puVar6 = puVar3;
            if (puVar3 < puVar7) {
              local_c = puVar7 + (-1 - (int)puVar3);
            }
            else {
              local_c = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar3;
            }
          }
          if (local_c == (undefined1 *)0x0) goto LAB_00539e59;
        }
LAB_00539d03:
        puVar7 = puVar6 + 1;
        param_3 = 0;
        *puVar6 = *local_4;
        local_4 = local_4 + 1;
        local_c = local_c + -1;
        if (local_4 == *(undefined1 **)(param_1 + 0x2c)) {
          local_4 = *(undefined1 **)(param_1 + 0x28);
        }
        iVar5 = piVar2[1] + -1;
        piVar2[1] = iVar5;
      }
      *piVar2 = 0;
      break;
    case 6:
      if (local_c != (undefined1 *)0x0) goto LAB_00539deb;
      if (puVar7 == *(undefined1 **)(param_1 + 0x2c)) {
        local_c = *(undefined1 **)(param_1 + 0x30);
        puVar6 = *(undefined1 **)(param_1 + 0x28);
        if (local_c != puVar6) {
          if (puVar6 < local_c) {
            local_c = local_c + (-1 - (int)puVar6);
          }
          else {
            local_c = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar6;
          }
          puVar7 = puVar6;
          if (local_c != (undefined1 *)0x0) goto LAB_00539deb;
        }
      }
      *(undefined1 **)(param_1 + 0x34) = puVar7;
      param_3 = FUN_0053a660(param_3);
      puVar6 = *(undefined1 **)(param_1 + 0x34);
      puVar7 = *(undefined1 **)(param_1 + 0x30);
      if (puVar6 < puVar7) {
        local_c = puVar7 + (-1 - (int)puVar6);
      }
      else {
        local_c = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar6);
      }
      if ((puVar6 == *(undefined1 **)(param_1 + 0x2c)) &&
         (puVar3 = *(undefined1 **)(param_1 + 0x28), puVar7 != puVar3)) {
        puVar6 = puVar3;
        if (puVar3 < puVar7) {
          local_c = puVar7 + (-1 - (int)puVar3);
        }
        else {
          local_c = *(undefined1 **)(param_1 + 0x2c) + -(int)puVar3;
        }
      }
      if (local_c == (undefined1 *)0x0) {
LAB_00539e59:
        *(uint *)(param_1 + 0x20) = local_18;
        *(uint *)(param_1 + 0x1c) = uVar8;
        param_2[1] = local_10;
        param_2[2] = (int)(pbVar9 + (param_2[2] - *param_2));
        goto LAB_00539f16;
      }
LAB_00539deb:
      param_3 = 0;
      *puVar6 = (char)piVar2[2];
      puVar7 = puVar6 + 1;
      local_c = local_c + -1;
      *piVar2 = 0;
      break;
    case 7:
      if (7 < uVar8) {
        uVar8 = uVar8 - 8;
        local_10 = local_10 + 1;
        pbVar9 = pbVar9 + -1;
      }
      *(undefined1 **)(param_1 + 0x34) = puVar7;
      param_3 = FUN_0053a660(param_3);
      puVar7 = *(undefined1 **)(param_1 + 0x34);
      if (*(undefined1 **)(param_1 + 0x30) == puVar7) {
        *piVar2 = 8;
switchD_005398b8_caseD_8:
        param_3 = 1;
LAB_00539efc:
        *(uint *)(param_1 + 0x1c) = uVar8;
        *(uint *)(param_1 + 0x20) = local_18;
        param_2[1] = local_10;
        iVar5 = (int)pbVar9 - *param_2;
      }
      else {
        *(uint *)(param_1 + 0x1c) = uVar8;
        *(uint *)(param_1 + 0x20) = local_18;
        param_2[1] = local_10;
        iVar5 = (int)pbVar9 - *param_2;
      }
      param_2[2] = param_2[2] + iVar5;
      puVar6 = puVar7;
LAB_00539f16:
      *param_2 = (int)pbVar9;
      *(undefined1 **)(param_1 + 0x34) = puVar6;
      FUN_0053a660(param_3);
      return;
    case 8:
      goto switchD_005398b8_caseD_8;
    case 9:
      *(uint *)(param_1 + 0x20) = local_18;
      *(uint *)(param_1 + 0x1c) = uVar8;
      param_2[1] = local_10;
      param_3 = 0xfffffffd;
      param_2[2] = (int)(pbVar9 + (param_2[2] - *param_2));
      goto LAB_00539f16;
    default:
      param_3 = 0xfffffffe;
      goto LAB_00539efc;
    }
  } while( true );
}


