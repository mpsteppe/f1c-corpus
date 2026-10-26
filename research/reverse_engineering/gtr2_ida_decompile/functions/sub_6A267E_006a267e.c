int __thiscall sub_6A267E(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // edx
  _DWORD *v6; // eax
  unsigned int v7; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // eax
  int *v11; // edi
  _DWORD *v12; // esi
  int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // edx
  _DWORD *v16; // ecx
  unsigned int v17; // eax
  _DWORD *v18; // ecx
  _DWORD *v19; // edx
  _DWORD *v20; // eax
  int v21; // esi
  int v23; // [esp+Ch] [ebp-2Ch]
  int v24; // [esp+10h] [ebp-28h]
  _DWORD *v26; // [esp+18h] [ebp-20h]
  int v27; // [esp+1Ch] [ebp-1Ch]
  int v28; // [esp+1Ch] [ebp-1Ch]
  int v29; // [esp+20h] [ebp-18h]
  int v30; // [esp+24h] [ebp-14h]
  unsigned int v31; // [esp+28h] [ebp-10h]
  unsigned int v32; // [esp+2Ch] [ebp-Ch]
  _DWORD *v33; // [esp+30h] [ebp-8h]
  _DWORD *j; // [esp+30h] [ebp-8h]
  unsigned int v35; // [esp+34h] [ebp-4h]
  unsigned int i; // [esp+34h] [ebp-4h]
  unsigned int v37; // [esp+34h] [ebp-4h]
  int v38; // [esp+34h] [ebp-4h]

  v1 = this;
  v2 = (_DWORD *)this[64];
  v26 = v2;
  if ( (*v2 & 0xFFFFF) == 4 && v2[1] == 4 )
  {
    v3 = (_DWORD *)v2[2];
    v4 = v3[3];
    v35 = 0;
    v23 = v4;
    v33 = *(_DWORD **)(v1[64] + 8);
    while ( *v33 != *(_DWORD *)(*(_DWORD *)(v1[64] + 8) + 12) )
    {
      ++v35;
      ++v33;
      if ( v35 >= 3 )
      {
        v5 = *(_DWORD *)(*(_DWORD *)(v1[5] + 4 * v4) + 72);
        v27 = -1;
        v24 = v5;
        if ( v5 != -1 )
        {
          v6 = *(_DWORD **)(v1[6] + 4 * v5);
          if ( (*v6 & 0xFFF00000) == 0x10000000 )
          {
            for ( i = 0; i < v6[3]; ++i )
            {
              if ( v4 == *(_DWORD *)(v6[4] + 4 * i) )
                v27 = *(_DWORD *)(4 * i + v6[2]);
            }
          }
        }
        v7 = 0;
        v8 = v3;
        while ( *v8 != v27 )
        {
          ++v7;
          ++v8;
          if ( v7 >= 3 )
          {
            v28 = 0;
            for ( j = v3; ; ++j )
            {
              v9 = *(_DWORD *)(*(_DWORD *)(v1[5] + 4 * *j) + 72);
              if ( v9 != -1 )
              {
                v10 = v1[6];
                v11 = *(int **)(v10 + 4 * v24);
                v12 = *(_DWORD **)(v10 + 4 * v9);
                v13 = *v11;
                if ( ((*v12 ^ *v11) & 0xFFF00000) == 0 )
                {
                  v14 = *v12 & 0xFFFFF;
                  v32 = v13 & 0xFFFFF;
                  v31 = v14;
                  if ( (v13 & 0xFFFFF) != 0 )
                  {
                    if ( v14 )
                    {
                      v29 = v11[1] / v32;
                      if ( v29 == v12[1] / v14 && v32 == v11[3] )
                      {
                        v15 = v12[3];
                        if ( v14 == v15 )
                        {
                          v30 = -1;
                          v37 = 0;
                          if ( v15 )
                          {
                            v16 = (_DWORD *)v12[4];
                            while ( *v16 != *j )
                            {
                              ++v37;
                              ++v16;
                              if ( v37 >= v15 )
                                goto LABEL_30;
                            }
                            v30 = v37;
                          }
LABEL_30:
                          v17 = 0;
                          if ( v15 )
                          {
                            v18 = (_DWORD *)v11[4];
                            while ( *v18 != v23 )
                            {
                              ++v17;
                              ++v18;
                              if ( v17 >= v12[3] )
                                goto LABEL_43;
                            }
                            if ( v17 != -1 && v30 != -1 )
                            {
                              v38 = 1;
                              if ( !v29 )
                                break;
                              v19 = (_DWORD *)(v11[2] + 4 * v17);
                              v20 = (_DWORD *)(v12[2] + 4 * v30);
                              v21 = v11[1] / v32;
                              do
                              {
                                if ( *v19 != *v20 )
                                  v38 = 0;
                                v20 += v31;
                                v19 += v32;
                                --v21;
                              }
                              while ( v21 );
                              v1 = this;
                              if ( v38 )
                                break;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
LABEL_43:
              if ( (unsigned int)++v28 >= 3 )
              {
                sub_686791((int)v1, v26[15], 4544, "Clip must be from a 3 vector in ps_1_%i", (unsigned __int8)v1[50]);
                return -2147467259;
              }
            }
            *(_DWORD *)v1[64] = 285212675;
            *(_DWORD *)(v1[64] + 4) = 3;
            *(_DWORD *)(v1[64] + 12) = 3;
            return 0;
          }
        }
        break;
      }
    }
    *v26 = 285212675;
    return 0;
  }
  else
  {
    sub_686791((int)this, v2[15], 4820, "internal error: malformed clip found");
    return -2147467259;
  }
}
