int __fastcall sub_5BC9A0(int a1, const char *a2, int len)
{
  int v5; // ebx
  int v6; // edi

  v5 = 1;
  while ( 1 )
  {
    --v5;
    if ( send(*(_DWORD *)(a1 + 1184), a2, len, 0) > 0 )
      break;
    if ( v5 < 0 )
      return 3;
    sub_5BC800((char *)a1);
    v6 = sub_5BC220((char *)a1, 0, 0, 2u, 0);
    if ( v6 )
    {
      sub_5BCA10(a1);
      return v6;
    }
  }
  return 0;
}
