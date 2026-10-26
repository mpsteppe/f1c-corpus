LPVOID __thiscall sub_4C0B10(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // edi
  LPVOID result; // eax

  if ( this[11338] )
    FreeWrapper_7bcf(this[11338]);
  if ( this[11336] )
    FreeWrapper_7bcf(this[11336]);
  v2 = this + 11227;
  sub_49A270(v2);
  v3 = 103;
  do
  {
    v2 -= 109;
    result = sub_49A270(v2);
    --v3;
  }
  while ( v3 );
  return result;
}

