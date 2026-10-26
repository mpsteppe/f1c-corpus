// Function: FUN_0058bccf @ 0058bccf
// Size (bytes): 90


void FUN_0058bccf(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = FUN_0058b465((int)*param_1);
  if (iVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_005e6bd4 < 2) {
        uVar4 = (byte)PTR_DAT_005e69c8[*param_1 * 2] & 4;
      }
      else {
        uVar4 = FUN_0058c674((int)*param_1,4);
      }
    } while (uVar4 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_005e6bd8;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}


