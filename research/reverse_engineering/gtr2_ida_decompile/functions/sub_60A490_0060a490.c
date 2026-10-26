int __thiscall sub_60A490(int this, char a2)
{
  int v3; // edx
  int v4; // ecx
  int result; // eax
  int v6; // [esp+0h] [ebp-8h]

  if ( a2 != *(_BYTE *)(this + 236) )
  {
    v3 = *(_DWORD *)(this + 204);
    v4 = *(_DWORD *)dword_FB40C8;
    if ( a2 )
      (*(void (__stdcall **)(int, int, int, int, int))(v4 + 276))(dword_FB40C8, v3, 6, 2, v6);
    else
      (*(void (__stdcall **)(int, int, int, int, int))(v4 + 276))(dword_FB40C8, v3, 6, 1, v6);
    result = (*(int (__stdcall **)(int, _DWORD, int))(*(_DWORD *)dword_FB40C8 + 276))(
               dword_FB40C8,
               *(_DWORD *)(this + 204),
               5);
    *(_BYTE *)(this + 236) = a2;
  }
  return result;
}
