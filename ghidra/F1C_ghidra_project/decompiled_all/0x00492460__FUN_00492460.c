// Function: FUN_00492460 @ 00492460
// Strings:  [NORMAL, GIZMO, SOUND_LOSTFOCUS, SOUND_FOCUS, undefined layer type %s, MODAL]


undefined4 __thiscall FUN_00492460(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  char local_80;
  undefined4 local_7f;
  
  local_80 = DAT_005ea438;
  puVar6 = &local_7f;
  for (iVar5 = 0x1f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  iVar5 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  if (param_2 != (char *)0x0) {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(&local_80 + -(int)param_2)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(&local_80);
  }
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + 1;
  iVar3 = FUN_00588410(&local_80,s_NORMAL_005c40e8);
  if (iVar3 == 0) {
    pvVar4 = operator_new(0xbc);
    if (pvVar4 != (void *)0x0) {
      iVar5 = FUN_00499140(0);
      goto LAB_00492551;
    }
  }
  else {
    iVar3 = FUN_00588410(&local_80,s_MODAL_005cc670);
    if (iVar3 != 0) {
      FUN_0058815f(&DAT_007cdcf0,s_undefined_layer_type__s_005cc658,param_2);
      FUN_00493c80(3,&DAT_007cdcf0);
      goto LAB_00492551;
    }
    pvVar4 = operator_new(0xbc);
    if (pvVar4 != (void *)0x0) {
      iVar5 = FUN_00499140(1);
      goto LAB_00492551;
    }
  }
  iVar5 = 0;
LAB_00492551:
  *(int *)(param_1 + 0x1a8) = iVar5;
  FUN_0049a9c0(0,599,0,799);
  FUN_00497510(iVar5);
  iVar3 = FUN_00491fb0();
  while ((iVar3 != 0 && (iVar3 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4), iVar3 == 0))) {
    iVar3 = FUN_005654a0(&DAT_005cc650,&local_80);
    if (iVar3 == 0) {
      iVar3 = FUN_005654a0(s_SOUND_FOCUS_005cc644,&local_80);
      pcVar2 = &local_80;
      if (iVar3 == 0) {
        iVar3 = FUN_005654a0(s_SOUND_LOSTFOCUS_005cc634,pcVar2);
        if (iVar3 == 0) {
          iVar3 = FUN_005654a0(s_GIZMO_005cc5ac,&local_80);
          if (iVar3 == 0) {
            iVar3 = FUN_005654a0(&DAT_005cc62c,&local_80);
            if (iVar3 != 0) {
              FUN_00492710(&local_80);
            }
          }
          else {
            iVar3 = FUN_00492a40(&local_80);
            if (iVar3 != 0) {
              FUN_004975b0(iVar3,*(undefined4 *)(param_1 + 0x1a8));
            }
          }
        }
        else {
          pcVar2 = &local_80;
          do {
            cVar1 = *pcVar2;
            pcVar2[(iVar5 - (int)&local_80) + 0x94] = cVar1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
          FUN_00497d20(&local_80);
        }
      }
      else {
        do {
          cVar1 = *pcVar2;
          pcVar2[(iVar5 - (int)&local_80) + 0x6c] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        FUN_00497d20(&local_80);
      }
    }
    else {
      if (((*(char *)(param_1 + 0x19a) != '\0') && (-1 < *(int *)(param_1 + 0x19c))) &&
         (*(int *)(param_1 + 0x19c) < 4)) {
        FUN_00493e20(&local_80);
      }
      FUN_0049ad50(&local_80);
    }
    iVar3 = FUN_00491fb0();
  }
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x194) + -1;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  return 0;
}


