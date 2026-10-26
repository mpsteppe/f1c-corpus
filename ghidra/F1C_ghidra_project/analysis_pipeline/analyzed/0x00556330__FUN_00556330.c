// Function: FUN_00556330 @ 00556330
// Size (bytes): 173


void __fastcall FUN_00556330(int *param_1)

{
  uint local_14;
  int local_10 [2];
  LARGE_INTEGER local_8;
  
  if (((*param_1 != 0) && (param_1[0xd] != 0)) && (param_1[0xc] != 0)) {
    if ((*(byte *)(param_1 + 0x12) & 1) == 0) {
      FUN_0055687b(local_10,&local_14);
    }
    else {
      QueryPerformanceCounter(&local_8);
      local_14 = local_8.s.LowPart;
      local_10[0] = local_8.s.HighPart;
    }
    param_1[10] = param_1[10] + (local_14 - param_1[0xc]);
    param_1[0xb] = param_1[0xb] +
                   ((local_10[0] - param_1[0xd]) - (uint)(local_14 < (uint)param_1[0xc]));
    param_1[0xc] = 0;
    param_1[0xd] = 0;
  }
  return;
}


