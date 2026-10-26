// Function: FUN_0057a070 @ 0057a070
// Size (bytes): 72


void __thiscall FUN_0057a070(byte *param_1,char *param_2,char *param_3)

{
  byte *pbVar1;
  int iVar2;
  
  _strncpy((char *)param_1,param_2,9);
  iVar2 = 4;
  pbVar1 = param_1;
  do {
    *pbVar1 = *pbVar1 | pbVar1[(int)(&stack0x0000000c + -(int)param_1)];
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _strncpy((char *)(param_1 + 0x10),param_3,4);
  return;
}


