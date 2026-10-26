// Function: FUN_0050f6f7 @ 0050f6f7
// Size (bytes): 371


void FUN_0050f6f7(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *unaff_ESI;
  
  iVar2 = unaff_ESI[8];
  if (iVar2 == 1) {
    unaff_ESI[9] = 1;
    unaff_ESI[10] = 1;
    goto LAB_0050f823;
  }
  if (iVar2 == 3) {
    if ((char)unaff_ESI[0x40] == '\0') {
      if (*(char *)((int)unaff_ESI + 0x106) == '\0') {
        piVar3 = (int *)unaff_ESI[0x31];
        iVar2 = *piVar3;
        iVar4 = piVar3[0x15];
        iVar5 = piVar3[0x2a];
        if (iVar2 == 1) {
          if ((iVar4 != 2) || (iVar5 != 3)) goto LAB_0050f7d5;
        }
        else {
          if (((iVar2 == 0x52) && (iVar4 == 0x47)) && (iVar5 == 0x42)) {
            unaff_ESI[9] = 2;
            goto LAB_0050f7f9;
          }
LAB_0050f7d5:
          iVar6 = *unaff_ESI;
          *(int *)(iVar6 + 0x18) = iVar2;
          *(int *)(iVar6 + 0x1c) = iVar4;
          *(int *)(iVar6 + 0x20) = iVar5;
          *(undefined4 *)(*unaff_ESI + 0x14) = 0x6b;
          (**(code **)(*unaff_ESI + 4))();
        }
        unaff_ESI[9] = 3;
      }
      else {
        bVar1 = *(byte *)((int)unaff_ESI + 0x107);
        if (bVar1 != 0) {
          if (bVar1 != 1) {
            *(undefined4 *)(*unaff_ESI + 0x14) = 0x6e;
            *(uint *)(*unaff_ESI + 0x18) = (uint)*(byte *)((int)unaff_ESI + 0x107);
            (**(code **)(*unaff_ESI + 4))();
          }
          goto LAB_0050f7a4;
        }
        unaff_ESI[9] = 2;
      }
    }
    else {
LAB_0050f7a4:
      unaff_ESI[9] = 3;
    }
LAB_0050f7f9:
    unaff_ESI[10] = 2;
    goto LAB_0050f823;
  }
  if (iVar2 != 4) {
    unaff_ESI[9] = 0;
    unaff_ESI[10] = 0;
    goto LAB_0050f823;
  }
  if (*(char *)((int)unaff_ESI + 0x106) == '\0') {
LAB_0050f75b:
    unaff_ESI[9] = 4;
  }
  else {
    bVar1 = *(byte *)((int)unaff_ESI + 0x107);
    if (bVar1 == 0) goto LAB_0050f75b;
    if (bVar1 != 2) {
      *(undefined4 *)(*unaff_ESI + 0x14) = 0x6e;
      *(uint *)(*unaff_ESI + 0x18) = (uint)*(byte *)((int)unaff_ESI + 0x107);
      (**(code **)(*unaff_ESI + 4))();
    }
    unaff_ESI[9] = 5;
  }
  unaff_ESI[10] = 4;
LAB_0050f823:
  *(undefined1 *)(unaff_ESI + 0x10) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x41) = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0xf] = 0x3ff00000;
  unaff_ESI[0x11] = 0;
  *(undefined1 *)((int)unaff_ESI + 0x4a) = 0;
  unaff_ESI[0x1d] = 0;
  *(undefined1 *)(unaff_ESI + 0x16) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x59) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x5a) = 0;
  unaff_ESI[0xb] = 1;
  unaff_ESI[0xc] = 1;
  *(undefined1 *)(unaff_ESI + 0x12) = 1;
  *(undefined1 *)((int)unaff_ESI + 0x49) = 1;
  unaff_ESI[0x13] = 2;
  *(undefined1 *)(unaff_ESI + 0x14) = 1;
  unaff_ESI[0x15] = 0x100;
  return;
}


