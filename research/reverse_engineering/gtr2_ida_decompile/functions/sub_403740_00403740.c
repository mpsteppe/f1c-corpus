void __thiscall sub_403740(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edi
  int v5; // ecx
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  float v10; // [esp+8h] [ebp-4h]

  v10 = 1.0 - (flt_FB1F28 + flt_FB1F24) * 0.5;
  if ( fabs(*(float *)(this + 384) - v10) > 0.050000001 || *(_DWORD *)(this + 388) != -1 )
  {
    if ( *(_DWORD *)(this + 388) == -1 )
    {
      *(_DWORD *)(this + 388) = 0;
      *(float *)(this + 384) = v10;
      *(_DWORD *)(this + 380) = 0;
    }
    v2 = *(_DWORD *)(this + 388);
    v3 = *(_DWORD *)(this + 312);
    v4 = v2 + 20;
    if ( v2 + 20 > v3 )
      v4 = v3;
    v5 = *(_DWORD *)(this + 380);
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          if ( v2 < v4 )
          {
            do
            {
              sub_5921A0(*(_DWORD *)(this + 316) + 320 * *(_DWORD *)(this + 388));
              v7 = *(_DWORD *)(this + 388) + 1;
              *(_DWORD *)(this + 388) = v7;
            }
            while ( v7 < v4 );
          }
          if ( v4 == *(_DWORD *)(this + 312) )
          {
            *(_DWORD *)(this + 380) = 0;
            *(_DWORD *)(this + 388) = -1;
          }
        }
      }
      else
      {
        if ( v2 < v4 )
        {
          do
          {
            sub_591DE0(*(_DWORD *)(this + 316) + 320 * *(_DWORD *)(this + 388));
            v8 = *(_DWORD *)(this + 388) + 1;
            *(_DWORD *)(this + 388) = v8;
          }
          while ( v8 < v4 );
        }
        if ( v4 == *(_DWORD *)(this + 312) )
        {
          *(_DWORD *)(this + 388) = 0;
          *(_DWORD *)(this + 380) = 2;
        }
      }
    }
    else
    {
      if ( v2 < v4 )
      {
        do
        {
          sub_592100(v10);
          v9 = *(_DWORD *)(this + 388) + 1;
          *(_DWORD *)(this + 388) = v9;
        }
        while ( v9 < v4 );
      }
      if ( v4 == *(_DWORD *)(this + 312) )
      {
        *(_DWORD *)(this + 380) = 1;
        *(_DWORD *)(this + 388) = 0;
      }
    }
  }
}
