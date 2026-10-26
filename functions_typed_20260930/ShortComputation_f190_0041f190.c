bool __thiscall sub_41F190(_DWORD *this)
{
  int v2; // eax
  int v3; // esi

  v2 = LinkedListDereference(&dword_7D2DB0);
  v3 = FlagsGetter(v2);
  return (unsigned __int8)ShortComputation_f1e0(this) && (v3 == 2 || v3 > 2 && this[v3 + 51] != 10);
}

