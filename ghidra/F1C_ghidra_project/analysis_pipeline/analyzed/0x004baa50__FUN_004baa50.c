// Function: FUN_004baa50 @ 004baa50
// Size (bytes): 105


int * __thiscall FUN_004baa50(int *param_1,char param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = (param_2 != '\0') - 1 & 2;
  puVar2 = operator_new(uVar1 * 0x3f8 + 4);
  if (puVar2 == (uint *)0x0) {
    *param_1 = 0;
    return param_1;
  }
  *puVar2 = uVar1;
  if (-1 < (int)(uVar1 - 1)) {
    do {
      FUN_004b4f50();
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  *param_1 = (int)(puVar2 + 1);
  return param_1;
}


