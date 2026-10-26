int __thiscall sub_69468D(int this)
{
  int result; // eax
  unsigned int i; // ecx
  int *v4; // eax
  BOOL v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  unsigned int k; // edx
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // ecx
  unsigned int j; // [esp+8h] [ebp-4h]

  result = sub_686DF9((_DWORD *)this);
  if ( result >= 0 )
  {
    result = sub_6875A0((_DWORD *)this);
    if ( result >= 0 )
    {
      result = sub_68FECA((_DWORD *)this);
      if ( result >= 0 )
      {
        result = sub_6825A9((_DWORD *)this);
        if ( result >= 0 )
        {
          result = sub_688BDF((_DWORD *)this);
          if ( result >= 0 )
          {
            for ( i = 0; i < *(_DWORD *)(this + 12); ++i )
            {
              v4 = *(int **)(*(_DWORD *)(this + 24) + 4 * i);
              if ( (*v4 & 0xFFF00000) == 0x10200000 )
                *v4 = v4[3] & 0xFFFFF | 0x10000000;
            }
            if ( (*(_BYTE *)(this + 204) & 4) != 0 )
            {
              *(_DWORD *)(this + 216) = 1;
              return 0;
            }
            else
            {
              result = sub_68AD21((_DWORD *)this);
              if ( result >= 0 )
              {
                result = sub_6872BA((_DWORD *)this);
                if ( result >= 0 )
                {
                  for ( j = 0; j < 0x100; ++j )
                  {
                    result = sub_68F321((_DWORD *)this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v5 = result == 0;
                    result = sub_6875A0((_DWORD *)this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v6 = result == 0 || v5;
                    result = sub_690096((_DWORD *)this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v7 = (result == 0) | v6;
                    result = sub_69056E((_DWORD *)this, 0);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v8 = (result == 0) | v7;
                    result = sub_687A52((_DWORD *)this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v9 = (result == 0) | v8;
                    result = sub_6907F5(this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v10 = (result == 0) | v9;
                    result = sub_687F01(this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v11 = (result == 0) | v10;
                    result = sub_688205((_DWORD *)this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    v12 = (result == 0) | v11;
                    result = sub_692044((_DWORD *)this);
                    if ( result )
                    {
                      if ( result < 0 )
                        return result;
                    }
                    else
                    {
                      result = 0;
                    }
                    if ( !(v12 | (result == 0)) )
                      break;
                  }
                  if ( j == 256 )
                    sub_686816(this, 0, 0, "internal warning: optimization did not converge");
                  for ( k = 0; k < *(_DWORD *)(this + 8); ++k )
                  {
                    v14 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * k);
                    v15 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v14[1]) + 4);
                    if ( (v15 & 0x100) != 0 && (v15 & 0xC00) == 0 )
                    {
                      v16 = *(_DWORD *)(this + 120);
                      v14[3] = -1;
                      v14[4] = -1;
                      v14[1] = v16;
                    }
                  }
                  result = sub_68EDC5(this);
                  if ( result >= 0 )
                  {
                    result = sub_688927(this);
                    if ( result >= 0 )
                    {
                      result = sub_68FECA((_DWORD *)this);
                      if ( result >= 0 )
                      {
                        result = sub_6825A9((_DWORD *)this);
                        if ( result >= 0 )
                        {
                          result = sub_688BDF((_DWORD *)this);
                          if ( result >= 0 )
                          {
                            *(_DWORD *)(this + 216) = 1;
                            return 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
