// Function: sendto @ 00598672
// Size (bytes): 6


int sendto(SOCKET s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00598672. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = sendto(s,buf,len,flags,to,tolen);
  return iVar1;
}


