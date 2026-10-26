// Function: FUN_0057c860 @ 0057c860
// Size (bytes): 117


undefined4 FUN_0057c860(SOCKET param_1,char param_2)

{
  SOCKET s;
  char cVar1;
  
  cVar1 = param_2;
  s = param_1;
  _param_2 = 1;
  if (cVar1 == '\0') {
    setsockopt(param_1,0xffff,0x20,&param_2,4);
  }
  else {
    setsockopt(param_1,6,1,&param_2,4);
    param_1 = 1;
    setsockopt(s,0xffff,8,(char *)&param_1,4);
  }
  WSAAsyncSelect(s,DAT_008d3e28,0x1a0a,0x3f);
  return 1;
}


