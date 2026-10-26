// Function: FUN_00512322 @ 00512322
// Size (bytes): 18


void FUN_00512322(int param_1)

{
  if (*(char *)(param_1 + 0x117) == '\x10') {
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) | 0x10;
  }
  return;
}


