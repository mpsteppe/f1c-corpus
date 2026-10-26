int __thiscall sub_476660(_DWORD *this)
{
  int *v2; // eax
  int v3; // eax
  int v4; // edi
  char *v5; // eax
  char *v6; // ecx
  int v7; // eax
  int *v8; // eax

  v2 = (int *)this[60];
  this[62] = v2;
  if ( v2 )
    v3 = *v2;
  else
    v3 = 0;
  v4 = 0;
  this[93] = 0;
  if ( v3 )
  {
    while ( 1 )
    {
      v5 = *(char **)(v3 + 60);
      if ( !v5 )
        v5 = byte_5EA438;
      v6 = (char *)dword_7D0434;
      if ( !dword_7D0434 )
        v6 = byte_5EA438;
      if ( !sub_588410(v6, v5) )
        break;
      v7 = this[62];
      ++v4;
      if ( v7 )
        this[62] = *(_DWORD *)(v7 + 4);
      v8 = (int *)this[62];
      if ( v8 )
      {
        v3 = *v8;
        if ( v3 )
          continue;
      }
      return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
    }
    this[93] = v4;
  }
  return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
}
