_DWORD *__thiscall sub_609300(_DWORD *this, _DWORD *a2)
{
  int i; // esi

  if ( a2[4] < this[2] )
  {
    sub_608C60((int)a2, 1);
    for ( i = 0; i < 1168; i += 292 )
      sub_609300(i + a2[72]);
  }
  return sub_6088B0(a2);
}
