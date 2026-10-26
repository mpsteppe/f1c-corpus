int __thiscall sub_5FD5E0(int this, int a2)
{
  int v2; // esi
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  char *v8; // eax
  char v9; // cl
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int v12; // edi
  _DWORD *v13; // ecx
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  _DWORD *v20; // eax
  int v21; // eax
  int v22; // edx
  char *v23; // edi
  char *v24; // esi
  unsigned int v25; // edx
  char *v26; // edi
  unsigned int v27; // ecx
  int v28; // eax
  int v29; // [esp-10h] [ebp-34h]
  char v30; // [esp+0h] [ebp-24h]
  int v31; // [esp+8h] [ebp-1Ch]
  float *v32; // [esp+Ch] [ebp-18h] BYREF
  _DWORD *v33; // [esp+10h] [ebp-14h]
  _DWORD *v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+20h] [ebp-4h]

  v2 = a2;
  if ( *(int *)(a2 + 36) > 0 )
  {
    if ( (*(_DWORD *)a2 & 1) != 0 )
    {
      if ( sub_5E97E0(
             dword_FB27F8,
             (const char *)(a2 + 4),
             &v32,
             *(_DWORD *)(a2 + 312),
             *(_DWORD *)(a2 + 316),
             (const char *)(a2 + 340)) )
      {
        sub_5D8C80(this, (char *)0xFFFFFFFF, "Error creating material %s for particle system", a2 + 4);
        return -1;
      }
      else if ( sub_5E9420((char *)v32) )
      {
        sub_5D8C80(this, (char *)0xFFFFFFFF, "Error loading material %s for particle system", a2 + 4);
        return -1;
      }
      else
      {
        sub_5E8360(v32, 4, *(_DWORD *)(a2 + 324));
        v5 = *(_DWORD *)(a2 + 36);
        *(_DWORD *)(this + 44) = v5;
        v6 = operator new(132 * v5 + 4);
        v34 = v6;
        v35 = 0;
        if ( v6 )
        {
          *v6 = v5;
          v33 = v6 + 1;
          sub_630A11(v6 + 1, 132, v5, sub_5FC790, j_nullsub_7);
          v7 = v33;
        }
        else
        {
          v7 = 0;
        }
        *(_DWORD *)(this + 52) = v7;
        v8 = (char *)(a2 + 4);
        v35 = -1;
        do
        {
          v9 = *v8;
          v8[this - a2] = *v8;
          ++v8;
        }
        while ( v9 );
        _strupr((char *)(this + 4));
        *(_DWORD *)(this + 60) = 1;
        v10 = operator new(0x6Cu);
        v34 = v10;
        v35 = 1;
        if ( v10 )
          v11 = sub_5FC740(v10);
        else
          v11 = 0;
        *(_DWORD *)(this + 64) = v11;
        memset(v11, 0, 0x6Cu);
        v12 = (int)(v11 + 27);
        *(_DWORD *)(*(_DWORD *)(this + 64) + 4) = v32;
        v13 = *(_DWORD **)(*(_DWORD *)(this + 64) + 4);
        v35 = -1;
        sub_5E8E90(v13);
        if ( (*(_BYTE *)(a2 + 312) & 0x20) != 0 )
        {
          **(_DWORD **)(*(_DWORD *)(this + 64) + 4) |= 0x20u;
          sub_5E9620((unsigned __int16)*(_DWORD *)(a2 + 328), *(int *)(a2 + 328) >> 16);
        }
        if ( sub_5E82A0(*(_DWORD **)(*(_DWORD *)(this + 64) + 4), 99) > 0 )
        {
          v12 = *(_DWORD *)(a2 + 332);
          *(_DWORD *)(sub_5E80D0(*(_DWORD **)(*(_DWORD *)(this + 64) + 4), 0) + 120) = v12;
          v29 = *(_DWORD *)(a2 + 336);
          v14 = (_DWORD *)sub_5E80D0(*(_DWORD **)(*(_DWORD *)(this + 64) + 4), 0);
          sub_5E2A20(v14, v29);
        }
        if ( (*(_BYTE *)a2 & 0x10) != 0 )
          *(_DWORD *)this |= 0x810u;
        if ( (*(_BYTE *)a2 & 0x20) != 0 )
          *(_DWORD *)this |= 0x820u;
        if ( (*(_DWORD *)a2 & 0x800) != 0 )
          *(_DWORD *)this |= 0x800u;
        if ( (*(_DWORD *)a2 & 0x1000) != 0 )
          *(_DWORD *)this |= 0x1000u;
        if ( (*(_DWORD *)a2 & 0x200) != 0 )
          *(_DWORD *)this |= 0x600u;
        if ( (*(_BYTE *)a2 & 1) != 0 )
        {
          v15 = *(_DWORD *)this | 1;
          *(_DWORD *)this = v15;
          *(_DWORD *)(this + 36) = 4;
          if ( (v15 & 0x800) != 0 )
            *(_DWORD *)(this + 40) = 6;
          else
            *(_DWORD *)(this + 40) = 12;
          *(_DWORD *)(*(_DWORD *)(this + 64) + 8) = 4 * *(_DWORD *)(this + 44);
          *(_DWORD *)(*(_DWORD *)(this + 64) + 36) = *(_DWORD *)(this + 44) * *(_DWORD *)(this + 40);
          **(_DWORD **)(this + 64) |= 0x4040u;
          v16 = *(_DWORD *)(this + 36);
          *(_DWORD *)(this + 76) = v16;
          *(_DWORD *)(this + 80) = operator new(v16 << 6);
          v17 = *(_DWORD *)(this + 40);
          *(_DWORD *)(this + 84) = v17;
          *(_DWORD *)(this + 88) = operator new(2 * v17);
          v18 = *(_DWORD *)(this + 44) * *(_DWORD *)(this + 76);
          *(_DWORD *)(this + 92) = v18;
          *(_DWORD *)(this + 96) = operator new(v18 << 6);
          v19 = *(_DWORD *)(a2 + 320);
          if ( (v19 & 0xFF000000) == 0 )
            v19 |= 0xFF000000;
          v20 = *(_DWORD **)(this + 80);
          v20[6] = v19;
          *v20 = -1090519040;
          v20[2] = 0;
          v20[3] = 0;
          v20[5] = 0;
          v20[7] = 0;
          v20[8] = 0;
          v20[9] = 0;
          v20 += 16;
          *(v20 - 12) = 1065353216;
          v20 += 16;
          *(v20 - 31) = 1056964608;
          *(v20 - 12) = 1065353216;
          *(v20 - 10) = v19;
          *(v20 - 7) = 1065353216;
          *(v20 - 16) = -1090519040;
          *(v20 - 15) = -1090519040;
          *(v20 - 14) = 0;
          *(v20 - 13) = 0;
          *(v20 - 11) = 0;
          *(v20 - 9) = 0;
          *(v20 - 8) = 0;
          v20[4] = 1065353216;
          v20[6] = v19;
          v20[8] = 1065353216;
          v20[9] = 1065353216;
          *v20 = 1056964608;
          v20[1] = -1090519040;
          v20[2] = 0;
          v20[3] = 0;
          v20[5] = 0;
          v20[7] = 0;
          v20 += 16;
          v20[4] = 1065353216;
          v20[6] = v19;
          v20[8] = 1065353216;
          *v20 = 1056964608;
          v20[1] = 1056964608;
          v20[2] = 0;
          v20[3] = 0;
          v20[5] = 0;
          v20[7] = 0;
          v20[9] = 0;
          **(_WORD **)(this + 88) = 0;
          *(_WORD *)(*(_DWORD *)(this + 88) + 2) = 1;
          *(_WORD *)(*(_DWORD *)(this + 88) + 4) = 2;
          *(_WORD *)(*(_DWORD *)(this + 88) + 6) = 2;
          *(_WORD *)(*(_DWORD *)(this + 88) + 8) = 3;
          v12 = *(_DWORD *)(this + 88);
          *(_WORD *)(v12 + 10) = 0;
          if ( (*(_DWORD *)this & 0x800) == 0 )
          {
            v12 = *(_DWORD *)(this + 88);
            *(_WORD *)(v12 + 12) = 3;
            *(_WORD *)(*(_DWORD *)(this + 88) + 14) = 2;
            *(_WORD *)(*(_DWORD *)(this + 88) + 16) = 0;
            *(_WORD *)(*(_DWORD *)(this + 88) + 18) = 0;
            *(_WORD *)(*(_DWORD *)(this + 88) + 20) = 2;
            *(_WORD *)(*(_DWORD *)(this + 88) + 22) = 1;
          }
        }
        if ( (*(_DWORD *)this & 0x400) != 0 )
        {
          v21 = 0;
          if ( *(int *)(this + 44) > 0 )
          {
            v22 = 0;
            v31 = 0;
            do
            {
              *(_DWORD *)(v22 + *(_DWORD *)(this + 52) + 128) = *(_DWORD *)(this + 96)
                                                              + ((v21 * *(_DWORD *)(this + 36)) << 6);
              v23 = *(char **)(v22 + *(_DWORD *)(this + 52) + 128);
              v24 = *(char **)(this + 80);
              v25 = *(_DWORD *)(this + 36) << 6;
              qmemcpy(v23, v24, 4 * (v25 >> 2));
              v26 = &v23[4 * (v25 >> 2)];
              v27 = v25 & 3;
              qmemcpy(v26, &v24[4 * (v25 >> 2)], v27);
              v12 = (int)&v26[v27];
              ++v21;
              v22 = v31 + 132;
              v31 += 132;
            }
            while ( v21 < *(_DWORD *)(this + 44) );
            v2 = v35;
          }
        }
        *(_DWORD *)(this + 56) = operator new(4 * *(_DWORD *)(this + 44));
        if ( (*(_BYTE *)(v2 + 312) & 4) != 0 )
          v28 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
                  dword_FB27A4,
                  "L0NOLIGHTING",
                  0);
        else
          v28 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
                  dword_FB27A4,
                  "L0NONDIRECTIONALT0",
                  0);
        *(_DWORD *)(this + 72) = v28;
        if ( !v28 )
          *(_DWORD *)(this + 72) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
                                     dword_FB27A4,
                                     "L0NOLIGHTING",
                                     0);
        return -(sub_5FC840((_DWORD *)this, this, v12, 0) != 0);
      }
    }
    else
    {
      sub_5D8C80(this, (char *)0xFFFFFFFF, "Plane is the only supported type for internal particles", v30);
      return -1;
    }
  }
  else
  {
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Invalid number of particles for system", v30);
    return -1;
  }
}
