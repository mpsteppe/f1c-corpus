int __cdecl sub_5119E9(int a1, int a2)
{
  int v2; // esi
  unsigned __int8 v3; // al
  unsigned int v4; // ebx
  int v5; // edi
  _DWORD *v6; // ebx
  int v7; // edi
  int result; // eax
  int v9; // [esp-18h] [ebp-24h]

  v2 = a1;
  v3 = *(_BYTE *)(a1 + 284);
  if ( v3 < 8u )
  {
    v4 = v3;
    v5 = 8 - v3;
    CallbackDispatchWithNullGuard(a1, v3 + a2 + 32, v5);
    v9 = a2 + 32;
    *(_BYTE *)(v2 + 284) = 8;
    if ( BoundedMemcmpAgainstReference(v9, v4, v5) )
    {
      if ( v4 < 4 && BoundedMemcmpAgainstReference(a2 + 32, v4, v5 - 4) )
        GuardedCallWithLongjmp(v2, (int)"Not a PNG file");
      else
        GuardedCallWithLongjmp(v2, (int)"PNG file corrupted by ASCII conversion");
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
          CallbackDispatchWithNullGuard(v2, &a1, 4);
          v7 = ByteArrayToInt(&a1);
          AnimationHandleAlloc(v2);
          sub_517F58(v2, v2 + 268, 4);
          if ( *v6 != *(_DWORD *)"IHDR" )
            break;
          sub_5188B4(v2, a2, v7);
        }
        if ( *v6 != *(_DWORD *)"PLTE" )
          break;
        sub_518AAA(v2, a2, v7);
      }
      if ( *v6 != *(_DWORD *)"IEND" )
        break;
      sub_518BD4(v2, a2, v7);
    }
    if ( *v6 == *(_DWORD *)"IDAT" )
      break;
    if ( *v6 == *(_DWORD *)"gAMA" )
    {
      sub_518C1E(v2, a2, v7);
    }
    else if ( *v6 == *(_DWORD *)"sRGB" )
    {
      sub_518D29(v2, a2, v7);
    }
    else if ( *v6 == *(_DWORD *)"tRNS" )
    {
      sub_518E18(v2, a2, v7);
    }
    else
    {
      sub_518FCF(v2, a2, v7);
    }
  }
  result = *(_DWORD *)(v2 + 88);
  if ( (result & 1) != 0 )
  {
    if ( *(_BYTE *)(v2 + 278) == 3 && (result & 2) == 0 )
      result = GuardedCallWithLongjmp(v2, (int)"Missing PLTE before IDAT");
  }
  else
  {
    result = GuardedCallWithLongjmp(v2, (int)"Missing IHDR before IDAT");
  }
  *(_DWORD *)(v2 + 88) |= 4u;
  *(_DWORD *)(v2 + 252) = v7;
  return result;
}

