// Function: FUN_0043e230 @ 0043e230
// Size (bytes): 289


void __fastcall FUN_0043e230(undefined4 *param_1)

{
  undefined4 *puVar1;
  double *pdVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  
  FUN_00431a50((float)*(double *)(param_1 + 0x753));
  iVar5 = 0;
  pdVar3 = (double *)(param_1 + 0x1ae);
  do {
    FUN_00431930(iVar5,(float)pdVar3[-5]);
    FUN_004319c0(iVar5,(float)*pdVar3);
    iVar4 = 0;
    pdVar2 = pdVar3 + -0x1c;
    do {
      FUN_00431a70(iVar5,iVar4,(float)*pdVar2);
      iVar4 = iVar4 + 1;
      pdVar2 = pdVar2 + 1;
    } while (iVar4 < 3);
    iVar5 = iVar5 + 1;
    pdVar3 = (double *)((int)pdVar3 + 0x464);
  } while (iVar5 < 4);
  FUN_004d5840();
  FUN_004358f0();
  param_1[0x7c0] = 0;
  FUN_0056e970();
  if (param_1[0x73f] != 0) {
    FUN_00587bcf(param_1[0x73f]);
  }
  if (param_1[0x58b] != 0) {
    FUN_00587bcf(param_1[0x58b]);
  }
  puVar1 = param_1;
  for (iVar5 = 0x7ce; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  iVar5 = 0;
  puVar1 = param_1 + 0x176;
  do {
    puVar1[-0xb5] = iVar5;
    *puVar1 = 0x8f5c28f6;
    puVar1[1] = 0x40767dc2;
    puVar1[2] = *puVar1;
    puVar1[3] = puVar1[1];
    puVar1[4] = puVar1[2];
    iVar5 = iVar5 + 1;
    puVar1[5] = puVar1[3];
    puVar1 = puVar1 + 0x119;
  } while (iVar5 < 4);
  return;
}


