// Function: FUN_00561ed0 @ 00561ed0
// Size (bytes): 106


void __fastcall FUN_00561ed0(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  char cVar3;
  
  DVar2 = GetTickCount();
  if (*(int *)(param_1 + 4) != -1) {
    uVar1 = *(uint *)(param_1 + 0xd8);
    if (((300000 < DVar2 - uVar1) || (uVar1 == 0)) || (DVar2 < uVar1)) {
      FUN_00562ac0();
      return;
    }
    if (('\0' < *(char *)(param_1 + 0xe8)) && (30000 < DVar2 - uVar1)) {
      FUN_00562ac0();
      cVar3 = *(char *)(param_1 + 0xe8) + '\x01';
      *(char *)(param_1 + 0xe8) = cVar3;
      if ('\n' < cVar3) {
        *(undefined1 *)(param_1 + 0xe8) = 0;
      }
    }
  }
  return;
}


