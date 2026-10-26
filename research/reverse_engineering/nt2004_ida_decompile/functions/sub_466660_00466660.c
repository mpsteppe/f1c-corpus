char __thiscall sub_466660(int *this)
{
  char result; // al
  int v3; // esi

  sub_460930(*this);
  result = byte_766188;
  if ( !byte_766188 )
  {
    sub_4CE820(&unk_7663E0);
    if ( *(_DWORD *)(*this + 6720) )
      sub_464C40(this);
    sub_45E910((_BYTE *)(*this + 30136));
    sub_56A640(*(_DWORD *)(*this + 6708));
    v3 = *this;
    if ( *(_BYTE *)(v3 + 164) )
      return sub_4BA6A0(&unk_76612C);
    result = *(_BYTE *)(v3 + 165);
    if ( result )
      return sub_4BA6A0(&unk_76612C);
  }
  return result;
}
