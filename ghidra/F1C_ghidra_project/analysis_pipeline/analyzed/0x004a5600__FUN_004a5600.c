// Function: FUN_004a5600 @ 004a5600
// Size (bytes): 95


void __thiscall FUN_004a5600(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  if ((param_2 != (byte *)0x0) && (pbVar1 = *(byte **)(param_1 + 8), param_2 != pbVar1)) {
    bVar2 = 0;
    if (pbVar1 != (byte *)0x0) {
      if ((*(int *)(param_1 + 0x184) == 3) && (*(char *)(param_1 + 400) != '\0')) {
        return;
      }
      if (*(int *)(param_1 + 0x184) == 4) {
        return;
      }
      bVar2 = *pbVar1 & 1;
      FUN_004a3440();
    }
    *(byte **)(param_1 + 8) = param_2;
    if (bVar2 != 0) {
      FUN_004a3390(0);
      return;
    }
    FUN_004a3440();
  }
  return;
}


