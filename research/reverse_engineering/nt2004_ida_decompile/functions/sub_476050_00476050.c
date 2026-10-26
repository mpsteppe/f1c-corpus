int *__thiscall sub_476050(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax
  CHAR *v4; // eax
  char **v5; // ebp
  char ***v6; // eax
  char ***v7; // esi
  char *v8; // eax
  char *v9; // eax
  char ****v10; // eax
  int *result; // eax
  int i; // ecx
  int v13; // ebp
  char *v14; // esi
  int v15; // edi
  int v16; // edi
  char *v17; // esi
  char *v18; // eax
  int v19; // ecx
  char *v20; // ebx
  char *v21; // esi
  double v22; // st7
  __int64 v23; // rax
  int *j; // ebp
  int *v25; // edi
  char v26; // al
  LPVOID *v27; // esi
  char ****v28; // [esp+1Ch] [ebp-38Ch]
  int *v29; // [esp+1Ch] [ebp-38Ch]
  char ****v30; // [esp+20h] [ebp-388h]
  int *v31; // [esp+24h] [ebp-384h]
  int v32; // [esp+28h] [ebp-380h]
  CHAR v33; // [esp+2Ch] [ebp-37Ch] BYREF
  int v34; // [esp+2Dh] [ebp-37Bh]
  __int16 v35; // [esp+31h] [ebp-377h]
  char v36; // [esp+33h] [ebp-375h]
  int v37; // [esp+34h] [ebp-374h]
  _DWORD *v38; // [esp+38h] [ebp-370h]
  int v39; // [esp+3Ch] [ebp-36Ch]
  char Buffer[2]; // [esp+40h] [ebp-368h] BYREF
  _BYTE v41[28]; // [esp+42h] [ebp-366h] BYREF
  __int16 v42; // [esp+5Eh] [ebp-34Ah]
  char v43[61]; // [esp+60h] [ebp-348h] BYREF
  __int16 v44; // [esp+9Dh] [ebp-30Bh]
  char v45; // [esp+9Fh] [ebp-309h]
  char v46[253]; // [esp+A0h] [ebp-308h] BYREF
  __int16 v47; // [esp+19Dh] [ebp-20Bh]
  char v48; // [esp+19Fh] [ebp-209h]
  char v49[256]; // [esp+1A0h] [ebp-208h] BYREF
  char String1[264]; // [esp+2A0h] [ebp-108h] BYREF

  v34 = 0;
  v35 = 0;
  v33 = byte_629120;
  v36 = 0;
  strcpy(Buffer, "-");
  memset(v41, 0, sizeof(v41));
  v42 = 0;
  v38 = this;
  sub_49F640(&v33);
  *(_WORD *)(&v33 + strlen(&v33)) = *(_WORD *)word_5FBEBC;
  sub_49F640(&v33);
  v2 = (const char *)this[105];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = dword_76662C;
  if ( !dword_76662C )
    v3 = &byte_629120;
  if ( strcmp(v3, v2) )
  {
    v4 = dword_76662C;
    if ( !dword_76662C )
      v4 = &byte_629120;
    sub_578600(v4);
  }
  v28 = 0;
  v30 = 0;
  v32 = 0;
  dword_76BB40 = dword_76BB38;
  if ( dword_76BB38 )
    v5 = *(char ***)dword_76BB38;
  else
    v5 = 0;
  for ( ; v5; v5 = (char **)sub_50EE10(&dword_76BB38) )
  {
    v6 = (char ***)operator new(0x14u);
    v7 = 0;
    if ( v6 )
    {
      v6[1] = 0;
      v6[2] = (char **)-1;
      v6[3] = 0;
      v6[4] = (char **)-1;
      *v6 = 0;
      v7 = v6;
    }
    v43[0] = byte_629120;
    memset(&v43[1], 0, 0x3Cu);
    v44 = 0;
    v45 = 0;
    v46[0] = byte_629120;
    memset(&v46[1], 0, 0xFCu);
    v47 = 0;
    v48 = 0;
    v8 = *v5;
    if ( !*v5 )
      v8 = &byte_629120;
    sub_4E8E50(v43, 63, aVenuename, v8);
    sub_578600(v43);
    v9 = *v5;
    if ( !*v5 )
      v9 = &byte_629120;
    sub_4E8E50(v46, 255, aEventname, v9);
    sub_578600(v46);
    *v7 = v5;
    v10 = (char ****)operator new(0xCu);
    if ( v10 )
    {
      *v10 = v7;
      v10[1] = 0;
      *((_BYTE *)v10 + 8) = 1;
    }
    else
    {
      v10 = 0;
    }
    if ( v28 )
      v30[1] = (char ***)v10;
    else
      v28 = v10;
    ++v32;
    v30 = v10;
  }
  result = (int *)sub_493160(v28);
  v29 = result;
  if ( result )
  {
    for ( i = result[1]; i; i = *(_DWORD *)(i + 4) )
      ;
  }
  v31 = result;
  if ( result )
  {
    v13 = *result;
    if ( *result )
    {
      do
      {
        v14 = String1;
        v15 = 2;
        do
        {
          sub_4764B0(v14);
          v14 += 132;
          --v15;
        }
        while ( v15 );
        v16 = 0;
        v17 = String1;
        do
        {
          if ( !v13 )
            break;
          while ( 1 )
          {
            sub_4764C0(v13);
            if ( !v31 )
              break;
            v31 = (int *)v31[1];
            if ( !v31 )
              break;
            v13 = *v31;
            if ( !*v31 || !(unsigned __int8)sub_476540(v17, *v31) )
              goto LABEL_41;
          }
          v13 = 0;
LABEL_41:
          ++v16;
          v17 += 132;
        }
        while ( v16 < 2 );
        v49[0] = 0;
        v18 = v46;
        v19 = 2;
        do
        {
          *v18 = 0;
          v18 += 128;
          --v19;
        }
        while ( v19 );
        v20 = v46;
        v21 = String1;
        v37 = 2;
        do
        {
          if ( strlen(v21) )
          {
            v22 = *((float *)v21 + 32);
            v23 = (__int64)(0.016666668 * v22);
            if ( (int)v23 > 0 )
            {
              v39 = 60 * v23;
              v22 = v22 - (double)(60 * (int)v23);
            }
            if ( v22 <= 0.0 )
              sprintf(Buffer, asc_601430);
            else
              sprintf(Buffer, "%i:%06.3f", (_DWORD)v23, v22);
            sprintf(v20, "%s%s%s", v21, &v33, Buffer);
          }
          v21 += 132;
          v20 += 128;
          --v37;
        }
        while ( v37 );
        sprintf(v49, "%s%s%s", v46, &v33, &v46[128]);
        sub_49F730(v49, 0, 0, 0, 0);
      }
      while ( v13 );
      result = v29;
    }
  }
  for ( j = result; j; result = (int *)sub_5BE8AE(v25) )
  {
    v25 = j;
    v26 = *((_BYTE *)j + 8);
    j = (int *)j[1];
    if ( v26 )
    {
      v27 = (LPVOID *)*v25;
      if ( *v25 )
      {
        if ( v27[3] )
          sub_5BE8AE(v27[3]);
        if ( v27[1] )
          sub_5BE8AE(v27[1]);
        sub_5BE8AE(v27);
      }
    }
  }
  return result;
}
