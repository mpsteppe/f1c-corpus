// Function: FUN_0048bbe0 @ 0048bbe0
// Size (bytes): 89


void __fastcall FUN_0048bbe0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_004979d0();
  if (piVar1 == param_1) {
    if (((char)param_1[0x38] == '\0') || (*(char *)((int)param_1 + 0xe1) == '\0')) {
      FUN_0048b910(1);
      (**(code **)(*param_1 + 0x2c))(1);
    }
  }
  else if (((char)param_1[0x38] != '\0') && (*(char *)((int)param_1 + 0xe1) != '\0')) {
    FUN_0048b910(0);
    (**(code **)(*param_1 + 0x2c))(1);
    return;
  }
  return;
}


