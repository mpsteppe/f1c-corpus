// Function: FUN_00548a00 @ 00548a00
// Size (bytes): 38


int __thiscall FUN_00548a00(int param_1,float param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(float *)(iVar1 + 8) == param_2) break;
    iVar1 = *(int *)(iVar1 + 0x14);
  }
  return iVar1;
}


