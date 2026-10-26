BOOL __thiscall sub_473630(int *this)
{
  int v2; // esi
  BOOL result; // eax

  if ( *(_DWORD *)(*this + 113328) == 4 && *(_DWORD *)(*this + 113316) && sub_59B670(*(_DWORD *)(*this + 113316)) == 3 )
    *(_DWORD *)(*this + 113328) = 3;
  v2 = *this;
  result = 1;
  if ( *(_DWORD *)(v2 + 113328) != 1 )
    return *(_BYTE *)(v2 + 1417) != 0;
  return result;
}
