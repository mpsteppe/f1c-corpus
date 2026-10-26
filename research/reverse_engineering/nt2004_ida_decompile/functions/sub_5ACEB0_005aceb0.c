int __thiscall sub_5ACEB0(float *this, FILE *Stream, size_t ElementCount)
{
  float *v3; // ebx
  _DWORD *v4; // ebp
  int v5; // edx
  int v6; // eax
  char v7; // cl
  int v8; // eax
  unsigned int v9; // esi
  float *v11; // edi
  int v12; // esi
  _DWORD *v13; // eax
  int v14; // esi
  _DWORD *v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // ebp
  int v19; // esi
  _DWORD *v20; // eax
  int v21; // esi
  _DWORD *v22; // edx
  Concurrency::details::_ReaderWriterLock *v23; // ecx
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // eax
  int v28; // edi
  int *v29; // esi
  _DWORD *v30; // ebx
  void *v31; // eax
  int v32; // esi
  bool v33; // cc
  char *v34; // esi
  char *v35; // eax
  FILE *v36; // eax
  int v37; // esi
  FILE *v38; // ebp
  int v39; // esi
  int v40; // ecx
  int *v41; // esi
  int *v42; // edi
  int v43; // ebp
  char *v44; // eax
  _DWORD *v45; // eax
  int v46; // ebp
  int v47; // ebp
  void *v48; // ecx
  unsigned int v49; // edx
  int v50; // eax
  int v51; // ecx
  double v52; // st7
  int v53; // edi
  int v54; // [esp+10h] [ebp-14h]
  _DWORD *v55; // [esp+10h] [ebp-14h]
  int v56; // [esp+10h] [ebp-14h]
  int v58; // [esp+14h] [ebp-10h]
  _DWORD *v59; // [esp+1Ch] [ebp-8h]
  FILE *Streama; // [esp+28h] [ebp+4h]
  FILE *Streamb; // [esp+28h] [ebp+4h]
  FILE *Streamc; // [esp+28h] [ebp+4h]
  size_t ElementCounta; // [esp+2Ch] [ebp+8h]

  v3 = this;
  v4 = 0;
  if ( ElementCount
    && (v5 = *(_DWORD *)(ElementCount + 296),
        v6 = *(_DWORD *)(ElementCount + 292) << 8,
        v7 = *(_BYTE *)(v6 + v5),
        v8 = v5 + v6,
        (v7 & 0x10) != 0) )
  {
    v9 = *(_DWORD *)(v8 + 12);
    dword_7F5E68 = (int)operator new(*(_DWORD *)(v8 + 8));
    dword_7F5E6C = (int)operator new(v9);
    if ( sub_5BED6F((void *)dword_7F5E6C, 1u, v9, Stream) != v9 )
    {
      sub_5BE8AE();
      sub_5BE8AE();
      return -1;
    }
    sub_5D2750(dword_7F5E6C, v9);
  }
  else
  {
    v26 = ftell(Stream);
    fseek(Stream, 0, 2);
    ElementCounta = ftell(Stream) - v26;
    fseek(Stream, v26, 0);
    dword_7F5E68 = (int)operator new(ElementCounta);
    if ( sub_5BED6F((void *)dword_7F5E68, 1u, ElementCounta, Stream) != ElementCounta )
    {
      sub_5BE8AE();
      return -1;
    }
  }
  dword_7F5E74 = 0;
  sub_59D490(v3 + 7, dword_7F5E68, 0x10u);
  sub_59D490(v3, dword_7F5E68, 4u);
  v11 = v3 + 1;
  sub_59D490(v3 + 1, dword_7F5E68, 4u);
  sub_59D490(v3 + 2, dword_7F5E68, 4u);
  v3[1] = 1.0 / v3[1];
  _strupr((char *)v3 + 28);
  if ( (*(_DWORD *)v3 & 2) != 0 )
  {
    sub_59D490(v3 + 5, dword_7F5E68, 4u);
    v12 = *((_DWORD *)v3 + 5);
    v13 = operator new(12 * v12 + 4);
    if ( v13 )
    {
      *v13 = v12;
      v14 = v12 - 1;
      v4 = v13 + 1;
      v15 = v13 + 1;
      if ( v14 >= 0 )
      {
        v16 = v14 + 1;
        do
        {
          sub_5B1340(v15);
          v15 += 3;
          --v16;
        }
        while ( v16 );
      }
    }
    v17 = *((_DWORD *)v3 + 5);
    *((_DWORD *)v3 + 6) = v4;
    Streama = 0;
    if ( v17 > 0 )
    {
      v54 = 0;
      do
      {
        v18 = v54 + *((_DWORD *)v3 + 6);
        sub_59D490((void *)(v18 + 4), dword_7F5E68, 4u);
        v19 = *(_DWORD *)(v18 + 4);
        v20 = operator new(8 * v19 + 4);
        if ( v20 )
        {
          *v20 = v19;
          v21 = v19 - 1;
          v22 = v20 + 1;
          v23 = (Concurrency::details::_ReaderWriterLock *)(v20 + 1);
          if ( v21 >= 0 )
          {
            v24 = v21 + 1;
            do
            {
              Concurrency::details::_ReaderWriterLock::_ReaderWriterLock(v23);
              v23 = (Concurrency::details::_ReaderWriterLock *)(v25 + 8);
              --v24;
            }
            while ( v24 );
          }
        }
        else
        {
          v22 = 0;
        }
        v27 = *(_DWORD *)(v18 + 4);
        v28 = 0;
        *(_DWORD *)(v18 + 8) = v22;
        if ( v27 > 0 )
        {
          do
          {
            v29 = (int *)(*(_DWORD *)(v18 + 8) + 8 * v28);
            sub_59D490(v29, dword_7F5E68, 4u);
            v30 = v29 + 1;
            v31 = operator new(36 * *v29);
            v32 = *v29;
            *v30 = v31;
            sub_59D490(v30, dword_7F5E68, 36 * v32);
            ++v28;
          }
          while ( v28 < *(_DWORD *)(v18 + 4) );
          v3 = this;
        }
        v33 = (int)&Streama->_ptr + 1 < *((_DWORD *)v3 + 5);
        Streama = (FILE *)((char *)Streama + 1);
        v54 += 12;
      }
      while ( v33 );
    }
  }
  else if ( (*(_DWORD *)v3 & 1) != 0 )
  {
    sub_59D490(v3 + 3, dword_7F5E68, 4u);
    v34 = (char *)*((_DWORD *)v3 + 3);
    v35 = (char *)operator new(44 * (_DWORD)v34 + 4);
    if ( v35 )
    {
      v36 = (FILE *)(v35 + 4);
      v36[-1]._tmpfname = v34;
      v37 = (int)(v34 - 1);
      Streamb = v36;
      v38 = v36;
      if ( v37 >= 0 )
      {
        v39 = v37 + 1;
        do
        {
          sub_5ACB70(v38);
          v38 = (FILE *)((char *)v38 + 44);
          --v39;
        }
        while ( v39 );
        v36 = Streamb;
      }
    }
    else
    {
      v36 = 0;
    }
    v40 = *((_DWORD *)v3 + 3);
    *((_DWORD *)v3 + 4) = v36;
    Streamc = 0;
    if ( v40 > 0 )
    {
      v58 = 0;
      do
      {
        v41 = (int *)(v58 + *((_DWORD *)v3 + 4));
        sub_59D490(v41, dword_7F5E68, 0x20u);
        sub_59D490(v41 + 8, dword_7F5E68, 4u);
        v42 = v41 + 9;
        sub_59D490(v41 + 9, dword_7F5E68, 4u);
        v43 = v41[9];
        v44 = (char *)operator new(32 * v43 + 4);
        if ( v44 )
        {
          v45 = v44 + 4;
          *(v45 - 1) = v43;
          v46 = v43 - 1;
          v59 = v45;
          v55 = v45;
          if ( v46 >= 0 )
          {
            v47 = v46 + 1;
            do
            {
              sub_5ACB30(v55);
              --v47;
              v55 += 8;
            }
            while ( v47 );
            v45 = v59;
          }
          v48 = v45;
        }
        else
        {
          v48 = 0;
        }
        v49 = 32 * *v42;
        v41[10] = (int)v48;
        sub_59D490(v48, dword_7F5E68, v49);
        v50 = 0;
        v56 = 0;
        if ( *v42 > 0 )
        {
          v51 = 0;
          do
          {
            ++v50;
            v51 += 32;
            v52 = (double)v56 * v3[1];
            v56 = v50;
            *(float *)(v51 + v41[10] - 32) = v52;
          }
          while ( v50 < *v42 );
        }
        v53 = *v42;
        if ( v53 > *((_DWORD *)v3 + 5) )
          *((_DWORD *)v3 + 5) = v53;
        v33 = (int)&Streamc->_ptr + 1 < *((_DWORD *)v3 + 3);
        Streamc = (FILE *)((char *)Streamc + 1);
        v58 += 44;
      }
      while ( v33 );
      v11 = v3 + 1;
    }
    v3[2] = (double)*((int *)v3 + 5) * *v11;
  }
  if ( dword_7F5E68 )
    sub_5BE8AE();
  if ( dword_7F5E6C )
    sub_5BE8AE();
  return 0;
}
