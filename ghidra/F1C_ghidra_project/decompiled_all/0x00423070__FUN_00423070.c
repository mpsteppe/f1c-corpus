// Function: FUN_00423070 @ 00423070
// Strings:  [config=%s, config=]


void FUN_00423070(int param_1)

{
  int iVar1;
  undefined1 local_50 [80];
  
  if (param_1 != 0) {
    iVar1 = FUN_00587c20(param_1,s_config__005c303c);
    if (iVar1 != 0) {
      iVar1 = FUN_005887ed(iVar1,s_config__s_005c3030,local_50);
      if (iVar1 == 1) {
        FUN_00566650(local_50);
      }
    }
  }
  return;
}


