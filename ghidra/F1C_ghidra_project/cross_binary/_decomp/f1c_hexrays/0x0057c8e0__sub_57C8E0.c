// f1c  0x0057c8e0  size=108
SOCKET __stdcall sub_57C8E0(SOCKET *a1, char a2)
{
  SOCKET result; // eax
  int v3; // eax
  char buf[256]; // [esp+4h] [ebp-100h] BYREF

  result = *a1;
  if ( *a1 != -1 )
  {
    if ( a2 && !shutdown(result, 1) )
    {
      buf[0] = 0;
      do
        v3 = recv(*a1, buf, 256, 0);
      while ( v3 != -1 && v3 );
    }
    result = closesocket(*a1);
    *a1 = -1;
  }
  return result;
}
