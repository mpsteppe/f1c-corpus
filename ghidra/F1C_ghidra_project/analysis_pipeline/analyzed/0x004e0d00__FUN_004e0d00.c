// Function: FUN_004e0d00 @ 004e0d00
// Size (bytes): 104


void __thiscall FUN_004e0d00(int param_1,int *param_2)

{
  if ((*param_2 != 0) && ((char)param_2[0x10] == '\0')) {
    FUN_0054ba00(*param_2,0);
    FUN_0054b4d0(param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6]);
    *(undefined1 *)(param_2 + 0x10) = 1;
    FUN_004e0ed0(*(undefined4 *)(param_1 + 0x964));
    FUN_00411440();
    return;
  }
  return;
}


