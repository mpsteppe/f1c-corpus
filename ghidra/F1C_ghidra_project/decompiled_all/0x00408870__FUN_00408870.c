// Function: FUN_00408870 @ 00408870
// Strings:  [2SEATER, 3SEATER, LEFT_OF_PITS, RIGHT_OF_PITS]


void __fastcall FUN_00408870(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  if (*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x24))(1);
  }
  pvVar1 = operator_new(200);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00456170();
  }
  *(int *)(param_1 + 0x24) = iVar2;
  if (iVar2 != 0) {
    FUN_00566650(s_2SEATER_005be8b0);
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x30) = 0x42700000;
    *(undefined4 *)(iVar2 + 0x34) = 0x42340000;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x38) = 0x42700000;
    *(undefined4 *)(iVar2 + 0x3c) = 0x42340000;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x40) = 0x3e800000;
    *(undefined4 *)(iVar2 + 0x44) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x48) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x4c) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x50) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x54) = 0x3f000000;
    *(undefined4 *)(iVar2 + 0x58) = 0x3f000000;
    *(undefined1 *)(*(int *)(param_1 + 0x24) + 0x60) = 1;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 100) = 0;
    *(undefined4 *)(iVar2 + 0x68) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x70) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x74) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x78) = 0;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(undefined4 *)(iVar2 + 0x84) = 0;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0x94) = 0xb7388ca4;
    *(undefined4 *)(iVar2 + 0x98) = 0x3da77814;
    *(undefined4 *)(iVar2 + 0x9c) = 0x3eca2c45;
    iVar2 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar2 + 0xa0) = 0xbe4ccccd;
    *(undefined4 *)(iVar2 + 0xa4) = 0;
    *(undefined4 *)(iVar2 + 0xa8) = 0x38991794;
    FUN_00456fb0(0);
  }
  if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x28))(1);
  }
  pvVar1 = operator_new(200);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00456170();
  }
  *(int *)(param_1 + 0x28) = iVar2;
  if (iVar2 != 0) {
    FUN_00566650(s_3SEATER_005be8b8);
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x30) = 0x42700000;
    *(undefined4 *)(iVar2 + 0x34) = 0x42340000;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x38) = 0x42700000;
    *(undefined4 *)(iVar2 + 0x3c) = 0x42340000;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x40) = 0x3e4ccccd;
    *(undefined4 *)(iVar2 + 0x44) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x48) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x4c) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x50) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x54) = 0x3f000000;
    *(undefined4 *)(iVar2 + 0x58) = 0x3f000000;
    *(undefined1 *)(*(int *)(param_1 + 0x28) + 0x60) = 1;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 100) = 0;
    *(undefined4 *)(iVar2 + 0x68) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x70) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x74) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x78) = 0;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(undefined4 *)(iVar2 + 0x84) = 0;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x88) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x43b40000;
    *(undefined4 *)(iVar2 + 0x90) = 0x43b40000;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0x94) = 0xbe87a1c2;
    *(undefined4 *)(iVar2 + 0x98) = 0xbb49ea9a;
    *(undefined4 *)(iVar2 + 0x9c) = 0x3ed810c7;
    iVar2 = *(int *)(param_1 + 0x28);
    *(undefined4 *)(iVar2 + 0xa0) = 0xbda8e714;
    *(undefined4 *)(iVar2 + 0xa4) = 0xbd68815e;
    *(undefined4 *)(iVar2 + 0xa8) = 0x3896feb5;
    FUN_00456fb0(0);
  }
  if (*(undefined4 **)(param_1 + 0x2c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x2c))(1);
  }
  pvVar1 = operator_new(200);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00456170();
  }
  *(int *)(param_1 + 0x2c) = iVar2;
  if (iVar2 != 0) {
    FUN_00566650(s_LEFT_OF_PITS_005be8c0);
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x30) = 0x42700000;
    *(undefined4 *)(iVar2 + 0x34) = 0x42340000;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x3c) = 0x42340000;
    *(undefined4 *)(iVar2 + 0x38) = 0x42700000;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x40) = 0x3e4ccccd;
    *(undefined4 *)(iVar2 + 0x44) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x48) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x4c) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x50) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x54) = 0x3f000000;
    *(undefined4 *)(iVar2 + 0x58) = 0x3f000000;
    *(undefined1 *)(*(int *)(param_1 + 0x2c) + 0x60) = 1;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 100) = 0;
    *(undefined4 *)(iVar2 + 0x68) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x70) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x74) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x78) = 0;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(undefined4 *)(iVar2 + 0x84) = 0;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x88) = 0x40000000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x3ecccccd;
    *(undefined4 *)(iVar2 + 0x90) = 0x40000000;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0xa0) = 0xbf0ae47e;
    *(undefined4 *)(iVar2 + 0xa4) = 0x3f0ee98a;
    *(undefined4 *)(iVar2 + 0xa8) = 0x3c1ce076;
    iVar2 = *(int *)(param_1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(undefined4 *)(iVar2 + 0x84) = 0x41200000;
    FUN_00456fb0(0x40a00000);
  }
  if (*(undefined4 **)(param_1 + 0x30) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x30))(1);
  }
  pvVar1 = operator_new(200);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00456170();
  }
  *(int *)(param_1 + 0x30) = iVar2;
  if (iVar2 != 0) {
    FUN_00566650(s_RIGHT_OF_PITS_005be8d0);
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x30) = 0x42700000;
    *(undefined4 *)(iVar2 + 0x34) = 0x42340000;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x3c) = 0x42340000;
    *(undefined4 *)(iVar2 + 0x38) = 0x42700000;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x40) = 0x3e4ccccd;
    *(undefined4 *)(iVar2 + 0x44) = 0x43fa0000;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x48) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x4c) = 0x3f800000;
    *(undefined4 *)(iVar2 + 0x50) = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x54) = 0x3f000000;
    *(undefined4 *)(iVar2 + 0x58) = 0x3f000000;
    *(undefined1 *)(*(int *)(param_1 + 0x30) + 0x60) = 1;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 100) = 0;
    *(undefined4 *)(iVar2 + 0x68) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x70) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x74) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x78) = 0;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(undefined4 *)(iVar2 + 0x84) = 0;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x88) = 0x40000000;
    *(undefined4 *)(iVar2 + 0x8c) = 0x3ecccccd;
    *(undefined4 *)(iVar2 + 0x90) = 0x40000000;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0xa0) = 0xbf142720;
    *(undefined4 *)(iVar2 + 0xa4) = 0xbf11b941;
    *(undefined4 *)(iVar2 + 0xa8) = 0xbc01f106;
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(iVar2 + 0x80) = 0;
    *(undefined4 *)(iVar2 + 0x84) = 0x41200000;
    FUN_00456fb0(0x40a00000);
  }
  return;
}


