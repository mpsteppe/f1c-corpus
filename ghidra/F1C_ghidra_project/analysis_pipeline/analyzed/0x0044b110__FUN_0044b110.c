// Function: FUN_0044b110 @ 0044b110
// Size (bytes): 600


uint FUN_0044b110(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int extraout_EDX;
  uint extraout_EDX_00;
  uint uVar4;
  uint uVar5;
  uint local_88;
  char local_84 [4];
  int local_80;
  uint local_7c;
  undefined1 local_78 [4];
  undefined1 local_74 [24];
  undefined1 local_5c [92];
  
  FUN_00448ee0(local_78);
  FUN_0044af20(local_74,param_1);
  FUN_0044b040(local_74,local_78,local_5c);
  uVar5 = 0;
  local_80 = 2 - (int)local_84;
  local_88 = 0;
  do {
    local_84[uVar5] = '\0';
    uVar4 = uVar5;
    if ((int)uVar5 < (int)(local_84 + local_80 + uVar5)) {
      do {
        uVar2 = (uVar4 == 3) - 1 & uVar4;
        cVar1 = FUN_0044b090(uVar2 * 0x5c + 0x10 + param_1,local_5c,
                             *(undefined4 *)(*(int *)(param_1 + uVar2 * 4) + 4 + uVar5 * 8));
        if (cVar1 == '\0') {
          local_88 = local_88 + 1;
          local_84[uVar5] = '\x01';
          break;
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < extraout_EDX);
    }
    uVar5 = uVar5 + 1;
    if (2 < (int)uVar5) {
      uVar2 = 1;
      if ((int)local_88 < 2) {
        if (local_88 == 0) {
          uVar4 = 0;
          while( true ) {
            if (uVar4 == 2) {
              iVar3 = 0;
            }
            else {
              iVar3 = uVar4 + 1;
            }
            cVar1 = FUN_0044b090(uVar4 * 0x5c + 0x10 + param_1,local_5c,
                                 *(undefined4 *)(*(int *)(param_1 + uVar4 * 4) + 4 + iVar3 * 8));
            if (cVar1 == '\0') break;
            uVar4 = uVar4 + 1;
            if (2 < (int)uVar4) {
              return 4;
            }
          }
          local_84[0] = '\x01';
          local_84[1] = '\x01';
          local_84[2] = 1;
          uVar5 = 3;
          uVar2 = extraout_EDX_00;
        }
        local_80 = 0;
        do {
          if (local_84[local_80] != '\0') {
            if (local_80 == 0) {
              uVar5 = 0;
              local_7c = 2;
              uVar4 = uVar2;
              local_88 = uVar2;
            }
            else if (local_80 == 1) {
              local_88 = 2;
              local_7c = 0;
              uVar4 = 2;
              uVar5 = uVar2;
            }
            else if (local_80 == 2) {
              local_88 = 3;
              uVar4 = 0;
              uVar5 = 2;
              local_7c = uVar2;
            }
            FUN_0044af60(local_74,param_1,local_88,0);
            FUN_0044b040(local_74,local_78,local_5c);
            cVar1 = FUN_0044b090(uVar5 * 0x5c + 0x10 + param_1,local_5c,
                                 *(undefined4 *)(*(int *)(param_1 + uVar5 * 4) + 4 + uVar4 * 8));
            if (cVar1 != '\0') {
              FUN_0044af60(local_74,param_1,local_88,1);
              FUN_0044b040(local_74,local_78,local_5c);
              cVar1 = FUN_0044b090(uVar4 * 0x5c + 0x10 + param_1,local_5c,
                                   *(undefined4 *)(*(int *)(param_1 + uVar4 * 4) + 4 + local_7c * 8)
                                  );
              if (cVar1 != '\0') {
                return local_88;
              }
            }
            uVar2 = 1;
          }
          local_80 = local_80 + 1;
        } while (local_80 < 3);
      }
      return 0;
    }
  } while( true );
}


