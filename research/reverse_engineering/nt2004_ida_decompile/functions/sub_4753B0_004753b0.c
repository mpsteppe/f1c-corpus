int __thiscall sub_4753B0(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  void *v4; // ebx
  int v5; // ebp
  _DWORD *v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  const char *v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // esi
  char *v15; // eax
  int v16; // edx
  int v17; // eax
  _DWORD *v18; // edx
  _DWORD *v19; // eax
  int v20; // eax
  _DWORD *v21; // edx
  int v22; // esi
  int v23; // ebx
  int v24; // eax
  _DWORD *v25; // edx
  _DWORD *i; // ecx
  _DWORD *v27; // ecx
  _DWORD *v29; // [esp-4h] [ebp-120h]
  int v31; // [esp+14h] [ebp-108h]
  int v32; // [esp+18h] [ebp-104h]
  char String2[256]; // [esp+1Ch] [ebp-100h] BYREF

  v1 = this;
  sub_472670(this);
  v2 = (_DWORD *)v1[71];
  v3 = v1 + 71;
  if ( v2 )
  {
    do
    {
      v4 = v2;
      v2 = (_DWORD *)v2[1];
      sub_492E20(v4);
      sub_5BE8AE(v4);
    }
    while ( v2 );
    v1 = this;
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v1[109] = -1;
  v31 = 0;
  if ( dword_7D6B50 > 0 )
  {
    do
    {
      sub_4E8D80(v31);
      v5 = dword_7D6B58 + 400 * dword_7D6B54;
      sub_4E8F80(String2, 255);
      v6 = this;
      if ( !_strcmpi((const char *)(v5 + 260), aEasports500) )
      {
        if ( (unsigned __int8)sub_475A00(String2) )
        {
          v7 = 0;
          v32 = 0;
          if ( (int)this[74] > 0 )
          {
            do
            {
              v8 = sub_492B30(v7);
              v9 = v8;
              if ( v8 )
              {
                v10 = *(const char **)(v8 + 64);
                if ( !v10 )
                  v10 = &byte_629120;
                if ( !_strcmpi(v10, String2) )
                {
                  v11 = (_DWORD *)*v3;
                  if ( *v3 )
                  {
                    while ( *v11 != v9 )
                    {
                      v11 = (_DWORD *)v11[1];
                      if ( !v11 )
                        goto LABEL_26;
                    }
                    if ( v11 == (_DWORD *)v3[2] )
                      v3[2] = v11[1];
                    v12 = v11[2];
                    if ( v12 )
                      *(_DWORD *)(v12 + 4) = v11[1];
                    else
                      *v3 = v11[1];
                    v13 = v11[1];
                    if ( v13 )
                      *(_DWORD *)(v13 + 8) = v11[2];
                    if ( (_DWORD *)v3[1] == v11 )
                      v3[1] = v11[2];
                    --v3[3];
                    sub_492E20(v11);
                    sub_5BE8AE(v11);
                  }
                }
              }
LABEL_26:
              v7 = ++v32;
            }
            while ( v32 < this[74] );
            v6 = this;
          }
        }
      }
      if ( !(unsigned __int8)sub_475A00(String2) )
      {
        v14 = operator new(0x64u);
        if ( v14 )
        {
          sub_4A5920(v6);
          v14[22] = 0;
          v14[23] = -1;
          *v14 = &off_5D6F68;
        }
        else
        {
          v14 = 0;
        }
        if ( sub_49C9C0(v6) )
          v15 = (char *)sub_49C9C0(v6);
        else
          v15 = (char *)sub_4AE330(v6[12]);
        sub_4A59F0(v15, (int)String2);
        sub_578600(String2);
        v16 = *v14;
        v14[21] = v5;
        v14[1] = v6[85] - v6[84];
        v14[2] = (*(int (__thiscall **)(_DWORD *))(v16 + 8))(v14) + 8;
        *((_BYTE *)v14 + 96) = *(_BYTE *)(v5 + 392);
        v14[20] = 1;
        sub_4A5110(v14, 1);
      }
      ++v31;
    }
    while ( v31 < dword_7D6B50 );
    v1 = this;
  }
  if ( (int)v1[74] > 0 )
  {
    v17 = 0;
    v18 = (_DWORD *)*v3;
    if ( !*v3 )
      goto LABEL_42;
    do
    {
      v18 = (_DWORD *)v18[1];
      ++v17;
    }
    while ( v18 );
    if ( v17 >= 2 )
    {
      v20 = v17 / 2 - 1;
      v21 = (_DWORD *)*v3;
      if ( v20 > 0 )
      {
        do
        {
          --v20;
          v21 = (_DWORD *)v21[1];
        }
        while ( v20 );
      }
      v22 = v21[1];
      v29 = (_DWORD *)*v3;
      v21[1] = 0;
      v23 = sub_492D20(v29);
      v24 = sub_492D20(v22);
      v19 = (_DWORD *)sub_493360(v23, v24);
      v1 = this;
    }
    else
    {
LABEL_42:
      v19 = (_DWORD *)*v3;
    }
    v25 = 0;
    *v3 = v19;
    if ( v19 )
    {
      for ( i = (_DWORD *)v19[1]; i; i = (_DWORD *)i[1] )
      {
        v19[2] = v25;
        v25 = v19;
        v19 = i;
      }
      v19[2] = v25;
    }
    v27 = (_DWORD *)*v3;
    v3[1] = v19;
    v3[2] = v27;
  }
  sub_4A5180(v1);
  return 0;
}
