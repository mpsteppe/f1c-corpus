int __thiscall sub_490B90(int *this)
{
  int v2; // edi
  int v3; // ebp
  int *v4; // edi
  int *v5; // ebx
  int *v6; // ebp
  int v7; // eax
  void *v8; // edx
  int v9; // edi
  int v10; // ebx
  int v11; // esi
  int result; // eax
  _DWORD *v13; // edi
  char v14; // al
  int v15; // esi
  _DWORD *v16; // edi
  char v17; // al
  int v18; // esi
  _DWORD *v19; // edi
  char v20; // al
  void *v21; // ebp
  int *v22; // [esp+Ch] [ebp-Ch]
  void *v23; // [esp+14h] [ebp-4h]

  v2 = 0;
  if ( *this > 0 )
  {
    v3 = 0;
    do
    {
      sub_4910D0(v3 + this[2]);
      ++v2;
      v3 += 16;
    }
    while ( v2 < *this );
  }
  v4 = this + 3;
  v22 = this + 3;
  sub_4910D0(this + 3);
  v5 = this + 7;
  sub_4910D0(this + 7);
  v6 = this + 11;
  sub_4910D0(this + 11);
  v7 = this[2];
  if ( v7 )
  {
    v8 = (void *)(v7 - 4);
    v9 = v7 + 16 * *(_DWORD *)(v7 - 4);
    v23 = (void *)(v7 - 4);
    if ( *(_DWORD *)(v7 - 4) - 1 >= 0 )
    {
      v10 = *(_DWORD *)(v7 - 4);
      do
      {
        v9 -= 16;
        sub_491DB0(v9);
        --v10;
      }
      while ( v10 );
      v5 = this + 7;
      v8 = v23;
    }
    sub_587BCF(v8);
    v4 = this + 3;
  }
  nullsub_3(this + 15);
  v11 = *v6;
  result = 0;
  if ( *v6 )
  {
    do
    {
      v13 = (_DWORD *)v11;
      v14 = *(_BYTE *)(v11 + 8);
      v11 = *(_DWORD *)(v11 + 4);
      if ( v14 && *v13 )
        sub_491E60(1);
      sub_587BCF(v13);
    }
    while ( v11 );
    v4 = v22;
    result = 0;
  }
  *v6 = 0;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 0;
  v15 = *v5;
  if ( *v5 )
  {
    do
    {
      v16 = (_DWORD *)v15;
      v17 = *(_BYTE *)(v15 + 8);
      v15 = *(_DWORD *)(v15 + 4);
      if ( v17 && *v16 )
        sub_491E60(1);
      sub_587BCF(v16);
    }
    while ( v15 );
    v4 = v22;
    result = 0;
  }
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v18 = *v4;
  if ( *v4 )
  {
    do
    {
      v19 = (_DWORD *)v18;
      v20 = *(_BYTE *)(v18 + 8);
      v18 = *(_DWORD *)(v18 + 4);
      if ( v20 )
      {
        v21 = (void *)*v19;
        if ( *v19 )
        {
          nullsub_3(*v19);
          sub_587BCF(v21);
        }
      }
      sub_587BCF(v19);
    }
    while ( v18 );
    v4 = v22;
    result = 0;
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  return result;
}
