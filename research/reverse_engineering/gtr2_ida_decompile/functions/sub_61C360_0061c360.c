int __thiscall sub_61C360(_DWORD *this, _DWORD *a2, double *a3, int a4)
{
  _DWORD *v4; // ebx
  int v5; // edi
  _DWORD *v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  double *v11; // edx
  int v12; // edi
  double *v13; // edi
  int v14; // edx
  size_t v15; // esi
  int v16; // edx
  _DWORD *v17; // esi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  bool v23; // cc
  int v24; // eax
  int v25; // edi
  int v26; // esi
  double *v27; // edx
  unsigned int v28; // ecx
  double *v29; // edx
  int v30; // ecx
  size_t v31; // esi
  _DWORD *v32; // edx
  int v33; // eax
  int v34; // ecx
  int v35; // ecx
  int v36; // esi
  void *v37; // eax
  int v38; // edi
  int v39; // ecx
  int v40; // eax
  int v41; // esi
  int v42; // edx
  int v43; // edx
  double *v44; // esi
  int v45; // esi
  int v46; // edx
  int result; // eax
  _DWORD *v48; // esi
  _DWORD *v49; // edi
  int v50; // edx
  int v51; // ebx
  size_t Size; // [esp+10h] [ebp-18h]
  double **Sizea; // [esp+10h] [ebp-18h]
  int v54; // [esp+14h] [ebp-14h]
  int v55; // [esp+14h] [ebp-14h]
  int v56; // [esp+14h] [ebp-14h]
  int v57; // [esp+14h] [ebp-14h]
  int v59; // [esp+1Ch] [ebp-Ch]
  int v60; // [esp+1Ch] [ebp-Ch]
  _DWORD *v61; // [esp+20h] [ebp-8h]
  int v62; // [esp+20h] [ebp-8h]
  _DWORD *v63; // [esp+20h] [ebp-8h]
  int v64; // [esp+24h] [ebp-4h]
  unsigned int v65; // [esp+24h] [ebp-4h]
  int v66; // [esp+24h] [ebp-4h]
  int v67; // [esp+24h] [ebp-4h]
  int v68; // [esp+24h] [ebp-4h]

  v4 = this;
  sub_61C300((void **)this);
  v5 = a4;
  if ( a4 > 0 )
  {
    v6 = a2;
    v64 = a4;
    do
    {
      v7 = 0;
      if ( a4 >= 4 )
      {
        do
        {
          if ( *(double *)(*v6 + 8 * v7) != 0.0 )
            *(double *)(*v6 + 8 * v7) = 1.0;
          if ( *(double *)(*v6 + 8 * v7 + 8) != 0.0 )
            *(double *)(*v6 + 8 * v7 + 8) = 1.0;
          if ( *(double *)(*v6 + 8 * v7 + 16) != 0.0 )
            *(double *)(*v6 + 8 * v7 + 16) = 1.0;
          if ( *(double *)(*v6 + 8 * v7 + 24) != 0.0 )
            *(double *)(*v6 + 8 * v7 + 24) = 1.0;
          v7 += 4;
        }
        while ( v7 < a4 - 3 );
      }
      for ( ; v7 < a4; ++v7 )
      {
        if ( *(double *)(*v6 + 8 * v7) != 0.0 )
          *(double *)(*v6 + 8 * v7) = 1.0;
      }
      ++v6;
      --v64;
    }
    while ( v64 );
    *a3 = 1.0;
    qmemcpy(a3 + 1, a3, 4 * ((unsigned int)(8 * a4 - 5) >> 2));
    v5 = a4;
  }
  v8 = 0;
  v59 = 0;
  Size = 0;
  if ( v5 >= 0 )
  {
    do
    {
      v9 = v8 == a4 ? 0 : v8;
      v54 = v9;
      if ( v9 < a4 )
      {
        v61 = &a2[v9];
        v65 = v9 - 4;
        do
        {
          if ( v8 == a4 )
          {
            v10 = 0;
            if ( v54 >= 4 )
            {
              v11 = (double *)(*v61 + 16);
              v12 = (v65 >> 2) + 1;
              v10 = 4 * v12;
              do
              {
                if ( *(v11 - 2) != 0.0 )
                  ++Size;
                if ( *(v11 - 1) != 0.0 )
                  ++Size;
                if ( *v11 != 0.0 )
                  ++Size;
                if ( v11[1] != 0.0 )
                  ++Size;
                v11 += 4;
                --v12;
              }
              while ( v12 );
            }
            if ( v10 < v54 )
            {
              v13 = (double *)(*v61 + 8 * v10);
              v14 = v54 - v10;
              v15 = Size;
              do
              {
                if ( *v13 != 0.0 )
                  ++v15;
                ++v13;
                --v14;
              }
              while ( v14 );
              Size = v15;
            }
            ++v59;
          }
          else
          {
            v16 = 0;
            if ( v8 >= 4 )
            {
              v17 = a2 + 2;
              do
              {
                v18 = *v61;
                if ( *(double *)(*v61 + 8 * v16) != 0.0 && *(double *)(*(v17 - 2) + 8 * v8) != 0.0 )
                {
                  ++Size;
                  if ( *(double *)(v18 + 8 * v8) == 0.0 )
                    *(double *)(v18 + 8 * v8) = 2.0;
                }
                v19 = *v61;
                if ( *(double *)(*v61 + 8 * v16 + 8) != 0.0 && *(double *)(*(v17 - 1) + 8 * v8) != 0.0 )
                {
                  ++Size;
                  if ( *(double *)(v19 + 8 * v8) == 0.0 )
                    *(double *)(v19 + 8 * v8) = 2.0;
                }
                v20 = *v61;
                if ( *(double *)(*v61 + 8 * v16 + 16) != 0.0 && *(double *)(*v17 + 8 * v8) != 0.0 )
                {
                  ++Size;
                  if ( *(double *)(v20 + 8 * v8) == 0.0 )
                    *(double *)(v20 + 8 * v8) = 2.0;
                }
                v21 = *v61;
                if ( *(double *)(*v61 + 8 * v16 + 24) != 0.0 && *(double *)(v17[1] + 8 * v8) != 0.0 )
                {
                  ++Size;
                  if ( *(double *)(v21 + 8 * v8) == 0.0 )
                    *(double *)(v21 + 8 * v8) = 2.0;
                }
                v16 += 4;
                v17 += 4;
              }
              while ( v16 < v8 - 3 );
            }
            for ( ; v16 < v8; ++v16 )
            {
              v22 = *v61;
              if ( *(double *)(*v61 + 8 * v16) != 0.0 && *(double *)(a2[v16] + 8 * v8) != 0.0 )
              {
                ++Size;
                if ( *(double *)(v22 + 8 * v8) == 0.0 )
                  *(double *)(v22 + 8 * v8) = 2.0;
              }
            }
            if ( *(double *)(*v61 + 8 * v8) != 0.0 )
              ++v59;
            *(double *)(a2[v8] + 8 * v54) = *(double *)(*v61 + 8 * v8);
          }
          v23 = ++v54 < a4;
          ++v65;
          ++v61;
        }
        while ( v23 );
      }
      ++v8;
    }
    while ( v8 <= a4 );
  }
  v24 = a4;
  v25 = a4 - 2;
  if ( a4 - 2 >= 0 )
  {
    v62 = v25 + 1;
    v55 = 8 * v25 + 24;
    v66 = 1;
    do
    {
      v26 = v62;
      if ( v66 >= 4 )
      {
        v27 = (double *)(v55 + a2[v25]);
        v28 = ((unsigned int)(a4 - v62 - 4) >> 2) + 1;
        v26 = v62 + 4 * v28;
        do
        {
          if ( *(v27 - 2) != 0.0 )
            ++Size;
          if ( *(v27 - 1) != 0.0 )
            ++Size;
          if ( *v27 != 0.0 )
            ++Size;
          if ( v27[1] != 0.0 )
            ++Size;
          v27 += 4;
          --v28;
        }
        while ( v28 );
      }
      if ( v26 < a4 )
      {
        v29 = (double *)(a2[v25] + 8 * v26);
        v30 = a4 - v26;
        v31 = Size;
        do
        {
          if ( *v29 != 0.0 )
            ++v31;
          ++v29;
          --v30;
        }
        while ( v30 );
        Size = v31;
      }
      --v25;
      ++v66;
      --v62;
      v55 -= 8;
    }
    while ( v25 >= 0 );
    v24 = a4;
  }
  if ( v24 > 0 )
  {
    v32 = a2;
    v67 = a4;
    do
    {
      v33 = 0;
      if ( a4 >= 4 )
      {
        do
        {
          v34 = *v32 + 8 * v33;
          if ( !*(_DWORD *)v34 && *(_DWORD *)(v34 + 4) == 0x40000000 )
            *(double *)v34 = 0.0;
          if ( !*(_DWORD *)(*v32 + 8 * v33 + 8) && *(_DWORD *)(*v32 + 8 * v33 + 12) == 0x40000000 )
            *(double *)(*v32 + 8 * v33 + 8) = 0.0;
          if ( !*(_DWORD *)(*v32 + 8 * v33 + 16) && *(_DWORD *)(*v32 + 8 * v33 + 20) == 0x40000000 )
            *(double *)(*v32 + 8 * v33 + 16) = 0.0;
          if ( !*(_DWORD *)(*v32 + 8 * v33 + 24) && *(_DWORD *)(*v32 + 8 * v33 + 28) == 0x40000000 )
            *(double *)(*v32 + 8 * v33 + 24) = 0.0;
          v33 += 4;
        }
        while ( v33 < a4 - 3 );
      }
      for ( ; v33 < a4; ++v33 )
      {
        v35 = *v32 + 8 * v33;
        if ( !*(_DWORD *)v35 && *(_DWORD *)(v35 + 4) == 0x40000000 )
          *(double *)v35 = 0.0;
      }
      ++v32;
      --v67;
    }
    while ( v67 );
  }
  v36 = a4;
  *v4 = operator new(8 * a4 + 8);
  v4[1] = operator new(8 * a4);
  v4[2] = operator new(8 * v59);
  v37 = operator new(Size);
  v38 = 0;
  v39 = 0;
  v4[3] = v37;
  v60 = 0;
  if ( a4 >= 0 )
  {
    do
    {
      *(_DWORD *)(*v4 + 8 * v38) = 0;
      *(_DWORD *)(*v4 + 8 * v38 + 4) = v4[2] + 8 * v60;
      v40 = v38 == a4 ? 0 : v38;
      v56 = v40;
      if ( v40 < a4 )
      {
        Sizea = (double **)&a2[v40];
        while ( 1 )
        {
          if ( v38 == a4 )
          {
            ++*(_DWORD *)(*v4 + 8 * v38);
            v41 = v4[2] + 8 * v60++;
            *(_BYTE *)v41 = v40;
            *(_BYTE *)(v41 + 1) = 0;
            *(_DWORD *)(v41 + 4) = v39 + v4[3];
            v42 = 0;
            if ( v40 >= 4 )
            {
              do
              {
                if ( (*Sizea)[v42] != 0.0 )
                {
                  ++*(_BYTE *)(v41 + 1);
                  *(_BYTE *)(v39 + v4[3]) = v42;
                  ++v39;
                }
                if ( (*Sizea)[v42 + 1] != 0.0 )
                {
                  ++*(_BYTE *)(v41 + 1);
                  *(_BYTE *)(v39 + v4[3]) = v42 + 1;
                  v4 = this;
                  ++v39;
                }
                if ( (*Sizea)[v42 + 2] != 0.0 )
                {
                  ++*(_BYTE *)(v41 + 1);
                  *(_BYTE *)(v39 + v4[3]) = v42 + 2;
                  v4 = this;
                  ++v39;
                }
                if ( (*Sizea)[v42 + 3] != 0.0 )
                {
                  ++*(_BYTE *)(v41 + 1);
                  *(_BYTE *)(v39 + v4[3]) = v42 + 3;
                  v4 = this;
                  ++v39;
                }
                v42 += 4;
              }
              while ( v42 < v56 - 3 );
            }
            for ( ; v42 < v56; ++v42 )
            {
              if ( (*Sizea)[v42] != 0.0 )
              {
                ++*(_BYTE *)(v41 + 1);
                *(_BYTE *)(v39 + v4[3]) = v42;
                ++v39;
              }
            }
          }
          else
          {
            if ( (*Sizea)[v38] == 0.0 )
            {
              v43 = 0;
              if ( v38 > 0 )
              {
                v44 = *Sizea;
                while ( *v44 == 0.0 || *(double *)(a2[v43] + 8 * v38) == 0.0 )
                {
                  ++v43;
                  ++v44;
                  if ( v43 >= v38 )
                    goto LABEL_142;
                }
                (*Sizea)[v38] = 2.0;
              }
            }
LABEL_142:
            if ( (*Sizea)[v38] != 0.0 )
            {
              ++*(_DWORD *)(*v4 + 8 * v38);
              v45 = v4[2] + 8 * v60++;
              *(_BYTE *)v45 = v56;
              *(_BYTE *)(v45 + 1) = 0;
              *(_DWORD *)(v45 + 4) = v39 + v4[3];
              v46 = 0;
              if ( v38 >= 4 )
              {
                v63 = a2 + 2;
                do
                {
                  if ( (*Sizea)[v46] != 0.0 && *(double *)(*(v63 - 2) + 8 * v38) != 0.0 )
                  {
                    ++*(_BYTE *)(v45 + 1);
                    *(_BYTE *)(v39 + v4[3]) = v46;
                    ++v39;
                  }
                  if ( (*Sizea)[v46 + 1] != 0.0 && *(double *)(*(v63 - 1) + 8 * v38) != 0.0 )
                  {
                    ++*(_BYTE *)(v45 + 1);
                    *(_BYTE *)(v39 + v4[3]) = v46 + 1;
                    v4 = this;
                    ++v39;
                  }
                  if ( (*Sizea)[v46 + 2] != 0.0 && *(double *)(*v63 + 8 * v38) != 0.0 )
                  {
                    ++*(_BYTE *)(v45 + 1);
                    *(_BYTE *)(v39 + v4[3]) = v46 + 2;
                    v4 = this;
                    ++v39;
                  }
                  if ( (*Sizea)[v46 + 3] != 0.0 && *(double *)(v63[1] + 8 * v38) != 0.0 )
                  {
                    ++*(_BYTE *)(v45 + 1);
                    *(_BYTE *)(v39 + v4[3]) = v46 + 3;
                    v4 = this;
                    ++v39;
                  }
                  v63 += 4;
                  v46 += 4;
                }
                while ( v46 < v38 - 3 );
              }
              for ( ; v46 < v38; ++v46 )
              {
                if ( (*Sizea)[v46] != 0.0 && *(double *)(a2[v46] + 8 * v38) != 0.0 )
                {
                  ++*(_BYTE *)(v45 + 1);
                  *(_BYTE *)(v39 + v4[3]) = v46;
                  ++v39;
                }
              }
            }
            *(double *)(a2[v38] + 8 * v56) = (*Sizea)[v38];
          }
          v23 = ++v56 < a4;
          ++Sizea;
          if ( !v23 )
            break;
          v40 = v56;
        }
      }
      ++v38;
    }
    while ( v38 <= a4 );
    v36 = a4;
  }
  result = v36 - 1;
  v57 = v36 - 1;
  if ( v36 - 1 >= 0 )
  {
    v68 = 0;
    v48 = this;
    v49 = &a2[result];
    do
    {
      v50 = v48[1] + 8 * result;
      *(_BYTE *)v50 = result;
      *(_BYTE *)(v50 + 1) = 0;
      *(_DWORD *)(v50 + 4) = v39 + v48[3];
      v51 = result + 1;
      if ( v68 >= 4 )
      {
        do
        {
          if ( *(double *)(*v49 + 8 * v51) != 0.0 )
          {
            ++*(_BYTE *)(v50 + 1);
            *(_BYTE *)(v39 + this[3]) = v51;
            ++v39;
          }
          if ( *(double *)(*v49 + 8 * v51 + 8) != 0.0 )
          {
            ++*(_BYTE *)(v50 + 1);
            *(_BYTE *)(v39 + this[3]) = v51 + 1;
            ++v39;
          }
          if ( *(double *)(*v49 + 8 * v51 + 16) != 0.0 )
          {
            ++*(_BYTE *)(v50 + 1);
            *(_BYTE *)(v39 + this[3]) = v51 + 2;
            ++v39;
          }
          if ( *(double *)(*v49 + 8 * v51 + 24) != 0.0 )
          {
            ++*(_BYTE *)(v50 + 1);
            *(_BYTE *)(v39 + this[3]) = v51 + 3;
            ++v39;
          }
          v51 += 4;
        }
        while ( v51 < a4 - 3 );
        result = v57;
      }
      v48 = this;
      if ( v51 < a4 )
      {
        do
        {
          if ( *(double *)(*v49 + 8 * v51) != 0.0 )
          {
            ++*(_BYTE *)(v50 + 1);
            *(_BYTE *)(v39 + this[3]) = v51;
            ++v39;
          }
          ++v51;
        }
        while ( v51 < a4 );
        result = v57;
      }
      --result;
      --v49;
      v57 = result;
      ++v68;
    }
    while ( result >= 0 );
  }
  return result;
}
