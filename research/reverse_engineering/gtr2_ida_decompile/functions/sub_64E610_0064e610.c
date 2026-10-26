int __thiscall sub_64E610(_DWORD *this, _DWORD *a2, int a3, int a4, int *a5, int a6, int a7)
{
  BOOL v7; // eax
  int result; // eax
  _DWORD *v9; // ebx
  _DWORD *v10; // esi
  _DWORD *v11; // ebx
  int *v12; // edi
  _DWORD *v13; // edi
  int v14; // eax
  int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  bool v18; // zf
  unsigned int v19; // eax
  int v20; // esi
  _DWORD *v21; // ecx
  int v22; // [esp+Ch] [ebp-70h] BYREF
  char v23; // [esp+15h] [ebp-67h]
  int v24; // [esp+18h] [ebp-64h]
  unsigned int v25; // [esp+24h] [ebp-58h]
  unsigned int v26; // [esp+28h] [ebp-54h]
  unsigned int v27; // [esp+2Ch] [ebp-50h] BYREF
  unsigned int v28; // [esp+30h] [ebp-4Ch]
  unsigned int v29; // [esp+34h] [ebp-48h]
  unsigned int v30; // [esp+38h] [ebp-44h]
  int v31; // [esp+3Ch] [ebp-40h]
  int v32; // [esp+40h] [ebp-3Ch]
  int v33; // [esp+44h] [ebp-38h]
  int v34; // [esp+48h] [ebp-34h]
  _DWORD v35[2]; // [esp+4Ch] [ebp-30h] BYREF
  int v36; // [esp+54h] [ebp-28h]
  unsigned int v37; // [esp+58h] [ebp-24h]
  unsigned int v38; // [esp+5Ch] [ebp-20h]
  int v39; // [esp+60h] [ebp-1Ch] BYREF
  BOOL v40; // [esp+64h] [ebp-18h]
  _DWORD *v41; // [esp+68h] [ebp-14h]
  int v42; // [esp+6Ch] [ebp-10h] BYREF
  int v43; // [esp+70h] [ebp-Ch]
  int v44; // [esp+74h] [ebp-8h]
  int v45; // [esp+78h] [ebp-4h]

  v41 = this;
  sub_64E558(this);
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)a3 + 48))(a3, &v22);
  if ( a5 )
  {
    v31 = *a5;
    v32 = a5[1];
    v33 = a5[2];
    v34 = a5[3];
    if ( v31 < 0 || v33 > v25 || v31 > v33 || v32 < 0 || v34 > v26 || v32 > v34 )
      return -2005530516;
    v7 = 1;
    if ( v31 || v33 != v25 || v32 || (v45 = 0, v34 != v26) )
      v45 = 1;
    if ( (a7 & 1) != 0 || v45 )
    {
      v40 = 0;
      goto LABEL_19;
    }
  }
  else
  {
    v33 = v25;
    v34 = v26;
    v31 = 0;
    v32 = 0;
    v45 = 0;
    v7 = (a7 & 1) == 0;
  }
  v40 = v7;
LABEL_19:
  v36 = a7 & 0x10000;
  if ( (a7 & 0x10000) != 0 )
  {
    v37 = v25;
    v38 = v26;
    v43 = 0;
    if ( (v22 == 827611204 || v22 == 844388420 || v22 == 861165636 || v22 == 877942852 || v22 == 894720068)
      && (((unsigned __int8)v25 | (unsigned __int8)v26) & 3) != 0 )
    {
      do
        ++v43;
      while ( (((v25 | v26) << v43) & 3) != 0 );
    }
    v9 = v41;
    v10 = v41 + 4;
    (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)a3 + 12))(a3, v41 + 4);
    v11 = v9 + 3;
    v44 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, int, _DWORD, int, int, _DWORD *, _DWORD))(*(_DWORD *)*v10 + 92))(
            *v10,
            v37 << v43,
            v38 << v43,
            v43 + 1,
            0,
            v22,
            (v24 == 3) + 2,
            v11,
            0);
    if ( v44 < 0
      || (v12 = v41 + 2,
          v44 = (*(int (__stdcall **)(_DWORD, int, _DWORD *))(*(_DWORD *)*v11 + 72))(*v11, v43, v41 + 2),
          v44 < 0) )
    {
      v13 = v41;
      v14 = v41[2];
      if ( v14 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14 + 8))(v41[2]);
        v13[2] = 0;
      }
      goto LABEL_38;
    }
    if ( !v40 )
    {
      v42 = 0;
      sub_5AF533(1);
      v44 = sub_64E479((int)v12, a3, *v12);
      sub_5AF533(0);
      if ( v44 < 0 )
      {
        if ( v43 )
          goto LABEL_36;
        v44 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, int, _DWORD, _DWORD, int, int *, _DWORD))(*(_DWORD *)*v10 + 112))(
                *v10,
                v37,
                v38,
                v22,
                0,
                0,
                1,
                &v42,
                0);
        if ( v44 < 0 )
          goto LABEL_36;
        v44 = (*(int (__stdcall **)(_DWORD, int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)*v10 + 136))(
                *v10,
                a3,
                0,
                v42,
                0,
                0);
        if ( v44 < 0 )
        {
          (*(void (__stdcall **)(int))(*(_DWORD *)v42 + 8))(v42);
          goto LABEL_36;
        }
        v44 = sub_64E479((int)v12, v42, *v12);
        (*(void (__stdcall **)(int))(*(_DWORD *)v42 + 8))(v42);
        if ( v44 < 0 )
        {
LABEL_36:
          if ( *v12 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)*v12 + 8))(*v12);
            *v12 = 0;
          }
