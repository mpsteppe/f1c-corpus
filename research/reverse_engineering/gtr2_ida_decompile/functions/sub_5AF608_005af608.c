void sub_5AF608()
{
  void *v0; // edi
  void *v1; // eax
  void *v2; // ebx
  int v3; // [esp+4h] [ebp-4h]

  if ( !dword_FB22F0 )
  {
    dword_FB22F0 = 1;
    v3 = 0;
    v0 = operator new(0);
    v1 = operator new(0);
    v2 = v1;
    if ( !v0 || !v1 || v0 == v1 )
      v3 = 1;
    if ( v0 )
      j__free(v0);
    if ( v2 && v2 != v0 )
      j__free(v2);
    j__free(0);
    if ( v3 )
    {
      OutputDebugStringA("D3DX: (WARN) Overloaded ::new and ::delete operators do not conform to C++ standards:\r\n");
      OutputDebugStringA("D3DX: (WARN) An allocation of zero bytes should return a unique non-null pointer to at\r\n");
      OutputDebugStringA("D3DX: (WARN) least zero bytes. Deletion of a null pointer should quietly do nothing.\r\n");
      OutputDebugStringA("D3DX: (WARN) D3DX relies upon this behavior.\r\n");
    }
  }
}
