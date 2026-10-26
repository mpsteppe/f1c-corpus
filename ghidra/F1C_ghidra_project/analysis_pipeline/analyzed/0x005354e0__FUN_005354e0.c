// Function: FUN_005354e0 @ 005354e0
// Size (bytes): 108


undefined4 __fastcall FUN_005354e0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (*(char *)(param_1 + 0x17) == 'r')) {
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[1] = 0;
    *param_1 = param_1[0x11];
    uVar1 = FUN_00536e90(0);
    param_1[0x13] = uVar1;
    if (*(int *)((int)param_1 + 0x5d) == 0) {
      FUN_0058afe1(param_1[0x10]);
      return 0;
    }
    FUN_00535620();
    uVar1 = FUN_00587f64(param_1[0x10],*(undefined4 *)((int)param_1 + 0x5d),0);
    return uVar1;
  }
  return 0xffffffff;
}


