// Function: FUN_00448140 @ 00448140
// Strings:  [%sAmbient\helicopter.wav]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00448140(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int local_118 [4];
  undefined1 local_108;
  float fStack_104;
  undefined1 local_100 [256];
  
  *param_1 = param_2;
  piVar5 = DAT_008ac4c4;
  if (DAT_008ac4c4 != (int *)0x0) {
    local_118[0] = 0;
    local_118[1] = 0xffffffff;
    FUN_00566650(&DAT_005ea438);
    local_118[2] = 0xffffffff;
    local_118[3] = 0xffffffff;
    local_108 = 0;
    puVar4 = DAT_005ec3e0;
    if (DAT_005ec3e0 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058969d(local_100,0x100,s__sAmbient_helicopter_wav_005c43b8,puVar4);
    FUN_00566650(local_100);
    local_118[2] = 0xffffffff;
    local_118[3] = 0xffffffff;
    local_108 = 0;
    piVar5 = (int *)(**(code **)(*piVar5 + 0x5c))(local_118,1,0);
    param_1[1] = piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x14))();
      fVar3 = DAT_007cf5e4;
      uVar2 = _DAT_007cf5c0;
      iVar6 = param_1[1];
      fStack_104 = DAT_007cf5e4;
      fVar1 = _DAT_0059e43c;
      if (_DAT_007cf59c < DAT_0059e440 == (_DAT_007cf59c == DAT_0059e440)) {
        fVar1 = _DAT_0059e43c / _DAT_007cf59c;
      }
      *(float *)(iVar6 + 0x1c) = fVar1;
      *(float *)(iVar6 + 0x20) = _DAT_0059e43c - fVar1 * fVar3;
      *(undefined4 *)(iVar6 + 0x24) = uVar2;
    }
    if (local_118[0] != 0) {
      FUN_00587bcf(local_118[0]);
    }
  }
  iVar6 = FUN_0054c230(0);
  if (iVar6 != 0) {
    iVar6 = *(int *)(iVar6 + 0x13c);
    param_1[3] = iVar6;
    if ((iVar6 != 0) && (*(int *)(iVar6 + 0x1c) != 0)) {
      param_1[2] = *(undefined4 *)(*(int *)(iVar6 + 0x1c) + 8);
    }
    iVar6 = FUN_0054c210();
    iVar7 = 0;
    if (0 < iVar6) {
      do {
        FUN_0054c230(iVar7);
        FUN_00551800(param_1[3]);
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar6);
    }
  }
  puVar8 = &DAT_005c43b0;
  FUN_00545f40(&DAT_005c43b0);
  iVar6 = FUN_00548890(puVar8);
  param_1[4] = iVar6;
  if (iVar6 != 0) {
    FUN_00550620(iVar6,0);
  }
  return;
}


