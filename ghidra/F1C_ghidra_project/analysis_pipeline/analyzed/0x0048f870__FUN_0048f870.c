// Function: FUN_0048f870 @ 0048f870
// Size (bytes): 373


void __fastcall FUN_0048f870(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  FUN_00498880(&local_4,&local_8);
  iVar2 = (param_1[0x49] - param_1[0x48]) / (param_1[0x58] + param_1[0x54]);
  if (param_1[0x3f] <= iVar2) {
    iVar2 = param_1[0x3f];
  }
  iVar2 = (param_1[0x49] - (param_1[0x58] + param_1[0x54]) * iVar2) - param_1[0x48];
  local_10 = 0;
  if (0 < param_1[0x56]) {
    do {
      iVar3 = param_1[0x57];
      iVar6 = 0;
      if (0 < iVar3) {
        do {
          iVar3 = iVar3 * local_10 + iVar6;
          if ((-1 < iVar3) && (iVar3 < param_1[0x3f])) {
            piVar1 = (int *)param_1[0x3c];
            for (; 0 < iVar3; iVar3 = iVar3 + -1) {
              if (piVar1 == (int *)0x0) goto LAB_0048f9b2;
              piVar1 = (int *)piVar1[1];
            }
            if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
              iVar5 = 0;
              iVar3 = 0;
              if (param_1[0x40] == 0) {
                iVar5 = param_1[0x5a];
              }
              else if (param_1[0x40] == 1) {
                iVar3 = param_1[0x5a];
              }
              iVar5 = ((param_1[0x58] + param_1[0x54]) * iVar6 - iVar5) + param_1[0x48];
              if (param_1[0x38] == 1) {
                iVar4 = iVar2 / 2;
LAB_0048f98a:
                iVar5 = iVar5 + iVar4;
              }
              else {
                iVar4 = iVar2;
                if (param_1[0x38] == 2) goto LAB_0048f98a;
              }
              FUN_0048ea20(iVar5,((param_1[0x59] + param_1[0x55]) * local_10 + param_1[0x50]) -
                                 iVar3);
            }
          }
LAB_0048f9b2:
          iVar3 = param_1[0x57];
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
      }
      local_10 = local_10 + 1;
    } while (local_10 < param_1[0x56]);
  }
  (**(code **)(*param_1 + 0x2c))(1);
  return;
}


