int __stdcall sub_53D260(const char *a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax

  result = WideStringLinkedListSearch(a1);
  if ( result )
  {
    FieldSetterAt0x48(a2);
    MaskedFieldSetter(a3, a4);
    return SwitchBasedParameterFieldSetWithFlags(a5, a6);
  }
  return result;
}

