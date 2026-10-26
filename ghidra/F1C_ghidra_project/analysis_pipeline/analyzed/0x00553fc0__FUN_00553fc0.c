// Function: FUN_00553fc0 @ 00553fc0
// Size (bytes): 620


void __thiscall FUN_00553fc0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == -1) {
    return;
  }
  if (param_2 == param_1[9]) {
    return;
  }
  switch(param_2) {
  case 0:
    piVar1 = param_1 + 1;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00553fe4_caseD_3;
    uVar4 = 1;
    *piVar1 = 1;
    uVar3 = 1;
    goto LAB_00554212;
  case 1:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,2);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    piVar1 = param_1 + 3;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00553fe4_caseD_3;
    *piVar1 = 1;
    break;
  case 2:
  case 8:
    iVar2 = FUN_00554260(1,7);
    if (iVar2 != 0) {
      uVar4 = 7;
LAB_005541c8:
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,uVar4);
    }
    goto LAB_005541db;
  default:
    goto switchD_00553fe4_caseD_3;
  case 4:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 4)) {
      *piVar1 = 4;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,4);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    piVar1 = param_1 + 3;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00553fe4_caseD_3;
    *piVar1 = 1;
    break;
  case 5:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,2);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 3)) goto switchD_00553fe4_caseD_3;
    uVar4 = 3;
    *piVar1 = 3;
    uVar3 = 2;
    goto LAB_00554212;
  case 6:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 4)) {
      *piVar1 = 4;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,4);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    piVar1 = param_1 + 3;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 3)) goto switchD_00553fe4_caseD_3;
    *piVar1 = 3;
    uVar4 = 3;
    goto LAB_00554210;
  case 7:
  case 0xc:
    iVar2 = FUN_00554260(1,4);
    if (iVar2 != 0) {
      uVar4 = 4;
      goto LAB_005541c8;
    }
LAB_005541db:
    iVar2 = FUN_00554260(2,2);
    if (iVar2 != 0) {
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    iVar2 = FUN_00554260(3,1);
    if (iVar2 == 0) goto switchD_00553fe4_caseD_3;
  }
  uVar4 = 1;
LAB_00554210:
  uVar3 = 3;
LAB_00554212:
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,uVar3,uVar4);
switchD_00553fe4_caseD_3:
  param_1[9] = param_2;
  return;
}


