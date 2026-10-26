int __thiscall sub_484360(_DWORD *this)
{
  int v2; // esi
  _DWORD *v3; // edi
  char v4; // al
  CHAR *v5; // eax
  int result; // eax
  int v7; // ebp
  _DWORD *v8; // esi
  char *v9; // eax
  _DWORD *v10; // eax
  int i; // [esp+10h] [ebp-304h]
  char v12[253]; // [esp+14h] [ebp-300h] BYREF
  __int16 v13; // [esp+111h] [ebp-203h]
  char v14; // [esp+113h] [ebp-201h]
  char v15[253]; // [esp+114h] [ebp-200h] BYREF
  __int16 v16; // [esp+211h] [ebp-103h]
  char v17; // [esp+213h] [ebp-101h]
  char v18[253]; // [esp+214h] [ebp-100h] BYREF
  __int16 v19; // [esp+311h] [ebp-3h]
  char v20; // [esp+313h] [ebp-1h]

  v15[0] = byte_629120;
  v2 = this[216];
  memset(&v15[1], 0, 0xFCu);
  v16 = 0;
  v17 = 0;
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 && *v3 )
      (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    sub_5BE8AE(v3);
  }
  this[216] = 0;
  this[217] = 0;
  this[218] = 0;
  this[219] = 0;
  v5 = dword_766578;
  if ( !dword_766578 )
    v5 = &byte_629120;
  sub_4E8D60(v5);
  result = sub_4E8F80(v15, 256);
  for ( i = 0; i < dword_7D6B50; ++i )
  {
    v12[0] = byte_629120;
    memset(&v12[1], 0, 0xFCu);
    v13 = 0;
    v14 = 0;
    sub_4E8D80(i);
    v7 = dword_7D6B58 + 400 * dword_7D6B54;
    sub_4E8F80(v12, 256);
    if ( !strcmp(v15, v12) )
    {
      v18[0] = byte_629120;
      memset(&v18[1], 0, 0xFCu);
      v19 = 0;
      v20 = 0;
      sub_4E8F40(v18, 256);
      v8 = operator new(0x64u);
      if ( v8 )
      {
        sub_4A5920(this);
        v8[22] = 0;
        v8[23] = -1;
        *v8 = &off_5D6F68;
      }
      else
      {
        v8 = 0;
      }
      if ( sub_49C9C0(this) )
        v9 = (char *)sub_49C9C0(this);
      else
        v9 = (char *)sub_4AE330(this[12]);
      sub_4A59F0(v9, (int)v18);
      v8[21] = v7;
      v10 = operator new(0x10u);
      if ( v10 )
      {
        *v10 = v8;
        v10[1] = 0;
        v10[2] = 0;
        *((_BYTE *)v10 + 12) = 1;
      }
      else
      {
        v10 = 0;
      }
      if ( this[216] )
      {
        *(_DWORD *)(this[217] + 4) = v10;
        v10[2] = this[217];
      }
      else
      {
        this[216] = v10;
        this[218] = v10;
      }
      this[217] = v10;
      ++this[219];
    }
    result = i + 1;
  }
  return result;
}
