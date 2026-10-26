BOOL __thiscall sub_559D10(_DWORD *this, int a2)
{
  _DWORD *v3; // edi
  char *v4; // eax
  char v5; // cl
  int v6; // eax
  int v7; // eax

  v3 = this + 99;
  v4 = (char *)(this + 3);
  do
  {
    v5 = *v4;
    v4[384] = *v4;
    ++v4;
  }
  while ( v5 );
  v6 = sub_5897CA(v3, asc_5C30AC);
  this[195] = v6;
  if ( !v6 || sub_588410(v6, a2) )
    return 0;
  v7 = sub_5897CA(0, byte_5EA438);
  this[195] = v7;
  return v7 != 0;
}

