bool __thiscall sub_477540(_BYTE *this, int a2, int a3, int a4, int a5)
{
  _BYTE *v5; // eax
  char v7; // cl
  char v8; // cl
  int v9; // ebp
  char *v10; // eax
  int v11; // edx
  char v12; // cl
  char *v13; // edi
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // kr00_4
  _BYTE *v18; // eax
  char *v19; // eax
  char *v20; // edi
  const char *v22; // ecx
  const char *v23; // eax
  int v25; // [esp+34h] [ebp-318h]
  _BYTE *v26; // [esp+38h] [ebp-314h]
  int v27; // [esp+3Ch] [ebp-310h] BYREF
  char v28[79]; // [esp+40h] [ebp-30Ch] BYREF
  char v29; // [esp+8Fh] [ebp-2BDh]
  char v30[28]; // [esp+94h] [ebp-2B8h] BYREF
  char v31[159]; // [esp+B0h] [ebp-29Ch] BYREF
  char v32; // [esp+14Fh] [ebp-1FDh] BYREF
  char v33; // [esp+150h] [ebp-1FCh] BYREF
  _BYTE v34[256]; // [esp+24Ch] [ebp-100h] BYREF

  v5 = (_BYTE *)a3;
  this[302726] = 0;
  this[302727] = 0;
  this[302728] = 0;
  this[302729] = 0;
  this[302730] = 0;
  this[302731] = 0;
  do
  {
    v7 = *v5;
    v34[(_DWORD)v5 - a3] = *v5;
    ++v5;
  }
  while ( v7 );
  LOWORD(v5) = (unsigned __int8)this[302704];
  v8 = this[302705];
  v26 = v5;
  if ( (unsigned __int8)(dword_B64148 + 105 * v8 - 24 * (_BYTE)v5 - 79) == *(_WORD *)(a2 + 8) )
    this[302726] = 1;
  if ( (unsigned __int8)(dword_B69638 + 99 * v8 - 120 * (_BYTE)v5 + 81) == *(_WORD *)(a2 + 12) )
    this[302727] = 1;
  if ( a4 )
  {
    if ( a5 )
    {
      if ( (unsigned __int8)sub_473D30() )
      {
        if ( (unsigned __int8)sub_473D30() )
        {
          if ( (unsigned __int8)sub_473210() )
          {
            v25 += (int)&v26[v27];
            if ( v25 == *(_DWORD *)(a2 + 14) )
              this[302728] = 1;
          }
        }
      }
    }
  }
  if ( (unsigned __int8)sub_473D30() )
  {
    v9 = (int)&v26[dword_BE27AC - 1413405834];
    v10 = (char *)(396 * dword_BE1CD4 + dword_BE1CD8 + 4);
    v27 = 0;
    v11 = &v33 - v10;
    do
    {
      v12 = *v10;
      v10[v11] = *v10;
      ++v10;
    }
    while ( v12 );
    v13 = &v32;
    while ( *++v13 )
      ;
    strcpy(v13, ".TRK");
    if ( (unsigned __int8)sub_617BD0(this[302705], &v27) )
      v9 += v27;
    if ( v9 == *(_DWORD *)(a3 + 18) )
      this[302729] = 1;
  }
  sub_473460(v30);
  v28[4] = 0;
  if ( (unsigned __int8)sub_473900() )
  {
    v15 = sub_53A220(v31);
    if ( v15 )
    {
      v16 = v15 + 4;
      v17 = strlen((const char *)(v15 + 4));
      v18 = (_BYTE *)(v16 + v17);
      if ( v16 + v17 > v16 )
      {
        while ( *v18 != 92 )
        {
          if ( (unsigned int)--v18 <= v16 )
            goto LABEL_30;
        }
        ++v18;
      }
LABEL_30:
      sub_630FE0(v28, v18, 79);
      v29 = 0;
      v19 = &v28[strlen(v28)];
      if ( v19 > v28 )
      {
        while ( *v19 != 46 )
        {
          if ( --v19 <= v28 )
            goto LABEL_35;
        }
        *v19 = 0;
      }
LABEL_35:
      v20 = (char *)&v27 + 3;
      while ( *++v20 )
        ;
      strcpy(v20, ".gdb");
      if ( (unsigned __int8)sub_473D30() && v25 == *(_DWORD *)(a2 + 22) )
        this[302730] = 1;
    }
  }
  v22 = dword_B7235C;
  if ( !dword_B7235C )
    v22 = WindowName;
  v23 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v23 = WindowName;
  sub_632041(v28, 80, "%s%s", v23, v22);
  v29 = 0;
  if ( (unsigned __int8)sub_473D30() && (unsigned __int8)v25 == *(_WORD *)(a2 + 26) )
    this[302731] = 1;
  return this[302726] && this[302727] && this[302728] && this[302729] && this[302730] && this[302731];
}
