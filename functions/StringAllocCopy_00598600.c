void __cdecl sub_598600(_DWORD *a1)
{
  char *v1; // eax

  if ( a1 )
  {
    v1 = Strlen(a1);
    if ( MallocWrapperForNhMalloc((int)(v1 + 1)) )
      sub_58FCA0();
  }
}
