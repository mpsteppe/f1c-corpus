// Function: FUN_005563e0 @ 005563e0
// Size (bytes): 82


void __fastcall FUN_005563e0(int *param_1)

{
  LARGE_INTEGER local_8;
  
  if (((*param_1 != 0) && (param_1[0xd] == 0)) && (param_1[0xc] == 0)) {
    if ((*(byte *)(param_1 + 0x12) & 1) != 0) {
      QueryPerformanceCounter(&local_8);
      param_1[0xd] = local_8.s.HighPart;
      param_1[0xc] = local_8.s.LowPart;
      return;
    }
    FUN_0055687b(param_1 + 0xd,param_1 + 0xc);
  }
  return;
}


