// Function: FUN_004b48e0 @ 004b48e0
// Size (bytes): 304


undefined4 __thiscall FUN_004b48e0(char *param_1,uint *param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  
  if (*param_1 != '\0') {
    switch(*param_2 >> 0x1d) {
    case 1:
      iVar5 = 0;
      break;
    case 2:
    case 3:
      iVar5 = 1;
      break;
    case 4:
      iVar5 = 2;
      break;
    default:
      iVar5 = -1;
      break;
    case 6:
      iVar5 = 3;
    }
    cVar1 = FUN_004b4760(iVar5,param_2);
    if (cVar1 == '\0') {
      puVar7 = (uint *)0x0;
      FUN_004ba780();
      if (DAT_008ab708 != (undefined4 *)0x0) {
        puVar7 = (uint *)*DAT_008ab708;
        *(undefined1 *)(DAT_008ab708 + 2) = 0;
        cVar1 = FUN_004bb6b0(puVar7,1);
        if (cVar1 == '\0') {
          puVar7 = (uint *)0x0;
        }
      }
      if (puVar7 == (uint *)0x0) {
        pvVar2 = operator_new(4);
        if (pvVar2 == (void *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_004ba950(0);
        }
        FUN_004bac40(uVar3,0);
        puVar7 = (uint *)FUN_004bacf0();
      }
      FUN_004b3a90(param_2);
      piVar6 = (int *)(param_1 + (iVar5 + 7) * 0x10);
      if (puVar7 != (uint *)0x0) {
        puVar4 = operator_new(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = puVar7;
          puVar4[1] = 0;
          *(undefined1 *)(puVar4 + 2) = 0;
        }
        if (*piVar6 == 0) {
          *piVar6 = (int)puVar4;
          piVar6[2] = (int)puVar4;
        }
        else {
          *(undefined4 **)(piVar6[1] + 4) = puVar4;
        }
        piVar6[1] = (int)puVar4;
        piVar6[3] = piVar6[3] + 1;
        FUN_004b47a0(1,iVar5,*puVar7 & 0xff);
        return 1;
      }
    }
  }
  return 0;
}


