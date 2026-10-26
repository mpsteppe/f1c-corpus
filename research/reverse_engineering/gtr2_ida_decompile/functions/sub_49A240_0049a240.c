int __thiscall sub_49A240(int this)
{
  int result; // eax
  char *v3; // eax
  int v4; // [esp+0h] [ebp-4h]

  result = sub_4D0AC0(v4);
  *(_DWORD *)(this + 600) = -1;
  *(_BYTE *)(this + 608) = 0;
  if ( *(_DWORD *)dword_B72314 == 5 )
  {
    v3 = sub_41D840(&byte_91CC38, "Loading Grid...");
    return sub_4D93B0(v3, WindowName, WindowName, WindowName, 0, 0, -1, -1, -1, -1);
  }
  return result;
}
