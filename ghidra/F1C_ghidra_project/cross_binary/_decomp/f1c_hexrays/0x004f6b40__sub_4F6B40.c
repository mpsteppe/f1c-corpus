// f1c  0x004f6b40  size=57
int sub_4F6B40()
{
  int *v0; // esi
  int v1; // edi
  int result; // eax

  v0 = &dword_8AF570;
  v1 = 45;
  do
  {
    *(v0 - 2) = 0;
    *(v0 - 1) = -1;
    result = sub_566650(byte_5EA438);
    *v0 = -1;
    v0[1] = -1;
    *((_BYTE *)v0 + 8) = 0;
    v0 += 5;
    --v1;
  }
  while ( v1 );
  return result;
}
