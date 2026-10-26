int sub_4F6AB0()
{
  int *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = &dword_8AF8F8;
  v1 = 45;
  do
  {
    *(v0 - 2) = 0;
    *(v0 - 1) = -1;
    result = StringCopyWithBufferRealloc(byte_5EA438);
    *v0 = -1;
    v0[1] = -1;
    *((_BYTE *)v0 + 8) = 0;
    v0 += 5;
    --v1;
  }
  while ( v1 );
  return result;
}

