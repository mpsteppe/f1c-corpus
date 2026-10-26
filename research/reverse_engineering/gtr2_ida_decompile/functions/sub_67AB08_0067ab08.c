int __stdcall sub_67AB08(int a1, int a2)
{
  int v2; // esi
  unsigned __int8 v3; // al
  unsigned int v4; // ebx
  unsigned int v5; // edi
  _DWORD *v6; // ebx
  size_t v7; // edi
  int result; // eax
  int v9; // [esp-Ch] [ebp-18h]

  v2 = a1;
  v3 = *(_BYTE *)(a1 + 284);
  if ( v3 < 8u )
  {
    v4 = v3;
    v5 = 8 - v3;
    sub_67CBAE(a1, v3 + a2 + 32, v5);
    v9 = a2 + 32;
    *(_BYTE *)(v2 + 284) = 8;
    if ( sub_679F8A(v9, v4, v5) )
    {
      if ( v4 < 4 )
      {
        if ( sub_679F8A(a2 + 32, v4, v5 - 4) )
          sub_679F05(v2, (int)"Not a PNG file");
      }
      sub_679F05(v2, (int)"PNG file corrupted by ASCII conversion");
    }
  }
  v6 = (_DWORD *)(v2 + 268);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          sub_67CBAE(v2, &a1, 4);
          v7 = sub_6B9D7D(&a1);
          sub_67A039(v2);
          sub_6B9DC1(v2, v2 + 268, 4);
          if ( *v6 != *(_DWORD *)off_16C9B28 )
            break;
          sub_6BA724(v2, a2, v7);
        }
        if ( *v6 != *(_DWORD *)"PLTE" )
          break;
        sub_6BA906(v2, a2, v7);
      }
      if ( *v6 != *(_DWORD *)"IEND" )
        break;
      sub_6BAA21(v2, a2, v7);
    }
    if ( *v6 == *(_DWORD *)"IDAT" )
      break;
    if ( *v6 == *(_DWORD *)"gAMA" )
    {
      sub_6BAA69(v2, a2, v7);
    }
    else if ( *v6 == *(_DWORD *)"sRGB" )
    {
      sub_6BAB6C(v2, a2, v7);
    }
    else if ( *v6 == *(_DWORD *)"tRNS" )
    {
      sub_6BAC50(v2, a2, v7);
    }
    else
    {
      sub_6BADE4(v2, a2, v7);
    }
  }
  result = *(_DWORD *)(v2 + 88);
  if ( (result & 1) == 0 )
    sub_679F05(v2, (int)"Missing IHDR before IDAT");
  if ( *(_BYTE *)(v2 + 278) == 3 && (result & 2) == 0 )
    sub_679F05(v2, (int)"Missing PLTE before IDAT");
  *(_DWORD *)(v2 + 88) |= 4u;
  *(_DWORD *)(v2 + 252) = v7;
  return result;
}
