void __thiscall sub_4FB5D0(int this)
{
  int v1; // ebx
  double v2; // st7
  int v3; // edi
  int v4; // ebp
  int v5; // esi
  float *v6; // edx
  int v7; // esi
  float *v8; // edx
  _DWORD *v9; // eax
  int v10; // edx
  _DWORD *v11; // eax
  int v12; // ecx

  v1 = *(_DWORD *)(this + 272);
  if ( v1 )
  {
    v2 = *(float *)(this + 60);
    v3 = 7;
    v4 = 7;
    if ( v2 >= 500.0 )
    {
LABEL_14:
      if ( v3 >= 0 )
      {
        v9 = (_DWORD *)(this + 4 * v3 + 204);
        v10 = v3 + 1;
        do
        {
          *v9-- = 1140457472;
          --v10;
        }
        while ( v10 );
      }
      if ( v4 >= 0 )
      {
        v11 = (_DWORD *)(this + 4 * v4 + 236);
        v12 = v4 + 1;
        do
        {
          *v11-- = 1140457472;
          --v12;
        }
        while ( v12 );
      }
    }
    else
    {
      while ( 1 )
      {
        v5 = v3;
        if ( v3 >= 0 )
        {
          v6 = (float *)(this + 4 * v3 + 204);
          do
          {
            if ( (double)(v5 + 1) < *(float *)(v1 + 80) )
              break;
            *v6 = v2;
            --v3;
            --v6;
            --v5;
          }
          while ( v5 >= 0 );
        }
        v7 = v4;
        if ( v4 >= 0 )
        {
          v8 = (float *)(this + 4 * v4 + 236);
          do
          {
            if ( (double)(v7 + 1) < *(float *)(v1 + 84) )
              break;
            *v8 = v2;
            --v4;
            --v8;
            --v7;
          }
          while ( v7 >= 0 );
        }
        v2 = v2 + *(float *)(v1 + 60);
        v1 = *(_DWORD *)(v1 + 272);
        if ( !v1 || v1 == *(_DWORD *)(v1 + 272) )
          break;
        if ( v2 >= 500.0 )
          goto LABEL_14;
      }
    }
  }
}
