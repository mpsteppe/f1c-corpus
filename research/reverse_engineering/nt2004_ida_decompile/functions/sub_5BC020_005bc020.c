int __thiscall sub_5BC020(int this)
{
  _DWORD *v2; // esi
  DWORD TickCount; // ebp
  int result; // eax

  v2 = (_DWORD *)(this + 8);
  TickCount = GetTickCount();
  for ( result = *v2; *v2; result = *v2 )
  {
    if ( TickCount <= *(_DWORD *)(result + 28) + 2500 )
      break;
    *(_BYTE *)(result + 21) |= 0x10u;
    *(_BYTE *)(*v2 + 21) &= 0xF3u;
    (*(void (__fastcall **)(int, int, _DWORD, _DWORD))(this + 64))(this, 1, *v2, *(_DWORD *)(this + 68));
    sub_5BC080(this + 8);
  }
  return result;
}
