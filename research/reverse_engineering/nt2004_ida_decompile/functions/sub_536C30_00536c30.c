int __fastcall sub_536C30(FILE *Stream, unsigned int a2)
{
  int v4; // edi
  int result; // eax

  v4 = 4;
  do
  {
    result = fputc((unsigned __int8)a2, Stream);
    a2 >>= 8;
    --v4;
  }
  while ( v4 );
  return result;
}
