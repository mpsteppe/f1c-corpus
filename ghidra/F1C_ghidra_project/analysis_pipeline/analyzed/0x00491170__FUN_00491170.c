// Function: FUN_00491170 @ 00491170
// Size (bytes): 260


undefined1 FUN_00491170(undefined4 *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  puVar1 = (undefined4 *)*param_1;
  param_1[2] = puVar1;
  if ((puVar1 == (undefined4 *)0x0) || (psVar4 = (short *)*puVar1, psVar4 == (short *)0x0)) {
    return 0;
  }
  while( true ) {
    cVar2 = FUN_004915a0((int)*psVar4,(int)psVar4[1],(int)psVar4[2],(int)psVar4[3]);
    if (cVar2 != '\0') {
      return 1;
    }
    cVar2 = FUN_00491680((int)*psVar4,(int)psVar4[1],(int)psVar4[2],(int)psVar4[3]);
    if (cVar2 != '\0') break;
    if (param_1[2] == 0) {
      return 0;
    }
    puVar1 = *(undefined4 **)(param_1[2] + 4);
    param_1[2] = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    psVar4 = (short *)*puVar1;
    if (psVar4 == (short *)0x0) {
      return 0;
    }
  }
  iVar3 = FUN_00491350((int)*psVar4,(int)psVar4[1],(int)psVar4[2],(int)psVar4[3]);
  iVar5 = iVar3;
  if (iVar3 == 0) {
    return 1;
  }
  do {
    cVar2 = FUN_00491170(param_1,iVar5);
    if (cVar2 == '\0') {
      param_1._0_1_ = 0;
      goto joined_r0x00491250;
    }
    iVar5 = *(int *)(iVar5 + 0xc);
  } while (iVar5 != 0);
  param_1._0_1_ = 1;
joined_r0x00491250:
  while (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0xc);
    FUN_00490aa0();
  }
  return param_1._0_1_;
}


