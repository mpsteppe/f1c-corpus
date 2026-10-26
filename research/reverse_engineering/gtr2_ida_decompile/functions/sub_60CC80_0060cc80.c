__int16 __thiscall sub_60CC80(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // ecx
  int v9; // ecx
  int v10; // ebp
  int v11; // ecx
  int v12; // ebp
  int i; // ebp
  _DWORD v16[64]; // [esp+10h] [ebp-200h]
  _DWORD v17[64]; // [esp+110h] [ebp-100h]

  v5 = this[192];
  v6 = a3;
  v7 = 0;
  if ( v5 == a2 )
    goto LABEL_42;
  if ( (a2 & 4) != (v5 & 4) )
  {
    v17[0] = 22;
    if ( (a2 & 4) != 0 )
      v16[0] = 1;
    else
      v16[0] = this[1202];
    v7 = 1;
  }
  v8 = a2 & 0x400;
  if ( v8 != (v5 & 0x400) )
  {
    v17[v7++] = 29;
    v16[v7 - 1] = v8 != 0;
  }
  v9 = a2 & 1;
  if ( v9 != (v5 & 1) )
  {
    v17[v7++] = 15;
    v16[v7 - 1] = v9 != 0;
  }
  if ( (a2 & 0x800) != (v5 & 0x800) )
  {
    v10 = this[1209];
    v17[v7] = 27;
    if ( (a2 & 0x800) != 0 )
    {
      v11 = a3;
      v16[v7++] = 1;
      if ( a3 == v10 )
        goto LABEL_24;
      if ( (_WORD)a3 != (_WORD)v10 )
      {
        v17[v7] = 19;
        v16[v7++] = (unsigned __int16)a3;
      }
      if ( HIWORD(a3) == *((_WORD *)this + 2419) )
        goto LABEL_23;
      v12 = HIWORD(a3);
    }
    else
    {
      v16[v7] = 0;
      v11 = 65538;
      ++v7;
      if ( v10 == 65538 )
        goto LABEL_24;
      if ( *((_WORD *)this + 2418) != 2 )
      {
        v17[v7] = 19;
        v16[v7++] = 2;
      }
      v12 = 1;
      if ( *((_WORD *)this + 2419) == 1 )
        goto LABEL_23;
    }
    v16[v7] = v12;
    v17[v7++] = 20;
LABEL_23:
    this[1209] = v11;
  }
LABEL_24:
  if ( (a2 & 0x1000) != (v5 & 0x1000) && (a2 & 0x1000) != 0 )
  {
    v17[v7] = 27;
    v16[v7++] = 1;
    if ( a3 != 131074 )
    {
      if ( *((_WORD *)this + 2418) != 2 )
      {
        v17[v7] = 19;
        v16[v7++] = 2;
      }
      if ( *((_WORD *)this + 2419) != 2 )
      {
        v17[v7] = 20;
        v16[v7++] = 2;
      }
      this[1209] = 131074;
    }
  }
  if ( (a2 & 0x10) != (v5 & 0x10) && (a2 & 0x10) != 0 )
  {
    v17[v7] = 9;
    v16[v7++] = 1;
  }
  if ( (a2 & 0x20) != (v5 & 0x20) && (a2 & 0x20) != 0 )
  {
    v17[v7] = 9;
    v16[v7++] = 1;
  }
  v5 &= 0x100u;
  if ( (a2 & 0x100) != v5 && (a2 & 0x100) != 0 )
  {
    v17[v7] = 9;
    v16[v7++] = 2;
  }
  v6 = a3;
LABEL_42:
  if ( (a2 & 1) != 0 )
  {
    LOWORD(v5) = a4;
    if ( a4 != this[1210] )
    {
      v17[v7] = 24;
      v16[v7++] = a4;
      this[1210] = a4;
    }
  }
  if ( (a2 & 0x800) != 0 )
  {
    v5 = this[1209];
    if ( v6 != v5 )
    {
      if ( (_WORD)v6 != (_WORD)v5 )
      {
        v17[v7] = 19;
        v16[v7++] = (unsigned __int16)v6;
      }
      LOWORD(v5) = HIWORD(a3);
      if ( HIWORD(a3) != *((_WORD *)this + 2419) )
      {
        v17[v7] = 20;
        v16[v7++] = HIWORD(a3);
      }
      this[1209] = v6;
    }
  }
  if ( v7 > 0 )
  {
    for ( i = 0; i < v7; ++i )
      LOWORD(v5) = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*this + 44))(this, v17[i], v16[i]);
  }
  this[192] = a2;
  return v5;
}
