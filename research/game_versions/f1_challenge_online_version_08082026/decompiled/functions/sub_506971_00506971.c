int __thiscall sub_506971(_DWORD *this, _DWORD *a2, int a3, int a4, const void *a5, int a6, int a7)
{
  bool v7; // zf
  unsigned int v8; // ebx
  BOOL v9; // eax
  int result; // eax
  int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // edx
  unsigned int v16; // edx
  _DWORD *v17; // ecx
  int v18; // [esp+Ch] [ebp-68h] BYREF
  int v19; // [esp+14h] [ebp-60h]
  int v20; // [esp+18h] [ebp-5Ch]
  unsigned int v21; // [esp+20h] [ebp-54h]
  unsigned int v22; // [esp+24h] [ebp-50h]
  unsigned int v23; // [esp+28h] [ebp-4Ch]
  _DWORD v24[6]; // [esp+2Ch] [ebp-48h] BYREF
  _DWORD v25[6]; // [esp+44h] [ebp-30h] BYREF
  _DWORD v26[3]; // [esp+5Ch] [ebp-18h] BYREF
  _DWORD *v27; // [esp+68h] [ebp-Ch]
  int v28; // [esp+6Ch] [ebp-8h]
  int v29; // [esp+70h] [ebp-4h] BYREF
  int v30; // [esp+88h] [ebp+14h]

  v7 = *this == 0;
  v27 = this;
  if ( !v7 )
    sub_50653E(this);
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)a3 + 32))(a3, &v18);
  if ( a5 )
  {
    qmemcpy(v25, a5, sizeof(v25));
    if ( v25[2] > v21 )
      return -2005530516;
    if ( v25[0] > v25[2] )
      return -2005530516;
    if ( v25[3] > v22 )
      return -2005530516;
    if ( v25[1] > v25[3] )
      return -2005530516;
    v8 = v25[5];
    if ( v25[5] > v23 || v25[4] > v25[5] )
      return -2005530516;
    if ( v25[0] || v25[2] != v21 || v25[1] || v25[3] != v22 || v25[4] || (v30 = 0, v25[5] != v23) )
      v30 = 1;
    v9 = (a7 & 1) == 0 && !v30;
  }
  else
  {
    v8 = v23;
    v30 = 0;
    v25[2] = v21;
    v25[3] = v22;
    v9 = (a7 & 1) == 0;
    v25[0] = 0;
    v25[1] = 0;
    v25[4] = 0;
    v25[5] = v23;
  }
  if ( !v20 && (v19 & 0x200) == 0 )
    return -2005530516;
  v11 = 16 * (a7 & 1 | 0x80);
  v28 = v11;
  if ( v9 && (v19 & 0x200) != 0 )
  {
    if ( (a7 & 0x20000) != 0 )
    {
      v11 |= 0x2000u;
      goto LABEL_65;
    }
    sub_500EAC(1);
    if ( (*(int (__stdcall **)(int, void *, int *))(*(_DWORD *)a3 + 28))(a3, &unk_5AD4B0, &v29) >= 0 )
    {
      if ( (*(int (__stdcall **)(int))(*(_DWORD *)v29 + 52))(v29) == 1 )
      {
        v11 |= 0x2000u;
        v28 = v11;
        v30 = 0;
      }
      if ( v29 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v29 + 8))(v29);
        v29 = 0;
      }
    }
    sub_500EAC(0);
  }
  if ( !v30 )
    goto LABEL_65;
  if ( v18 != 827611204 && v18 != 844388420 )
  {
    if ( v18 == 844715353 )
    {
LABEL_44:
      v12 = (v25[2] + 1) & 0xFFFFFFFE;
      v24[3] = v25[3];
      v24[0] = v25[0] & 0xFFFFFFFE;
      v24[2] = v12;
      v24[1] = v25[1];
      v24[4] = v25[4];
      v24[5] = v8;
      if ( v12 > v21 )
      {
        v12 = v21;
        v24[2] = v21;
      }
      if ( (v25[0] & 0xFFFFFFFE) != 0 || v12 != v21 || v25[1] || v25[3] != v22 || v25[4] || v8 != v23 )
        goto LABEL_68;
      goto LABEL_65;
    }
    if ( v18 != 861165636 && v18 != 877942852 && v18 != 894720068 )
    {
      if ( v18 != 1498831189 )
      {
        qmemcpy(v24, v25, sizeof(v24));
LABEL_67:
        v11 = v28;
LABEL_68:
        result = (*(int (__stdcall **)(int, _DWORD *, _DWORD *, int))(*(_DWORD *)a3 + 36))(a3, v26, v24, v11);
        if ( result < 0 )
          return result;
        v25[0] -= v24[0];
        v25[2] -= v24[0];
        v25[1] -= v24[1];
        v25[3] -= v24[1];
        v25[4] -= v24[4];
        v25[5] = v8 - v24[4];
        goto LABEL_70;
      }
      goto LABEL_44;
    }
  }
  v13 = (v25[2] + 3) & 0xFFFFFFFC;
  v14 = (v25[3] + 3) & 0xFFFFFFFC;
  v24[0] = v25[0] & 0xFFFFFFFC;
  v24[2] = v13;
  v24[1] = v25[1] & 0xFFFFFFFC;
  v24[3] = v14;
  v24[4] = v25[4];
  v24[5] = v8;
  if ( v13 > v21 )
  {
    v13 = v21;
    v24[2] = v21;
  }
  if ( v14 > v22 )
  {
    v14 = v22;
    v24[3] = v22;
  }
  if ( (v25[0] & 0xFFFFFFFC) != 0 || v13 != v21 || (v25[1] & 0xFFFFFFFC) != 0 || v14 != v22 || v25[4] || v8 != v23 )
    goto LABEL_67;
  v11 = v28;
LABEL_65:
  result = (*(int (__stdcall **)(int, _DWORD *, _DWORD, int))(*(_DWORD *)a3 + 36))(a3, v26, 0, v11);
  if ( result >= 0 )
  {
LABEL_70:
    v15 = v21;
    *a2 = v26[2];
    a2[1] = v18;
    a2[2] = v26[0];
    a2[3] = v26[1];
    a2[4] = 0;
    a2[5] = 0;
    a2[8] = 0;
    a2[9] = v23;
    qmemcpy(a2 + 10, v25, 0x18u);
    a2[17] = a6;
    a2[6] = v15;
    v16 = v22;
    a2[18] = a4;
    v17 = v27;
    a2[7] = v16;
    a2[16] = 1;
    *v17 = a3;
    return 0;
  }
  return result;
}
