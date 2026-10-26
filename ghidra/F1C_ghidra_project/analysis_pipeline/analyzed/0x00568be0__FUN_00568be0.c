// Function: FUN_00568be0 @ 00568be0
// Size (bytes): 122


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00568be0(uint *param_1,uint param_2)

{
  double dVar1;
  BOOL BVar2;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  if (param_2 == 1) {
    BVar2 = QueryPerformanceFrequency(&local_8);
    if (BVar2 != 0) {
      QueryPerformanceCounter(&local_10);
      param_1[6] = local_10.s.LowPart;
      param_1[7] = local_10.s.HighPart;
      *param_1 = local_8.s.LowPart;
    }
  }
  param_1[8] = param_1[6];
  param_1[0x12] = param_2;
  param_1[10] = 0;
  param_1[0xb] = 0;
  dVar1 = _DAT_005af448 / (double)*param_1;
  param_1[9] = param_1[7];
  param_1[4] = 0;
  param_1[5] = 0;
  *(double *)(param_1 + 2) = dVar1;
  return;
}


