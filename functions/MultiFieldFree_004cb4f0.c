int __thiscall sub_4CB4F0(_DWORD *this)
{
  int v2; // eax
  void *v3; // eax
  int result; // eax

  v2 = this[23];
  this[22] = 0;
  if ( v2 )
  {
    FreeWrapper_7bcf((LPVOID)(v2 - 4));
    this[23] = 0;
  }
  v3 = (void *)this[26];
  this[25] = 0;
  if ( v3 )
  {
    FreeWrapper_7bcf(v3);
    this[26] = 0;
  }
  result = this[21];
  if ( result )
  {
    result = DoublyLinkedListNodeRemovalByPointer(this[21]);
    this[21] = 0;
  }
  return result;
}
