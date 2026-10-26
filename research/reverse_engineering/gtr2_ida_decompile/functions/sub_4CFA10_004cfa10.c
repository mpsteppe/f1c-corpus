char __thiscall sub_4CFA10(int this)
{
  char v2; // bl
  int v3; // edi
  char result; // al
  double v5; // st7
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  const CHAR *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // et2
  int v14; // ebx
  int v15; // eax

  v2 = 0;
  if ( *(_DWORD *)(this + 244) )
    v3 = sub_4E29F0(*(_DWORD *)(this + 132));
  else
    v3 = 0;
  if ( !v3 )
    return 0;
  if ( !*(_DWORD *)(v3 + 36) )
  {
    *(_DWORD *)(this + 136) = 0;
    return 0;
  }
  v5 = sub_4DE460(*(_DWORD *)(this + 48)) + *(float *)(this + 128);
  *(float *)(this + 128) = v5;
  if ( v5 > *(float *)(v3 + 20) )
  {
    v6 = *(_DWORD *)(this + 264);
    if ( v6 )
    {
      v7 = v6 - 1;
      *(_DWORD *)(this + 264) = v7;
      if ( v7 <= 0 )
      {
        v8 = sub_4CF880((_DWORD *)this);
        if ( v8 )
        {
          if ( strlen(v8) )
          {
            v9 = sub_4CF880((_DWORD *)this);
            v10 = sub_4DE300(*(_DWORD *)(this + 48), v9);
            if ( v10 )
            {
              if ( byte_B708D0 == 1 )
                sub_4E05F0(v10);
            }
          }
        }
      }
    }
    *(_DWORD *)(this + 128) = 0;
    v11 = *(_DWORD *)(v3 + 24);
    if ( v11 )
    {
      if ( v11 == 1 )
      {
        v12 = *(_DWORD *)(this + 136) + 1;
        *(_DWORD *)(this + 136) = v12;
        v13 = v12 % *(_DWORD *)(v3 + 16);
        result = 1;
        *(_DWORD *)(this + 136) = v13;
        return result;
      }
    }
    else
    {
      v14 = *(_DWORD *)(this + 136) + 1;
      *(_DWORD *)(this + 136) = v14;
      v15 = v14;
      if ( v14 >= *(_DWORD *)(v3 + 16) )
        v15 = *(_DWORD *)(v3 + 16);
      *(_DWORD *)(this + 136) = v15;
    }
    return 1;
  }
  return v2;
}
