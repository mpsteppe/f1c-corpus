int sub_4BE390()
{
  char *v0; // eax
  int result; // eax
  const char **v2; // esi
  const char *v3; // eax
  int v4; // eax
  char v5; // cl
  int v6; // eax
  char v7; // cl
  const char *v8; // esi
  int v9; // eax
  char v10; // cl
  int v11; // eax
  char v12; // cl
  int v13; // eax
  char v14; // cl
  int v15; // eax
  char v16; // cl
  int v17; // eax
  char v18; // cl
  int v19; // eax
  char v20; // cl
  int v21; // eax
  char v22; // cl
  int v23; // eax
  char v24; // cl
  int v25; // eax
  char v26; // cl
  int v27; // eax
  char v28; // cl
  char v29[253]; // [esp+Ch] [ebp-400h] BYREF
  __int16 v30; // [esp+109h] [ebp-303h]
  char v31; // [esp+10Bh] [ebp-301h]
  char v32[253]; // [esp+10Ch] [ebp-300h] BYREF
  __int16 v33; // [esp+209h] [ebp-203h]
  char v34; // [esp+20Bh] [ebp-201h]
  char Destination[253]; // [esp+20Ch] [ebp-200h] BYREF
  __int16 v36; // [esp+309h] [ebp-103h]
  char v37; // [esp+30Bh] [ebp-101h]
  char v38[253]; // [esp+30Ch] [ebp-100h] BYREF
  __int16 v39; // [esp+409h] [ebp-3h]
  char v40; // [esp+40Bh] [ebp-1h]

  v0 = dword_7665D8;
  if ( !dword_7665D8 )
    v0 = &byte_629120;
  result = sub_4E7790(v0);
  v2 = (const char **)result;
  if ( result && dword_768228 >= 0 && dword_768228 < *(_DWORD *)(result + 1228) )
  {
    v38[0] = byte_629120;
    memset(&v38[1], 0, 0xFCu);
    v39 = 0;
    v40 = 0;
    Destination[0] = byte_629120;
    memset(&Destination[1], 0, 0xFCu);
    v36 = 0;
    v37 = 0;
    v29[0] = byte_629120;
    memset(&v29[1], 0, 0xFCu);
    v30 = 0;
    v31 = 0;
    v32[0] = byte_629120;
    memset(&v32[1], 0, 0xFCu);
    v33 = 0;
    v34 = 0;
    sub_4E7140(dword_768228, v38, 256);
    sub_4BE0B0(v38, 256);
    v3 = *v2;
    if ( !*v2 )
      v3 = &byte_629120;
    strncpy(Destination, v3, 0xFFu);
    v37 = 0;
    sub_4BE0B0(Destination, 256);
    v4 = 0;
    do
    {
      v5 = byte_609FF8[v4];
      v29[v4++] = v5;
    }
    while ( v5 );
    v6 = 0;
    do
    {
      v7 = byte_609FE8[v6];
      v32[v6++] = v7;
    }
    while ( v7 );
    v8 = (const char *)(v2 + 291);
    sub_4BE1C0(v29, v32, v8, v38, Destination);
    v9 = 0;
    do
    {
      v10 = byte_609FD8[v9];
      v29[v9++] = v10;
    }
    while ( v10 );
    v11 = 0;
    do
    {
      v12 = byte_609FC4[v11];
      v32[v11++] = v12;
    }
    while ( v12 );
    sub_4BE1C0(v29, v32, v8, v38, Destination);
    v13 = 0;
    do
    {
      v14 = byte_609FB0[v13];
      v29[v13++] = v14;
    }
    while ( v14 );
    v15 = 0;
    do
    {
      v16 = byte_609F98[v15];
      v32[v15++] = v16;
    }
    while ( v16 );
    sub_4BE1C0(v29, v32, v8, v38, Destination);
    v17 = 0;
    do
    {
      v18 = byte_609F84[v17];
      v29[v17++] = v18;
    }
    while ( v18 );
    v19 = 0;
    do
    {
      v20 = byte_609F6C[v19];
      v32[v19++] = v20;
    }
    while ( v20 );
    sub_4BE1C0(v29, v32, v8, v38, Destination);
    v21 = 0;
    do
    {
      v22 = byte_609F5C[v21];
      v29[v21++] = v22;
    }
    while ( v22 );
    v23 = 0;
    do
    {
      v24 = byte_609F48[v23];
      v32[v23++] = v24;
    }
    while ( v24 );
    sub_4BE1C0(v29, v32, v8, v38, Destination);
    v25 = 0;
    do
    {
      v26 = aWcrims[v25];
      v29[v25++] = v26;
    }
    while ( v26 );
    v27 = 0;
    do
    {
      v28 = *((_BYTE *)&dword_6011F4 + v27);
      v32[v27++] = v28;
    }
    while ( v28 );
    return sub_4BE1C0(v29, v32, v8, v38, Destination);
  }
  return result;
}
