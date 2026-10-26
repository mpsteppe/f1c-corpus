int __thiscall sub_60D760(_DWORD *this, int *a2, char a3)
{
  int *v3; // esi
  int v5; // ebp
  _DWORD *v6; // ebx
  int v7; // eax
  int v8; // eax
  int *v9; // ecx
  char v10; // bl
  int v11; // eax
  int i; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  bool v16; // zf

  v3 = a2;
  if ( sub_5E7150(a2, 8) )
  {
    v5 = 0;
    if ( (int)this[1206] > 0 )
    {
      v6 = this + 705;
      do
      {
        v7 = this[2387];
        a2 = 0;
        this[2] = (*(int (__stdcall **)(int, int, int **))(*(_DWORD *)v7 + 256))(v7, v5, &a2);
        if ( a2 )
        {
          v8 = sub_5E7150(v3, 8);
          v9 = a2;
          if ( (int *)v8 == a2 )
          {
            sub_60A820(v6, 0);
            v9 = a2;
          }
          this[2] = (*(int (__stdcall **)(int *))(*v9 + 8))(v9);
        }
        ++v5;
        v6 += 62;
      }
      while ( v5 < this[1206] );
    }
    v10 = a3;
    if ( (*(_BYTE *)v3 & 0x40) == 0 )
      goto LABEL_31;
    if ( a3 )
    {
      (*(void (__thiscall **)(_DWORD *, int *))(*this + 248))(this, v3);
      if ( (int *)this[2431] == v3 )
        (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*this + 588))(this, 0, 0);
    }
    if ( (*(_BYTE *)v3 & 0x40) == 0 || v10 )
    {
LABEL_31:
      if ( sub_5E7150(v3, 8) )
      {
        v11 = sub_5E7150(v3, 8);
        this[2] = (*(int (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
        sub_5E71A0(v3, 0, 8);
        if ( sub_5E7150(v3, 4) )
        {
          if ( (*v3 & 0x10) != 0 )
          {
            for ( i = 0; i < 6; ++i )
            {
              v13 = sub_5E7150(v3, 4);
              (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v13 + 84))(v13, i, 0);
            }
          }
          else
          {
            if ( (*v3 & 0x20) != 0 )
              v14 = sub_6CE7B0(4);
            else
              v14 = sub_5E7150(v3, 4);
            (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v14 + 84))(v14, 0);
          }
        }
      }
    }
  }
  v15 = *v3;
  v16 = (*v3 & 0x40) == 0;
  v3[8] = 0;
  if ( v16 )
    *v3 = v15 & 0xFFFFFEF7;
  else
    *v3 = v15 & 0xFFFFFEFF;
  return 0;
}
