int __thiscall sub_4F8EA0(_DWORD *this)
{
  void *v2; // edi
  int v3; // eax

  v2 = (void *)this[6];
  if ( v2 )
  {
    EmptyStub_7470(this[6]);
    FreeWrapper_7bcf(v2);
  }
  v3 = WideStringLinkedListSearch(aFtframerate);
  if ( v3 )
    StringCompareLinkedListSearch(v3);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[5] = 0;
  this[4] = 0;
  this[6] = 0;
  this[8] = 0;
  this[7] = 0;
  this[10] = 0;
  this[9] = 0;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 108) = 0;
  return 0;
}

