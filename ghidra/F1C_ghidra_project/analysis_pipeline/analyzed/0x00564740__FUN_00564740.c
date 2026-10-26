// Function: FUN_00564740 @ 00564740
// Size (bytes): 51


void __fastcall FUN_00564740(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < (int)param_1[1]) {
    do {
      FUN_00564860();
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1[1]);
  }
  FUN_0058aa6f(*param_1);
  FUN_0058aa6f(param_1);
  return;
}


