// f1c  0x00415900  size=175
LPVOID *__thiscall sub_415900(LPVOID *this, char a2)
{
  LPVOID *v3; // esi
  int v4; // ebx
  void *v5; // eax
  LPVOID *v6; // esi
  int v7; // ebx
  void *v8; // eax
  LPVOID *v9; // esi
  int v10; // ebx
  void *v11; // eax
  LPVOID *v12; // esi
  int v13; // ebx
  void *v14; // eax

  sub_4149A0((int)this);
  v3 = this + 44;
  v4 = 2;
  do
  {
    v5 = *(v3 - 5);
    v3 -= 5;
    if ( v5 )
      sub_587BCF(v5);
    --v4;
  }
  while ( v4 );
  v6 = this + 34;
  v7 = 2;
  do
  {
    v8 = *(v6 - 5);
    v6 -= 5;
    if ( v8 )
      sub_587BCF(v8);
    --v7;
  }
  while ( v7 );
  v9 = this + 24;
  v10 = 2;
  do
  {
    v11 = *(v9 - 5);
    v9 -= 5;
    if ( v11 )
      sub_587BCF(v11);
    --v10;
  }
  while ( v10 );
  v12 = this + 14;
  v13 = 2;
  do
  {
    v14 = *(v12 - 5);
    v12 -= 5;
    if ( v14 )
      sub_587BCF(v14);
    --v13;
  }
  while ( v13 );
  if ( *this )
    sub_587BCF(*this);
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
