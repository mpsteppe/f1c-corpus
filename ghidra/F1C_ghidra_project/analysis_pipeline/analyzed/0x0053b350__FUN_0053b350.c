// Function: FUN_0053b350 @ 0053b350
// Size (bytes): 93


void __fastcall FUN_0053b350(uint *param_1)

{
  if ((*param_1 & 2) != 0) {
    *param_1 = *param_1 & 0xfffffffd;
    param_1[10] = (uint)((float)param_1[7] * (float)param_1[10]);
    param_1[0xb] = (uint)((float)param_1[7] * (float)param_1[0xb]);
    param_1[0xc] = (uint)((float)param_1[7] * (float)param_1[0xc]);
    param_1[0xe] = (uint)((float)param_1[8] * (float)param_1[0xe]);
    param_1[0xf] = (uint)((float)param_1[0xf] * (float)param_1[8]);
    param_1[0x10] = (uint)((float)param_1[0x10] * (float)param_1[8]);
    param_1[0x12] = (uint)((float)param_1[0x12] * (float)param_1[9]);
    param_1[0x13] = (uint)((float)param_1[0x13] * (float)param_1[9]);
    param_1[0x14] = (uint)((float)param_1[0x14] * (float)param_1[9]);
  }
  return;
}


