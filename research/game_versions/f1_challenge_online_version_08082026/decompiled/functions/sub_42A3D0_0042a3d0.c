char __thiscall sub_42A3D0(_DWORD *this)
{
  int v2; // eax
  int v3; // edx
  double v4; // st7
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  double v9; // st7
  double v10; // st7
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int i; // ebp
  char v16; // [esp+13h] [ebp-9h]
  float v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+14h] [ebp-8h]
  float v19; // [esp+18h] [ebp-4h]
  _DWORD *v20; // [esp+18h] [ebp-4h]

  v2 = this[4472];
  v3 = this[4450];
  v16 = 1;
  *((_BYTE *)this + 17736) = 1;
  *((_BYTE *)this + 17796) = 0;
  if ( v2 + 1 > v3 )
  {
    if ( dword_7C56A4 == 7 )
    {
      if ( dword_7C56A8 != 8 )
        *((_BYTE *)this + 17796) = 1;
      v4 = (double)(dword_8ACF8C - this[4111]) + 1.5;
    }
    else
    {
      v4 = (double)(int)this[4 * v2 + 4452] - (double)(int)this[4111];
    }
  }
  else
  {
    v4 = (double)(this[4 * v2 + 4456] - this[4111]) + 1.5;
  }
  v17 = v4;
  if ( *(_DWORD *)(*this + 3352) && !*(_BYTE *)(*this + 3416) && dword_7C56A4 == 7 )
  {
    sub_4EFAC0(this + 3);
    v5 = this[4111];
    v6 = 4 * (this[4472] + 1113);
    *((_BYTE *)this + 17796) = 0;
    this[v6] = v5;
    this[4 * this[4472] + 4455] = 8;
  }
  if ( *((_BYTE *)this + 14842) && dword_7C56A4 == 7 )
  {
    sub_4EFAC0(this + 3);
    v7 = this[4111];
    v8 = 4 * (this[4472] + 1113);
    *((_BYTE *)this + 17796) = 0;
    this[v8] = v7;
    this[4 * this[4472] + 4455] = 8;
  }
  if ( sub_42AEE0(this) || dword_7C56A4 != 7 )
  {
    v16 = 0;
    sub_4C6D90(0);
    *((float *)this + 4429) = dbl_8AFEA0 + 180.0;
    if ( dword_7C56A4 == 7 )
    {
      *((_BYTE *)this + 17424) = 1;
      *((_BYTE *)this + 17908) = 0;
      sub_4BC060(1);
    }
  }
  if ( v17 >= 3.0 )
    v9 = v17;
  else
    v9 = 3.0;
  v10 = v9 * *((float *)this + 4474);
  if ( *((float *)this + 3682) < v10 )
    v10 = *((float *)this + 3682);
  v19 = v10;
  *(float *)&this[4 * this[4472] + 4453] = v10;
  sub_4A5BD0(v19);
  if ( !v16 )
  {
    sub_4F1890(LODWORD(v19));
    sub_42A6F0(this);
  }
  v11 = *this;
  if ( *(_DWORD *)(*this + 3284) && !*(_BYTE *)(v11 + 3348) || *(_DWORD *)(v11 + 3352) && !*(_BYTE *)(v11 + 3416) )
    sub_4A56B0(1);
  if ( flt_8AFEE8 >= 0.0099999998 )
  {
    if ( flt_8AFEE8 >= 0.33000001 )
    {
      v18 = 5;
      if ( flt_8AFEE8 >= 0.66000003 )
        v18 = 6;
    }
    else
    {
      v18 = 4;
    }
  }
  else
  {
    v18 = this[4451];
  }
  v12 = 0;
  v20 = this + 4480;
  do
  {
    if ( *v20 == v18 )
    {
      v13 = this[3294];
      for ( i = 0; v13 != v12; v13 = this[3294] )
      {
        if ( v13 >= v12 )
          sub_4A57A0(2);
        else
          sub_4A5750(2);
        if ( ++i > 7 )
          break;
      }
    }
    ++v12;
    ++v20;
  }
  while ( v12 < 7 );
  return v16;
}
