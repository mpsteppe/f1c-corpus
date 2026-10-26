// Function: FUN_00411680 @ 00411680
// Size (bytes): 35


void __fastcall FUN_00411680(undefined2 *param_1)

{
  int iVar1;
  
  iVar1 = 0x219;
  do {
    *param_1 = 1;
    param_1[1] = 0;
    param_1 = param_1 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


