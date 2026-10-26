
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047b1e0(int *param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  int iStack_c;
  undefined4 auStack_8 [2];
  
  (**(code **)(*param_1 + 0x2c))(1);
  FUN_00498880(auStack_8,&iStack_c);
  fVar3 = (float10)FUN_00498730();
  fVar1 = (float)(fVar3 + (float10)(float)param_1[0x42]);
  param_1[0x42] = (int)fVar1;
  switch(param_1[0x41]) {
  case 1:
    iVar2 = FUN_0047b850(auStack_8[0],iStack_c);
    fVar1 = _DAT_0059e4e0;
    param_1[0x39] = iVar2;
    if (fVar1 < (float)param_1[0x42]) {
      param_1[0x42] = (int)((float)param_1[0x42] - _DAT_0059e4e0);
      if (iStack_c <= param_1[1] + param_1[0x3f]) {
        FUN_0047bae0(0xffffffff);
      }
      if (param_1[2] - param_1[0x3f] <= iStack_c) {
        FUN_0047bae0(1);
        (**(code **)(*param_1 + 0x54))();
        return;
      }
    }
    break;
  case 2:
    if (_DAT_0059e4e0 < fVar1) {
      param_1[0x42] = (int)(fVar1 - _DAT_0059e4e0);
      FUN_0047bae0(0xffffffff);
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    break;
  case 3:
    if (_DAT_0059e4e0 < fVar1) {
      param_1[0x42] = (int)(fVar1 - _DAT_0059e4e0);
      FUN_0047bae0(1);
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    break;
  case 4:
    iStack_c = iStack_c - param_1[0x47];
    param_1[0x44] = iStack_c;
    if (-1 < iStack_c) {
      if (param_1[0x45] < iStack_c) {
        param_1[0x44] = param_1[0x45];
      }
      FUN_0047be00();
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    param_1[0x44] = 0;
    FUN_0047be00();
    (**(code **)(*param_1 + 0x54))();
    return;
  case 5:
    if (_DAT_0059e7f8 < fVar1) {
      param_1[0x42] = (int)(fVar1 - _DAT_0059e7f8);
      FUN_0047bb40(iStack_c);
    }
  }
  (**(code **)(*param_1 + 0x54))();
  return;
}

