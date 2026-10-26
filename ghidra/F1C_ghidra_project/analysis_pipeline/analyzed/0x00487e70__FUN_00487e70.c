// Function: FUN_00487e70 @ 00487e70
// Size (bytes): 92


undefined4 __fastcall FUN_00487e70(int *param_1)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00498880(&local_4,&local_8);
  iVar1 = FUN_004874e0();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x30))(local_4,local_8);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x9c))();
      if (iVar1 == 0) {
        FUN_00486630();
        return 0;
      }
    }
  }
  return 0xffffffff;
}


