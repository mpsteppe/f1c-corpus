// Function: FUN_0048a3c0 @ 0048a3c0
// Size (bytes): 628


/* WARNING: Removing unreachable block (ram,0x0048a5ee) */

void __thiscall FUN_0048a3c0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0x168);
  iVar2 = *(int *)(param_1 + 0x94);
  local_14 = -1;
  local_18 = 0;
  iVar9 = iVar2;
  iVar3 = local_18;
  do {
    if (iVar9 < 1) {
      if (*(int *)(param_1 + 0x90) == 0) {
        *(int *)(param_1 + 0x90) = iVar3;
        *(int *)(param_1 + 0x94) = iVar2;
        FUN_00489ab0(local_14,0);
      }
      return;
    }
    local_28 = FUN_004863c0(0);
    *(undefined4 *)(param_1 + 0x168) = 0;
    if (param_3 < 0) {
      uVar4 = FUN_00489920();
    }
    else {
      uVar4 = FUN_00489970(param_3);
    }
    FUN_00566650(uVar4);
    iVar8 = 0;
    local_2c = 0;
    local_24 = 0;
    local_20 = 0;
    if (0 < iVar9) {
      do {
        uVar4 = FUN_004863c0(local_20);
        *(int *)(param_1 + 0x168) = local_20;
        if (param_3 < 0) {
          iVar5 = FUN_00489920();
        }
        else {
          iVar5 = FUN_00489970(param_3);
        }
        if (iVar5 != 0) {
          switch(param_2) {
          case 0:
            iVar7 = FUN_00587ece(&DAT_005ea438);
            iVar6 = FUN_00587ece(iVar5);
            iVar8 = local_24;
            if (iVar6 < iVar7) {
LAB_0048a4bf:
              FUN_00566650(iVar5);
              local_2c = local_24;
              iVar8 = local_24;
              local_28 = uVar4;
            }
            break;
          case 1:
            iVar7 = FUN_00587ece(&DAT_005ea438);
            iVar6 = FUN_00587ece(iVar5);
            iVar8 = local_24;
            if (iVar7 < iVar6) goto LAB_0048a4bf;
            break;
          case 2:
            iVar7 = FUN_00588410(iVar5,&DAT_005ea438);
            if (iVar7 < 0) {
LAB_0048a586:
              FUN_00566650(iVar5);
              local_2c = iVar8;
              local_28 = uVar4;
            }
            break;
          case 3:
            iVar7 = FUN_00588410(iVar5,&DAT_005ea438);
            if (0 < iVar7) goto LAB_0048a586;
          }
          iVar8 = iVar8 + 1;
          local_24 = iVar8;
        }
        local_20 = local_20 + 1;
      } while (local_20 < iVar9);
    }
    iVar9 = 0;
    iVar8 = FUN_00486400(local_28);
    local_18 = iVar3;
    if ((iVar8 != 0) && (local_18 = iVar8, iVar3 != 0)) {
      iVar9 = 1;
      iVar7 = *(int *)(iVar3 + 0x8c);
      iVar5 = iVar3;
      while (iVar6 = iVar7, iVar6 != 0) {
        iVar9 = iVar9 + 1;
        iVar5 = iVar6;
        iVar7 = *(int *)(iVar6 + 0x8c);
      }
      *(int *)(iVar5 + 0x8c) = iVar8;
      local_18 = iVar3;
    }
    if (local_2c == iVar1) {
      local_14 = iVar9;
    }
    iVar9 = *(int *)(param_1 + 0x94);
    *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
    iVar3 = local_18;
  } while( true );
}


