// Function: FUN_004de5d0 @ 004de5d0
// Size (bytes): 19


int __fastcall FUN_004de5d0(int param_1,int param_2)

{
  return (uint)*(ushort *)(param_1 + param_2 * 2) * 0x30 + *(int *)(*(int *)(param_1 + 8) + 0xc);
}


