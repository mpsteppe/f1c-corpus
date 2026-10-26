int __thiscall sub_6B2D5D(int this)
{
  int v2; // edi
  bool v3; // zf
  _DWORD *v4; // eax
  int result; // eax
  unsigned int i; // edi
  int v7; // eax
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // eax
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebx
  int v16; // edi
  unsigned int v17; // ebx
  int v18; // edi
  unsigned int v19; // [esp+Ch] [ebp-8h]
  int v20; // [esp+10h] [ebp-4h]
  int v21; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( *(_DWORD *)(this + 92) )
  {
    v3 = *(_DWORD *)(this + 12) == 0;
    *(_DWORD *)(this + 252) = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(this + 252));
        *(_DWORD *)(this + 256) = v4;
        if ( (*v4 & 0xFFF00000) == 0x20800000 )
        {
          result = sub_6BC65D(this);
          if ( result < 0 )
            return result;
          v2 |= result == 0;
        }
        ++*(_DWORD *)(this + 252);
      }
      while ( *(_DWORD *)(this + 252) < *(_DWORD *)(this + 12) );
      if ( v2 )
        sub_6BC1A9(this);
    }
  }
  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
    goto LABEL_26;
  for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
  {
    v7 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = i;
    *(_DWORD *)(this + 256) = *(_DWORD *)(v7 + 4 * i);
    if ( !sub_6B26DB((_DWORD *)this) )
      sub_6BC1A9(this);
  }
  v8 = 0;
  if ( !*(_DWORD *)(this + 12) )
  {
LABEL_18:
    sub_6BC1A9(this);
    v11 = 0;
    if ( *(_DWORD *)(this + 12) )
    {
      do
      {
        v12 = *(_DWORD *)(this + 24);
        *(_DWORD *)(this + 252) = v11;
        v13 = *(_DWORD **)(v12 + 4 * v11);
        *(_DWORD *)(this + 256) = v13;
        v14 = *v13 & 0xFFF00000;
        if ( v14 == 271581184 || v14 == 273678336 || v14 == 274726912 || v14 == 275775488 || v14 == 1342177280 )
        {
          result = sub_6BFAB9(this);
          if ( result < 0 )
            return result;
        }
      }
      while ( (unsigned int)++v11 < *(_DWORD *)(this + 12) );
    }
LABEL_26:
    if ( *(_DWORD *)(this + 48) )
    {
      v19 = 0;
      while ( v19 < 0x10 )
      {
        v15 = *(_DWORD *)(this + 12);
        v16 = 0;
        v20 = 1;
        if ( v15 )
        {
          do
          {
            *(_DWORD *)(this + 256) = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v16);
            result = sub_6BCB13(this);
            if ( result < 0 )
              return result;
            if ( !result )
              v20 = 0;
            result = sub_681C03((void *)this, *(_DWORD **)(this + 256));
            if ( result < 0 )
              return result;
            **(_DWORD **)(this + 256) = 0;
          }
          while ( ++v16 < v15 );
        }
        result = sub_6825A9((_DWORD *)this);
        if ( result < 0 )
          return result;
        ++v19;
        if ( v20 )
        {
          if ( v19 < 0x10 )
            goto LABEL_47;
          break;
        }
      }
      v17 = *(_DWORD *)(this + 12);
      v18 = 0;
      v21 = 1;
      if ( v17 )
      {
        do
        {
          *(_DWORD *)(this + 256) = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v18);
          result = sub_6BCB13(this);
          if ( result < 0 )
            return result;
          if ( !result )
          {
            sub_686791(this, *(_DWORD *)(*(_DWORD *)(this + 256) + 60), 4553, "relative address refrences too deep");
            v21 = 0;
          }
          result = sub_681C03((void *)this, *(_DWORD **)(this + 256));
          if ( result < 0 )
            return result;
          **(_DWORD **)(this + 256) = 0;
        }
        while ( ++v18 < v17 );
      }
      result = sub_6825A9((_DWORD *)this);
      if ( result < 0 )
        return result;
      if ( !v21 )
        return -2147467259;
    }
LABEL_47:
    if ( !*(_DWORD *)(this + 96) )
      return 0;
    result = sub_6C9033(this);
    if ( result >= 0 )
    {
      sub_6BC1A9(this);
      result = sub_688BDF((_DWORD *)this);
      if ( result >= 0 )
        return 0;
    }
    return result;
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 252) = v8;
    v10 = *(_DWORD **)(v9 + 4 * v8);
    *(_DWORD *)(this + 256) = v10;
    if ( (*v10 & 0xFFF00000) == 0x50000000 )
    {
      result = sub_6B16E1((_DWORD *)this);
      if ( result < 0 )
        return result;
    }
    if ( (unsigned int)++v8 >= *(_DWORD *)(this + 12) )
      goto LABEL_18;
  }
}
