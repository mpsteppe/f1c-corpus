// Function: FUN_00496030 @ 00496030
// Size (bytes): 541


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __thiscall FUN_00496030(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if (*(float *)(param_1 + 0xdc) <= DAT_0059e440) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0x157c);
  if (iVar5 == 0) {
    return 0;
  }
  uVar1 = *(undefined4 *)(iVar5 + 4);
  uVar2 = *(undefined4 *)(iVar5 + 0xc);
  if (*(int *)(param_1 + 0xdc) != 0x3c23d70a) goto switchD_004960a2_default;
  if (*(int *)(param_1 + 0x1578) == 0) {
    uVar4 = _rand();
    uVar4 = uVar4 & 0x80000001;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
    }
    *(uint *)(param_1 + 0x1578) = uVar4;
  }
  switch(*(undefined4 *)(param_1 + 0x1578)) {
  case 0:
    uVar4 = _rand();
    uVar4 = uVar4 & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    switch(uVar4) {
    case 0:
      *(undefined4 *)(param_1 + 0x1580) = uVar2;
      *(undefined4 *)(param_1 + 0x1584) = 0xfffffda8;
      break;
    case 1:
      *(undefined4 *)(param_1 + 0x1580) = uVar2;
      *(undefined4 *)(param_1 + 0x1584) = 600;
      break;
    case 2:
      *(undefined4 *)(param_1 + 0x1580) = 800;
      *(undefined4 *)(param_1 + 0x1584) = 0xfffffda8;
      break;
    case 3:
      *(undefined4 *)(param_1 + 0x1580) = 800;
      *(undefined4 *)(param_1 + 0x1584) = uVar1;
      break;
    case 4:
      *(undefined4 *)(param_1 + 0x1580) = 800;
      *(undefined4 *)(param_1 + 0x1584) = 600;
      break;
    case 5:
      *(undefined4 *)(param_1 + 0x1580) = 0xfffffce0;
      *(undefined4 *)(param_1 + 0x1584) = 0xfffffda8;
      break;
    case 6:
      *(undefined4 *)(param_1 + 0x1580) = 0xfffffce0;
      *(undefined4 *)(param_1 + 0x1584) = uVar1;
      break;
    default:
      *(undefined4 *)(param_1 + 0x1580) = 0xfffffce0;
      *(undefined4 *)(param_1 + 0x1584) = 600;
    }
    break;
  case 1:
    iVar5 = _rand();
    iVar5 = iVar5 % 3;
    if (iVar5 == 0) {
      *(undefined4 *)(param_1 + 0x1580) = uVar2;
LAB_004961b4:
      *(undefined4 *)(param_1 + 0x1584) = 0xfffffda8;
    }
    else if (iVar5 == 1) {
      *(undefined4 *)(param_1 + 0x1580) = uVar2;
      *(undefined4 *)(param_1 + 0x1584) = 600;
    }
    else if (iVar5 == 2) {
      *(undefined4 *)(param_1 + 0x1580) = 800;
      goto LAB_004961b4;
    }
  case 2:
  case 3:
  case 4:
    *(undefined4 *)(param_1 + 0x18f0) = 0;
    *(undefined1 *)(param_1 + 0x18ec) = 0;
  }
switchD_004960a2_default:
  fVar6 = (float10)FUN_00498730();
  fVar6 = (float10)*(float *)(param_1 + 0xdc) - fVar6;
  fVar3 = (float10)DAT_0059e440;
  *(float *)(param_1 + 0xdc) = (float)fVar6;
  if (fVar3 < fVar6) {
    fVar3 = (float10)_DAT_0059e6f8;
    FUN_00498740();
    FUN_00495dc0((float)(fVar6 * fVar3));
    FUN_00497100(param_2);
    FUN_00497250(1);
    return 1;
  }
  *(undefined4 *)(param_1 + 0x157c) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  FUN_00497250(1);
  return 1;
}


