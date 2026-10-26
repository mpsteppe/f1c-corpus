// Function: FUN_0059706a @ 0059706a
// Size (bytes): 41


void FUN_0059706a(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_008d47e0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_008d46bc = 0;
  DAT_008d46cc = 0;
  DAT_008d48e4 = 0;
  DAT_008d46c0 = 0;
  DAT_008d46c4 = 0;
  DAT_008d46c8 = 0;
  return;
}


