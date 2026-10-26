// Function: FUN_005119e9 @ 005119e9
// Strings:  [Missing PLTE before IDAT, Missing IHDR before IDAT, PNG file corrupted by ASCII conversion, Not a PNG file]


void FUN_005119e9(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  iVar2 = param_1;
  if (*(byte *)(param_1 + 0x11c) < 8) {
    uVar4 = (uint)*(byte *)(param_1 + 0x11c);
    iVar5 = -uVar4 + 8;
    FUN_00513bd1(param_1,uVar4 + 0x20 + param_2,iVar5);
    *(undefined1 *)(iVar2 + 0x11c) = 8;
    iVar5 = FUN_00513c38(param_2 + 0x20,uVar4,iVar5);
    if (iVar5 != 0) {
      if ((uVar4 < 4) && (iVar5 = FUN_00513c38(param_2 + 0x20,uVar4,-uVar4 + 4), iVar5 != 0)) {
        pcVar6 = "Not a PNG file";
      }
      else {
        pcVar6 = "PNG file corrupted by ASCII conversion";
      }
      FUN_00511869(iVar2,pcVar6);
    }
  }
  piVar1 = (int *)(iVar2 + 0x10c);
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          FUN_00513bd1(iVar2,&param_1,4);
          uVar3 = FUN_00517f35(&param_1);
          FUN_00513cd8(iVar2);
          FUN_00517f58(iVar2,piVar1,4);
          if (*piVar1 != DAT_005af264) break;
          FUN_005188b4(iVar2,param_2,uVar3);
        }
        if (*piVar1 != DAT_005af27c) break;
        FUN_00518aaa(iVar2,param_2,uVar3);
      }
      if (*piVar1 != DAT_005af274) break;
      FUN_00518bd4(iVar2,param_2,uVar3);
    }
    if (*piVar1 == DAT_005af26c) break;
    if (*piVar1 == DAT_005af284) {
      FUN_00518c1e();
    }
    else if (*piVar1 == DAT_005af28c) {
      FUN_00518d29();
    }
    else if (*piVar1 == DAT_005af294) {
      FUN_00518e18();
    }
    else {
      FUN_00518fcf(iVar2,param_2,uVar3);
    }
  }
  if ((*(uint *)(iVar2 + 0x58) & 1) == 0) {
    pcVar6 = "Missing IHDR before IDAT";
  }
  else {
    if ((*(char *)(iVar2 + 0x116) != '\x03') || ((*(uint *)(iVar2 + 0x58) & 2) != 0))
    goto LAB_00511b4d;
    pcVar6 = "Missing PLTE before IDAT";
  }
  FUN_00511869(iVar2,pcVar6);
LAB_00511b4d:
  *(uint *)(iVar2 + 0x58) = *(uint *)(iVar2 + 0x58) | 4;
  *(undefined4 *)(iVar2 + 0xfc) = uVar3;
  return;
}


