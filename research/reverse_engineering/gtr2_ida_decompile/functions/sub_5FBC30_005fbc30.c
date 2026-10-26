void *__thiscall sub_5FBC30(int this)
{
  void *result; // eax
  int v3; // ebx
  void *v4; // esi
  int v5; // edx

  result = *(void **)(this + 8);
  if ( (int)result > *(_DWORD *)(this + 4) )
  {
    if ( *(_DWORD *)(this + 16) )
      j__free(*(void **)(this + 16));
    v3 = *(_DWORD *)(this + 8);
    result = operator new(8 * v3);
    v4 = result;
    if ( result )
      result = (void *)sub_41D1B0((int)result, 8, v3, (int)Concurrency::details::_ReaderWriterLock::_ReaderWriterLock);
    else
      v4 = 0;
    v5 = *(_DWORD *)(this + 8);
    *(_DWORD *)(this + 16) = v4;
    *(_DWORD *)(this + 4) = v5;
  }
  return result;
}
