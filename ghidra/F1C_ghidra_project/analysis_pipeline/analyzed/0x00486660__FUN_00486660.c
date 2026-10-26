// Function: FUN_00486660 @ 00486660
// Size (bytes): 59


void __thiscall FUN_00486660(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  if ((char)param_2 != (char)param_1[0x19]) {
    (**(code **)(*param_1 + 0x2c))(1);
  }
  *(char *)(param_1 + 0x19) = (char)param_2;
  piVar1 = (int *)param_1[0x24];
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x38))(param_2);
    piVar1 = (int *)FUN_00486320();
  }
  return;
}


