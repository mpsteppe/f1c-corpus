// Function: FUN_004ef2e0 @ 004ef2e0
// Size (bytes): 515


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ef2e0(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  bool bVar10;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined2 local_4;
  
  fVar2 = (float)_DAT_008afea0;
  fVar3 = fVar2 - *(float *)(param_1 + 0x1018);
  if (_DAT_0059e4e0 <= fVar3) {
    if (_DAT_0059e46c < fVar3) {
      *(float *)(param_1 + 0x1018) = fVar2;
      iVar1 = DAT_008aae64;
      if (DAT_0083ee60 < 0x3ff) {
        DAT_0083ee60 = DAT_0083ee60 + 1;
        DAT_008aae64 = DAT_008aae64 + 0x1b0;
      }
      puVar6 = (undefined4 *)FUN_004e2760();
      *(undefined4 *)(iVar1 + 8) = *puVar6;
      *(undefined4 *)(iVar1 + 0xc) = puVar6[1];
      *(undefined4 *)(iVar1 + 0x10) = puVar6[2];
      *(undefined4 *)(iVar1 + 0x14) = puVar6[3];
      *(undefined2 *)(iVar1 + 0x18) = *(undefined2 *)(puVar6 + 4);
      if ((*(char *)(iVar1 + 0xe) == '\0') && (*(int *)(iVar1 + 0x10) == 0)) {
        bVar4 = 1;
      }
      else {
        bVar4 = 0;
      }
      FUN_004b33b0(2,2,(-(uint)bVar4 & 0xfffffff4) + 0x12,*(undefined4 *)(param_1 + 4),
                   (float)_DAT_008afea0,0);
      return;
    }
    local_14 = *(undefined4 *)(param_1 + 0x101c);
    local_10 = *(undefined4 *)(param_1 + 0x1020);
    local_c = *(undefined4 *)(param_1 + 0x1024);
    local_8 = *(undefined4 *)(param_1 + 0x1028);
    local_4 = *(undefined2 *)(param_1 + 0x102c);
    puVar6 = (undefined4 *)FUN_004e2760();
    local_24 = puVar6[1];
    iVar1 = puVar6[2];
    local_28 = *puVar6;
    uVar5 = local_24;
    local_1c = puVar6[3];
    iVar7 = 9;
    bVar10 = true;
    local_20 = iVar1;
    local_18 = *(undefined2 *)(puVar6 + 4);
    psVar8 = (short *)&local_14;
    psVar9 = (short *)&local_28;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar10 = *psVar8 == *psVar9;
      psVar8 = psVar8 + 1;
      psVar9 = psVar9 + 1;
    } while (bVar10);
    if (!bVar10) {
      *(float *)(param_1 + 0x1018) = fVar2;
      iVar7 = DAT_008aae64;
      if (DAT_0083ee60 < 0x3ff) {
        DAT_0083ee60 = DAT_0083ee60 + 1;
        DAT_008aae64 = DAT_008aae64 + 0x1b0;
      }
      local_24._2_1_ = (char)((uint)local_24 >> 0x10);
      if ((local_24._2_1_ == '\0') && (iVar1 == 0)) {
        bVar4 = 1;
      }
      else {
        bVar4 = 0;
      }
      local_24 = uVar5;
      FUN_004b33b0(2,2,(-(uint)bVar4 & 0xfffffff4) + 0x12,*(undefined4 *)(param_1 + 4),
                   (float)_DAT_008afea0,0);
      *(undefined4 *)(iVar7 + 8) = local_28;
      *(undefined4 *)(iVar7 + 0xc) = local_24;
      *(int *)(iVar7 + 0x10) = iVar1;
      *(undefined4 *)(iVar7 + 0x14) = local_1c;
      *(undefined2 *)(iVar7 + 0x18) = local_18;
      return;
    }
  }
  return;
}


