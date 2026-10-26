int __thiscall sub_5F1550(_DWORD **this, _DWORD *a2, _DWORD *a3, int a4)
{
  int v5; // eax
  _DWORD *v7; // edx
  char v8; // [esp+8h] [ebp-14h]
  _DWORD v9[3]; // [esp+Ch] [ebp-10h] BYREF
  int v10; // [esp+18h] [ebp-4h]

  v5 = (*(int (__stdcall **)(_DWORD *, _DWORD, _DWORD *))(*this[2386] + 32))(this[2386], 0, v9);
  this[2] = (_DWORD *)v5;
  if ( v5 )
  {
    sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Could not acquire desktop didplay mode", v8);
    return -1;
  }
  if ( a2 )
    *a2 = v9[0];
  if ( a3 )
    *a3 = v9[1];
  if ( a4 )
  {
    v7 = *this;
    if ( v10 == 22 )
    {
      ((void (__thiscall *)(_DWORD **, int, _DWORD, int))v7[43])(this, 21, 0, a4);
      return 0;
    }
    ((void (__thiscall *)(_DWORD **, int, _DWORD, int))v7[43])(this, v10, 0, a4);
  }
  return 0;
}
