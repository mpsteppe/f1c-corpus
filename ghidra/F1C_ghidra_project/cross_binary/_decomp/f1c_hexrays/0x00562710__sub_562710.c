// f1c  0x00562710  size=284
char *__fastcall sub_562710(SOCKET *a1, const struct sockaddr *a2, char *buf, const char *a4)
{
  int v4; // edx
  const char *v5; // esi
  char *result; // eax
  char *v7; // edi
  int i; // ecx

  v4 = 0;
  v5 = a4;
  if ( strlen(a4) + strlen(buf) < 0x546 )
  {
LABEL_11:
    result = 0;
    strcat(buf, v5);
  }
  else
  {
    while ( strlen(v5) > 0x546 )
    {
      result = (char *)v5;
      v7 = (char *)v5;
      for ( i = 0; i < 1350; ++i )
      {
        if ( *result == 92 )
        {
          if ( !(v4 % 2) )
            v7 = result;
          ++v4;
        }
        ++result;
      }
      if ( v7 == v5 )
        return result;
      *v7 = 0;
      sub_562710(buf, (int)v5);
      *v7 = 92;
      v5 = v7;
      v4 = 0;
      if ( strlen(buf) + strlen(v7) < 0x546 )
        goto LABEL_11;
    }
    sub_562610(a1, a2, buf);
    strcpy(buf, v5);
  }
  return result;
}
