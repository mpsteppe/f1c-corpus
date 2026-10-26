int __thiscall sub_55C330(int *this, _DWORD *a2, _DWORD *a3, int a4)
{
  int v5; // eax
  _DWORD v7[3]; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+18h] [ebp-4h]

  v5 = (*(int (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)this[1087] + 32))(this[1087], 0, v7);
  *this = v5;
  if ( v5 )
  {
    sub_53C590(-1, aCouldNotGetCur);
    return -1;
  }
  if ( a2 )
    *a2 = v7[0];
  if ( a3 )
    *a3 = v7[1];
  if ( a4 )
  {
    if ( v8 == 22 )
    {
      sub_55C450(21, 0, a4);
      return 0;
    }
    sub_55C450(v8, 0, a4);
  }
  return 0;
}

