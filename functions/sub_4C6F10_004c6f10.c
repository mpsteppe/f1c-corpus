void __thiscall sub_4C6F10(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  int i; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ebp
  int v12; // edi
  int k; // ebx
  int v14; // edx
  int m; // ecx
  int v16; // eax
  int v17; // eax
  bool v18; // sf
  int j; // [esp+10h] [ebp-4Ch]
  int v20; // [esp+14h] [ebp-48h]
  int v21; // [esp+18h] [ebp-44h]
  int v22; // [esp+18h] [ebp-44h]
  int v23; // [esp+1Ch] [ebp-40h]
  int v24; // [esp+20h] [ebp-3Ch]
  int v25; // [esp+24h] [ebp-38h]
  int v26; // [esp+28h] [ebp-34h]
  float v27[3]; // [esp+2Ch] [ebp-30h] BYREF
  float v28[3]; // [esp+38h] [ebp-24h] BYREF
  float v29[3]; // [esp+44h] [ebp-18h] BYREF
  float v30[3]; // [esp+50h] [ebp-Ch] BYREF

  v2 = 0;
  this[4649] = this[4645] % 52;
  do
  {
    v3 = IndexedArrayAccessor(v2);
    if ( !v3 )
      break;
    if ( !sub_588410(this + 4526, v3) )
    {
      this[4649] = v2;
      break;
    }
    ++v2;
  }
  while ( v2 < 52 );
  v4 = this[4548];
  v24 = 0;
  v25 = 2;
  v26 = 1;
  if ( (v4 & 1) != v4 < 13 )
  {
    v24 = 2;
    v25 = 0;
  }
  v5 = dword_7D0B40;
  v21 = dword_7D0B40;
  v20 = dword_7D0B40;
  if ( dword_7D0B40 >= 3 )
    v20 = 3;
  ArrayOfStructIndexedFieldCopy(dword_5EA2C0, this[4649], v28, v27);
  if ( ZeroVectorCheck(v28, v27) && (v6 = 0, v5 > 0) )
  {
    while ( 1 )
    {
      v7 = *(&v24 + v6);
      this[4650] = v7;
      for ( i = 0; i < dword_5C329C; ++i )
      {
        v9 = dword_7C54F0[i];
        if ( (_DWORD *)v9 != this && *(_DWORD *)(v9 + 18596) == this[4649] && *(_DWORD *)(v9 + 18600) == v7 )
          break;
      }
      if ( i == dword_5C329C )
        break;
      if ( ++v6 >= v21 )
        goto LABEL_20;
    }
  }
  else
  {
LABEL_20:
    v10 = 0;
    for ( j = 0; ; v10 = j )
    {
      v11 = v20;
      v12 = v10 != 0 ? v20 : 0;
      v23 = v12;
      if ( v10 )
        v11 = 3;
      v22 = v11;
      this[4649] = 0;
      do
      {
        ArrayOfStructIndexedFieldCopy(dword_5EA2C0, this[4649], v28, v27);
        if ( ZeroVectorCheck(v28, v27) )
        {
          for ( k = v12; k < v11; ++k )
          {
            IndexedStructDataRead(dword_5EA2C0, this[4649], k, v30, v29);
            if ( v30[0] != 0.0 || v30[2] != 0.0 || v29[0] != 0.0 || v29[1] != 0.0 || v29[2] != 0.0 )
            {
              v14 = *(&v24 + k);
              this[4650] = v14;
              for ( m = 0; m < dword_5C329C; ++m )
              {
                v16 = dword_7C54F0[m];
                if ( (_DWORD *)v16 != this && *(_DWORD *)(v16 + 18596) == this[4649] && *(_DWORD *)(v16 + 18600) == v14 )
                  break;
              }
              if ( m == dword_5C329C )
                return;
              v11 = v22;
              v12 = v23;
            }
          }
        }
        v17 = this[4649] + 1;
        v18 = this[4649] - 51 < 0;
        this[4649] = v17;
      }
      while ( v18 != __OFSUB__(v17, 52) );
      if ( ++j >= 2 )
        break;
    }
    this[4649] = -1;
    this[4650] = -1;
  }
}
