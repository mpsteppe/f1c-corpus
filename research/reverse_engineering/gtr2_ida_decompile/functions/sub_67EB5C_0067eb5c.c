BOOL __thiscall sub_67EB5C(_DWORD **this)
{
  BOOL result; // eax
  _DWORD *v3; // [esp-Ch] [ebp-10h]

  while ( *this )
  {
    v3 = *this;
    *this = (_DWORD *)**this;
    result = VirtualFree(v3, 0, 0x8000u);
  }
  return result;
}
