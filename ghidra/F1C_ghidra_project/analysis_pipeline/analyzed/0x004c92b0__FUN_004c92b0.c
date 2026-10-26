// Function: FUN_004c92b0 @ 004c92b0
// Size (bytes): 81


void __thiscall FUN_004c92b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int extraout_ECX;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  piVar1 = (int *)FUN_004c9260();
  if (piVar1 != (int *)0x0) {
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    (**(code **)(*piVar1 + 4))(2,extraout_ECX + 8,&local_c,param_3,0x3f800000,1);
  }
  return;
}


