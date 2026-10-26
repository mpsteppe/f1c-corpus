// Function: FUN_00543440 @ 00543440
// Size (bytes): 85


void __thiscall
FUN_00543440(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6)

{
  FUN_00543540(&param_2,&param_3,&param_4,&param_5);
  if ((0 < param_4) && (0 < param_5)) {
    FUN_005404d0(param_1,param_2,param_3,param_4,param_5,param_6);
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffbff;
  }
  return;
}


