void __thiscall sub_5995E5(_DWORD *this)
{
  _DWORD *v1; // esi
  char v2; // al
  char *v3; // eax

  v1 = (_DWORD *)this[1];
  if ( v1 )
  {
    v2 = *((_BYTE *)v1 - 1);
    if ( v2 )
    {
      if ( v2 != -1 )
      {
        ReferenceCountDecrementWithConditionalFree(this, 1);
        v3 = Strlen(v1);
        BufferWriteWithNullTerminate(v1, v3);
      }
    }
  }
}

