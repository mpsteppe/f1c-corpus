// Function: FUN_00500680 @ 00500680
// Size (bytes): 36


int * FUN_00500680(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_005ad508;
  while( true ) {
    if (PTR_DAT_005d7150 <= piVar1) {
      return (int *)&DAT_005ad4e0;
    }
    if (param_1 == *piVar1) break;
    piVar1 = piVar1 + 9;
  }
  return piVar1;
}


