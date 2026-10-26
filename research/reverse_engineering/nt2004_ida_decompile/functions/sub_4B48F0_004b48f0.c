int __thiscall sub_4B48F0(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  bool v11; // bl
  int v12; // eax
  int v13; // ecx

  v11 = *(_DWORD *)(dword_75AAC4 + 16584) == 2 || dword_7D5DA4 == 2;
  v12 = this[4];
  if ( v12 )
  {
    v13 = *(_DWORD *)(v12 + 16);
    if ( v13 )
    {
      if ( this[1] )
      {
        sub_59FFB0(0, 0, *(_DWORD *)(v13 + 28), *(_DWORD *)(v13 + 32), 0);
        if ( !v11 )
        {
          sub_4B4BC0(this);
          sub_4B4AF0(this);
          sub_4B4CA0(this);
          sub_4B4D00(this);
          sub_4B4D40(this);
          sub_4B4D80(this);
        }
      }
    }
  }
  sub_4B4E70(this, v11);
  v1 = this[21];
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 16);
    if ( v2 )
      sub_4B7CF0(0, this + 26, v2);
  }
  v3 = this[22];
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 16);
    if ( v4 )
      sub_4B7CF0(1, this + 45, v4);
  }
  v5 = this[23];
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 16);
    if ( v6 )
      sub_4B7CF0(2, this + 64, v6);
  }
  v7 = this[24];
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 16);
    if ( v8 )
      sub_4B7CF0(3, this + 83, v8);
  }
  result = this[25];
  if ( result )
  {
    result = *(_DWORD *)(result + 16);
    if ( result )
      return sub_4B7CF0(4, this + 102, result);
  }
  return result;
}
