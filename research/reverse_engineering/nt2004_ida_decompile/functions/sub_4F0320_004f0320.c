int __stdcall sub_4F0320(int a1, int a2)
{
  int result; // eax
  _DWORD v3[4]; // [esp+10h] [ebp-14h] BYREF
  char v4; // [esp+20h] [ebp-4h]

  result = dword_7D6BBC;
  if ( dword_7D6BBC )
  {
    v3[0] = 0;
    memset(&v3[1], 255, 12);
    sub_578600(&byte_629120);
    sub_578600(a1);
    v4 = 0;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_7D6BBC + 32))(dword_7D6BBC, a2);
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)dword_7D6BBC + 4))(dword_7D6BBC, v3, 1, 0);
    result = v3[0];
    if ( v3[0] )
      return sub_5BE8AE();
  }
  return result;
}
