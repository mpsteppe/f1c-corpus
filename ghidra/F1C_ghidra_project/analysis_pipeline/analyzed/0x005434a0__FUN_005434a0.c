// Function: FUN_005434a0 @ 005434a0
// Size (bytes): 159


void __thiscall
FUN_005434a0(int param_1,float param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = __ftol();
  param_2 = (float)*(int *)(param_1 + 0x20);
  local_8 = __ftol();
  param_3 = __ftol();
  param_2 = (float)__ftol();
  FUN_00543540(&local_4,&local_8,&param_3,&param_2);
  if ((0 < param_3) && (0 < (int)param_2)) {
    FUN_005404d0(param_1,local_4,local_8,param_3,param_2,param_6);
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffbff;
  }
  return;
}


