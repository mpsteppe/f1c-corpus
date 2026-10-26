// Function: FUN_004b57f0 @ 004b57f0
// Size (bytes): 576


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_004b57f0(undefined4 *param_1)

{
  float fVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_004ba820();
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  FUN_004ba820();
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004baac0(1);
  }
  FUN_004bb150(uVar3,1);
  puVar4 = param_1 + 0x10;
  iVar5 = 0x68;
  do {
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4 = puVar4 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  param_1[0x1b0] = 0;
  param_1[0x1b1] = 0;
  param_1[0x1b2] = 0;
  param_1[0x1b3] = 0;
  param_1[0x1b5] = 0;
  param_1[0x1b6] = 0;
  param_1[0x1b7] = 0;
  param_1[0x1b8] = 0;
  FUN_005668b0();
  param_1[0x1c1] = 0;
  param_1[0x1c2] = 0xffffffff;
  param_1[0x1c3] = 0;
  param_1[0x1c4] = 0xffffffff;
  param_1[0x1c5] = 0;
  param_1[0x1c6] = 0;
  param_1[0x1c7] = 0;
  param_1[0x1c8] = 0;
  param_1[0x1c9] = 0;
  param_1[0x1ca] = 0xffffffff;
  param_1[0x1cb] = 0;
  param_1[0x1cc] = 0xffffffff;
  FUN_004ff670();
  FUN_00568ba0();
  param_1[0x3d1] = 0;
  param_1[0x3d2] = 0;
  param_1[0x3d3] = 0;
  param_1[0x3d4] = 0;
  FUN_004ba820();
  param_1[0x3d9] = 0;
  param_1[0x3da] = 0;
  param_1[0x3db] = 0;
  param_1[0x3dc] = 0;
  param_1[0x3dd] = DAT_005acd24;
  param_1[0x3e5] = 0;
  param_1[0x3e6] = 0xffffffff;
  param_1[0x1c0] = 0;
  param_1[0x269] = 4;
  param_1[0x26a] = 2;
  param_1[0x26b] = 2;
  param_1[0x26c] = 0;
  param_1[0x26d] = 0;
  param_1[0x26e] = 0;
  param_1[0x26f] = 0;
  param_1[0x34a] = 0;
  FUN_00568be0(1);
  FUN_00568c60();
  fVar1 = _DAT_0059e43c;
  param_1[0x35e] = 0xfe967699;
  puVar4 = param_1 + 0x35f;
  for (iVar5 = 0x68; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  param_1[0x3c9] = 0;
  param_1[0x3ca] = 0;
  param_1[0x3cb] = 0;
  param_1[0x3cc] = 0;
  param_1[0x3cd] = 0;
  *(undefined1 *)(param_1 + 0x3de) = 0;
  *(undefined1 *)((int)param_1 + 0xf79) = 1;
  *(undefined1 *)((int)param_1 + 0xf7a) = 1;
  fVar1 = fVar1 / _DAT_005acd08;
  *(undefined1 *)((int)param_1 + 0xf81) = 0;
  param_1[0x3e3] = 5;
  param_1[0x3e4] = 0x44610000;
  param_1[0x3ce] = 0;
  param_1[0x3cf] = 0;
  param_1[0x3d0] = 0xffffffff;
  param_1[0x3df] = fVar1;
  return param_1;
}


