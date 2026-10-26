int __thiscall sub_49DBB0(int this, int *a2, int *a3, int *a4, _DWORD *a5)
{
  const char *v6; // eax
  int v7; // edx
  char *v8; // edx
  int v9; // edx
  int v10; // edx
  char *v11; // eax
  char *v12; // eax
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

  v6 = *(const char **)(this + 160);
  if ( !v6 )
    v6 = &byte_629120;
  if ( strlen(v6) )
  {
    if ( !*(_DWORD *)(this + 244) )
      return 0;
    switch ( sub_49D1E0((_DWORD *)this) )
    {
      case 0:
      case 4:
        if ( sub_49D1D0((_BYTE *)this) )
          v8 = *(char **)(v10 + 88);
        else
          v8 = *(char **)(v10 + 64);
        break;
      case 2:
        if ( !sub_49D1D0((_BYTE *)this) )
          goto LABEL_14;
        v8 = *(char **)(v7 + 88);
        break;
      case 3:
        if ( sub_49D1D0((_BYTE *)this) )
          v8 = *(char **)(v9 + 88);
        else
          v8 = *(char **)(v9 + 80);
        break;
      default:
LABEL_14:
        v8 = *(char **)(v7 + 72);
        break;
    }
    v11 = v8;
    if ( !v8 )
      v11 = &byte_629120;
    if ( !v11 )
      return 0;
    sub_4AE350(v11);
    v12 = *(char **)(this + 160);
    if ( !v12 )
      v12 = &byte_629120;
    sub_4AE230(v12, (int)&v32, (int)&v31);
    if ( v32 <= 0 || v31 <= 0 )
      return 0;
    v13 = *(_DWORD *)(this + 156);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 12);
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 4))(this) - v14 < 0 )
      {
        v17 = *(_DWORD *)(this + 12);
        v18 = *(_DWORD *)(this + 16) - v17 - v32;
        v16 = *(_DWORD *)(*(_DWORD *)(this + 156) + 4);
        v15 = v17 + (((int)v18 - HIDWORD(v18)) >> 1);
      }
      else
      {
        v15 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 4))(this);
        v16 = *(_DWORD *)(*(_DWORD *)(this + 156) + 4);
      }
LABEL_31:
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 8))(this) - v16 < 0 )
      {
        v24 = *(_DWORD *)(this + 4);
        v25 = *(_DWORD *)(this + 8) - v24 - v31;
        v23 = v24 + (((int)v25 - HIDWORD(v25)) >> 1);
      }
      else
      {
        v23 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
      }
      v26 = *(char **)(this + 160);
      if ( !v26 )
        v26 = &byte_629120;
      sub_4AE080(v26, v23, v23 + v31, v15, v15 + v32);
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
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 4))(this) - v20 < 0 )
      {
        v21 = *(_DWORD *)(this + 12);
        v22 = *(_DWORD *)(this + 16) - v21 - v32;
        v15 = v21 + (((int)v22 - HIDWORD(v22)) >> 1);
      }
      else
      {
        v15 = (*(int (__thiscall **)(int))(*(_DWORD *)this + 4))(this);
      }
      v16 = *(_DWORD *)(*(_DWORD *)(this + 152) + 4);
      goto LABEL_31;
    }
  }
  return -1;
}
