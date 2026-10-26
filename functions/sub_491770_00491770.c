char __thiscall sub_491770(int **this)
{
  int *v2; // ecx
  int v3; // esi
  int v4; // ebx

  v2 = *this;
  v3 = 0;
  if ( *v2 > 0 )
  {
    v4 = 0;
    do
    {
      ListIteratorFullDestruction(v4 + v2[2]);
      v2 = *this;
      ++v3;
      v4 += 16;
    }
    while ( v3 < **this );
  }
  ListIteratorFullDestruction((int)(*this + 3));
  return ListIteratorFullDestruction((int)(*this + 7));
}
