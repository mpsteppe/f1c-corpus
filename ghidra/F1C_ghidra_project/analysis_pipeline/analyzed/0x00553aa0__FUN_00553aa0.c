// Function: FUN_00553aa0 @ 00553aa0
// Size (bytes): 549


void __fastcall
FUN_00553aa0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  sbyte sVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  code *local_10;
  code *local_c;
  code *local_8;
  code *local_4;
  
  if (*(int *)(param_6 + 0x30) == 6) {
    iVar8 = (param_5 >> 8 & 0xf800U) + (param_5 >> 5 & 0x7e0U) + (param_5 >> 3 & 0x1fU);
  }
  else {
    iVar8 = param_4;
    if (*(int *)(param_6 + 0x30) == 5) {
      iVar8 = (param_5 >> 9 & 0x7c00U) + (param_5 >> 6 & 0x3e0U) + (param_5 >> 3 & 0x1fU);
    }
  }
  uVar2 = FUN_00543210(0,0);
  if (*(int *)(param_6 + 0x24) == 0x10) {
    local_c = FUN_00553cd0;
    local_10 = FUN_00553d00;
    local_8 = FUN_00561970;
    local_4 = FUN_005619af;
    iVar7 = *(int *)(param_6 + 0x28) >> 1;
    sVar4 = 1;
    param_5 = iVar8;
  }
  else {
    local_c = (code *)&LAB_00553d40;
    local_10 = FUN_00553d70;
    local_8 = FUN_00561a41;
    local_4 = FUN_00561a86;
    iVar7 = *(int *)(param_6 + 0x28) >> 2;
    sVar4 = 2;
  }
  uVar6 = param_3 - param_1 >> 0x1f;
  iVar8 = (param_3 - param_1 ^ uVar6) - uVar6;
  if (iVar8 == 0) {
    (*local_10)(param_4,param_5,iVar7,uVar2);
    goto LAB_00553cae;
  }
  uVar6 = param_4 - param_2 >> 0x1f;
  iVar3 = (param_4 - param_2 ^ uVar6) - uVar6;
  if (iVar3 == 0) {
    (*local_c)(param_2,param_5,iVar7,uVar2);
    goto LAB_00553cae;
  }
  if (iVar8 < iVar3) {
    if (param_4 < param_2) {
      iVar5 = iVar7 * param_4 + param_3;
      bVar1 = param_3 <= param_1;
    }
    else {
      iVar5 = iVar7 * param_2 + param_1;
      bVar1 = param_1 < param_3;
    }
    (*local_4)((iVar8 << sVar4) - iVar3,iVar3 + 1,iVar8 << sVar4,iVar8 - iVar3 << sVar4,
               (uint)bVar1 * 2 + -1,iVar5,param_5,iVar7,uVar2);
    goto LAB_00553cae;
  }
  if (param_3 < param_1) {
    param_3 = iVar7 * param_4 + param_3;
    if (param_2 < param_4) {
LAB_00553c21:
      iVar7 = -iVar7;
    }
  }
  else {
    param_3 = iVar7 * param_2 + param_1;
    if (param_4 <= param_2) goto LAB_00553c21;
  }
  (*local_8)((iVar3 << sVar4) - iVar8,iVar8 + 1,iVar3 << sVar4,iVar3 - iVar8 << sVar4,iVar7,param_3,
             param_5,uVar2);
LAB_00553cae:
  FUN_00543230(0,0);
  return;
}


