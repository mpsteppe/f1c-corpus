// Function: FUN_0041c0f0 @ 0041c0f0
// Size (bytes): 714


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041c0f0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  uVar1 = param_2 + 1;
  uVar5 = 0;
  if (DAT_005c329c == 0) {
    return;
  }
  puVar3 = &DAT_005f0738;
  while (*puVar3 != uVar1) {
    uVar5 = uVar5 + 1;
    puVar3 = puVar3 + 0x1230;
    if (DAT_005c329c <= uVar5) {
      return;
    }
  }
  iVar6 = 0x18d;
  FUN_004144d0();
  if (DAT_007d0410 == 2) goto LAB_0041c377;
  iVar2 = *(int *)(param_1 + uVar5 * 4);
  if (iVar2 == 1) {
    if (uVar1 == 1) {
      iVar6 = 0x204;
    }
    else if ((_DAT_0059e450 <= (float)(int)uVar1 / (float)(int)DAT_005c329c) || (6 < (int)uVar1)) {
      if (((float)(int)uVar1 / (float)(int)DAT_005c329c <= _DAT_0059e800) || ((int)uVar1 < 0xb)) {
        if (((double)(int)uVar1 < (double)(int)DAT_005c329c * _DAT_0059e838) &&
           (0xb < (int)DAT_005c329c)) {
          iVar6 = 0x206;
        }
      }
      else {
        iVar6 = 0x207;
      }
    }
    else {
      iVar6 = 0x205;
    }
    goto LAB_0041c377;
  }
  if (iVar2 == 2) {
    iVar6 = *(int *)(DAT_007c54e8 + 0x4060);
    if ((int)uVar1 < iVar6) {
      if (uVar1 == iVar6 - 1U) {
        uVar4 = uVar1 & 0x80000001;
        bVar7 = uVar4 == 0;
        if ((int)uVar4 < 0) {
          bVar7 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar7) {
          iVar6 = 0x20b;
          goto LAB_0041c377;
        }
      }
      iVar6 = (3 < (int)((iVar6 - uVar1) + -1)) + 0x209;
    }
    else {
      if (uVar1 == iVar6 + 1U) {
        uVar4 = uVar1 & 0x80000001;
        bVar7 = uVar4 == 0;
        if ((int)uVar4 < 0) {
          bVar7 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (bVar7) {
          iVar6 = 0x20b;
          goto LAB_0041c377;
        }
      }
      iVar6 = (3 < (int)((uVar1 - iVar6) + -1)) + 0x20c;
    }
    goto LAB_0041c377;
  }
  if ((iVar2 != 3) || (DAT_007d0410 != 4)) goto LAB_0041c377;
  iVar6 = *(int *)(DAT_007c54e8 + 0x4060);
  if ((int)uVar1 < iVar6) {
    if (uVar1 == iVar6 - 1U) {
      uVar4 = uVar1 & 0x80000001;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
      }
      if (uVar4 != 0) {
        iVar6 = 0x213;
        goto LAB_0041c20f;
      }
    }
    iVar6 = ((int)(param_2 + 4) <= iVar6) + 0x216;
  }
  else {
    if (uVar1 == iVar6 + 1U) {
      uVar4 = uVar1 & 0x80000001;
      bVar7 = uVar4 == 0;
      if ((int)uVar4 < 0) {
        bVar7 = (uVar4 - 1 | 0xfffffffe) == 0xffffffff;
      }
      if (bVar7) {
        iVar6 = 0x213;
        goto LAB_0041c20f;
      }
    }
    iVar6 = (iVar6 + 3 <= (int)uVar1) + 0x210;
  }
LAB_0041c20f:
  uVar4 = _rand();
  uVar4 = uVar4 & 0x80000001;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
  }
  if (uVar4 == 1) {
    uVar4 = *(uint *)(DAT_007c54e8 + 0x489c);
    switch(iVar6) {
    case 0x210:
      iVar6 = 0x20e;
      uVar1 = uVar4;
      break;
    case 0x211:
      iVar6 = 0x20f;
      uVar1 = uVar4;
      break;
    default:
      break;
    case 0x213:
      iVar6 = 0x212;
      uVar1 = uVar4;
      break;
    case 0x216:
      iVar6 = 0x214;
      uVar1 = uVar4;
      break;
    case 0x217:
      iVar6 = 0x215;
      uVar1 = uVar4;
    }
  }
LAB_0041c377:
  param_2 = uVar1;
  FUN_004144f0(iVar6,*(undefined4 *)(&DAT_005f0f74 + uVar5 * 0x48c0),param_2,0xffffffff,0xffffffff,
               0xc0000000,0xc0000000);
  FUN_00418560(local_20);
  return;
}


