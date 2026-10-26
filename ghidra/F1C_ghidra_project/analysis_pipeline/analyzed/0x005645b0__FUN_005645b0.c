// Function: FUN_005645b0 @ 005645b0
// Size (bytes): 56


uint __fastcall FUN_005645b0(char *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = FUN_0058b465((int)cVar1);
    uVar3 = iVar2 + uVar3 * -0x63306ce7;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return uVar3 % param_2;
}


