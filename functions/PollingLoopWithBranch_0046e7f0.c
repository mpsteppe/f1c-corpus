char __thiscall sub_46E7F0(_DWORD *this)
{
  int v3; // eax

  while ( !StringEmptyCheck(dword_7C73E0) )
    DirectoryPathExtraction(dword_7C73E0);
  if ( !this[90] )
    return SettingsSetupFileRead((char **)dword_7C73E0);
  v3 = UIScreenTextAccessor(this);
  return PathNormalizerFileEnumeration((char **)dword_7C73E0, v3);
}
