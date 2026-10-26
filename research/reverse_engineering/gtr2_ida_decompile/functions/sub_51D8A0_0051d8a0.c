int __thiscall sub_51D8A0(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // eax
  bool v4; // cf
  int v5; // edi
  int result; // eax
  int v7; // esi
  int v8; // ebx
  unsigned __int16 *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  _DWORD *v20; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  _DWORD *v26; // edx

  v3 = (_DWORD *)this[7];
  v4 = (*v3 & 8) != 0;
  v5 = v3[26];
  result = a2;
  v7 = a2;
  if ( a2 < a3 )
  {
    v8 = 36 * a2;
    do
    {
      if ( v7 >= *(_DWORD *)(v5 + 368) )
        v9 = 0;
      else
        v9 = (unsigned __int16 *)(v8 + *(_DWORD *)(v5 + 372));
      v10 = *((_DWORD *)v9 + 2);
      v11 = *v9;
      if ( (*(_BYTE *)v10 & 8) != 0 )
        v12 = 88 * v11;
      else
        v12 = v11 << 6;
      v13 = *(_DWORD *)(v10 + 32) + v12;
      if ( (v4 ? 0x7000 : 0) != 0 )
        v14 = (_DWORD *)(v13 + 56);
      else
        v14 = (_DWORD *)(v13 + 32);
      *v14 = 1036831949;
      if ( v7 >= *(_DWORD *)(v5 + 368) )
        v15 = 0;
      else
        v15 = v8 + *(_DWORD *)(v5 + 372);
      v16 = *(_DWORD *)(v15 + 8);
      v17 = *(unsigned __int16 *)(v15 + 2);
      if ( (*(_BYTE *)v16 & 8) != 0 )
        v18 = 88 * v17;
      else
        v18 = v17 << 6;
      v19 = *(_DWORD *)(v16 + 32) + v18;
      if ( (v4 ? 0x7000 : 0) != 0 )
        v20 = (_DWORD *)(v19 + 56);
      else
        v20 = (_DWORD *)(v19 + 32);
      *v20 = 1036831949;
      if ( v7 >= *(_DWORD *)(v5 + 368) )
        v21 = 0;
      else
        v21 = v8 + *(_DWORD *)(v5 + 372);
      v22 = *(_DWORD *)(v21 + 8);
      v23 = *(unsigned __int16 *)(v21 + 4);
      if ( (*(_BYTE *)v22 & 8) != 0 )
        v24 = 88 * v23;
      else
        v24 = v23 << 6;
      v25 = *(_DWORD *)(v22 + 32) + v24;
      if ( (v4 ? 0x7000 : 0) != 0 )
        v26 = (_DWORD *)(v25 + 56);
      else
        v26 = (_DWORD *)(v25 + 32);
      result = a3;
      ++v7;
      v8 += 36;
      *v26 = 1036831949;
    }
    while ( v7 < a3 );
  }
  return result;
}
