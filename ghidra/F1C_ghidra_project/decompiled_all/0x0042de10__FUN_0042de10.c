// Function: FUN_0042de10 @ 0042de10
// Strings:  [bevel, [FINAL_DRIVE], [FINAL_DRIVE], ratio, ratio, ratio, ratio, [GEAR_RATIOS]]


void __thiscall FUN_0042de10(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 local_320 [4];
  undefined1 local_31c [388];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  puVar5 = local_180;
  for (iVar4 = 0x60; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  FUN_0042ddd0();
  iVar4 = FUN_00587db0(param_2,&DAT_005c36f0);
  if (iVar4 != 0) {
    iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
    while (iVar1 != 0) {
      iVar1 = FUN_005651b0();
      if (iVar1 == 0) {
        iVar1 = FUN_00587c20(local_180,s__GEAR_RATIOS__005c36e0);
        if (iVar1 == 0) {
          iVar1 = FUN_00587c20(local_180,s__FINAL_DRIVE__005c36c8);
          if (iVar1 != 0) {
            param_1[2] = 0;
            iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
            while (((iVar1 != 0 && (iVar1 = FUN_005651b0(), iVar1 != 1)) && (iVar1 != 4))) {
              if ((iVar1 == 0) &&
                 (iVar1 = FUN_00565760(s_ratio_005c36d8,local_320,local_31c,0,0), iVar1 != 0)) {
                param_1[2] = param_1[2] + 1;
              }
              iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
            }
          }
        }
        else {
          *param_1 = 0;
          iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
          while (((iVar1 != 0 && (iVar1 = FUN_005651b0(), iVar1 != 1)) && (iVar1 != 4))) {
            if ((iVar1 == 0) &&
               (iVar1 = FUN_00565760(s_ratio_005c36d8,local_320,local_31c,0,0), iVar1 != 0)) {
              *param_1 = *param_1 + 1;
            }
            iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
          }
        }
      }
      iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
    }
    pvVar2 = operator_new(*param_1 << 3);
    param_1[1] = (int)pvVar2;
    pvVar2 = operator_new(param_1[2] << 3);
    param_1[3] = (int)pvVar2;
    FUN_00587f64(iVar4,0,0);
    iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
    while (iVar1 != 0) {
      iVar1 = FUN_005651b0();
      if (iVar1 == 0) {
        iVar1 = FUN_00587c20(local_180,s__GEAR_RATIOS__005c36e0);
        if (iVar1 == 0) {
          iVar1 = FUN_00587c20(local_180,s__FINAL_DRIVE__005c36c8);
          if (iVar1 == 0) goto LAB_0042e181;
          iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
          if (iVar1 != 0) {
            iVar1 = 0;
            do {
              iVar3 = FUN_005651b0();
              if ((iVar3 == 1) || (iVar3 == 4)) break;
              if (iVar3 == 0) {
                FUN_00565760(s_bevel_005c36c0,param_1 + 4,param_1 + 5,0,0);
                iVar3 = FUN_00565760(s_ratio_005c36d8,param_1[3] + iVar1,param_1[3] + iVar1 + 4,0,0)
                ;
                if (iVar3 != 0) {
                  iVar1 = iVar1 + 8;
                }
              }
              iVar3 = FUN_00587ca0(local_180,0x180,iVar4);
            } while (iVar3 != 0);
          }
          iVar1 = param_1[2];
          iVar3 = param_1[3];
        }
        else {
          iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
          if (iVar1 != 0) {
            iVar1 = 0;
            do {
              iVar3 = FUN_005651b0();
              if ((iVar3 == 1) || (iVar3 == 4)) break;
              if ((iVar3 == 0) &&
                 (iVar3 = FUN_00565760(s_ratio_005c36d8,param_1[1] + iVar1,param_1[1] + iVar1 + 4,0,
                                       0), iVar3 != 0)) {
                iVar1 = iVar1 + 8;
              }
              iVar3 = FUN_00587ca0(local_180,0x180,iVar4);
            } while (iVar3 != 0);
          }
          iVar1 = *param_1;
          iVar3 = param_1[1];
        }
        FUN_005890aa(iVar3,iVar1,8,&LAB_0042dc20);
      }
LAB_0042e181:
      iVar1 = FUN_00587ca0(local_180,0x180,iVar4);
    }
    FUN_00587d02(iVar4);
  }
  return;
}


