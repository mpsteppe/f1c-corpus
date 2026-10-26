// Function: FUN_004b04e0 @ 004b04e0
// Size (bytes): 81


void __thiscall FUN_004b04e0(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2[(param_1 + 0x14) - (int)param_2] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = FUN_00566810();
  if (iVar3 == 0) {
    FUN_004b01b0(param_2,param_1 + 0x14);
  }
  FUN_004b0540(param_3);
  return;
}


