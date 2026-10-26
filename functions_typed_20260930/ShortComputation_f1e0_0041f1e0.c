bool __thiscall sub_41F1E0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = LinkedListDereference(&dword_7D2DB0);
  v3 = FlagsGetter(v2);
  return this && v3 >= 2 && this[v3 + 5] == 1 && this[v3 + 4] == 1;
}

