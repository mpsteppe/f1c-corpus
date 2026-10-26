// Function: FUN_00556900 @ 00556900
// Size (bytes): 46


void __thiscall FUN_00556900(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = *(int *)(*(int *)(param_1 + 0x110) + 0x28); iVar1 != 0;
      iVar1 = *(int *)(iVar1 + 0x5c)) {
    iVar2 = *(int *)(iVar1 + 0x54);
    if ((*(uint *)(iVar2 + 0x18) & 0x400) != 0) {
      *(float *)(iVar2 + 0x38) = param_2 + *(float *)(iVar2 + 0x38);
    }
  }
  return;
}


