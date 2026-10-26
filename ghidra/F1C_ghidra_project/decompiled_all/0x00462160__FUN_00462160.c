// Function: FUN_00462160 @ 00462160
// Strings:  [numplayers, mapname, hostname]


void __thiscall FUN_00462160(int *param_1,int param_2,char param_3,char param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x1b79c) == 0) {
    return;
  }
  if (param_3 != '\0') {
    if (param_2 == DAT_007d1020) {
      *(bool *)(iVar1 + 0xc4) = *(char *)(iVar1 + 0xc4) == '\0';
    }
    else {
      *(undefined1 *)(iVar1 + 0xc4) = 1;
    }
  }
  DAT_007d1020 = param_2;
  if (param_2 < DAT_007d1028) {
    DAT_007d1020 = DAT_007d1028;
  }
  else if (DAT_007d102c < param_2) {
    DAT_007d1020 = DAT_007d102c;
  }
  iVar1 = FUN_00461fc0();
  if (iVar1 != 0) {
    DAT_007cd2a0 = 1;
    return;
  }
  if (DAT_007d1020 == 1) {
    pcVar2 = &DAT_005c61ec;
  }
  else {
    if (DAT_007d1020 == 2) {
      uVar3 = 3;
      pcVar2 = s_mapname_005c5c20;
      goto LAB_0046222f;
    }
    if (DAT_007d1020 != 3) {
      uVar3 = 3;
      pcVar2 = s_hostname_005c5c34;
      goto LAB_0046222f;
    }
    pcVar2 = s_numplayers_005c5c14;
  }
  uVar3 = 0;
LAB_0046222f:
  FUN_00563ec0(pcVar2,uVar3);
  if (param_4 != '\0') {
    DAT_007cd2a0 = 1;
    return;
  }
  return;
}


