// Function: FUN_00411650 @ 00411650
// Size (bytes): 39


ushort __fastcall FUN_00411650(ushort *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (1 < *param_1) {
    uVar1 = param_1[1];
    param_1[1] = uVar1 + 1;
    if (*param_1 <= (ushort)(uVar1 + 1)) {
      param_1[1] = 0;
    }
  }
  return uVar1;
}


