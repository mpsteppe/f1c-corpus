int __thiscall sub_5AF520(int this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v8; // edi
  char *v9; // eax
  _DWORD *v10; // eax
  int v11; // edi
  _DWORD *v12; // ebp
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // edi
  char *v16; // eax
  char *v17; // eax
  int v18; // edi
  char *v19; // ebp
  int v20; // edi
  void *v21; // edi
  unsigned int v22; // edx
  void *v23; // eax
  void *v24; // eax
  int v25; // edx
  int v26; // ecx
  int v27; // ebp
  int v28; // eax
  int v29; // edx
  void *v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // edi
  int v34; // edx
  _DWORD *v35; // ecx
  int v36; // edi
  _DWORD *v37; // eax
  bool v38; // cc
  _DWORD *v39; // ecx
  int v40; // eax
  int v41; // edx
  int v42; // eax
  int v43; // edi
  int v44; // eax
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  int v48; // eax
  int v49; // edx
  _DWORD *v50; // eax
  int v51; // ecx
  int v52; // edx
  int v53; // ecx
  int v54; // edi
  int v55; // edx
  _WORD *v56; // eax
  int v57; // ecx
  __int16 v58; // dx
  int v59; // ecx
  void *v60; // edi
  int v61; // edi
  int v62; // ebp
  unsigned int v63; // [esp-8h] [ebp-34h]
  int v64; // [esp+10h] [ebp-1Ch]
  int v65; // [esp+10h] [ebp-1Ch]
  int v66; // [esp+10h] [ebp-1Ch]
  int v67; // [esp+10h] [ebp-1Ch]
  int v68; // [esp+14h] [ebp-18h]
  int v69; // [esp+14h] [ebp-18h]
  int v70; // [esp+14h] [ebp-18h]
  int v71; // [esp+18h] [ebp-14h]
  __int16 v72; // [esp+18h] [ebp-14h]
  _DWORD *v73; // [esp+1Ch] [ebp-10h]
  void *v74; // [esp+1Ch] [ebp-10h]
  int v75; // [esp+1Ch] [ebp-10h]
  void *v76; // [esp+20h] [ebp-Ch]
  int v77; // [esp+24h] [ebp-8h]
  _DWORD *v78; // [esp+28h] [ebp-4h]

  if ( (*(_BYTE *)(a2 + 32) & 8) == 0 )
    return 0;
  v3 = operator new(0x240u);
  if ( v3 )
    v4 = sub_59D4D0(v3);
  else
    v4 = 0;
  v76 = v4;
  if ( sub_59D610((char *)v4, aPtemp, a2 + 56) )
  {
    if ( v4 )
    {
      sub_59D5F0(v4);
      sub_5BE8AE();
    }
    sub_591C60(this, -1, aSomeMtsInitErr);
    return -1;
  }
  v6 = (_DWORD *)sub_59EFF0(v4, 0);
  v78 = v6;
  if ( (BYTE1(v6[5]) & 0x80u) != 0 )
  {
    sub_59B050((int)v6, 0);
    v7 = (_DWORD *)sub_598170((_DWORD *)dword_7E8E5C);
    if ( v7 && sub_59A570(v7) )
    {
      sub_59D650(v4);
      if ( v4 )
      {
        sub_59D5F0(v4);
        sub_5BE8AE();
      }
      return -1;
    }
    strcpy((char *)this, (const char *)a2);
    v8 = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(this + 44) = v8;
    v9 = (char *)operator new((v8 << 7) + 4);
    if ( v9 )
    {
      v10 = v9 + 4;
      *(v10 - 1) = v8;
      v11 = v8 - 1;
      v73 = v10;
      v12 = v10;
      if ( v11 >= 0 )
      {
        v13 = v11 + 1;
        do
        {
          sub_5AF260(v12);
          v12 += 32;
          --v13;
        }
        while ( v13 );
      }
      v14 = v73;
    }
    else
    {
      v14 = 0;
    }
    *(_DWORD *)(this + 52) = v14;
    v15 = v6[70];
    *(_DWORD *)(this + 76) = v15;
    v16 = (char *)operator new((v15 << 6) + 4);
    if ( v16 )
    {
      v17 = v16 + 4;
      *((_DWORD *)v17 - 1) = v15;
      v18 = v15 - 1;
      v74 = v17;
      v19 = v17;
      if ( v18 >= 0 )
      {
        v20 = v18 + 1;
        do
        {
          sub_5918B0(v19);
          v19 += 64;
          --v20;
        }
        while ( v20 );
      }
      v21 = v74;
    }
    else
    {
      v21 = 0;
    }
    v22 = *(_DWORD *)(this + 76) << 6;
    *(_DWORD *)(this + 80) = v21;
    memset(v21, 0, v22);
    if ( (*(_BYTE *)(a2 + 32) & 0x10) != 0 )
      *(_DWORD *)(this + 32) = 16;
    if ( (*(_BYTE *)(a2 + 32) & 0x20) != 0 )
      *(_DWORD *)(this + 32) = 32;
    v23 = operator new(4 * *(_DWORD *)(this + 44));
    v63 = 4 * *(_DWORD *)(this + 44);
    *(_DWORD *)(this + 64) = v23;
    v24 = operator new(v63);
    v25 = *(_DWORD *)(this + 32);
    v26 = *(_DWORD *)(this + 76);
    *(_DWORD *)(this + 60) = v24;
    *(_DWORD *)(this + 32) = v25 | 8;
    *(_DWORD *)(this + 36) = 0;
    *(_DWORD *)(this + 40) = 0;
    v75 = 0;
    if ( v26 > 0 )
    {
      v27 = 0;
      do
      {
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27) &= ~0x10u;
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 4) = *(_DWORD *)(v6[71] + v27 + 4);
        sub_5997A0(*(_DWORD **)(*(_DWORD *)(this + 80) + v27 + 4));
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 8) = *(_DWORD *)(this + 44) * *(_DWORD *)(v6[71] + v27 + 8);
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 16) = *(_DWORD *)(this + 44) * *(_DWORD *)(v6[71] + v27 + 16);
        v28 = *(_DWORD *)(this + 80) + v27;
        v29 = *(_DWORD *)(this + 40);
        *(_DWORD *)(this + 36) += *(_DWORD *)(v28 + 8);
        *(_DWORD *)(this + 40) = *(_DWORD *)(v28 + 16) + v29;
        v30 = *(char *)(a2 + 32) >= 0
            ? operator new(36 * *(_DWORD *)(v6[71] + v27 + 8))
            : operator new(36 * *(_DWORD *)(v28 + 8));
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 12) = v30;
        *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 20) = operator new(2 * *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 16));
        if ( *(char *)(a2 + 32) >= 0 )
        {
          v39 = *(_DWORD **)(*(_DWORD *)(this + 80) + v27 + 12);
          v40 = v6[71] + v27;
          v65 = 0;
          if ( *(int *)(v40 + 8) > 0 )
          {
            v41 = 0;
            do
            {
              v42 = *(_DWORD *)(v40 + 12);
              v43 = *(_DWORD *)(v42 + v41);
              v44 = v41 + v42;
              *v39 = v43;
              v39[1] = *(_DWORD *)(v44 + 4);
              v39[2] = *(_DWORD *)(v44 + 8);
              v39[6] = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v41 + 24) | 0xFF000000;
              v39 += 9;
              v40 = v27 + v6[71];
              v41 += 48;
              ++v65;
            }
            while ( v65 < *(_DWORD *)(v40 + 8) );
          }
        }
        else
        {
          v31 = *(_DWORD *)(this + 44);
          *(_DWORD *)(this + 32) |= 0x80u;
          v68 = 0;
          if ( v31 > 0 )
          {
            do
            {
              v32 = v6[71];
              v33 = *(_DWORD *)(v32 + v27 + 8);
              v34 = v27 + v32;
              v35 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 12) + 36 * v68 * v33);
              v64 = 0;
              if ( v33 > 0 )
              {
                v36 = 0;
                v71 = 0;
                do
                {
                  v37 = (_DWORD *)(v36 + *(_DWORD *)(v34 + 12));
                  *v35 = *v37;
                  v35[1] = v37[1];
                  v35[2] = v37[2];
                  v35[6] = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v71 + 24) | 0xFF000000;
                  v35 += 9;
                  v36 = v71 + 48;
                  v38 = ++v64 < *(_DWORD *)(v34 + 8);
                  v71 += 48;
                }
                while ( v38 );
              }
              ++v68;
            }
            while ( v68 < *(_DWORD *)(this + 44) );
          }
        }
        if ( *(char *)(a2 + 32) < 0 )
          *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 56) = 32;
        else
          *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 56) = 34;
        v45 = *(_DWORD *)(this + 80);
        v46 = *(_DWORD *)(v45 + v27 + 60);
        v47 = v27 + v45;
        if ( v46 > 0 )
          *(_DWORD *)(v47 + 56) |= 0x1000u;
        if ( sub_5A7A90(dword_7E6B48, (_DWORD *)(v27 + *(_DWORD *)(this + 80))) )
          return -1;
        if ( *(char *)(a2 + 32) >= 0 )
        {
          *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 8) = *(_DWORD *)(v6[71] + v27 + 8);
          *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 16) = *(_DWORD *)(v6[71] + v27 + 16);
        }
        sub_5A7E60((_DWORD *)(v27 + *(_DWORD *)(this + 80)), 12);
        v48 = 0;
        v66 = 0;
        if ( *(int *)(this + 44) > 0 )
        {
          v69 = 0;
          do
          {
            *(_DWORD *)(v69 + *(_DWORD *)(this + 52) + 4) = v48;
            v49 = *(_DWORD *)(v6[71] + v27 + 8);
            if ( v49 > 0 )
            {
              v50 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 32)
                             + ((v66 * *(_DWORD *)(v6[71] + v27 + 8)) << 6)
                             + 36);
              v51 = 0;
              do
              {
                *(v50 - 1) = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v51 + 32);
                *v50 = *(_DWORD *)(*(_DWORD *)(v6[71] + v27 + 12) + v51 + 36);
                v50 += 16;
                v51 += 48;
                --v49;
              }
              while ( v49 );
            }
            v48 = v66 + 1;
            v38 = ++v66 < *(_DWORD *)(this + 44);
            v69 += 128;
          }
          while ( v38 );
        }
        v52 = v6[71];
        v53 = *(_DWORD *)(v52 + v27 + 8);
        v54 = *(_DWORD *)(v52 + v27 + 16);
        v55 = 0;
        v72 = v53;
        v77 = v54;
        v67 = 0;
        if ( *(int *)(this + 44) > 0 )
        {
          v70 = 0;
          do
          {
            v56 = (_WORD *)(v70 + *(_DWORD *)(*(_DWORD *)(this + 80) + v27 + 20));
            v57 = 0;
            if ( v54 > 0 )
            {
              v58 = v72 * v55;
              do
              {
                *v56 = v58 + *(_WORD *)(*(_DWORD *)(v6[71] + v27 + 20) + 2 * v57);
                v54 = v77;
                ++v56;
                ++v57;
              }
              while ( v57 < v77 );
              v55 = v67;
            }
            v67 = ++v55;
            v70 += 2 * v54;
          }
          while ( v55 < *(_DWORD *)(this + 44) );
        }
        v59 = *(_DWORD *)(this + 80);
        v60 = *(void **)(v59 + v27 + 40);
        if ( v60 )
        {
          qmemcpy(v60, *(const void **)(v59 + v27 + 20), 2 * *(_DWORD *)(this + 44) * *(_DWORD *)(v59 + v27 + 16));
          v6 = v78;
        }
        sub_5A7EC0((_DWORD *)(v27 + *(_DWORD *)(this + 80)), 12);
        v27 += 64;
      }
      while ( ++v75 < *(_DWORD *)(this + 76) );
    }
    v61 = 0;
    if ( (int)v6[70] > 0 )
    {
      v62 = 0;
      do
      {
        sub_5A7DD0(dword_7E6B48, (_DWORD *)(v62 + v6[71]));
        ++v61;
        v62 += 64;
      }
      while ( v61 < v6[70] );
    }
    sub_5BE8AE();
    if ( v76 )
    {
      sub_59D5F0(v76);
      sub_5BE8AE();
    }
    *(_DWORD *)(this + 68) = operator new(4 * *(_DWORD *)(this + 76));
    *(_DWORD *)(this + 72) = operator new(4 * *(_DWORD *)(this + 76));
    return 0;
  }
  sub_59D650(v4);
  if ( v4 )
  {
    sub_59D5F0(v4);
    sub_5BE8AE();
  }
  sub_591C60(this, -1, aParticleMustBe);
  return -1;
}
