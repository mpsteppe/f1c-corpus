// Function: FUN_00551390 @ 00551390
// Size (bytes): 171


void __thiscall FUN_00551390(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0x14);
  if (iVar1 < param_3) {
    *(int *)(param_1 + 8) = iVar1 + -1;
  }
  else {
    *(int *)(param_1 + 8) = param_3;
  }
  puVar3 = *(uint **)(param_1 + 0x18);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      if ((*puVar3 & 0xff) < 0xff) {
        iVar2 = *(int *)(param_1 + 8) * 0x20 +
                *(int *)((*puVar3 & 0xff) * 0x2c + 0x28 + *(int *)(*(int *)(param_1 + 0x1c) + 0x10))
        ;
        FUN_0053b4c0(puVar3 + 1);
        puVar3[0xd] = *(uint *)(iVar2 + 4);
        puVar3[0xe] = *(uint *)(iVar2 + 8);
        puVar3[0xf] = *(uint *)(iVar2 + 0xc);
      }
      puVar3 = puVar3 + 0x22;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x14));
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10000;
  if (param_2 != 0) {
    FUN_0054b330(0x40,0x20,0);
  }
  return;
}


