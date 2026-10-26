// Function: FUN_0057a880 @ 0057a880
// Size (bytes): 38


undefined1 * __fastcall FUN_0057a880(undefined4 *param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  puVar2 = local_8;
  cVar1 = (**(code **)(*(int *)*param_1 + 0x78))(local_8,local_4);
  if (cVar1 == '\0') {
    return (undefined1 *)0x0;
  }
  return puVar2;
}


