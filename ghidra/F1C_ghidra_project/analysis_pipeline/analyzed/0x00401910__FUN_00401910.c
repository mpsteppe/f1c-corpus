// Function: FUN_00401910 @ 00401910
// Size (bytes): 882


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00401910(int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float local_48;
  float local_40;
  float local_3c;
  int local_38;
  int local_34;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    iVar5 = 0;
    do {
      fVar1 = *(float *)(*(int *)(param_1 + 0x134) + 0x18 + iVar5);
      pfVar3 = (float *)(*(int *)(param_1 + 0x134) + iVar5);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x13c;
      pfVar3[0x25] = fVar1 * pfVar3[8] + *pfVar3;
      pfVar3[0x26] = fVar1 * pfVar3[9] + pfVar3[1];
      pfVar3[0x27] = fVar1 * pfVar3[10] + pfVar3[2];
    } while (iVar4 < *(int *)(param_1 + 0x130));
  }
  local_34 = 0;
  if (0 < *(int *)(param_1 + 0x130)) {
    local_38 = 0;
    do {
      iVar4 = *(int *)(param_1 + 0x134);
      iVar5 = *(int *)(iVar4 + 0x10c + local_38);
      iVar2 = *(int *)(iVar4 + 0x110 + local_38);
      pfVar3 = (float *)(iVar4 + local_38);
      if ((iVar5 != 0) && (iVar2 != 0)) {
        FUN_00401340(pfVar3);
        fVar6 = (float10)FUN_004e8ce0(pfVar3[0x1d],pfVar3 + 0x1e,pfVar3[0x1c],0x41800000);
        local_40 = (float)fVar6;
        FUN_00401340(iVar5);
        fVar6 = (float10)FUN_004e8ce0(*(undefined4 *)(iVar5 + 0x74),iVar5 + 0x78,
                                      *(undefined4 *)(iVar5 + 0x70),0x41800000);
        fVar1 = (float)fVar6;
        FUN_00401340(iVar2);
        fVar7 = (float10)FUN_004e8ce0(*(undefined4 *)(iVar2 + 0x74),iVar2 + 0x78,
                                      *(undefined4 *)(iVar2 + 0x70),0x41800000);
        fVar6 = fVar7;
        if ((float10)fVar1 < fVar7) {
          fVar6 = (float10)fVar1;
        }
        if ((fVar6 <= (float10)local_40) && (local_40 = fVar1, fVar7 <= (float10)fVar1)) {
          local_40 = (float)fVar7;
        }
        local_3c = pfVar3[6];
        local_48 = pfVar3[6] - _DAT_0059e44c;
        if (local_48 < pfVar3[6] + _DAT_0059e448) {
          do {
            pfVar3[0x25] = local_48 * pfVar3[8] + *pfVar3;
            pfVar3[0x26] = local_48 * pfVar3[9] + pfVar3[1];
            pfVar3[0x27] = local_48 * pfVar3[10] + pfVar3[2];
            FUN_00401340(pfVar3);
            fVar7 = (float10)FUN_004e8ce0(pfVar3[0x1d],pfVar3 + 0x1e,pfVar3[0x1c],0x41800000);
            FUN_00401340(iVar5);
            fVar6 = (float10)FUN_004e8ce0(*(undefined4 *)(iVar5 + 0x74),iVar5 + 0x78,
                                          *(undefined4 *)(iVar5 + 0x70),0x41800000);
            fVar1 = (float)fVar6;
            FUN_00401340(iVar2);
            fVar8 = (float10)FUN_004e8ce0(*(undefined4 *)(iVar2 + 0x74),iVar2 + 0x78,
                                          *(undefined4 *)(iVar2 + 0x70),0x41800000);
            fVar6 = fVar8;
            if ((float10)fVar1 < fVar8) {
              fVar6 = (float10)fVar1;
            }
            if (fVar6 <= (float10)(float)fVar7) {
              if ((float10)fVar1 < fVar8) {
                fVar8 = (float10)fVar1;
              }
            }
            else {
              fVar8 = (float10)(float)fVar7;
            }
            if ((float10)local_40 < fVar8) {
              local_40 = (float)fVar8;
              local_3c = local_48;
            }
            local_48 = local_48 + _DAT_0059e444;
          } while (local_48 < pfVar3[6] + _DAT_0059e448);
        }
        pfVar3[0x25] = local_3c * pfVar3[8] + *pfVar3;
        pfVar3[0x26] = local_3c * pfVar3[9] + pfVar3[1];
        pfVar3[0x27] = local_3c * pfVar3[10] + pfVar3[2];
      }
      local_34 = local_34 + 1;
      local_38 = local_38 + 0x13c;
    } while (local_34 < *(int *)(param_1 + 0x130));
  }
  return;
}


