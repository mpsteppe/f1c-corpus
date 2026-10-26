int __thiscall UIFieldRenderer(int this, int *a2, int *a3, int *a4, _DWORD *a5)
{
  const char *v6; // eax
  int v7; // eax
  int v8; // edx
  const char *v9; // edx
  int v10; // edx
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int v16; // edi
  int v17; // ecx
  __int64 v18; // rax
  int v19; // eax
  int v20; // edi
  int v21; // ecx
  __int64 v22; // rax
  int v23; // edi
  int v24; // ecx
  __int64 v25; // rax
  char *v26; // eax
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int v31; // [esp+Ch] [ebp-8h] BYREF
  int v32; // [esp+10h] [ebp-4h] BYREF

  v6 = *(const char **)(this + 176);
  if ( !v6 )
    v6 = byte_5EA438;
  if ( strlen(v6) )
  {
    if ( !*(_DWORD *)(this + 200) )
      return 0;
    v7 = ShortComputation_6720((_DWORD *)this);
    if ( !v7 || v7 == 2 )
    {
      if ( ByteFieldGetterAt100((_BYTE *)this) )
        v9 = *(const char **)(v10 + 72);
      else
        v9 = *(const char **)(v10 + 64);
    }
    else
    {
      v9 = *(const char **)(v8 + 72);
    }
    v11 = v9;
    if ( !v9 )
      v11 = byte_5EA438;
    if ( !v11 )
      return 0;
    sub_498560(*(char **)(this + 64), v11);
    v12 = *(const char **)(this + 176);
    if ( !v12 )
      v12 = byte_5EA438;
    TextRenderToSurface(*(const char **)(this + 64), v12, &v32, &v31, 1);
    if ( v32 <= 0 || v31 <= 0 )
      return 0;
    v13 = *(_DWORD *)(this + 156);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 12);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this) - v14 < 0 )
      {
        v17 = *(_DWORD *)(this + 12);
        v18 = *(_DWORD *)(this + 16) - v17 - v32;
        v16 = *(_DWORD *)(*(_DWORD *)(this + 156) + 4);
        v15 = v17 + (((int)v18 - HIDWORD(v18)) >> 1);
      }
      else
      {
        v15 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this);
        v16 = *(_DWORD *)(*(_DWORD *)(this + 156) + 4);
      }
LABEL_27:
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 28))(this) - v16 < 0 )
      {
        v24 = *(_DWORD *)(this + 4);
        v25 = *(_DWORD *)(this + 8) - v24 - v31;
        v23 = v24 + (((int)v25 - HIDWORD(v25)) >> 1);
      }
      else
      {
        v23 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 28))(this);
      }
      v26 = *(char **)(this + 176);
      if ( !v26 )
        v26 = byte_5EA438;
      BitmapDraw_81f0(*(const char **)(this + 64), v26, v23, v23 + v31, v15, v15 + v32, 1);
      v27 = v31;
      *a2 = v23;
      v28 = v27 + v23;
      v29 = v32;
      *a3 = v28;
      *a4 = v15;
      *a5 = v29 + v15;
      return 0;
    }
    v19 = *(_DWORD *)(this + 152);
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 12);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this) - v20 < 0 )
      {
        v21 = *(_DWORD *)(this + 12);
        v22 = *(_DWORD *)(this + 16) - v21 - v32;
        v15 = v21 + (((int)v22 - HIDWORD(v22)) >> 1);
      }
      else
      {
        v15 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 24))(this);
      }
      v16 = *(_DWORD *)(*(_DWORD *)(this + 152) + 4);
      goto LABEL_27;
    }
  }
  return -1;
}

