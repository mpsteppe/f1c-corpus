// Function: FUN_0049de40 @ 0049de40
// Size (bytes): 805


void __thiscall FUN_0049de40(int param_1,char param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x54);
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    return;
  }
  iStack_24 = 0x49de75;
  uVar3 = __ftol();
  uVar3 = uVar3 & 0x80000001;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
  }
  iStack_24 = 0;
  uStack_28 = 0;
  uStack_2c = 0x3f800000;
  uStack_30 = 0x3f800000;
  uStack_34 = 0;
  uStack_38 = 0;
  uStack_40 = 0;
  uStack_44 = 0;
  iStack_3c = iVar1;
  if (param_2 != '\0') {
    uStack_48 = 0x49deb1;
    FUN_005432f0();
    return;
  }
  uStack_48 = 0x49dec2;
  FUN_005432f0();
  if (*(int *)(DAT_007c54e0 + 0xcd4) == 0) {
LAB_0049defa:
    bVar2 = 0;
LAB_0049defc:
    iStack_24 = (-(uint)bVar2 & 0xff01ff00) - 0x10000;
    uStack_28 = 0x35;
    uStack_2c = 0x12;
    uStack_30 = 0x1a;
    uStack_34 = 0xc3;
    uStack_38 = 0x49df21;
    FUN_00543440();
  }
  else if ((*(char *)(DAT_007c54e0 + 0xd14) != '\0') || (uVar3 == 0)) {
    if ((*(int *)(DAT_007c54e0 + 0xcd4) == 0) || (*(char *)(DAT_007c54e0 + 0xd14) == '\0'))
    goto LAB_0049defa;
    bVar2 = 1;
    goto LAB_0049defc;
  }
  if (*(int *)(DAT_007c54e0 + 0xd18) == 0) {
LAB_0049df59:
    bVar2 = 0;
  }
  else {
    if ((*(char *)(DAT_007c54e0 + 0xd58) == '\0') && (uVar3 != 0)) goto LAB_0049df7d;
    if ((*(int *)(DAT_007c54e0 + 0xd18) == 0) || (*(char *)(DAT_007c54e0 + 0xd58) == '\0'))
    goto LAB_0049df59;
    bVar2 = 1;
  }
  iStack_24 = (-(uint)bVar2 & 0xff01ff00) - 0x10000;
  uStack_28 = 0x23;
  uStack_2c = 0xe;
  uStack_30 = 0x23;
  uStack_34 = 0x2a;
  uStack_38 = 0x49df7d;
  FUN_00543440();
LAB_0049df7d:
  iStack_24 = 0xf;
  uStack_28 = 0x19;
  uStack_2c = 0x10;
  uStack_30 = 0x30;
  uStack_34 = 2;
  uStack_38 = 0x49df8e;
  FUN_0049e570();
  uStack_38 = 0xf;
  iStack_3c = 0x19;
  uStack_40 = 0x10;
  uStack_44 = 0xa4;
  uStack_48 = 0;
  uStack_4c = 0x49dfa2;
  FUN_0049e570();
  uStack_4c = 0xf;
  uStack_50 = 0x19;
  uStack_54 = 0x4a;
  uStack_58 = 0x30;
  uStack_5c = 3;
  uStack_60 = 0x49dfb3;
  FUN_0049e570();
  uStack_60 = 0xf;
  FUN_0049e570(1,0xa4,0x4a,0x19);
  FUN_0049e7b0(2,0x30,4,0x19,7);
  FUN_0049e7b0(0,0xa4,4,0x19,7);
  FUN_0049e7b0(3,0x30,0x5e,0x19,7);
  FUN_0049e7b0(1,0xa4,0x5e,0x19,7);
  if ((*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) ==
       *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) &&
     (bVar4 = DAT_007c8b40 != '\0', DAT_007c8b40 = '\0', bVar4)) {
    uVar5 = 0xffffff00;
  }
  else {
    uVar5 = 0xff00ff00;
  }
  FUN_00543440(0x3b,0x31,0x2e,6,uVar5);
  FUN_00543440(0x57,0x2d,0x10,0xd,0xff00);
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0049c700(&uStack_60,0xf);
    FUN_0049f6a0(&uStack_60,0x3a,0x69,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049c770(&uStack_60,0xf);
    FUN_0049f6a0(&uStack_60,0x42,0x69,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
    FUN_0049c830(&uStack_60,0xf);
    FUN_0049f6a0(&uStack_60,0xb8,0x69,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),1);
    FUN_0049c8a0(&uStack_60,0xf);
    FUN_0049f6a0(&uStack_60,0xc0,0x69,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0);
  }
  return;
}


