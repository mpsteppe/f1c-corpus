int __cdecl sub_58EB90(int a1, int a2, __int16 *a3, int a4, int a5)
{
  int v6; // edi
  _BYTE *v7; // esi
  _BYTE *v8; // ebp
  int v9; // eax
  int v11; // [esp+10h] [ebp-14h]
  int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-8h]
  int v15; // [esp+20h] [ebp-4h]
  int v16; // [esp+34h] [ebp+10h]

  v6 = 0;
  v11 = 0;
  v12 = 0;
  v13 = -1;
  v14 = sub_58ED70(a4);
  v7 = *(_BYTE **)(dword_7E483C + 4 * *a3);
  v16 = (unsigned __int8)v7[5];
  if ( !sub_58F050(a4, v7, a5) )
    return v6;
  v8 = v7 + 14;
  v15 = (v7[4] & 0xF) + 2;
  if ( v16 > 0 )
  {
    do
    {
      if ( sub_58EDA0(a2, a4, a5, v8) && sub_58EEE0(a3, v7, v6) )
      {
        v9 = sub_58CF90(v7, v6);
        if ( v9 <= 0 )
        {
          if ( sub_58F020(a1, v6) )
            ++v11;
          if ( v14 )
            sub_58ED00(a2, a4, v8);
        }
        else if ( v9 > v12 )
        {
          v12 = v9;
          v13 = v6;
        }
      }
      v8 += v15;
      ++v6;
    }
    while ( v6 < v16 );
    v6 = v11;
    if ( !v11 && v13 != -1 )
    {
      v6 = sub_58F020(a1, v13) != 0;
      if ( v14 )
        sub_58ED00(a2, a4, &v7[v13 * v15 + 14]);
    }
    return v6;
  }
  return 0;
}
