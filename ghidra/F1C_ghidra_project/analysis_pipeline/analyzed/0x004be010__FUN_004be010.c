// Function: FUN_004be010 @ 004be010
// Size (bytes): 353


void FUN_004be010(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  uVar2 = param_1;
  bVar1 = false;
  iVar3 = __ftol();
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_004be051:
    bVar1 = true;
  }
  else if (7 < iVar3) {
    iVar3 = 7;
    goto LAB_004be051;
  }
  iVar4 = __ftol();
  if (iVar4 < 0) {
    iVar4 = 0;
LAB_004be081:
    bVar1 = true;
  }
  else if (7 < iVar4) {
    iVar4 = 7;
    goto LAB_004be081;
  }
  iVar5 = __ftol();
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_004be0b1:
    bVar1 = true;
  }
  else if (7 < iVar5) {
    iVar5 = 7;
    goto LAB_004be0b1;
  }
  param_1 = __ftol();
  if (param_1 < 0) {
    param_1 = 0;
  }
  else {
    if (param_1 < 8) goto LAB_004be0fb;
    param_1 = 7;
  }
  bVar1 = true;
LAB_004be0fb:
  if (iVar3 <= iVar4) {
    local_4 = (iVar4 - iVar3) + 1;
    do {
      if (iVar5 <= param_1) {
        iVar3 = (param_1 - iVar5) + 1;
        do {
          FUN_004bd900(uVar2);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  if (bVar1) {
    FUN_004bd900(uVar2);
  }
  return;
}


