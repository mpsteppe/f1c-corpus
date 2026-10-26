int __thiscall sub_45EBD0(_DWORD *this)
{
  int result; // eax
  LPVOID *v3; // ebx
  bool v4; // zf
  LPVOID **v5; // esi
  LPVOID *v6; // edi
  int v7; // [esp+4h] [ebp-4h]

  result = this[28127];
  if ( result > 64 )
  {
    result -= 64;
    if ( result > 0 )
    {
      v7 = result;
      do
      {
        result = this[28124];
        if ( result )
        {
          v3 = *(LPVOID **)result;
          v4 = *(_DWORD *)result == 0;
          *(_BYTE *)(result + 8) = 0;
          if ( !v4 )
          {
            v5 = (LPVOID **)this[28124];
            result = 0;
            if ( v5 )
            {
              while ( *v5 != v3 )
              {
                result = (int)v5;
                v5 = (LPVOID **)v5[1];
                if ( !v5 )
                  goto LABEL_25;
              }
              if ( v5 == (LPVOID **)this[28126] )
                this[28126] = v5[1];
              if ( result )
                *(_DWORD *)(result + 4) = v5[1];
              else
                this[28124] = v5[1];
              if ( (LPVOID **)this[28125] == v5 )
                this[28125] = result;
              --this[28127];
              if ( *((_BYTE *)v5 + 8) )
              {
                v6 = *v5;
                if ( *v5 )
                {
                  if ( *v6 )
                    FreeWrapper_7bcf(*v6);
                  FreeWrapper_7bcf(v6);
                }
              }
              FreeWrapper_7bcf(v5);
              if ( *v3 )
                FreeWrapper_7bcf(*v3);
              result = FreeWrapper_7bcf(v3);
            }
          }
        }
LABEL_25:
        --v7;
      }
      while ( v7 );
    }
  }
  return result;
}
