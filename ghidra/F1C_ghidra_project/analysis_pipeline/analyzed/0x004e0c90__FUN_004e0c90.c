// Function: FUN_004e0c90 @ 004e0c90
// Size (bytes): 98


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e0c90(int param_1,float param_2)

{
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0x894) != 0) {
    FUN_0054b420(&local_c,&local_8,&local_4);
    local_c = *(float *)(param_1 + 0x930) - param_2 * _DAT_0059e7e8;
    FUN_0054b4d0(local_c,local_8,local_4,0,0,param_2);
  }
  return;
}


