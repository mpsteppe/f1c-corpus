// Function: FUN_00546f70 @ 00546f70
// Size (bytes): 105


undefined4 __thiscall FUN_00546f70(int param_1,int param_2)

{
  if ((param_2 < *(int *)(param_1 + 0xa4)) && (*(int *)(param_1 + 0xa4) < 8)) {
    FUN_0054fc40(0x800000);
    FUN_0054fc80(0,0);
    FUN_0054fd30(0x3f800000,0x3f800000);
    FUN_0054fca0(2);
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x80;
  }
  return 0;
}


