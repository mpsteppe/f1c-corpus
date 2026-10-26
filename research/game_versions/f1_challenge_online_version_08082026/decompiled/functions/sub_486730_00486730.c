char __thiscall sub_486730(int this)
{
  int v2; // eax
  int v3; // ebp
  char v4; // bl
  char result; // al
  double v6; // st7
  int v7; // eax
  int v8; // eax
  char *v9; // eax
  char *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // et2
  int v15; // edx
  int v16; // ebp
  int v17; // eax

  v2 = sub_486460((_DWORD *)this, *(_DWORD *)(this + 132));
  v3 = v2;
  v4 = 0;
  if ( !v2 )
    return 0;
  if ( !*(_DWORD *)(v2 + 40) )
  {
    *(_DWORD *)(this + 136) = 0;
    return 0;
  }
  v6 = sub_498730(*(_DWORD *)(this + 64)) + *(float *)(this + 128);
  *(float *)(this + 128) = v6;
  if ( v6 > *(float *)(v3 + 24) )
  {
    v7 = *(_DWORD *)(this + 220);
    if ( v7 )
    {
      v8 = v7 - 1;
      *(_DWORD *)(this + 220) = v8;
      if ( v8 <= 0 )
      {
        v9 = sub_486280((_DWORD *)this);
        if ( v9 )
        {
          if ( strlen(v9) )
          {
            v10 = sub_486280((_DWORD *)this);
            v11 = sub_497E80(v10);
            if ( v11 )
              sub_498030(v11);
          }
        }
      }
    }
    *(_DWORD *)(this + 128) = 0;
    v12 = *(_DWORD *)(v3 + 28);
    if ( v12 )
    {
      if ( v12 == 1 )
      {
        v13 = *(_DWORD *)(this + 136) + 1;
        *(_DWORD *)(this + 136) = v13;
        v14 = v13 % *(_DWORD *)(v3 + 16);
        result = 1;
        *(_DWORD *)(this + 136) = v14;
        return result;
      }
    }
    else
    {
      v15 = *(_DWORD *)(this + 136) + 1;
      *(_DWORD *)(this + 136) = v15;
      v16 = *(_DWORD *)(v3 + 16);
      v17 = v15;
      if ( v15 >= v16 )
        v17 = v16;
      *(_DWORD *)(this + 136) = v17;
    }
    return 1;
  }
  return v4;
}
