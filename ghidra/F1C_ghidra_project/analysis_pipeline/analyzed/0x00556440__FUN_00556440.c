// Function: FUN_00556440 @ 00556440
// Size (bytes): 106


void __fastcall FUN_00556440(int *param_1)

{
  LARGE_INTEGER local_8;
  
  if (*param_1 != 0) {
    if ((*(byte *)(param_1 + 0x12) & 1) == 0) {
      FUN_0055687b(param_1 + 7,param_1 + 6);
    }
    else {
      QueryPerformanceCounter(&local_8);
      param_1[6] = local_8.s.LowPart;
      param_1[7] = local_8.s.HighPart;
    }
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[8] = param_1[6];
    param_1[9] = param_1[7];
    param_1[4] = 0;
    param_1[5] = 0;
  }
  return;
}


