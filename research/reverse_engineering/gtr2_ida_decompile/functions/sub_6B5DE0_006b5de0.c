void __stdcall sub_6B5DE0(int *Parameter)
{
  signed int i; // esi

  for ( i = 1; i >= 0; --i )
    sub_6B5CE0(Parameter, i);
  sub_6D3B30(Parameter, Parameter[1], 84);
  Parameter[1] = 0;
  pfnAPC((ULONG_PTR)Parameter);
}
