char __thiscall sub_4B8360(int this)
{
  float **v2; // eax
  float *v3; // ecx
  LPVOID **v4; // esi
  LPVOID *v5; // eax
  LPVOID *v6; // eax
  LPVOID *v7; // ebp
  int v8; // eax
  float **v9; // eax

  v2 = *(float ***)(this + 1728);
  *(_DWORD *)(this + 1736) = v2;
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      while ( 1 )
      {
        if ( fabs(*v3 - *(float *)(this + 3896)) > 2.0 )
        {
          if ( *v3 > (double)*(float *)(this + 3896) )
            return 1;
        }
        else
        {
          v4 = *(LPVOID ***)(this + 1728);
          if ( v4 )
          {
            while ( *v4 != (LPVOID *)v3 )
            {
              v4 = (LPVOID **)v4[1];
              if ( !v4 )
                goto LABEL_24;
            }
            if ( v4 == *(LPVOID ***)(this + 1736) )
              *(_DWORD *)(this + 1736) = v4[1];
            v5 = v4[2];
            if ( v5 )
              v5[1] = v4[1];
            else
              *(_DWORD *)(this + 1728) = v4[1];
            v6 = v4[1];
            if ( v6 )
              v6[2] = v4[2];
            if ( *(LPVOID ***)(this + 1732) == v4 )
              *(_DWORD *)(this + 1732) = v4[2];
            --*(_DWORD *)(this + 1740);
            if ( *((_BYTE *)v4 + 12) )
            {
              v7 = *v4;
              if ( *v4 )
              {
                if ( v7[1] )
                  FreeWrapper_7bcf(v7[1]);
                FreeWrapper_7bcf(v7);
              }
            }
            FreeWrapper_7bcf(v4);
            *(_BYTE *)(this + 1744) = 1;
            goto LABEL_26;
          }
        }
LABEL_24:
        v8 = *(_DWORD *)(this + 1736);
        if ( v8 )
          *(_DWORD *)(this + 1736) = *(_DWORD *)(v8 + 4);
LABEL_26:
        v9 = *(float ***)(this + 1736);
        if ( v9 )
        {
          v3 = *v9;
          if ( *v9 )
            continue;
        }
        return 1;
      }
    }
  }
  return 1;
}

