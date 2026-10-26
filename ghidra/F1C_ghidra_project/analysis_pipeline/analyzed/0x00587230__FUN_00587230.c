// Function: FUN_00587230 @ 00587230
// Size (bytes): 31


void __thiscall FUN_00587230(int param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x19);
  if (param_2 != '\0') {
    *(char *)(param_1 + 0x19) = cVar1 + '\x01';
    return;
  }
  if (cVar1 != '\0') {
    *(char *)(param_1 + 0x19) = cVar1 + -1;
  }
  return;
}


