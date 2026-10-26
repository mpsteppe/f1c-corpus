// Function: FUN_005508a0 @ 005508a0
// Strings:  [%s\%s, Illegal mesh file name %s, Could not locate mesh file %s, Error loading MAS animation file %s, Error loading animation file %s]


undefined4 __thiscall FUN_005508a0(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 local_300 [256];
  char local_200 [256];
  char local_100 [256];
  
  *(undefined1 *)(param_1 + 7) = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_200 + -(int)param_2)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_200);
  if ((local_200[0] == '\0') || (iVar3 = FUN_00587c20(local_200,&DAT_005dc050), iVar3 == 0)) {
    FUN_0058815f(local_300,s_Illegal_mesh_file_name__s_005dbef0,param_2);
  }
  else {
    iVar3 = FUN_00587db0(local_200,&DAT_005be828);
    if (iVar3 == 0) {
      iVar3 = 0;
      if (0 < DAT_008b8e30) {
        puVar6 = &DAT_008b5a3c;
        do {
          FUN_0058815f(local_100,s__s__s_005c2d64,puVar6,local_200);
          iVar4 = FUN_00587db0(local_100,&DAT_005be828);
          if (iVar4 != 0) {
            iVar5 = FUN_00550ad0(iVar4,0);
            if (iVar5 != 0) {
              FUN_00587d02(iVar4);
              param_2 = local_100;
              goto LAB_005509e4;
            }
            FUN_00587d02(iVar4);
            break;
          }
          iVar3 = iVar3 + 1;
          puVar6 = puVar6 + 0x84;
        } while (iVar3 < DAT_008b8e30);
      }
      if (iVar3 == DAT_008b8e30) {
        iVar3 = 0;
        for (iVar4 = DAT_008b8f14; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x130)) {
          iVar5 = FUN_00560230(local_200);
          if (iVar5 == 0) {
            iVar4 = FUN_00550ad0(*(undefined4 *)(iVar4 + 0x10),iVar4);
            if (iVar4 != 0) {
              pcVar2 = s_Error_loading_MAS_animation_file_005dc00c;
              goto LAB_00550a7b;
            }
            break;
          }
          iVar3 = iVar3 + 1;
        }
      }
      else {
        iVar3 = -1;
      }
      if (iVar3 != DAT_008b6ac0) {
        return 0;
      }
      pcVar2 = s_Could_not_locate_mesh_file__s_005dbf0c;
LAB_00550a7b:
      FUN_0058815f(local_300,pcVar2,param_2);
    }
    else {
      iVar4 = FUN_00550ad0(iVar3,0);
      if (iVar4 == 0) {
        FUN_00587d02(iVar3);
        return 0;
      }
      FUN_00587d02(iVar3);
LAB_005509e4:
      FUN_0058815f(local_300,s_Error_loading_animation_file__s_005dc030,param_2);
    }
  }
  FUN_0053c590(0xffffffff,local_300);
  return 0xffffffff;
}


