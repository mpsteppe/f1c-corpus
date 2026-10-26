// Function: FUN_0044a450 @ 0044a450
// Size (bytes): 82


void FUN_0044a450(int param_1,undefined4 *param_2,float *param_3)

{
  if (param_1 < 8) {
    *param_2 = (&DAT_007ca388)[param_1];
    *param_3 = *(float *)(&DAT_007ca3a4 + param_1 * -4);
    return;
  }
  *param_2 = *(undefined4 *)(&DAT_007ca3c0 + param_1 * -4);
  *param_3 = -*(float *)(&DAT_007ca36c + param_1 * 4);
  return;
}


