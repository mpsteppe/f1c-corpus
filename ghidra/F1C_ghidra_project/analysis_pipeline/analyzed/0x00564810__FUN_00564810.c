// Function: FUN_00564810 @ 00564810
// Size (bytes): 73


undefined4 * __fastcall FUN_00564810(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = _malloc(0x18);
  if (param_2 == 0) {
    param_2 = 8;
  }
  puVar1[2] = param_1;
  *puVar1 = 0;
  puVar1[1] = param_2;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  pvVar2 = _malloc(param_1 * param_2);
  puVar1[5] = pvVar2;
  return puVar1;
}


