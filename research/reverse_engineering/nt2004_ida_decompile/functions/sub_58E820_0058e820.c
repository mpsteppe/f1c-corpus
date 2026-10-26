void __cdecl sub_58E820(int a1, int a2)
{
  int v2; // esi
  int v3; // ebx
  int *v4; // ebp
  unsigned __int16 *v5; // edi
  unsigned __int8 v6; // bl
  int i; // edi
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // edx
  int v11; // edx
  _BYTE *v12; // edi
  unsigned __int16 *v13; // esi
  int v14; // [esp+10h] [ebp-198h]
  int v15; // [esp+10h] [ebp-198h]
  int v16; // [esp+14h] [ebp-194h]
  _DWORD v17[100]; // [esp+18h] [ebp-190h] BYREF

  v2 = 0;
  v3 = *(unsigned __int8 *)(a1 + 6);
  v16 = v3;
  if ( *(_BYTE *)(a1 + 6) )
  {
    v4 = v17;
    v5 = (unsigned __int16 *)(a1 + 12);
    v14 = *(unsigned __int8 *)(a1 + 6);
    do
    {
      v6 = *(_BYTE *)(a1 + 4 * *v5);
      *v4 = sub_58E110(v6);
      v2 += sub_58E110(v6);
      ++v5;
      ++v4;
      --v14;
    }
    while ( v14 );
    v3 = v16;
  }
  for ( i = 0; v2 > 0; v17[v9] = 0 )
  {
    v8 = (unsigned __int16)sub_58FAA0(v2, -1);
    v9 = 0;
    if ( v3 > 0 )
    {
      v10 = v17;
      do
      {
        v8 -= *v10;
        if ( v8 < 0 )
          break;
        ++v9;
        ++v10;
      }
      while ( v9 < v3 );
    }
    v11 = v17[v9];
    *(_BYTE *)(i + a2) = v9;
    v2 -= v11;
    ++i;
  }
  v15 = 0;
  if ( v3 > 0 )
  {
    v12 = (_BYTE *)(a2 + i);
    v13 = (unsigned __int16 *)(a1 + 12);
    do
    {
      if ( !sub_58E110(*(_BYTE *)(a1 + 4 * *v13)) )
        *v12++ = v15;
      ++v13;
      ++v15;
    }
    while ( v15 < v3 );
  }
}
