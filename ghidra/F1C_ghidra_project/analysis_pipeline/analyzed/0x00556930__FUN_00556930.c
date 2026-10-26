// Function: FUN_00556930 @ 00556930
// Size (bytes): 75


void __thiscall FUN_00556930(int param_1,int param_2)

{
  uint uVar1;
  
  while( true ) {
    uVar1 = *(uint *)(param_1 + 0x38);
    if ((uVar1 != 0) && ((*(uint *)(param_2 + 0x84) & uVar1 & DAT_008b8e34) != uVar1)) {
      return;
    }
    FUN_00556980(param_2);
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_00556930(param_2);
    }
    if (*(int *)(param_1 + 0x40) == 0) break;
    param_1 = *(int *)(param_1 + 0x4c);
    if (param_1 == 0) {
      return;
    }
  }
  return;
}


