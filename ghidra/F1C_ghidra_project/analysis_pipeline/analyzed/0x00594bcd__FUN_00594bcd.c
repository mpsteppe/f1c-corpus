// Function: FUN_00594bcd @ 00594bcd
// Size (bytes): 69


void FUN_00594bcd(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x18 + (param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  *piVar1 = *piVar1 + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_008d41b8 = DAT_008d41b8 + 1, DAT_008d41b8 == 0x20)) {
    FUN_00594ab4(0x10);
  }
  return;
}


