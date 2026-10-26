void sub_5CFE0C()
{
  bool v0; // zf
  bool v1; // bl
  _BYTE v2[4]; // [esp+4h] [ebp-4h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v2);
  v0 = dword_628B94-- == 1;
  v1 = v0;
  std::_Lockit::~_Lockit((std::_Lockit *)v2);
  if ( v1 )
  {
    unknown_libname_185(&unk_7FF550);
    unknown_libname_185(dword_7FF678);
    unknown_libname_185(dword_7FF4C0);
  }
}
