// Function: FUN_00553e10 @ 00553e10
// Size (bytes): 399


void __thiscall FUN_00553e10(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1 + 1;
  *param_1 = param_2;
  piVar2 = param_1 + 6;
  param_1[10] = 0;
  if ((piVar2 != (int *)0x0) && (*piVar2 != 1)) {
    *piVar2 = 1;
  }
  piVar2 = param_1 + 7;
  if ((piVar2 != (int *)0x0) && (*piVar2 != 2)) {
    *piVar2 = 2;
  }
  piVar2 = param_1 + 8;
  if ((piVar2 != (int *)0x0) && (*piVar2 != 1)) {
    *piVar2 = 1;
  }
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,4,1);
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,5,2);
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,6,1);
  param_1[9] = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 1)) {
    *piVar1 = 1;
  }
  piVar1 = param_1 + 2;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
    *piVar1 = 2;
  }
  piVar1 = param_1 + 3;
  if ((piVar1 != (int *)0x0) && (*piVar1 != 1)) {
    *piVar1 = 1;
  }
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,1);
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,3,1);
  param_1[0xb] = 0;
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0xb,0);
  param_1[0xd] = 0;
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0x12,0);
  param_1[0xc] = 0;
  (**(code **)(*DAT_008b89a0 + 0xf4))(DAT_008b89a0,*param_1,0);
  param_1[0xe] = 0;
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0xd,1);
  param_1[0xf] = 0;
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0xe,1);
  param_1[0x10] = 0;
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,0x13,0);
  return;
}