LABEL_38:
          if ( *v11 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v11 + 8))(*v11);
            *v11 = 0;
          }
          if ( *v10 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v10 + 8))(*v10);
            *v10 = 0;
          }
          return v44;
        }
      }
    }
    v42 = *v12;
  }
  else
  {
    v42 = a3;
  }
  v15 = 16 * (a7 & 1 | 0x80);
  if ( v40 && !v36 && (v23 & 2) != 0 )
  {
    if ( (a7 & 0x20000) != 0 )
    {
      v15 |= 0x2000u;
      v45 = 0;
      goto LABEL_88;
    }
    sub_5AF533(1);
    if ( (*(int (__stdcall **)(int, void *, int *))(*(_DWORD *)a3 + 44))(a3, &unk_73CCC4, &v39) >= 0 )
    {
      if ( (*(int (__stdcall **)(int))(*(_DWORD *)v39 + 52))(v39) == 1 )
      {
        v15 |= 0x2000u;
        v45 = 0;
      }
      if ( v39 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v39 + 8))(v39);
        v39 = 0;
      }
    }
    sub_5AF533(0);
  }
  if ( v45 )
  {
    if ( v22 > 877942852 )
    {
      if ( v22 != 894720068 )
      {
        if ( v22 != 1111970375 && v22 != 1195525970 && v22 != 1498831189 )
          goto LABEL_79;
        goto LABEL_80;
      }
    }
    else if ( v22 != 877942852 && v22 != 827611204 && v22 != 844388420 )
    {
      if ( v22 != 844715353 )
      {
        if ( v22 == 861165636 )
          goto LABEL_65;
LABEL_79:
        v27 = v31;
        v28 = v32;
        v29 = v33;
        v30 = v34;
        goto LABEL_87;
      }
LABEL_80:
      v19 = (v33 + 1) & 0xFFFFFFFE;
      v27 = v31 & 0xFFFFFFFE;
      v29 = v19;
      v28 = v32;
      v30 = v34;
      if ( v19 > v25 )
      {
        v19 = v25;
        v29 = v25;
      }
      if ( (v31 & 0xFFFFFFFE) == 0 && v19 == v25 && !v32 )
      {
        v18 = v34 == v26;
LABEL_73:
        if ( v18 )
        {
          v45 = 0;
          goto LABEL_87;
        }
      }
LABEL_86:
      v45 = 1;
      goto LABEL_87;
    }
LABEL_65:
    v16 = (v33 + 3) & 0xFFFFFFFC;
    v17 = (v34 + 3) & 0xFFFFFFFC;
    v27 = v31 & 0xFFFFFFFC;
    v29 = v16;
    v28 = v32 & 0xFFFFFFFC;
    v30 = v17;
    if ( v16 > v25 )
    {
      v16 = v25;
      v29 = v25;
    }
    if ( v17 > v26 )
    {
      v17 = v26;
      v30 = v26;
    }
    if ( (v31 & 0xFFFFFFFC) == 0 && v16 == v25 && (v32 & 0xFFFFFFFC) == 0 )
    {
      v18 = v17 == v26;
      goto LABEL_73;
    }
    goto LABEL_86;
  }
LABEL_87:
  if ( v36 )
  {
    result = (*(int (__stdcall **)(int, _DWORD *, unsigned int *, int))(*(_DWORD *)v42 + 52))(
               v42,
               v35,
               v45 != 0 ? &v27 : 0,
               v15);
    if ( result < 0 )
      return result;
    goto LABEL_91;
  }
LABEL_88:
  sub_5AF533(1);
  v20 = (*(int (__stdcall **)(int, _DWORD *, unsigned int *, int))(*(_DWORD *)v42 + 52))(
          v42,
          v35,
          v45 != 0 ? &v27 : 0,
          v15);
  sub_5AF533(0);
  if ( v20 < 0 )
    return sub_64E610(a2, a3, a4, a5, a6, a7 | 0x10000);
LABEL_91:
  if ( v45 )
  {
    v31 -= v27;
    v33 -= v27;
    v32 -= v28;
    v34 -= v28;
  }
  *a2 = v35[1];
  a2[1] = v22;
  a2[2] = v35[0];
  a2[6] = v25;
  a2[7] = v26;
  a2[10] = v31;
  a2[9] = 1;
  a2[11] = v32;
  a2[15] = 1;
  a2[16] = 1;
  a2[19] = a6;
  a2[12] = v33;
  a2[3] = 0;
  a2[4] = 0;
  a2[5] = 0;
  a2[8] = 0;
  a2[14] = 0;
  a2[17] = 0;
  a2[18] = 0;
  a2[20] = a4;
  v21 = v41;
  a2[13] = v34;
  v21[1] = a3;
  *v21 = a7;
  (*(void (__stdcall **)(int))(*(_DWORD *)a3 + 4))(a3);
  return 0;
}
