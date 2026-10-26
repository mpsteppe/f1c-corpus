char __thiscall sub_476EC0(_DWORD *this)
{
  char *v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // ebp
  int *v6; // ecx
  int v7; // ecx
  char *v8; // esi
  _BYTE *v9; // ecx
  bool v10; // cf
  int v11; // ecx
  int v12; // ecx
  int *v13; // ecx

  (*(void (__thiscall **)(_DWORD *))(*this + 160))(this);
  v2 = (char *)dword_7CE64C;
  v3 = 0;
  if ( !dword_7CE64C )
    v2 = byte_5EA438;
  v4 = sub_4C40B0(v2);
  v5 = v4;
  if ( v4 )
  {
    v6 = (int *)this[60];
    this[62] = v6;
    if ( v6 )
    {
      v7 = *v6;
      if ( v7 )
      {
        while ( 1 )
        {
          v8 = *(char **)(v7 + 4);
          if ( !v8 )
            v8 = byte_5EA438;
          v9 = (_BYTE *)(v5 + 124);
          while ( 1 )
          {
            LOBYTE(v4) = *v9;
            v10 = *v9 < (unsigned __int8)*v8;
            if ( *v9 != *v8 )
              break;
            if ( !*v9 )
              goto LABEL_13;
            LOBYTE(v4) = v9[1];
            v10 = (unsigned __int8)v4 < (unsigned __int8)v8[1];
            if ( (_BYTE)v4 != v8[1] )
              break;
            v9 += 2;
            v8 += 2;
            if ( !(_BYTE)v4 )
            {
LABEL_13:
              v11 = 0;
              goto LABEL_15;
            }
          }
          v11 = -v10 - (v10 - 1);
LABEL_15:
          if ( !v11 )
            break;
          v12 = this[62];
          ++v3;
          if ( v12 )
            this[62] = *(_DWORD *)(v12 + 4);
          v13 = (int *)this[62];
          if ( v13 )
          {
            v7 = *v13;
            if ( v7 )
              continue;
          }
          return v4;
        }
        this[93] = v3;
      }
    }
  }
  return v4;
}
