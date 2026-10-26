// Function: FUN_004b4fb0 @ 004b4fb0
// Size (bytes): 134


undefined4 __thiscall FUN_004b4fb0(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  FUN_00566bd0(param_1,1);
  iVar2 = -1;
  pcVar3 = (char *)(param_1 + 1);
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  param_2 = ~(byte)iVar2 - 1;
  FUN_00566bd0(&param_2,1);
  FUN_00566bd0((char *)(param_1 + 1),param_2);
  FUN_00566bd0(param_1 + 0x41,0x20);
  FUN_00566bd0(param_1 + 0x61,0x20);
  FUN_00566bd0(param_1 + 0x84,4);
  FUN_00566bd0(param_1 + 0x88,4);
  return 1;
}


