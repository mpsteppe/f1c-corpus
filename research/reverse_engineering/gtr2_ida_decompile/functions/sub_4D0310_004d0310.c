int __thiscall sub_4D0310(void *this, int a2, int a3, int a4, int a5)
{
  const char *v6; // eax
  int v7; // eax
  int v8; // ecx
  const CHAR *v9; // eax
  const CHAR *v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // ecx
  __int64 v16; // rax
  int v17; // eax
  int v18; // edi
  int v19; // ecx
  __int64 v20; // rax
  int v21; // edi
  int v22; // ecx
  __int64 v23; // rax
  int *v25; // [esp+Ch] [ebp-28h]
  _DWORD *v26; // [esp+10h] [ebp-24h]
  int *v27; // [esp+14h] [ebp-20h]
  _DWORD *v28; // [esp+18h] [ebp-1Ch]
  int v29; // [esp+1Ch] [ebp-18h]
  int v30; // [esp+1Ch] [ebp-18h]
  _BYTE v31[4]; // [esp+28h] [ebp-Ch] BYREF
  _BYTE v32[4]; // [esp+2Ch] [ebp-8h] BYREF

  v6 = (const char *)*((_DWORD *)this + 40);
  if ( !v6 )
    v6 = WindowName;
  if ( !strlen(v6) )
    return -1;
  v7 = *((_DWORD *)this + 61);
  if ( !v7 )
    return 0;
  v8 = *((_DWORD *)this + 33);
  if ( !v8 || v8 == 2 )
    v9 = *((_BYTE *)this + 100) ? *(const CHAR **)(v7 + 72) : *(const CHAR **)(v7 + 64);
  else
    v9 = *(const CHAR **)(v7 + 72);
  if ( !v9 )
  {
    v9 = WindowName;
    if ( !WindowName )
      return 0;
  }
  sub_4DF1B0(*((_DWORD *)this + 12), v9);
  v10 = (const CHAR *)*((_DWORD *)this + 40);
  if ( !v10 )
    v10 = WindowName;
  sub_4E08C0(*((_DWORD *)this + 12), v10, v32, v31, 1, v29);
  if ( v30 <= 0 || (int)v28 <= 0 )
    return 0;
  v11 = *((_DWORD *)this + 39);
  if ( v11 )
  {
    v12 = *(_DWORD *)(v11 + 12);
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this) - v12 < 0 )
    {
      v15 = *((_DWORD *)this + 3);
      v16 = *((_DWORD *)this + 4) - v15 - v30;
      v14 = *(_DWORD *)(*((_DWORD *)this + 39) + 4);
      v13 = v15 + (((int)v16 - HIDWORD(v16)) >> 1);
    }
    else
    {
      v13 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this);
      v14 = *(_DWORD *)(*((_DWORD *)this + 39) + 4);
    }
LABEL_26:
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)this + 8))(this) - v14 < 0 )
    {
      v22 = *((_DWORD *)this + 1);
      v23 = *((_DWORD *)this + 2) - v22 - (int)v28;
      v21 = v22 + (((int)v23 - HIDWORD(v23)) >> 1);
    }
    else
    {
      v21 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 8))(this);
    }
    sub_4E0730(*((_DWORD *)this + 12));
    *v25 = v21;
    *v26 = v13 + v21;
    *v27 = v13;
    *v28 = v13 + v30 + v13;
    return 0;
  }
  v17 = *((_DWORD *)this + 38);
  if ( v17 )
  {
    v18 = *(_DWORD *)(v17 + 12);
    if ( (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this) - v18 < 0 )
    {
      v19 = *((_DWORD *)this + 3);
      v20 = *((_DWORD *)this + 4) - v19 - v30;
      v13 = v19 + (((int)v20 - HIDWORD(v20)) >> 1);
    }
    else
    {
      v13 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this);
    }
    v14 = *(_DWORD *)(*((_DWORD *)this + 38) + 4);
    goto LABEL_26;
  }
  return -1;
}
