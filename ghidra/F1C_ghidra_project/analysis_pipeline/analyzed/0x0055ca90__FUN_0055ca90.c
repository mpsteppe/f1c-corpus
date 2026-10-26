// Function: FUN_0055ca90 @ 0055ca90
// Size (bytes): 386


void __thiscall FUN_0055ca90(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_18;
  int *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = param_2;
  if ((param_2 == 0) || (uVar1 = *(uint *)(param_2 + 0x18), (uVar1 & 0x40000) == 0)) {
    uVar6 = *(undefined4 *)(param_1[0x54b] + 0xc);
    piVar4 = (int *)param_1[0x440];
    iVar3 = *piVar4;
    iVar5 = *(int *)(param_1[0x54a] + 0xc);
LAB_0055cbb8:
    uVar6 = (**(code **)(iVar3 + 0x7c))(piVar4,iVar5,uVar6);
  }
  else {
    iVar5 = *(int *)(param_2 + 0xc);
    if (iVar5 != 0) {
      if ((uVar1 & 0x200000) == 0) {
        if ((*(int *)(param_2 + 4) != 0) &&
           (iVar3 = *(int *)(*(int *)(param_2 + 4) + 0xc), iVar3 != 0)) {
          uVar6 = (**(code **)(*(int *)param_1[0x440] + 0x7c))((int *)param_1[0x440],iVar5,iVar3);
          goto LAB_0055cbbb;
        }
        uVar6 = *(undefined4 *)(param_1[0x54b] + 0xc);
        piVar4 = (int *)param_1[0x440];
        iVar3 = *piVar4;
      }
      else {
        piVar4 = (int *)param_1[0x440];
        iVar3 = *piVar4;
        uVar6 = 0;
      }
      goto LAB_0055cbb8;
    }
    piVar4 = *(int **)(param_2 + 0x14);
    if (piVar4 == (int *)0x0) goto LAB_0055cbbd;
    if ((uVar1 & 0x200000) == 0) {
      uVar6 = (**(code **)(*piVar4 + 0x3c))(piVar4,0,&param_2);
      *param_1 = uVar6;
      if ((*(int *)(iVar2 + 4) == 0) || (iVar5 = *(int *)(*(int *)(iVar2 + 4) + 0xc), iVar5 == 0)) {
        uVar6 = (**(code **)(*(int *)param_1[0x440] + 0x7c))
                          ((int *)param_1[0x440],local_8,*(undefined4 *)(param_1[0x54b] + 0xc));
        *param_1 = uVar6;
        uVar6 = (**(code **)(*local_14 + 8))(local_14);
      }
      else {
        uVar6 = (**(code **)(*(int *)param_1[0x440] + 0x7c))((int *)param_1[0x440],local_8,iVar5);
        *param_1 = uVar6;
        uVar6 = (**(code **)(*local_14 + 8))(local_14);
      }
    }
    else {
      uVar6 = (**(code **)(*(int *)param_1[0x440] + 0x7c))((int *)param_1[0x440],0,0);
    }
  }
LAB_0055cbbb:
  *param_1 = uVar6;
LAB_0055cbbd:
  if (param_3 != 0) {
    local_10 = *(undefined4 *)(iVar2 + 0x1c);
    local_c = *(undefined4 *)(iVar2 + 0x20);
    local_18 = 0;
    local_14 = (int *)0x0;
    local_8 = 0;
    local_4 = 0x3f800000;
    uVar6 = (**(code **)(*(int *)param_1[0x440] + 0xa0))((int *)param_1[0x440],&local_18);
    *param_1 = uVar6;
  }
  return;
}


