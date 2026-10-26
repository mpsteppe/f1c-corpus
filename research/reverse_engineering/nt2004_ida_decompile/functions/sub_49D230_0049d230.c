char __thiscall sub_49D230(int this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ebp
  char v5; // bl
  char result; // al
  double v7; // st7
  int v8; // eax
  int v9; // eax
  CHAR *v10; // eax
  char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // et2
  int v16; // edx
  int v17; // ebp
  int v18; // eax

  v2 = sub_49CB60((_DWORD *)this, *(_DWORD *)(this + 132));
  v4 = v2;
  v5 = 0;
  if ( !v2 )
    return 0;
  if ( !*(_DWORD *)(v2 + 36) )
  {
    *(_DWORD *)(this + 136) = 0;
    return 0;
  }
  v7 = sub_4AE720(*(_DWORD *)(this + 48), v3) + *(float *)(this + 128);
  *(float *)(this + 128) = v7;
  if ( v7 > *(float *)(v4 + 20) )
  {
    v8 = *(_DWORD *)(this + 264);
    if ( v8 )
    {
      v9 = v8 - 1;
      *(_DWORD *)(this + 264) = v9;
      if ( v9 <= 0 )
      {
        v10 = sub_49C980((_DWORD *)this);
        if ( v10 )
        {
          if ( strlen(v10) )
          {
            v11 = sub_49C980((_DWORD *)this);
            v12 = sub_4ADDB0(v11);
            if ( v12 )
              sub_4ADF10(v12);
          }
        }
      }
    }
    *(_DWORD *)(this + 128) = 0;
    v13 = *(_DWORD *)(v4 + 24);
    if ( v13 )
    {
      if ( v13 == 1 )
      {
        v14 = *(_DWORD *)(this + 136) + 1;
        *(_DWORD *)(this + 136) = v14;
        v15 = v14 % *(_DWORD *)(v4 + 16);
        result = 1;
        *(_DWORD *)(this + 136) = v15;
        return result;
      }
    }
    else
    {
      v16 = *(_DWORD *)(this + 136) + 1;
      *(_DWORD *)(this + 136) = v16;
      v17 = *(_DWORD *)(v4 + 16);
      v18 = v16;
      if ( v16 >= v17 )
        v18 = v17;
      *(_DWORD *)(this + 136) = v18;
    }
    return 1;
  }
  return v5;
}
