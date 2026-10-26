int __thiscall sub_5E2E70(char *this, const char *ArgList, int a3, int a4, int a5, int a6, int a7, int a8)
{
  char v9; // al
  bool v10; // zf
  unsigned int v12; // eax
  char v13; // cl
  int v14; // eax
  char *v15; // edi
  const char *v16; // eax
  int v17; // edx
  char v18; // cl
  char v19; // [esp+0h] [ebp-10h]

  if ( (a8 & 0x100000) != 0 )
    goto LABEL_26;
  v9 = 0;
  if ( a3 > 128 )
  {
    if ( a3 > 1024 )
    {
      if ( a3 == 2048 )
        goto LABEL_14;
      v10 = a3 == 4096;
    }
    else
    {
      if ( a3 == 1024 || a3 == 256 )
        goto LABEL_14;
      v10 = a3 == 512;
    }
    if ( !v10 )
LABEL_13:
      v9 = 1;
  }
  else if ( a3 != 128 )
  {
    if ( (unsigned int)a3 <= 0x40 )
    {
      switch ( a3 )
      {
        case 0:
        case 1:
        case 2:
          goto LABEL_14;
        case 3:
          goto LABEL_13;
      }
      goto LABEL_14;
    }
    goto LABEL_13;
  }
LABEL_14:
  if ( a4 > 128 )
  {
    if ( a4 > 1024 )
    {
      if ( a4 != 2048 && a4 != 4096 )
        goto LABEL_25;
    }
    else if ( a4 != 1024 && a4 != 256 && a4 != 512 )
    {
      goto LABEL_25;
    }
  }
  else if ( a4 != 128 )
  {
    switch ( a4 )
    {
      case 0:
      case 1:
      case 2:
      case 4:
      case 8:
      case 16:
      case 32:
      case 64:
        break;
      default:
        goto LABEL_25;
    }
  }
  if ( v9 )
  {
LABEL_25:
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Texture %s is not power of 2 size", (char)ArgList);
    sub_5D8CE0();
    return -1;
  }
LABEL_26:
  if ( (a7 & 3) != 0 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Surface type must be SYSTEMTEXTURE or VIDEOTEXTURE", v19);
    return -1;
  }
  else
  {
    v12 = strlen(ArgList);
    v13 = ArgList[v12 - 1];
    v14 = v12 - 1;
    if ( v13 != 92 )
    {
      do
        --v14;
      while ( v14 >= 0 && ArgList[v14] != 92 );
    }
    v15 = this + 140;
    v16 = &ArgList[v14 + 1];
    v17 = v15 - v16;
    do
    {
      v18 = *v16;
      v16[v17] = *v16;
      ++v16;
    }
    while ( v18 );
    _strupr(v15);
    if ( a3 > 0 && a4 > 0 && sub_5E72D0(a3, a4, a5, a6, a7) )
    {
      sub_5E6DD0(this);
      *v15 = 0;
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing texture surface for %s", (char)ArgList);
      return -1;
    }
    else
    {
      return 0;
    }
  }
}
