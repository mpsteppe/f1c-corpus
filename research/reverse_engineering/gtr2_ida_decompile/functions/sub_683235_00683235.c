int __thiscall sub_683235(_DWORD *this, int a2, int *a3, double *a4)
{
  int v4; // ebx
  int v6; // ecx
  bool v7; // zf
  double v8; // st7
  _DWORD *v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // eax
  _DWORD *v12; // edi
  unsigned int v13; // edi
  double v14; // st7
  int v15; // ecx
  int v16; // edi
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // edi
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edi
  int v25; // eax
  int v27; // eax
  double v28; // st7
  double v29; // [esp+8h] [ebp-20h] BYREF
  int v30; // [esp+10h] [ebp-18h]
  double v31; // [esp+14h] [ebp-14h] BYREF
  double v32; // [esp+1Ch] [ebp-Ch] BYREF
  int v33; // [esp+24h] [ebp-4h] BYREF

  v4 = a2;
  v6 = *(_DWORD *)(this[5] + 4 * a2);
  v7 = a2 == *a3;
  v30 = v6;
  if ( !v7 )
  {
    if ( *(_DWORD *)(v6 + 64) != -1 )
    {
      v33 = *(_DWORD *)(v6 + 64);
      v8 = *(double *)(v6 + 40);
      goto LABEL_3;
    }
    if ( *(_DWORD *)(v6 + 8) == -1 && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v6 + 4)) + 4) & 2) != 0 )
    {
      v9 = *(_DWORD **)(this[6] + 4 * *(_DWORD *)(v6 + 72));
      v10 = v9[3];
      v11 = 0;
      if ( v10 )
      {
        v12 = (_DWORD *)v9[4];
        do
        {
          if ( *v12 == a2 )
            break;
          ++v11;
          ++v12;
        }
        while ( v11 < v10 );
      }
      if ( v11 == v10 )
        goto LABEL_41;
      v13 = *v9 & 0xFFF00000;
      switch ( v13 )
      {
        case 0x10000000u:
          v33 = -1;
          if ( (int)sub_683235(*(_DWORD *)(v9[2] + 4 * v11), &v33, &v29) >= 0 )
            goto LABEL_43;
          goto LABEL_41;
        case 0x10100000u:
          v33 = -1;
          if ( (int)sub_683235(*(_DWORD *)(v9[2] + 4 * v11), &v33, &v29) >= 0 )
          {
            v14 = -v29;
LABEL_42:
            v29 = v14;
            goto LABEL_43;
          }
LABEL_41:
          v14 = 1.0;
          v33 = v4;
          goto LABEL_42;
        case 0x20400000u:
          v15 = v9[2];
          v16 = *(_DWORD *)(v15 + 4 * v11);
          v17 = *(_DWORD *)(v15 + 4 * (v11 + v10));
          v33 = -1;
          if ( v16 == v17 )
          {
            if ( (int)sub_683235(v16, &v33, &v29) >= 0 )
            {
              v14 = v29 + v29;
              goto LABEL_42;
            }
          }
          else if ( (int)sub_683235(v16, &v33, &v32) >= 0 && (int)sub_683235(v17, &v33, &v31) >= 0
                 || (v33 = -1, (int)sub_683235(v17, &v33, &v31) >= 0) && (int)sub_683235(v16, &v33, &v32) >= 0 )
          {
            v14 = v31 + v32;
            goto LABEL_42;
          }
          goto LABEL_40;
      }
      if ( v13 != 542113792 )
        goto LABEL_41;
      v18 = v9[2];
      v19 = *(_DWORD *)(v18 + 4 * (v11 + v10));
      HIDWORD(v32) = *(_DWORD *)(v18 + 4 * v11);
      HIDWORD(v31) = v19;
      if ( HIDWORD(v32) == v19 )
        goto LABEL_41;
      v20 = 4 * v19;
      v21 = *(_DWORD *)(4 * v19 + this[5]);
      if ( (*(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v21 + 4)) + 4) & 0x100) != 0 && *(_DWORD *)(v21 + 8) == -1 )
      {
        v33 = -1;
        if ( (int)sub_683235(HIDWORD(v32), &v33, &v29) >= 0 )
        {
          v22 = *(_DWORD *)(v20 + this[5]);
          goto LABEL_39;
        }
        v19 = HIDWORD(v31);
      }
      v23 = this[5];
      v24 = this[4];
      HIDWORD(v31) = 4 * HIDWORD(v32);
      v25 = *(_DWORD *)(4 * HIDWORD(v32) + v23);
      if ( (*(_DWORD *)(*(_DWORD *)(v24 + 4 * *(_DWORD *)(v25 + 4)) + 4) & 0x100) == 0
        || *(_DWORD *)(v25 + 8) != -1
        || (v33 = -1, (int)sub_683235(v19, &v33, &v29) < 0) )
      {
LABEL_40:
        v4 = a2;
        goto LABEL_41;
      }
      v22 = *(_DWORD *)(HIDWORD(v31) + this[5]);
LABEL_39:
      v14 = v29 * *(double *)(v22 + 32);
      goto LABEL_42;
    }
  }
  v33 = a2;
  v8 = 1.0;
LABEL_3:
  v29 = v8;
LABEL_43:
  if ( *a3 != -1 && v33 != *a3 )
    return -2147467259;
  v27 = v30;
  *(_DWORD *)(v30 + 64) = v33;
  v28 = v29;
  *a3 = v33;
  *(double *)(v27 + 40) = v28;
  *a4 = v29;
  return 0;
}
