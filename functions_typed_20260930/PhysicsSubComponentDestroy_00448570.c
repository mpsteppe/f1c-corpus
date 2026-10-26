int __thiscall sub_448570(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // ebx
  int result; // eax

  v2 = this + 19;
  v3 = 4;
  do
  {
    if ( *v2 )
    {
      PhysicsSubComponentDestroy();
      result = FreeWrapper_7bcf(*v2);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  if ( this[23] )
  {
    PhysicsSubComponentDestroy();
    result = FreeWrapper_7bcf(this[23]);
    this[23] = 0;
  }
  return result;
}

