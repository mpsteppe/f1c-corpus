// Function: FUN_0046a980 @ 0046a980
// Size (bytes): 53


void FUN_0046a980(int *param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_007d1b08;
  do {
    if ((*piVar1 == *param_1) && (piVar1[1] == param_1[1])) {
      *piVar1 = 0;
      piVar1[1] = 0x59;
    }
    piVar1 = piVar1 + 7;
  } while ((int)piVar1 < 0x7d1fd8);
  return;
}


