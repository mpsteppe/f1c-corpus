// Function: FUN_00542560 @ 00542560
// Size (bytes): 54


void __thiscall FUN_00542560(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(int *)(param_1 + 0x19c) = param_2;
    FUN_00542200((float)*(int *)(param_1 + 0x68),(float)*(int *)(param_1 + 100),
                 (float)*(int *)(param_1 + 0x54),(float)*(int *)(param_1 + 0x58),1);
  }
  return;
}


