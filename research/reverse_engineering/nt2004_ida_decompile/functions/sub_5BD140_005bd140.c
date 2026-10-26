int __fastcall sub_5BD140(int a1, _BYTE *a2, int a3)
{
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // eax
  int v11; // [esp+10h] [ebp-4h]

  v5 = 0;
  v11 = sub_577650(*(void **)(a1 + 8));
  if ( v11 <= 0 )
    return 1;
  while ( 1 )
  {
    v7 = *(_DWORD *)(sub_5BE1B0(*(_DWORD *)(a1 + 8), v5) + 4);
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 != 1 )
          return 0;
        a2 += 2;
        a3 -= 2;
      }
      else
      {
        ++a2;
        --a3;
      }
    }
    else
    {
      result = 0;
      if ( a3 < 1 )
        return result;
      LOBYTE(result) = *a2++;
      --a3;
      if ( result == 255 )
      {
        v10 = sub_5BC130((int)a2, a3);
        if ( v10 == -1 )
          return 0;
        a2 += v10;
        a3 -= v10;
      }
    }
    if ( a3 < 0 )
      break;
    if ( ++v5 >= v11 )
      return 1;
  }
  return 0;
}
