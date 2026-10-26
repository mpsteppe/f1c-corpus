char __thiscall sub_616A70(_DWORD *this, int a2)
{
  const char ***v3; // eax
  _DWORD *v4; // edi
  const char **v5; // eax
  const char *v6; // ecx
  const char *v7; // eax
  int v8; // eax
  int v9; // eax
  const char ***v10; // eax
  _DWORD *v11; // eax
  int v12; // edx
  const char *v13; // esi
  _DWORD *v14; // eax

  v3 = (const char ***)this[9];
  v4 = this + 9;
  this[11] = v3;
  if ( v3 && (v5 = *v3) != 0 )
  {
    while ( 1 )
    {
      v6 = *(const char **)(a2 + 8);
      if ( !v6 )
        v6 = WindowName;
      v7 = *v5;
      if ( !v7 )
        v7 = WindowName;
      v8 = _stricmp(v7, v6);
      if ( !v8 )
        break;
      v9 = v4[2];
      if ( v9 )
        v4[2] = *(_DWORD *)(v9 + 4);
      v10 = (const char ***)v4[2];
      if ( v10 )
      {
        v5 = *v10;
        if ( v5 )
          continue;
      }
      goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v11 = operator new(0xCu);
    if ( v11 )
    {
      v12 = this[13];
      this[13] = v12 + 1;
      v13 = *(const char **)(a2 + 8);
      if ( !v13 )
        v13 = WindowName;
      v14 = sub_616520(v11, v13, v12);
    }
    else
    {
      v14 = 0;
    }
    LOBYTE(v8) = sub_5FDFB0(v4, (int)v14, 1);
  }
  return v8;
}
