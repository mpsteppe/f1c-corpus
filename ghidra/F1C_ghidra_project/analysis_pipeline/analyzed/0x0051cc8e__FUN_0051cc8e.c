
void FUN_0051cc8e(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iStack_c;
  int iStack_8;
  
  iVar1 = *(int *)(in_EAX + 0x19c);
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  iVar3 = 0;
  puVar5 = &DAT_005b6900;
  iStack_c = -0xe25100;
  iStack_8 = -0xb2f480;
  iVar4 = 0x2c8d00;
  do {
    *(int *)(iVar3 + *(int *)(iVar1 + 0x10)) = iStack_8 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar1 + 0x14)) = iStack_c >> 0x10;
    *(undefined **)(iVar3 + *(int *)(iVar1 + 0x18)) = puVar5;
    *(int *)(iVar3 + *(int *)(iVar1 + 0x1c)) = iVar4;
    iVar4 = iVar4 + -0x581a;
    puVar5 = puVar5 + -0xb6d2;
    iVar3 = iVar3 + 4;
    iStack_c = iStack_c + 0x1c5a2;
    iStack_8 = iStack_8 + 0x166e9;
  } while (-0x2b34e7 < iVar4);
  return;
}

