int __thiscall sub_496980(_DWORD *this)
{
  int v1; // ecx
  _DWORD *v2; // eax
  char Buffer[125]; // [esp+8h] [ebp-80h] BYREF
  __int16 v5; // [esp+85h] [ebp-3h]
  char v6; // [esp+87h] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v1 = this[12];
  v5 = 0;
  v6 = 0;
  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v1 + 28))(v1, 57);
  if ( v2 )
  {
    sub_41D810(Buffer, 0x7Fu, "%d / %d", v2[149] + v2[150], v2[151]);
    sub_4CE020(Buffer);
  }
  return 0;
}
