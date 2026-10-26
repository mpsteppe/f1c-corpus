// Function: FUN_004a57f0 @ 004a57f0
// Size (bytes): 34


void __fastcall FUN_004a57f0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = FUN_004a5820(iVar2);
    if ((iVar1 == 0) && (0 < iVar2)) break;
    iVar2 = iVar2 + 1;
  }
  *(int *)(param_1 + 0xa8) = iVar2;
  return;
}


