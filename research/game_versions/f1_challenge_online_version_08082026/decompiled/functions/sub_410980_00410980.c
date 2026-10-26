int __thiscall sub_410980(int *this, float a2)
{
  int result; // eax
  int i; // esi
  _DWORD *v5; // ecx

  sub_4BDFE0(&unk_8AB710);
  result = *this;
  for ( i = 0; i < *this; ++i )
  {
    if ( !sub_40F1C0(*(_DWORD *)(this[2] + 4 * i), a2) )
    {
      v5 = *(_DWORD **)(this[2] + 4 * i--);
      sub_40F100(v5);
    }
    result = *this;
  }
  return result;
}
