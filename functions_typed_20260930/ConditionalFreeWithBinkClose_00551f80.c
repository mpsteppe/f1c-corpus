int __stdcall sub_551F80(_DWORD *a1)
{
  int result; // eax

  if ( a1 )
  {
    BinkVideoClose(a1);
    EmptyStub_7470(a1);
    return FreeWrapper_7bcf(a1);
  }
  return result;
}

