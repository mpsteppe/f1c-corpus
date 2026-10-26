// Function: FUN_004dfa60 @ 004dfa60
// Size (bytes): 155


void __thiscall FUN_004dfa60(int *param_1,int param_2,char param_3)

{
  *(undefined1 *)((int)param_1 + 0x42) = (undefined1)param_2;
  if (*param_1 != 0) {
    if (param_3 != '\0') {
      FUN_0040e2b0();
    }
    FUN_0054b530(param_1 + 1,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5,param_1 + 6);
    *(undefined1 *)(param_1 + 0x10) = 1;
    FUN_0054c0b0(&param_3,&param_2);
    *(bool *)((int)param_1 + 0x41) = param_2 != 0;
    FUN_00566e40();
    return;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  FUN_00566e40();
  return;
}


