bool __stdcall sub_409430(int a1)
{
  const char *v1; // eax
  bool result; // al

  result = 0;
  if ( !*(_DWORD *)dword_76BB84 )
  {
    if ( a1 )
    {
      v1 = (const char *)sub_459B80();
      if ( !_strcmpi(v1, aCockpit) && (!(unsigned __int8)sub_42DBA0(&unk_62BF64) || dword_75AAC0 != dword_75AAC8) )
        return 1;
    }
  }
  return result;
}
