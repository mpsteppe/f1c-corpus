// Function: FUN_0056f060 @ 0056f060
// Size (bytes): 43


void __fastcall FUN_0056f060(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *param_1) {
    do {
      FUN_0056a150();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  return;
}


