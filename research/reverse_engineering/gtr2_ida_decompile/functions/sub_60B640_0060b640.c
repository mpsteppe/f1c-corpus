char __thiscall sub_60B640(char *this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // eax
  _DWORD *v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // eax
  _DWORD *v15; // ecx
  int v16; // eax
  _DWORD *v17; // ecx
  int v18; // eax
  _DWORD *v19; // ecx
  int v20; // eax
  _DWORD *v21; // ecx
  int v22; // eax
  _DWORD *v23; // ecx
  int v24; // eax
  _DWORD *v25; // ecx
  char v27; // [esp+7h] [ebp-1h]

  LOBYTE(v6) = 1;
  v27 = 1;
  if ( *this >= 0 )
  {
    if ( !a5 )
      a5 = *((_DWORD *)this + 6);
    if ( (a5 & 1) != 0 )
    {
      v7 = (_DWORD *)*((_DWORD *)this + 9);
      if ( v7 )
      {
        v8 = sub_60AD50(v7, a2, a3, a4);
        *((_DWORD *)this + 14) = v8;
        if ( !v8 )
          v27 = 0;
      }
    }
    if ( (a5 & 2) != 0 )
    {
      v9 = (_DWORD *)*((_DWORD *)this + 10);
      if ( v9 )
      {
        v10 = sub_60AD50(v9, a2, a3, a4);
        *((_DWORD *)this + 15) = v10;
        if ( !v10 )
          v27 = 0;
      }
    }
    if ( (a5 & 4) != 0 )
    {
      v11 = (_DWORD *)*((_DWORD *)this + 11);
      if ( v11 )
      {
        v12 = sub_60AD50(v11, a2, a3, a4);
        *((_DWORD *)this + 16) = v12;
        if ( !v12 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x10) != 0 )
    {
      v13 = (_DWORD *)*((_DWORD *)this + 12);
      if ( v13 )
      {
        v14 = sub_60AD50(v13, a2, a3, a4);
        *((_DWORD *)this + 17) = v14;
        if ( !v14 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x20) != 0 )
    {
      v15 = (_DWORD *)*((_DWORD *)this + 13);
      if ( v15 )
      {
        v16 = sub_60AD50(v15, a2, a3, a4);
        *((_DWORD *)this + 18) = v16;
        if ( !v16 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x1000) != 0 )
    {
      v17 = (_DWORD *)*((_DWORD *)this + 8);
      if ( v17 )
      {
        v18 = sub_60AD50(v17, a2, a3, a4);
        *((_DWORD *)this + 19) = v18;
        if ( !v18 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x8000) != 0 )
    {
      v19 = (_DWORD *)*((_DWORD *)this + 8);
      if ( v19 )
      {
        v20 = sub_60AD50(v19, a2, a3, a4);
        *((_DWORD *)this + 19) = v20;
        if ( !v20 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x2000) != 0 )
    {
      v21 = (_DWORD *)*((_DWORD *)this + 8);
      if ( v21 )
      {
        v22 = sub_60AD50(v21, a2, a3, a4);
        *((_DWORD *)this + 19) = v22;
        if ( !v22 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x4000) != 0 )
    {
      v23 = (_DWORD *)*((_DWORD *)this + 8);
      if ( v23 )
      {
        v24 = sub_60AD50(v23, a2, a3, a4);
        *((_DWORD *)this + 19) = v24;
        if ( !v24 )
          v27 = 0;
      }
    }
    if ( (a5 & 0x20000) == 0
      || (v25 = (_DWORD *)*((_DWORD *)this + 8)) == 0
      || (v6 = sub_60AD50(v25, a2, a3, a4), (*((_DWORD *)this + 19) = v6) != 0) )
    {
      LOBYTE(v6) = v27;
      if ( v27 )
        *(_DWORD *)this |= 0x80u;
    }
  }
  return v6;
}
