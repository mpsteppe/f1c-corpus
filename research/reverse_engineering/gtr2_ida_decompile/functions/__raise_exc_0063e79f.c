int __cdecl _raise_exc(ULONG_PTR Arguments, unsigned int *a2, DWORD dwExceptionCode, int a4, double *a5, double *a6)
{
  char v6; // cl
  unsigned int *v7; // esi
  char v8; // al
  int v9; // eax
  unsigned int *v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int *v13; // eax
  unsigned int v14; // ecx
  double *v15; // edi
  int result; // eax
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  unsigned int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // ecx

  *(_DWORD *)(Arguments + 4) = 0;
  *(_DWORD *)(Arguments + 8) = 0;
  *(_DWORD *)(Arguments + 12) = 0;
  v6 = dwExceptionCode;
  if ( (dwExceptionCode & 0x10) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 1u;
    dwExceptionCode = -1073741681;
  }
  if ( (v6 & 2) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 2u;
    dwExceptionCode = -1073741677;
  }
  if ( (v6 & 1) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 4u;
    dwExceptionCode = -1073741679;
  }
  if ( (v6 & 4) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 8u;
    dwExceptionCode = -1073741682;
  }
  if ( (v6 & 8) != 0 )
  {
    *(_DWORD *)(Arguments + 4) |= 0x10u;
    dwExceptionCode = -1073741680;
  }
  v7 = a2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(16 * *a2)) & 0x10;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(2 * *v7)) & 8;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v7 >> 1)) & 4;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v7 >> 3)) & 2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*v7 >> 5)) & 1;
  v8 = _statfp();
  if ( (v8 & 1) != 0 )
    *(_DWORD *)(Arguments + 12) |= 0x10u;
  if ( (v8 & 4) != 0 )
    *(_DWORD *)(Arguments + 12) |= 8u;
  if ( (v8 & 8) != 0 )
    *(_DWORD *)(Arguments + 12) |= 4u;
  if ( (v8 & 0x10) != 0 )
    *(_DWORD *)(Arguments + 12) |= 2u;
  if ( (v8 & 0x20) != 0 )
    *(_DWORD *)(Arguments + 12) |= 1u;
  v9 = *v7 & 0xC00;
  switch ( v9 )
  {
    case 0:
      *(_DWORD *)Arguments &= 0xFFFFFFFC;
      break;
    case 1024:
      v10 = (unsigned int *)Arguments;
      v11 = *(_DWORD *)Arguments & 0xFFFFFFFC | 1;
      goto LABEL_28;
    case 2048:
      v10 = (unsigned int *)Arguments;
      v11 = *(_DWORD *)Arguments & 0xFFFFFFFC | 2;
LABEL_28:
      *v10 = v11;
      break;
    case 3072:
      *(_DWORD *)Arguments |= 3u;
      break;
  }
  v12 = *v7 & 0x300;
  switch ( v12 )
  {
    case 0:
      v13 = (unsigned int *)Arguments;
      v14 = *(_DWORD *)Arguments & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v13 = (unsigned int *)Arguments;
      v14 = *(_DWORD *)Arguments & 0xFFFFFFE3 | 4;
LABEL_36:
      *v13 = v14;
      break;
    case 768:
      *(_DWORD *)Arguments &= 0xFFFFFFE3;
      break;
  }
  *(_DWORD *)Arguments ^= (*(_DWORD *)Arguments ^ (32 * a4)) & 0x1FFE0;
  *(_DWORD *)(Arguments + 32) |= 1u;
  *(_DWORD *)(Arguments + 32) = *(_DWORD *)(Arguments + 32) & 0xFFFFFFE1 | 2;
  *(double *)(Arguments + 16) = *a5;
  *(_DWORD *)(Arguments + 96) |= 1u;
  v15 = a6;
  *(_DWORD *)(Arguments + 96) = *(_DWORD *)(Arguments + 96) & 0xFFFFFFE1 | 2;
  *(double *)(Arguments + 80) = *v15;
  _clrfp();
  RaiseException(dwExceptionCode, 0, 1u, &Arguments);
  result = Arguments;
  if ( (*(_BYTE *)(Arguments + 8) & 0x10) != 0 )
    *v7 &= ~1u;
  if ( (*(_BYTE *)(result + 8) & 8) != 0 )
    *v7 &= ~4u;
  if ( (*(_BYTE *)(result + 8) & 4) != 0 )
    *v7 &= ~8u;
  if ( (*(_BYTE *)(result + 8) & 2) != 0 )
    *v7 &= ~0x10u;
  if ( (*(_BYTE *)(result + 8) & 1) != 0 )
    *v7 &= ~0x20u;
  v17 = *(_DWORD *)result & 3;
  if ( !v17 )
  {
    *v7 &= 0xFFFFF3FF;
    goto LABEL_56;
  }
  v18 = v17 - 1;
  if ( !v18 )
  {
    v20 = *v7 & 0xFFFFF3FF | 0x400;
    goto LABEL_54;
  }
  v19 = v18 - 1;
  if ( !v19 )
  {
    v20 = *v7 & 0xFFFFF3FF | 0x800;
LABEL_54:
    *v7 = v20;
    goto LABEL_56;
  }
  if ( v19 == 1 )
    *((_BYTE *)v7 + 1) |= 0xCu;
LABEL_56:
  v21 = (*(_DWORD *)result >> 2) & 7;
  if ( !v21 )
  {
    v23 = *v7 & 0xFFFFF0FF | 0x300;
    goto LABEL_62;
  }
  v22 = v21 - 1;
  if ( !v22 )
  {
    v23 = *v7 & 0xFFFFF1FF | 0x200;
LABEL_62:
    *v7 = v23;
    goto LABEL_63;
  }
  if ( v22 == 1 )
    *v7 &= 0xFFFFF3FF;
LABEL_63:
  *v15 = *(double *)(result + 80);
  return result;
}
