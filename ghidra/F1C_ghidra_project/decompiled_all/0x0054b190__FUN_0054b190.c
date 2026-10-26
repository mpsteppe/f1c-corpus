// Function: FUN_0054b190 @ 0054b190
// Strings:  [CUBE_MTS_4.10, CUBE_MTS_4.10]


undefined4 FUN_0054b190(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  pcVar2 = s_CUBE_MTS_4_10_005dbfc0;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_2 + -0x5dbfc0] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x18);
  puVar4 = (undefined4 *)(param_1 + 0x1c);
  puVar5 = (undefined4 *)(param_2 + 0x1c);
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(param_2 + 0xdc) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(param_2 + 0xe0) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_2 + 0xf4) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(param_2 + 0xf8) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_2 + 0x100) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_2 + 0x110) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(param_2 + 0x114) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(param_2 + 0x120) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(param_2 + 0x124) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(param_2 + 0x128) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(param_2 + 300) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(param_2 + 0x118) = *(undefined4 *)(param_1 + 0xb8);
  *(undefined4 *)(param_2 + 0x11c) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(param_2 + 0x134) = *(undefined4 *)(param_1 + 0xd4);
  return 0;
}


