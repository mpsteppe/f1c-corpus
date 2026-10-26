char __thiscall sub_54BDA0(char *this, int a2)
{
  int v2; // edx
  char result; // al

  v2 = a2 - (_DWORD)this;
  do
  {
    result = *this;
    this[v2] = *this;
    ++this;
  }
  while ( result );
  return result;
}

