// Function: FUN_004a24d0 @ 004a24d0
// Strings:  [10SEC_STARTERREAR, 10SEC_STARTERREAR, 10SEC_SMAN4, 10SEC_SMAN4, 10SEC_SMAN3, 10SEC_SMAN3, 10SEC_SMAN2, 10SEC_SMAN2]


char __fastcall FUN_004a24d0(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  FUN_00589901(param_1);
  iVar1 = 0xe;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_FRONT_JACK_UP_005cd32c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\0';
  }
  iVar1 = 0x10;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_FRONT_JACK_DOWN_005cd31c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x01';
  }
  iVar1 = 0xd;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_REAR_JACK_UP_005cd30c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x02';
  }
  iVar1 = 0xf;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_REAR_JACK_DOWN_005cd2fc;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x03';
  }
  iVar1 = 0xe;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_LOLLIPOP_DOWN_005cd2ec;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x04';
  }
  iVar1 = 0xc;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_LOLLIPOP_UP_005cd2e0;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x05';
  }
  iVar1 = 8;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_FUEL_IN_005cd2d8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x06';
  }
  iVar1 = 9;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_FUEL_OUT_005cd2cc;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\a';
  }
  iVar1 = 0x11;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_FRONT_LEFT_WHEEL_005cd2b8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\b';
  }
  iVar1 = 0x12;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_FRONT_RIGHT_WHEEL_005cd2a4;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\t';
  }
  iVar1 = 0x10;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_REAR_LEFT_WHEEL_005cd294;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\n';
  }
  iVar1 = 0x11;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_REAR_RIGHT_WHEEL_005cd280;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\v';
  }
  iVar1 = 0x12;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_REAR_RIGHT_WHEEL2_005cd26c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\f';
  }
  iVar1 = 0x14;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_LOLLIPOP_DOWN_005cd258;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\r';
  }
  iVar1 = 0x12;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_LOLLIPOP_UP_005cd244;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x0e';
  }
  iVar1 = 0x11;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_FMAN_FLEFT_005cd230;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x0f';
  }
  iVar1 = 0xb;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_NMAN_005cd224;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x10';
  }
  iVar1 = 0xb;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_RMAN_005cd218;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x11';
  }
  iVar1 = 0xc;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_RMAN2_005cd20c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x12';
  }
  iVar1 = 0xb;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_SMAN_005cd200;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x13';
  }
  iVar1 = 0xc;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_SMAN2_005cd1f4;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x14';
  }
  iVar1 = 0xc;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_SMAN3_005cd1e8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x15';
  }
  iVar1 = 0xc;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = s_10SEC_SMAN4_005cd1dc;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    return '\x16';
  }
  bVar4 = true;
  iVar1 = 0x12;
  pcVar2 = s_10SEC_STARTERREAR_005cd1c8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *param_1 == *pcVar2;
    param_1 = param_1 + 1;
    pcVar2 = pcVar2 + 1;
  } while (bVar4);
  return !bVar4 + '\x17';
}


