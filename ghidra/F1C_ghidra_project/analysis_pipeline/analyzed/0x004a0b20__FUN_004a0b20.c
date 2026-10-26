// Function: FUN_004a0b20 @ 004a0b20
// Size (bytes): 118


undefined4 FUN_004a0b20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x403c);
  if ((*(int *)(param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894)) &&
     (iVar1 % 5 == 1)) {
    FUN_004d8760(0xd,0);
  }
  if (((*(int *)(param_1 + 0x4060) == 1) && (1 < iVar1)) && ((iVar1 + 3) % 5 == 0)) {
    FUN_004d8760(0x13,0);
  }
  return 0;
}


