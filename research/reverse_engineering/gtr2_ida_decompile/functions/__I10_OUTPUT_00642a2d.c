int __cdecl _I10_OUTPUT(int a1, unsigned int a2, __int16 a3, int a4, char a5, int a6)
{
  unsigned __int16 v6; // dx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int i; // esi
  _BYTE *v11; // eax
  _BYTE *v12; // ecx
  bool v13; // zf
  char *v14; // eax
  char v15; // cl
  char *v16; // eax
  bool v17; // cc
  char *v18; // ecx
  char v19; // al
  _BYTE *v21; // [esp+Ch] [ebp-30h]
  int v22; // [esp+10h] [ebp-2Ch]
  __int64 v23; // [esp+14h] [ebp-28h] BYREF
  int v24; // [esp+1Ch] [ebp-20h]
  _BYTE v25[12]; // [esp+20h] [ebp-1Ch] BYREF
  _BYTE v26[12]; // [esp+2Ch] [ebp-10h] BYREF
  int v27; // [esp+38h] [ebp-4h]
  int v28; // [esp+4Ch] [ebp+10h]
  int v29; // [esp+4Ch] [ebp+10h]

  v27 = dword_912B08;
  memset(v25, 204, 10);
  v25[10] = -5;
  v25[11] = 63;
  v22 = 1;
  v6 = a3 & 0x7FFF;
  if ( a3 >= 0 )
    *(_BYTE *)(a6 + 2) = 32;
  else
    *(_BYTE *)(a6 + 2) = 45;
  if ( v6 || a2 || a1 )
  {
    if ( v6 == 0x7FFF )
    {
      *(_WORD *)a6 = 1;
      if ( (a2 != 0x80000000 || a1) && (a2 & 0x40000000) == 0 )
      {
        strcpy((char *)(a6 + 4), "1#SNAN");
LABEL_22:
        *(_BYTE *)(a6 + 3) = 6;
        return 0;
      }
      if ( a3 < 0 && a2 == -1073741824 )
      {
        if ( !a1 )
        {
          strcpy((char *)(a6 + 4), "1#IND");
LABEL_19:
          *(_BYTE *)(a6 + 3) = 5;
          return 0;
        }
      }
      else if ( a2 == 0x80000000 && !a1 )
      {
        strcpy((char *)(a6 + 4), "1#INF");
        goto LABEL_19;
      }
      strcpy((char *)(a6 + 4), "1#QNAN");
      goto LABEL_22;
    }
    *(_WORD *)v26 = 0;
    *(_DWORD *)&v26[2] = a1;
    v7 = (int)(77 * (HIBYTE(v6) + 2 * HIBYTE(a2)) + 19728 * v6 - 323162868) >> 16;
    *(_WORD *)&v26[10] = a3 & 0x7FFF;
    *(_DWORD *)&v26[6] = a2;
    __multtenpow12(v26, -(__int16)v7, 1);
    if ( *(_WORD *)&v26[10] >= 0x3FFFu )
    {
      LOWORD(v7) = v7 + 1;
      __ld12mul(v26, v25);
    }
    v8 = a4;
    *(_WORD *)a6 = v7;
    if ( (a5 & 1) == 0 || (v8 = (__int16)v7 + a4, v8 > 0) )
    {
      if ( v8 > 21 )
        v8 = 21;
      v9 = *(unsigned __int16 *)&v26[10] - 16382;
      *(_WORD *)&v26[10] = 0;
      v28 = 8;
      do
      {
        __shl_12(v26);
        --v28;
      }
      while ( v28 );
      if ( v9 < 0 )
      {
        for ( i = (unsigned __int8)-(char)v9; i; --i )
          __shr_12((int *)v26);
      }
      v11 = (_BYTE *)(a6 + 4);
      v21 = (_BYTE *)(a6 + 4);
      if ( v8 + 1 > 0 )
      {
        v29 = v8 + 1;
        do
        {
          v23 = *(_QWORD *)v26;
          v24 = *(_DWORD *)&v26[8];
          __shl_12(v26);
          __shl_12(v26);
          __add_12((unsigned int *)v26, (unsigned int *)&v23);
          __shl_12(v26);
          v12 = v21++;
          v13 = v29-- == 1;
          *v12 = v26[11] + 48;
          v26[11] = 0;
        }
        while ( !v13 );
        v11 = v21;
      }
      v14 = v11 - 1;
      v15 = *v14;
      v16 = v14 - 1;
      v17 = v15 < 53;
      v18 = (char *)(a6 + 4);
      if ( v17 )
      {
        while ( v16 >= v18 && *v16 == 48 )
          --v16;
        if ( v16 < v18 )
        {
          *v18 = 48;
          goto LABEL_54;
        }
      }
      else
      {
        while ( v16 >= v18 && *v16 == 57 )
          *v16-- = 48;
        if ( v16 < v18 )
        {
          ++v16;
          ++*(_WORD *)a6;
        }
        ++*v16;
      }
      v19 = (_BYTE)v16 - a6 - 3;
      *(_BYTE *)(a6 + 3) = v19;
      *(_BYTE *)(v19 + a6 + 4) = 0;
      return v22;
    }
  }
  *(_BYTE *)(a6 + 4) = 48;
LABEL_54:
  *(_WORD *)a6 = 0;
  *(_BYTE *)(a6 + 2) = 32;
  *(_BYTE *)(a6 + 3) = 1;
  *(_BYTE *)(a6 + 5) = 0;
  return 1;
}
