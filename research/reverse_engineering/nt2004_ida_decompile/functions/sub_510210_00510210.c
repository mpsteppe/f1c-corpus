_DWORD *__thiscall sub_510210(_DWORD *this, _DWORD *a2)
{
  int v3; // edi
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c3
  _DWORD *result; // eax
  int v8; // ecx

  v3 = this[4365];
  if ( v5 | v6 )
  {
    this[4369] = this[4367];
  }
  else
  {
    ++v3;
    this[4369] = this[4368];
  }
  result = this + 4451;
  v8 = 4;
  do
  {
    *result = this[4369];
    result += 62;
    --v8;
  }
  while ( v8 );
  if ( v3 <= 0 )
  {
    this[4370] = a2;
  }
  else
  {
    do
    {
      sub_5102E0(this);
      sub_510C10(this);
      sub_510540(this);
      sub_5107B0(this);
      sub_510EA0(this);
      --v3;
    }
    while ( v3 );
    result = a2;
    this[4370] = a2;
  }
  return result;
}
