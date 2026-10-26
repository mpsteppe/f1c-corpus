int __thiscall sub_596220(_DWORD *this)
{
  int v1; // ebx
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int v5; // eax
  char *v6; // esi
  int v7; // edi
  int v8; // esi
  _DWORD *v9; // eax
  _DWORD *v10; // ebp
  _DWORD *v11; // edi
  int v12; // esi
  int i; // ebp
  int v14; // esi
  int v16; // eax
  char *v17; // esi
  int v18; // edi
  int v19; // eax
  char *v20; // esi
  int v21; // edi
  int v22; // eax
  char *v23; // esi
  int v24; // edi
  int v25; // eax
  char *v26; // esi
  int v27; // edi
  _DWORD *v28; // eax
  int v29; // esi
  int *v30; // eax
  _DWORD *v31; // edi
  int v32; // esi
  int *v33; // eax
  _DWORD *v34; // edi
  int v35; // esi
  int *v36; // eax
  _DWORD *v37; // edi
  int v38; // esi
  int *v39; // eax
  _DWORD *v40; // edi
  _DWORD *v41; // ebx
  int v42; // eax
  _DWORD *v43; // ebp
  int v44; // eax
  void *v45; // eax
  unsigned int v46; // edx
  int v47; // edi
  _DWORD *v48; // esi
  void *v49; // eax
  int v50; // [esp+10h] [ebp-30h]
  int v51; // [esp+14h] [ebp-2Ch]
  int v52; // [esp+18h] [ebp-28h]
  int v53; // [esp+1Ch] [ebp-24h]
  int v54; // [esp+20h] [ebp-20h]
  int v55; // [esp+24h] [ebp-1Ch]
  int v56; // [esp+28h] [ebp-18h]
  int v57; // [esp+2Ch] [ebp-14h]
  int v58; // [esp+30h] [ebp-10h]
  int v59; // [esp+34h] [ebp-Ch]
  _DWORD *v60; // [esp+38h] [ebp-8h]
  int v61; // [esp+3Ch] [ebp-4h]

  v1 = (int)this;
  v2 = this[87];
  v60 = (_DWORD *)v1;
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 - 4);
    v4 = 3 * v3;
    v5 = v3 - 1;
    v6 = (char *)(v2 + 8 * v4);
    if ( v5 >= 0 )
    {
      v7 = v5 + 1;
      do
      {
        v6 -= 24;
        nullsub_6(v6);
        --v7;
      }
      while ( v7 );
    }
    sub_5BE8AE();
    *(_DWORD *)(v1 + 348) = 0;
    *(_DWORD *)(v1 + 344) = 0;
  }
  v8 = *(_DWORD *)(v1 + 104);
  v9 = operator new(24 * v8 + 4);
  if ( v9 )
  {
    v10 = v9 + 1;
    *v9 = v8;
    v11 = v9 + 1;
    if ( v8 - 1 >= 0 )
    {
      do
      {
        sub_594070(v11);
        v11 += 6;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v10 = 0;
  }
  v12 = *(_DWORD *)(v1 + 260);
  *(_DWORD *)(v1 + 348) = v10;
  for ( i = 0; v12; v12 = *(_DWORD *)(v12 + 260) )
  {
    if ( *(_DWORD *)(v12 + 236) )
      sub_59E9C0();
  }
  if ( *(_DWORD *)(v1 + 268) )
    sub_59E9C0();
  v14 = *(_DWORD *)(v1 + 268);
  if ( v14 )
  {
    do
    {
      if ( sub_596FA0(v14, 0) )
        return -1;
      if ( ++i % 2 )
      {
        InterlockedDecrement(&Addend);
        sub_598180(0);
      }
      v14 = *(_DWORD *)(v14 + 76);
    }
    while ( v14 );
    i = 0;
  }
  if ( (*(_BYTE *)(v1 + 240) & 4) == 0 )
  {
    if ( *(_DWORD *)(v1 + 276) )
    {
      if ( sub_59A570() )
        return -1;
      sub_59A5E0(*(_DWORD *)(v1 + 276));
    }
    if ( sub_5969C0(v1) )
      return -1;
    sub_597C70(v1);
    sub_597DE0(v1);
  }
  v16 = *(_DWORD *)(v1 + 456);
  if ( v16 )
  {
    v17 = (char *)(v16 + 528 * *(_DWORD *)(v16 - 4));
    if ( *(_DWORD *)(v16 - 4) - 1 >= 0 )
    {
      v18 = *(_DWORD *)(v16 - 4);
      do
      {
        v17 -= 528;
        sub_5AEA20(v17);
        --v18;
      }
      while ( v18 );
    }
    sub_5BE8AE();
    i = 0;
    *(_DWORD *)(v1 + 456) = 0;
    *(_DWORD *)(v1 + 452) = 0;
  }
  v19 = *(_DWORD *)(v1 + 464);
  if ( v19 )
  {
    v20 = (char *)(v19 + 528 * *(_DWORD *)(v19 - 4));
    if ( *(_DWORD *)(v19 - 4) - 1 >= 0 )
    {
      v21 = *(_DWORD *)(v19 - 4);
      do
      {
        v20 -= 528;
        sub_5AEA20(v20);
        --v21;
      }
      while ( v21 );
    }
    sub_5BE8AE();
    i = 0;
    *(_DWORD *)(v1 + 464) = 0;
    *(_DWORD *)(v1 + 460) = 0;
  }
  v22 = *(_DWORD *)(v1 + 472);
  if ( v22 )
  {
    v23 = (char *)(v22 + 528 * *(_DWORD *)(v22 - 4));
    if ( *(_DWORD *)(v22 - 4) - 1 >= 0 )
    {
      v24 = *(_DWORD *)(v22 - 4);
      do
      {
        v23 -= 528;
        sub_5AEA20(v23);
        --v24;
      }
      while ( v24 );
    }
    sub_5BE8AE();
    i = 0;
    *(_DWORD *)(v1 + 472) = 0;
    *(_DWORD *)(v1 + 468) = 0;
  }
  v25 = *(_DWORD *)(v1 + 480);
  if ( v25 )
  {
    v26 = (char *)(v25 + 528 * *(_DWORD *)(v25 - 4));
    if ( *(_DWORD *)(v25 - 4) - 1 >= 0 )
    {
      v27 = *(_DWORD *)(v25 - 4);
      do
      {
        v26 -= 528;
        sub_5AEA20(v26);
        --v27;
      }
      while ( v27 );
    }
    sub_5BE8AE();
    i = 0;
    *(_DWORD *)(v1 + 480) = 0;
    *(_DWORD *)(v1 + 476) = 0;
  }
  v28 = *(_DWORD **)(v1 + 276);
  *(_DWORD *)(v1 + 68) = v28[5];
  v29 = *(_DWORD *)(v1 + 68);
  *(_DWORD *)(v1 + 72) = v28[6];
  *(_DWORD *)(v1 + 76) = v28[7];
  *(_DWORD *)(v1 + 80) = v28[8];
  *(_DWORD *)(v1 + 452) = v29;
  if ( v29 > 0 )
  {
    v30 = (int *)operator new(528 * v29 + 4);
    if ( v30 )
    {
      i = (int)(v30 + 1);
      *v30 = v29;
      v31 = v30 + 1;
      if ( v29 - 1 >= 0 )
      {
        do
        {
          sub_5AE9E0(v31);
          v31 += 132;
          --v29;
        }
        while ( v29 );
      }
    }
    *(_DWORD *)(v1 + 456) = i;
    i = 0;
  }
  v32 = *(_DWORD *)(v1 + 72);
  *(_DWORD *)(v1 + 460) = v32;
  if ( v32 > 0 )
  {
    v33 = (int *)operator new(528 * v32 + 4);
    if ( v33 )
    {
      i = (int)(v33 + 1);
      *v33 = v32;
      v34 = v33 + 1;
      if ( v32 - 1 >= 0 )
      {
        do
        {
          sub_5AE9E0(v34);
          v34 += 132;
          --v32;
        }
        while ( v32 );
      }
    }
    *(_DWORD *)(v1 + 464) = i;
    i = 0;
  }
  v35 = *(_DWORD *)(v1 + 76);
  *(_DWORD *)(v1 + 468) = v35;
  if ( v35 > 0 )
  {
    v36 = (int *)operator new(528 * v35 + 4);
    if ( v36 )
    {
      i = (int)(v36 + 1);
      *v36 = v35;
      v37 = v36 + 1;
      if ( v35 - 1 >= 0 )
      {
        do
        {
          sub_5AE9E0(v37);
          v37 += 132;
          --v35;
        }
        while ( v35 );
      }
    }
    *(_DWORD *)(v1 + 472) = i;
    i = 0;
  }
  v38 = *(_DWORD *)(v1 + 80);
  *(_DWORD *)(v1 + 476) = v38;
  if ( v38 > 0 )
  {
    v39 = (int *)operator new(528 * v38 + 4);
    if ( v39 )
    {
      i = (int)(v39 + 1);
      *v39 = v38;
      v40 = v39 + 1;
      if ( v38 - 1 >= 0 )
      {
        do
        {
          sub_5AE9E0(v40);
          v40 += 132;
          --v38;
        }
        while ( v38 );
      }
    }
    *(_DWORD *)(v1 + 480) = i;
  }
  v61 = *(_DWORD *)(v1 + 452) + *(_DWORD *)(v1 + 460) + *(_DWORD *)(v1 + 468) + *(_DWORD *)(v1 + 476);
  v56 = 0;
  v58 = 0;
  v52 = 0;
  v54 = 0;
  v51 = 0;
  if ( v61 > 0 )
  {
    v59 = 0;
    v57 = 0;
    v55 = 0;
    v53 = 0;
    while ( 1 )
    {
      v41 = (_DWORD *)sub_59A620(v51);
      v42 = v41[39];
      if ( (v42 & 0x20) != 0 )
      {
        if ( (v42 & 0x100) != 0 )
        {
          v41[40] = v52;
          v43 = (_DWORD *)(v53 + v60[118]);
          ++v52;
          v53 += 528;
        }
        else
        {
          v41[40] = v54;
          v43 = (_DWORD *)(v55 + v60[120]);
          ++v54;
          v55 += 528;
        }
      }
      else if ( (v42 & 0x100) != 0 )
      {
        v41[40] = v56;
        v43 = (_DWORD *)(v57 + v60[114]);
        ++v56;
        v57 += 528;
      }
      else
      {
        v41[40] = v58;
        v43 = (_DWORD *)(v59 + v60[116]);
        ++v58;
        v59 += 528;
      }
      v44 = sub_49D1E0(v41);
      v43[129] = v44;
      if ( v44 > 0 )
      {
        v45 = operator new(16 * v44);
        v46 = 16 * v43[129];
        v43[131] = v45;
        memset(v45, 0, v46);
        *v43 = 256;
        v50 = 0;
        if ( (int)v41[43] > 0 )
          break;
      }
LABEL_123:
      if ( ++v51 >= v61 )
      {
        v1 = (int)v60;
        goto LABEL_125;
      }
    }
    v47 = v41[44] + 64;
    v48 = v43 + 10;
    while ( 1 )
    {
      v49 = *(void **)(v47 + 32);
      if ( (int)v49 <= (int)&unk_800000 )
        break;
      if ( v49 == &unk_804000 )
        goto LABEL_101;
LABEL_102:
      if ( (v41[39] & 0x800) != 0 )
        *v43 |= 4u;
      if ( (v41[39] & 0x40) != 0 )
        *v43 |= 0x400u;
      if ( (*(_BYTE *)v47 & 0xC) != 0 )
        v48[3] = 1;
      if ( (v41[39] & 0x20) != 0 )
      {
        *v43 |= 0x800u;
        *v48 = 2;
      }
      if ( *(char *)v47 < 0 )
      {
        *v43 |= 1u;
        *v48 = 3;
      }
      if ( (*(_DWORD *)v47 & 0x200) != 0 )
        *(v48 - 1) = 6;
      v48[4] = 0;
      if ( (*(_DWORD *)v47 & 0x400) != 0 )
      {
        v48[4] = 1;
      }
      else if ( (*(_DWORD *)v47 & 0x1000) != 0 )
      {
        v48[4] = 2;
      }
      v48[5] = 0;
      if ( (*(_DWORD *)v47 & 0x800) != 0 )
      {
        v48[5] = 1;
      }
      else if ( (*(_DWORD *)v47 & 0x2000) != 0 )
      {
        v48[5] = 2;
      }
      v48[6] = *(_DWORD *)(v47 + 72);
      v47 += 148;
      v48 += 16;
      if ( ++v50 >= v41[43] )
        goto LABEL_123;
    }
    if ( v49 != &unk_800000 )
    {
      if ( v49 == (void *)0x100000 )
      {
        if ( v50 <= 0 || v50 % sub_5A8470(&unk_7E6B48) )
        {
          switch ( *(_DWORD *)(v47 + 36) )
          {
            case 1:
              *(v48 - 1) = 1;
              *v48 = 2;
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
            case 2:
              *(v48 - 1) = 2;
              *v48 = 2;
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
            case 3:
              *(v48 - 1) = 3;
              *v48 = 4;
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
            case 4:
              *v48 = 2;
              *(v48 - 1) = 4;
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
            case 5:
              *(v48 - 1) = 9;
              *v48 = 4;
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
            case 6:
              *(v48 - 1) = 10;
              *v48 = 4;
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
            case 7:
              *(v48 - 1) = 11;
              *v48 = 4;
              goto LABEL_99;
            default:
LABEL_99:
              v48[1] = *(_DWORD *)(v47 + 44);
              break;
          }
        }
        else
        {
          *(v48 - 1) = 1;
          *v48 = 2;
          v48[1] = *(_DWORD *)(v47 + 44);
        }
      }
      else if ( v49 == (void *)0x400000 )
      {
        *v43 |= 0x800u;
        *(v48 - 1) = 2;
        *v48 = 2;
        v48[1] = 0;
      }
      goto LABEL_102;
    }
LABEL_101:
    *(v48 - 1) = 8;
    *v48 = 1;
    *(_DWORD *)(v47 + 44) = 1;
    v48[1] = 1;
    goto LABEL_102;
  }
LABEL_125:
  sub_592800();
  sub_5920F0((void *)v1);
  return 0;
}
