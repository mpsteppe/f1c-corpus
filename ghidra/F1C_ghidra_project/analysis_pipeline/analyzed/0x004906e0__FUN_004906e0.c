// Function: FUN_004906e0 @ 004906e0
// Size (bytes): 358


undefined4 * FUN_004906e0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int *local_4;
  
  if ((DAT_007cd9c8 & 1) == 0) {
    DAT_007cd9c8 = DAT_007cd9c8 | 1;
    piVar2 = operator_new(0x20);
    if (piVar2 == (int *)0x0) {
      DAT_007cd9cc = (int *)0x0;
      piVar2 = DAT_007cd9cc;
    }
    else {
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      piVar2[3] = 0;
      piVar2[4] = 0;
      piVar2[5] = 0;
      piVar2[6] = 0;
      piVar2[7] = 0;
      local_4 = operator_new(4);
      if (local_4 == (int *)0x0) {
        local_4 = (int *)0x0;
      }
      else {
        puVar3 = operator_new(0x204);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = 0x20;
          puVar3 = puVar3 + 1;
          iVar6 = 0x20;
          do {
            FUN_004912f0();
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        *local_4 = (int)puVar3;
        puVar3 = operator_new(0xc);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = local_4;
          puVar3[1] = 0;
          *(undefined1 *)(puVar3 + 2) = 1;
        }
        if (*piVar2 == 0) {
          *piVar2 = (int)puVar3;
          piVar2[2] = (int)puVar3;
        }
        else {
          *(undefined4 **)(piVar2[1] + 4) = puVar3;
        }
        piVar2[1] = (int)puVar3;
        piVar2[3] = piVar2[3] + 1;
      }
      iVar6 = 0;
      do {
        iVar1 = *local_4;
        if (iVar1 + iVar6 != 0) {
          piVar4 = operator_new(0xc);
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            *piVar4 = iVar1 + iVar6;
            piVar4[1] = 0;
            *(undefined1 *)(piVar4 + 2) = 0;
          }
          if (piVar2[4] == 0) {
            piVar2[5] = (int)piVar4;
            piVar2[6] = (int)piVar4;
          }
          else {
            piVar4[1] = piVar2[4];
          }
          piVar2[4] = (int)piVar4;
          piVar2[7] = piVar2[7] + 1;
        }
        iVar6 = iVar6 + 0x10;
      } while (iVar6 < 0x200);
    }
    DAT_007cd9cc = piVar2;
    pvVar5 = operator_new(4);
    if (pvVar5 == (void *)0x0) {
      DAT_007cd9d0 = 0;
    }
    else {
      DAT_007cd9d0 = FUN_00491710(1);
    }
    FUN_00587b3e(&LAB_00490850);
  }
  return &DAT_007cd9cc;
}


