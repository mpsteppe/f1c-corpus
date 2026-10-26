// Function: FUN_0040fb30 @ 0040fb30
// Size (bytes): 564


void __fastcall FUN_0040fb30(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[2] != 0) {
    FUN_00587bcf(param_1[2]);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_1[4] != 0) {
    FUN_00587bcf(param_1[4] + -4);
  }
  param_1[3] = 0;
  param_1[4] = 0;
  if (param_1[6] != 0) {
    FUN_00587bcf(param_1[6] + -4);
  }
  param_1[5] = 0;
  param_1[6] = 0;
  if (param_1[8] != 0) {
    FUN_00587bcf(param_1[8] + -4);
  }
  param_1[7] = 0;
  param_1[8] = 0;
  if (param_1[10] != 0) {
    FUN_00587bcf(param_1[10] + -4);
  }
  iVar1 = param_1[0xb];
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_0040fd70();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  if (param_1[0xd] != 0) {
    FUN_00587bcf(param_1[0xd] + -4);
  }
  iVar1 = param_1[0xe];
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_0040fd70();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = param_1[0x10];
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  if (iVar1 != 0) {
    FUN_00401030(iVar1,0x24,*(undefined4 *)(iVar1 + -4),FUN_0047aa60);
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = param_1[0x11];
  if (iVar1 != 0) {
    FUN_00401030(iVar1,0x318,*(undefined4 *)(iVar1 + -4),FUN_0040fd70);
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = param_1[0x13];
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  if (iVar1 != 0) {
    FUN_00401030(iVar1,0x24,*(undefined4 *)(iVar1 + -4),FUN_0047aa60);
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = param_1[0x14];
  if (iVar1 != 0) {
    FUN_00401030(iVar1,0x328,*(undefined4 *)(iVar1 + -4),FUN_0040fd70);
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = param_1[0x16];
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  if (iVar1 != 0) {
    FUN_00401030(iVar1,0x24,*(undefined4 *)(iVar1 + -4),FUN_0047aa60);
    FUN_00587bcf(iVar1 + -4);
  }
  if (param_1[0x17] != 0) {
    FUN_0040fdd0(3);
  }
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  if (param_1[0x19] != 0) {
    FUN_0040fda0(3);
  }
  if (param_1[0x1a] != 0) {
    FUN_0040fdd0(3);
  }
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  param_1[0x18] = 0;
  return;
}


