int __thiscall sub_60A680(int this, int a2)
{
  bool v3; // zf
  int result; // eax
  int v5; // edi

  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 208) = 0;
  *(_DWORD *)(this + 212) = 0;
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 224) = 0;
  *(_DWORD *)(this + 228) = 0;
  *(_DWORD *)(this + 244) = -1;
  *(_DWORD *)(this + 248) = -1;
  *(_DWORD *)(this + 252) = -1;
  *(_DWORD *)(this + 240) = a2;
  sub_609B00(this, 1, 4);
  if ( *(_DWORD *)(this + 208) != 2 )
  {
    v3 = *(_BYTE *)(this + 236) == 0;
    *(_DWORD *)(this + 208) = 2;
    if ( !v3 )
      (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 268))(
        dword_FB40C8,
        *(_DWORD *)(this + 240),
        2,
        2);
  }
  if ( *(_DWORD *)(this + 212) != 1 )
  {
    v3 = *(_BYTE *)(this + 236) == 0;
    *(_DWORD *)(this + 212) = 1;
    if ( !v3 )
      (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 268))(
        dword_FB40C8,
        *(_DWORD *)(this + 240),
        3,
        1);
  }
  *(_DWORD *)(this + 244) = 4;
  result = sub_60A000(2);
  v5 = *(_DWORD *)(this + 240);
  if ( v5 != *(_DWORD *)(this + 252) && v5 != -1 )
  {
    result = (*(int (__stdcall **)(int, int, int, _DWORD))(*(_DWORD *)dword_FB40C8 + 268))(
               dword_FB40C8,
               v5,
               11,
               *(_DWORD *)(this + 240));
    *(_DWORD *)(this + 252) = v5;
  }
  return result;
}
