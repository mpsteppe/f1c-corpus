// Function: FUN_00565140 @ 00565140
// Size (bytes): 102


void __fastcall FUN_00565140(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_3) {
    do {
      if ((*(int *)(param_1 + 0x514) == 0) ||
         (0x3e < (*(int *)(param_1 + 0x514) - param_1) - 0x4d4U)) {
        *(int *)(param_1 + 0x514) = param_1 + 0x4d4;
        FUN_00564f10(0x10);
      }
      *(byte *)(iVar1 + param_2) = *(byte *)(iVar1 + param_2) ^ **(byte **)(param_1 + 0x514);
      iVar1 = iVar1 + 1;
      *(int *)(param_1 + 0x514) = *(int *)(param_1 + 0x514) + 1;
    } while (iVar1 < param_3);
  }
  return;
}


