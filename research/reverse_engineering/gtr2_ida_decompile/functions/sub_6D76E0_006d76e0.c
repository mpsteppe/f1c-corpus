void __stdcall sub_6D76E0(int *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // esi
  int v5; // edi
  int v6; // ecx
  int v7; // edi
  _DWORD *v8; // edx
  unsigned __int8 *v9; // eax
  int v10; // ecx
  bool v11; // zf
  int v12; // [esp+Ch] [ebp-20h]
  int v13; // [esp+18h] [ebp-14h]
  int v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+20h] [ebp-Ch]
  _BYTE *v16; // [esp+24h] [ebp-8h]
  int v17; // [esp+28h] [ebp-4h]
  _DWORD *v18; // [esp+34h] [ebp+8h]
  int v19; // [esp+38h] [ebp+Ch]
  int v20; // [esp+3Ch] [ebp+10h]

  v17 = 8 * a2[7];
  v4 = a1[60] / a2[2];
  v14 = a1[61] / a2[3];
  sub_6D75E0(v17 * v4, a3, a3, a1[61], a1[7]);
  v5 = a2[3];
  v6 = 0;
  v13 = 0;
  v12 = v5;
  if ( v5 > 0 )
  {
    v18 = (_DWORD *)a3;
    do
    {
      v16 = *(_BYTE **)(a4 + 4 * v6);
      v19 = 0;
      if ( v17 )
      {
        v15 = v17;
        do
        {
          v7 = 0;
          if ( v14 > 0 )
          {
            v8 = v18;
            v20 = v14;
            do
            {
              v9 = (unsigned __int8 *)(v19 + *v8);
              if ( v4 > 0 )
              {
                v10 = v4;
                do
                {
                  v7 += *v9++;
                  --v10;
                }
                while ( v10 );
              }
              ++v8;
              --v20;
            }
            while ( v20 );
          }
          *v16++ = (v7 + v4 * v14 / 2) / (v4 * v14);
          v11 = v15 == 1;
          v19 += v4;
          --v15;
        }
        while ( !v11 );
        v5 = v12;
        v6 = v13;
      }
      ++v6;
      v18 += v14;
      v13 = v6;
    }
    while ( v6 < v5 );
  }
}
