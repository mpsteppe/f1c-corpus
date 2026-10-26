int __cdecl sub_58E570(int *a1)
{
  int v1; // eax
  int v2; // edi
  _BYTE *v3; // esi
  char v4; // cl
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // edx
  __int16 v9; // bp
  int v10; // eax
  _DWORD *v11; // ebx
  int v12; // ecx
  int v13; // ebp
  int v14; // ebx
  _BYTE *v15; // edi
  int v16; // eax
  unsigned int v17; // edx
  int v18; // eax
  __int16 v19; // [esp+10h] [ebp-1BCh]
  int v20; // [esp+14h] [ebp-1B8h] BYREF
  int v21; // [esp+18h] [ebp-1B4h]
  int v22; // [esp+1Ch] [ebp-1B0h]
  int v23; // [esp+20h] [ebp-1ACh]
  int v24; // [esp+24h] [ebp-1A8h] BYREF
  int v25; // [esp+28h] [ebp-1A4h] BYREF
  int v26; // [esp+2Ch] [ebp-1A0h]
  int v27; // [esp+30h] [ebp-19Ch]
  int v28; // [esp+34h] [ebp-198h]
  int v29; // [esp+38h] [ebp-194h]
  _BYTE v30[100]; // [esp+3Ch] [ebp-190h] BYREF
  _BYTE v31[300]; // [esp+A0h] [ebp-12Ch] BYREF

  v1 = *a1;
  v2 = 0;
  v23 = 0;
  LOBYTE(v25) = 0;
  v19 = 0;
  v26 = 0;
  v20 = v1;
  v3 = (_BYTE *)sub_58D520((unsigned __int16 *)&v20);
  if ( !v3 || !sub_58D600((int)&v20, &v24) || !sub_58E930(v3, v24) )
    return 0;
  v4 = v3[10];
  v5 = dword_7FFA20[v24];
  v22 = v5;
  if ( (v4 & 1) != 0 || v5 != 1 )
  {
    if ( v5 )
      v26 = sub_58D6F0((int)&v20);
  }
  else
  {
    v22 = 0;
  }
  LOBYTE(v29) = sub_58FDA0(&v20, v3, a1, &v25);
  sub_58E820(v3, v30);
  v7 = (unsigned __int8)v3[6];
  v27 = v7;
  if ( v7 <= 0 )
    return -1;
  LOBYTE(v6) = v3[10];
  v28 = (v6 >> 3) & 1;
  if ( v28 )
  {
    v9 = 1;
    v19 = 0;
    v10 = 3 * (((char)v3[7] >> 4) + 1);
    LOBYTE(v10) = v10 & 0xFC;
    v11 = a1 + 1;
    v21 = *(_DWORD *)&v3[v10 + 12 + ((3 * ((v3[7] & 0xF) + 1)) & 0xFFFFFFFC) + ((2 * v7 + 3) & 0xFFFFFFFC)];
    do
    {
      if ( sub_58F7D0(v21, *v11, v2) )
        v19 |= v9;
      v9 *= 2;
      ++v2;
      ++v11;
    }
    while ( v2 < 20 );
    v7 = v27;
  }
  v12 = v23;
  v13 = 0;
  v21 = 0;
  while ( v12 < v7 )
  {
    v14 = (unsigned __int8)v30[v12];
    if ( v14 >= v7 )
      break;
    v15 = &v3[4 * *(unsigned __int16 *)&v3[2 * v14 + 12]];
    if ( sub_58F8A0(v15) )
    {
      if ( sub_58F810(v3, v15, a1) )
      {
        if ( !v28
          || (v16 = 3 * (((char)v3[7] >> 4) + 1),
              LOBYTE(v16) = v16 & 0xFC,
              v17 = v16 + ((3 * ((v3[7] & 0xF) + 1)) & 0xFFFFFFFC),
              v18 = 2 * (unsigned __int8)v3[6] + 3,
              LOBYTE(v18) = v18 & 0xFC,
              *(_WORD *)&v3[2 * v14 + 16 + v18 + v17] == v19) )
        {
          sub_58F6D0(v31);
          if ( (int)sub_58E970(v31, v15, a1, (unsigned __int8)v29, (unsigned __int8)v25, v22) > 0 )
          {
            v21 = sub_58F1D0(&v20, v31, v15, v22, v26);
            if ( v21 )
              sub_58F6F0(v31, v24, v3, v15, v14, a1);
          }
        }
      }
    }
    v13 = v21;
    v12 = ++v23;
    if ( v21 )
      break;
    v7 = v27;
  }
  return v13;
}
