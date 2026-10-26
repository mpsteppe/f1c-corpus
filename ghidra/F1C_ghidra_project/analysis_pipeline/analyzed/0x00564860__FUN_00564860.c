// Function: FUN_00564860 @ 00564860
// Size (bytes): 48


void __fastcall FUN_00564860(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      FUN_00564890();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  FUN_0058aa6f(param_1[5]);
  FUN_0058aa6f(param_1);
  return;
}


