// Function: FUN_004198b0 @ 004198b0
// Size (bytes): 299


void __thiscall FUN_004198b0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_20 [32];
  
  if (((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) && (DAT_007c56a8 != 8)) {
    iVar1 = *(int *)(param_1 + 0x1b0 + *(int *)(param_2 + 0x4894) * 4);
    iVar3 = *(int *)(param_2 + 0x4060);
    if ((iVar1 != iVar3) && (DAT_007c56a4 == 5)) {
      FUN_004144d0();
      *(int *)(param_1 + 0x1b0 + *(int *)(param_2 + 0x4894) * 4) = iVar3;
      if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_2 + 0x4894)) {
        if (*(int *)(param_2 + 0x403c) == 1) {
          return;
        }
        if (iVar3 < iVar1) {
          cVar2 = '\x11';
        }
        else {
          if (iVar3 == 1) {
            return;
          }
          cVar2 = '\x12';
        }
        uVar4 = 0xffffffff;
      }
      else {
        if (iVar3 == 1) {
          return;
        }
        if (*(int *)(param_2 + 0x403c) == 1) {
          return;
        }
        if (*(int *)(param_2 + 0x403c) == 2) {
          cVar2 = '\a';
        }
        else {
          cVar2 = (iVar1 <= iVar3) + '\b';
        }
        uVar4 = *(undefined4 *)(param_1 + 0x1b0 + *(int *)(param_2 + 0x4894) * 4);
        iVar3 = *(int *)(param_2 + 0x489c);
      }
      FUN_004144f0(cVar2,iVar3,uVar4,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
    }
  }
  return;
}


