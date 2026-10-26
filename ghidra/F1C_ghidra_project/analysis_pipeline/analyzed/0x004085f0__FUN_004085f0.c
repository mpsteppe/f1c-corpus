// Function: FUN_004085f0 @ 004085f0
// Size (bytes): 290


void __thiscall FUN_004085f0(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int iVar2;
  float10 fVar3;
  float10 extraout_ST0;
  undefined4 uVar4;
  
  switch(*(undefined4 *)(param_1 + 0x34)) {
  case 0:
    iVar2 = *(int *)(param_1 + 0x10);
    break;
  case 1:
    iVar2 = *(int *)(param_1 + 0x14);
    break;
  case 2:
    iVar2 = *(int *)(param_1 + 0x18);
    break;
  case 3:
    iVar2 = *(int *)(param_1 + 0x1c);
    break;
  case 4:
    iVar2 = *(int *)(param_1 + 0x3c) * 200 + *(int *)(param_1 + 0x20);
    break;
  case 5:
    iVar2 = *(int *)(param_1 + 0x24);
    break;
  case 6:
    iVar2 = *(int *)(param_1 + 0x28);
    break;
  case 7:
    iVar2 = *(int *)(param_1 + 0x2c);
    break;
  case 8:
    iVar2 = *(int *)(param_1 + 0x30);
    break;
  default:
    return;
  }
  if (iVar2 == 0) {
    return;
  }
  if (param_2 == -1) {
    fVar3 = (float10)FUN_004084a0();
    uVar4 = 1;
    uVar1 = DAT_005ea55c;
LAB_0040867f:
    FUN_00456f70(uVar1,uVar4,(float)fVar3);
  }
  else if (param_2 == 1) {
    uVar4 = FUN_004084a0();
    uVar1 = DAT_005be870;
    fVar3 = extraout_ST0;
    goto LAB_0040867f;
  }
  if (param_3 == -1) {
    fVar3 = (float10)FUN_004084a0();
    iVar2 = extraout_EDX;
    uVar1 = DAT_005ea55c;
  }
  else {
    if (param_3 != 1) goto LAB_004086c2;
    fVar3 = (float10)FUN_004084a0();
    iVar2 = extraout_EDX_00;
    uVar1 = DAT_005be870;
  }
  (**(code **)(iVar2 + 0xc))(uVar1,0,(float)fVar3);
LAB_004086c2:
  if (param_4 != -1) {
    if (param_4 == 1) {
      fVar3 = (float10)FUN_004084a0();
      (**(code **)(extraout_EDX_02 + 0x10))(DAT_005ea55c,1,(float)fVar3);
    }
    return;
  }
  fVar3 = (float10)FUN_004084a0();
  (**(code **)(extraout_EDX_01 + 0x10))(DAT_005be870,1,(float)fVar3);
  return;
}


