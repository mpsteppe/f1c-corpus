char *__thiscall sub_4D8B50(float ***this)
{
  float *v1; // ebx
  float ***v2; // esi
  float **v3; // eax
  bool v4; // zf
  float *v5; // ecx
  char *v6; // ecx
  float **v7; // eax
  float **v8; // eax
  char *v9; // eax
  char v10; // dl
  char *v11; // eax
  char v12; // dl
  char *v13; // eax
  char *v14; // edx
  char v15; // cl
  char *v16; // esi
  int v17; // ebp
  _DWORD *v18; // edi
  const char *v19; // eax
  const char *v20; // eax
  void *v21; // edi
  char *result; // eax
  bool v23; // cc
  char *v24; // [esp-4h] [ebp-A0h]
  _DWORD *v25; // [esp+10h] [ebp-8Ch]
  float ***i; // [esp+14h] [ebp-88h]
  float *v27; // [esp+18h] [ebp-84h]
  char String2[29]; // [esp+1Ch] [ebp-80h] BYREF
  __int16 v29; // [esp+39h] [ebp-63h]
  char v30; // [esp+3Bh] [ebp-61h]
  char v31[29]; // [esp+3Ch] [ebp-60h] BYREF
  __int16 v32; // [esp+59h] [ebp-43h]
  char v33; // [esp+5Bh] [ebp-41h]
  char Source[61]; // [esp+5Ch] [ebp-40h] BYREF
  __int16 v35; // [esp+99h] [ebp-3h]
  char v36; // [esp+9Bh] [ebp-1h]

  v1 = (float *)this;
  v2 = this + 16;
  v27 = (float *)this;
  v25 = &unk_62BF68;
  for ( i = this + 16; ; v2 = i )
  {
    String2[0] = byte_629120;
    memset(&String2[1], 0, 0x1Cu);
    v29 = 0;
    v30 = 0;
    v31[0] = byte_629120;
    memset(&v31[1], 0, 0x1Cu);
    v32 = 0;
    v33 = 0;
    Source[0] = byte_629120;
    memset(&Source[1], 0, 0x3Cu);
    v35 = 0;
    v36 = 0;
    v3 = *v2;
    v4 = *v2 == 0;
    v2[2] = *v2;
    if ( !v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        while ( !sub_4D4770(v5, v1[519]) )
        {
          v7 = v2[2];
          if ( v7 )
            v2[2] = (float **)v7[1];
          v8 = v2[2];
          if ( v8 )
          {
            v5 = *v8;
            if ( *v8 )
              continue;
          }
          goto LABEL_17;
        }
        v9 = v6 + 65;
        do
        {
          v10 = *v9;
          v9[String2 - (v6 + 65)] = *v9;
          ++v9;
        }
        while ( v10 );
        v11 = v6 + 97;
        do
        {
          v12 = *v11;
          v11[v31 - (v6 + 97)] = *v11;
          ++v11;
        }
        while ( v12 );
        v13 = v6 + 1;
        v14 = (char *)(Source - (v6 + 1));
        do
        {
          v15 = *v13;
          v13[(_DWORD)v14] = *v13;
          ++v13;
        }
        while ( v15 );
      }
    }
LABEL_17:
    v16 = (char *)(v25 + 21);
    v17 = v25[474];
    if ( strlen(String2) )
    {
      v18 = v25;
      v24 = String2;
      v19 = (const char *)sub_4EDED0(v25);
      if ( _strcmpi(v19, v24) || !v17 )
      {
        sub_4EED10(String2);
        sub_50B240(v31);
        v24 = String2;
        v20 = (const char *)sub_4EDED0(v18);
        if ( !_strcmpi(v20, v24) )
        {
          v21 = v25;
          if ( v17 )
          {
            sub_4EE280(v25);
            sub_4EED10(String2);
            sub_50B240(v31);
          }
          sub_51BC20(0, 0);
          ++NumOfElements;
          sub_42DC40();
          sub_4EE0B0(v21, 1);
          sub_4EE160(COERCE_FLOAT(1));
          sub_51BC20(3, 0);
        }
      }
    }
    else if ( v17 )
    {
      sub_4EE280(v25);
      sub_51BC20(-1, 0);
      --NumOfElements;
      sub_42DC40();
    }
    if ( strcmp(v16 + 24688, Source) )
      sub_4EDDD0(Source);
    result = (char *)(v25 + 6326);
    v23 = (int)(v25 + 6326) < (int)byte_7547E8;
    i += 4;
    v25 += 6326;
    if ( !v23 )
      break;
    v1 = v27;
  }
  return result;
}
