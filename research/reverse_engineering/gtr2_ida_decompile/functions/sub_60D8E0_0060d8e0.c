int __thiscall sub_60D8E0(_DWORD **this, int *a2)
{
  _DWORD *v4; // ebp
  _DWORD *v5; // edx
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // [esp-Ch] [ebp-14h]

  if ( !a2 )
    return 0;
  if ( (*a2 & 0x100) == 0 )
  {
    if ( ((int (__thiscall *)(_DWORD **, int *))(*this)[83])(this, a2) == -1 )
    {
      v4 = 0;
      v5 = dword_FB2D78;
      v6 = 0x7FFFFFFF;
      dword_FB2D80 = (int)dword_FB2D78;
      if ( !dword_FB2D78 )
        goto LABEL_20;
      v7 = *(_DWORD **)dword_FB2D78;
      if ( !*(_DWORD *)dword_FB2D78 )
        goto LABEL_20;
      do
      {
        if ( (*v7 & 0x10000) == 0
          && (*v7 & 0x100) != 0
          && v7[5] == a2[5]
          && v7[6] == a2[6]
          && v7[1] == a2[1]
          && v7[2] == a2[2]
          && v7[8] < v6 )
        {
          v4 = v7;
          v6 = v7[8];
        }
        v5 = (_DWORD *)v5[1];
        dword_FB2D80 = (int)v5;
        if ( !v5 )
          break;
        v7 = (_DWORD *)*v5;
      }
      while ( *v5 );
      if ( v4 )
      {
        ((void (__thiscall *)(_DWORD **, _DWORD *, _DWORD))(*this)[84])(this, v4, 0);
        if ( ((int (__thiscall *)(_DWORD **, int *))(*this)[83])(this, a2) )
          return 0;
      }
      else
      {
LABEL_20:
        ((void (__thiscall *)(_DWORD **, _DWORD))(*this)[85])(this, 0);
        if ( ((int (__thiscall *)(_DWORD **, int *))(*this)[83])(this, a2) )
          return 0;
      }
    }
    if ( sub_5E7150(a2, 4) )
    {
      v8 = *this[2387];
      v11 = sub_5E7150(a2, 8);
      v9 = sub_5E7150(a2, 4);
      v10 = (*(int (__stdcall **)(_DWORD *, int, int))(v8 + 124))(this[2387], v9, v11);
      this[2] = (_DWORD *)v10;
      if ( v10 )
        return 0;
      *a2 |= 0x100u;
    }
  }
  ++a2[8];
  return 1;
}
