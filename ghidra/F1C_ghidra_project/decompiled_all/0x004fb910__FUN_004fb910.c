// Function: FUN_004fb910 @ 004fb910
// Strings:  [MONACO]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004fb910(undefined4 param_1)

{
  int iVar1;
  int local_8;
  float local_4;
  
  switch(param_1) {
  case 0:
    local_8 = 1;
    local_4 = 12.0;
    break;
  case 1:
    local_8 = 2;
    local_4 = 11.0;
    break;
  case 2:
    local_8 = 2;
    local_4 = 13.0;
    break;
  case 3:
    local_8 = 3;
    local_4 = 9.0;
    break;
  case 4:
    local_8 = 3;
    local_4 = 10.25;
    break;
  case 5:
    local_8 = 3;
    local_4 = 13.0;
    break;
  case 6:
    local_4 = 9.5;
    goto LAB_004fb99e;
  case 7:
    local_4 = 14.0;
LAB_004fb99e:
    local_8 = 4;
  }
  if (((DAT_007c56a4 == 1) || (DAT_007c56a4 == 2)) && (iVar1 = FUN_00566810(), iVar1 != 0)) {
    local_8 = local_8 + -1;
  }
  return (float10)local_4 * (float10)_DAT_0059fb48 + (float10)local_8 * (float10)_DAT_005ad28c;
}


