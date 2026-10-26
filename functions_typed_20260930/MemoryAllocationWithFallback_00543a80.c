int __thiscall sub_543A80(_BYTE *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  void *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  void *v8; // esi
  void *v9; // esi
  void *v10; // esi

  if ( !a2 )
    return 0;
  if ( (this[236] & 4) == 0 )
  {
    v3 = (_DWORD *)OperatorNewNhMallocWrapper(60);
    if ( v3 )
      v4 = AudioEmitterCreate(v3);
    else
      v4 = 0;
    dword_8B8DBC = (int)v4;
    if ( UtilityFunction_2950(v4, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152) )
    {
      v5 = (void *)dword_8B8DBC;
      if ( dword_8B8DBC )
      {
        EmptyStub_7470(dword_8B8DBC);
        FreeWrapper_7bcf(v5);
      }
      dword_8B8DBC = 0;
    }
    v6 = (_DWORD *)OperatorNewNhMallocWrapper(60);
    if ( v6 )
      v7 = AudioEmitterCreate(v6);
    else
      v7 = 0;
    dword_8B8DC0 = (int)v7;
    if ( UtilityFunction_2950(v7, dword_8B8DF4, dword_8B8DF4, dword_8B8DF8, 262152) )
    {
      v8 = (void *)dword_8B8DC0;
      if ( dword_8B8DC0 )
      {
        EmptyStub_7470(dword_8B8DC0);
        FreeWrapper_7bcf(v8);
      }
      dword_8B8DC0 = 0;
    }
  }
  if ( !sub_55B6B0(a2) )
  {
    *((_DWORD *)this + 59) |= 0x10800u;
    return 0;
  }
  if ( dword_8B8DBC )
  {
    sub_542E50((_DWORD *)dword_8B8DBC);
    v9 = (void *)dword_8B8DBC;
    if ( dword_8B8DBC )
    {
      EmptyStub_7470(dword_8B8DBC);
      FreeWrapper_7bcf(v9);
    }
    dword_8B8DBC = 0;
  }
  if ( dword_8B8DC0 )
  {
    sub_542E50((_DWORD *)dword_8B8DC0);
    v10 = (void *)dword_8B8DC0;
    if ( dword_8B8DC0 )
    {
      EmptyStub_7470(dword_8B8DC0);
      FreeWrapper_7bcf(v10);
    }
    dword_8B8DC0 = 0;
  }
  return -1;
}

