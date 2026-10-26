// Function: FUN_004900a0 @ 004900a0
// Size (bytes): 190


undefined4 __fastcall FUN_004900a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  int local_4;
  
  local_c = 0;
  local_8 = 0;
  iVar1 = FUN_00487060(0);
  iVar2 = FUN_00487060(1);
  iVar3 = FUN_004870e0(0);
  local_4 = FUN_004870e0(1);
  FUN_00498880(&local_c,&local_8);
  if ((((local_c <= iVar1) || (iVar2 <= local_c)) || (local_8 <= iVar3)) || (local_4 <= local_8))
  goto LAB_0049013c;
  iVar1 = param_1[0x38];
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      param_1[0x38] = 0;
      goto LAB_0049013c;
    }
    if (iVar1 == 2) {
      param_1[0x38] = 2;
      goto LAB_0049013c;
    }
  }
  param_1[0x38] = 1;
LAB_0049013c:
  (**(code **)(*param_1 + 0x40))(param_1[0x38]);
  (**(code **)(*param_1 + 0x98))();
  return 0;
}


