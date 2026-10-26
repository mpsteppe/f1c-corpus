// Function: FUN_0049adc0 @ 0049adc0
// Size (bytes): 127


undefined4 __thiscall FUN_0049adc0(int *param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined2 *)0x0) {
    FUN_00587bcf(0);
    return 0;
  }
  *puVar1 = param_2;
  puVar1[1] = param_3;
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = puVar1;
    puVar2[1] = 0;
    *(undefined1 *)(puVar2 + 2) = 1;
  }
  if (*param_1 == 0) {
    *param_1 = (int)puVar2;
    param_1[2] = (int)puVar2;
    param_1[1] = (int)puVar2;
    param_1[3] = param_1[3] + 1;
    return 1;
  }
  *(undefined4 **)(param_1[1] + 4) = puVar2;
  param_1[1] = (int)puVar2;
  param_1[3] = param_1[3] + 1;
  return 1;
}


