// Function: FUN_0048dff0 @ 0048dff0
// Size (bytes): 94


undefined4 __fastcall FUN_0048dff0(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00486720();
  switch(uVar1) {
  case 1:
    (**(code **)(*param_1 + 0x40))(6);
    (**(code **)(*param_1 + 0x9c))();
    return 0;
  case 2:
    uVar1 = 7;
    break;
  default:
    goto switchD_0048dffe_caseD_3;
  case 4:
    (**(code **)(*param_1 + 0x40))(8);
    (**(code **)(*param_1 + 0x9c))();
    return 0;
  case 5:
    uVar1 = 9;
  }
  (**(code **)(*param_1 + 0x40))(uVar1);
switchD_0048dffe_caseD_3:
  (**(code **)(*param_1 + 0x9c))();
  return 0;
}


