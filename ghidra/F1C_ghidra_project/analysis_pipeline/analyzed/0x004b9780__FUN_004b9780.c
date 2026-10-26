// Function: FUN_004b9780 @ 004b9780
// Size (bytes): 41


undefined4 * __fastcall FUN_004b9780(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xf9c);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_004b57f0();
    *param_1 = uVar2;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


