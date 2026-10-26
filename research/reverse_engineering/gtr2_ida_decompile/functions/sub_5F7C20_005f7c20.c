_DWORD *__thiscall sub_5F7C20(_DWORD *this, int a2, int a3)
{
  _DWORD *result; // eax
  _DWORD *v5; // ebp
  void *v6; // eax
  _DWORD *v7; // ebp
  size_t v8; // [esp-4h] [ebp-1Ch]

  result = (_DWORD *)a2;
  if ( !*(_BYTE *)(a2 + 201) )
  {
    *(_BYTE *)(a2 + 201) = 1;
    v5 = (_DWORD *)this[a3 + 189];
    ++this[a3 + 183];
    if ( v5 )
    {
      v6 = (void *)v5[1];
      *v5 = 0;
      if ( v6 )
        j__free(v6);
      j__free(v5);
    }
    result = (_DWORD *)this[a3 + 183];
    this[a3 + 189] = 0;
    if ( (int)result > 0 )
    {
      result = operator new(8u);
      v7 = result;
      if ( result )
      {
        v8 = 4 * this[a3 + 183];
        *result = 0;
        result = operator new(v8);
        v7[1] = result;
      }
      else
      {
        v7 = 0;
      }
      this[a3 + 189] = v7;
    }
  }
  return result;
}
