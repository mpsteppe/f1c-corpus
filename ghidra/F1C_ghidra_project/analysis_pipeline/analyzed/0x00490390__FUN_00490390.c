// Function: FUN_00490390 @ 00490390
// Size (bytes): 61


undefined4 __fastcall FUN_00490390(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00486720();
  switch(uVar1) {
  case 0:
  case 1:
  case 2:
    (**(code **)(*param_1 + 0x40))(4);
    break;
  case 3:
  case 4:
  case 5:
    (**(code **)(*param_1 + 0x40))(1);
  }
  (**(code **)(*param_1 + 0x9c))();
  FUN_00490660();
  return 0;
}


