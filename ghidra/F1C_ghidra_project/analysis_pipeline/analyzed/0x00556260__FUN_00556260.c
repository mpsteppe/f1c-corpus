// Function: FUN_00556260 @ 00556260
// Size (bytes): 196


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00556260(uint *param_1,uint param_2)

{
  double dVar1;
  BOOL BVar2;
  LARGE_INTEGER local_b0;
  LARGE_INTEGER local_a8;
  undefined1 local_a0 [40];
  int local_78;
  
  if (param_2 == 1) {
    BVar2 = QueryPerformanceFrequency(&local_a8);
    if (BVar2 != 0) {
      QueryPerformanceCounter(&local_b0);
      param_1[6] = local_b0.s.LowPart;
      param_1[7] = local_b0.s.HighPart;
      *param_1 = local_a8.s.LowPart;
    }
  }
  else if (param_2 == 2) {
    FUN_0055f080();
    FUN_0055fbc0(local_a0);
    FUN_0055687b(param_1 + 7,param_1 + 6);
    *param_1 = local_78 * 1000000;
    FUN_00557470();
  }
  param_1[8] = param_1[6];
  param_1[0x12] = param_2;
  dVar1 = _DAT_005af448 / (double)*param_1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[9] = param_1[7];
  param_1[4] = 0;
  param_1[5] = 0;
  *(double *)(param_1 + 2) = dVar1;
  return;
}


