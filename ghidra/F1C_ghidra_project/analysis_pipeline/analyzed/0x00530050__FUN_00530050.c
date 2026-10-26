// Function: FUN_00530050 @ 00530050
// Size (bytes): 678


void __thiscall
FUN_00530050(int param_1,char *param_2,int param_3,int param_4,int param_5,undefined2 *param_6)

{
  float fVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int local_10;
  int local_c;
  float *local_8;
  
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x24b8)) {
    local_8 = (float *)(param_3 + 0x100);
    do {
      local_10 = 0;
      uVar2 = *param_6;
      pfVar12 = local_8;
      if (0 < *(int *)(param_1 + 0x24cc)) {
        do {
          iVar10 = (int)*param_2;
          param_2 = param_2 + 1;
          if (iVar10 == 0) {
            pfVar12[0x40] = 0.0;
            *pfVar12 = 0.0;
            pfVar12[-0x40] = 0.0;
          }
          else {
            iVar11 = (int)(short)param_6[iVar10 * 2];
            iVar7 = (int)(short)param_6[iVar10 * 2 + 1];
            iVar8 = (int)*(char *)(param_4 + param_5);
            cVar6 = (char)param_6[iVar10 * 2];
            if (iVar7 < 0) {
              fVar1 = *(float *)(&DAT_005b10a4 + (iVar8 + iVar11 * 0x40) * 4);
              uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
              uVar4 = *(undefined4 *)(param_1 + 0x24a8);
              uVar5 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
              *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar11;
              pfVar12[-0x40] =
                   (float)(int)(((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                                 uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) +
                               iVar7) * fVar1;
              uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
              uVar4 = *(undefined4 *)(param_1 + 0x24a8);
              uVar5 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
              *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar11;
              *pfVar12 = (float)(int)(((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 |
                                        (uVar3 & 0xff00) << 8 | uVar3 << 0x18) >>
                                       (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) + iVar7) *
                         fVar1;
              uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
              uVar4 = *(undefined4 *)(param_1 + 0x24a8);
              uVar5 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
              *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar11;
              param_4 = param_4 + 3;
              pfVar12[0x40] =
                   (float)(int)(((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                                 uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) +
                               iVar7) * fVar1;
            }
            else {
              uVar3 = *(uint *)(*(int *)(param_1 + 0x24a4) + (*(int *)(param_1 + 0x24a8) >> 3));
              uVar4 = *(undefined4 *)(param_1 + 0x24a8);
              uVar5 = *(uint *)(&DAT_005b4788 + iVar11 * 4);
              *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar11;
              pbVar9 = (byte *)(*(int *)(&DAT_005da738 + iVar7 * 4) +
                               ((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                                uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) * 3
                               );
              pfVar12[-0x40] = *(float *)(&DAT_005b10a4 + ((uint)*pbVar9 * 0x40 + iVar8) * 4);
              *pfVar12 = *(float *)(&DAT_005b10a4 + ((uint)pbVar9[1] * 0x40 + iVar8) * 4);
              pfVar12[0x40] = *(float *)(&DAT_005b10a4 + ((uint)pbVar9[2] * 0x40 + iVar8) * 4);
              param_4 = param_4 + 3;
            }
          }
          local_10 = local_10 + 1;
          pfVar12 = pfVar12 + 0x20;
        } while (local_10 < *(int *)(param_1 + 0x24cc));
      }
      local_c = local_c + 1;
      local_8 = local_8 + 1;
      param_6 = param_6 + (1 << ((byte)uVar2 & 0x1f)) * 2;
    } while (local_c < *(int *)(param_1 + 0x24b8));
  }
                    /* WARNING: Could not recover jumptable at 0x005302ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_LAB_0053073c)[*(int *)(param_1 + 0x24b8)])();
  return;
}


