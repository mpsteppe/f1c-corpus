
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004c9840(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int unaff_EDI;
  undefined4 uStack_218;
  undefined4 uStack_214;
  float fStack_210;
  undefined4 uStack_20c;
  undefined1 uStack_208;
  undefined1 auStack_200 [512];
  
  piVar5 = DAT_008ac4c4;
  if (DAT_008ac4c4 != (int *)0x0) {
    uStack_218 = 0;
    uStack_214 = 0xffffffff;
    FUN_00566650(&DAT_005ea438);
    fStack_210 = -NAN;
    uStack_20c = 0xffffffff;
    uStack_208 = 0;
    puVar4 = DAT_005ec3e0;
    if (DAT_005ec3e0 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058815f(auStack_200,s__s_s_s_005c6784,puVar4,s_Ambient__005d3448,s_pithorn_wav_005d347c);
    FUN_00566650(auStack_200);
    fStack_210 = -NAN;
    uStack_20c = 0xffffffff;
    uStack_208 = 0;
    piVar5 = (int *)(**(code **)(*piVar5 + 0x5c))(&uStack_218,0,1);
    *(int **)(param_1 + 0x1c) = piVar5;
    if (piVar5 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar5 + 0x14))();
      fVar3 = DAT_007cf578;
      uVar2 = _DAT_007cf554;
      if (iVar6 == 0) {
        iVar6 = *(int *)(param_1 + 0x1c);
        fStack_210 = DAT_007cf578;
        fVar1 = _DAT_0059e43c;
        if (_DAT_007cf530 < DAT_0059e440 == (_DAT_007cf530 == DAT_0059e440)) {
          fVar1 = _DAT_0059e43c / _DAT_007cf530;
        }
        *(float *)(iVar6 + 0x1c) = fVar1;
        *(float *)(iVar6 + 0x20) = _DAT_0059e43c - fVar1 * fVar3;
        *(undefined4 *)(iVar6 + 0x24) = uVar2;
      }
      else {
        if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x1c))(1);
        }
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
    }
    if (unaff_EDI != 0) {
      FUN_00587bcf(unaff_EDI);
    }
  }
  return 0;
}

