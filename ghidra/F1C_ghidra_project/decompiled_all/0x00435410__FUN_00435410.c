// Function: FUN_00435410 @ 00435410
// Strings:  [SpringParams, SpringCollLen, SpringBody, SpringHead, SpringDir, FREEDAMPING, NORMAL, SLIDING]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00435410(int *param_1,int param_2,undefined4 param_3,int *param_4,int *param_5)

{
  double *pdVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  void *local_41c;
  double local_418;
  double local_410;
  double local_408;
  double local_400 [5];
  undefined1 local_3d8 [8];
  undefined1 local_3d0 [8];
  undefined1 local_3c8 [8];
  double local_3c0;
  double local_3b8;
  double local_3b0;
  double local_3a8;
  double local_3a0;
  double local_398;
  double local_390;
  double local_388;
  double local_380;
  double local_368;
  undefined1 local_360 [448];
  undefined4 local_1a0;
  undefined1 local_19c;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188 [97];
  
  FUN_004358f0();
  piVar6 = param_1;
  for (iVar3 = 6; piVar6 = piVar6 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = *param_4;
    param_4 = param_4 + 1;
  }
  piVar6 = param_1 + 0x13;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = *param_5;
    param_5 = param_5 + 1;
    piVar6 = piVar6 + 1;
  }
  *param_1 = param_2;
  if (param_2 != 0) {
    FUN_005668b0();
    cVar2 = FUN_00566b20(param_3,1);
    if (cVar2 != '\0') {
      puVar5 = local_188;
      for (iVar3 = 0x60; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      local_1a0 = 0;
      local_18c = 0;
      local_194 = 0;
      local_190 = 0;
      local_19c = 1;
      iVar3 = FUN_00566cc0(local_188,0x180);
      while (iVar3 != 0) {
        iVar3 = FUN_005651b0();
        if (iVar3 == 0) {
          iVar3 = FUN_00565aa0(s_HeadMass_005c412c,local_400,0,0,0);
          if (iVar3 != 0) {
            iVar3 = *param_1;
            *(double *)(iVar3 + 0xac) = local_400[0];
            *(double *)(iVar3 + 0xb4) = _DAT_0059e420 / local_400[0];
          }
          iVar3 = FUN_00565aa0(s_HeadInertia_005c4120,local_3d8,local_3d0,local_3c8,0);
          if (iVar3 != 0) {
            FUN_005697a0(local_3d8);
          }
          FUN_00565aa0(s_MinPos_005c4118,param_1 + 7,param_1 + 9,param_1 + 0xb,0);
          FUN_00565aa0(s_MaxPos_005c4110,param_1 + 0xd,param_1 + 0xf,param_1 + 0x11,0);
          pdVar1 = (double *)(param_1 + 0x19);
          iVar3 = FUN_00565aa0(s_MinOri_005c4108,pdVar1,param_1 + 0x1b,param_1 + 0x1d,0);
          if (iVar3 != 0) {
            *pdVar1 = *pdVar1 * _DAT_0059eae8;
            *(double *)(param_1 + 0x1b) = *(double *)(param_1 + 0x1b) * _DAT_0059eae8;
            *(double *)(param_1 + 0x1d) = *(double *)(param_1 + 0x1d) * _DAT_0059eae8;
          }
          pdVar1 = (double *)(param_1 + 0x1f);
          iVar3 = FUN_00565aa0(s_MaxOri_005c4100,pdVar1,param_1 + 0x21,param_1 + 0x23,0);
          if (iVar3 != 0) {
            *pdVar1 = *pdVar1 * _DAT_0059eae8;
            *(double *)(param_1 + 0x21) = *(double *)(param_1 + 0x21) * _DAT_0059eae8;
            *(double *)(param_1 + 0x23) = *(double *)(param_1 + 0x23) * _DAT_0059eae8;
          }
          iVar3 = FUN_00565520(s_Spring_005c40f8,local_360,0);
          if (iVar3 != 0) {
            iVar3 = param_1[0x25];
            if (iVar3 <= param_1[0x26]) {
              iVar7 = iVar3 + 3;
              param_1[0x25] = iVar7;
              local_41c = operator_new(iVar7 * 100);
              if (local_41c == (void *)0x0) {
                local_41c = (void *)0x0;
              }
              else if (-1 < iVar3 + 2) {
                do {
                  FUN_00435390();
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
              }
              iVar3 = 0;
              if (0 < param_1[0x26]) {
                iVar7 = 0;
                do {
                  puVar5 = (undefined4 *)(param_1[0x27] + iVar7);
                  puVar8 = (undefined4 *)(iVar7 + (int)local_41c);
                  for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar8 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar8 = puVar8 + 1;
                  }
                  iVar3 = iVar3 + 1;
                  iVar7 = iVar7 + 100;
                } while (iVar3 < param_1[0x26]);
              }
              if (param_1[0x27] != 0) {
                FUN_00587bcf(param_1[0x27]);
              }
              param_1[0x27] = (int)local_41c;
            }
            iVar3 = FUN_00588410(local_360,s_SLIDING_005c40f0);
            if (iVar3 == 0) {
              *(undefined4 *)(param_1[0x26] * 100 + param_1[0x27]) = 0;
            }
            else {
              iVar3 = FUN_00588410(local_360,s_NORMAL_005c40e8);
              if (iVar3 == 0) {
                *(undefined4 *)(param_1[0x26] * 100 + param_1[0x27]) = 1;
              }
              else {
                iVar3 = FUN_00588410(local_360,s_FREEDAMPING_005c40dc);
                if (iVar3 != 0) goto LAB_00435766;
                *(undefined4 *)(param_1[0x26] * 100 + param_1[0x27]) = 2;
              }
            }
            param_1[0x26] = param_1[0x26] + 1;
          }
LAB_00435766:
          iVar3 = param_1[0x26] + -1;
          if ((-1 < iVar3) && (iVar3 < param_1[0x25])) {
            iVar7 = iVar3 * 100 + param_1[0x27];
            FUN_00565aa0(s_SpringDir_005c40d0,iVar7 + 4,iVar7 + 0xc,iVar7 + 0x14,0);
            FUN_00565aa0(s_SpringHead_005c40c4,iVar7 + 0x1c,iVar7 + 0x24,iVar7 + 0x2c,0);
            iVar3 = FUN_00565aa0(s_SpringBody_005c40b8,&local_418,&local_410,&local_408,0);
            if (iVar3 != 0) {
              FUN_0056bd40(param_1 + 0x13);
              local_368 = local_380 * local_408 + local_388 * local_410 + local_390 * local_418;
              *(double *)(iVar7 + 0x34) =
                   local_3c0 * local_418 + local_3b0 * local_408 + local_3b8 * local_410 +
                   *(double *)(param_1 + 1);
              *(double *)(iVar7 + 0x3c) =
                   local_398 * local_408 + local_3a0 * local_410 + local_3a8 * local_418 +
                   *(double *)(param_1 + 3);
              *(double *)(iVar7 + 0x44) = local_368 + *(double *)(param_1 + 5);
            }
            FUN_00565aa0(s_SpringCollLen_005c40a8,iVar7 + 0x4c,0,0,0);
            FUN_00565aa0(s_SpringParams_005c4098,iVar7 + 0x54,iVar7 + 0x5c,0,0);
          }
        }
        iVar3 = FUN_00566cc0(local_188,0x180);
      }
    }
    FUN_005668d0();
  }
  return;
}


