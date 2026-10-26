LPVOID *__thiscall sub_418CF0(LPVOID *this, char a2)
{
  LPVOID *v3; // esi
  int v4; // ebx
  void *v5; // eax
  LPVOID *v6; // esi
  int v7; // ebx
  void *v8; // eax

  TextFormatStructInitializer_4fe0((int)this);
  v3 = this + 23;
  v4 = 2;
  do
  {
    v5 = *(v3 - 5);
    v3 -= 5;
    if ( v5 )
      FreeWrapper_7bcf(v5);
    --v4;
  }
  while ( v4 );
  v6 = this + 13;
  v7 = 2;
  do
  {
    v8 = *(v6 - 5);
    v6 -= 5;
    if ( v8 )
      FreeWrapper_7bcf(v8);
    --v7;
  }
  while ( v7 );
  if ( *this )
    FreeWrapper_7bcf(*this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf(this);
  return this;
}

