bool __thiscall sub_41F100(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  v2 = LinkedListDereference(&dword_7D2DB0);
  v3 = FlagsGetter(v2);
  return this && v3 >= 3 && this[v3 + 54] == 10 && this[v3 + 53] == 10 && this[v3 + 52] == 10;
}

