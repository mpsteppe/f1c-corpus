// Function: FUN_005542f0 @ 005542f0
// Size (bytes): 439


void __thiscall FUN_005542f0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == -1) {
    return;
  }
  if (param_2 == param_1[10]) {
    return;
  }
  switch(param_2) {
  case 0:
    piVar1 = param_1 + 6;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,4,2);
    }
    piVar1 = param_1 + 7;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 2)) goto switchD_00554314_default;
    *piVar1 = 2;
    uVar4 = 2;
    break;
  case 1:
    piVar1 = param_1 + 6;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,4,2);
    }
    piVar1 = param_1 + 7;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00554314_default;
    *piVar1 = 1;
    uVar4 = 1;
    break;
  case 2:
    piVar1 = param_1 + 6;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 4)) {
      *piVar1 = 4;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,4,4);
    }
    piVar1 = param_1 + 7;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,5,2);
    }
    piVar1 = param_1 + 8;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00554314_default;
    uVar4 = 1;
    *piVar1 = 1;
    uVar3 = 6;
    goto LAB_0055448d;
  case 3:
    iVar2 = FUN_00554260(4,2);
    if (iVar2 != 0) {
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,4,2);
    }
    iVar2 = FUN_00554260(5,2);
    if (iVar2 == 0) goto switchD_00554314_default;
    uVar4 = 2;
    break;
  case 4:
    iVar2 = FUN_00554260(4,2);
    if (iVar2 != 0) {
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,4,2);
    }
    iVar2 = FUN_00554260(5,3);
    if (iVar2 == 0) goto switchD_00554314_default;
    uVar4 = 3;
    break;
  default:
    goto switchD_00554314_default;
  }
  uVar3 = 5;
LAB_0055448d:
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,uVar3,uVar4);
switchD_00554314_default:
  param_1[10] = param_2;
  return;
}


