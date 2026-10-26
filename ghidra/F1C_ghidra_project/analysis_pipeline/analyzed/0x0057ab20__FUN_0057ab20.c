// Function: FUN_0057ab20 @ 0057ab20
// Size (bytes): 35


uint __fastcall FUN_0057ab20(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0057acb0(*param_1);
  if (uVar1 == 0) {
    *param_1 = 0;
    return 1;
  }
  return uVar1 & 0xffffff00;
}


