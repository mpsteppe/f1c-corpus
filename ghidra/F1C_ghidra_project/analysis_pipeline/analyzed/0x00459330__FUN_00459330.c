// Function: FUN_00459330 @ 00459330
// Size (bytes): 403


int __thiscall FUN_00459330(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = param_2;
  uVar3 = FUN_00415c30();
  FUN_00566650(uVar3);
  FUN_00456110(iVar2 + 0xc);
  FUN_00456130((undefined4 *)(iVar2 + 0x90));
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(iVar2 + 0x90);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(iVar2 + 0x94);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(iVar2 + 0x98);
  FUN_00456040(&param_2,&local_8);
  *(int *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x34) = local_8;
  FUN_00456060(&param_2,&local_8);
  *(int *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0x3c) = local_8;
  FUN_00456080(&param_2,&local_8);
  *(int *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x44) = local_8;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar2 + 0x48);
  FUN_004560a0(&param_2,&local_8);
  *(int *)(param_1 + 0x4c) = param_2;
  *(undefined4 *)(param_1 + 0x50) = local_8;
  FUN_004560c0(&param_2,&local_8);
  *(int *)(param_1 + 0x54) = param_2;
  *(undefined4 *)(param_1 + 0x58) = local_8;
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar2 + 0x5c);
  *(undefined1 *)(param_1 + 0x60) = *(undefined1 *)(iVar2 + 0x60);
  FUN_004560e0(&param_2,&local_8,&local_4);
  *(undefined4 *)(param_1 + 0x68) = local_8;
  *(int *)(param_1 + 100) = param_2;
  *(undefined4 *)(param_1 + 0x6c) = local_4;
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iVar2 + 0x70);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar2 + 0x74);
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(iVar2 + 0x78);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar2 + 0x7c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(iVar2 + 0x80);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar2 + 0x84);
  fVar1 = *(float *)(iVar2 + 0x88);
  *(float *)(param_1 + 0x88) = fVar1;
  *(float *)(param_1 + 0x8c) = fVar1 * fVar1;
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(iVar2 + 0xa4);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar2 + 0xa8);
  FUN_004582e0(iVar2 + 0xb0);
  return param_1;
}


