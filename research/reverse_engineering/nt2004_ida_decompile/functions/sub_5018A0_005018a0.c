int __thiscall sub_5018A0(float *this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // ebx

  sub_501CE0(this);
  this[22] = (double)dword_6152E8 * 0.00078125001;
  this[23] = (double)dword_6152EC * 0.0009765625;
  sub_502350(this);
  sub_502570(COERCE_FLOAT(1));
  sub_502570(COERCE_FLOAT(2));
  sub_502570(COERCE_FLOAT(3));
  sub_502570(COERCE_FLOAT(4));
  sub_502570(COERCE_FLOAT(5));
  sub_502130(this);
  v2 = this + 7;
  v3 = 2;
  do
  {
    if ( *v2 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v2 + 8))(*v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = this + 9;
  v5 = 5;
  do
  {
    if ( *v4 )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v4 + 8))(*v4);
    ++v4;
    --v5;
  }
  while ( v5 );
  sub_501F60(-1, 0);
  return sub_501DD0(this);
}
