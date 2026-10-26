// Function: FUN_004e3360 @ 004e3360
// Strings:  [RestrictionLimit, DefaultLimit, ForceFieldSphere, ForceFieldSphere, RestrictionSphere, RestrictionSphere]


void FUN_004e3360(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6,int param_7,int param_8)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  float unaff_retaddr;
  int iStack00000028;
  int in_stack_00000360;
  int in_stack_0000036c;
  int in_stack_00000374;
  int in_stack_0000037c;
  int in_stack_00000384;
  int in_stack_0000038c;
  int in_stack_00001e30;
  
  FUN_005881c0();
  FUN_0042e320();
  FUN_004f34e0();
  iVar5 = 0;
  FUN_004f4270();
  FUN_004dd450();
  iStack00000028 = 0;
  FUN_005668b0();
  puVar6 = (undefined4 *)&stack0x000001e0;
  for (iVar4 = 0x60; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  cVar1 = FUN_00566b20();
  if (cVar1 != '\0') {
    iVar4 = FUN_00566cc0();
    while (iVar4 != 0) {
      iVar4 = FUN_005651b0();
      if (iVar4 == 0) {
        iVar4 = FUN_00565870();
        if (iVar4 != 0) {
          iStack00000028 = iStack00000028 + 1;
        }
        iVar4 = FUN_00565870();
        if (iVar4 != 0) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar4 = FUN_00566cc0();
    }
    piVar2 = operator_new(iVar5 * 0x18 + 4);
    if (piVar2 == (int *)0x0) {
      param_5 = (int *)0x0;
    }
    else {
      *piVar2 = iVar5;
      param_5 = piVar2 + 1;
      if (-1 < iVar5 + -1) {
        do {
          piVar2[5] = 0;
          piVar2[6] = 0;
          iVar5 = iVar5 + -1;
          piVar2 = piVar2 + 6;
        } while (iVar5 != 0);
      }
    }
    pvVar3 = operator_new(iStack00000028 * 0x14);
    FUN_00566d30();
    iVar5 = FUN_00566cc0();
    while (iVar5 != 0) {
      iVar5 = FUN_005651b0();
      if (iVar5 == 0) {
        FUN_00565870();
        FUN_00565870();
        iVar5 = FUN_00565870();
        if (iVar5 != 0) {
          piVar2 = (int *)((int)pvVar3 + param_2 * 0x14);
          *piVar2 = param_6;
          piVar2[1] = param_7;
          piVar2[2] = param_8;
          *(float *)((int)pvVar3 + param_2 * 0x14 + 0xc) = unaff_retaddr * unaff_retaddr;
          *(undefined4 *)((int)pvVar3 + param_2 * 0x14 + 0x10) = 0x3f800000;
          param_2 = param_2 + 1;
        }
        iVar5 = FUN_00565870();
        if (iVar5 != 0) {
          piVar2 = param_5 + param_4 * 6;
          *piVar2 = param_6;
          piVar2[1] = param_7;
          piVar2[2] = param_8;
          param_5[param_4 * 6 + 3] = (int)(unaff_retaddr * unaff_retaddr);
          param_5[param_4 * 6 + 4] = 0;
          param_5[param_4 * 6 + 5] = 0;
          param_4 = param_4 + 1;
        }
      }
      iVar5 = FUN_00566cc0();
    }
    FUN_00566b90();
  }
  *(undefined4 *)(extraout_ECX + 0xba8) = 1;
  FUN_004de610();
  if (((*(int *)(extraout_ECX + 0x5e4) != 0) && (*(char *)(extraout_ECX + 0x624) != '\0')) &&
     (*(char *)(extraout_ECX + 0x625) != '\0')) {
    *(int *)(extraout_ECX + 0xba8) = *(int *)(extraout_ECX + 0xba8) + 1;
    FUN_004de610();
  }
  if (((*(int *)(extraout_ECX + 0x628) != 0) && (*(char *)(extraout_ECX + 0x668) != '\0')) &&
     (*(char *)(extraout_ECX + 0x669) != '\0')) {
    *(int *)(extraout_ECX + 0xba8) = *(int *)(extraout_ECX + 0xba8) + 1;
    FUN_004de610();
  }
  piVar2 = (int *)(extraout_ECX + 0x66c);
  iVar5 = 8;
  do {
    if (((*piVar2 != 0) && ((char)piVar2[0x10] != '\0')) && (*(char *)((int)piVar2 + 0x41) != '\0'))
    {
      *(int *)(extraout_ECX + 0xba8) = *(int *)(extraout_ECX + 0xba8) + 1;
      FUN_004de610();
    }
    piVar2 = piVar2 + 0x11;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_005668d0();
  FUN_004dd470();
  if (in_stack_0000038c != 0) {
    FUN_00587bcf();
  }
  if (in_stack_00000384 != 0) {
    FUN_00587bcf();
  }
  if (in_stack_0000037c != 0) {
    FUN_00587bcf();
  }
  if (in_stack_00000374 != 0) {
    FUN_00587bcf();
  }
  if (in_stack_0000036c != 0) {
    FUN_00587bcf();
  }
  if (in_stack_00000360 != 0) {
    FUN_00587bcf();
  }
  FUN_0042ddd0();
  if (in_stack_00001e30 != 0) {
    FUN_00587bcf();
  }
  return;
}


