int __thiscall sub_4B4A60(void *this)
{
  int v2; // eax
  int v3; // eax

  if ( byte_B722E4 )
    v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 22);
  else
    v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 21);
  if ( v2 )
    *(_BYTE *)(v2 + 608) = *(_BYTE *)(v2 + 608) == 0;
  if ( byte_B722E4 )
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 22);
  else
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 21);
  if ( v3 )
    (*(void (__thiscall **)(void *, bool))(*(_DWORD *)this + 44))(this, *(_BYTE *)(v3 + 608) == 0);
  return 0;
}
