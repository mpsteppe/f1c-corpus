// Function: FUN_00493990 @ 00493990
// Strings:  [SURFACE, POS-W-H, LOCATION, SUBANIMFRAME, ANIMRULE, ANIMDELTA]


undefined4 __thiscall FUN_00493990(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  float10 fVar9;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  undefined4 local_11c;
  int local_118;
  undefined4 local_114;
  int local_110;
  undefined4 local_10c;
  float local_108;
  undefined4 local_104;
  undefined1 local_100;
  undefined4 local_ff;
  undefined1 local_80 [128];
  
  local_100 = DAT_005ea438;
  puVar8 = &local_ff;
  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  uVar5 = 0;
  uVar7 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  uVar6 = 0;
  local_10c = 0;
  local_118 = 0;
  local_108 = 0.0;
  local_104 = 0;
  local_110 = 0;
  local_128 = 0;
  local_124 = 0;
  local_114 = 0;
  local_11c = 0;
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
  bVar2 = false;
  bVar3 = false;
  bVar1 = false;
  local_120 = param_1;
  iVar4 = FUN_00491fb0();
  if (iVar4 != 0) {
    do {
      iVar4 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4);
      if (iVar4 == 0) {
        iVar4 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f8);
        if (iVar4 != 0) {
          local_118 = local_118 + 1;
          goto LAB_00493bdd;
        }
        iVar4 = FUN_00565870(s_LOCATION_005cc694,&local_128,&local_124,&local_114,&local_11c,0,0,0,0
                            );
        if (iVar4 == 0) {
          iVar4 = FUN_00565870(s_POS_W_H_005cc68c,&local_128,&local_124,&local_114,&local_11c,0,0,0,
                               0);
          if (iVar4 == 0) {
            iVar4 = FUN_005654a0(s_SURFACE_005cc678,local_80);
            if (iVar4 == 0) {
              iVar4 = FUN_005654a0(s_ANIMDELTA_005cc92c,&local_100);
              if (iVar4 == 0) {
                iVar4 = FUN_005654a0(s_ANIMRULE_005cc920,&local_100);
                if (iVar4 == 0) {
                  iVar4 = FUN_005654a0(s_SUBANIMFRAME_005cc910,&local_100);
                  if ((iVar4 != 0) && (bVar1)) {
                    FUN_00493990(param_2,local_110);
                  }
                }
                else {
                  local_104 = FUN_00587ece(&local_100);
                }
              }
              else {
                fVar9 = (float10)FUN_0058850f(&local_100);
                local_108 = (float)fVar9;
              }
            }
            else {
              bVar3 = true;
            }
            goto LAB_00493bdd;
          }
          uVar7 = __ftol();
          uVar6 = __ftol();
          uVar5 = __ftol();
          local_10c = __ftol();
          bVar2 = true;
        }
        else {
          uVar7 = __ftol();
          uVar6 = __ftol();
          uVar5 = __ftol();
          local_10c = __ftol();
          bVar2 = true;
        }
LAB_00493be5:
        if ((bVar3) && (!bVar1)) {
          local_110 = FUN_00499f70(uVar7,uVar6,uVar5,local_10c,local_80,0,1,param_3);
          bVar1 = true;
        }
      }
      else {
        local_118 = local_118 + -1;
        if (local_118 < 1) break;
LAB_00493bdd:
        if (bVar2) goto LAB_00493be5;
      }
      iVar4 = FUN_00491fb0();
    } while (iVar4 != 0);
    if (local_110 != 0) {
      if (DAT_0059e440 < local_108) {
        *(float *)(local_110 + 0x18) = local_108;
      }
      *(undefined4 *)(local_110 + 0x1c) = local_104;
    }
  }
  *(int *)(local_120 + 0x194) = *(int *)(local_120 + 0x194) + -1;
  return 0;
}


