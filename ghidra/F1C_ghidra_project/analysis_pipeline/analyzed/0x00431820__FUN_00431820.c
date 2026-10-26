// Function: FUN_00431820 @ 00431820
// Size (bytes): 34


int __fastcall FUN_00431820(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0x2c;
  pcVar2 = (char *)(param_1 + 0x16cc);
  do {
    if (*pcVar2 == '\0') break;
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x40;
  } while (iVar1 < 0x33);
  return iVar1 + -0x2c;
}


