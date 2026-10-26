// Function: FUN_00499af0 @ 00499af0
// Size (bytes): 27


void __fastcall FUN_00499af0(undefined4 *param_1)

{
  int iVar1;
  
  if ((undefined4 *)param_1[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x14])(1);
  }
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}


