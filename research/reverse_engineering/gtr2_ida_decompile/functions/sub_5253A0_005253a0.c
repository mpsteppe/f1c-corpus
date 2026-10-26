int __userpurge sub_5253A0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4)
{
  int result; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // ebp
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // ebp
  int v14; // esi
  int v15; // eax
  char v16; // dl
  int v17; // ecx
  int v18; // esi
  int v19; // edi
  char v20; // al
  int v21; // ebx
  int v22; // ebx
  int v23; // ebp
  char v24; // [esp+1h] [ebp-85h]
  int v26; // [esp+6h] [ebp-80h]
  int v27; // [esp+Ah] [ebp-7Ch]
  int v28; // [esp+Eh] [ebp-78h]
  int v29; // [esp+16h] [ebp-70h]
  _DWORD v30[25]; // [esp+1Ah] [ebp-6Ch]
  int v31; // [esp+7Eh] [ebp-8h]

  result = 22616 * a4;
  if ( dword_923E84[5654 * a4] != -1 )
  {
    v6 = 0;
    v24 = HIBYTE(a3);
    v30[0] = 0;
    v30[1] = 0;
    while ( 1 )
    {
      v7 = a1[722649];
      v8 = a1[722650];
      v9 = 0;
      if ( v7 >= v8 )
      {
        if ( v7 < 0 || v8 < 0 )
        {
LABEL_10:
          v28 = 0;
          goto LABEL_11;
        }
        v10 = v7 - v8 + 1;
      }
      else
      {
        v10 = a1[722648] - v8 + v7 + 1;
      }
      v28 = v10;
      if ( v10 == 1 && !*(_BYTE *)(184 * v8 + a1[722647]) )
        goto LABEL_10;
LABEL_11:
      if ( v28 > 0 )
      {
        do
        {
          v11 = a1[722649] - v6;
          if ( v11 < 0 )
            v11 += a1[722648];
          v12 = sub_521380();
          if ( v12 )
          {
            if ( v24 )
              break;
            v30[v9] = v12;
            v30[v9++ + 12] = v11;
          }
          if ( v9 >= 12 )
            break;
          ++v6;
        }
        while ( v6 < a2 );
        v26 = v9;
      }
      if ( (double)v26 >= 9.0 )
      {
        v13 = v9 - 1;
        v14 = 0;
        a2 = v13;
        if ( v13 - 1 > 0 )
        {
          v15 = v31 / 8;
          v16 = 1 << (v31 % 8);
          do
          {
            v17 = 184 * v30[v14 + 12] + a1[722647] + 57;
            *(_BYTE *)(v15 + v17) |= v16;
            ++v14;
          }
          while ( v14 < v13 - 1 );
        }
        if ( v13 > 1 )
        {
          while ( 1 )
          {
            v18 = v13 - 1;
            v19 = v13 - 2;
            v20 = 0;
            v21 = v13 - 1;
            v29 = v13 - 1;
            v26 = v13 - 1;
            if ( v13 - 2 > 0 )
            {
              while ( v21 <= v19 )
              {
LABEL_36:
                if ( v20 )
                {
                  if ( --v19 > 0 )
                    continue;
                }
                goto LABEL_40;
              }
              while ( v18 <= v19 )
              {
                if ( !v20 )
                  goto LABEL_40;
LABEL_35:
                v26 = --v21;
                if ( v21 <= v19 )
                  goto LABEL_36;
              }
              v22 = v30[v19];
              v23 = v30[v13];
              while ( sub_521B90((float *)v27, v23, v30[v18], v22) )
              {
                --v18;
                v20 = 1;
                if ( v18 <= v19 )
                {
                  v13 = a2;
                  v18 = v29;
                  v21 = v26;
                  goto LABEL_35;
                }
              }
              v18 = v29;
              v21 = v26;
            }
LABEL_40:
            while ( v18 > v21 )
            {
              sub_5251E0((_BYTE *)(*(_DWORD *)(v27 + 2890588) + 184 * v30[v18 + 12]), (_DWORD *)v30[v18]);
              --v18;
            }
            a2 = v21;
            if ( v21 <= 1 )
              break;
            v13 = v21;
          }
          a1 = (_DWORD *)v27;
        }
      }
      v6 = 0;
    }
  }
  return result;
}
