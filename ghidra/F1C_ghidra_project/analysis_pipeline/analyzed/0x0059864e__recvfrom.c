// Function: recvfrom @ 0059864e
// Size (bytes): 6


int recvfrom(SOCKET s,char *buf,int len,int flags,sockaddr *from,int *fromlen)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0059864e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = recvfrom(s,buf,len,flags,from,fromlen);
  return iVar1;
}


