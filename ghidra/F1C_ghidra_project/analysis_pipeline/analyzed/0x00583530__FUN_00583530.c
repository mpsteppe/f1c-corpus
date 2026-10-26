// Function: FUN_00583530 @ 00583530
// Size (bytes): 56


void FUN_00583530(int *param_1)

{
  int iVar1;
  
  FUN_00586000(param_1,1);
  iVar1 = 0;
  do {
    FUN_00583210(*param_1 + iVar1,0);
    iVar1 = iVar1 + 0x103c;
  } while (iVar1 < 0x2078);
  return;
}


