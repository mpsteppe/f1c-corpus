int __thiscall sub_448DE0(int this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  int result; // eax

  do
  {
    v2 = (_DWORD *)(this + 76);
    v3 = 4;
    *(double *)(this + 16) = (*(double *)(this + 4) + *(double *)(this + 16)) * 0.5;
    do
    {
      if ( *v2 )
        result = PhysicsTreeMassPropagation();
      ++v2;
      --v3;
    }
    while ( v3 );
    this = *(_DWORD *)(this + 92);
  }
  while ( this );
  return result;
}
