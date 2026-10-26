// Function: FUN_0047e0a0 @ 0047e0a0
// Strings:  [%s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, %s%s%s, Wins:]


void __fastcall FUN_0047e0a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_104 [260];
  
  iVar6 = 0;
  iVar4 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x15);
  if ((iVar4 != 0) && (iVar4 = FUN_0048f590(), iVar4 != 0)) {
    if ((*(int *)(iVar4 + 0x48) < 1) || (*(int **)(iVar4 + 0x3c) == (int *)0x0)) {
      iVar6 = 0;
    }
    else {
      iVar6 = **(int **)(iVar4 + 0x3c);
    }
    iVar6 = *(int *)(iVar6 + 0x3c);
  }
  FUN_00489cb0();
  if (iVar6 != 0) {
    piVar3 = *(int **)(param_1 + 0x44);
    while (piVar3 != (int *)0x0) {
      piVar1 = (int *)piVar3[1];
      if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
        if (*piVar2 != 0) {
          FUN_00587bcf(*piVar2);
        }
        FUN_00587bcf(piVar2);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar1;
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    FUN_00486f30(s_Team__005c743c,0xffffffff);
    FUN_00486f30(s_Founded__005c7430,0xffffffff);
    FUN_00486f30(s_Headquarters__005c7420,0xffffffff);
    FUN_00486f30(s_Starts__005c68f8,0xffffffff);
    FUN_00486f30(s_Pole_Positions__005c6888,0xffffffff);
    FUN_00486f30(s_Wins__005c6878,0xffffffff);
    FUN_00486f30(s_Constructor_Championships__005c7404,0xffffffff);
    FUN_004894d0(&stack0xfffffef4);
    iVar4 = iVar6 + 700;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(0);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar4);
    FUN_00489600(auStack_104,0,0,0,0);
    iVar4 = iVar6 + 0x33c;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(1);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar4);
    FUN_00489600(auStack_104,0,0,0,0);
    iVar4 = iVar6 + 0x34c;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(2);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar4);
    FUN_00489600(auStack_104,0,0,0,0);
    iVar4 = iVar6 + 0x38c;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(3);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar4);
    FUN_00489600(auStack_104,0,0,0,0);
    iVar4 = iVar6 + 0x39c;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(4);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar4);
    FUN_00489600(auStack_104,0,0,0,0);
    iVar4 = iVar6 + 0x3ac;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(5);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar4);
    FUN_00489600(auStack_104,0,0,0,0);
    iVar6 = iVar6 + 0x3bc;
    puVar7 = &stack0xfffffef4;
    uVar5 = FUN_00487010(6);
    FUN_0058815f(auStack_104,s__s_s_s_005c6784,uVar5,puVar7,iVar6);
    FUN_00489600(auStack_104,0,0,0,0);
    FUN_0058815f(auStack_104,&DAT_005c2c18,&stack0xfffffef4);
    FUN_00489600(auStack_104,0,0,0,0);
  }
  return;
}


