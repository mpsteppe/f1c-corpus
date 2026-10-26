void __thiscall sub_404B10(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  float v9; // [esp+10h] [ebp-4h]

  v9 = 1.0 - (flt_7DAB04 + flt_7DAB08) * 0.5;
  if ( fabs(*(float *)(this + 440) - v9) > 0.05000000074505806 || *(_DWORD *)(this + 444) != -1 )
  {
    if ( *(_DWORD *)(this + 444) == -1 )
    {
      *(_DWORD *)(this + 444) = 0;
      *(float *)(this + 440) = v9;
      *(_DWORD *)(this + 436) = 0;
    }
    v2 = *(_DWORD *)(this + 444);
    v3 = v2 + 20;
    if ( v2 + 20 > *(_DWORD *)(this + 356) )
      v3 = *(_DWORD *)(this + 356);
    v4 = *(_DWORD *)(this + 436);
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          if ( v2 < v3 )
          {
            do
            {
              sub_529080(*(_DWORD *)(this + 360) + 348 * *(_DWORD *)(this + 444));
              v6 = *(_DWORD *)(this + 444) + 1;
              *(_DWORD *)(this + 444) = v6;
            }
            while ( v6 < v3 );
          }
          if ( v3 == *(_DWORD *)(this + 356) )
          {
            *(_DWORD *)(this + 436) = 0;
            *(_DWORD *)(this + 444) = -1;
          }
        }
      }
      else
      {
        if ( v2 < v3 )
        {
          do
          {
            sub_528C20(*(_DWORD *)(this + 360) + 348 * *(_DWORD *)(this + 444));
            v7 = *(_DWORD *)(this + 444) + 1;
            *(_DWORD *)(this + 444) = v7;
          }
          while ( v7 < v3 );
        }
        if ( v3 == *(_DWORD *)(this + 356) )
        {
          *(_DWORD *)(this + 444) = 0;
          *(_DWORD *)(this + 436) = 2;
        }
      }
    }
    else
    {
      if ( v2 < v3 )
      {
        do
        {
          sub_528FF0(v9);
          v8 = *(_DWORD *)(this + 444) + 1;
          *(_DWORD *)(this + 444) = v8;
        }
        while ( v8 < v3 );
      }
      if ( v3 == *(_DWORD *)(this + 356) )
      {
        *(_DWORD *)(this + 436) = 1;
        *(_DWORD *)(this + 444) = 0;
      }
    }
  }
}
