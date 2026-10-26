// Function: FUN_0057c8e0 @ 0057c8e0
// Size (bytes): 108


void FUN_0057c8e0(SOCKET *param_1,char param_2)

{
  int iVar1;
  char local_100 [256];
  
  if (*param_1 != 0xffffffff) {
    if (param_2 != '\0') {
      iVar1 = shutdown(*param_1,1);
      if (iVar1 == 0) {
        local_100[0] = '\0';
        do {
          iVar1 = recv(*param_1,local_100,0x100,0);
          if (iVar1 == -1) break;
        } while (iVar1 != 0);
      }
    }
    closesocket(*param_1);
    *param_1 = 0xffffffff;
  }
  return;
}


