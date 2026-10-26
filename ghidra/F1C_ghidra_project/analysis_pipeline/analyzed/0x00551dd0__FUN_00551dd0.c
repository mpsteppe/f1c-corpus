// Function: FUN_00551dd0 @ 00551dd0
// Size (bytes): 196


void __thiscall
FUN_00551dd0(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _BinkWait_4(*param_1);
  if (iVar1 == 0) {
    _BinkDoFrame_4(*param_1);
    _BinkNextFrame_4(*param_1);
    param_1[1] = (param_1[1] + 1U) % *(uint *)(*param_1 + 8);
  }
  uVar2 = param_2;
  switch(*(undefined4 *)(param_2 + 0x30)) {
  case 5:
    uVar2 = 9;
    break;
  case 6:
    uVar2 = 10;
    break;
  case 7:
    uVar2 = 1;
    break;
  case 8:
    uVar2 = 5;
  }
  if ((param_5 & 0x20) != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if ((param_5 & 0x10) != 0) {
    uVar2 = uVar2 | 0x60000000;
  }
  iVar1 = FUN_00543210(4,0);
  if (iVar1 != 0) {
    _BinkCopyToBuffer_28
              (*param_1,iVar1,*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_2 + 0x20),
               param_3,param_4,uVar2);
    FUN_00543230(4,0);
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffffbff;
  }
  return;
}


