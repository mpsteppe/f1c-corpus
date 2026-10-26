// Function: FUN_0049a190 @ 0049a190
// Size (bytes): 41


void __fastcall FUN_0049a190(int *param_1)

{
  int iVar1;
  undefined4 *extraout_ECX;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar1 = FUN_00499e00();
    *param_1 = iVar1;
    if (extraout_ECX != (undefined4 *)0x0) {
      (**(code **)*extraout_ECX)(1);
    }
    iVar1 = *param_1;
  }
  return;
}


