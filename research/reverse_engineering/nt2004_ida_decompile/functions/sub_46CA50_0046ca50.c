int __thiscall sub_46CA50(_DWORD *this, int a2)
{
  int v3; // edi
  LPVOID *v4; // ebp
  bool v5; // zf
  int v6; // edi
  LPVOID *v7; // ebp
  int v8; // ecx
  int result; // eax
  int v10; // ecx
  int v11; // edx
  int i; // edi
  LPVOID *v13; // ebp
  int j; // edi
  LPVOID *v15; // ebp

  *this = a2;
  sub_57B690(this + 1);
  this[25] = 1065353216;
  this[26] = 0;
  this[24] = 0;
  v3 = this[27];
  while ( v3 )
  {
    v4 = (LPVOID *)v3;
    v5 = *(_BYTE *)(v3 + 8) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 )
      sub_5BE8AE(*v4);
    sub_5BE8AE(v4);
  }
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  v6 = this[31];
  while ( v6 )
  {
    v7 = (LPVOID *)v6;
    v5 = *(_BYTE *)(v6 + 8) == 0;
    v6 = *(_DWORD *)(v6 + 4);
    if ( !v5 )
      sub_5BE8AE(*v7);
    sub_5BE8AE(v7);
  }
  this[31] = 0;
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  v8 = (int)(this + 35);
  do
  {
    result = sub_46C710(v8);
    v8 = v10 + 284;
  }
  while ( v11 != 1 );
  this[3514] = 0;
  for ( i = this[3564]; i; result = sub_5BE8AE(v13) )
  {
    v13 = (LPVOID *)i;
    v5 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v5 )
      sub_5BE8AE(*v13);
  }
  this[3564] = 0;
  this[3565] = 0;
  this[3566] = 0;
  this[3567] = 0;
  for ( j = this[3568]; j; result = sub_5BE8AE(v15) )
  {
    v15 = (LPVOID *)j;
    v5 = *(_BYTE *)(j + 8) == 0;
    j = *(_DWORD *)(j + 4);
    if ( !v5 )
      sub_5BE8AE(*v15);
  }
  this[3568] = 0;
  this[3569] = 0;
  this[3570] = 0;
  this[3571] = 0;
  return result;
}
