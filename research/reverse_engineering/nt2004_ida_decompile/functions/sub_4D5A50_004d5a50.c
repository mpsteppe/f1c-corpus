int __thiscall sub_4D5A50(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *v3; // ebp
  bool v4; // zf
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  _DWORD *v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // esi
  int v12; // edi
  char v13; // al
  int v14; // ebx
  int v15; // ebx
  char v16; // al
  char v17; // [esp+7h] [ebp-79h] BYREF
  int v18; // [esp+8h] [ebp-78h]
  int i; // [esp+Ch] [ebp-74h]
  _DWORD *v20; // [esp+10h] [ebp-70h]
  int j; // [esp+14h] [ebp-6Ch]
  int v22; // [esp+18h] [ebp-68h]
  int v23; // [esp+1Ch] [ebp-64h]
  _DWORD v24[24]; // [esp+20h] [ebp-60h]

  result = 25304 * a2;
  v3 = this;
  v4 = dword_630030[6326 * a2] == -1;
  v20 = this;
  if ( !v4 )
  {
    for ( i = 0; i < 4; ++i )
    {
      v5 = 0;
      v18 = 0;
      v6 = 0;
      v22 = sub_4D6280(v3);
      if ( v22 > 0 )
      {
        do
        {
          v7 = v3[332] - v6;
          if ( v7 < 0 )
            v7 += v3[331];
          v8 = sub_4D37A0((char *)(v3[330] + (v7 << 7)), i, a2, &v17);
          if ( v8 )
          {
            if ( v17 )
              break;
            v24[v5] = v8;
            v24[v5++ + 12] = v7;
          }
          if ( v5 >= 12 )
            break;
          ++v6;
        }
        while ( v6 < v22 );
        v18 = v5;
      }
      if ( (double)v18 >= 9.0 )
      {
        v9 = v5 - 1;
        v10 = 0;
        for ( j = v9; v10 < v9 - 1; ++v10 )
          sub_4D3760((_BYTE *)(v3[330] + (v24[v10 + 12] << 7)), i, a2);
        if ( v9 > 1 )
        {
          while ( 1 )
          {
            v11 = v9 - 1;
            v12 = v9 - 2;
            v13 = 0;
            v14 = v11;
            v22 = v11;
            v18 = v11;
            if ( v12 > 0 )
            {
              while ( v14 <= v12 )
              {
LABEL_27:
                if ( v13 )
                {
                  if ( --v12 > 0 )
                    continue;
                }
                goto LABEL_31;
              }
              while ( v11 <= v12 )
              {
                if ( !v13 )
                  goto LABEL_31;
LABEL_26:
                v18 = --v14;
                if ( v14 <= v12 )
                  goto LABEL_27;
              }
              v15 = v24[v12];
              v23 = v24[j];
              while ( 1 )
              {
                v16 = sub_4D5C20(v23, v24[v11], v15);
                v3 = v20;
                if ( !v16 )
                  break;
                --v11;
                v13 = 1;
                if ( v11 <= v12 )
                {
                  v11 = v22;
                  v14 = v18;
                  goto LABEL_26;
                }
              }
              v11 = v22;
              v14 = v18;
            }
LABEL_31:
            while ( v11 > v14 )
            {
              sub_4D3990((char *)(v3[330] + (v24[v11 + 12] << 7)), (_DWORD *)v24[v11]);
              --v11;
            }
            j = v14;
            if ( v14 <= 1 )
              break;
            v9 = j;
          }
        }
      }
      result = i + 1;
    }
  }
  return result;
}
