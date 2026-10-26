// Function: FUN_005404d0 @ 005404d0
// Size (bytes): 637


undefined4 __thiscall
FUN_005404d0(int *param_1,int param_2,int param_3,int param_4,uint param_5,undefined4 *param_6,
            undefined4 *param_7)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_28;
  undefined4 *puStack_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  puVar6 = param_6;
  uVar5 = *(uint *)(param_2 + 0x18);
  if ((uVar5 & 0x40000) != 0) {
    FUN_0055ca90(param_2,0);
    local_10 = param_3;
    local_8 = param_3 + param_5;
    local_c = param_4;
    local_4 = param_4 + (int)param_6;
    iVar2 = (**(code **)(*(int *)param_1[0x440] + 0x90))
                      ((int *)param_1[0x440],1,&local_10,1,param_7,0,0);
    *param_1 = iVar2;
    FUN_0055ca90(0,0);
    return 0;
  }
  if ((uVar5 & 1) == 0) {
    if ((uVar5 & 2) != 0) {
      piVar3 = *(int **)(param_2 + 0xc);
      goto LAB_0054057b;
    }
  }
  else {
    piVar3 = *(int **)(param_2 + 8);
LAB_0054057b:
    if (piVar3 != (int *)0x0) {
      local_14 = param_4 + (int)param_6;
      local_18 = param_5 + param_3;
      local_20 = param_3;
      local_1c = param_4;
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,&local_28,&local_20,0);
      *param_1 = iVar2;
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      param_6 = puStack_24;
      *(undefined4 *)(param_2 + 0x28) = local_28;
    }
  }
  if ((*(uint *)(param_2 + 0x18) & 4) == 0) {
    if ((*(uint *)(param_2 + 0x18) & 8) != 0) {
      piVar3 = *(int **)(param_2 + 0x14);
      goto LAB_005405dd;
    }
  }
  else {
    piVar3 = *(int **)(param_2 + 0x10);
LAB_005405dd:
    if (piVar3 != (int *)0x0) {
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_3 + param_5;
      local_14 = param_4 + (int)puVar6;
      iVar2 = (**(code **)(*piVar3 + 0x40))(piVar3,0,&local_28,&local_20,0);
      *param_1 = iVar2;
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(param_2 + 0x28) = local_28;
      param_6 = puStack_24;
    }
  }
  iVar2 = *(int *)(param_2 + 0x28);
  switch(*(undefined4 *)(param_2 + 0x30)) {
  case 7:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    break;
  case 8:
    if (0 < (int)puVar6) {
      do {
        uVar5 = param_5;
        puVar7 = param_6;
        if (0 < (int)param_5) {
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar7 = param_7;
            puVar7 = puVar7 + 1;
          }
          param_6 = param_6 + param_5;
        }
        param_6 = param_6 + ((iVar2 >> 2) - param_5);
        puVar6 = (undefined4 *)((int)puVar6 + -1);
      } while (puVar6 != (undefined4 *)0x0);
    }
    break;
  default:
    uVar1 = FUN_0055ceb0(*(undefined4 *)(param_2 + 0x30),param_7);
    if (0 < (int)puVar6) {
      param_7 = puVar6;
      do {
        puVar6 = param_6;
        if (0 < (int)param_5) {
          puVar6 = (undefined4 *)((int)param_6 + param_5 * 2);
          for (uVar5 = param_5 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
            *param_6 = CONCAT22(uVar1,uVar1);
            param_6 = param_6 + 1;
          }
          for (uVar5 = (uint)((param_5 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined2 *)param_6 = uVar1;
            param_6 = (undefined4 *)((int)param_6 + 2);
          }
        }
        param_6 = (undefined4 *)((int)puVar6 + ((iVar2 >> 1) - param_5) * 2);
        param_7 = (undefined4 *)((int)param_7 + -1);
      } while (param_7 != (undefined4 *)0x0);
    }
  }
  if ((*(uint *)(param_2 + 0x18) & 1) == 0) {
    if ((*(uint *)(param_2 + 0x18) & 2) != 0) {
      piVar3 = *(int **)(param_2 + 0xc);
      goto LAB_005406f9;
    }
  }
  else {
    piVar3 = *(int **)(param_2 + 8);
LAB_005406f9:
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 0x28))(piVar3);
      *param_1 = iVar2;
    }
  }
  if ((*(uint *)(param_2 + 0x18) & 4) == 0) {
    if ((*(uint *)(param_2 + 0x18) & 8) == 0) goto LAB_00540736;
    piVar3 = *(int **)(param_2 + 0x14);
  }
  else {
    piVar3 = *(int **)(param_2 + 0x10);
  }
  if (piVar3 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar3 + 0x44))(piVar3,0);
    *unaff_EBP = uVar4;
    param_2 = local_4;
  }
LAB_00540736:
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffbff;
  return 0;
}


