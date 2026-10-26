// Function: FUN_0044fee0 @ 0044fee0
// Size (bytes): 99


void __thiscall FUN_0044fee0(int param_1,double *param_2,double *param_3)

{
  *(double *)(param_1 + 0x560) = *(double *)(param_1 + 0x560) + *param_2;
  *(double *)(param_1 + 0x568) = param_2[1] + *(double *)(param_1 + 0x568);
  *(double *)(param_1 + 0x570) = param_2[2] + *(double *)(param_1 + 0x570);
  *(double *)(param_1 + 0x578) = *(double *)(param_1 + 0x578) + *param_3;
  *(double *)(param_1 + 0x580) = param_3[1] + *(double *)(param_1 + 0x580);
  *(double *)(param_1 + 0x588) = param_3[2] + *(double *)(param_1 + 0x588);
  return;
}


