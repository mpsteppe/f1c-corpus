int __thiscall sub_476250(_DWORD **this)
{
  int v2; // edi
  int v3; // eax
  char *v4; // ecx
  const char **v5; // esi
  int v6; // edi
  const char *v7; // esi
  const char *v8; // eax
  int v9; // eax
  int v10; // eax
  _BYTE v12[56]; // [esp+Ch] [ebp-138h] BYREF
  _BYTE v13[256]; // [esp+44h] [ebp-100h] BYREF

  v2 = LinkedListIndexedAccessor_f590();
  if ( v2 )
  {
    v3 = (*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 1);
    if ( v3 )
    {
      v4 = *(char **)(v2 + 60);
      if ( !v4 )
        v4 = byte_5EA438;
      v5 = (const char **)(v3 + 228);
      StringCopyWithBufferRealloc(v4);
      v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 21);
      if ( v6 )
      {
        v7 = *v5;
        if ( !v7 )
          v7 = byte_5EA438;
        v8 = (const char *)dword_5EC3D8;
        if ( !dword_5EC3D8 )
          v8 = byte_5EA438;
        if ( (int)StringFormatProcessingWithNullTerm(v13, 255, "%s%s", v8, v7) >= 0 )
        {
          StructZeroInit_7a00(v12);
          if ( (unsigned __int8)AudioFileLoadDecode(v13, 0) == 1 )
          {
            v9 = ConditionalDispatch_81f0(aGameFilter);
            if ( v9 )
              SingleFunctionDispatch_6f90(v9);
            else
              SingleFunctionDispatch_6f90(String1);
            (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 160))(v6);
            v10 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 17);
            if ( v10 )
              (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 160))(v10);
          }
          LinkedListDestructorWithInnerFree(v12);
        }
      }
    }
  }
  return 0;
}
