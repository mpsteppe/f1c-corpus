// Function: FUN_004903f0 @ 004903f0
// Size (bytes): 60


undefined4 __fastcall FUN_004903f0(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00486720();
  switch(uVar1) {
  case 0:
  case 1:
  case 2:
    (**(code **)(*param_1 + 0x40))(1);
    FUN_00490660();
    return 0;
  case 3:
  case 4:
  case 5:
    (**(code **)(*param_1 + 0x40))(4);
  }
  FUN_00490660();
  return 0;
}


