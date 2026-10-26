HCURSOR __thiscall sub_44F5F0(HCURSOR *this)
{
  HCURSOR *v2; // esi
  int v3; // edi
  HCURSOR result; // eax

  SetCursor(0);
  v2 = this + 12;
  v3 = 6;
  do
  {
    result = *v2;
    if ( *v2 )
    {
      result = (HCURSOR)DestroyCursor(*v2);
      *v2 = 0;
    }
    v2 += 5;
    --v3;
  }
  while ( v3 );
  this[42] = 0;
  return result;
}

