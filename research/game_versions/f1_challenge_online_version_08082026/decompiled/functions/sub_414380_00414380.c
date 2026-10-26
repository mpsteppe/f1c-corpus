LPVOID __thiscall sub_414380(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // ebx
  void *v4; // eax
  LPVOID *v5; // esi
  int v6; // ebx
  void *v7; // eax
  LPVOID *v8; // esi
  int v9; // ebx
  void *v10; // eax
  LPVOID *v11; // esi
  int v12; // ebx
  void *v13; // eax
  LPVOID result; // eax

  sub_414D70();
  v2 = this + 43;
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
  v5 = this + 33;
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
  v8 = this + 23;
  v9 = 2;
  do
  {
    v10 = *(v8 - 5);
    v8 -= 5;
    if ( v10 )
      sub_587BCF(v10);
    --v9;
  }
  while ( v9 );
  v11 = this + 13;
  v12 = 2;
  do
  {
    v13 = *(v11 - 5);
    v11 -= 5;
    if ( v13 )
      sub_587BCF(v13);
    --v12;
  }
  while ( v12 );
  result = *this;
  if ( *this )
    return (LPVOID)sub_587BCF(*this);
  return result;
}
