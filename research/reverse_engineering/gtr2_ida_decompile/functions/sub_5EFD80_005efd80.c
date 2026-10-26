int __thiscall sub_5EFD80(int this)
{
  int result; // eax
  int *v3; // ebx
  _DWORD *v4; // ecx
  int v5; // edx
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int *v9; // eax
  int i; // edx
  int v11; // edx
  int v12; // eax
  int *v13; // edi
  int v14; // ebp
  int v15; // eax
  int v16; // edi
  bool v17; // zf
  int v18; // ecx
  int v19; // eax
  double v20; // st7
  _BYTE *v21; // edi
  double v22; // st6
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  char *v26; // eax
  int v27; // ebp
  char *v28; // ebx
  int v29; // eax
  double v30; // st5
  bool v31; // cc
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  int v35; // [esp+8h] [ebp-1Ch]
  int v36; // [esp+8h] [ebp-1Ch]
  int v37; // [esp+Ch] [ebp-18h] BYREF
  int v38; // [esp+10h] [ebp-14h] BYREF
  int *v39; // [esp+14h] [ebp-10h]
  int v40; // [esp+18h] [ebp-Ch]
  int v41; // [esp+1Ch] [ebp-8h]
  int v42; // [esp+20h] [ebp-4h]

  result = sub_5E6E70(*(void **)(this + 172), **(_DWORD **)(this + 172), 0, 2);
  v3 = (int *)result;
  v39 = (int *)result;
  if ( result )
  {
    v4 = *(_DWORD **)(this + 172);
    v5 = v4[1];
    v40 = v4[2];
    v6 = (int)v4[4] >> 2;
    v7 = v5 + v6 * (v40 - 2);
    v8 = v3[v7 - 1];
    v9 = &v3[v7 - 2];
    *(_DWORD *)(this + 88) = v8;
    *(_DWORD *)(this + 92) = *v9;
    *(_DWORD *)(this + 96) = *(v9 - 1);
    for ( i = 1; ; ++i )
    {
      v35 = i + 1;
      if ( *(int *)((char *)&v3[i] + v4[4]) == *(_DWORD *)(this + 88) )
        break;
    }
    *(_DWORD *)(this + 100) = i;
    v11 = 1;
    *(_DWORD *)(this + 116) = v4[1] / (v35 - 1);
    v12 = 4 * v6;
    v13 = &v3[v6 + 1];
    do
    {
      v14 = *v13;
      ++v11;
      v13 = (int *)((char *)v13 + v12);
    }
    while ( v14 != *(_DWORD *)(this + 88) );
    v15 = v40 / (v11 - 1);
    *(_DWORD *)(this + 104) = v11 - 1;
    v16 = v15 * *(_DWORD *)(this + 116);
    *(_DWORD *)(this + 120) = v15;
    *(_DWORD *)(this + 124) = v16 + 32;
    v37 = v4[1];
    v17 = (*(_BYTE *)(this + 16) & 1) == 0;
    v18 = v4[2];
    v42 = v16;
    v38 = v18;
    if ( !v17 )
    {
      (*(void (__thiscall **)(int, int *))(*(_DWORD *)dword_FB27A4 + 280))(dword_FB27A4, &v37);
      (*(void (__thiscall **)(int, int *))(*(_DWORD *)dword_FB27A4 + 280))(dword_FB27A4, &v38);
    }
    v19 = 0;
    v36 = 0;
    if ( v16 > 0 )
    {
      v20 = (double)v37;
      v21 = (_BYTE *)(this + 189);
      v22 = (double)v38;
      do
      {
        v23 = *(_DWORD *)(this + 116);
        v24 = *(_DWORD *)(this + 100) * (v19 % v23) + 1;
        v25 = v19 / v23 * *(_DWORD *)(this + 104) + 1;
        v26 = (char *)v3 + v25 * *(_DWORD *)(*(_DWORD *)(this + 172) + 16);
        v27 = *(_DWORD *)&v26[4 * v24];
        v28 = &v26[4 * v24];
        v29 = 0;
        v17 = v27 == *(_DWORD *)(this + 96);
        v40 = v24;
        v41 = v25;
        if ( v17 )
        {
LABEL_14:
          LOBYTE(v29) = v29 + 1;
        }
        else
        {
          while ( ++v29 < *(_DWORD *)(this + 100) )
          {
            if ( *(_DWORD *)&v28[4 * v29] == *(_DWORD *)(this + 96) )
              goto LABEL_14;
          }
        }
        v30 = (double)v40;
        *(v21 - 1) = v29 - 1;
        *v21 = *(_BYTE *)(this + 104) - 1;
        *(_WORD *)(v21 - 3) = v25;
        *(_WORD *)(v21 - 5) = v24;
        v3 = v39;
        v21 += 24;
        *(float *)(v21 - 21) = v30 / v20;
        *(float *)(v21 - 17) = (double)v41 / v22;
        v41 = *(_DWORD *)(this + 100) + v24 - 1;
        *(float *)(v21 - 13) = (double)v41 / v20;
        v41 = *(_DWORD *)(this + 104) + v25 - 1;
        v19 = v36 + 1;
        v31 = ++v36 < v42;
        *(float *)(v21 - 9) = (double)v41 / v22;
      }
      while ( v31 );
    }
    v32 = *(_DWORD *)(this + 172);
    if ( *(_DWORD *)(v32 + 4) * *(_DWORD *)(v32 + 8) > 0 )
    {
      v33 = *(_DWORD *)(v32 + 4) * *(_DWORD *)(v32 + 8);
      do
      {
        v34 = *v3;
        if ( *v3 == *(_DWORD *)(this + 96) || v34 == *(_DWORD *)(this + 88) || v34 == *(_DWORD *)(this + 92) )
        {
          *v3 = 0;
          **(_DWORD **)(this + 172) |= 0x200u;
        }
        ++v3;
        --v33;
      }
      while ( v33 );
    }
    *(_DWORD *)(this + 92) = -16777216;
    return sub_5E6EA0(*(void **)(this + 172), **(_DWORD **)(this + 172), 0, 2);
  }
  return result;
}
