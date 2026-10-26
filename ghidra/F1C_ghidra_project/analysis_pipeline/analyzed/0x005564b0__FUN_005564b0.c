// Function: FUN_005564b0 @ 005564b0
// Size (bytes): 85


undefined4 __thiscall FUN_005564b0(int *param_1,LONG *param_2,DWORD *param_3)

{
  LARGE_INTEGER local_8;
  
  if (*param_1 != 0) {
    if ((param_1[0x12] & 1U) != 0) {
      QueryPerformanceCounter(&local_8);
      *param_2 = local_8.s.HighPart;
      *param_3 = local_8.s.LowPart;
      return 0;
    }
    if ((param_1[0x12] & 2U) != 0) {
      FUN_0055687b(param_2,param_3);
    }
  }
  return 0;
}


