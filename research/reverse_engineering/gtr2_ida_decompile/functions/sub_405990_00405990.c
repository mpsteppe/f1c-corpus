char __thiscall sub_405990(_BYTE *this, double a2)
{
  char v2; // fps^1
  bool v3; // c0
  char v4; // c2
  bool v5; // c3
  _BYTE *v6; // ebp
  __int16 v7; // ax
  char v8; // bl
  double v9; // st7
  int v10; // eax
  int *v11; // ecx
  _DWORD *v12; // edx
  int v13; // ecx
  int *v14; // ebx
  int v15; // esi
  int v16; // eax
  _BYTE *v17; // eax
  _DWORD *v18; // edx
  int v19; // esi
  const void *v20; // esi
  int v21; // eax
  int v22; // edi
  int v23; // ecx
  int v24; // esi
  int v25; // ebp
  int v26; // eax
  double v27; // st7
  bool v28; // zf
  int v29; // ecx
  int v30; // eax
  int v31; // ebx
  double v32; // st7
  float *v33; // eax
  float *v34; // ecx
  double v35; // st7
  double v36; // st6
  float v37; // eax
  int v38; // ebx
  double v39; // st7
  float *v40; // eax
  int v42; // [esp+4h] [ebp-78h]
  char v43; // [esp+1Bh] [ebp-61h]
  int *v44; // [esp+1Ch] [ebp-60h]
  float v46; // [esp+2Ch] [ebp-50h]
  float v47; // [esp+38h] [ebp-44h]
  float v48[16]; // [esp+3Ch] [ebp-40h] BYREF
  int v49; // [esp+80h] [ebp+4h]

  v4 = 0;
  v5 = a2 == 0.0;
  v6 = this;
  v3 = a2 < 0.0;
  HIBYTE(v7) = v2;
  if ( a2 == 0.0 )
  {
    v43 = 1;
  }
  else
  {
    v43 = 0;
    if ( !this[4] || (v7 = sub_4057C0(), !(_BYTE)v7) )
    {
      v8 = 0;
      goto LABEL_4;
    }
  }
  v8 = 1;
LABEL_4:
  if ( v6[6] && dword_BE1204 == 2 )
    v9 = 0.0;
  else
    v9 = a2;
  if ( v8 || v6[5] )
    v7 = 1;
  else
    LOBYTE(v7) = 0;
  (*(void (__stdcall **)(_DWORD, _DWORD, __int16, _DWORD))(**((_DWORD **)v6 + 2) + 36))(
    LODWORD(v9),
    HIDWORD(*(unsigned __int64 *)&v9),
    v7,
    0);
  if ( v8 || (LOBYTE(v10) = v6[5], (_BYTE)v10) )
  {
    v11 = (int *)*((_DWORD *)v6 + 12);
    v10 = *v11;
    v12 = (_DWORD *)**((_DWORD **)v6 + 9);
    if ( (int *)*v11 != v11 )
    {
      do
      {
        if ( v12 == *((_DWORD **)v6 + 9) )
          break;
        qmemcpy(v48, (const void *)(v12[2] + 68), sizeof(v48));
        qmemcpy((void *)(*(_DWORD *)(v10 + 8) + 76), v48, 0x40u);
        **(_DWORD **)(v10 + 8) |= 0x40u;
        v10 = *(_DWORD *)v10;
        v12 = (_DWORD *)*v12;
      }
      while ( v10 != *((_DWORD *)v6 + 12) );
    }
    v13 = *((_DWORD *)v6 + 5);
    if ( v13 )
    {
      v10 = (*((_DWORD *)v6 + 6) - v13) >> 2;
      if ( v10 )
      {
        v10 = *((_DWORD *)v6 + 6);
        v14 = (int *)*((_DWORD *)v6 + 5);
        v44 = v14;
        if ( v13 != v10 )
        {
          do
          {
            if ( v43
              || (v15 = *v14, (**(_BYTE **)*v14 & 6) == 0)
              && ((v42 = *(_DWORD *)(v15 + 4), v16 = sub_410A80(&dword_91BF20), (unsigned __int8)sub_5DAF80(v16, v42))
               || v6[5]
               && (v17 = *(_BYTE **)(dword_91BF40 + 8)) != 0
               && (*v17 & 8) != 0
               && (unsigned __int8)sub_5DAF80(v17, *(_DWORD *)(v15 + 4))) )
            {
              v18 = (_DWORD *)*v14;
              v19 = *(_DWORD *)(*v14 + 16);
              if ( v6[6] )
                v20 = (const void *)(v19 + 4);
              else
                v20 = (const void *)(v19 + 68);
              v21 = v18[1];
              qmemcpy(v48, v20, sizeof(v48));
              v22 = 0;
              if ( *(int *)(v21 + 360) > 0 )
              {
                do
                {
                  v23 = *(_DWORD *)(v18[2] + 4 * v22);
                  v24 = 0;
                  if ( *(int *)(v23 + 8) > 0 )
                  {
                    v49 = 0;
                    v25 = 0;
                    do
                    {
                      v26 = *(_DWORD *)(*(_DWORD *)(v18[5] + 4 * v22) + 4 * v24);
                      if ( v26 != -1 )
                      {
                        v27 = v48[8];
                        v28 = (*(_BYTE *)v23 & 8) == 0;
                        v29 = *(_DWORD *)(v23 + 32);
                        v30 = 3 * v26;
                        if ( v28 )
                        {
                          v34 = (float *)(v49 + v29);
                          v38 = v18[3];
                          v39 = v27 * *(float *)(v38 + 4 * v30 + 8);
                          v40 = (float *)(v38 + 4 * v30);
                          v35 = v39 + v48[4] * v40[1] + v48[0] * *v40 + v48[12];
                          v36 = v48[1] * *v40 + v48[9] * v40[2] + v48[5] * v40[1] + v48[13];
                          v47 = v48[2] * *v40 + v48[10] * v40[2] + v48[6] * v40[1] + v48[14];
                          v37 = v47;
                        }
                        else
                        {
                          v31 = v18[3];
                          v32 = v27 * *(float *)(v31 + 4 * v30 + 8);
                          v33 = (float *)(v31 + 4 * v30);
                          v34 = (float *)(v25 + v29);
                          v35 = v32 + v48[4] * v33[1] + v48[0] * *v33 + v48[12];
                          v36 = v48[9] * v33[2] + v48[5] * v33[1] + v48[1] * *v33 + v48[13];
                          v46 = v48[10] * v33[2] + v48[6] * v33[1] + v48[2] * *v33 + v48[14];
                          v37 = v46;
                        }
                        *v34 = v35;
                        v34[1] = v36;
                        v34[2] = v37;
                      }
                      v49 += 64;
                      v23 = *(_DWORD *)(v18[2] + 4 * v22);
                      ++v24;
                      v25 += 88;
                    }
                    while ( v24 < *(_DWORD *)(v23 + 8) );
                    v6 = this;
                    v14 = v44;
                  }
                  ++v22;
                }
                while ( v22 < *(_DWORD *)(v18[1] + 360) );
              }
              *(_DWORD *)v18[1] &= ~0x800u;
            }
            v10 = *((_DWORD *)v6 + 6);
            v44 = ++v14;
          }
          while ( v14 != (int *)v10 );
        }
      }
    }
  }
  return v10;
}
