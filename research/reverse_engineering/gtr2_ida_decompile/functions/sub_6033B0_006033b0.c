int __thiscall sub_6033B0(void *this, int a2, int a3, _DWORD *a4, int a5, unsigned int a6, int a7)
{
  int v8; // edi
  int v9; // edx
  int v11; // esi
  int v12; // ebp
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  unsigned int v22; // eax
  int v23; // ecx
  int v24; // eax
  unsigned int v25; // esi
  unsigned int v26; // esi
  unsigned int v27; // ebx
  char v28; // [esp+0h] [ebp-68h]
  int v30; // [esp+Ch] [ebp-5Ch]
  int v31; // [esp+10h] [ebp-58h] BYREF
  int v32; // [esp+14h] [ebp-54h]
  int v33; // [esp+18h] [ebp-50h]
  int v34; // [esp+1Ch] [ebp-4Ch]
  int v35; // [esp+20h] [ebp-48h]
  int v36; // [esp+24h] [ebp-44h] BYREF
  char *v37; // [esp+28h] [ebp-40h]
  int v38; // [esp+2Ch] [ebp-3Ch] BYREF
  int v39; // [esp+30h] [ebp-38h]
  unsigned int v40; // [esp+38h] [ebp-30h]
  int v41; // [esp+40h] [ebp-28h]
  char v42[24]; // [esp+48h] [ebp-20h] BYREF
  unsigned int v43; // [esp+60h] [ebp-8h]
  unsigned int v44; // [esp+64h] [ebp-4h]
  int v45; // [esp+70h] [ebp+8h]

  v8 = 128;
  if ( sub_64479A(a2, a3, &v38) )
  {
    sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Error reading image file info", v28);
    return -1;
  }
  v9 = a6;
  if ( a6 >= v40 )
  {
    sub_5D8C80((int)this + 4, (char *)0xFFFFFFFF, "Invalid MIP level request", v28);
    return -1;
  }
  v11 = v39;
  v12 = v38;
  v45 = v38;
  v30 = v39;
  v35 = 1;
  if ( v41 == 5 )
    v35 = 6;
  v34 = 0;
  while ( 1 )
  {
    v13 = a4[6] - 9;
    v33 = 0;
    switch ( v13 )
    {
      case 0:
      case 1:
        if ( v9 <= 0 )
          goto LABEL_18;
        do
        {
          v14 = 1;
          if ( v12 >> 2 >= 1 )
            v14 = v12 >> 2;
          v15 = v11 >> 2;
          if ( v11 >> 2 < 1 )
            v15 = 1;
          v12 >>= 1;
          v11 >>= 1;
          --v9;
          v8 += 8 * v14 * v15;
        }
        while ( v9 );
        goto LABEL_17;
      case 2:
      case 3:
      case 4:
        if ( v9 > 0 )
        {
          do
          {
            v17 = 1;
            if ( v12 >> 2 >= 1 )
              v17 = v12 >> 2;
            v18 = v11 >> 2;
            if ( v11 >> 2 < 1 )
              v18 = 1;
            v8 += 16 * v17 * v18;
            v12 >>= 1;
            v11 >>= 1;
            --v9;
          }
          while ( v9 );
LABEL_17:
          v30 = v11;
          v45 = v12;
        }
LABEL_18:
        v16 = v32;
        break;
      default:
        v16 = *(int *)(a2 + 88) >> 3;
        v32 = v16;
        if ( v9 > 0 )
        {
          v19 = v9;
          do
          {
            v8 += v12 * v11 * v16;
            v12 >>= 1;
            v11 >>= 1;
            --v19;
          }
          while ( v19 );
          v30 = v11;
          v45 = v12;
        }
        break;
    }
    if ( (*(int (__thiscall **)(void *, _DWORD *, int *, int, _DWORD, int))(*(_DWORD *)this + 12))(
           this,
           a4,
           &v31,
           a7,
           *a4,
           v34) )
    {
      return -1;
    }
    (*(void (__stdcall **)(int, char *))(*(_DWORD *)v31 + 48))(v31, v42);
    if ( !(*(int (__stdcall **)(int, int *, _DWORD, _DWORD))(*(_DWORD *)v31 + 52))(v31, &v36, 0, 0) )
    {
      switch ( a4[6] )
      {
        case 9:
        case 0xA:
          v20 = 1;
          if ( v43 >> 2 )
            v20 = v43 >> 2;
          v21 = v44 >> 2;
          if ( !(v44 >> 2) )
            v21 = 1;
          v22 = 8 * v20 * v21;
          goto LABEL_43;
        case 0xB:
        case 0xC:
        case 0xD:
          v23 = 1;
          if ( v43 >> 2 )
            v23 = v43 >> 2;
          v24 = v44 >> 2;
          if ( !(v44 >> 2) )
            v24 = 1;
          v22 = 16 * v23 * v24;
LABEL_43:
          v25 = v22;
          sub_5D70A0(v37, (const void *)(v8 + a2), v22);
          v8 += v25;
          break;
        default:
          v26 = v16 * v43;
          v27 = 0;
          if ( v44 )
          {
            do
            {
              sub_5D70A0(&v37[v33], (const void *)(v8 + a2), v26);
              v8 += v26;
              v33 += v36;
              ++v27;
            }
            while ( v27 < v44 );
            v12 = v45;
          }
          break;
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)v31 + 56))(v31);
      v11 = v30;
    }
    if ( (*(_BYTE *)a4 & 0xC) != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v31 + 8))(v31);
    if ( ++v34 >= v35 )
      return 0;
    v9 = a6;
  }
}
