// Function: FUN_00488900 @ 00488900
// Size (bytes): 102


void __fastcall FUN_00488900(int *param_1)

{
  int iVar1;
  int local_8;
  undefined1 local_4 [4];
  
  FUN_00498880(&local_8,local_4);
  iVar1 = (**(code **)(*param_1 + 0x18))();
  (**(code **)(*param_1 + 0x1c))();
  (**(code **)(*param_1 + 0x24))();
  if ((*(char *)((int)param_1 + 0xed) != '\0') && (param_1[0x38] != local_8 - iVar1)) {
    param_1[0x38] = local_8 - iVar1;
    FUN_00488970();
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return;
}


