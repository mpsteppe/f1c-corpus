// Function: FUN_0048b910 @ 0048b910
// Size (bytes): 60


void __thiscall FUN_0048b910(int *param_1,char param_2)

{
  int *piVar1;
  
  *(char *)(param_1 + 0x38) = param_2;
  (**(code **)(*param_1 + 0x2c))(1);
  if (param_2 == '\0') {
    piVar1 = (int *)FUN_004979d0();
    if (piVar1 == param_1) {
      FUN_004979e0();
    }
    (**(code **)(*param_1 + 0xb0))();
  }
  return;
}


