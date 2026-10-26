int __thiscall sub_6942F3(int this)
{
  int result; // eax
  unsigned int v3; // eax
  int v4; // edi
  bool v5; // zf
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // edx
  int v10; // ecx
  int v11; // edi
  _DWORD *v12; // edx
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // ecx
  _DWORD *v16; // ecx
  void *v17[25]; // [esp+8h] [ebp-7Ch] BYREF
  int v18; // [esp+6Ch] [ebp-18h]
  int v19; // [esp+70h] [ebp-14h]
  int v20; // [esp+74h] [ebp-10h]
  int v21; // [esp+78h] [ebp-Ch]
  unsigned int v22; // [esp+7Ch] [ebp-8h]
  unsigned int v23; // [esp+80h] [ebp-4h]

  result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 136), 3, 132096);
  if ( result >= 0 )
  {
    result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 140), 6, 1025);
    if ( result >= 0 )
    {
      result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 144), 10, 17409);
      if ( result >= 0 )
      {
        if ( (v3 = *(_DWORD *)(this + 200) & 0xFFFF0000, v3 != 1180172288) && v3 != 1415053312
          || (result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 136), 2, 200744), result >= 0) )
        {
          if ( (*(_DWORD *)(this + 200) & 0xFFFF0000) == 0xFFFE0000
            || (result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 128), 16, 512), result >= 0) )
          {
            result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 132), 32, 270336);
            if ( result >= 0 )
            {
              result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 180), 8224, 0x40000);
              if ( result >= 0 )
              {
                result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 184), 262176, 0x2000);
                if ( result >= 0 )
                {
                  if ( (*(_DWORD *)(this + 200) & 0xFFFF0000) == 0xFFFF0000
                    || (result = sub_685670((_DWORD *)this, *(_DWORD *)(this + 148), 128, 0), result >= 0) )
                  {
                    if ( !*(_DWORD *)(this + 48) )
                      goto LABEL_22;
                    result = sub_68E047((char *)this, v17, *(_DWORD *)(this + 140), *(_DWORD *)(this + 48));
                    if ( result < 0 )
                      return result;
                    if ( sub_68E712(this, (int)v17, 0) >= 0 )
                    {
                      sub_68E712(this, (int)v17, 1);
                    }
                    else
                    {
                      v4 = sub_685670((_DWORD *)this, *(_DWORD *)(this + 136), 2, 196648);
                      if ( v4 < 0 )
                      {
LABEL_18:
                        sub_685D67(v17);
                        return v4;
                      }
                    }
                    result = sub_685D67(v17);
                    if ( result >= 0 )
                    {
LABEL_22:
                      v4 = sub_68E047((char *)this, v17, *(_DWORD *)(this + 136), *(_DWORD *)(this + 44));
                      if ( v4 < 0 )
                        goto LABEL_18;
                      v4 = sub_68E712(this, (int)v17, 1);
                      if ( v4 < 0 )
                        goto LABEL_18;
                      v4 = sub_685D67(v17);
                      if ( v4 < 0 )
                        goto LABEL_18;
                      v4 = sub_68E047((char *)this, v17, *(_DWORD *)(this + 144), *(_DWORD *)(this + 52));
                      if ( v4 < 0 )
                        goto LABEL_18;
                      v4 = sub_68E712(this, (int)v17, 1);
                      if ( v4 < 0 )
                        goto LABEL_18;
                      v4 = sub_685D67(v17);
                      if ( v4 < 0 )
                        goto LABEL_18;
                      if ( (*(_BYTE *)(this + 204) & 4) != 0 )
                        return 0;
                      v20 = 0;
                      sub_686606((_DWORD *)this);
                      v5 = *(_DWORD *)(this + 12) == 0;
                      v22 = 0;
                      if ( v5 )
                        return 0;
                      do
                      {
                        v6 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v22);
                        if ( (*v6 & 0xFFF00000) == 0x10000000 )
                        {
                          v7 = 0;
                          v5 = v6[3] == 0;
                          v21 = 0;
                          v23 = 0;
                          if ( !v5 )
                          {
                            do
                            {
                              v8 = v6[2];
                              v9 = *(_DWORD *)(v6[4] + 4 * v23);
                              v10 = *(_DWORD *)(this + 20);
                              v18 = 4 * v23;
                              v11 = *(_DWORD *)(4 * v23 + v8);
                              v19 = v9;
                              v12 = *(_DWORD **)(v10 + 4 * v9);
                              v13 = *(_DWORD **)(v10 + 4 * v11);
                              if ( v12[1] == v13[1]
                                && v12[2] == v13[2]
                                && v12[3] == v13[3]
                                && v12[4] == v13[4]
                                && v12[5] == v13[5]
                                && v12[6] == v13[6]
                                && !v12[15]
                                && !v13[15] )
                              {
                                v14 = -1;
                                if ( v11 != -1 )
                                  v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v11) + 48);
                                v12[12] = v14;
                                v7 = v21;
                              }
                              else
                              {
                                v15 = v21;
                                *(_DWORD *)(v6[4] + 4 * v21) = v19;
                                *(_DWORD *)(v6[2] + 4 * v15) = *(_DWORD *)(v6[2] + v18);
                                v7 = v15 + 1;
                                v21 = v7;
                              }
                              ++v23;
                            }
                            while ( v23 < v6[3] );
                          }
                          if ( v7 != v6[3] )
                          {
                            *v6 = v7 != 0 ? v7 & 0xFFFFF | 0x10000000 : 0;
                            v6[1] = v7;
                            v6[3] = v7;
                            v20 = 1;
                          }
                        }
                        ++v22;
                      }
                      while ( v22 < *(_DWORD *)(this + 12) );
                      if ( !v20 )
                        return 0;
                      result = sub_68661F((_DWORD *)this);
                      if ( result >= 0 )
                      {
                        result = sub_688BDF(v16);
                        if ( result >= 0 )
                        {
                          result = sub_6825A9((_DWORD *)this);
                          if ( result >= 0 )
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
  return result;
}
