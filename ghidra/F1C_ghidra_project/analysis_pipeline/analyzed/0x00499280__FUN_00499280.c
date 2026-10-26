// Function: FUN_00499280 @ 00499280
// Size (bytes): 87


void __fastcall FUN_00499280(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x11];
  *param_1 = &PTR_FUN_005aca74;
  while (iVar1 != 0) {
    iVar1 = FUN_00486320();
    if ((undefined4 *)param_1[0x11] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x11])(1);
    }
    param_1[0x11] = iVar1;
  }
  if (param_1[0x18] != 0) {
    FUN_00587bcf(param_1[0x18]);
  }
  if (param_1[0x16] != 0) {
    FUN_00587bcf(param_1[0x16]);
  }
  FUN_0049a990();
  return;
}


