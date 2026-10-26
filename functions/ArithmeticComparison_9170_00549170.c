_DWORD *__thiscall sub_549170(_DWORD *this)
{
  int i; // esi
  _DWORD *result; // eax
  _DWORD *v4; // [esp+8h] [ebp-4h] BYREF

  for ( i = this[58]; i; i = *(_DWORD *)(i + 20) )
  {
    v4 = 0;
    RecursiveTreeStringSearch(i, &v4);
    result = v4;
    if ( v4 )
    {
      LinkedListRemove((_DWORD *)*this, (int)v4);
      result = (_DWORD *)DoublyLinkedListAppend_90b0(this, v4);
    }
  }
  return result;
}
