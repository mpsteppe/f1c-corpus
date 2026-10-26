int __thiscall sub_49ED00(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  const char *v6; // edi
  unsigned __int16 v7; // di
  char *i; // eax
  unsigned __int16 v9; // cx
  CHAR *v10; // eax
  char v11; // al
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // ebx
  char *v16; // ebp
  char *v17; // edi
  char *v19; // edi
  int v20; // ebx
  int v21; // ebp
  char *v22; // edi
  int v23; // edx
  bool v24; // zf
  int v25; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // ebx
  int v29; // edi
  int v30; // ecx
  int v31; // ebp
  int v32; // edi
  int v33; // ebp
  int v34; // ecx
  int v35; // edx
  int v37; // [esp-14h] [ebp-290h]
  int v38; // [esp-10h] [ebp-28Ch]
  int v39; // [esp-Ch] [ebp-288h]
  int v40; // [esp-8h] [ebp-284h]
  int v41; // [esp+Ch] [ebp-270h] BYREF
  int v42; // [esp+10h] [ebp-26Ch] BYREF
  int v43; // [esp+14h] [ebp-268h]
  int j; // [esp+18h] [ebp-264h]
  int v45; // [esp+1Ch] [ebp-260h]
  char Delimiter[2]; // [esp+22h] [ebp-25Ah] BYREF
  int v47; // [esp+24h] [ebp-258h]
  int v48; // [esp+28h] [ebp-254h]
  int v49; // [esp+2Ch] [ebp-250h]
  int v50; // [esp+30h] [ebp-24Ch]
  int v51; // [esp+34h] [ebp-248h]
  int v52; // [esp+38h] [ebp-244h] BYREF
  char *Source[16]; // [esp+3Ch] [ebp-240h] BYREF
  char Destination[512]; // [esp+7Ch] [ebp-200h] BYREF

  v6 = (const char *)this[40];
  if ( !v6 )
    v6 = &byte_629120;
  if ( sub_41F230(dword_62A170, v6, ::Destination) )
  {
    if ( v6 )
    {
      strncpy(::Destination, v6, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      ::Destination[0] = 0;
    }
  }
  strncpy(Destination, ::Destination, 0x1FFu);
  strcpy(Delimiter, "|");
  memset(Source, 0, sizeof(Source));
  Destination[511] = 0;
  v7 = 0;
  for ( i = strtok(Destination, Delimiter); i; i = strtok(0, Delimiter) )
  {
    if ( v7 >= 0x10u )
      break;
    v9 = v7++;
    Source[v9] = i;
  }
  v10 = (CHAR *)this[42];
  if ( !v10 )
    v10 = &byte_629120;
  v11 = toupper(*v10);
  switch ( v11 )
  {
    case 'C':
      this[67] = 2;
      break;
    case 'L':
      this[67] = 1;
      break;
    case 'R':
      this[67] = 3;
      break;
  }
  v12 = this[1];
  v13 = this[4];
  v49 = this[2];
  v14 = this[3];
  v43 = v12;
  v48 = v14;
  v45 = v13;
  if ( v7 )
  {
    if ( (int)this[68] > 0 )
    {
      v15 = 0;
      v50 = v7;
      do
      {
        v16 = Source[v15];
        v41 = 0;
        v42 = 0;
        sub_4AE230(v16, (int)&v41, (int)&v42);
        if ( v41 > this[68] )
        {
          v17 = v16;
          if ( *v16 )
          {
            while ( *++v17 )
              ;
          }
          v19 = v17 - 1;
          *v19 = 0;
          sub_4AE230(v16, (int)&v41, (int)&v42);
          while ( v41 > this[68] )
          {
            if ( v16 == v19 )
              break;
            *--v19 = 0;
            sub_4AE230(v16, (int)&v41, (int)&v42);
          }
        }
        ++v15;
      }
      while ( v15 < v50 );
LABEL_46:
      v26 = v43;
LABEL_47:
      v32 = 0;
      if ( v50 > 0 )
      {
        v33 = (v49 - v26) / v50;
        for ( j = v33; ; v33 = j )
        {
          if ( sub_49D870(this, 0, &v42, &v41) )
          {
            v34 = v42 - this[3];
            v35 = v41 - this[1];
          }
          else
          {
            v34 = 0;
            v35 = 0;
          }
          v41 = v35;
          v42 = v34;
          v40 = v45 + v34;
          v39 = v34 + v48;
          v38 = v43 + v35 + v32 * v33 + v33;
          v37 = v43 + v35 + v32 * v33;
          if ( this[67] == 2 )
          {
            sub_4ADFB0(Source[v32], v37, v38, v39, v40);
          }
          else if ( this[67] == 3 )
          {
            sub_4AE150(Source[v32], v37, v38, v39, v40);
          }
          else
          {
            sub_4AE080(Source[v32], v37, v38, v39, v40);
          }
          if ( ++v32 >= v50 )
            break;
        }
        v26 = v43;
      }
      *a2 = v26;
      *a3 = v49;
      *a4 = v48;
      *a5 = v45;
      return 0;
    }
    v20 = v13 - v14;
    v21 = 0;
    v47 = 0;
    v41 = 0;
    j = v20;
    v51 = v49 - v12;
    v50 = v7;
    v47 = v7;
    v22 = Source[0];
    do
    {
      v42 = 0;
      v52 = 0;
      sub_4AE230(v22, (int)&v42, (int)&v52);
      if ( v21 <= v42 )
        v21 = v42;
      v23 = v52 + v41;
      v24 = v47 == 1;
      v41 += v52;
      --v47;
    }
    while ( !v24 );
    v25 = v23;
    v26 = v43;
    v47 = v21;
    if ( v20 >= v21 && v51 >= v25 )
      goto LABEL_47;
    v27 = this[67];
    v28 = v43;
    v29 = v25 + v43;
    if ( v27 == 2 )
    {
      j = v45 - (__int64)((double)j * 0.5 + 0.5);
      v30 = j - (__int64)((double)v47 * 0.5 + 0.5);
      v25 = v41;
    }
    else
    {
      if ( v27 == 3 )
      {
        v30 = v45 - v21;
        v31 = v45;
LABEL_43:
        j = v25 / 2;
        if ( v51 / 2 > v25 / 2 )
          v28 = v43 + v51 / 2 - v25 / 2;
        v48 = v30;
        v43 = v28;
        v49 = v29;
        v45 = v31;
        sub_4B13F0(v28, v29, v30, v31);
        goto LABEL_46;
      }
      v30 = v48;
    }
    v31 = v30 + v21;
    goto LABEL_43;
  }
  return 0;
}
