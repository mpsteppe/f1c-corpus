void __thiscall std::string::_Split(_DWORD *this)
{
  char *v1; // esi
  char v2; // al
  size_t v3; // eax

  v1 = (char *)this[1];
  if ( v1 )
  {
    v2 = *(v1 - 1);
    if ( v2 )
    {
      if ( v2 != -1 )
      {
        std::string::_Tidy(this, 1);
        v3 = strlen(v1);
        std::string::assign(v1, v3);
      }
    }
  }
}
