// Function: FUN_00491280 @ 00491280
// Size (bytes): 101


undefined4 FUN_00491280(undefined4 *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  short *psVar3;
  
  puVar1 = (undefined4 *)*param_1;
  param_1[2] = puVar1;
  if ((puVar1 != (undefined4 *)0x0) && (psVar3 = (short *)*puVar1, psVar3 != (short *)0x0)) {
    while( true ) {
      cVar2 = FUN_00491680((int)*psVar3,(int)psVar3[1],(int)psVar3[2],(int)psVar3[3]);
      if (cVar2 != '\0') {
        return 1;
      }
      if (param_1[2] == 0) break;
      puVar1 = *(undefined4 **)(param_1[2] + 4);
      param_1[2] = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        return 0;
      }
      psVar3 = (short *)*puVar1;
      if (psVar3 == (short *)0x0) {
        return 0;
      }
    }
  }
  return 0;
}


