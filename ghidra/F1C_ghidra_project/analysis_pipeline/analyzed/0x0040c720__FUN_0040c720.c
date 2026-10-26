// Function: FUN_0040c720 @ 0040c720
// Size (bytes): 94


undefined1 __thiscall FUN_0040c720(int param_1,int param_2)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) !=
      *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
    if (((DAT_007cfe88 != '\0') || (*(char *)(DAT_007c54e0 + 0x344c) == '\0')) || (param_2 != 3)) {
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
      return uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


