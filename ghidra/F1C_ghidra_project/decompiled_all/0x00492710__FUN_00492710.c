// Function: FUN_00492710 @ 00492710
// Strings:  [GIZMO, SURFACE, LOCATION2, POS-W-H, LOCATION, ESCTARGET, ENTERTARGET]


undefined4 __fastcall FUN_00492710(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_1a0 [4];
  undefined1 local_19c [4];
  undefined1 local_198 [4];
  undefined1 local_194 [4];
  undefined1 local_190 [4];
  undefined1 local_18c [4];
  undefined1 local_188 [4];
  undefined1 local_184 [4];
  undefined1 local_180 [128];
  undefined1 local_100;
  undefined4 local_ff;
  undefined1 local_80 [128];
  
  local_100 = DAT_005ea438;
  puVar7 = &local_ff;
  for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  pvVar1 = operator_new(0x68);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004991e0(0);
  }
  FUN_00498e50(uVar2);
  *(undefined4 *)(param_1 + 0x1ac) = uVar2;
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
  iVar6 = FUN_00491fb0();
  while ((iVar6 != 0 && (iVar6 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4), iVar6 == 0))) {
    iVar6 = FUN_005654a0(&DAT_005cc650,&local_100);
    if (iVar6 == 0) {
      iVar6 = FUN_005654a0(s_ENTERTARGET_005cc6ac,local_180);
      if (iVar6 == 0) {
        iVar6 = FUN_005654a0(s_ESCTARGET_005cc6a0,local_180);
        if (iVar6 == 0) {
          iVar6 = FUN_00565870(s_LOCATION_005cc694,local_194,local_19c,local_1a0,local_198,0,0,0,0);
          if (iVar6 == 0) {
            iVar6 = FUN_00565870(s_POS_W_H_005cc68c,local_18c,local_190,local_184,local_188,0,0,0,0)
            ;
            if (iVar6 == 0) {
              iVar6 = FUN_00565870(s_LOCATION2_005cc680,local_194,local_19c,local_1a0,local_198,0,0,
                                   0,0);
              if (iVar6 == 0) {
                iVar6 = FUN_005654a0(s_SURFACE_005cc678,local_180);
                if (iVar6 == 0) {
                  iVar6 = FUN_005654a0(s_GIZMO_005cc5ac,local_80);
                  if ((iVar6 != 0) && (iVar6 = FUN_00492a40(local_80), iVar6 != 0)) {
                    FUN_00497590(iVar6,*(undefined4 *)(param_1 + 0x1a8),
                                 *(undefined4 *)(param_1 + 0x1ac));
                  }
                }
                else {
                  FUN_00497ad0(local_180,1);
                  uVar3 = 1;
                  uVar2 = FUN_00497ba0(local_180);
                  FUN_004992e0(uVar2,uVar3);
                }
              }
              else {
                uVar2 = __ftol();
                uVar3 = __ftol(uVar2);
                uVar4 = __ftol(uVar3);
                uVar5 = __ftol(uVar4);
                FUN_0049a9e0(uVar5,uVar4,uVar3,uVar2);
              }
            }
            else {
              uVar2 = __ftol();
              uVar3 = __ftol(uVar2);
              uVar4 = __ftol(uVar3);
              uVar5 = __ftol(uVar4);
              FUN_0049a9c0(uVar5,uVar4,uVar3,uVar2);
            }
          }
          else {
            uVar2 = __ftol();
            uVar3 = __ftol(uVar2);
            uVar4 = __ftol(uVar3);
            uVar5 = __ftol(uVar4);
            FUN_0049a9c0(uVar5,uVar4,uVar3,uVar2);
          }
        }
        else {
          FUN_00566650(local_180);
        }
      }
      else {
        FUN_00566650(local_180);
      }
    }
    else {
      if (((*(char *)(param_1 + 0x19a) != '\0') && (-1 < *(int *)(param_1 + 0x19c))) &&
         (*(int *)(param_1 + 0x19c) < 4)) {
        FUN_00493e20(&local_100);
      }
      FUN_0049ad50(&local_100);
    }
    iVar6 = FUN_00491fb0();
  }
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -1;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  return 0;
}


