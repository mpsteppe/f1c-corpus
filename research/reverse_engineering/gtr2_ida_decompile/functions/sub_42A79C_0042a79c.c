SOCKET __stdcall sub_42A79C(SOCKET *a1, char a2)
{
  SOCKET result; // eax
  SOCKET v3; // ecx
  int i; // eax
  char buf[256]; // [esp+0h] [ebp-100h] BYREF

  result = *a1;
  if ( *a1 != -1 )
  {
    if ( a2 )
    {
      if ( !shutdown(result, 1) )
      {
        v3 = *a1;
        buf[0] = 0;
        for ( i = recv(v3, buf, 256, 0); i != -1; i = recv(*a1, buf, 256, 0) )
        {
          if ( !i )
            break;
        }
      }
    }
    result = closesocket(*a1);
    *a1 = -1;
  }
  return result;
}
