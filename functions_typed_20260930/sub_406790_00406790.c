char __thiscall sub_406790(int this)
{
  const char *v2; // eax
  char *v3; // eax
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // ebp
  bool v7; // zf
  int v8; // edx
  int v9; // edx
  char *v10; // eax
  int v11; // eax
  char result; // al
  int v13; // esi
  int v14; // edi
  int v15; // [esp+14h] [ebp-24h]
  char v16; // [esp+18h] [ebp-20h] BYREF
  _BYTE v17[28]; // [esp+19h] [ebp-1Fh] BYREF
  __int16 v18; // [esp+35h] [ebp-3h]
  char v19; // [esp+37h] [ebp-1h]

  v15 = *(_DWORD *)(*(_DWORD *)(this + 8) + 144);
  v2 = *(const char **)(this + 16);
  if ( !*(_BYTE *)(this + 32) )
  {
    if ( !v2 )
      v2 = &byte_5EA438;
    if ( !strcmp(v2, &byte_5EA438) )
    {
      v6 = (_DWORD *)sub_4080B0(*(_DWORD *)(this + 28));
      if ( !v6 || BinaryDataDeserialization(v6, *(_DWORD *)(this + 24)) )
        goto LABEL_23;
      v7 = v6[11] == 2;
      v16 = byte_5EA438;
      if ( v7 )
      {
        v8 = v6[9];
        memset(v17, 0, sizeof(v17));
        v18 = 0;
        v19 = 0;
        StringFormatWithBufferOverflowCheck(&v16, "%s%d,%d.mp3", asc_5BE820, v6[4], v8);
      }
      else
      {
        v9 = v6[4];
        memset(v17, 0, sizeof(v17));
        v18 = 0;
        v19 = 0;
        StringFormatWithBufferOverflowCheck(&v16, "%s%d", asc_5BE820, v9);
      }
      v5 = AIL_open_stream(v15, &v16, 0);
    }
    else
    {
      v10 = *(char **)(this + 16);
      if ( !v10 )
        v10 = &byte_5EA438;
      v5 = AIL_open_stream(v15, v10, 0);
    }
    goto LABEL_22;
  }
  if ( !v2 )
    v2 = &byte_5EA438;
  if ( strcmp(v2, &byte_5EA438) && *(int *)(this + 28) > 0 )
  {
    v3 = *(char **)(this + 16);
    if ( !v3 )
      v3 = &byte_5EA438;
    if ( (unsigned __int8)sub_4069F0(v3, *(_DWORD *)(this + 24)) )
    {
      v16 = byte_5EA438;
      memset(v17, 0, sizeof(v17));
      v4 = *(_DWORD *)(this + 92);
      v18 = 0;
      v19 = 0;
      StringFormatWithBufferOverflowCheck(&v16, "%s%d,%d.mp3", asc_5BE820, v4, *(_DWORD *)(this + 28));
      v5 = AIL_open_stream(v15, &v16, 0);
LABEL_22:
      *(_DWORD *)(this + 12) = v5;
    }
  }
LABEL_23:
  v11 = *(_DWORD *)(this + 12);
  if ( v11 )
  {
    AIL_register_stream_callback(v11, SettingsSaveWrapper);
    AIL_start_stream(*(_DWORD *)(this + 12));
    AIL_set_stream_volume_levels(*(_DWORD *)(this + 12), *(float *)(this + 4), *(float *)(this + 4));
    return MutexLockWithTimeout((_DWORD *)this, 2);
  }
  else
  {
    MutexLockWithTimeout((_DWORD *)this, 0);
    v13 = this + 28;
    v14 = 3;
    do
    {
      result = StringCopyWithBufferRealloc(&byte_5EA438);
      *(_DWORD *)(v13 - 4) = -1;
      *(_DWORD *)v13 = -1;
      *(_BYTE *)(v13 + 4) = 0;
      v13 += 20;
      --v14;
    }
    while ( v14 );
  }
  return result;
}

