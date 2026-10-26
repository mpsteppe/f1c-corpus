unsigned int __thiscall sub_6BB832(_DWORD *this)
{
  char v2; // bl
  bool v3; // zf
  int v4; // ecx
  int v5; // eax
  int v7; // eax
  _DWORD *v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  _DWORD *v12; // ebx
  char ArgList[256]; // [esp+Ch] [ebp-20Ch] BYREF
  char v14[256]; // [esp+10Ch] [ebp-10Ch] BYREF
  unsigned int v15; // [esp+20Ch] [ebp-Ch]
  unsigned int v16; // [esp+210h] [ebp-8h] BYREF
  char v17; // [esp+217h] [ebp-1h]

  v2 = 0;
  v3 = this[2] == 0;
  v17 = 0;
  v16 = 0;
  if ( !v3 )
  {
    do
    {
      v4 = *(_DWORD *)(this[5] + 4 * v16);
      v5 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v4 + 4)) + 4);
      if ( ((v5 & 0x10) != 0 && (v5 & 0x200) == 0 || (v5 & 0x20) != 0)
        && (*(int (__thiscall **)(_DWORD *, int, _DWORD))(*this + 4))(this, v4, 0) < 0 )
      {
        sub_6BB7BD(this, &v16);
        v17 = 1;
        v2 = 1;
      }
      ++v16;
    }
    while ( v16 < this[2] );
    if ( v2 )
      return -2147467259;
  }
  v3 = this[2] == 0;
  v16 = 0;
  if ( !v3 )
  {
    do
    {
      v7 = this[5];
      v8 = *(_DWORD **)(v7 + 4 * v16);
      v9 = v8[1];
      v10 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v9) + 4);
      if ( (v10 & 0x10) != 0 && (v10 & 0x200) == 0 || (v10 & 0x20) != 0 )
      {
        v15 = v16 + 1;
        if ( v16 + 1 < this[2] )
        {
          v11 = v7 + 4 * v15;
          while ( 1 )
          {
            v12 = *(_DWORD **)v11;
            if ( *(_DWORD *)(*(_DWORD *)v11 + 4) == v9
              && v12[28] == v8[28]
              && v12[27] == v8[27]
              && ((unsigned int)&dword_1000000 & (*v12 ^ *v8)) != 0 )
            {
              break;
            }
            ++v15;
            v11 += 4;
            if ( v15 >= this[2] )
              goto LABEL_23;
          }
          sub_681DE0(this, (int)v8, (int)ArgList, 256);
          sub_681DE0(this, (int)v12, (int)v14, 256);
          sub_686791((int)this, v8[26], 4501, "Inconsistent semantic definition: %s and %s", ArgList, v14);
          sub_6BB7BD(this, &v16);
          v17 = 1;
LABEL_23:
          v2 = v17;
        }
      }
      ++v16;
    }
    while ( v16 < this[2] );
  }
  return v2 != 0 ? 0x80004005 : 0;
}
