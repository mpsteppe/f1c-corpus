// Function: FUN_00478690 @ 00478690
// Size (bytes): 39


int * __fastcall FUN_00478690(int *param_1)

{
  if (param_1[0x4e] != 0) {
    (**(code **)(*param_1 + 0x3c))(1);
    return param_1 + 0x46;
  }
  (**(code **)(*param_1 + 0x3c))(0);
  return (int *)0x0;
}


