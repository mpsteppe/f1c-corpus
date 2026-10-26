// Function: FUN_004b44e0 @ 004b44e0
// Size (bytes): 248


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b44e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  void *pvVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  
  DAT_008ab6f0 = (undefined4 *)0x0;
  DAT_008ab6f4 = (undefined4 *)0x0;
  _DAT_008ab6f8 = (undefined4 *)0x0;
  _DAT_008ab6fc = 0;
  DAT_008ab700 = (int *)0x0;
  _DAT_008ab704 = (int *)0x0;
  DAT_008ab708 = (int *)0x0;
  DAT_008ab70c = 0;
  piVar6 = operator_new(4);
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    pvVar7 = operator_new(0x3600);
    *piVar6 = (int)pvVar7;
    puVar8 = operator_new(0xc);
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      *puVar8 = piVar6;
      puVar8[1] = 0;
      *(undefined1 *)(puVar8 + 2) = 1;
    }
    puVar2 = puVar8;
    puVar3 = puVar8;
    if (DAT_008ab6f0 != (undefined4 *)0x0) {
      DAT_008ab6f4[1] = puVar8;
      puVar2 = DAT_008ab6f0;
      puVar3 = _DAT_008ab6f8;
    }
    _DAT_008ab6f8 = puVar3;
    DAT_008ab6f0 = puVar2;
    _DAT_008ab6fc = _DAT_008ab6fc + 1;
    DAT_008ab6f4 = puVar8;
  }
  iVar10 = 0;
  do {
    iVar1 = *piVar6;
    if (iVar1 + iVar10 != 0) {
      piVar9 = operator_new(0xc);
      if (piVar9 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        *piVar9 = iVar1 + iVar10;
        piVar9[1] = 0;
        *(undefined1 *)(piVar9 + 2) = 0;
      }
      piVar4 = piVar9;
      piVar5 = piVar9;
      if (DAT_008ab700 != (int *)0x0) {
        piVar9[1] = (int)DAT_008ab700;
        piVar4 = _DAT_008ab704;
        piVar5 = DAT_008ab708;
      }
      DAT_008ab708 = piVar5;
      _DAT_008ab704 = piVar4;
      DAT_008ab70c = DAT_008ab70c + 1;
      DAT_008ab700 = piVar9;
    }
    iVar10 = iVar10 + 0x1b0;
  } while (iVar10 < 0x3600);
  return;
}


