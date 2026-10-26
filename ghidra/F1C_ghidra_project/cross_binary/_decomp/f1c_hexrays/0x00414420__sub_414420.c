// f1c  0x00414420  size=87
LPVOID __thiscall sub_414420(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // ebx
  void *v4; // eax
  LPVOID *v5; // esi
  int v6; // ebx
  void *v7; // eax
  LPVOID result; // eax

  sub_414FE0();
  v2 = this + 23;
  v3 = 2;
  do
  {
    v4 = *(v2 - 5);
    v2 -= 5;
    if ( v4 )
      sub_587BCF(v4);
    --v3;
  }
  while ( v3 );
  v5 = this + 13;
  v6 = 2;
  do
  {
    v7 = *(v5 - 5);
    v5 -= 5;
    if ( v7 )
      sub_587BCF(v7);
    --v6;
  }
  while ( v6 );
  result = *this;
  if ( *this )
    return (LPVOID)sub_587BCF(*this);
  return result;
}
