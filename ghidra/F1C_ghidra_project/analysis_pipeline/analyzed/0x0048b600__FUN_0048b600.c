// Function: FUN_0048b600 @ 0048b600
// Size (bytes): 476


int __thiscall FUN_0048b600(int *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined1 uVar2;
  char cVar3;
  undefined1 *puVar4;
  int iVar5;
  int local_14;
  undefined1 local_c [4];
  int local_8;
  int local_4;
  
  if ((char)param_1[0xbb] == '\0') {
    return 0;
  }
  iVar5 = 0;
  local_14 = 0;
  if (0 < param_3) {
    do {
      sVar1 = *(short *)(param_2 + local_14 * 2);
      if (sVar1 == 1) {
LAB_0048b766:
        if (*(char *)((int)param_1 + 0xe5) == '\0') {
          FUN_0048b910(0);
        }
        (**(code **)(*param_1 + 0xb0))();
        iVar5 = 1;
LAB_0048b78e:
        puVar4 = (undefined1 *)param_1[0x28];
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        FUN_0049a490(puVar4,param_1[0xbc]);
        (**(code **)(*param_1 + 0x2c))(1);
      }
      else {
        if (sVar1 == 0xe) {
          if (param_1[0xbd] != param_1[0xbc]) {
            param_1[0xbd] = param_1[0xbd] + -1;
          }
          *(undefined1 *)param_1[0xbd] = 0;
          iVar5 = 1;
          goto LAB_0048b78e;
        }
        if (sVar1 == 0x1c) goto LAB_0048b766;
        uVar2 = FUN_00455b30(sVar1);
        cVar3 = FUN_0048b560(uVar2);
        if (cVar3 != '\0') {
          if (param_1[0xbd] - param_1[0xbc] < param_1[0xbe] + -1) {
            *(undefined1 *)param_1[0xbd] = uVar2;
            iVar5 = param_1[0xbd];
            param_1[0xbd] = iVar5 + 1;
            *(undefined1 *)(iVar5 + 1) = 0;
            if (((param_1[0xbf] != 0) && (param_1[0x32] != 0)) && (param_1[0x10] != 0)) {
              puVar4 = *(undefined1 **)(param_1[0x32] + 0x40);
              if (puVar4 == (undefined1 *)0x0) {
                puVar4 = &DAT_005ea438;
              }
              FUN_00498560(puVar4);
              FUN_004983b0(param_1[0xbf],&local_4,local_c,1);
              FUN_004983b0(param_1[0xbc],&local_8,local_c,1);
              if (local_4 < local_8) {
                if (param_1[0xbd] != param_1[0xbc]) {
                  param_1[0xbd] = param_1[0xbd] + -1;
                }
                *(undefined1 *)param_1[0xbd] = 0;
              }
            }
          }
          iVar5 = 1;
          goto LAB_0048b78e;
        }
        if (iVar5 != 0) goto LAB_0048b78e;
      }
      local_14 = local_14 + 1;
    } while (local_14 < param_3);
  }
  return iVar5;
}


