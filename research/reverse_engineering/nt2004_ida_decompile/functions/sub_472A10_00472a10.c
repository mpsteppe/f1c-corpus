int __thiscall sub_472A10(_DWORD *this, int a2, int a3)
{
  int v3; // ebx
  CHAR *v5; // eax
  int v6; // ebp
  char *v7; // ecx
  int v8; // edi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int result; // eax
  CHAR *v20; // ecx
  char *v21; // eax
  int v22; // [esp+10h] [ebp-4h] BYREF

  v3 = a2;
  sub_4A5820(a2, a3);
  v5 = (CHAR *)this[16];
  v6 = 0;
  a2 = 0;
  v22 = 0;
  if ( !v5 )
    v5 = &byte_629120;
  v7 = (char *)this[18];
  if ( !v7 )
    v7 = &byte_629120;
  sub_4AE370(v7, (int)v5, (int)&a2, (int)&v22);
  if ( this[20] == 1 )
  {
    v12 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v12 <= a2 )
    {
      v15 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      v14 = a2 - v15;
    }
    else
    {
      v13 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      v14 = v13 - a2;
    }
    v10 = v14 / 2;
  }
  else
  {
    if ( this[20] != 2 )
    {
      v8 = v3 + 50;
      goto LABEL_16;
    }
    v9 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v9 <= a2 )
    {
      v11 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
      v8 = a2 + v3 - v11;
      goto LABEL_16;
    }
    v10 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    v3 -= a2;
  }
  v8 = v3 + v10;
LABEL_16:
  v16 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
  v17 = v22;
  if ( v16 > v22 )
  {
    v18 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
    v17 = v22;
    v6 = a3 + (v18 - v22) / 2;
  }
  result = sub_4A4680(v8 + a2, v6 + v17);
  if ( (_BYTE)result )
  {
    v20 = (CHAR *)this[16];
    if ( !v20 )
      v20 = &byte_629120;
    v21 = (char *)this[18];
    if ( !v21 )
      v21 = &byte_629120;
    return sub_4AE3F0(v21, (int)v20, v8, v6, 0);
  }
  return result;
}
