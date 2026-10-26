// Function: FUN_00493fc0 @ 00493fc0
// Strings:  [Generic_Button_Normal_TgtCheck, Generic_Button_Normal, Prelinked Gizmo - %s]


/* WARNING: Type propagation algorithm not settling */

undefined4 * __thiscall FUN_00493fc0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_84 [3];
  undefined1 auStack_81 [129];
  
  if (param_2 == 0) {
    return (undefined4 *)0x0;
  }
  _local_84 = param_1;
  puVar1 = (undefined4 *)(**(code **)(**(int **)(param_1 + 0x1a4) + 0x18))(param_2);
  if (puVar1 != (undefined4 *)0x0) goto LAB_00494136;
  iVar4 = 0;
  while (iVar2 = FUN_00588410(param_2,(&PTR_s_Generic_Button_Normal_005cc270)[iVar4]), iVar2 != 0) {
    iVar4 = iVar4 + 1;
    if (0x16 < iVar4) {
      return (undefined4 *)0x0;
    }
  }
  switch(iVar4) {
  case 0:
    pvVar3 = operator_new(0xe4);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_00487220(0,0);
    break;
  case 1:
    pvVar3 = operator_new(0xe4);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_00487220(1,0);
    break;
  case 2:
    pvVar3 = operator_new(0xe4);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_00487660(0,0);
    break;
  case 3:
    puVar1 = operator_new(0xec);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    FUN_00487220(0,0);
    *puVar1 = &PTR_LAB_005ac8d8;
    *(undefined1 *)(puVar1 + 0x39) = 0;
    puVar1[0x3a] = 0;
    break;
  case 4:
    puVar1 = operator_new(0xf0);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    FUN_00485e30();
    *puVar1 = &PTR_FUN_005ac1d0;
    FUN_004883a0();
    break;
  case 5:
    pvVar3 = operator_new(0xec);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar5 = 1;
    goto LAB_00494125;
  case 6:
    pvVar3 = operator_new(0xec);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar5 = 2;
    goto LAB_00494125;
  case 7:
    pvVar3 = operator_new(0xec);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar5 = 3;
LAB_00494125:
    puVar1 = (undefined4 *)FUN_00488b00(uVar5,0xffffffff);
    break;
  case 8:
    pvVar3 = operator_new(0x110);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048aa40();
    break;
  case 9:
    pvVar3 = operator_new(0x304);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048b420(0,0,0,0,0,0);
    break;
  case 10:
    pvVar3 = operator_new(0x174);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_004893c0();
    break;
  case 0xb:
    puVar1 = operator_new(0xec);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    FUN_00485e30();
    *puVar1 = &PTR_FUN_005ac830;
    puVar1[0x38] = &DAT_007c7c7c;
    puVar1[0x39] = 0x323232;
    puVar1[0x3a] = 0xc0c0c;
    break;
  case 0xc:
    pvVar3 = operator_new(0x118);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_00488180();
    break;
  case 0xd:
    pvVar3 = operator_new(0xe4);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_00487ed0(0,0);
    break;
  default:
    return (undefined4 *)0x0;
  case 0xf:
    pvVar3 = operator_new(0x128);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048d740();
    break;
  case 0x10:
    pvVar3 = operator_new(0xf0);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048d660();
    break;
  case 0x11:
    pvVar3 = operator_new(0xf0);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048e070();
    break;
  case 0x12:
    pvVar3 = operator_new(0x104);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048e300();
    break;
  case 0x13:
    pvVar3 = operator_new(0xf0);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048e600();
    break;
  case 0x14:
    pvVar3 = operator_new(0x180);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048eaa0();
    break;
  case 0x15:
    pvVar3 = operator_new(0xe8);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_0048fe60();
    break;
  case 0x16:
    pvVar3 = operator_new(0xf4);
    if (pvVar3 == (void *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)FUN_00490250();
  }
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_00494136:
  if (puVar1[0x23] == 0) {
    return puVar1;
  }
  _local_84 = CONCAT31(stack0xffffff7d,DAT_005ea438);
  puVar1 = (undefined4 *)((int)local_84 + 1);
  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  *(undefined2 *)puVar1 = 0;
  *(undefined1 *)((int)puVar1 + 2) = 0;
  FUN_0058815f(local_84,s_Prelinked_Gizmo____s_005cc990,param_2);
  FUN_00493c80(1,local_84);
  return (undefined4 *)0x0;
}


