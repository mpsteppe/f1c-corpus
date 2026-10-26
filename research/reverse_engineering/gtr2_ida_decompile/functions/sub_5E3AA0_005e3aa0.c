int __thiscall sub_5E3AA0(char *this, float a2, const char *a3, float a4, char a5)
{
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  _DWORD *v9; // eax
  _BYTE *v10; // edi
  unsigned int v11; // eax
  char v12; // cl
  int v13; // eax
  char *v14; // eax
  int v15; // edx
  char v16; // cl
  int v17; // ecx
  int v18; // eax
  _DWORD *v19; // eax
  unsigned int v20; // eax
  char v21; // cl
  int v22; // eax
  char *v23; // eax
  int v24; // edx
  char v25; // cl
  int v26; // eax
  int *v27; // edi
  int v28; // ebp
  unsigned __int64 v29; // rax
  void *v30; // eax
  int v31; // eax
  void *v32; // ebp
  char *v34; // edi
  char *v35; // eax
  char v36; // cl
  int v37; // ecx
  char *v38; // edi
  int v40; // eax
  int v41; // edi
  _DWORD *v42; // eax
  char *v43; // ebp
  char *v44; // eax
  int v45; // ecx
  int v46; // ebx
  int v47; // ebp
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  int v51; // eax
  int v52; // edx
  int v53; // edi
  int v54; // eax
  int v55; // edx
  char *v56; // eax
  char v57; // cl
  char *v58; // eax
  char v59; // cl
  int v60; // eax
  int v61; // eax
  char v62; // cl
  int v63; // eax
  _BYTE *v64; // eax
  char v65; // cl
  char *v66; // eax
  char *v67; // edi
  void *v68; // edi
  int v69; // ebx
  int v70; // ebp
  int v71; // edi
  char *v72; // eax
  char *v73; // edi
  int v74; // [esp+1Ch] [ebp-56Ch]
  int v75; // [esp+40h] [ebp-548h]
  int v76; // [esp+44h] [ebp-544h]
  int v77; // [esp+48h] [ebp-540h]
  int v78; // [esp+48h] [ebp-540h]
  char *v79; // [esp+4Ch] [ebp-53Ch]
  int v80; // [esp+50h] [ebp-538h]
  char *v81; // [esp+54h] [ebp-534h]
  int v82; // [esp+58h] [ebp-530h]
  char v83[32]; // [esp+5Ch] [ebp-52Ch] BYREF
  char v84[256]; // [esp+7Ch] [ebp-50Ch] BYREF
  char String[256]; // [esp+17Ch] [ebp-40Ch] BYREF
  char v86[255]; // [esp+27Ch] [ebp-30Ch] BYREF
  char v87; // [esp+37Bh] [ebp-20Dh] BYREF
  char v88[256]; // [esp+37Ch] [ebp-20Ch] BYREF
  char Buffer[256]; // [esp+47Ch] [ebp-10Ch] BYREF
  int v90; // [esp+584h] [ebp-4h]

  v6 = *((_DWORD *)this + 24);
  v7 = 0;
  v75 = 0;
  v76 = 0;
  switch ( v6 )
  {
    case 15:
      return 0;
    case 14:
      v8 = sub_5E9100("CUBENORMALIZER", 1);
      *((_DWORD *)this + 55) = v8;
      if ( !v8 )
      {
        v9 = operator new(0xDCu);
        v90 = 0;
        if ( v9 )
        {
          v7 = (int)(v9 + 1);
          *v9 = 1;
          sub_630A11(v9 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
        }
        v10 = (_BYTE *)(v7 + 140);
        v90 = -1;
        *((_DWORD *)this + 55) = v7;
        sprintf((char *const)(v7 + 140), "%s", "CUBENORMALIZER");
        v11 = strlen((const char *)(v7 + 140));
        v12 = *(_BYTE *)(v11 + v7 + 140 - 1);
        v13 = v11 - 1;
        if ( v12 != 92 )
        {
          do
            --v13;
          while ( v13 >= 0 && v10[v13] != 92 );
        }
        v14 = &v10[v13 + 1];
        v15 = v10 - v14;
        do
        {
          v16 = *v14;
          v14[v15] = *v14;
          ++v14;
        }
        while ( v16 );
        _strupr((char *)(v7 + 140));
        if ( !sub_5E72D0(256, 256, 8, 1, 20) )
        {
          (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 516))(dword_FB27A4, v7);
          sub_5FDFB0(*((_DWORD *)this + 55), 0);
          goto LABEL_107;
        }
        v17 = v7;
        goto LABEL_13;
      }
      goto LABEL_107;
    case 9:
      sprintf(Buffer, "SPECPOWER%.1f", a4);
      v18 = sub_5E9100(Buffer, 1);
      *((_DWORD *)this + 55) = v18;
      if ( v18 )
        goto LABEL_107;
      v19 = operator new(0xDCu);
      v90 = 1;
      if ( v19 )
      {
        v7 = (int)(v19 + 1);
        *v19 = 1;
        sub_630A11(v19 + 1, 216, 1, sub_5E2AC0, j_j_nullsub_7);
      }
      v10 = (_BYTE *)(v7 + 140);
      v90 = -1;
      *((_DWORD *)this + 55) = v7;
      sprintf((char *const)(v7 + 140), "SPECPOWER%.1f", a4);
      v20 = strlen((const char *)(v7 + 140));
      v21 = *(_BYTE *)(v20 + v7 + 140 - 1);
      v22 = v20 - 1;
      if ( v21 != 92 )
      {
        do
          --v22;
        while ( v22 >= 0 && v10[v22] != 92 );
      }
      v23 = &v10[v22 + 1];
      v24 = v10 - v23;
      do
      {
        v25 = *v23;
        v23[v24] = *v23;
        ++v23;
      }
      while ( v25 );
      _strupr((char *)(v7 + 140));
      v26 = sub_5E72D0(1024, 1, 8, 1, 4);
      v17 = v7;
      if ( !v26 )
      {
        v27 = (int *)sub_5E6E70(4, 0, 2);
        if ( v27 )
        {
          v28 = 0;
          v77 = 0;
          do
          {
            v29 = (unsigned __int64)(pow((double)v77 * 0.0009765625, a4) * 256.0);
            *v27++ = (unsigned __int8)v29
                   | (((unsigned __int8)v29 | (((unsigned __int8)v29 | ((unsigned __int8)v29 << 8)) << 8)) << 8);
            v77 = ++v28;
          }
          while ( v28 < 1024 );
          sub_5E6EA0(4, 0, 2);
          sub_5FDFB0(*((_DWORD *)this + 55), 0);
        }
        goto LABEL_107;
      }
LABEL_13:
      sub_5E6DD0(v17);
      *v10 = 0;
      sub_5D8C80(v7, (char *)0xFFFFFFFF, "Error initializing texture surface for %s", (char)v10);
      goto LABEL_107;
    case 99:
      return 0;
  }
  if ( *((_DWORD *)this + 21) == 7 )
  {
    v30 = operator new(0x114u);
    v90 = 2;
    if ( v30 )
      v31 = sub_5F4610(v30);
    else
      v31 = 0;
    v90 = -1;
    *((_DWORD *)this + 56) = v31;
    if ( sub_5F4640(v31, (int)(this + 12), 0, 0) )
    {
      v32 = (void *)*((_DWORD *)this + 56);
      if ( v32 )
      {
        j_nullsub_7(*((void **)this + 56));
        j__free(v32);
      }
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing video file %s", (_BYTE)this + 12);
      return -1;
    }
    *(_DWORD *)this |= 0x40000u;
  }
  else if ( *((int *)this + 1) > 1 )
  {
    sub_5E9670(this);
  }
  v34 = this + 12;
  sub_5E7FB0((int)(this + 12), String, 1);
  if ( byte_FB2754 && (*(_DWORD *)this & 0xC) != 0 )
  {
    if ( (*(_DWORD *)this & 0x10) != 0 )
      *((_DWORD *)this + 34) = 1;
    else
      *((_DWORD *)this + 34) = (*(_DWORD *)this & 0x20u) >> 4;
  }
  else
  {
    *(_DWORD *)this &= 0xFFFFFFF3;
    *((_DWORD *)this + 34) = 0;
  }
  v35 = this + 12;
  v79 = (char *)(v88 - v34);
  do
  {
    v36 = *v35;
    v35[v88 - v34] = *v35;
    ++v35;
  }
  while ( v36 );
  v37 = *((_DWORD *)this + 1);
  if ( v37 > 1 )
  {
    v38 = &v87;
    while ( *++v38 )
      ;
    strcpy(v38, "00");
  }
  v40 = sub_5E9100(v88, v37);
  *((_DWORD *)this + 55) = v40;
  if ( v40 && (*(_DWORD *)this & 0x100) == 0 )
  {
LABEL_107:
    ++*(_DWORD *)(*((_DWORD *)this + 55) + 108);
    return 0;
  }
  v41 = *((_DWORD *)this + 1);
  v42 = operator new(216 * v41 + 4);
  v90 = 3;
  if ( v42 )
  {
    v43 = (char *)(v42 + 1);
    *v42 = v41;
    sub_630A11(v42 + 1, 216, v41, sub_5E2AC0, j_j_nullsub_7);
    v44 = v43;
  }
  else
  {
    v44 = 0;
  }
  v45 = *((_DWORD *)this + 1);
  v46 = 0;
  v90 = -1;
  *((_DWORD *)this + 55) = v44;
  v78 = 0;
  if ( v45 <= 0 )
  {
LABEL_104:
    v64 = this + 12;
    do
    {
      v65 = v64[(_DWORD)v79];
      *v64++ = v65;
    }
    while ( v65 );
    sub_5FDFB0(*((_DWORD *)this + 55), 0);
    goto LABEL_107;
  }
  v80 = v44 - v86 + 140;
  v82 = v44 - v84 + 140;
  v47 = (int)(v44 + 140);
  v81 = (char *)(v83 - v44 - 140);
  while ( 2 )
  {
    *(_DWORD *)(v47 + 68) = v46;
    *(_DWORD *)(v47 + 72) = *((_DWORD *)this + 1);
    if ( byte_FB2754 && (v48 = *(_DWORD *)this, (*(_DWORD *)this & 0xC) != 0) )
    {
      if ( (v48 & 8) != 0 )
      {
        v75 |= 0x400u;
      }
      else if ( (v48 & 4) != 0 )
      {
        v75 |= 0x800u;
      }
    }
    else
    {
      *(_DWORD *)(v47 - 120) = 1;
    }
    v49 = *(_DWORD *)this;
    if ( (*(_DWORD *)this & 1) != 0 )
      v76 |= 1u;
    if ( (v49 & 0x8000) != 0 )
      v76 |= 0x8000u;
    v50 = *((_DWORD *)this + 24);
    if ( v50 == 3 )
      v75 |= 0x80000u;
    switch ( v50 )
    {
      case 4:
      case 10:
        v51 = v75 | 4;
        goto LABEL_81;
      case 11:
        v75 |= 0x14u;
        v76 |= 0x8001u;
        goto LABEL_82;
      case 14:
        v51 = v75 | 0x14;
        goto LABEL_81;
      default:
        if ( (v49 & 2) != 0 )
        {
          v76 |= 0x8003u;
          v75 |= 0x48u;
        }
        v52 = v75 | 4;
        v75 |= 4u;
        if ( (v49 & 0x80u) == 0 )
          goto LABEL_82;
        v51 = v52 | 0x200;
LABEL_81:
        v75 = v51;
LABEL_82:
        if ( *((_DWORD *)this + 21) == 7 )
        {
          v53 = v47 - 140;
          v74 = sub_5F4580(*((_DWORD *)this + 56));
          v54 = sub_5F4570(*((_DWORD *)this + 56));
          if ( sub_5E2E70((char *)(v47 - 140), this + 12, v54, v74, 0, 4, 4, 0) )
          {
            v66 = (char *)*((_DWORD *)this + 55);
            if ( v66 )
            {
              v67 = v66 - 4;
              `eh vector destructor iterator'(v66, 0xD8u, *((_DWORD *)v66 - 1), j_j_nullsub_7);
              j__free(v67);
            }
            v68 = (void *)*((_DWORD *)this + 56);
            if ( v68 )
            {
              j_nullsub_7(*((void **)this + 56));
              j__free(v68);
            }
            sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing video file texture %s", (_BYTE)this + 12);
            goto LABEL_122;
          }
          v46 = v78;
LABEL_94:
          if ( (*(_DWORD *)this & 0x100) != 0 )
          {
            if ( a3 )
            {
              v60 = strlen((const char *)v47);
              if ( v60 > 0 )
              {
                while ( *(_BYTE *)(v60 + v47) != 46 )
                {
                  if ( --v60 <= 0 )
                    goto LABEL_103;
                }
                *(_BYTE *)(v53 + v60 + 140) = 0;
                v61 = v47;
                do
                {
                  v62 = *(_BYTE *)v61;
                  v81[v61] = *(_BYTE *)v61;
                  ++v61;
                }
                while ( v62 );
                sprintf((char *const)v47, "%s%4s%s%c", v83, a3, String, 0);
              }
            }
          }
LABEL_103:
          v81 -= 216;
          v47 += 216;
          v63 = *((_DWORD *)this + 1);
          ++v46;
          v82 += 216;
          v80 += 216;
          v78 = v46;
          if ( v46 >= v63 )
            goto LABEL_104;
          continue;
        }
        if ( *((int *)this + 1) <= 1 )
        {
          sprintf(v84, "%s%s", this + 12, ".DDS");
          sprintf(v86, "%s%s", this + 12, String);
        }
        else
        {
          sprintf(v84, "%s%.2d%s", this + 12, v46, ".DDS");
          sprintf(v86, "%s%.2d%s", this + 12, v46, String);
        }
        v55 = v82;
        v56 = v84;
        do
        {
          v57 = *v56;
          v56[v55] = *v56;
          ++v56;
        }
        while ( v57 );
        v53 = v47 - 140;
        if ( !sub_5E30C0(v47, 0, 0, 0, *((_DWORD *)this + 2), *((_DWORD *)this + 30), v75) )
          goto LABEL_94;
        v58 = v86;
        do
        {
          v59 = *v58;
          v58[v80] = *v58;
          ++v58;
        }
        while ( v59 );
        if ( !sub_5E30C0(v47, 0, 0, 0, *((_DWORD *)this + 2), *((_DWORD *)this + 30), v75) )
          goto LABEL_94;
        if ( v46 > 0 )
        {
          v69 = v78;
          v70 = 0;
          do
          {
            v71 = v70 + *((_DWORD *)this + 55);
            sub_5E6DD0(v71);
            v70 += 216;
            --v69;
            *(_BYTE *)(v71 + 140) = 0;
          }
          while ( v69 );
        }
        v72 = (char *)*((_DWORD *)this + 55);
        if ( v72 )
        {
          v73 = v72 - 4;
          `eh vector destructor iterator'(v72, 0xD8u, *((_DWORD *)v72 - 1), j_j_nullsub_7);
          j__free(v73);
        }
        *((_DWORD *)this + 55) = 0;
        if ( a2 == 0.0 )
          sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error loading texture %s", (_BYTE)this + 12);
        else
          sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error loading texture %s for material %s", (_BYTE)this + 12);
LABEL_122:
        if ( a5 )
          sub_5D8CE0();
        return -1;
    }
  }
}
