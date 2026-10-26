void __thiscall sub_404460(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  float v9; // [esp+10h] [ebp-4h]

  v9 = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5;
  if ( fabs(*(float *)(this + 368) - v9) > 0.05000000074505806 || *(_DWORD *)(this + 372) != -1 )
  {
    if ( *(_DWORD *)(this + 372) == -1 )
    {
      *(_DWORD *)(this + 372) = 0;
      *(float *)(this + 368) = v9;
      *(_DWORD *)(this + 364) = 0;
    }
    v2 = *(_DWORD *)(this + 372);
    v3 = v2 + 20;
    if ( v2 + 20 > *(_DWORD *)(this + 304) )
      v3 = *(_DWORD *)(this + 304);
    v4 = *(_DWORD *)(this + 364);
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
              sub_4FB2E0(*(_DWORD *)(this + 308) + 316 * *(_DWORD *)(this + 372));
              v6 = *(_DWORD *)(this + 372) + 1;
              *(_DWORD *)(this + 372) = v6;
            }
            while ( v6 < v3 );
          }
          if ( v3 == *(_DWORD *)(this + 304) )
          {
            *(_DWORD *)(this + 364) = 0;
            *(_DWORD *)(this + 372) = -1;
          }
        }
      }
      else
      {
        if ( v2 < v3 )
        {
          do
          {
            sub_4FAF60(*(_DWORD *)(this + 308) + 316 * *(_DWORD *)(this + 372));
            v7 = *(_DWORD *)(this + 372) + 1;
            *(_DWORD *)(this + 372) = v7;
          }
          while ( v7 < v3 );
        }
        if ( v3 == *(_DWORD *)(this + 304) )
        {
          *(_DWORD *)(this + 372) = 0;
          *(_DWORD *)(this + 364) = 2;
        }
      }
    }
    else
    {
      if ( v2 < v3 )
      {
        do
        {
          sub_4FB260(v9);
          v8 = *(_DWORD *)(this + 372) + 1;
          *(_DWORD *)(this + 372) = v8;
        }
        while ( v8 < v3 );
      }
      if ( v3 == *(_DWORD *)(this + 304) )
      {
        *(_DWORD *)(this + 364) = 1;
        *(_DWORD *)(this + 372) = 0;
      }
    }
  }
}
