// Function: FUN_00406100 @ 00406100
// Size (bytes): 48


void __fastcall FUN_00406100(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  puVar3 = local_c;
  if ((*(int *)(param_1 + 0x58) != 0) && (*(int *)(*(int *)(param_1 + 0x58) + 0x10) != 0)) {
    puVar2 = local_8;
    puVar1 = local_4;
    FUN_00404fe0(puVar1,puVar2,local_c);
    FUN_00407e10(puVar1,puVar2,puVar3);
  }
  return;
}


