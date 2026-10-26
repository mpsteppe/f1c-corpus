// Function: FUN_004a1367 @ 004a1367
// Size (bytes): 114


void FUN_004a1367(BOOL param_1,DWORD param_2)

{
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  DWORD unaff_retaddr;
  uint uStack0000001c;
  int iVar1;
  int in_stack_0000002c;
  int in_stack_00000098;
  
  uStack0000001c = (in_stack_0000002c - unaff_EDI >> 1) - (in_stack_00000098 >> 1);
  uStack0000001c = ((int)uStack0000001c < 0) - 1 & uStack0000001c;
  iVar1 = unaff_EBX;
  AdjustWindowRectEx((LPRECT)&stack0x00000020,unaff_retaddr,param_1,param_2);
  FUN_0059db5b(uStack0000001c,unaff_ESI - unaff_EBX,in_stack_00000098 - iVar1);
  return;
}


