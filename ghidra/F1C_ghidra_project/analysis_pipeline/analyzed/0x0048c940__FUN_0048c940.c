// Function: FUN_0048c940 @ 0048c940
// Size (bytes): 66


undefined4 __fastcall FUN_0048c940(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_00486710();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x40))(5);
    (**(code **)(*param_1 + 0xac))();
    return 0;
  }
  iVar2 = FUN_00486720();
  if (iVar2 == 5) {
    (**(code **)(*param_1 + 0x40))(0);
  }
  (**(code **)(*param_1 + 0xac))();
  return 0;
}


