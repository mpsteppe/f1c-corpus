int __userpurge sub_5FCE80@<eax>(int *a1@<ecx>, float a2@<ebx>, int a3@<edi>, int a4@<esi>, int a5, _DWORD *a6)
{
  int result; // eax
  _DWORD *v8; // ebx
  int i; // esi
  int v10; // edi
  bool v11; // cc
  int v12; // esi
  bool v13; // zf
  int v14; // ebx
  int v15; // eax
  int v16; // edi
  int v17; // esi
  int v18; // eax
  int v19; // ebx
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // eax
  float v24; // [esp+0h] [ebp-60h]
  float v25; // [esp+4h] [ebp-5Ch]
  float v26; // [esp+8h] [ebp-58h]
  float v27; // [esp+8h] [ebp-58h]
  float v30; // [esp+1Ch] [ebp-44h] BYREF
  float v31; // [esp+20h] [ebp-40h] BYREF
  int v32; // [esp+24h] [ebp-3Ch]
  int v33; // [esp+28h] [ebp-38h]
  float v34; // [esp+2Ch] [ebp-34h] BYREF
  int v35; // [esp+30h] [ebp-30h]
  float *v36; // [esp+34h] [ebp-2Ch]
  int v37; // [esp+38h] [ebp-28h]
  unsigned int v38; // [esp+3Ch] [ebp-24h]
  float v39; // [esp+40h] [ebp-20h]
  int v40; // [esp+44h] [ebp-1Ch]
  float v41[3]; // [esp+48h] [ebp-18h] BYREF
  char v42[4]; // [esp+54h] [ebp-Ch] BYREF
  unsigned int v43; // [esp+58h] [ebp-8h] BYREF
  _DWORD *v44; // [esp+5Ch] [ebp-4h] BYREF

  result = a1[12];
  if ( result )
  {
    v31 = a2;
    v8 = a6;
    sub_5E4D90(a6, (int)v42, (int)&v43, (int)&v44);
    if ( (*a1 & 0x20) != 0 )
    {
      sub_5E4DA0(a6, &v31, &v34, &v30);
      v30 = 0.0;
      v31 = 0.0;
    }
    else if ( (*a1 & 0x10) != 0 )
    {
      sub_5E4DA0(a6, &v31, &v34, &v30);
    }
    if ( (*(_BYTE *)a1 & 0x40) != 0 )
    {
      for ( i = 0; i < a1[12]; ++i )
      {
        v10 = *(_DWORD *)(a1[14] + 4 * i);
        *(float *)(v10 + 16) = sub_5D7980((float *)(v10 + 92), v41);
      }
      sub_632C60(a1[14], a1[12]);
    }
    sub_5FCA00(a1, 4096);
    result = a1[17];
    if ( result )
    {
      v32 = 0;
      v39 = sub_600770(2);
      v11 = a1[12] <= 0;
      v33 = 0;
      if ( !v11 )
      {
        do
        {
          v12 = *(_DWORD *)(a1[14] + 4 * v33);
          v13 = (*(_BYTE *)a1 & 0x30) == 0;
          v37 = v12;
          v14 = v12 + 20;
          if ( !v13 )
          {
            v26 = -v30;
            v25 = -v34;
            v24 = -v31;
            sub_5D73C0(v12 + 20, v24, v25, v26);
          }
          if ( (*(_DWORD *)v12 & 0x40000) != 0 )
            *(_DWORD *)v14 |= 2u;
          sub_5D8400((float *)(v12 + 20));
          v15 = a1[19];
          v16 = a1[20];
          v17 = *(_DWORD *)(*(_DWORD *)(a1[16] + 44) + 76) + (v32 << 6);
          v35 = 0;
          if ( v15 > 0 )
          {
            v36 = (float *)(v14 + 4);
            do
            {
              sub_5D7810((float *)v16, (float *)v17, v36);
              *(_DWORD *)(v17 + 12) = *(_DWORD *)(v16 + 12);
              *(_DWORD *)(v17 + 16) = *(_DWORD *)(v16 + 16);
              *(_DWORD *)(v17 + 20) = *(_DWORD *)(v16 + 20);
              v18 = v37;
              *(_DWORD *)(v17 + 32) = *(_DWORD *)(v16 + 32);
              *(_DWORD *)(v17 + 36) = *(_DWORD *)(v16 + 36);
              *(_DWORD *)(v17 + 28) = 0;
              v19 = *(_DWORD *)(v16 + 24);
              v43 = *(_DWORD *)(v18 + 12);
              v38 = HIBYTE(v43);
              v40 = v19;
              v27 = (double)HIBYTE(v43) * v39;
              v20 = sub_5FC610(v27);
              v21 = v35;
              *(_DWORD *)(v17 + 24) = (((unsigned __int8)v43 * ((unsigned __int8)v19 + 1)) >> 8)
                                    + ((((BYTE1(v43) * (BYTE1(v19) + 1)) >> 8)
                                      + ((((BYTE2(v43) * (BYTE2(v40) + 1)) >> 8) + (v20 << 8)) << 8)) << 8);
              v22 = a1[19];
              v16 += 64;
              v17 += 64;
              v35 = v21 + 1;
            }
            while ( v21 + 1 < v22 );
          }
          v11 = v33 + 1 < a1[12];
          v32 += a1[19];
          ++v33;
        }
        while ( v11 );
        v8 = v44;
      }
      if ( (*a1 & 0x100000) != 0 )
      {
        (*(void (__thiscall **)(int, _DWORD, int, int, int))(*(_DWORD *)dword_FB27A4 + 416))(
          dword_FB27A4,
          *(_DWORD *)(a1[16] + 44),
          4096,
          a3,
          a4);
        v23 = *a1 & 0xFFEFFFFF;
        a1[17] = 0;
        *a1 = v23;
      }
      return (*(int (__thiscall **)(int, _DWORD *, int *))(*(_DWORD *)dword_FB27A4 + 424))(dword_FB27A4, v8, a1);
    }
  }
  return result;
}
