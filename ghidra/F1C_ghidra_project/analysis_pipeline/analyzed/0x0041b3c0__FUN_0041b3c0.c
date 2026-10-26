// Function: FUN_0041b3c0 @ 0041b3c0
// Size (bytes): 1328


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_0041b3c0(int param_1,undefined4 param_2,undefined4 param_3,float param_4,int param_5,int param_6
            )

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float10 fVar7;
  undefined4 uVar8;
  int local_20 [8];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (*(char *)(DAT_007c54e8 + 0x344c) != '\0') {
    return;
  }
  if (DAT_007c56a8 == 8) {
    return;
  }
  if (DAT_0059e440 <= param_4) {
    if (DAT_005ea3fc < param_4) {
      param_4 = DAT_005ea3fc;
    }
  }
  else {
    param_4 = 0.0;
  }
  FUN_004144d0();
  fVar7 = (float10)FUN_004f0050();
  fVar1 = (float)fVar7;
  iVar3 = FUN_004d7c10(param_4);
  iVar4 = FUN_004d7c10(fVar1);
  bVar6 = iVar4 != iVar3;
  switch(param_2) {
  case 0:
    if ((((*(int *)(param_1 + 0x4f0 + iVar3 * 4) != 2) || (iVar5 = FUN_004d1ad0(iVar3), iVar5 != 0))
        || (*(undefined4 *)(param_1 + 0x4f0 + iVar3 * 4) = 0, DAT_007c56a4 != 7)) ||
       (DAT_007c56a8 == 5)) goto switchD_0041b47f_caseD_1;
    if (iVar3 == 0) {
      if (iVar4 == 1) goto switchD_0041b47f_caseD_1;
      cVar2 = FUN_004189b0(0x8a);
      if (cVar2 == '\0') {
        cVar2 = FUN_004189f0(0x8a);
        if (cVar2 != '\0') goto switchD_0041b47f_caseD_1;
        if (bVar6) goto LAB_0041b677;
        uVar8 = 0x7e;
      }
      else {
        FUN_004189f0(0x8a);
        if (bVar6) {
LAB_0041b677:
          uVar8 = 0x89;
        }
        else {
          uVar8 = 0x7e;
        }
      }
    }
    else if (iVar3 == 1) {
      if (iVar4 == 2) goto switchD_0041b47f_caseD_1;
      cVar2 = FUN_004189b0(0x86);
      if (cVar2 == '\0') {
        cVar2 = FUN_004189f0(0x86);
        if (cVar2 != '\0') goto switchD_0041b47f_caseD_1;
        if (bVar6) goto LAB_0041b5f3;
        uVar8 = 0x7e;
      }
      else {
        FUN_004189f0(0x86);
        if (bVar6) {
LAB_0041b5f3:
          uVar8 = 0x85;
        }
        else {
          uVar8 = 0x7e;
        }
      }
    }
    else {
      if ((iVar3 != 2) || (iVar4 == 0)) goto switchD_0041b47f_caseD_1;
      cVar2 = FUN_004189b0(0x88);
      if (cVar2 == '\0') {
        cVar2 = FUN_004189f0(0x88);
        if (cVar2 != '\0') goto switchD_0041b47f_caseD_1;
        if (bVar6) goto LAB_0041b56f;
        uVar8 = 0x7e;
      }
      else {
        FUN_004189f0(0x88);
        if (bVar6) {
LAB_0041b56f:
          uVar8 = 0x87;
        }
        else {
          uVar8 = 0x7e;
        }
      }
    }
    break;
  default:
    goto switchD_0041b47f_caseD_1;
  case 2:
    if ((iVar4 != iVar3) || (fVar1 + _DAT_0059e828 < param_4)) {
      if (iVar3 == 0) {
        if ((iVar4 != 1) &&
           ((iVar4 != 2 || (fVar7 = (float10)FUN_004d7cf0(fVar1,0), (float10)_DAT_0059e824 <= fVar7)
            ))) {
          FUN_00418a20(0x89);
          FUN_00418a20(0x86);
          FUN_004189f0(0x8a);
          uVar8 = 0x8a;
          goto LAB_0041b7ff;
        }
      }
      else if (iVar3 == 1) {
        if ((iVar4 != 2) &&
           ((iVar4 != 0 || (fVar7 = (float10)FUN_004d7cf0(fVar1,0), (float10)_DAT_0059e824 <= fVar7)
            ))) {
          FUN_00418a20(0x85);
          FUN_00418a20(0x88);
          FUN_004189f0(0x86);
          uVar8 = 0x86;
          goto LAB_0041b7ff;
        }
      }
      else if (((iVar3 == 2) && (iVar4 != 0)) &&
              ((iVar4 != 1 ||
               (fVar7 = (float10)FUN_004d7cf0(fVar1,0), (float10)_DAT_0059e824 <= fVar7)))) {
        FUN_00418a20(0x87);
        FUN_00418a20(0x8a);
        FUN_004189f0(0x88);
        uVar8 = 0x88;
LAB_0041b7ff:
        FUN_004144f0(uVar8,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      }
    }
    if (local_20[0] == -1) {
      return;
    }
    *(undefined4 *)(param_1 + 0x4f0 + iVar3 * 4) = 2;
    goto switchD_0041b47f_caseD_1;
  case 3:
    uVar8 = 0x83;
    break;
  case 5:
    if ((DAT_007c54e8 == 0) || (DAT_007c54e8 != param_5)) goto switchD_0041b47f_caseD_1;
    if (param_6 == 1) {
      uVar8 = 0x7b;
    }
    else if (param_6 == 2) {
      FUN_00418a20(0x7b);
      uVar8 = 0x7c;
    }
    else {
      if (param_6 != 3) goto switchD_0041b47f_caseD_1;
      FUN_00418a20(0x7b);
      FUN_00418a20(0x7c);
      uVar8 = 0x7d;
    }
  }
  FUN_004144f0(uVar8,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
switchD_0041b47f_caseD_1:
  if (local_20[0] != -1) {
    FUN_00418560(local_20);
  }
  return;
}


