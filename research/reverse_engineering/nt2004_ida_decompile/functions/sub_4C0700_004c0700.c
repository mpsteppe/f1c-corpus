char __thiscall sub_4C0700(char *this, _DWORD *a2)
{
  char result; // al
  int v3; // esi
  char *v4; // edi
  char v5; // al

  result = 0;
  if ( *a2 )
  {
    v3 = 0;
    v4 = this + 32;
    do
    {
      v5 = (unsigned __int8)sub_4BFF30((void *)v3);
      sub_57A400((int)a2, aSD_1, v5);
      ++v3;
      v4 += 64;
    }
    while ( v3 < 12 );
    return 1;
  }
  return result;
}
