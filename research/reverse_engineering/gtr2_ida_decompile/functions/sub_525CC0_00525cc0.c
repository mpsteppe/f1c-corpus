int __thiscall sub_525CC0(int *this, int *a2, float *a3)
{
  int *v4; // esi
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // ecx
  _DWORD *i; // edx
  int v9; // eax
  int *v10; // ecx
  _BYTE *v12; // edi
  _BYTE *v13; // ecx
  int v14; // esi
  int *v15; // eax
  bool v16; // zf
  int v17; // edx
  int *v18; // eax
  int v19; // ebp
  double v20; // st7
  _DWORD *v21; // esi
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  int *v24; // eax
  float *v25; // ebx
  __int16 v26; // dx
  int *v28; // esi
  int v29; // edi
  int *v30; // eax
  char v31; // al
  char v32; // al
  int v33; // edx
  _DWORD *v34; // eax
  float v35; // [esp+30h] [ebp-28h]
  int v36; // [esp+34h] [ebp-24h]
  int v37; // [esp+38h] [ebp-20h]
  void *Block; // [esp+3Ch] [ebp-1Ch] BYREF
  int *v39; // [esp+40h] [ebp-18h]
  int *v40; // [esp+44h] [ebp-14h]
  int v41; // [esp+48h] [ebp-10h]
  int v42; // [esp+54h] [ebp-4h]
  float v43; // [esp+5Ch] [ebp+4h]

  v36 = 0;
  if ( *(_BYTE *)this )
  {
    v4 = this + 30;
    v5 = 4;
    do
    {
      v6 = sub_524E20(*v4);
      v7 = v6;
      *v4 = (int)v6;
      if ( v6 )
      {
        for ( i = (_DWORD *)v6[1]; i; i = (_DWORD *)i[1] )
          v7 = i;
      }
      v4[1] = (int)v7;
      v4[2] = (int)v6;
      v4 += 4;
      --v5;
    }
    while ( v5 );
    *(_BYTE *)this = 0;
  }
  v9 = 0;
  v10 = this + 33;
  do
  {
    if ( *v10 > 0 )
      break;
    ++v9;
    v10 += 4;
  }
  while ( v9 < 4 );
  if ( v9 == 4 )
    return 0;
  v12 = this + 30;
  v35 = 9.9999997e37;
  v13 = this + 30;
  v14 = 4;
  do
  {
    v15 = *(int **)v13;
    v16 = *(_DWORD *)v13 == 0;
    *((_DWORD *)v13 + 2) = *(_DWORD *)v13;
    if ( !v16 )
    {
      v17 = *v15;
      if ( *v15 )
      {
        if ( *(float *)(v17 + 4) < (double)v35 )
          v35 = *(float *)(v17 + 4);
      }
    }
    v13 += 16;
    --v14;
  }
  while ( v14 );
  Block = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v37 = 4;
  do
  {
    v18 = *(int **)v12;
    v16 = *(_DWORD *)v12 == 0;
    *((_DWORD *)v12 + 2) = *(_DWORD *)v12;
    if ( !v16 )
    {
      v19 = *v18;
      if ( *v18 )
      {
        do
        {
          v20 = v35 - *(float *)(v19 + 4);
          if ( v20 <= -0.02 || v20 >= 0.02 )
            break;
          v21 = *(_DWORD **)v12;
          v22 = 0;
          if ( *(_DWORD *)v12 )
          {
            while ( *v21 != v19 )
            {
              v22 = v21;
              v21 = (_DWORD *)v21[1];
              if ( !v21 )
                goto LABEL_38;
            }
            if ( v21 == *((_DWORD **)v12 + 2) )
              *((_DWORD *)v12 + 2) = v21[1];
            if ( v22 )
              v22[1] = v21[1];
            else
              *(_DWORD *)v12 = v21[1];
            if ( *((_DWORD **)v12 + 1) == v21 )
              *((_DWORD *)v12 + 1) = v22;
            --*((_DWORD *)v12 + 3);
            if ( *((_BYTE *)v21 + 8) )
              j__free((void *)*v21);
            j__free(v21);
          }
LABEL_38:
          v23 = operator new(0xCu);
          if ( v23 )
          {
            *v23 = v19;
            v23[1] = 0;
            *((_BYTE *)v23 + 8) = 0;
          }
          else
          {
            v23 = 0;
          }
          if ( Block )
          {
            v39[1] = (int)v23;
          }
          else
          {
            Block = v23;
            v40 = v23;
          }
          v39 = v23;
          v24 = *(int **)v12;
          v16 = *(_DWORD *)v12 == 0;
          ++v41;
          *((_DWORD *)v12 + 2) = v24;
          if ( v16 )
            break;
          v19 = *v24;
        }
        while ( *v24 );
      }
    }
    v12 += 16;
    --v37;
  }
  while ( v37 );
  v25 = a3;
  v26 = v41;
  *a3 = v35;
  *((_WORD *)v25 + 4) = v26;
  *((_DWORD *)v25 + 1) = sub_614040(a2);
  (*(void (__thiscall **)(int *, float *, int))(*a2 + 24))(a2, v25, 4);
  (*(void (__thiscall **)(int *, float *, int))(*a2 + 24))(a2, v25 + 2, 2);
  v28 = (int *)Block;
  v40 = (int *)Block;
  if ( Block )
  {
    v29 = *(_DWORD *)Block;
    if ( *(_DWORD *)Block )
    {
      while ( 1 )
      {
        v30 = 0;
        if ( v28 )
        {
          while ( *v28 != v29 )
          {
            v30 = v28;
            v28 = (int *)v28[1];
            if ( !v28 )
              goto LABEL_65;
          }
          if ( v28 == v40 )
            v40 = (int *)v28[1];
          if ( v30 )
            v30[1] = v28[1];
          else
            Block = (void *)v28[1];
          if ( v39 == v28 )
            v39 = v30;
          v31 = *((_BYTE *)v28 + 8);
          --v41;
          if ( v31 )
            j__free((void *)*v28);
          j__free(v28);
        }
LABEL_65:
        v43 = *v25;
        (*(void (__thiscall **)(int *, int, int))(*a2 + 24))(a2, v29, 4);
        if ( (*(_DWORD *)v29 & 0xE0000000) == 0x20000000 && (*(_DWORD *)v29 & 0xFC0000) == 0 )
        {
          v32 = sub_431910((*(float *)(v29 + 4) - v43) * 5988.023751164697);
          v33 = *a2;
          LOBYTE(a3) = v32;
          (*(void (__thiscall **)(int *, float **, int))(v33 + 24))(a2, &a3, 1);
        }
        (*(void (__thiscall **)(int *, int, int))(*a2 + 24))(a2, v29 + 8, (*(_DWORD *)v29 >> 8) & 0x3FF);
        ++v36;
        v34 = operator new(0xCu);
        if ( v34 )
        {
          *v34 = v29;
          v34[1] = 0;
          *((_BYTE *)v34 + 8) = 0;
        }
        else
        {
          v34 = 0;
        }
        if ( dword_BE1244 )
        {
          v34[1] = dword_BE1244;
        }
        else
        {
          dword_BE1248 = (int)v34;
          dword_BE124C = (int)v34;
        }
        dword_BE1244 = (int)v34;
        ++dword_BE1250;
        if ( !v40 )
          break;
        v29 = *v40;
        if ( !*v40 )
          break;
        v28 = (int *)Block;
      }
    }
  }
  sub_525140((int *)&Block);
  return v36;
}
