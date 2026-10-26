int __cdecl sub_54E97C(jmp_buf Buf, int a2)
{
  int *__attribute__((__org_typedef(jmp_buf))) v2; // esi
  unsigned __int8 v3; // al
  unsigned int v4; // ebx
  int v5; // edi
  _DWORD *v6; // ebx
  size_t v7; // edi
  int result; // eax
  int v9; // [esp-18h] [ebp-24h]

  v2 = Buf;
  v3 = *((_BYTE *)Buf + 284);
  if ( v3 < 8u )
  {
    v4 = v3;
    v5 = 8 - v3;
    sub_550B64(Buf, v3 + a2 + 32, v5);
    v9 = a2 + 32;
    *((_BYTE *)v2 + 284) = 8;
    if ( sub_550BCB(v9, v4, v5) )
    {
      if ( v4 < 4 )
      {
        if ( sub_550BCB(a2 + 32, v4, v5 - 4) )
          sub_54E7FC(v2, (int)"Not a PNG file");
      }
      sub_54E7FC(v2, (int)"PNG file corrupted by ASCII conversion");
    }
  }
  v6 = v2 + 67;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          sub_550B64(v2, (int)&Buf, 4);
          v7 = sub_554EC3(&Buf);
          sub_550C6B(v2);
          sub_554EE6(v2, (int)(v2 + 67), 4);
          if ( *v6 != *(_DWORD *)"IHDR" )
            break;
          sub_555842(v2, a2, v7);
        }
        if ( *v6 != *(_DWORD *)"PLTE" )
          break;
        sub_555A38(v2, a2, v7);
      }
      if ( *v6 != *(_DWORD *)"IEND" )
        break;
      sub_555B62(v2, a2, v7);
    }
    if ( *v6 == *(_DWORD *)"IDAT" )
      break;
    if ( *v6 == *(_DWORD *)"gAMA" )
    {
      sub_555BAC(v2, a2, v7);
    }
    else if ( *v6 == *(_DWORD *)"sRGB" )
    {
      sub_555CB7(v2, a2, v7);
    }
    else if ( *v6 == *(_DWORD *)"tRNS" )
    {
      sub_555DA6(v2, a2, v7);
    }
    else
    {
      sub_555F5D(v2, a2, v7);
    }
  }
  result = v2[22];
  if ( (result & 1) == 0 )
    sub_54E7FC(v2, (int)"Missing IHDR before IDAT");
  if ( *((_BYTE *)v2 + 278) == 3 && (result & 2) == 0 )
    sub_54E7FC(v2, (int)"Missing PLTE before IDAT");
  v2[22] |= 4u;
  v2[63] = v7;
  return result;
}
