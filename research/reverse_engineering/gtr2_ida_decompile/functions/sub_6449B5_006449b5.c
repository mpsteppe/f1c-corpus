int __fastcall sub_6449B5(
        int a1,
        int a2,
        unsigned int *a3,
        unsigned int *a4,
        unsigned int *a5,
        int *a6,
        int a7,
        int *a8,
        unsigned int a9,
        int a10)
{
  _DWORD *v12; // eax
  int v13; // edx
  unsigned int v14; // eax
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  bool v18; // cc
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // edi
  int v23; // eax
  int v24; // ecx
  unsigned int v25; // esi
  unsigned int i; // eax
  unsigned int v27; // ecx
  unsigned int j; // eax
  unsigned int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // eax
  char v32[60]; // [esp+8h] [ebp-144h] BYREF
  int v33; // [esp+44h] [ebp-108h]
  unsigned int v34; // [esp+60h] [ebp-ECh]
  unsigned int v35; // [esp+64h] [ebp-E8h]
  unsigned int v36; // [esp+68h] [ebp-E4h]
  int v37; // [esp+70h] [ebp-DCh]
  unsigned int v38; // [esp+138h] [ebp-14h]
  int v39; // [esp+13Ch] [ebp-10h]
  unsigned int v40; // [esp+140h] [ebp-Ch]
  unsigned int v41; // [esp+144h] [ebp-8h]
  unsigned int v42; // [esp+148h] [ebp-4h]

  if ( !a2 )
    return -2005530516;
  if ( a7 == -1 )
    a7 = 0;
  if ( (a7 & 0xFFE039EC) != 0 || a9 >= 4 )
    return -2005530516;
  if ( a8 )
    v39 = *a8;
  else
    v39 = 0;
  if ( a9 == 3 )
  {
    if ( !v39 )
      v39 = 21;
  }
  else
  {
    v12 = sub_644568(v39);
    v39 = sub_64467B(a2, a7, a10, v12);
    if ( !v39 )
      return -2005530518;
  }
  if ( a3 )
    v41 = *a3;
  else
    v41 = -1;
  if ( a4 )
    v42 = *a4;
  else
    v42 = -1;
  if ( a5 )
    v40 = *a5;
  else
    v40 = -1;
  if ( a6 )
    v38 = *a6;
  else
    v38 = -1;
  if ( v41 == -1 )
  {
    if ( v42 == -1 )
    {
      v42 = 256;
      v41 = 256;
      goto LABEL_38;
    }
    v41 = v42;
  }
  else if ( v42 == -1 )
  {
    v42 = v41;
  }
  if ( !v41 )
    v41 = 1;
  if ( !v42 )
    v42 = 1;
LABEL_38:
  if ( a10 == 5 )
  {
    if ( v41 > v42 )
      v42 = v41;
    v41 = v42;
  }
  if ( v40 == -1 || !v40 )
    v40 = 1;
  if ( a9 != 3 )
  {
    (*(void (__stdcall **)(int, char *))(*(_DWORD *)a2 + 28))(a2, v32);
    v13 = v33;
    if ( a10 == 4 )
    {
      v14 = v36;
      if ( v40 > v36 )
        v40 = v36;
      if ( v41 > v36 )
        v41 = v36;
    }
    else
    {
      if ( v41 > v34 )
        v41 = v34;
      if ( v42 > v35 )
        v42 = v35;
      if ( a10 != 3 )
        goto LABEL_65;
      v15 = (v33 & 0x20) != 0 ? 1 : v37;
      if ( !v15 )
        goto LABEL_65;
      if ( v41 > v42 * v15 )
        v41 = v42 * v15;
      v14 = v41 * v15;
    }
    if ( v42 > v14 )
      v42 = v14;
LABEL_65:
    switch ( a10 )
    {
      case 3:
        v16 = 2;
        break;
      case 4:
        v16 = 0x40000;
        break;
      case 5:
        v16 = 0x20000;
        break;
      default:
        v16 = a10;
        break;
    }
    if ( v38 == 1
      && (v33 & 0x100) != 0
      && v39 != 827611204
      && v39 != 844388420
      && v39 != 861165636
      && v39 != 877942852
      && v39 != 894720068 )
    {
      v16 = 0;
    }
    if ( (v16 & v33) != 0 )
    {
      v17 = v41;
      v18 = v41 <= 1;
      v41 = 1;
      if ( !v18 )
      {
        do
          v41 *= 2;
        while ( v41 < v17 );
      }
      v19 = v42;
      v18 = v42 <= 1;
      v42 = 1;
      if ( !v18 )
      {
        do
          v42 *= 2;
        while ( v42 < v19 );
      }
      v20 = v40;
      v18 = v40 <= 1;
      v40 = 1;
      if ( !v18 )
      {
        do
          v40 *= 2;
        while ( v40 < v20 );
      }
    }
    goto LABEL_89;
  }
  v13 = v33;
LABEL_89:
  if ( v39 == 827611204 || v39 == 844388420 || v39 == 861165636 || v39 == 877942852 || v39 == 894720068 )
  {
    v21 = (v41 + 3) & 0xFFFFFFFC;
    v22 = (v42 + 3) & 0xFFFFFFFC;
    v41 = v21;
    v42 = v22;
  }
  else
  {
    v21 = v41;
    v22 = v42;
  }
  switch ( a10 )
  {
    case 3:
      v23 = 0x4000;
      break;
    case 4:
      v23 = 0x8000;
      break;
    case 5:
      v23 = 0x10000;
      break;
    default:
      v23 = a10;
      break;
  }
  if ( a9 != 3
    && ((v23 & v13) == 0
     || (v13 & 0x100) != 0 && (((v21 - 1) & v21) != 0 || ((v22 - 1) & v22) != 0 || ((v40 - 1) & v40) != 0)) )
  {
    v38 = 1;
    v24 = 1;
  }
  else
  {
    v25 = 0;
    for ( i = v21; i; ++v25 )
      i >>= 1;
    v27 = 0;
    for ( j = v22; j; ++v27 )
      j >>= 1;
    v29 = v40;
    v30 = 0;
    while ( v29 )
    {
      v29 >>= 1;
      ++v30;
    }
    v31 = v25;
    if ( v25 <= v27 )
      v31 = v27;
    if ( a10 == 4 && v30 > v31 )
      v31 = v30;
    v24 = v38;
    if ( v38 > v31 || !v38 )
      v24 = v31;
    if ( v24 != 1 && (a7 & 0x400) != 0 )
      v24 = 0;
  }
  if ( a3 )
    *a3 = v41;
  if ( a4 )
    *a4 = v42;
  if ( a5 )
    *a5 = v40;
  if ( a6 )
    *a6 = v24;
  if ( a8 )
    *a8 = v39;
  return 0;
}
