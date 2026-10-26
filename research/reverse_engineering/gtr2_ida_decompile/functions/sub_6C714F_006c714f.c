int __thiscall sub_6C714F(_DWORD *this)
{
  int result; // eax
  unsigned int v3; // edi
  _DWORD *v4; // esi
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // esi
  int v12; // eax
  _DWORD *v13; // edi
  unsigned int v14; // edx
  bool i; // cf
  int v16; // eax
  int v17; // ecx
  _DWORD *v18; // edx
  unsigned int v19; // eax
  char *v20; // esi
  _BYTE *v21; // edi
  _BYTE *v22; // edi
  char *v23; // esi
  char v24; // cl
  unsigned int v25; // ecx
  int v26; // edx
  _DWORD v27[4]; // [esp+4h] [ebp-60h] BYREF
  _BYTE v28[16]; // [esp+14h] [ebp-50h] BYREF
  _DWORD v29[4]; // [esp+24h] [ebp-40h] BYREF
  int v30; // [esp+34h] [ebp-30h]
  unsigned int v31; // [esp+38h] [ebp-2Ch]
  unsigned int v32; // [esp+3Ch] [ebp-28h]
  int v33; // [esp+40h] [ebp-24h] BYREF
  _DWORD *v34; // [esp+44h] [ebp-20h]
  unsigned int v35; // [esp+48h] [ebp-1Ch]
  char *v36; // [esp+4Ch] [ebp-18h]
  int v37; // [esp+50h] [ebp-14h]
  unsigned int v38; // [esp+54h] [ebp-10h]
  int v39; // [esp+58h] [ebp-Ch]
  unsigned int v40; // [esp+5Ch] [ebp-8h]
  _DWORD *v41; // [esp+60h] [ebp-4h]

  result = sub_6BC1A9(this);
  if ( result >= 0 )
  {
    v40 = 0;
    v32 = this[3];
    v3 = v32;
    if ( v32 )
    {
      while ( 1 )
      {
        v4 = *(_DWORD **)(this[6] + 4 * v40);
        v5 = *v4;
        v6 = (*v4 & 0xFFF00000) == 0;
        v41 = v4;
        if ( !v6 )
          break;
LABEL_24:
        if ( ++v40 >= v3 )
          goto LABEL_25;
      }
      v39 = 0;
      v37 = v5 & 0xFFFFF;
      v7 = (*(int (__thiscall **)(_DWORD *, _DWORD *, int *))(*this + 32))(this, v4, &v33);
      while ( v7 && (*v4 & 0xFFF00000) != 0x74100000 )
      {
        if ( v40 >= this[83] )
        {
          memset(v29, 255, sizeof(v29));
          memset(v28, 255, sizeof(v28));
        }
        v8 = v4[2];
        v35 = v37 != 1 ? 0 : 3;
        v9 = 4 * v35;
        v36 = (char *)(v8 + 4 * v37 * v33);
        v38 = 4 * v35;
        if ( memcmp(v36, &v28[4 * v35], 4 * v37)
          || (v10 = (int)v41, v41[3]) && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v41[4]) + 20) != -1 )
        {
          v11 = v37;
          v12 = sub_681B0A(this, v37 & 0xFFFFF | 0x10000000, -1, -1);
          if ( v12 == -1 )
            return -2147024882;
          v34 = *(_DWORD **)(this[6] + 4 * v12);
          result = sub_680D22(v34, (int)v41);
          if ( result < 0 )
            return result;
          v13 = &v29[v38 / 4];
          result = (*(int (__thiscall **)(_DWORD *, unsigned int, _DWORD *, int, _DWORD *, int))(*this + 128))(
                     this,
                     v40,
                     &v29[v38 / 4],
                     v11,
                     v27,
                     v39);
          if ( result < 0 )
            return result;
          v30 = *(_DWORD *)(this[5] + 4 * *v13);
          v14 = v35;
          v31 = v35 + v11;
          for ( i = v35 < v35 + v11; ; i = v35 + 1 < v31 )
          {
            v35 = v14;
            if ( !i )
              break;
            v16 = this[5];
            v17 = *(_DWORD *)(v16 + 4 * v29[v14]);
            if ( v41[3] )
            {
              *(_DWORD *)(v17 + 20) = *(_DWORD *)(*(_DWORD *)(v16 + 4 * *(_DWORD *)v41[4]) + 20);
              *(_DWORD *)(v17 + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v41[4]) + 24);
            }
            v14 = v35 + 1;
          }
          v18 = v34;
          v27[v39] = *(_DWORD *)(v30 + 12);
          v19 = 4 * v11;
          qmemcpy((void *)v18[4], v13, 4 * v11);
          qmemcpy((void *)v34[2], v36, 4 * v11);
          ++v39;
          v10 = (int)v41;
          v20 = v36;
          v21 = &v28[v38];
          qmemcpy(&v28[v38], v36, 4 * (v19 >> 2));
          v23 = &v20[4 * (v19 >> 2)];
          v22 = &v21[4 * (v19 >> 2)];
          v24 = v19;
          v9 = v38;
          qmemcpy(v22, v23, v24 & 3);
        }
        qmemcpy(v36, (char *)v29 + v9, 4 * v37);
        v7 = (*(int (__thiscall **)(_DWORD *, int, int *))(*this + 32))(this, v10, &v33);
        v4 = v41;
        v3 = v32;
      }
      if ( sub_681C03(this, v4) != -1 )
      {
        sub_66238F(v4, 1);
        *(_DWORD *)(this[6] + 4 * v40) = 0;
        goto LABEL_24;
      }
      return -2147024882;
    }
    else
    {
LABEL_25:
      v25 = v3;
      if ( v3 < this[3] )
      {
        v26 = 0;
        do
        {
          *(_DWORD *)(v26 + this[6]) = *(_DWORD *)(this[6] + 4 * v25++);
          v26 += 4;
        }
        while ( v25 < this[3] );
      }
      this[3] -= v3;
      return 0;
    }
  }
  return result;
}
