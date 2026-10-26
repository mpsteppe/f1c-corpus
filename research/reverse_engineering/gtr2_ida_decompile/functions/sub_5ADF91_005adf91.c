char __stdcall sub_5ADF91(
        int a1,
        int a2,
        char *a3,
        char *a4,
        unsigned int a5,
        unsigned int a6,
        int a7,
        float **a8,
        _BYTE *a9,
        float a10,
        float *a11)
{
  float *v11; // eax
  int v12; // esi
  float v13; // ecx
  float *v14; // edx
  float *v15; // ebx
  char *v16; // edi
  char *v17; // esi
  float *v18; // esi
  unsigned int v19; // eax
  double v20; // st7
  float *v21; // eax
  bool v22; // zf
  unsigned int v23; // ecx
  float *v24; // esi
  double v25; // st7
  unsigned int v26; // esi
  float *v27; // edi
  char *v28; // edi
  char *v29; // esi
  float **v30; // eax
  float *v31; // ebx
  float *v32; // edi
  _BYTE v34[8]; // [esp+Ch] [ebp-338h] BYREF
  char v35; // [esp+14h] [ebp-330h] BYREF
  int v36; // [esp+318h] [ebp-2Ch]
  BOOL v37; // [esp+31Ch] [ebp-28h]
  float v38; // [esp+320h] [ebp-24h]
  float v39; // [esp+324h] [ebp-20h]
  float v40; // [esp+328h] [ebp-1Ch]
  float v41; // [esp+32Ch] [ebp-18h]
  float v42; // [esp+330h] [ebp-14h]
  float v43; // [esp+334h] [ebp-10h]
  float v44; // [esp+338h] [ebp-Ch]
  float *v45; // [esp+33Ch] [ebp-8h]
  unsigned int v46; // [esp+340h] [ebp-4h]
  unsigned int v47; // [esp+364h] [ebp+20h]
  float v48; // [esp+374h] [ebp+30h]

  LOBYTE(v11) = LOBYTE(a10);
  v12 = 12 * LODWORD(a10);
  v36 = 12 * LODWORD(a10);
  v37 = 12 * LODWORD(a10) != a6;
  if ( LODWORD(a10) == 2 )
  {
    LOBYTE(v11) = (_BYTE)a9;
    if ( *a9 || a9[1] != 3 )
    {
      if ( a9[1] || *a9 != 3 )
        goto LABEL_20;
      v13 = *(float *)(a7 + 4);
      v46 = *(unsigned int *)a7;
      v15 = a8[1];
      v11 = *a8;
      v45 = v11;
      v14 = v11;
    }
    else
    {
      v13 = *(float *)a7;
      v46 = *(unsigned int *)(a7 + 4);
      LOBYTE(v11) = (_BYTE)a8;
      v14 = a8[1];
      v15 = *a8;
      v45 = v14;
    }
    v41 = v13;
    if ( v13 != 0.0 )
    {
      LOBYTE(v11) = a5;
      if ( a5 )
      {
        v47 = a5;
        do
        {
          if ( v37 )
          {
            v16 = a4;
            a4 += a6;
            qmemcpy(v16, a3, 4 * (a6 >> 2));
            v17 = &a3[4 * (a6 >> 2)];
            a3 += a6;
            qmemcpy(&v16[4 * (a6 >> 2)], v17, a6 & 3);
          }
          v18 = a11;
          *v15 = 0.0;
          v15[1] = 0.0;
          v15[2] = 0.0;
          *v14 = 0.0;
          v14[1] = 0.0;
          v14[2] = 0.0;
          if ( *a11 >= 0.0 )
          {
            do
            {
              v19 = (unsigned int)(__int64)*v18 >> 1;
              v20 = (double)(int)(2 * v19);
              if ( (v19 & 0x40000000) != 0 )
                v20 = v20 + 4294967300.0;
              v48 = *v18 - v20;
              sub_5A9C3F();
              sub_5A9D52();
              v21 = v45;
              ++v18;
              v42 = v42 * v48;
              v43 = v43 * v48;
              v44 = v44 * v48;
              v38 = v38 * v48;
              v39 = v39 * v48;
              v40 = v40 * v48;
              *v15 = v42 + *v15;
              v15[1] = v43 + v15[1];
              v15[2] = v44 + v15[2];
              *v21 = v38 + *v21;
              v21[1] = v39 + v21[1];
              v21[2] = v40 + v21[2];
            }
            while ( *v18 >= 0.0 );
            v14 = v45;
          }
          LOBYTE(v11) = a6;
          LODWORD(v41) += a6;
          v46 += a6;
          v14 = (float *)((char *)v14 + a6);
          v15 = (float *)((char *)v15 + a6);
          v22 = v47-- == 1;
          v45 = v14;
          a11 = v18 + 1;
        }
        while ( !v22 );
      }
      return (char)v11;
    }
  }
LABEL_20:
  v45 = 0;
  if ( a5 )
  {
    while ( 1 )
    {
      v23 = v12;
      v24 = a11;
      memset(v34, 0, v23);
      while ( *v24 >= 0.0 )
      {
        v46 = 2 * ((unsigned int)(__int64)*v24 >> 1);
        v25 = *v24 - (double)v46;
        v26 = 0;
        *(float *)&v46 = v25;
        if ( a10 != 0.0 )
        {
          v27 = (float *)&v35;
          do
          {
            LOBYTE(v11) = a9[v26];
            if ( (_BYTE)v11 )
            {
              if ( (_BYTE)v11 != 3 && ((unsigned __int8)v11 <= 5u || (unsigned __int8)v11 > 7u) )
                return (char)v11;
              sub_5A9D52();
            }
            else
            {
              sub_5A9C3F();
            }
            ++v26;
            v42 = v42 * *(float *)&v46;
            v43 = v43 * *(float *)&v46;
            v44 = v44 * *(float *)&v46;
            *(v27 - 2) = v42 + *(v27 - 2);
            *(v27 - 1) = v43 + *(v27 - 1);
            *v27 = v44 + *v27;
            v27 += 3;
          }
          while ( v26 < LODWORD(a10) );
        }
        v24 = ++a11;
      }
      if ( v37 )
      {
        v28 = a4;
        a4 += a6;
        qmemcpy(v28, a3, 4 * (a6 >> 2));
        v29 = &a3[4 * (a6 >> 2)];
        a3 += a6;
        qmemcpy(&v28[4 * (a6 >> 2)], v29, a6 & 3);
      }
      if ( a10 != 0.0 )
      {
        v30 = a8;
        v31 = (float *)v34;
        *(float *)&v46 = a10;
        do
        {
          v32 = *v30;
          *v32++ = *v31;
          *v32 = v31[1];
          v32[1] = v31[2];
          *v30 = (float *)((char *)*v30 + a6);
          *(float **)((char *)v30 + a7 - (_DWORD)a8) = (float *)(*(char **)((char *)v30 + a7 - (_DWORD)a8) + a6);
          v31 += 3;
          ++v30;
          --v46;
        }
        while ( *(float *)&v46 != 0.0 );
      }
      ++a11;
      v45 = (float *)((char *)v45 + 1);
      LOBYTE(v11) = (_BYTE)v45;
      if ( (unsigned int)v45 >= a5 )
        break;
      v12 = v36;
    }
  }
  return (char)v11;
}
