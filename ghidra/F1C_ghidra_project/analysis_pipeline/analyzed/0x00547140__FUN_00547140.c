// Function: FUN_00547140 @ 00547140
// Size (bytes): 111


void __thiscall FUN_00547140(int param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_2) {
  case 1:
    (**(code **)(*DAT_008b8f24 + 0x10))(param_3,param_1 + 0x54);
    return;
  case 2:
    (**(code **)(*DAT_008b8f24 + 0x10))(param_3,param_1 + 0x44);
    return;
  case 3:
    (**(code **)(*DAT_008b8f24 + 0x10))(param_3,param_1 + 100);
    return;
  case 4:
    (**(code **)(*DAT_008b8f24 + 0x10))(param_3,param_1 + 0x74);
  }
  return;
}


