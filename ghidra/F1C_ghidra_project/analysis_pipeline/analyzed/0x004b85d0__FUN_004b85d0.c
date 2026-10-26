// Function: FUN_004b85d0 @ 004b85d0
// Size (bytes): 264


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_004b85d0(int param_1)

{
  float *pfVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = *(undefined4 **)(param_1 + 0x6cc);
  if (0 < (int)puVar3) {
    iVar2 = (int)puVar3 + -1;
    puVar3 = *(undefined4 **)(param_1 + 0x6c4);
    *(undefined4 **)(param_1 + 0x6c8) = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      pfVar1 = (float *)*puVar3;
      iVar4 = iVar2;
joined_r0x004b85f8:
      if (pfVar1 != (float *)0x0) {
        if (*pfVar1 < *(float *)(param_1 + 0xf38) - _DAT_005acd20) {
          if ((-1 < iVar4) && (iVar4 < *(int *)(param_1 + 0x6cc))) {
            *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(param_1 + 0x6c0);
            while ((0 < iVar4 && (*(int *)(param_1 + 0x6c8) != 0))) {
              iVar4 = iVar4 + -1;
              *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(*(int *)(param_1 + 0x6c8) + 4);
            }
            goto LAB_004b86b4;
          }
          goto LAB_004b86aa;
        }
        iVar4 = iVar4 + -1;
        if (*(int *)(param_1 + 0x6c8) != 0) {
          *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(*(int *)(param_1 + 0x6c8) + 8);
        }
        if (*(undefined4 **)(param_1 + 0x6c8) != (undefined4 *)0x0) goto code_r0x004b8633;
      }
    }
    if ((iVar2 < 0) || (*(int *)(param_1 + 0x6cc) <= iVar2)) {
LAB_004b86aa:
      *(undefined4 *)(param_1 + 0x6c8) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(param_1 + 0x6c0);
      while ((0 < iVar2 && (*(int *)(param_1 + 0x6c8) != 0))) {
        iVar2 = iVar2 + -1;
        *(undefined4 *)(param_1 + 0x6c8) = *(undefined4 *)(*(int *)(param_1 + 0x6c8) + 4);
      }
    }
LAB_004b86b4:
    if (*(undefined4 **)(param_1 + 0x6c8) == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0xf38) = uRam00000000;
      return 0;
    }
    puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x6c8);
    *(undefined4 *)(param_1 + 0xf38) = *puVar3;
  }
  return (uint)puVar3 & 0xffffff00;
code_r0x004b8633:
  pfVar1 = (float *)**(undefined4 **)(param_1 + 0x6c8);
  goto joined_r0x004b85f8;
}


