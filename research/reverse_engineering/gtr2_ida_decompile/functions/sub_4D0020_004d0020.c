int __thiscall sub_4D0020(int *this, int a2, int a3, int a4, int a5)
{
  const char *v6; // eax
  _DWORD *v7; // eax
  const CHAR *v8; // eax
  const CHAR *v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  int v16; // ecx
  __int64 v17; // rax
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // edi
  int v22; // ecx
  __int64 v23; // rax
  int v24; // ebx
  int v25; // ecx
  __int64 v26; // rax
  int *v28; // [esp+Ch] [ebp-28h]
  _DWORD *v29; // [esp+10h] [ebp-24h]
  int *v30; // [esp+14h] [ebp-20h]
  _DWORD *v31; // [esp+18h] [ebp-1Ch]
  int v32; // [esp+1Ch] [ebp-18h]
  int v33; // [esp+1Ch] [ebp-18h]
  _BYTE v34[4]; // [esp+28h] [ebp-Ch] BYREF
  _BYTE v35[4]; // [esp+2Ch] [ebp-8h] BYREF

  v6 = (const char *)this[40];
  if ( !v6 )
    v6 = WindowName;
  if ( !strlen(v6) )
    return -1;
  v7 = (_DWORD *)this[61];
  if ( !v7 )
    return 0;
  switch ( this[33] )
  {
    case 0:
    case 4:
      if ( *((_BYTE *)this + 100) )
        v8 = (const CHAR *)v7[22];
      else
        v8 = (const CHAR *)v7[16];
      break;
    case 2:
      if ( !*((_BYTE *)this + 100) )
        goto LABEL_14;
      v8 = (const CHAR *)v7[22];
      break;
    case 3:
      if ( *((_BYTE *)this + 100) )
        v8 = (const CHAR *)v7[22];
      else
        v8 = (const CHAR *)v7[20];
      break;
    default:
LABEL_14:
      v8 = (const CHAR *)v7[18];
      break;
  }
  if ( !v8 )
  {
    v8 = WindowName;
    if ( !WindowName )
      return 0;
  }
  sub_4DF1B0(this[12], v8);
  v9 = (const CHAR *)this[40];
  if ( !v9 )
    v9 = WindowName;
  sub_4E08C0(this[12], v9, v34, v35, 1, v32);
  if ( (int)v31 <= 0 || v33 <= 0 )
    return 0;
  v10 = this[39];
  if ( v10 )
  {
    v11 = this[67];
    if ( v11 )
    {
      v12 = *(_DWORD *)(v10 + 12);
      v13 = *this;
      if ( v11 == 1 )
      {
        if ( (*(int (__thiscall **)(int *))(v13 + 4))(this) - v12 < 0 )
          v14 = this[4] - (_DWORD)v31;
        else
          v14 = (*(int (__thiscall **)(int *))(*this + 4))(this);
        v15 = *(_DWORD *)(this[39] + 4);
      }
      else if ( (*(int (__thiscall **)(int *))(v13 + 4))(this) - v12 < 0 )
      {
        v16 = this[3];
        v17 = this[4] - v16 - (int)v31;
        v15 = *(_DWORD *)(this[39] + 4);
        v14 = v16 + (((int)v17 - HIDWORD(v17)) >> 1);
      }
      else
      {
        v14 = (*(int (__thiscall **)(int *))(*this + 4))(this);
        v15 = *(_DWORD *)(this[39] + 4);
      }
    }
    else
    {
      v14 = this[3];
      v15 = *(_DWORD *)(this[39] + 4);
    }
    goto LABEL_42;
  }
  v18 = this[38];
  if ( v18 )
  {
    v19 = this[67];
    if ( !v19 )
    {
      v14 = this[3];
      goto LABEL_41;
    }
    v20 = *this;
    v21 = *(_DWORD *)(v18 + 12);
    if ( v19 == 1 )
    {
      if ( (*(int (__thiscall **)(int *))(v20 + 4))(this) - v21 < 0 )
      {
        v14 = this[4] - (_DWORD)v31;
        goto LABEL_41;
      }
    }
    else if ( (*(int (__thiscall **)(int *))(v20 + 4))(this) - v21 < 0 )
    {
      v22 = this[3];
      v23 = this[4] - v22 - (int)v31;
      v14 = v22 + (((int)v23 - HIDWORD(v23)) >> 1);
      goto LABEL_41;
    }
    v14 = (*(int (__thiscall **)(int *))(*this + 4))(this);
LABEL_41:
    v15 = *(_DWORD *)(this[38] + 4);
LABEL_42:
    if ( (*(int (__thiscall **)(int *))(*this + 8))(this) - v15 < 0 )
    {
      v25 = this[1];
      v26 = this[2] - v25 - v33;
      v24 = v25 + (((int)v26 - HIDWORD(v26)) >> 1);
    }
    else
    {
      v24 = (*(int (__thiscall **)(int *))(*this + 8))(this);
    }
    sub_4E0730(this[12]);
    *v28 = v24;
    *v29 = (char *)v31 + v14 + v24;
    *v30 = v14;
    *v31 = 2 * v14;
    return 0;
  }
  return -1;
}
