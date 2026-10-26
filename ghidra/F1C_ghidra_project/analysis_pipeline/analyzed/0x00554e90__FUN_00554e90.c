// Function: FUN_00554e90 @ 00554e90
// Size (bytes): 218


undefined4 __thiscall FUN_00554e90(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_EBX;
  
  iVar1 = *(int *)(param_2 + 0x54);
  if (*(int *)(iVar1 + 0x14) != 0) {
    return 0xfffffffe;
  }
  iVar2 = (**(code **)(**(int **)(iVar1 + 0x10) + 0x48))(*(int **)(iVar1 + 0x10),0);
  *param_1 = iVar2;
  if (*(char *)(iVar1 + 0x18) < '\0') {
    switch(*(undefined4 *)(iVar1 + 0x30)) {
    case 9:
      unaff_EBX = 0x31545844;
      break;
    case 10:
      unaff_EBX = 0x32545844;
      break;
    case 0xb:
      unaff_EBX = 0x33545844;
      break;
    case 0xc:
      unaff_EBX = 0x34545844;
      break;
    case 0xd:
      unaff_EBX = 0x35545844;
    }
  }
  else {
    FUN_0055c650(&stack0xfffffffc,*(undefined4 *)(iVar1 + 0x30),0);
  }
  iVar2 = *(int *)(param_2 + 0x50);
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  iVar2 = (**(code **)(*(int *)param_1[0x440] + 0x50))
                    ((int *)param_1[0x440],*(undefined4 *)(iVar1 + 0x1c),
                     *(undefined4 *)(iVar1 + 0x20),iVar2,0,unaff_EBX,0,iVar1 + 0x14);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 8;
    return 0;
  }
  return 0xffffffff;
}


