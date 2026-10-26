int __thiscall sub_491740(int **this)
{
  int *v1; // esi
  int result; // eax

  v1 = *this;
  if ( *this )
  {
    MultiListDestruction(*this);
    return FreeWrapper_7bcf(v1);
  }
  return result;
}

