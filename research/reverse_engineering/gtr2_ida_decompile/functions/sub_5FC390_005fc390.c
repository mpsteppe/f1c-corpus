unsigned int __thiscall sub_5FC390(unsigned int *this, char a2)
{
  _DWORD **v3; // eax
  _DWORD *v4; // edi
  int v5; // ecx
  int *v6; // eax
  int v7; // ecx
  unsigned int v8; // eax
  int *v9; // eax
  int *v10; // eax
  int i; // eax
  unsigned int v12; // eax
  int *v13; // eax
  int *v14; // eax
  int v15; // edi
  int *v16; // eax
  int j; // eax
  unsigned int v18; // eax
  int *v19; // eax
  unsigned int v20; // eax
  int *v21; // eax
  _DWORD **v22; // eax
  _DWORD *k; // eax
  unsigned int v24; // eax
  _DWORD **v25; // eax
  unsigned int result; // eax
  float v27; // [esp+8h] [ebp-Ch]

  (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 660))(dword_FB27A4);
  sub_5FBC30((int)(this + 23));
  sub_5FBC30((int)(this + 28));
  sub_5FBC30((int)(this + 33));
  sub_5FBC30((int)(this + 38));
  sub_5FBC30((int)(this + 43));
  sub_5FBC30((int)(this + 48));
  if ( (int)this[191] > 0 && (v3 = (_DWORD **)this[188]) != 0 )
    v4 = *v3;
  else
    v4 = 0;
  if ( (*v4 & 0xF00) != 0 )
  {
    dword_FB2824 = dword_FB281C;
    if ( dword_FB281C )
    {
      v5 = *(_DWORD *)dword_FB281C;
      if ( *(_DWORD *)dword_FB281C )
      {
        do
        {
          sub_5E88B0(v5, (int)this, (int)v4);
          if ( !dword_FB2824 )
            break;
          dword_FB2824 = *(_DWORD *)(dword_FB2824 + 4);
          if ( !dword_FB2824 )
            break;
          v5 = *(_DWORD *)dword_FB2824;
        }
        while ( *(_DWORD *)dword_FB2824 );
      }
    }
  }
  if ( (int)this[192] > 0 )
  {
    v6 = (int *)this[193];
    this[195] = (unsigned int)v6;
    if ( v6 )
    {
      v7 = *v6;
      if ( *v6 )
      {
        do
        {
          if ( (*(_BYTE *)v7 & 1) != 0 && *(_DWORD *)(v7 + 200) )
            sub_600870(0, 1);
          v8 = this[195];
          if ( !v8 )
            break;
          v9 = *(int **)(v8 + 4);
          this[195] = (unsigned int)v9;
          if ( !v9 )
            break;
          v7 = *v9;
        }
        while ( *v9 );
      }
    }
  }
  v10 = (int *)this[129];
  this[131] = (unsigned int)v10;
  if ( v10 )
  {
    for ( i = *v10; i; i = *v13 )
    {
      sub_5E3540(i);
      v12 = this[131];
      if ( !v12 )
        break;
      v13 = *(int **)(v12 + 4);
      this[131] = (unsigned int)v13;
      if ( !v13 )
        break;
    }
  }
  if ( a2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 468))(dword_FB27A4);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 460))(dword_FB27A4, 0);
  v14 = (int *)this[97];
  this[99] = (unsigned int)v14;
  if ( v14 )
  {
    v15 = *v14;
    if ( *v14 )
    {
      do
      {
        v16 = (int *)this[133];
        this[135] = (unsigned int)v16;
        if ( v16 )
        {
          for ( j = *v16; j; j = *v19 )
          {
            sub_607090(j, (int)this, v15, 0);
            v18 = this[135];
            if ( !v18 )
              break;
            v19 = *(int **)(v18 + 4);
            this[135] = (unsigned int)v19;
            if ( !v19 )
              break;
          }
        }
        sub_5FBFF0(v15, (int)(this + 113), (int)(this + 109), v15, (int)(this + 109), (int)(this + 113), 0);
        v20 = this[99];
        if ( !v20 )
          break;
        v21 = *(int **)(v20 + 4);
        this[99] = (unsigned int)v21;
        if ( !v21 )
          break;
        v15 = *v21;
      }
      while ( *v21 );
    }
  }
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 464))(dword_FB27A4, 0);
  if ( (*this & 0x800) != 0 )
  {
    v27 = sub_5F5AA0(0);
    sub_5E43D0(v27);
  }
  v22 = (_DWORD **)this[188];
  this[190] = (unsigned int)v22;
  if ( v22 )
  {
    for ( k = *v22; k; k = *v25 )
    {
      *k &= 0xFFFFF0FF;
      v24 = this[190];
      if ( !v24 )
        break;
      v25 = *(_DWORD ***)(v24 + 4);
      this[190] = (unsigned int)v25;
      if ( !v25 )
        break;
    }
  }
  result = *this & 0xFEFFFFFF;
  *this = result;
  return result;
}
