// Function: FUN_004c7ca0 @ 004c7ca0
// Size (bytes): 289


void FUN_004c7ca0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_008acfcc != 0) {
    FUN_0054c110(7,0x1000);
  }
  local_c = DAT_008afe88;
  if (DAT_008afe88 != 0) {
    local_4 = FUN_005452f0();
    iVar6 = 0;
    if (0 < local_4) {
      do {
        iVar2 = FUN_00545340(iVar6);
        if (iVar2 != 0) {
          local_10 = 0;
          FUN_0054c150(&local_10,0x1000);
          if ((local_10 != 0) &&
             (puVar3 = (undefined4 *)FUN_004c9a50(), puVar3 != (undefined4 *)0x0)) {
            iVar4 = FUN_004c8f80(iVar2);
            iVar2 = local_8;
            if (iVar4 == 0) {
              if (*(int *)(local_8 + 0xc) == 0) {
                puVar5 = operator_new(0x10);
                if (puVar5 == (undefined4 *)0x0) {
                  puVar5 = (undefined4 *)0x0;
                }
                else {
                  *puVar5 = 0;
                  puVar5[1] = 0;
                  puVar5[2] = 0;
                  puVar5[3] = 0;
                }
                *(undefined4 **)(iVar2 + 0xc) = puVar5;
              }
              piVar1 = *(int **)(iVar2 + 0xc);
              if (piVar1 != (int *)0x0) {
                puVar5 = operator_new(0xc);
                if (puVar5 == (undefined4 *)0x0) {
                  puVar5 = (undefined4 *)0x0;
                }
                else {
                  *puVar5 = puVar3;
                  puVar5[1] = 0;
                  *(undefined1 *)(puVar5 + 2) = 1;
                }
                if (*piVar1 == 0) {
                  *piVar1 = (int)puVar5;
                  piVar1[2] = (int)puVar5;
                  piVar1[1] = (int)puVar5;
                  piVar1[3] = piVar1[3] + 1;
                }
                else {
                  *(undefined4 **)(piVar1[1] + 4) = puVar5;
                  piVar1[1] = (int)puVar5;
                  piVar1[3] = piVar1[3] + 1;
                }
                goto LAB_004c7dac;
              }
            }
            (**(code **)*puVar3)(1);
          }
        }
LAB_004c7dac:
        iVar6 = iVar6 + 1;
      } while (iVar6 < local_4);
    }
  }
  return;
}


