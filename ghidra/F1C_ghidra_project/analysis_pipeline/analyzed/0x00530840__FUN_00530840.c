// Function: FUN_00530840 @ 00530840
// Size (bytes): 1124


void __thiscall
FUN_00530840(int param_1,int param_2,char *param_3,int param_4,char *param_5,undefined2 *param_6)

{
  byte *pbVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  int local_c;
  char *local_8;
  
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x24b8)) {
    puVar9 = (undefined2 *)(param_4 + 0x80);
    do {
      local_8 = param_3 + 1;
      uVar2 = *param_6;
      iVar7 = (int)*param_3;
      if (iVar7 == 0) {
        puVar9[0x40] = 0;
        *puVar9 = 0;
        puVar9[-0x40] = 0;
      }
      else {
        iVar10 = (int)(short)param_6[iVar7 * 2];
        iVar8 = (int)(short)param_6[iVar7 * 2 + 1];
        cVar6 = (char)param_6[iVar7 * 2];
        if (iVar8 < 0) {
          iVar7 = *(int *)(param_2 + (iVar10 * 0x40 + (int)*param_5) * 4);
          uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar4 = *(undefined4 *)(param_1 + 0x24a8);
          uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
          puVar9[-0x40] =
               (short)((int)((((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                               uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) +
                             iVar8) * iVar7) >> 0xc);
          uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar4 = *(undefined4 *)(param_1 + 0x24a8);
          uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
          *puVar9 = (short)((int)((((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8
                                    | uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) &
                                   uVar5) + iVar8) * iVar7) >> 0xc);
          uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar4 = *(undefined4 *)(param_1 + 0x24a8);
          uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
          iVar7 = (((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18
                    ) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) + iVar8) * iVar7;
LAB_00530a42:
          puVar9[0x40] = (short)(iVar7 >> 0xc);
        }
        else {
          iVar7 = (int)*param_5;
          uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
          uVar4 = *(undefined4 *)(param_1 + 0x24a8);
          uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
          *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
          pbVar1 = (byte *)(*(int *)(&DAT_005da738 + iVar8 * 4) +
                           ((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                            uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) * 3);
          if (*(int *)(&DAT_005da738 + iVar8 * 4) != 0) {
            puVar9[-0x40] = (short)(*(int *)(param_2 + ((uint)*pbVar1 * 0x40 + iVar7) * 4) >> 0xc);
            *puVar9 = (short)(*(int *)(param_2 + ((uint)pbVar1[1] * 0x40 + iVar7) * 4) >> 0xc);
            iVar7 = *(int *)(param_2 + ((uint)pbVar1[2] * 0x40 + iVar7) * 4);
            goto LAB_00530a42;
          }
        }
        param_5 = param_5 + 3;
      }
      if (*(int *)(param_1 + 0x24cc) == 2) {
        iVar7 = (int)*local_8;
        local_8 = param_3 + 2;
        if (iVar7 == 0) {
          puVar9[0x60] = 0;
          puVar9[0x20] = 0;
          puVar9[-0x20] = 0;
        }
        else {
          iVar10 = (int)(short)param_6[iVar7 * 2];
          iVar8 = (int)(short)param_6[iVar7 * 2 + 1];
          cVar6 = (char)param_6[iVar7 * 2];
          if (iVar8 < 0) {
            iVar7 = *(int *)(param_2 + (iVar10 * 0x40 + (int)*param_5) * 4);
            uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar4 = *(undefined4 *)(param_1 + 0x24a8);
            uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
            puVar9[-0x20] =
                 (short)((int)((((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                                 uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) +
                               iVar8) * iVar7) >> 0xc);
            uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar4 = *(undefined4 *)(param_1 + 0x24a8);
            uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
            puVar9[0x20] = (short)((int)((((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 |
                                            (uVar3 & 0xff00) << 8 | uVar3 << 0x18) >>
                                           (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) + iVar8) *
                                        iVar7) >> 0xc);
            uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar4 = *(undefined4 *)(param_1 + 0x24a8);
            uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
            iVar7 = (((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                      uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) + iVar8) *
                    iVar7;
LAB_00530c42:
            puVar9[0x60] = (short)(iVar7 >> 0xc);
          }
          else {
            iVar7 = (int)*param_5;
            uVar3 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
            uVar4 = *(undefined4 *)(param_1 + 0x24a8);
            uVar5 = *(uint *)(&DAT_005b4788 + iVar10 * 4);
            *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar10;
            pbVar1 = (byte *)(*(int *)(&DAT_005da738 + iVar8 * 4) +
                             ((uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                              uVar3 << 0x18) >> (-(((byte)uVar4 & 7) + cVar6) & 0x1f) & uVar5) * 3);
            if (*(int *)(&DAT_005da738 + iVar8 * 4) != 0) {
              puVar9[-0x20] = (short)(*(int *)(param_2 + ((uint)*pbVar1 * 0x40 + iVar7) * 4) >> 0xc)
              ;
              puVar9[0x20] = (short)(*(int *)(param_2 + ((uint)pbVar1[1] * 0x40 + iVar7) * 4) >> 0xc
                                    );
              iVar7 = *(int *)(param_2 + ((uint)pbVar1[2] * 0x40 + iVar7) * 4);
              goto LAB_00530c42;
            }
          }
          param_5 = param_5 + 3;
        }
      }
      local_c = local_c + 1;
      puVar9 = puVar9 + 1;
      param_6 = param_6 + (1 << ((byte)uVar2 & 0x1f)) * 2;
      param_3 = local_8;
    } while (local_c < *(int *)(param_1 + 0x24b8));
  }
                    /* WARNING: Could not recover jumptable at 0x00530c9d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_LAB_00531148)[*(int *)(param_1 + 0x24b8)])();
  return;
}


