// Function: FUN_00408e20 @ 00408e20
// Strings:  [SWINGMAN, COCKPIT, TVCOCKPIT, NOSECAM, LOCALCAM]


undefined4 FUN_00408e20(undefined4 param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 unaff_retaddr;
  int in_stack_00002060;
  
  FUN_005881c0();
  if (in_stack_00002060 != 0) {
    FUN_005668b0();
    puVar8 = (undefined4 *)&stack0x000005dc;
    for (iVar6 = 0x60; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    FUN_00456170();
    FUN_00456170();
    FUN_00456170();
    FUN_00456170();
    iVar6 = 0x20;
    do {
      FUN_00456170();
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    param_1 = 0;
    cVar1 = FUN_00566b20();
    if (cVar1 == '\0') {
      iVar6 = 0x20;
      do {
        FUN_004562a0();
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    else {
      iVar6 = FUN_00566cc0();
      while (iVar6 != 0) {
        iVar6 = FUN_005651b0();
        if ((iVar6 == 0) && (iVar6 = FUN_00565520(), iVar6 != 0)) {
          iVar6 = FUN_00588410();
          if (iVar6 == 0) {
            FUN_004562f0();
          }
          else {
            iVar6 = FUN_00588410();
            if (iVar6 == 0) {
              FUN_004562f0();
            }
            else {
              iVar6 = FUN_00588410();
              if (iVar6 == 0) {
                FUN_004562f0();
              }
              else {
                iVar6 = FUN_00588410();
                if (iVar6 == 0) {
                  FUN_004562f0();
                }
                else if (param_1 < 0x20) {
                  FUN_004562f0();
                  param_1 = param_1 + 1;
                }
              }
            }
          }
        }
        iVar6 = FUN_00566cc0();
      }
      if (param_2 != 0) {
        FUN_00566b90();
        if (*(undefined4 **)(extraout_ECX + 0x1c) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(extraout_ECX + 0x1c))();
        }
        pvVar2 = operator_new(200);
        if (pvVar2 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_00456170();
        }
        *(int *)(extraout_ECX + 0x1c) = iVar6;
        if (iVar6 != 0) {
          FUN_00457000();
        }
        if (*(undefined4 **)(extraout_ECX + 0x14) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(extraout_ECX + 0x14))();
        }
        pvVar2 = operator_new(200);
        if (pvVar2 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_00456170();
        }
        *(int *)(extraout_ECX + 0x14) = iVar6;
        if (iVar6 != 0) {
          FUN_00457000();
        }
        if (*(undefined4 **)(extraout_ECX + 0x18) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(extraout_ECX + 0x18))();
        }
        pvVar2 = operator_new(200);
        if (pvVar2 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_00456170();
        }
        *(int *)(extraout_ECX + 0x18) = iVar6;
        if (iVar6 != 0) {
          FUN_00457000();
        }
        if (*(undefined4 **)(extraout_ECX + 0x10) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(extraout_ECX + 0x10))();
        }
        pvVar2 = operator_new(200);
        if (pvVar2 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_00456170();
        }
        *(int *)(extraout_ECX + 0x10) = iVar6;
        if (iVar6 != 0) {
          FUN_00457000();
        }
        if (*(undefined4 **)(extraout_ECX + 0x20) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(extraout_ECX + 0x20))();
        }
        if (param_1 < 1) {
          *(undefined4 *)(extraout_ECX + 0x38) = 0;
          *(undefined4 *)(extraout_ECX + 0x3c) = 0;
        }
        else {
          piVar3 = operator_new(param_1 * 200 + 4);
          if (piVar3 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = piVar3 + 1;
            *piVar3 = param_1;
            iVar6 = param_1;
            if (-1 < param_1 + -1) {
              do {
                FUN_00456170();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          *(int **)(extraout_ECX + 0x20) = piVar4;
          if (piVar4 != (int *)0x0) {
            iVar6 = param_1;
            if (0 < param_1) {
              do {
                FUN_00457000();
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
            *(int *)(extraout_ECX + 0x38) = param_1;
            *(undefined4 *)(extraout_ECX + 0x3c) = 0;
          }
        }
        FUN_00408870();
        if (DAT_005ea510 != 0) {
          FUN_00542520();
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x1c);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x18);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x14);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x10);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          iVar7 = 0;
          *(int *)(iVar6 + 0x44) = param_1;
          if (0 < *(int *)(extraout_ECX + 0x38)) {
            iVar6 = 0;
            do {
              FUN_00456080();
              iVar5 = *(int *)(extraout_ECX + 0x20) + iVar6;
              *(undefined4 *)(iVar5 + 0x40) = unaff_retaddr;
              iVar7 = iVar7 + 1;
              *(int *)(iVar5 + 0x44) = param_1;
              iVar6 = iVar6 + 200;
            } while (iVar7 < *(int *)(extraout_ECX + 0x38));
          }
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x24);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x28);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x2c);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
          FUN_00456080();
          iVar6 = *(int *)(extraout_ECX + 0x30);
          *(undefined4 *)(iVar6 + 0x40) = unaff_retaddr;
          *(int *)(iVar6 + 0x44) = param_1;
        }
        iVar6 = 0x20;
        do {
          FUN_004562a0();
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        FUN_004562a0();
        FUN_004562a0();
        FUN_004562a0();
        FUN_004562a0();
        FUN_005668d0();
        return 0;
      }
      iVar6 = 0x20;
      do {
        FUN_004562a0();
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    FUN_004562a0();
    FUN_004562a0();
    FUN_004562a0();
    FUN_004562a0();
    FUN_005668d0();
  }
  return 1;
}


