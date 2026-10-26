void sub_5D0F4D()
{
  bool v0; // zf
  bool v1; // bl
  _BYTE v2[4]; // [esp+4h] [ebp-4h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v2);
  v0 = dword_628CEC-- == 1;
  v1 = v0;
  std::_Lockit::~_Lockit((std::_Lockit *)v2);
  if ( v1 )
  {
    unknown_libname_185(byte_7FF818);
    unknown_libname_185((char *)dword_7FF6B0);
    unknown_libname_185((char *)dword_7FF6F0);
  }
}
