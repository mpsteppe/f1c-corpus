int __thiscall sub_6A0549(int this)
{
  int v2; // edi
  bool v3; // zf
  _DWORD *v4; // eax
  int result; // eax
  unsigned int v6; // ebx
  int v7; // edi
  unsigned int v8; // ebx
  int v9; // edi
  unsigned int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]
  int v12; // [esp+10h] [ebp-4h]

  if ( *(_DWORD *)(this + 92) )
  {
    v2 = 0;
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
  if ( *(_DWORD *)(this + 48) )
  {
    v10 = 0;
    while ( v10 < 0x10 )
    {
      v6 = *(_DWORD *)(this + 12);
      v7 = 0;
      v11 = 1;
      if ( v6 )
      {
        do
        {
          *(_DWORD *)(this + 256) = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v7);
          result = sub_6BCB13(this);
          if ( result < 0 )
            return result;
          if ( !result )
            v11 = 0;
          result = sub_681C03((void *)this, *(_DWORD **)(this + 256));
          if ( result < 0 )
            return result;
          **(_DWORD **)(this + 256) = 0;
        }
        while ( ++v7 < v6 );
      }
      result = sub_6825A9((_DWORD *)this);
      if ( result < 0 )
        return result;
      ++v10;
      if ( v11 )
      {
        if ( v10 < 0x10 )
          goto LABEL_30;
        break;
      }
    }
    v8 = *(_DWORD *)(this + 12);
    v9 = 0;
    v12 = 1;
    if ( v8 )
    {
      do
      {
        *(_DWORD *)(this + 256) = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v9);
        result = sub_6BCB13(this);
        if ( result < 0 )
          return result;
        if ( !result )
        {
          sub_686791(this, *(_DWORD *)(*(_DWORD *)(this + 256) + 60), 4553, "relative address refrences too deep");
          v12 = 0;
        }
        result = sub_681C03((void *)this, *(_DWORD **)(this + 256));
        if ( result < 0 )
          return result;
        **(_DWORD **)(this + 256) = 0;
      }
      while ( ++v9 < v8 );
    }
    result = sub_6825A9((_DWORD *)this);
    if ( result < 0 )
      return result;
    if ( !v12 )
      return -2147467259;
  }
LABEL_30:
  if ( (*(_BYTE *)(this + 112) & 0x40) != 0
    || (result = (*(int (__thiscall **)(int))(*(_DWORD *)this + 152))(this), result >= 0) )
  {
    if ( !*(_DWORD *)(this + 96) )
      return 0;
    result = sub_6C9033(this);
    if ( result >= 0 )
    {
      sub_6BC1A9(this);
      result = sub_688BDF((_DWORD *)this);
      if ( result >= 0 )
      {
        result = sub_6C466D(this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}
