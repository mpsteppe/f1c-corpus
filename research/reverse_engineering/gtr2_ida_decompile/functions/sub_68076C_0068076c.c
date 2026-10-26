int __thiscall sub_68076C(_DWORD *this, _DWORD *a2, int a3, char *a4, __int16 a5, int a6)
{
  char *v6; // edi
  bool v7; // zf
  int v8; // esi
  int result; // eax
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // ecx
  const char *v13; // ecx
  int v14; // eax
  char *v15; // edi
  _BYTE *i; // edi
  unsigned int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // [esp-10h] [ebp-78h]
  _DWORD v22[8]; // [esp+Ch] [ebp-5Ch] BYREF
  _WORD Block[6]; // [esp+2Ch] [ebp-3Ch] BYREF
  int v24; // [esp+38h] [ebp-30h]
  int v25; // [esp+3Ch] [ebp-2Ch] BYREF
  int v26; // [esp+40h] [ebp-28h]
  int v27; // [esp+48h] [ebp-20h] BYREF
  _DWORD *v28; // [esp+4Ch] [ebp-1Ch]
  char ArgList[4]; // [esp+50h] [ebp-18h]
  char *v30; // [esp+54h] [ebp-14h]
  char *v31; // [esp+58h] [ebp-10h]
  int v32; // [esp+5Ch] [ebp-Ch]
  int v33; // [esp+60h] [ebp-8h] BYREF
  int v34; // [esp+64h] [ebp-4h] BYREF
  char *v35; // [esp+74h] [ebp+Ch]

  HIBYTE(a6) |= 0x80u;
  v6 = a4;
  v7 = *(_WORD *)"c_" == *(_WORD *)a4;
  v28 = this;
  v34 = 0;
  if ( v7 || *(_WORD *)"b_" == *(_WORD *)a4 || *(_WORD *)"i_" == *(_WORD *)a4 || *(_WORD *)"s_" == *(_WORD *)a4 )
  {
    *(_DWORD *)ArgList = a4 + 2;
    v22[2] = a4 + 2;
    v21 = this[1];
    v22[0] = 10;
    v22[4] = 0;
    v22[5] = 0;
    sub_69974C(1, v22, 0, 0, v21, 2, &v34, 0);
    result = sub_680494(*(_DWORD **)(v34 + 32), &v33, &v27);
    if ( result < 0 )
      return result;
    v8 = a3;
    if ( *(_DWORD *)(v34 + 48) )
    {
      v10 = *(_DWORD *)(v34 + 48);
      v35 = 0;
      v31 = 0;
      v30 = 0;
      v32 = v10;
      if ( v10 )
      {
        do
        {
          v11 = *(_DWORD **)(v32 + 8);
          if ( v11[1] == 17 )
          {
            v12 = v11[4];
            if ( v12 )
              v13 = *(const char **)(v12 + 24);
            else
              v13 = 0;
            v14 = v11[5];
            if ( v14 )
              v15 = *(char **)(v14 + 24);
            else
              v15 = 0;
            if ( v13 )
            {
              if ( sub_6460B4(v13, 0, &v25) >= 0 && v15 && sub_635155(*v15) == *a4 )
              {
                if ( a6 == v26 )
                {
                  v35 = v15;
                }
                else if ( ((a6 ^ v26) & 0xFFFF0000) == 0 && !(_WORD)v26 )
                {
                  v31 = v15;
                }
              }
            }
            else if ( v15 && sub_635155(*v15) == *a4 )
            {
              v30 = v15;
            }
          }
          v32 = *(_DWORD *)(v32 + 12);
        }
        while ( v32 );
        v6 = a4;
        if ( v35 )
          goto LABEL_33;
      }
      v35 = v31;
      if ( v31 || (v35 = v30) != 0 )
      {
LABEL_33:
        if ( *v6 == sub_635155(*v35) )
        {
          if ( isdigit(v35[1]) )
          {
            for ( i = v35 + 2; isdigit((char)*i); ++i )
              ;
            if ( !*i )
            {
              v17 = j__atol(v35 + 1);
              if ( v17 > 0x1FFF )
              {
                sub_65DD1F(
                  (_DWORD *)(*(_DWORD *)(*v28 + 4) + 24),
                  0,
                  2902,
                  "Constant variable '%s' bound to register greater than 8191 (%d requested)",
                  *(const char **)ArgList,
                  v17);
                return -2147467259;
              }
              *(_WORD *)(v8 + 10) |= (unsigned __int16)(4 * v17) | 2;
            }
          }
        }
      }
    }
    v18 = v34;
    if ( (*(_BYTE *)(v34 + 28) & 2) != 0 )
      *(_BYTE *)(v8 + 10) |= 1u;
    v19 = *(_DWORD *)(v18 + 40);
    if ( !v19 )
    {
      if ( !*(_DWORD *)(v18 + 36) )
      {
        if ( (*(_BYTE *)(v8 + 10) & 1) == 0 )
        {
LABEL_50:
          v20 = *(_DWORD *)(v34 + 32);
          if ( *(_DWORD *)(v20 + 4) != 9 || *(_DWORD *)(v20 + 20) != 20 )
          {
            result = sub_6C5628((int)a2, *(_DWORD *)(v34 + 32), (void *)1, 0, v8 + 12);
            if ( result < 0 )
              return result;
            goto LABEL_56;
          }
          sub_65DD1F(
            (_DWORD *)(*(_DWORD *)(*v28 + 4) + 24),
            0,
            2905,
            "Sampler variable '%s' does not specify the sampler type.  Explicit sampler types required for asm fragments.",
            *(const char **)ArgList);
          return -2147467259;
        }
        result = sub_680715(a2, v33, (_DWORD *)(v8 + 16));
LABEL_49:
        if ( result < 0 )
          return result;
        goto LABEL_50;
      }
      v19 = *(_DWORD *)(v18 + 36);
    }
    result = sub_680652(a2, v33, v27, v19, (_DWORD *)(v8 + 16));
    goto LABEL_49;
  }
  v8 = a3;
  Block[0] = 1;
  Block[1] = 3;
  Block[2] = 1;
  Block[3] = 4;
  Block[4] = 1;
  Block[5] = 0;
  v24 = 0;
  result = sub_68024C(a2, (char *)Block, 0x10u, 6, (_DWORD *)(a3 + 12));
  if ( result < 0 )
    return result;
  v33 = 1;
LABEL_56:
  result = sub_68024C(a2, a4, 0xFFFFFFFF, 7, (_DWORD *)v8);
  if ( result >= 0 )
  {
    if ( *(_WORD *)"b_" == *(_WORD *)a4 )
      *(_WORD *)(v8 + 4) = 0;
    else
      *(_WORD *)(v8 + 4) = (*(_WORD *)"i_" != *(_WORD *)a4) + 1;
    *(_WORD *)(v8 + 6) = a5;
    *(_WORD *)(v8 + 8) = v33;
  }
  return result;
}
