int __thiscall sub_458E50(int this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax

  do
  {
    v2 = (_DWORD *)(this + 84);
    v3 = 4;
    *(double *)(this + 24) = (*(double *)(this + 8) + *(double *)(this + 24)) * 0.5;
    do
    {
      if ( *v2 )
        result = sub_458E50();
      ++v2;
      --v3;
    }
    while ( v3 );
    this = *(_DWORD *)(this + 100);
  }
  while ( this );
  return result;
}
