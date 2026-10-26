int __thiscall sub_5A2210(int this, char *Str, int a3, int a4)
{
  const char *v4; // esi
  int v6; // ebp
  int v8; // esi
  __int64 v9; // rax
  int v10; // ecx
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  int v14; // esi
  int v15; // edx
  int v16; // eax
  int v17; // ebx
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  int v28; // ecx
  int v29; // ebp
  int v30; // ecx
  int v31; // eax
  unsigned int v32; // eax
  int v33; // ecx
  int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // edx
  int v37; // eax
  int v38; // [esp+1Ch] [ebp-4Ch]
  int v39; // [esp+20h] [ebp-48h] BYREF
  int v40; // [esp+24h] [ebp-44h] BYREF
  int v41; // [esp+28h] [ebp-40h] BYREF
  int v42; // [esp+2Ch] [ebp-3Ch] BYREF
  int v43; // [esp+30h] [ebp-38h]
  int v44; // [esp+34h] [ebp-34h] BYREF
  int v45; // [esp+38h] [ebp-30h] BYREF
  int v46; // [esp+3Ch] [ebp-2Ch]
  int v47; // [esp+40h] [ebp-28h] BYREF
  char *v48; // [esp+44h] [ebp-24h]
  _DWORD v49[6]; // [esp+48h] [ebp-20h] BYREF
  unsigned int v50; // [esp+60h] [ebp-8h]
  unsigned int v51; // [esp+64h] [ebp-4h]

  v4 = Str;
  v6 = 0;
  v43 = this;
  v39 = 0;
  v44 = 0;
  v38 = 128;
  if ( !strstr(Str, dword_608FD8) )
    return -1;
  sub_5A1D50((char *)this, v4);
  if ( sub_59F4D0(*(void **)(this + 16), (int)v4, (int)&v41, (int)&v40, (int)&v42, (int)&v45, (LPCWCH *)&v39, &v44) )
  {
    if ( v39 )
      sub_5BE8AE();
    sub_5A2660(this);
    return -1;
  }
  else
  {
    v8 = (__int64)(__FYL2X__((double)v41, 0.6931471805599453094) * 1.442695036924675 + 0.5);
    v9 = (__int64)(__FYL2X__((double)v40, 0.6931471805599453094) * 1.442695036924675 + 0.5);
    HIDWORD(v9) = *(_DWORD *)(this + 92);
    v10 = v41;
    v11 = v40;
    v47 = v41;
    v46 = v40;
    if ( !HIDWORD(v9) || SHIDWORD(v9) > v8 || SHIDWORD(v9) > (int)v9 )
    {
      if ( v8 < (int)v9 )
        LODWORD(v9) = v8;
      *(_DWORD *)(this + 92) = v9;
    }
    if ( v45 < dword_7E8D7C )
      *(_DWORD *)(this + 4) |= 1u;
    v12 = a4;
    if ( (a4 & 0x800) != 0 )
    {
      v13 = a3;
      if ( !a3 )
        v13 = 16711935;
      v14 = v43;
      sub_5A0280(*(_DWORD **)(v43 + 16), v13);
      v11 = v40;
      v10 = v41;
    }
    else
    {
      v14 = v43;
    }
    if ( (*(_BYTE *)(v14 + 4) & 1) == 0 )
    {
      v15 = dword_7E8D7C;
      while ( v15 )
      {
        v10 >>= 1;
        if ( v10 <= 2 || v11 >> 1 <= 2 )
          break;
        v11 >>= 1;
        v16 = *(_DWORD *)(v14 + 92);
        ++v6;
        --v15;
        v41 = v10;
        v40 = v11;
        if ( v16 > 1 )
          *(_DWORD *)(v14 + 92) = v16 - 1;
      }
    }
    *(_DWORD *)(*(_DWORD *)(v14 + 16) + 44) = *(_DWORD *)(v14 + 92);
    if ( (v12 & 0xF) != 0 )
    {
      if ( sub_59F580(*(void **)(v14 + 16), v41, v40, v42, v12) )
        return -1;
      if ( dword_7E8D40 )
      {
        if ( v6 > 0 )
        {
          v17 = 128;
          v18 = v46;
          v19 = v47;
          a4 = v42 - 9;
          do
          {
            switch ( a4 )
            {
              case 0:
              case 1:
                v20 = 1;
                if ( v19 >> 2 >= 1 )
                  v20 = v19 >> 2;
                v21 = v18 >> 2;
                if ( v18 >> 2 < 1 )
                  v21 = 1;
                v17 += 8 * v20 * v21;
                break;
              case 2:
              case 3:
              case 4:
                v22 = 1;
                if ( v19 >> 2 >= 1 )
                  v22 = v19 >> 2;
                v23 = v18 >> 2;
                if ( v18 >> 2 < 1 )
                  v23 = 1;
                v24 = 16 * v22 * v23;
                goto LABEL_45;
              default:
                v24 = v19 * v18 * (*(int *)(v39 + 88) >> 3);
LABEL_45:
                v17 += v24;
                break;
            }
            v19 >>= 1;
            v18 >>= 1;
            --v6;
          }
          while ( v6 );
          v38 = v17;
        }
        v25 = *(_DWORD *)(v14 + 92);
        v26 = 0;
        a4 = 0;
        if ( v25 > 0 )
        {
          do
          {
            v27 = *(_DWORD *)(v14 + 16);
            v28 = *(_DWORD *)(v27 + 56);
            v29 = 0;
            if ( (v28 & 4) != 0 )
            {
              (*(void (__stdcall **)(_DWORD, int, char **))(**(_DWORD **)(v27 + 20) + 60))(
                *(_DWORD *)(v27 + 20),
                v26,
                &Str);
            }
            else if ( (v28 & 8) != 0 )
            {
              (*(void (__stdcall **)(_DWORD, int, char **))(**(_DWORD **)(v27 + 24) + 60))(
                *(_DWORD *)(v27 + 24),
                v26,
                &Str);
            }
            else if ( (v28 & 1) != 0 )
            {
              Str = *(char **)(v27 + 12);
            }
            else if ( (v28 & 2) != 0 )
            {
              Str = *(char **)(v27 + 16);
            }
            (*(void (__stdcall **)(char *, _DWORD *))(*(_DWORD *)Str + 32))(Str, v49);
            if ( !(*(int (__stdcall **)(char *, int *, _DWORD, _DWORD))(*(_DWORD *)Str + 36))(Str, &v47, 0, 0) )
            {
              switch ( v42 )
              {
                case 9:
                case 10:
                  v30 = 1;
                  if ( v50 >> 2 )
                    v30 = v50 >> 2;
                  v31 = v51 >> 2;
                  if ( !(v51 >> 2) )
                    v31 = 1;
                  v32 = 8 * v30 * v31;
                  goto LABEL_69;
                case 11:
                case 12:
                case 13:
                  v33 = 1;
                  if ( v50 >> 2 )
                    v33 = v50 >> 2;
                  v34 = v51 >> 2;
                  if ( !(v51 >> 2) )
                    v34 = 1;
                  v32 = 16 * v33 * v34;
LABEL_69:
                  qmemcpy(v48, (const void *)(v38 + v39), v32);
                  v38 += v32;
                  break;
                default:
                  v35 = v50 * (*(int *)(v39 + 88) >> 3);
                  v36 = 0;
                  if ( v51 )
                  {
                    do
                    {
                      qmemcpy(&v48[v29], (const void *)(v39 + v38), v35);
                      v29 += v47;
                      ++v36;
                      v38 += v35;
                    }
                    while ( v36 < v51 );
                    v26 = a4;
                  }
                  break;
              }
              (*(void (__stdcall **)(char *))(*(_DWORD *)Str + 40))(Str);
              v14 = v43;
            }
            if ( (*(_BYTE *)(*(_DWORD *)(v14 + 16) + 56) & 0xC) != 0 )
              (*(void (__stdcall **)(char *))(*(_DWORD *)Str + 8))(Str);
            v37 = *(_DWORD *)(v14 + 92);
            a4 = ++v26;
          }
          while ( v26 < v37 );
        }
      }
    }
    if ( v39 )
      sub_5BE8AE();
    *(_DWORD *)(v14 + 92) = *(_DWORD *)(*(_DWORD *)(v14 + 16) + 44);
    return 0;
  }
}
