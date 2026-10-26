// Function: FUN_0057e8d0 @ 0057e8d0
// Size (bytes): 107


undefined4 FUN_0057e8d0(char *param_1,int param_2)

{
  char *_Source;
  undefined1 local_10 [4];
  _union_1226 local_c;
  
  local_c.S_addr = htonl(0);
  htons(0);
  FUN_0057b9f0(local_10);
  _Source = inet_ntoa((in_addr)local_c.S_un_b);
  if (_Source != (char *)0x0) {
    _strncpy(param_1,_Source,param_2 - 1U);
    param_1[param_2 - 1U] = '\0';
    return 1;
  }
  return 0;
}


