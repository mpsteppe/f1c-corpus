int __thiscall sub_4A7890(_DWORD *this)
{
  int ContentID; // edi

  ContentID = CGarageOnline::GetContentID((CGarageOnline *)dword_B6CBB4);
  if ( this[149] != ContentID )
  {
    sub_4948A0();
    this[149] = ContentID;
  }
  return 0;
}
