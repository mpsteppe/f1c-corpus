void __thiscall sub_4BF030(int this, float a2)
{
  int v3; // eax
  _DWORD **v4; // eax
  _DWORD *v5; // ecx
  int v6; // ecx
  int v7; // eax
  _DWORD **v8; // eax
  double v9; // st7
  _DWORD **v10; // eax
  double v11; // st7
  _DWORD *v12; // ecx
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  _DWORD **v16; // eax
  float v17; // [esp+10h] [ebp+4h]

  if ( (*(_BYTE *)this & 1) != 0 )
  {
    v3 = *(_DWORD *)(this + 180);
    if ( v3 > 0 )
    {
      *(_DWORD *)(this + 180) = v3 - 1;
      v4 = *(_DWORD ***)(this + 184);
      *(_DWORD *)(this + 192) = v4;
      if ( v4 )
      {
        v5 = *v4;
        if ( *v4 )
        {
          do
          {
            if ( sub_4BD140(v5, *(_DWORD *)(this + 200)) )
            {
              *(_DWORD *)(v6 + 68) = -1082130432;
              sub_4BD160(v6, *(_DWORD *)(this + 200), 0.0);
            }
            v7 = *(_DWORD *)(this + 192);
            if ( !v7 )
              break;
            v8 = *(_DWORD ***)(v7 + 4);
            *(_DWORD *)(this + 192) = v8;
            if ( !v8 )
              break;
            v5 = *v8;
          }
          while ( *v8 );
        }
      }
    }
  }
  if ( (*(_BYTE *)this & 2) != 0 )
  {
    v9 = sub_4BE6A0((float *)this, *(_DWORD *)(this + 200));
    v10 = *(_DWORD ***)(this + 184);
    v11 = v9 * (a2 - *(float *)(this + 4)) + *(float *)(this + 4) - *(float *)(this + 4);
    *(_DWORD *)(this + 192) = v10;
    if ( v10 )
    {
      v12 = *v10;
      if ( *v10 )
      {
        do
        {
          v13 = *(_DWORD *)(this + 200);
          if ( sub_4BD140(v12, v13) )
          {
            v17 = v11;
            sub_4BD160(v14, v13, v17);
          }
          v15 = *(_DWORD *)(this + 192);
          if ( !v15 )
            break;
          v16 = *(_DWORD ***)(v15 + 4);
          *(_DWORD *)(this + 192) = v16;
          if ( !v16 )
            break;
          v12 = *v16;
        }
        while ( *v16 );
      }
    }
  }
}
