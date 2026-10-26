// Function: FUN_00464c10 @ 00464c10
// Size (bytes): 261


int __fastcall FUN_00464c10(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_4;
  
  FUN_00568ba0();
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  iVar2 = param_1 + 0x8c;
  local_4 = 0x68;
  do {
    FUN_00401000(iVar2,1,0x68,&LAB_00464d20);
    *(undefined4 *)(iVar2 + 0x220) = 0;
    *(undefined4 *)(iVar2 + 0x224) = 0;
    *(undefined2 *)(iVar2 + 0x228) = 0;
    piVar1 = operator_new(8);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      *piVar1 = iVar2;
      piVar1[1] = -0x40800000;
    }
    *(int **)(iVar2 + 0x22c) = piVar1;
    FUN_00464a40();
    iVar2 = iVar2 + 0x230;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  *(undefined4 *)(param_1 + 0xe5b0) = 0;
  *(undefined4 *)(param_1 + 0xe5b4) = 0;
  *(undefined4 *)(param_1 + 0xe5b8) = 0;
  *(undefined4 *)(param_1 + 0xe5bc) = 0;
  *(undefined4 *)(param_1 + 0xe5c0) = 0;
  *(undefined4 *)(param_1 + 0xe5c4) = 0;
  *(undefined4 *)(param_1 + 0xe5c8) = 0;
  *(undefined4 *)(param_1 + 0xe5cc) = 0;
  FUN_00568be0(1);
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x60) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe40c) = 0;
  puVar3 = (undefined4 *)(param_1 + 0xe410);
  for (iVar2 = 0x68; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  return param_1;
}


