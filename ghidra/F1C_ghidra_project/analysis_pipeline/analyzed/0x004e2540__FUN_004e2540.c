// Function: FUN_004e2540 @ 004e2540
// Size (bytes): 203


void __thiscall
FUN_004e2540(int param_1,int param_2,float *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar1 = param_2 * 0x128 + 0xd4 + param_1;
  fVar2 = *param_3 - *(float *)(param_1 + 0x48);
  fVar3 = param_3[1] - *(float *)(param_1 + 0x4c);
  fVar4 = param_3[2] - *(float *)(param_1 + 0x50);
  *(float *)(iVar1 + 0x74) = fVar2;
  *(float *)(iVar1 + 0x78) = fVar3;
  *(float *)(iVar1 + 0x7c) = fVar4;
  *(float *)(iVar1 + 0xb8) = fVar2;
  *(float *)(iVar1 + 0xbc) = fVar3;
  *(float *)(iVar1 + 0xc0) = fVar4;
  *(undefined4 *)(iVar1 + 0xfc) = param_4;
  *(undefined4 *)(iVar1 + 0xf8) = param_5;
  *(undefined4 *)(iVar1 + 200) = param_5;
  *(undefined4 *)(iVar1 + 0xc4) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = param_6;
  FUN_005670d0(param_5,param_6);
  puVar6 = (undefined4 *)(iVar1 + 0xd0);
  puVar7 = (undefined4 *)(iVar1 + 0x8c);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  FUN_00567340(param_4,iVar1 + 0x80);
  return;
}


