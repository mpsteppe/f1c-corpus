
void FUN_0057e860(undefined4 param_1)

{
  char cVar1;
  undefined2 uStack_10;
  u_short uStack_e;
  u_long uStack_c;
  
  uStack_10 = 2;
  uStack_c = htonl(0);
  uStack_e = htons(0);
  FUN_0057b9f0(&uStack_10);
  cVar1 = FUN_00586ca0();
  if (cVar1 != '\0') {
    FUN_0057d8d0(param_1,&uStack_10);
    return;
  }
  FUN_0057d6c0(param_1,&uStack_10);
  return;
}

