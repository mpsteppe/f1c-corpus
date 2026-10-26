int __thiscall sub_5E9420(char *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // ebp
  bool v9; // zf
  bool v10; // cc
  int v11; // eax
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  if ( (*(_DWORD *)this & 1) == 0 || (*(_DWORD *)this & 2) == 0 )
    return 0;
  v2 = *((_DWORD *)this + 63);
  switch ( *((_DWORD *)this + 63) )
  {
    case 1:
      v3 = *((_DWORD *)this + 66);
      break;
    case 2:
      v3 = *((_DWORD *)this + 133);
      break;
    case 3:
      v3 = *((_DWORD *)this + 200);
      break;
    default:
      v3 = 0;
      break;
  }
  v4 = v2 - 1;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        v6 = *((_DWORD *)this + 201);
      else
        v6 = 0;
    }
    else
    {
      v6 = *((_DWORD *)this + 134);
    }
  }
  else
  {
    v6 = *((_DWORD *)this + 67);
  }
  v15 = v3 + v6;
  v13 = v3;
  if ( v3 >= v3 + v6 )
  {
LABEL_26:
    if ( !strcmp(this + 4, "STLITA") || !strcmp(this + 4, "PTLITA") )
    {
      v11 = *(_DWORD *)this | 0x10000;
      *((_DWORD *)this + 59) = 5;
      *((_DWORD *)this + 60) = 6;
      *(_DWORD *)this = v11;
    }
    return 0;
  }
  v7 = 484 * v3;
  v14 = v7;
  while ( !sub_5E3AA0(
             (char *)(v7 + *((_DWORD *)this + 65)),
             COERCE_FLOAT(this + 4),
             this + 68,
             *((float *)this + 61),
             1) )
  {
    v8 = *(_DWORD *)this & 0xFFFFFFFD;
    v9 = (*(_DWORD *)this & 0x10000) == 0;
    *(_DWORD *)this = v8;
    if ( !v9
      && (!strcmp(this + 4, "WC_TEAM_WINDOWS_GL_A8") || strlen(this + 4) > 4 && !strcmp(&this[strlen(this + 4)], "_WPS")) )
    {
      *(_DWORD *)this = v8 | 0x20000;
    }
    v7 = v14 + 484;
    v10 = ++v13 < v15;
    v14 += 484;
    if ( !v10 )
      goto LABEL_26;
  }
  return -1;
}
