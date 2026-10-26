int __cdecl sub_550307(int *a1, char *a2, int a3, int a4)
{
  char v5; // cl
  int result; // eax
  char *v7; // edx
  char v8; // al
  char *v9; // edx
  char v10; // bl
  char v11; // al
  char *v12; // esi
  bool v13; // zf
  unsigned __int8 v14; // cl
  char *v15; // edx
  char v16; // al
  char *v17; // edx
  char v18; // bl
  char v19; // al
  char *v20; // esi
  char *i; // ecx
  int v22; // [esp+Ch] [ebp-8h]
  int v23; // [esp+10h] [ebp-4h]
  int v24; // [esp+10h] [ebp-4h]
  char *v25; // [esp+1Ch] [ebp+8h]
  char *v26; // [esp+1Ch] [ebp+8h]

  v5 = *((_BYTE *)a1 + 8);
  result = *a1;
  v22 = *a1;
  if ( v5 == 2 && a3 && *((_BYTE *)a1 + 9) == 8 )
  {
    v7 = a2;
    v25 = a2;
    if ( !result )
    {
LABEL_8:
      v14 = *((_BYTE *)a1 + 9);
      *((_BYTE *)a1 + 11) = v14;
      *((_BYTE *)a1 + 8) = 3;
      *((_BYTE *)a1 + 10) = 1;
      a1[1] = (result * (unsigned int)v14 + 7) >> 3;
      return result;
    }
    v23 = result;
    do
    {
      v8 = *v7;
      v9 = v7 + 1;
      v10 = *v9++;
      v11 = *(_BYTE *)((((int)(unsigned __int8)*v9 >> 3) & 0x1F | (4 * (v10 & 0xF8 | (32 * (v8 & 0xF8))))) + a3);
      v12 = v25;
      v7 = v9 + 1;
      ++v25;
      v13 = v23-- == 1;
      *v12 = v11;
    }
    while ( !v13 );
LABEL_7:
    result = v22;
    goto LABEL_8;
  }
  if ( v5 == 6 && a3 && *((_BYTE *)a1 + 9) == 8 )
  {
    v15 = a2;
    v26 = a2;
    if ( !result )
      goto LABEL_8;
    v24 = result;
    do
    {
      v16 = *v15;
      v17 = v15 + 1;
      v18 = *v17++;
      v19 = *(_BYTE *)((((int)(unsigned __int8)*v17 >> 3) & 0x1F | (4 * (v18 & 0xF8 | (32 * (v16 & 0xF8))))) + a3);
      v20 = v26;
      v15 = v17 + 2;
      ++v26;
      v13 = v24-- == 1;
      *v20 = v19;
    }
    while ( !v13 );
    goto LABEL_7;
  }
  if ( v5 == 3 )
  {
    if ( a4 )
    {
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        for ( i = a2; result; --result )
        {
          *i = *(_BYTE *)((unsigned __int8)*i + a4);
          ++i;
        }
      }
    }
  }
  return result;
}
