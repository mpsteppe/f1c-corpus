// Function: FUN_0055c070 @ 0055c070
// Size (bytes): 549


void __thiscall FUN_0055c070(undefined4 *param_1,int param_2,byte param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined1 local_40 [32];
  undefined4 local_20;
  int iStack_8;
  
  FUN_00553db0();
  if ((*(byte *)(param_2 + 0x24) & 4) == 0) {
    FUN_005424e0(&local_50,&local_4c,&local_48,&local_44);
    local_44 = local_44 + local_4c;
    local_48 = local_48 + local_50;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x90))
                      ((int *)param_1[0x440],1,&local_50,1,
                       *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x7c),0,0);
    *param_1 = uVar2;
  }
  if ((param_3 & 0x10) == 0) {
    local_20 = 5;
    FUN_005546a0(local_40,0);
    FUN_00554790(0x100,0,0);
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],7,0);
    *param_1 = uVar2;
    iVar1 = *(int *)(param_2 + 0x18);
    if (*(int *)(iVar1 + 0x138) != param_1[0x4f3]) {
      param_1[0x4f3] = *(int *)(iVar1 + 0x138);
      FUN_0054b9e0();
    }
    iStack_8 = 0;
    if (0 < *(int *)(iVar1 + 0x118)) {
      puVar6 = (undefined4 *)(*(int *)(iVar1 + 0x11c) + 0x1c);
      do {
        if (((*(uint *)(iVar1 + 0x14) & 0x1000000) == 0) && (*(int *)(iVar1 + 0x13c) == 0)) {
          puVar3 = (undefined4 *)FUN_00540f00(*puVar6,0xa0,puVar6[4],puVar6[-5]);
          iVar5 = puVar6[-5];
          puVar4 = (undefined4 *)puVar6[-4];
          puVar6[1] = puVar3;
          if (0 < iVar5) {
            do {
              *puVar3 = *puVar4;
              puVar3[1] = puVar4[1];
              puVar3[2] = puVar4[2];
              puVar3 = puVar3 + 0x10;
              puVar4 = puVar4 + 0xc;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          FUN_00540f90(*puVar6);
        }
        FUN_00554700(*puVar6);
        uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x154))
                          ((int *)param_1[0x440],*(undefined4 *)(puVar6[2] + 0x18),puVar6[4]);
        *param_1 = uVar2;
        if ((char)((uint)*(undefined4 *)(iVar1 + 0x14) >> 8) < '\0') {
          uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                            ((int *)param_1[0x440],4,0,puVar6[-5],puVar6[5],(int)puVar6[-3] / 3);
        }
        else {
          uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                            ((int *)param_1[0x440],5,0,puVar6[-5],puVar6[5],puVar6[-3] + -2);
        }
        *param_1 = uVar2;
        puVar6 = puVar6 + 0x10;
        iStack_8 = iStack_8 + 1;
      } while (iStack_8 < *(int *)(iVar1 + 0x118));
    }
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x1000000;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],7,param_1[0x4ee]);
    *param_1 = uVar2;
  }
  return;
}


