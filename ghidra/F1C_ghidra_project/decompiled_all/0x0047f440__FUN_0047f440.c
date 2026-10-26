// Function: FUN_0047f440 @ 0047f440
// Strings:  [F1_2002.gdb]


undefined4 * __thiscall FUN_0047f440(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  iVar1 = param_2 + -1;
  if (((iVar1 < 0) || (0x1fb < iVar1)) || (*(int *)(param_1 + 0x191c + iVar1 * 4) != 0)) {
    return (undefined4 *)0x0;
  }
  if (0x1b4 < param_2) goto switchD_0047f48b_caseD_1c;
  if (param_2 == 0x1b4) {
    pvVar2 = operator_new(0x304);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00470230();
      *(undefined4 **)(param_1 + 0x1fe8) = puVar3;
      return puVar3;
    }
    goto LAB_0047f9fb;
  }
  switch(iVar1) {
  case 0:
    puVar3 = operator_new(0xec);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_00487220(0,0);
      puVar3[0x39] = 0;
      puVar3[0x3a] = 0xffffffff;
      *puVar3 = &PTR_LAB_005a7638;
      FUN_00566650(s_F1_2002_gdb_005bf970);
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 1:
    pvVar2 = operator_new(0x17c);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_004685b0();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 2:
    puVar3 = operator_new(0x454);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048c9f0();
      puVar3[0x111] = 0;
      puVar3[0x112] = 0;
      puVar3[0x113] = 0;
      puVar3[0x114] = 0;
      *puVar3 = &PTR_FUN_005a6f48;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 3:
    pvVar2 = operator_new(0x188);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00469880();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 4:
  case 5:
    pvVar2 = operator_new(0x350);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046a220();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 6:
    puVar3 = operator_new(0xe8);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048fe60();
      *puVar3 = &PTR_FUN_005a7588;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 7:
    puVar3 = operator_new(0xe8);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048fe60();
      *puVar3 = &PTR_FUN_005a74d8;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 8:
    puVar3 = operator_new(0xe8);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048fe60();
      *puVar3 = &PTR_FUN_005a7428;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 9:
    puVar3 = operator_new(0xe8);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048fe60();
      *puVar3 = &PTR_FUN_005a7378;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x12:
  case 0x18:
  case 0x19:
    puVar3 = operator_new(0x180);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048eaa0();
      *puVar3 = &PTR_LAB_005a7218;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 0xf:
  case 0x15:
    puVar3 = operator_new(0x19c);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048eaa0();
      FUN_004c5db0();
      *puVar3 = &PTR_FUN_005a7168;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 0x10:
  case 0x17:
    pvVar2 = operator_new(0x18c);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00477410(param_2);
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x11:
    puVar3 = operator_new(0x180);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048eaa0();
      *puVar3 = &PTR_LAB_005a70b8;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 0x13:
    puVar3 = operator_new(0x184);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0048eaa0();
      puVar3[0x60] = 0;
      *puVar3 = &PTR_LAB_005a72c8;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 0x14:
  case 0x16:
    pvVar2 = operator_new(400);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_004766f0(param_2);
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x1a:
    pvVar2 = operator_new(0x17c);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046a4e0();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x1b:
    pvVar2 = operator_new(0x20c);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046a900();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  default:
    goto switchD_0047f48b_caseD_1c;
  case 0x1d:
  case 0x1f:
  case 0x20:
    pvVar2 = operator_new(0x180);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046b580(0,0);
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x1e:
    pvVar2 = operator_new(0x180);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046b580(0,1);
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x21:
    pvVar2 = operator_new(0x180);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_004750f0();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x22:
  case 0x23:
    puVar3 = operator_new(0x174);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_004893c0();
      *puVar3 = &PTR_FUN_005a7008;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    goto LAB_0047f94b;
  case 0x24:
    pvVar2 = operator_new(0x120);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0047a9e0();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x25:
    pvVar2 = operator_new(0x178);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0047be70();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    puVar3 = operator_new(0x178);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_004893c0();
      *puVar3 = &PTR_FUN_005a6e98;
      puVar3[0x5d] = 1;
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
LAB_0047f94b:
    *(undefined4 *)(param_1 + 0x191c + iVar1 * 4) = 0;
    return (undefined4 *)0x0;
  case 0x2a:
    pvVar2 = operator_new(0x178);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046e7d0();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x2b:
    pvVar2 = operator_new(0x178);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0046eec0();
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
    break;
  case 0x2c:
    pvVar2 = operator_new(0xe4);
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00487220(0,0);
      *(undefined4 **)(param_1 + 0x191c + iVar1 * 4) = puVar3;
      return puVar3;
    }
  }
LAB_0047f9fb:
  *(undefined4 *)(param_1 + 0x191c + iVar1 * 4) = 0;
switchD_0047f48b_caseD_1c:
  return *(undefined4 **)(param_1 + 0x191c + iVar1 * 4);
}


