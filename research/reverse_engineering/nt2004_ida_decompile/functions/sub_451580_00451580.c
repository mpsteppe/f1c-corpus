int __thiscall sub_451580(_DWORD **this, int a2)
{
  int v3; // eax
  int v4; // edi
  int result; // eax
  int i; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  _BYTE *v9; // eax
  int v10; // [esp+28h] [ebp-504h] BYREF
  _BYTE v11[1280]; // [esp+2Ch] [ebp-500h] BYREF

  if ( *this == (_DWORD *)2 )
  {
    v3 = (*(int (__stdcall **)(_DWORD *, int, int))(*this[1] + 36))(this[1], 256, a2);
    v4 = v3;
    if ( (v3 == -2147024884 || v3 == -2147024866) && !(*(int (__stdcall **)(_DWORD *))(*this[1] + 28))(this[1]) )
      return (*(int (__stdcall **)(_DWORD *, int, int))(*this[1] + 36))(this[1], 256, a2);
    return v4;
  }
  for ( i = 0; i < 256; ++i )
    *(_BYTE *)(i + a2) = *((_BYTE *)this + i + 896) << 7;
  v7 = this[1];
  v10 = -1;
  result = (*(int (__stdcall **)(_DWORD *, int, _DWORD, int *, int))(*v7 + 40))(v7, 20, 0, &v10, 1);
  if ( !result )
  {
    v4 = (*(int (__stdcall **)(_DWORD *, int, _BYTE *, int *, _DWORD))(*this[1] + 40))(this[1], 20, v11, &v10, 0);
    if ( !v4 )
    {
      v8 = 0;
      if ( v10 > 0 )
      {
        v9 = v11;
        do
        {
          *(_BYTE *)(*(_DWORD *)v9 + a2) = v9[4] & 0x80;
          ++v8;
          v9 += 20;
        }
        while ( v8 < v10 );
      }
    }
    return v4;
  }
  return result;
}
