// Function: thunk_FUN_004c0f60 @ 004c1660
// Size (bytes): 5


uint __fastcall thunk_FUN_004c0f60(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_EAX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0xb150));
  if (*(char *)(param_1 + 0xb150) == '\0') {
    uVar2 = FUN_004c11d0();
    uVar3 = FUN_004c0910(uVar2);
    iVar7 = 0x67;
    iVar6 = param_1;
    do {
      uVar3 = CONCAT31((int3)(uVar3 >> 8),*(char *)(iVar6 + 0x1b0));
      if (*(char *)(iVar6 + 0x1b0) != '\0') {
        uVar2 = FUN_004c11d0();
        uVar3 = FUN_004c0910(uVar2);
      }
      iVar6 = iVar6 + 0x1b4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (*(int *)(param_1 + 0xb14c) == 7) {
      uVar5 = 0;
      do {
        iVar6 = 0;
        uVar3 = param_1 + 0xaf6cU;
        if (uVar5 != 0) {
          uVar3 = uVar5 * 0x1b4 + -0x1b4 + param_1;
        }
        if (*(char *)(uVar3 + 0x1b0) != '\0') {
          piVar1 = (int *)(uVar3 + 0x198);
          uVar3 = 0;
          do {
            if (uVar5 != uVar3) {
              uVar4 = param_1 + 0xaf6cU;
              if (uVar3 != 0) {
                uVar4 = uVar3 * 0x1b4 + -0x1b4 + param_1;
              }
              if ((*(char *)(uVar4 + 0x1b0) != '\0') && (*piVar1 < *(int *)(uVar4 + 0x198))) {
                iVar6 = iVar6 + 1;
              }
            }
            uVar3 = uVar3 + 1;
          } while ((int)uVar3 < 0x68);
          if (uVar5 == 0) {
            *(int *)(param_1 + 0xb108) = iVar6;
          }
          else {
            uVar3 = uVar5 * 0x1b4;
            *(int *)((uVar3 - 0x18) + param_1) = iVar6;
          }
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < 0x68);
    }
    *(undefined1 *)(param_1 + 0xb150) = 1;
  }
  return uVar3 & 0xffffff00;
}


