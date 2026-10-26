// Function: FUN_00489cb0 @ 00489cb0
// Size (bytes): 76


void __fastcall FUN_00489cb0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)param_1[0x24];
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    puVar1 = (undefined4 *)puVar1[0x23];
    (*(code *)*puVar2)(1);
  }
  param_1[0x24] = 0;
  param_1[0x5a] = -1;
  param_1[0x25] = 0;
  (**(code **)(*param_1 + 0x2c))(1);
  return;
}


