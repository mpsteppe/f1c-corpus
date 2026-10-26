int __thiscall sub_558310(int this)
{
  int v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int v5; // eax
  int i; // esi
  int v7; // edi
  _WORD *v8; // ecx
  __int16 v9; // dx
  _DWORD *v10; // eax
  __int16 v11; // di
  _DWORD *v12; // eax
  char *v13; // edi
  char *v14; // esi
  unsigned int v15; // edx
  char *v16; // edi
  char *v17; // esi
  char v18; // cl
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  int v22; // ecx
  int v23; // esi
  int v24; // edi
  _WORD *v25; // eax
  int v26; // edx
  _DWORD *v27; // esi
  _DWORD *v28; // edx
  int v29; // edi
  _DWORD *v30; // edx
  _DWORD *v31; // esi
  bool v32; // zf
  __int16 v33; // dx
  __int16 v34; // si
  __int16 v35; // di
  _WORD *v36; // eax
  __int16 v37; // bx
  __int16 v38; // cx
  _WORD *v39; // eax
  _WORD *v40; // eax
  __int16 v41; // di
  unsigned int v42; // eax
  int j; // [esp+18h] [ebp-8h]
  int v44; // [esp+1Ch] [ebp-4h]

  v2 = *(_DWORD *)(this + 32);
  if ( (v2 & 1) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)(this + 80) + 56) = 32;
    *(_DWORD *)(*(_DWORD *)(this + 80) + 8) = *(_DWORD *)(this + 44) * *(_DWORD *)(this + 36);
    *(_DWORD *)(*(_DWORD *)(this + 80) + 16) = *(_DWORD *)(this + 44) * *(_DWORD *)(this + 40);
    v3 = (_DWORD *)sub_587C03(36);
    if ( v3 )
    {
      v3[5] = 0;
      v3[4] = 0;
      v3[3] = 0;
      v3[2] = 0;
      v3[1] = 0;
      *v3 = 0;
      v3[7] = 0;
      v3[6] = 0;
      v3[8] = 0;
    }
    else
    {
      v3 = 0;
    }
    *(_DWORD *)(*(_DWORD *)(this + 80) + 28) = v3;
    **(_DWORD **)(*(_DWORD *)(this + 80) + 28) = *(_DWORD *)(*(_DWORD *)(this + 80) + 56);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 28) + 12) = *(_DWORD *)(*(_DWORD *)(this + 80) + 8);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 28) + 8) = 64;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 28) + 4) = 1234;
    if ( !sub_540DF0(dword_8B78A0, *(int **)(*(_DWORD *)(this + 80) + 28)) )
    {
      *(_DWORD *)(*(_DWORD *)(this + 80) + 44) = 0;
      v4 = (_DWORD *)sub_587C03(28);
      if ( v4 )
      {
        v4[3] = 0;
        v4[2] = 0;
        v4[1] = 0;
        *v4 = 0;
        v4[5] = 0;
        v4[4] = 0;
        v4[6] = 0;
      }
      else
      {
        v4 = 0;
      }
      *(_DWORD *)(*(_DWORD *)(this + 80) + 36) = v4;
      **(_DWORD **)(*(_DWORD *)(this + 80) + 36) = 2;
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 36) + 4) = *(_DWORD *)(*(_DWORD *)(this + 80) + 16);
      if ( !sub_540FC0(dword_8B78A0, *(int **)(*(_DWORD *)(this + 80) + 36)) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 80) + 48) = 0;
        sub_540D40(*(_DWORD **)(this + 80), 44);
        if ( *(char *)(this + 32) >= 0 )
        {
          *(_DWORD *)(*(_DWORD *)(this + 80) + 8) = *(_DWORD *)(this + 36);
          *(_DWORD *)(*(_DWORD *)(this + 80) + 16) = *(_DWORD *)(this + 40);
          v5 = *(_DWORD *)(*(_DWORD *)(this + 80) + 12);
          *(_DWORD *)(v5 + 28) = 0;
          *(_DWORD *)(v5 + 32) = 0;
          v5 += 36;
          *(_DWORD *)(v5 + 28) = 0;
          *(_DWORD *)(v5 + 32) = 1065353216;
          v5 += 36;
          *(_DWORD *)(v5 + 28) = 1065353216;
          *(_DWORD *)(v5 + 32) = 1065353216;
          v5 += 36;
          *(_DWORD *)(v5 + 28) = 1065353216;
          *(_DWORD *)(v5 + 32) = 0;
        }
        for ( i = 0; i < *(_DWORD *)(this + 44); ++i )
        {
          v7 = *(_DWORD *)(this + 80);
          v8 = (_WORD *)(*(_DWORD *)(v7 + 20) + 2 * i * *(_DWORD *)(this + 40));
          v9 = i * *(_WORD *)(this + 36);
          v10 = (_DWORD *)(*(_DWORD *)(v7 + 32) + ((i * *(_DWORD *)(this + 36)) << 6));
          v10[8] = 0;
          v10[9] = 0;
          v10[25] = 1065353216;
          v10[24] = 0;
          v10 += 16;
          v10[24] = 1065353216;
          v10[25] = 1065353216;
          v10 += 16;
          v10[24] = 1065353216;
          v10[25] = 0;
          v8[1] = v9 + 1;
          v11 = v9 + 3;
          *v8 = v9;
          v8[2] = v9 + 2;
          v8[3] = v9 + 2;
          v8[4] = v9 + 3;
          v8[5] = v9;
          if ( (*(_BYTE *)(this + 33) & 2) == 0 )
          {
            v8[7] = v9 + 2;
            v8[6] = v11;
            v8[8] = v9 + 1;
            v8[9] = v9 + 1;
            v8[10] = v9;
            v8[11] = v11;
          }
        }
        v12 = *(_DWORD **)(this + 80);
        v13 = (char *)v12[10];
        if ( !v13 )
          goto LABEL_42;
        v14 = (char *)v12[5];
        if ( *(char *)(this + 32) < 0 )
          goto LABEL_18;
        goto LABEL_40;
      }
    }
    goto LABEL_28;
  }
  if ( (v2 & 2) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)(this + 80) + 56) = 32;
    *(_DWORD *)(*(_DWORD *)(this + 80) + 8) = *(_DWORD *)(this + 44) * *(_DWORD *)(this + 36);
    *(_DWORD *)(*(_DWORD *)(this + 80) + 16) = *(_DWORD *)(this + 44) * *(_DWORD *)(this + 40);
    v19 = (_DWORD *)sub_587C03(36);
    if ( v19 )
    {
      v19[5] = 0;
      v19[4] = 0;
      v19[3] = 0;
      v19[2] = 0;
      v19[1] = 0;
      *v19 = 0;
      v19[7] = 0;
      v19[6] = 0;
      v19[8] = 0;
    }
    else
    {
      v19 = 0;
    }
    *(_DWORD *)(*(_DWORD *)(this + 80) + 28) = v19;
    **(_DWORD **)(*(_DWORD *)(this + 80) + 28) = *(_DWORD *)(*(_DWORD *)(this + 80) + 56);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 28) + 12) = *(_DWORD *)(*(_DWORD *)(this + 80) + 8);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 28) + 8) = 64;
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 28) + 4) = 1234;
    if ( !sub_540DF0(dword_8B78A0, *(int **)(*(_DWORD *)(this + 80) + 28)) )
    {
      *(_DWORD *)(*(_DWORD *)(this + 80) + 44) = 0;
      v20 = (_DWORD *)sub_587C03(28);
      if ( v20 )
      {
        v20[3] = 0;
        v20[2] = 0;
        v20[1] = 0;
        *v20 = 0;
        v20[5] = 0;
        v20[4] = 0;
        v20[6] = 0;
      }
      else
      {
        v20 = 0;
      }
      *(_DWORD *)(*(_DWORD *)(this + 80) + 36) = v20;
      **(_DWORD **)(*(_DWORD *)(this + 80) + 36) = 2;
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + 36) + 4) = *(_DWORD *)(*(_DWORD *)(this + 80) + 16);
      if ( !sub_540FC0(dword_8B78A0, *(int **)(*(_DWORD *)(this + 80) + 36)) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 80) + 48) = 0;
        if ( *(char *)(this + 32) >= 0 )
        {
          *(_DWORD *)(*(_DWORD *)(this + 80) + 8) = *(_DWORD *)(this + 36);
          *(_DWORD *)(*(_DWORD *)(this + 80) + 16) = *(_DWORD *)(this + 40);
        }
        sub_540D40(*(_DWORD **)(this + 80), 44);
        v23 = 0;
        for ( j = 0; v23 < *(_DWORD *)(this + 44); j = v23 )
        {
          v24 = *(_DWORD *)(this + 80);
          v25 = (_WORD *)(*(_DWORD *)(v24 + 20) + 2 * v23 * *(_DWORD *)(this + 40));
          LOWORD(v22) = v23 * *(_WORD *)(this + 36);
          v26 = *(_DWORD *)(v24 + 32) + ((v23 * *(_DWORD *)(this + 36)) << 6);
          v27 = (_DWORD *)(v26 + 36);
          v28 = (_DWORD *)(v26 + 32);
          v29 = 6;
          do
          {
            *v28 = 0;
            *v27 = 0;
            v28[16] = 0;
            v27[16] = 1065353216;
            v30 = v28 + 16;
            v31 = v27 + 16;
            v30[16] = 1065353216;
            v31[16] = 1065353216;
            v30 += 32;
            v31 += 32;
            *v30 = 1065353216;
            *v31 = 1065353216;
            v30 += 16;
            v31 += 16;
            *v30 = 1065353216;
            *v31 = 0;
            v30 += 16;
            v31 += 16;
            *v30 = 0;
            *v31 = 0;
            v28 = v30 + 16;
            v27 = v31 + 16;
            --v29;
          }
          while ( v29 );
          v32 = (**(_BYTE **)(this + 80) & 0x10) == 0;
          v33 = v22 + 1;
          *v25 = v22;
          v25[1] = v22 + 1;
          if ( v32 )
          {
            v25[5] = v22;
            v25[2] = v22 + 2;
            v25[3] = v22 + 2;
            v25[4] = v22 + 3;
            v25[7] = v22 + 2;
            v25[6] = v22 + 3;
            v25[11] = v22 + 3;
            v40 = v25 + 6;
            v40[4] = v22 + 7;
            v40 += 6;
            v41 = v22 + 6;
            *(v40 - 4) = v22 + 6;
            *(v40 - 3) = v22 + 6;
            *v40 = v22 + 7;
            v40[1] = v22 + 6;
            v40[2] = v22 + 5;
            v40[3] = v22 + 5;
            v40[4] = v22 + 4;
            v40[5] = v22 + 7;
            v40 += 6;
            v40[4] = v22;
            *v40 = v22 + 4;
            v40[1] = v22 + 5;
            v40[2] = v33;
            v40[3] = v33;
            v40[5] = v22 + 4;
            v40 += 6;
            v40[1] = v22;
            v40[4] = v22 + 7;
            *v40 = v22 + 4;
            v40[2] = v22 + 3;
            v40[3] = v22 + 3;
            v40[5] = v22 + 4;
            v39 = v40 + 6;
            v39[1] = v22 + 5;
            LOWORD(v22) = v22 + 2;
            v39[2] = v41;
            v39[3] = v41;
            v39[5] = v33;
          }
          else
          {
            v25[7] = v22;
            v25[2] = v33;
            v34 = v22 + 2;
            v25[3] = v22 + 2;
            v25[4] = v22 + 2;
            v35 = v22 + 3;
            v25[5] = v22 + 3;
            v25[6] = v22 + 3;
            v25[8] = v22 + 3;
            v25[9] = v22 + 2;
            v25[10] = v22 + 2;
            v25[15] = v22 + 3;
            v36 = v25 + 8;
            v36[3] = v22 + 6;
            v36[4] = v22 + 6;
            v44 = v22 + 6;
            v36[5] = v22 + 7;
            v36[6] = v22 + 7;
            v36[8] = v22 + 7;
            v36 += 8;
            v36[1] = v22 + 6;
            v36[2] = v22 + 6;
            v36[3] = v22 + 5;
            v36[4] = v22 + 5;
            v36[5] = v22 + 4;
            v36[6] = v22 + 4;
            v36[7] = v22 + 7;
            v36[13] = v22;
            v36[14] = v22;
            v36 += 8;
            v36[3] = v33;
            v36[4] = v33;
            *v36 = v22 + 4;
            v36[1] = v22 + 5;
            v36[2] = v22 + 5;
            v37 = v22 + 4;
            v36[7] = v22 + 4;
            v36 += 8;
            v36[1] = v22;
            v36[2] = v22;
            v36[5] = v22 + 7;
            v36[6] = v22 + 7;
            v38 = v22 + 5;
            *v36 = v37;
            v36[3] = v35;
            v36[4] = v35;
            v36[7] = v37;
            v39 = v36 + 8;
            v39[1] = v38;
            v39[2] = v38;
            v22 = v44;
            v39[3] = v44;
            v39[5] = v34;
            v39[6] = v34;
            v39[7] = v33;
          }
          *v39 = v33;
          v39[4] = v22;
          v23 = j + 1;
        }
        v12 = *(_DWORD **)(this + 80);
        v13 = (char *)v12[10];
        if ( !v13 )
          goto LABEL_42;
        v14 = (char *)v12[5];
        if ( *(char *)(this + 32) < 0 )
        {
LABEL_18:
          v15 = 2 * v12[4];
          qmemcpy(v13, v14, 4 * (v15 >> 2));
          v17 = &v14[4 * (v15 >> 2)];
          v16 = &v13[4 * (v15 >> 2)];
          v18 = v15;
LABEL_41:
          qmemcpy(v16, v17, v18 & 3);
LABEL_42:
          sub_540DA0(*(_DWORD **)(this + 80), 12);
          return 0;
        }
LABEL_40:
        v42 = 2 * *(_DWORD *)(this + 44) * *(_DWORD *)(this + 40);
        qmemcpy(v13, v14, 4 * (v42 >> 2));
        v17 = &v14[4 * (v42 >> 2)];
        v16 = &v13[4 * (v42 >> 2)];
        v18 = v42;
        goto LABEL_41;
      }
    }
LABEL_28:
    sub_53C590(-1, aErrorCreatingV);
    return -1;
  }
  return 0;
}
