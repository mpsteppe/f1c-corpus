char __thiscall sub_4C1050(_DWORD *this)
{
  int v2; // eax
  char **v3; // eax
  char *v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  char *v10; // eax
  char *v11; // edi

  v2 = FlagsGetter(this);
  v3 = (char **)SessionConfigReader(v2);
  if ( v3 )
  {
    v4 = *v3;
    if ( !v4 )
      v4 = byte_5EA438;
    TrackSceneLoader(v4);
    AIW(0);
    this[11334] = 0;
    sub_4C0850(this + 11227);
    v5 = this;
    v6 = 103;
    do
    {
      v5[107] = 1;
      sub_4C0850(v5);
      v5 += 109;
      --v6;
    }
    while ( v6 );
    v7 = ActiveEntityCounter(this) + 1;
    if ( v7 < 103 )
    {
      v8 = 18624 * v7;
      do
      {
        SessionStateTransition(-1, 0);
        v8 += 18624;
      }
      while ( v8 < 1918272 );
    }
    sub_4B1190((int)byte_7CE498, -1.0);
    dword_7D00EC = this[11347];
    if ( dword_7D00EC >= dword_7D00F4 )
    {
      if ( dword_7D00EC > dword_7D00F8 )
        dword_7D00EC = dword_7D00F8;
    }
    else
    {
      dword_7D00EC = dword_7D00F4;
    }
    v9 = (char *)this[11227];
    if ( !v9 )
      v9 = byte_5EA438;
    StringCopyWithBufferRealloc(v9);
    v10 = (char *)this[11229];
    if ( !v10 )
      v10 = byte_5EA438;
    StringCopyWithBufferRealloc(v10);
    v11 = (char *)this[11229];
    if ( !v11 )
      v11 = byte_5EA438;
    ShortComputation_5730((int **)&dword_5EA5E8, (int)v11);
  }
  return 0;
}

