// Function: FUN_004b4a30 @ 004b4a30
// Size (bytes): 259


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004b4a30(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  uVar2 = 0;
  switch(*param_2 >> 0x1d) {
  case 1:
    iVar7 = 0;
    break;
  case 2:
  case 3:
    iVar7 = 1;
    break;
  case 4:
    iVar7 = 2;
    break;
  default:
    iVar7 = -1;
    break;
  case 6:
    iVar7 = 3;
  }
  iVar4 = (iVar7 + 7) * 0x10;
  puVar3 = *(undefined4 **)(iVar4 + param_1);
  puVar5 = (undefined4 *)(iVar4 + param_1);
  puVar6 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    while ((uint *)*puVar3 != param_2) {
      puVar1 = puVar3 + 1;
      puVar6 = puVar3;
      puVar3 = (undefined4 *)*puVar1;
      if ((undefined4 *)*puVar1 == (undefined4 *)0x0) {
        return uVar2;
      }
    }
    if (puVar3 == (undefined4 *)puVar5[2]) {
      puVar5[2] = puVar3[1];
    }
    if (puVar6 == (undefined4 *)0x0) {
      *puVar5 = puVar3[1];
    }
    else {
      puVar6[1] = puVar3[1];
    }
    if ((undefined4 *)puVar5[1] == puVar3) {
      puVar5[1] = puVar6;
    }
    puVar5[3] = puVar5[3] + -1;
    if (*(char *)(puVar3 + 2) != '\0') {
      FUN_00587bcf(*puVar3);
    }
    FUN_00587bcf(puVar3);
    FUN_004b47a0(0,iVar7,*param_2 & 0xff);
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = param_2;
      puVar3[1] = 0;
      *(undefined1 *)(puVar3 + 2) = 0;
    }
    puVar6 = puVar3;
    puVar5 = puVar3;
    if (DAT_008ab700 != (undefined4 *)0x0) {
      puVar3[1] = DAT_008ab700;
      puVar6 = _DAT_008ab704;
      puVar5 = DAT_008ab708;
    }
    DAT_008ab708 = puVar5;
    _DAT_008ab704 = puVar6;
    DAT_008ab70c = DAT_008ab70c + 1;
    uVar2 = 1;
    DAT_008ab700 = puVar3;
  }
  return uVar2;
}


