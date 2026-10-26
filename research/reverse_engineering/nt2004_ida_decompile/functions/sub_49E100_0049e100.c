int __thiscall sub_49E100(_DWORD *this, int *a2, int *a3, int *a4, _DWORD *a5)
{
  const char *v6; // eax
  int v7; // eax
  int v8; // edx
  char *v9; // edx
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

  v6 = (const char *)this[40];
  if ( !v6 )
    v6 = &byte_629120;
  if ( strlen(v6) )
  {
    if ( !this[61] )
      return 0;
    v7 = sub_49D1E0(this);
    if ( !v7 || v7 == 2 )
    {
      if ( sub_49D1D0(this) )
        v9 = *(char **)(v10 + 72);
      else
        v9 = *(char **)(v10 + 64);
    }
    else
    {
      v9 = *(char **)(v8 + 72);
    }
    v11 = v9;
    if ( !v9 )
      v11 = &byte_629120;
    if ( !v11 )
      return 0;
    sub_4AE350(v11);
    v12 = (char *)this[40];
    if ( !v12 )
      v12 = &byte_629120;
    sub_4AE230(v12, (int)&v32, (int)&v31);
    if ( v32 <= 0 || v31 <= 0 )
      return 0;
    v13 = this[39];
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 12);
      if ( (*(int (__thiscall **)(_DWORD *))(*this + 4))(this) - v14 < 0 )
      {
        v17 = this[3];
        v18 = this[4] - v17 - v32;
        v16 = *(_DWORD *)(this[39] + 4);
        v15 = v17 + (((int)v18 - HIDWORD(v18)) >> 1);
      }
      else
      {
        v15 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
        v16 = *(_DWORD *)(this[39] + 4);
      }
LABEL_27:
      if ( (*(int (__thiscall **)(_DWORD *))(*this + 8))(this) - v16 < 0 )
      {
        v24 = this[1];
        v25 = this[2] - v24 - v31;
        v23 = v24 + (((int)v25 - HIDWORD(v25)) >> 1);
      }
      else
      {
        v23 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
      }
      v26 = (char *)this[40];
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
    v19 = this[38];
    if ( v19 )
    {
      v20 = *(_DWORD *)(v19 + 12);
      if ( (*(int (__thiscall **)(_DWORD *))(*this + 4))(this) - v20 < 0 )
      {
        v21 = this[3];
        v22 = this[4] - v21 - v32;
        v15 = v21 + (((int)v22 - HIDWORD(v22)) >> 1);
      }
      else
      {
        v15 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      }
      v16 = *(_DWORD *)(this[38] + 4);
      goto LABEL_27;
    }
  }
  return -1;
}
