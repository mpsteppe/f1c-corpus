int __thiscall sub_488580(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // esi
  int **v3; // edi
  void *v4; // ebp
  int v5; // esi
  int j; // ebx
  int v7; // ecx
  int *v8; // eax
  int v9; // ebp
  const char *v10; // eax
  int v11; // eax
  int *v12; // esi
  _DWORD *v13; // esi
  char *v14; // eax
  _DWORD *v15; // eax
  int *v16; // eax
  int *v17; // ecx
  int *k; // edx
  int i; // [esp+14h] [ebp-108h]
  int v22; // [esp+18h] [ebp-104h]
  char String2[256]; // [esp+1Ch] [ebp-100h] BYREF

  v1 = this;
  v2 = (_DWORD *)this[216];
  v3 = (int **)(this + 216);
  while ( v2 )
  {
    v4 = v2;
    v2 = (_DWORD *)v2[1];
    sub_576570(v4);
    sub_5BE8AE(v4);
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  for ( i = 0; i < dword_7D6B50; ++i )
  {
    sub_4E8D80(i);
    v5 = dword_7D6B58 + 400 * dword_7D6B54;
    v22 = v5;
    sub_4E8F80(String2, 255);
    if ( !_strcmpi((const char *)(v5 + 260), aEasports500) && (unsigned __int8)sub_4888C0(String2) )
    {
      for ( j = 0; j < this[219]; ++j )
      {
        v7 = j;
        if ( j >= 0 && j < (int)v3[3] )
        {
          v8 = *v3;
          if ( j <= 0 )
          {
LABEL_12:
            if ( v8 )
            {
              v9 = *v8;
              if ( *v8 )
              {
                v10 = *(const char **)(v9 + 64);
                if ( !v10 )
                  v10 = &byte_629120;
                v11 = _strcmpi(v10, String2);
                if ( !v11 )
                {
                  v12 = *v3;
                  if ( *v3 )
                  {
                    while ( *v12 != v9 )
                    {
                      v11 = (int)v12;
                      v12 = (int *)v12[1];
                      if ( !v12 )
                        goto LABEL_29;
                    }
                    if ( v12 == v3[2] )
                      v3[2] = (int *)v12[1];
                    if ( v11 )
                      *(_DWORD *)(v11 + 4) = v12[1];
                    else
                      *v3 = (int *)v12[1];
                    if ( v3[1] == v12 )
                      v3[1] = (int *)v11;
                    v3[3] = (int *)((char *)v3[3] - 1);
                    sub_576570(v12);
                    sub_5BE8AE(v12);
                  }
                }
              }
            }
          }
          else
          {
            while ( v8 )
            {
              v8 = (int *)v8[1];
              if ( --v7 <= 0 )
                goto LABEL_12;
            }
          }
        }
LABEL_29:
        ;
      }
      v1 = this;
    }
    if ( !(unsigned __int8)sub_4888C0(String2) )
    {
      v13 = operator new(0x64u);
      if ( v13 )
      {
        sub_4A5920(v1);
        v13[22] = 0;
        v13[23] = -1;
        *v13 = &off_5D6F68;
      }
      else
      {
        v13 = 0;
      }
      if ( sub_49C9C0(v1) )
        v14 = (char *)sub_49C9C0(v1);
      else
        v14 = (char *)sub_4AE330(v1[12]);
      sub_4A59F0(v14, (int)String2);
      sub_578600(String2);
      v13[21] = v22;
      v15 = operator new(0xCu);
      if ( v15 )
      {
        *v15 = v13;
        v15[1] = 0;
        *((_BYTE *)v15 + 8) = 1;
      }
      else
      {
        v15 = 0;
      }
      if ( *v3 )
      {
        v3[1][1] = (int)v15;
      }
      else
      {
        *v3 = v15;
        v3[2] = v15;
      }
      v3[1] = v15;
      v3[3] = (int *)((char *)v3[3] + 1);
    }
  }
  if ( (int)v1[219] > 0 )
  {
    v16 = (int *)sub_493060(*v3);
    v17 = v16;
    *v3 = v16;
    if ( v16 )
    {
      for ( k = (int *)v16[1]; k; k = (int *)k[1] )
        v17 = k;
    }
    v3[1] = v17;
    v3[2] = v16;
  }
  return 0;
}
