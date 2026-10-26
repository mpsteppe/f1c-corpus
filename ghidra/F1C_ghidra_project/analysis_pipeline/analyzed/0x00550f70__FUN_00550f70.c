// Function: FUN_00550f70 @ 00550f70
// Size (bytes): 384


undefined4 __fastcall FUN_00550f70(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_8;
  int local_4;
  
  if ((*param_1 & 2) == 0) {
    if ((*param_1 & 1) == 0) {
      return 0;
    }
    local_8 = 0;
    if (0 < (int)param_1[3]) {
      local_4 = 0;
      do {
        iVar2 = *(int *)(local_4 + 0x28 + param_1[4]);
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + -4);
          if (-1 < iVar3 + -1) {
            do {
              FUN_005507d0();
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          FUN_00587bcf(iVar2 + -4);
        }
        local_8 = local_8 + 1;
        local_4 = local_4 + 0x2c;
      } while (local_8 < (int)param_1[3]);
    }
    uVar1 = param_1[4];
    if (uVar1 == 0) {
      return 0;
    }
    iVar3 = *(int *)(uVar1 - 4);
    iVar2 = uVar1 - 4;
    if (-1 < iVar3 + -1) {
      do {
        FUN_00557470();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  else {
    local_8 = 0;
    if (0 < (int)param_1[5]) {
      local_4 = 0;
      do {
        iVar2 = param_1[6] + local_4;
        iVar3 = 0;
        if (0 < *(int *)(param_1[6] + 4 + local_4)) {
          do {
            FUN_00587bcf(*(undefined4 *)(*(int *)(iVar2 + 8) + 4 + iVar3 * 8));
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(iVar2 + 4));
        }
        iVar2 = *(int *)(iVar2 + 8);
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + -4);
          if (-1 < iVar3 + -1) {
            do {
              FUN_00550810();
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          FUN_00587bcf(iVar2 + -4);
        }
        local_8 = local_8 + 1;
        local_4 = local_4 + 0xc;
      } while (local_8 < (int)param_1[5]);
    }
    uVar1 = param_1[6];
    if (uVar1 == 0) {
      return 0;
    }
    iVar3 = *(int *)(uVar1 - 4);
    iVar2 = uVar1 - 4;
    if (-1 < iVar3 + -1) {
      do {
        FUN_00550820();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      FUN_00587bcf(iVar2);
      return 0;
    }
  }
  FUN_00587bcf(iVar2);
  return 0;
}


