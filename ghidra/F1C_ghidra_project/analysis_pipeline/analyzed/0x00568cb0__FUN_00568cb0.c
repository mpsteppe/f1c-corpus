// Function: FUN_00568cb0 @ 00568cb0
// Size (bytes): 54


undefined4 __thiscall FUN_00568cb0(int *param_1,LONG *param_2,DWORD *param_3)

{
  LARGE_INTEGER local_8;
  
  if ((*param_1 != 0) && ((*(byte *)(param_1 + 0x12) & 1) != 0)) {
    QueryPerformanceCounter(&local_8);
    *param_2 = local_8.s.HighPart;
    *param_3 = local_8.s.LowPart;
  }
  return 0;
}


