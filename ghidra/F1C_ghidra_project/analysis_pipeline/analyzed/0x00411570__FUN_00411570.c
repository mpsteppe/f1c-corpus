// Function: FUN_00411570 @ 00411570
// Size (bytes): 224


void FUN_00411570(int param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_005ecf0c + param_1 * 0x1230;
  iVar2 = 4;
  do {
    if (param_2 == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = *puVar3;
    }
    FUN_0040e710(uVar1);
    puVar3 = puVar3 + 0x4a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  do {
    if (param_2 == '\0') {
      uVar1 = 0;
    }
    else if (iVar2 == 0) {
      uVar1 = (&DAT_005ed3ac)[param_1 * 0x1230];
    }
    else {
      uVar1 = (&DAT_005ed3f0)[param_1 * 0x1230];
    }
    FUN_0040e710(uVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  puVar3 = &DAT_005ed434 + param_1 * 0x1230;
  iVar2 = 8;
  do {
    if (param_2 == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = *puVar3;
    }
    FUN_0040e710(uVar1);
    puVar3 = puVar3 + 0x11;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


