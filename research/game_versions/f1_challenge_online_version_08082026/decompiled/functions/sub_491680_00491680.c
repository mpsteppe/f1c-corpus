bool __thiscall sub_491680(__int16 *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx

  v5 = *this;
  v6 = v5 + this[2];
  if ( v5 <= a2 )
    v5 = a2;
  if ( v6 >= a2 + a4 )
    v6 = a2 + a4;
  if ( v6 - v5 <= 0 )
    return 0;
  v7 = this[1];
  v8 = v7 + this[3];
  if ( v7 <= a3 )
    v7 = a3;
  if ( v8 >= a3 + a5 )
    v8 = a3 + a5;
  return v8 - v7 > 0;
}
