// Function: FUN_004b84f0 @ 004b84f0
// Size (bytes): 215


uint __fastcall FUN_004b84f0(int param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x6cc);
  if ((int)puVar2 < 1) goto LAB_004b85c4;
  puVar2 = *(undefined4 **)(param_1 + 0x6c0);
  iVar3 = 0;
  *(undefined4 **)(param_1 + 0x6c8) = puVar2;
  if ((puVar2 != (undefined4 *)0x0) && (pfVar1 = (float *)*puVar2, pfVar1 != (float *)0x0)) {
    while (*pfVar1 <= *(float *)(param_1 + 0xf38)) {
      iVar3 = iVar3 + 1;
      if (*(int *)(param_1 + 0x6c8) != 0) {
        *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(*(int *)(param_1 + 0x6c8) + 4);
      }
      if ((*(undefined4 **)(param_1 + 0x6c8) == (undefined4 *)0x0) ||
         (pfVar1 = (float *)**(undefined4 **)(param_1 + 0x6c8), pfVar1 == (float *)0x0)) break;
    }
  }
  if (iVar3 == *(int *)(param_1 + 0x6cc)) {
    if (*(int *)(param_1 + 0x6cc) < 1) {
LAB_004b859b:
      *(undefined4 *)(param_1 + 0x6c8) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(param_1 + 0x6c0);
    }
  }
  else {
    if ((iVar3 < 0) || (*(int *)(param_1 + 0x6cc) <= iVar3)) goto LAB_004b859b;
    *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(param_1 + 0x6c0);
    while ((0 < iVar3 && (*(int *)(param_1 + 0x6c8) != 0))) {
      iVar3 = iVar3 + -1;
      *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(*(int *)(param_1 + 0x6c8) + 4);
    }
  }
  if (*(undefined4 **)(param_1 + 0x6c8) == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xf38) = uRam00000000;
    return 0;
  }
  puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x6c8);
  *(undefined4 *)(param_1 + 0xf38) = *puVar2;
LAB_004b85c4:
  return (uint)puVar2 & 0xffffff00;
}


