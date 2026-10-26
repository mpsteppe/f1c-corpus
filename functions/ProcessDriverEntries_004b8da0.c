char *__thiscall sub_4B8DA0(float ***this)
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
  int v19; // eax
  int v20; // eax
  char *result; // eax
  bool v22; // cc
  char *v23; // [esp-4h] [ebp-A0h]
  _DWORD *v24; // [esp+10h] [ebp-8Ch]
  float ***i; // [esp+14h] [ebp-88h]
  float *v26; // [esp+18h] [ebp-84h]
  char v27[29]; // [esp+1Ch] [ebp-80h] BYREF
  __int16 v28; // [esp+39h] [ebp-63h]
  char v29; // [esp+3Bh] [ebp-61h]
  _BYTE v30[29]; // [esp+3Ch] [ebp-60h] BYREF
  __int16 v31; // [esp+59h] [ebp-43h]
  char v32; // [esp+5Bh] [ebp-41h]
  char v33[61]; // [esp+5Ch] [ebp-40h] BYREF
  __int16 v34; // [esp+99h] [ebp-3h]
  char v35; // [esp+9Bh] [ebp-1h]

  v1 = (float *)this;
  v2 = this + 16;
  v26 = (float *)this;
  v24 = &unk_5EC6D8;
  for ( i = this + 16; ; v2 = i )
  {
    v27[0] = byte_5EA438[0];
    memset(&v27[1], 0, 0x1Cu);
    v28 = 0;
    v29 = 0;
    v30[0] = byte_5EA438[0];
    memset(&v30[1], 0, 0x1Cu);
    v31 = 0;
    v32 = 0;
    v33[0] = byte_5EA438[0];
    memset(&v33[1], 0, 0x3Cu);
    v34 = 0;
    v35 = 0;
    v3 = *v2;
    v4 = *v2 == 0;
    v2[2] = *v2;
    if ( !v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        while ( !UtilityFunction_50c0(v5, v1[974]) )
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
          v9[v27 - (v6 + 65)] = *v9;
          ++v9;
        }
        while ( v10 );
        v11 = v6 + 97;
        do
        {
          v12 = *v11;
          v11[v30 - (v6 + 97)] = *v11;
          ++v11;
        }
        while ( v12 );
        v13 = v6 + 1;
        v14 = (char *)(v33 - (v6 + 1));
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
    v16 = (char *)(v24 + 3);
    v17 = v24[445];
    if ( strlen(v27) )
    {
      v18 = v24;
      v23 = v27;
      v19 = PathFilenameExtractor(v24);
      if ( sub_588410(v19, v23) || !v17 )
      {
        TwoCallDelegation(v27);
        StringCopyWithBufferRealloc(v30);
        v23 = v27;
        v20 = PathFilenameExtractor(v18);
        if ( !sub_588410(v20, v23) )
        {
          if ( v17 )
            sub_4C6E80(v24);
          SessionStateTransition(0, 0);
          ++dword_5C329C;
          BuildActiveVehiclePointerArray();
          VehgenScnFileLoader(1);
          SceneRenderUpdate(1);
          SessionStateTransition(3, 0);
        }
      }
    }
    else if ( v17 )
    {
      sub_4C6E80(v24);
      SessionStateTransition(-1, 0);
      --dword_5C329C;
      BuildActiveVehiclePointerArray();
    }
    if ( strcmp(v16 + 17940, v33) )
      SetDriverName(v33);
    result = (char *)(v24 + 4656);
    v22 = (int)(v24 + 4656) < (int)byte_7C54D8;
    i += 4;
    v24 += 4656;
    if ( !v22 )
      break;
    v1 = v26;
  }
  return result;
}
