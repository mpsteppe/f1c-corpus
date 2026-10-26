int __thiscall sub_542240(_DWORD *this)
{
  int v1; // eax
  _DWORD v3[3]; // [esp+0h] [ebp-Ch] BYREF

  v1 = this[7];
  if ( v1 )
  {
    memset(v3, 0, sizeof(v3));
    (*(void (__thiscall **)(int, int, _DWORD *, _DWORD *, int, int, int))(*(_DWORD *)v1 + 4))(
      v1,
      2,
      this + 2,
      v3,
      dword_B70948,
      1065353216,
      1);
  }
  return 0;
}
