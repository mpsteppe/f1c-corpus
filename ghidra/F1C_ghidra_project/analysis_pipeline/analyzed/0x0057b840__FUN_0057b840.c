// Function: FUN_0057b840 @ 0057b840
// Size (bytes): 128


undefined4 __thiscall FUN_0057b840(int param_1,undefined4 *param_2)

{
  int iVar1;
  short sStack_e;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(int *)(iVar1 + 4) != param_2[1]) ||
     (sStack_e = (short)((uint)*param_2 >> 0x10), *(short *)(iVar1 + 2) != sStack_e)) {
    if ((*(int *)(iVar1 + 0x14) != param_2[1]) ||
       (sStack_e = (short)((uint)*param_2 >> 0x10), *(short *)(iVar1 + 0x12) != sStack_e)) {
      return 0;
    }
  }
  return 1;
}


