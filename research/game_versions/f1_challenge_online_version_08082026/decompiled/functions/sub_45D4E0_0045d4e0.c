int __thiscall sub_45D4E0(_BYTE *this)
{
  void *v1; // esi
  int result; // eax

  if ( *this )
  {
    if ( this[1] )
    {
      v1 = off_5E4DFC;
      sub_561ED0(off_5E4DFC);
      return sub_561E30(v1);
    }
    else
    {
      return sub_561E30(off_5E4DFC);
    }
  }
  return result;
}
