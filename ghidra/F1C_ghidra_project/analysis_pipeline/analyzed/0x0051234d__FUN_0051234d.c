// Function: FUN_0051234d @ 0051234d
// Size (bytes): 25


undefined4 FUN_0051234d(int param_1)

{
  if (*(char *)(param_1 + 0x113) != '\0') {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 2;
    return 7;
  }
  return 1;
}


